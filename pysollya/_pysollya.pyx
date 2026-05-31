# cython: language_level=3
"""pysollya._pysollya — Cython bindings for the Sollya library."""
from __future__ import division, print_function

from pysollya.csollya cimport *
from cpython.bytes cimport PyBytes_AsString, PyBytes_FromString
from cpython.long cimport PyLong_AsLong
from cpython.object cimport Py_LT, Py_LE, Py_EQ, Py_NE, Py_GT, Py_GE
from libc.stdlib cimport malloc, free

import atexit, sys, locale
# bigfloat not available on Python 3.14, optional
try:
    import bigfloat
    HAS_BIGFLOAT = True
except ImportError:
    HAS_BIGFLOAT = False

# ---------- message callback (suppresses Sollya messages to stderr) ----------
cdef int __msg_callback(sollya_msg_t msg, void *data) noexcept:
    return 0  # suppress

# ---------- library init / shutdown ----------
sollya_lib_init_with_custom_memory_function_modifiers(NULL, NULL)
atexit.register(lambda: sollya_lib_close())
sollya_lib_install_msg_callback(__msg_callback, NULL)

# ---------- helpers ----------
cdef SollyaObject wrap(sollya_obj_t v):
    cdef SollyaObject r = SollyaObject.__new__(SollyaObject)
    r.value = v
    return r

cdef SollyaObject as_SollyaObject(op):
    if isinstance(op, SollyaObject):
        return op
    return SollyaObject(op)

cdef bytes _encode(s):
    if isinstance(s, bytes):
        return s
    return s.encode(locale.getpreferredencoding(False))

cdef _decode(b):
    try:
        return b.decode(locale.getpreferredencoding(False))
    except UnicodeDecodeError:
        return b.decode("utf-8")

cdef sollya_obj_t _to_sollya(op) except NULL:
    cdef sollya_obj_t obj
    cdef sollya_obj_t* slist
    cdef int n
    if isinstance(op, SollyaObject):
        return sollya_lib_copy_obj((<SollyaObject>op).value)
    elif isinstance(op, float):
        return sollya_lib_constant_from_double(<double>op)
    elif isinstance(op, bool):
        return sollya_lib_true() if op else sollya_lib_false()
    elif isinstance(op, int):
        try:
            return sollya_lib_constant_from_int64(PyLong_AsLong(op))
        except OverflowError:
            # Fallback for very large ints via string parse
            s = str(op)
            bs = _encode(s + ";")
            return sollya_lib_parse_string(bs)
    elif op is None:
        return sollya_lib_void()
    elif isinstance(op, str):
        bs = _encode(op)
        return sollya_lib_string(PyBytes_AsString(bs))
    elif isinstance(op, bytes):
        return sollya_lib_string(PyBytes_AsString(op))
    elif isinstance(op, (list, tuple)):
        n = len(op)
        slist = <sollya_obj_t*>malloc(sizeof(sollya_obj_t) * n)
        for i in range(n):
            slist[i] = _to_sollya(op[i])
        obj = sollya_lib_list(slist, n)
        for i in range(n):
            sollya_lib_clear_obj(slist[i])
        free(slist)
        return obj
    elif HAS_BIGFLOAT and isinstance(op, bigfloat.BigFloat):
        # Use string conversion as safe fallback
        s = str(op)
        bs = _encode(s + ";")
        return sollya_lib_parse_string(bs)
    raise TypeError(f"Cannot convert {type(op)} to Sollya object")

# ========================= SollyaObject ==============================
cdef class SollyaObject:
    cdef sollya_obj_t value

    def __cinit__(self):
        self.value = NULL

    def __init__(self, op=None):
        if op is not None:
            self.value = _to_sollya(op)

    def __dealloc__(self):
        if self.value is not NULL:
            sollya_lib_clear_obj(self.value)

    def __repr__(self):
        cdef int n
        cdef char* buf
        n = sollya_lib_snprintf(NULL, 0, <char*>b"%b", <sollya_obj_t>self.value)
        if n > 0:
            buf = <char*>malloc(n + 1)
            sollya_lib_snprintf(buf, n + 1, <char*>b"%b", <sollya_obj_t>self.value)
            result = _decode(buf)
            free(buf)
            return result
        return ""

    def __hash__(self):
        return sollya_lib_hash(self.value)

    def __call__(self, *args):
        cdef sollya_obj_t res
        if sollya_lib_obj_is_procedure(self.value) or sollya_lib_obj_is_externalprocedure(self.value):
            res = sollya_lib_concat(self.value, as_SollyaObject(args).value)
            return wrap(res)
        elif len(args) == 1:
            res = sollya_lib_apply(self.value, as_SollyaObject(args[0]).value, NULL)
            return wrap(res)
        else:
            raise TypeError("expected exactly one argument")

    # --- type checks ---
    def is_function(self): return bool(sollya_lib_obj_is_function(self.value))
    def is_list(self): return bool(sollya_lib_obj_is_list(self.value))
    def is_end_elliptic_list(self): return bool(sollya_lib_obj_is_end_elliptic_list(self.value))
    def is_range(self): return bool(sollya_lib_obj_is_range(self.value))
    def is_string(self): return bool(sollya_lib_obj_is_string(self.value))
    def is_error(self): return bool(sollya_lib_obj_is_error(self.value))
    def is_structure(self): return bool(sollya_lib_obj_is_structure(self.value))
    def is_procedure(self): return bool(sollya_lib_obj_is_procedure(self.value))

    # --- conversions ---
    def __bool__(self):
        if sollya_lib_is_true(self.value):
            return True
        elif sollya_lib_is_false(self.value):
            return False
        raise ValueError("not a boolean")

    def __int__(self):
        cdef int64_t result
        if sollya_lib_get_constant_as_int64(&result, self.value):
            return result
        # Try via uint64 array for large values
        cdef uint64_t *arr
        cdef int sign
        cdef size_t length
        if sollya_lib_get_constant_as_uint64_array(&sign, &arr, &length, self.value):
            res = 0
            for i in range(length):
                res = (res << 64) + arr[length - 1 - i]
            sollya_lib_free(arr)
            if sign < 0:
                res = -res
            elif sign == 0:
                res = 0
            return res
        raise ValueError("cannot convert to int")

    def __float__(self):
        cdef double result
        if sollya_lib_get_constant_as_double(&result, self.value):
            return result
        raise ValueError("cannot convert to float")

    # --- arithmetic ---
    def __neg__(self):
        return wrap(sollya_lib_neg(as_SollyaObject(self).value))

    def __add__(left, right):
        cdef SollyaObject l = as_SollyaObject(left)
        cdef SollyaObject r = as_SollyaObject(right)
        if sollya_lib_obj_is_list(l.value) and (sollya_lib_obj_is_list(r.value) or sollya_lib_obj_is_end_elliptic_list(r.value)):
            return wrap(sollya_lib_concat(l.value, r.value))
        return wrap(sollya_lib_add(l.value, r.value))

    def __radd__(right, left):
        cdef SollyaObject l = as_SollyaObject(left)
        cdef SollyaObject r = as_SollyaObject(right)
        if sollya_lib_obj_is_list(l.value) and (sollya_lib_obj_is_list(r.value) or sollya_lib_obj_is_end_elliptic_list(r.value)):
            return wrap(sollya_lib_concat(l.value, r.value))
        return wrap(sollya_lib_add(l.value, r.value))

    def __sub__(left, right):
        return wrap(sollya_lib_sub(as_SollyaObject(left).value, as_SollyaObject(right).value))

    def __rsub__(right, left):
        return wrap(sollya_lib_sub(as_SollyaObject(left).value, as_SollyaObject(right).value))

    def __mul__(left, right):
        return wrap(sollya_lib_mul(as_SollyaObject(left).value, as_SollyaObject(right).value))

    def __rmul__(right, left):
        return wrap(sollya_lib_mul(as_SollyaObject(left).value, as_SollyaObject(right).value))

    def __truediv__(left, right):
        return wrap(sollya_lib_div(as_SollyaObject(left).value, as_SollyaObject(right).value))

    def __rtruediv__(right, left):
        return wrap(sollya_lib_div(as_SollyaObject(left).value, as_SollyaObject(right).value))

    def __pow__(self, op, modulo):
        return wrap(sollya_lib_pow(as_SollyaObject(self).value, as_SollyaObject(op).value))

    def __rpow__(op, self, modullo):
        return wrap(sollya_lib_pow(as_SollyaObject(self).value, as_SollyaObject(op).value))

    def __abs__(self):
        return wrap(sollya_lib_abs(as_SollyaObject(self).value))

    # --- comparisons ---
    def __richcmp__(SollyaObject self, py_other, int op):
        cdef SollyaObject other = as_SollyaObject(py_other)
        cdef sollya_obj_t res = NULL
        if op == Py_LT:   res = sollya_lib_cmp_less(self.value, other.value)
        elif op == Py_EQ:  res = sollya_lib_cmp_equal(self.value, other.value)
        elif op == Py_GT:  res = sollya_lib_cmp_greater(self.value, other.value)
        elif op == Py_LE:  res = sollya_lib_cmp_less_equal(self.value, other.value)
        elif op == Py_NE:  res = sollya_lib_cmp_not_equal(self.value, other.value)
        elif op == Py_GE:  res = sollya_lib_cmp_greater_equal(self.value, other.value)
        cdef bint b = sollya_lib_is_true(res)
        sollya_lib_clear_obj(res)
        return b

    def identical(self, SollyaObject other):
        return bool(sollya_lib_cmp_objs_structurally(self.value, other.value))

    def approx(self):
        return wrap(sollya_lib_approx(self.value))

    # --- container ---
    def __len__(self):
        cdef sollya_obj_t slen
        cdef int64_t ilen = -1
        slen = sollya_lib_length(self.value)
        if sollya_lib_obj_is_error(slen):
            sollya_lib_clear_obj(slen)
            raise ValueError("no length")
        if not sollya_lib_get_constant_as_int64(&ilen, slen):
            sollya_lib_clear_obj(slen)
            raise ValueError("length not integer")
        sollya_lib_clear_obj(slen)
        return ilen

    def __getitem__(self, index):
        cdef SollyaObject result = SollyaObject.__new__(SollyaObject)
        if sollya_lib_obj_is_list(self.value) or sollya_lib_obj_is_end_elliptic_list(self.value):
            if sollya_lib_get_element_in_list(&result.value, self.value, int(index)):
                return result
            raise IndexError("index out of range")
        raise ValueError("not a list")

    def __contains__(self, elt):
        res = sollya_lib_cmp_in(as_SollyaObject(elt).value, self.value)
        b = sollya_lib_is_true(res)
        sollya_lib_clear_obj(res)
        return b

    def __iter__(self):
        cdef sollya_obj_t *objs = NULL
        cdef int length = 0
        cdef int is_end_elliptic = 0
        if not (sollya_lib_obj_is_list(self.value) or sollya_lib_obj_is_end_elliptic_list(self.value)):
            raise ValueError("not iterable")
        if not sollya_lib_get_list_elements(&objs, &length, &is_end_elliptic, self.value):
            raise RuntimeError("list conversion failed")
        items = [wrap(objs[i]) for i in range(length)]
        sollya_lib_free(objs)
        for item in items:
            yield item

    # --- decomposition ---
    def arity(self):
        cdef int res
        if sollya_lib_get_function_arity(&res, self.value):
            return res
        raise ValueError("no arity")

    def operand(self, n):
        cdef SollyaObject result = SollyaObject.__new__(SollyaObject)
        if not sollya_lib_get_nth_subfunction(&result.value, self.value, n + 1):
            raise IndexError("operand index out of range")
        return result

    def operands(self):
        a = self.arity()
        return [self.operand(n) for n in range(a)]


# =================== Module-level functions ============================
def parse(expr_str):
    """Parse a Sollya expression string (must end with semicolon)."""
    if not expr_str.endswith(";"):
        expr_str = expr_str + ";"
    bs = _encode(expr_str)
    cdef sollya_obj_t res = sollya_lib_parse_string(bs)
    if res is NULL:
        raise ValueError(f"Failed to parse: {expr_str}")
    return wrap(res)

def S(expr_str):
    """Shorthand for parse."""
    return parse(expr_str)

def Interval(a, b):
    """Create a Sollya range [a, b]."""
    return wrap(sollya_lib_range(as_SollyaObject(a).value, as_SollyaObject(b).value))

# --- free variable ---
x = wrap(sollya_lib_free_variable())
_x_ = x

# --- math functions ---
def sqrt(op): return wrap(sollya_lib_sqrt(as_SollyaObject(op).value))
def exp(op): return wrap(sollya_lib_exp(as_SollyaObject(op).value))
def log(op): return wrap(sollya_lib_log(as_SollyaObject(op).value))
def log2(op): return wrap(sollya_lib_log2(as_SollyaObject(op).value))
def log10(op): return wrap(sollya_lib_log10(as_SollyaObject(op).value))
def sin(op): return wrap(sollya_lib_sin(as_SollyaObject(op).value))
def cos(op): return wrap(sollya_lib_cos(as_SollyaObject(op).value))
def tan(op): return wrap(sollya_lib_tan(as_SollyaObject(op).value))
def asin(op): return wrap(sollya_lib_asin(as_SollyaObject(op).value))
def acos(op): return wrap(sollya_lib_acos(as_SollyaObject(op).value))
def atan(op): return wrap(sollya_lib_atan(as_SollyaObject(op).value))
def sinh(op): return wrap(sollya_lib_sinh(as_SollyaObject(op).value))
def cosh(op): return wrap(sollya_lib_cosh(as_SollyaObject(op).value))
def tanh(op): return wrap(sollya_lib_tanh(as_SollyaObject(op).value))
def asinh(op): return wrap(sollya_lib_asinh(as_SollyaObject(op).value))
def acosh(op): return wrap(sollya_lib_acosh(as_SollyaObject(op).value))
def atanh(op): return wrap(sollya_lib_atanh(as_SollyaObject(op).value))
def erf(op): return wrap(sollya_lib_erf(as_SollyaObject(op).value))
def erfc(op): return wrap(sollya_lib_erfc(as_SollyaObject(op).value))
def log1p(op): return wrap(sollya_lib_log1p(as_SollyaObject(op).value))
def expm1(op): return wrap(sollya_lib_expm1(as_SollyaObject(op).value))
def ceil_sol(op): return wrap(sollya_lib_ceil(as_SollyaObject(op).value))
def floor_sol(op): return wrap(sollya_lib_floor(as_SollyaObject(op).value))
def nearestint(op): return wrap(sollya_lib_nearestint(as_SollyaObject(op).value))
def absolute(op): return wrap(sollya_lib_abs(as_SollyaObject(op).value))

# --- polynomial operations ---
def diff(op): return wrap(sollya_lib_diff(as_SollyaObject(op).value))
def horner(op): return wrap(sollya_lib_horner(as_SollyaObject(op).value))
def canonical(op): return wrap(sollya_lib_canonical(as_SollyaObject(op).value))
def expand_expr(op): return wrap(sollya_lib_expand(as_SollyaObject(op).value))
def simplify(op): return wrap(sollya_lib_simplify(as_SollyaObject(op).value))
def dirtysimplify(op): return wrap(sollya_lib_dirtysimplify(as_SollyaObject(op).value))
def degree(op): return wrap(sollya_lib_degree(as_SollyaObject(op).value))
def numerator(op): return wrap(sollya_lib_numerator(as_SollyaObject(op).value))
def denominator(op): return wrap(sollya_lib_denominator(as_SollyaObject(op).value))
def substitute(f, g): return wrap(sollya_lib_substitute(as_SollyaObject(f).value, as_SollyaObject(g).value))
def coeff(f, n): return wrap(sollya_lib_coeff(as_SollyaObject(f).value, as_SollyaObject(n).value))
def subpoly(f, lst): return wrap(sollya_lib_subpoly(as_SollyaObject(f).value, as_SollyaObject(lst).value))
def roundcoefficients(f, lst): return wrap(sollya_lib_roundcoefficients(as_SollyaObject(f).value, as_SollyaObject(lst).value))
def sup(op): return wrap(sollya_lib_sup(as_SollyaObject(op).value))
def inf(op): return wrap(sollya_lib_inf(as_SollyaObject(op).value))
def mid(op): return wrap(sollya_lib_mid(as_SollyaObject(op).value))
def evaluate(f, pt): return wrap(sollya_lib_evaluate(as_SollyaObject(f).value, as_SollyaObject(pt).value))

def taylor(f, n, pt):
    return wrap(sollya_lib_taylor(as_SollyaObject(f).value, as_SollyaObject(n).value, as_SollyaObject(pt).value))

def remez(f, n, interval):
    return wrap(sollya_lib_remez(as_SollyaObject(f).value, as_SollyaObject(n).value, as_SollyaObject(interval).value, NULL))

def fpminimax(f, n, formats, interval):
    return wrap(sollya_lib_fpminimax(as_SollyaObject(f).value, as_SollyaObject(n).value, as_SollyaObject(formats).value, as_SollyaObject(interval).value, NULL))

def infnorm(f, interval):
    return wrap(sollya_lib_infnorm(as_SollyaObject(f).value, as_SollyaObject(interval).value, NULL))

def supnorm(p, f, interval, mode, accuracy):
    return wrap(sollya_lib_supnorm(as_SollyaObject(p).value, as_SollyaObject(f).value, as_SollyaObject(interval).value, as_SollyaObject(mode).value, as_SollyaObject(accuracy).value))

def dirtyinfnorm(f, interval):
    return wrap(sollya_lib_dirtyinfnorm(as_SollyaObject(f).value, as_SollyaObject(interval).value))

def findzeros(f, interval):
    return wrap(sollya_lib_findzeros(as_SollyaObject(f).value, as_SollyaObject(interval).value))

def dirtyfindzeros(f, interval):
    return wrap(sollya_lib_dirtyfindzeros(as_SollyaObject(f).value, as_SollyaObject(interval).value))

def integral(f, interval):
    return wrap(sollya_lib_integral(as_SollyaObject(f).value, as_SollyaObject(interval).value))

def numberroots(f, interval):
    return wrap(sollya_lib_numberroots(as_SollyaObject(f).value, as_SollyaObject(interval).value))

def gcd(a, b):
    return wrap(sollya_lib_gcd(as_SollyaObject(a).value, as_SollyaObject(b).value))

def head(lst): return wrap(sollya_lib_head(as_SollyaObject(lst).value))
def tail(lst): return wrap(sollya_lib_tail(as_SollyaObject(lst).value))
def revert(lst): return wrap(sollya_lib_revert(as_SollyaObject(lst).value))
def sort_list(lst): return wrap(sollya_lib_sort(as_SollyaObject(lst).value))
def length(op): return wrap(sollya_lib_length(as_SollyaObject(op).value))

def mantissa(op): return wrap(sollya_lib_mantissa(as_SollyaObject(op).value))
def exponent_sol(op): return wrap(sollya_lib_exponent(as_SollyaObject(op).value))
def precision_sol(op): return wrap(sollya_lib_precision(as_SollyaObject(op).value))

# --- rounding ---
def round_sol(f, n, mode):
    return wrap(sollya_lib_round(as_SollyaObject(f).value, as_SollyaObject(n).value, as_SollyaObject(mode).value))

def rationalapprox(f, n):
    return wrap(sollya_lib_rationalapprox(as_SollyaObject(f).value, as_SollyaObject(n).value))

# --- format functions ---
def double_sol(op): return wrap(sollya_lib_double(as_SollyaObject(op).value))
def single_sol(op): return wrap(sollya_lib_single(as_SollyaObject(op).value))
def bfloat16_sol(op): return wrap(sollya_lib_bfloat16(as_SollyaObject(op).value))

# --- constants/objects ---
on = wrap(sollya_lib_on())
off = wrap(sollya_lib_off())
dyadic = wrap(sollya_lib_dyadic())
powers = wrap(sollya_lib_powers())
binary = wrap(sollya_lib_binary())
hexadecimal = wrap(sollya_lib_hexadecimal())
file_obj = wrap(sollya_lib_file())
postscript = wrap(sollya_lib_postscript())
postscriptfile = wrap(sollya_lib_postscriptfile())
perturb = wrap(sollya_lib_perturb())
RD = wrap(sollya_lib_round_down())
RU = wrap(sollya_lib_round_up())
RZ = wrap(sollya_lib_round_towards_zero())
RN = wrap(sollya_lib_round_to_nearest())
honorcoeffprec = wrap(sollya_lib_honorcoeffprec())
true_obj = wrap(sollya_lib_true())
false_obj = wrap(sollya_lib_false())
void_obj = wrap(sollya_lib_void())
default = wrap(sollya_lib_default())
decimal = wrap(sollya_lib_decimal())
sol_absolute = wrap(sollya_lib_absolute())
sol_relative = wrap(sollya_lib_relative())
fixed = wrap(sollya_lib_fixed())
floating = wrap(sollya_lib_floating())
error = wrap(sollya_lib_error())
pi = wrap(sollya_lib_pi())
doubleformat = wrap(sollya_lib_double_obj())
singleformat = wrap(sollya_lib_single_obj())
quadformat = wrap(sollya_lib_quad_obj())
halfprecisionformat = wrap(sollya_lib_halfprecision_obj())
bfloat16format = wrap(sollya_lib_bfloat16_obj())
doubleextendedformat = wrap(sollya_lib_doubleextended_obj())
doubledoubleformat = wrap(sollya_lib_double_double_obj())
tripledoubleformat = wrap(sollya_lib_triple_double_obj())

# --- settings ---
def set_prec(v): sollya_lib_set_prec(as_SollyaObject(v).value)
def get_prec(): return wrap(sollya_lib_get_prec())
def set_points(v): sollya_lib_set_points(as_SollyaObject(v).value)
def get_points(): return wrap(sollya_lib_get_points())
def set_diam(v): sollya_lib_set_diam(as_SollyaObject(v).value)
def get_diam(): return wrap(sollya_lib_get_diam())
def set_display(v): sollya_lib_set_display(as_SollyaObject(v).value)
def get_display(): return wrap(sollya_lib_get_display())
def set_verbosity(v): sollya_lib_set_verbosity(as_SollyaObject(v).value)
def get_verbosity(): return wrap(sollya_lib_get_verbosity())
def set_autosimplify(v): sollya_lib_set_autosimplify(as_SollyaObject(v).value)
def get_autosimplify(): return wrap(sollya_lib_get_autosimplify())
def set_canonical_mode(v): sollya_lib_set_canonical(as_SollyaObject(v).value)
def get_canonical_mode(): return wrap(sollya_lib_get_canonical())

# --- display hook ---
__displayhook = sys.displayhook
def autoprint(obj):
    if isinstance(obj, SollyaObject):
        sollya_lib_autoprint((<SollyaObject>obj).value, NULL)
    else:
        __displayhook(obj)
