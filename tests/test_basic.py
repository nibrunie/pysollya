"""Basic tests for pysollya."""
import pysollya
from pysollya import *


def test_import():
    assert hasattr(pysollya, "x")
    assert hasattr(pysollya, "sin")
    assert hasattr(pysollya, "remez")


def test_parse():
    r = S("1 + 2")
    assert float(r) == 3.0


def test_interval():
    iv = Interval(-1, 1)
    assert repr(iv) == "[-1;1]"


def test_arithmetic():
    a, b = S("3"), S("5")
    assert float(a + b) == 8.0
    assert float(a * b) == 15.0
    assert float(a - b) == -2.0
    assert float(a / b) == 0.6
    assert float(a ** S("2")) == 9.0


def test_math_functions():
    f = sin(x)
    assert "sin" in repr(f)
    g = exp(x) + cos(x)
    assert "exp" in repr(g)
    assert "cos" in repr(g)


def test_polynomial_ops():
    p = x ** 3 + S("2") * x ** 2 + S("3") * x + S("4")
    assert int(degree(p)) == 3
    h = horner(p)
    assert repr(h)  # non-empty
    d = diff(p)
    assert repr(d)


def test_remez():
    f = sin(x) / x
    iv = Interval(-1, 1)
    p = remez(f, 5, iv)
    assert int(degree(p)) == 5
    err = infnorm(f - p, iv)
    assert repr(err)


def test_taylor():
    t = taylor(sin(x), 5, S("0"))
    assert repr(t)


def test_settings():
    old = get_prec()
    set_prec(S("200"))
    assert int(get_prec()) == 200
    set_prec(old)


def test_constants():
    assert repr(pi) == "pi"
    assert repr(on)
    assert repr(off)


if __name__ == "__main__":
    for name, fn in list(globals().items()):
        if name.startswith("test_") and callable(fn):
            fn()
            print(f"  PASS: {name}")
    print("All tests passed!")
