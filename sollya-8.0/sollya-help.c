/*

  Copyright 2021 by

  Department of Computer Science & Engineering
  UAA College of Engineering
  University of Alaska Anchorage.

  Contributor Ch. Lauter

  christoph.lauter@christoph-lauter.org

  This software is a computer program whose purpose is to provide an
  environment for safe floating-point code development. It is
  particularly targeted to the automated implementation of
  mathematical floating-point libraries (libm). Amongst other features,
  it offers a certified infinity norm, an automatic polynomial
  implementer and a fast Remez algorithm.

  This software is governed by the CeCILL-C license under French law and
  abiding by the rules of distribution of free software.  You can  use,
  modify and/ or redistribute the software under the terms of the CeCILL-C
  license as circulated by CEA, CNRS and INRIA at the following URL
  "http://www.cecill.info".

  As a counterpart to the access to the source code and  rights to copy,
  modify and redistribute granted by the license, users are provided only
  with a limited warranty  and the software's author,  the holder of the
  economic rights,  and the successive licensors  have only  limited
  liability.

  In this respect, the user's attention is drawn to the risks associated
  with loading,  using,  modifying and/or developing or reproducing the
  software by the user in light of its specific status of free software,
  that may mean  that it is complicated to manipulate,  and  that  also
  therefore means  that it is reserved for developers  and  experienced
  professionals having in-depth computer knowledge. Users are therefore
  encouraged to load and test the software's suitability as regards their
  requirements in conditions enabling the security of their systems and/or
  data to be ensured and,  more generally, to use and operate it in the
  same conditions as regards security.

  The fact that you are presently reading this means that you have had
  knowledge of the CeCILL-C license and that you accept its terms.

  This program is distributed WITHOUT ANY WARRANTY; without even the
  implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.

*/

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include <string.h>

#include "general.h"
#include "help.h"
#include "sollya-help.h"

typedef struct __help_entry_struct_t help_entry_t;
struct __help_entry_struct_t {
  const char *topic;
  const char *help_text;
};

static const help_entry_t help_entry_table[] = {
    { "abs", HELP_ABS_TEXT },
    { "absolute", HELP_ABSOLUTE_TEXT },
    { "accurateinfnorm", HELP_ACCURATEINFNORM_TEXT },
    { "acos", HELP_ACOS_TEXT },
    { "acosh", HELP_ACOSH_TEXT },
    { "annotatefunction", HELP_ANNOTATEFUNCTION_TEXT },
    { "asciiplot", HELP_ASCIIPLOT_TEXT },
    { "asin", HELP_ASIN_TEXT },
    { "asinh", HELP_ASINH_TEXT },
    { "atan", HELP_ATAN_TEXT },
    { "atanh", HELP_ATANH_TEXT },
    { "autodiff", HELP_AUTODIFF_TEXT },
    { "autosimplify", HELP_AUTOSIMPLIFY_TEXT },
    { "bashevaluate", HELP_BASHEVALUATE_TEXT },
    { "bashexecute", HELP_BASHEXECUTE_TEXT },
    { "bezout", HELP_BEZOUT_TEXT },
    { "binary", HELP_BINARY_TEXT },
    { "bind", HELP_BIND_TEXT },
    { "boolean", HELP_BOOLEAN_TEXT },
    { "canonical", HELP_CANONICAL_TEXT },
    { "ceil", HELP_CEIL_TEXT },
    { "chebyshevform", HELP_CHEBYSHEVFORM_TEXT },
    { "checkinfnorm", HELP_CHECKINFNORM_TEXT },
    { "coeff", HELP_COEFF_TEXT },
    { "composepolynomials", HELP_COMPOSEPOLYNOMIALS_TEXT },
    { "constant", HELP_CONSTANT_TEXT },
    { "cos", HELP_COS_TEXT },
    { "cosh", HELP_COSH_TEXT },
    { "DD", HELP_DOUBLEDOUBLE_TEXT },
    { "decimal", HELP_DECIMAL_TEXT },
    { "default", HELP_DEFAULT_TEXT },
    { "degree", HELP_DEGREE_TEXT },
    { "DE", HELP_DOUBLEEXTENDED_TEXT },
    { "denominator", HELP_DENOMINATOR_TEXT },
    { "D", HELP_DOUBLE_TEXT },
    { "diam", HELP_DIAM_TEXT },
    { "dieonerrormode", HELP_DIEONERRORMODE_TEXT },
    { "diff", HELP_DIFF_TEXT },
    { "dirtyfindzeros", HELP_DIRTYFINDZEROS_TEXT },
    { "dirtyinfnorm", HELP_DIRTYINFNORM_TEXT },
    { "dirtyintegral", HELP_DIRTYINTEGRAL_TEXT },
    { "dirtysimplify", HELP_DIRTYSIMPLIFY_TEXT },
    { "display", HELP_DISPLAY_TEXT },
    { "div", HELP_DIVEUCL_TEXT },
    { "doubledouble", HELP_DOUBLEDOUBLE_TEXT },
    { "doubleextended", HELP_DOUBLEEXTENDED_TEXT },
    { "double", HELP_DOUBLE_TEXT },
    { "dyadic", HELP_DYADIC_TEXT },
    { "erfc", HELP_ERFC_TEXT },
    { "erf", HELP_ERF_TEXT },
    { "error", HELP_ERROR_TEXT },
    { "evaluate", HELP_EVALUATE_TEXT },
    { "execute", HELP_EXECUTE_TEXT },
    { "expand", HELP_EXPAND_TEXT },
    { "exp", HELP_EXP_TEXT },
    { "expm1", HELP_EXPM1_TEXT },
    { "exponent", HELP_EXPONENT_TEXT },
    { "externaldata", HELP_EXTERNALDATA_TEXT },
    { "externalplot", HELP_EXTERNALPLOT_TEXT },
    { "externalproc", HELP_EXTERNALPROC_TEXT },
    { "false", HELP_FALSE_TEXT },
    { "file", HELP_FILE_TEXT },
    { "findzeros", HELP_FINDZEROS_TEXT },
    { "fixed", HELP_FIXED_TEXT },
    { "floating", HELP_FLOATING_TEXT },
    { "floor", HELP_FLOOR_TEXT },
    { "fpminimax", HELP_FPMINIMAX_TEXT },
    { "fullparentheses", HELP_FULLPARENTHESES_TEXT },
    { "function", HELP_FUNCTION_TEXT },
    { "gcd", HELP_GCD_TEXT },
    { "getbacktrace", HELP_GETBACKTRACE_TEXT },
    { "getsuppressedmessages", HELP_GETSUPPRESSEDMESSAGES_TEXT },
    { "guessdegree", HELP_GUESSDEGREE_TEXT },
    { "halfprecision", HELP_HALFPRECISION_TEXT },
    { "head", HELP_HEAD_TEXT },
    { "&&", HELP_AND_TEXT },
    { ":.", HELP_APPEND_TEXT },
    { "~", HELP_APPROX_TEXT },
    { "@", HELP_CONCAT_TEXT },
    { "/", HELP_DIVIDE_TEXT },
    { "==", HELP_EQUAL_TEXT },
    { ">=", HELP_GE_TEXT },
    { ">", HELP_GT_TEXT },
    { "<=", HELP_LE_TEXT },
    { "<", HELP_LT_TEXT },
    { "-", HELP_MINUS_TEXT },
    { "*", HELP_MULT_TEXT },
    { "!=", HELP_NEQ_TEXT },
    { "!", HELP_NOT_TEXT },
    { "||", HELP_OR_TEXT },
    { "+", HELP_PLUS_TEXT },
    { "^", HELP_POWER_TEXT },
    { ".:", HELP_PREPEND_TEXT },
    { "hexadecimal", HELP_HEXADECIMAL_TEXT },
    { "honorcoeffprec", HELP_HONORCOEFFPREC_TEXT },
    { "hopitalrecursions", HELP_HOPITALRECURSIONS_TEXT },
    { "horner", HELP_HORNER_TEXT },
    { "HP", HELP_HALFPRECISION_TEXT },
    { "implementconstant", HELP_IMPLEMENTCONSTANT_TEXT },
    { "implementpoly", HELP_IMPLEMENTPOLY_TEXT },
    { "inf", HELP_INF_TEXT },
    { "infnorm", HELP_INFNORM_TEXT },
    { "in", HELP_IN_TEXT },
    { "integer", HELP_INTEGER_TEXT },
    { "integral", HELP_INTEGRAL_TEXT },
    { "interpolate", HELP_INTERPOLATE_TEXT },
    { "isbound", HELP_ISBOUND_TEXT },
    { "isevaluable", HELP_ISEVALUABLE_TEXT },
    { "length", HELP_LENGTH_TEXT },
    { "libraryconstant", HELP_LIBRARYCONSTANT_TEXT },
    { "library", HELP_LIBRARY_TEXT },
    { "list of", HELP_LISTOF_TEXT },
    { "log10", HELP_LOG10_TEXT },
    { "log1p", HELP_LOG1P_TEXT },
    { "log2", HELP_LOG2_TEXT },
    { "log", HELP_LOG_TEXT },
    { "mantissa", HELP_MANTISSA_TEXT },
    { "max", HELP_MAX_TEXT },
    { "mid", HELP_MID_TEXT },
    { "midpointmode", HELP_MIDPOINTMODE_TEXT },
    { "min", HELP_MIN_TEXT },
    { "mod", HELP_MODEUCL_TEXT },
    { "nearestint", HELP_NEARESTINT_TEXT },
    { "nop", HELP_NOP_TEXT },
    { "numberroots", HELP_NUMBERROOTS_TEXT },
    { "numerator", HELP_NUMERATOR_TEXT },
    { "object", HELP_OBJECT_TEXT },
    { "objectname", HELP_OBJECTNAME_TEXT },
    { "off", HELP_OFF_TEXT },
    { "on", HELP_ON_TEXT },
    { "parse", HELP_PARSE_TEXT },
    { "perturb", HELP_PERTURB_TEXT },
    { "pi", HELP_PI_TEXT },
    { "plot", HELP_PLOT_TEXT },
    { "points", HELP_POINTS_TEXT },
    { "postscriptfile", HELP_POSTSCRIPTFILE_TEXT },
    { "postscript", HELP_POSTSCRIPT_TEXT },
    { "powers", HELP_POWERS_TEXT },
    { "prec", HELP_PREC_TEXT },
    { "precision", HELP_PRECISION_TEXT },
    { "printdouble", HELP_PRINTDOUBLE_TEXT },
    { "printexpansion", HELP_PRINTEXPANSION_TEXT },
    { "print", HELP_PRINT_TEXT },
    { "printsingle", HELP_PRINTFLOAT_TEXT },
    { "printxml", HELP_PRINTXML_TEXT },
    { "procedure", HELP_PROCEDURE_TEXT },
    { "proc", HELP_PROC_TEXT },
    { "QD", HELP_QD_TEXT },
    { "quad", HELP_QUAD_TEXT },
    { "quit", HELP_QUIT_TEXT },
    { "range", HELP_RANGE_TEXT },
    { "rationalapprox", HELP_RATIONALAPPROX_TEXT },
    { "rationalmode", HELP_RATIONALMODE_TEXT },
    { "RD", HELP_RD_TEXT },
    { "readfile", HELP_READFILE_TEXT },
    { "readxml", HELP_READXML_TEXT },
    { "relative", HELP_RELATIVE_TEXT },
    { "remez", HELP_REMEZ_TEXT },
    { "rename", HELP_RENAME_TEXT },
    { "restart", HELP_RESTART_TEXT },
    { "return", HELP_RETURN_TEXT },
    { "revert", HELP_REVERT_TEXT },
    { "RN", HELP_RN_TEXT },
    { "roundcoefficients", HELP_ROUNDCOEFFICIENTS_TEXT },
    { "roundcorrectly", HELP_ROUNDCORRECTLY_TEXT },
    { "round", HELP_ROUND_TEXT },
    { "roundingwarnings", HELP_ROUNDINGWARNINGS_TEXT },
    { "RU", HELP_RU_TEXT },
    { "RZ", HELP_RZ_TEXT },
    { "searchgal", HELP_SEARCHGAL_TEXT },
    { "SG", HELP_SINGLE_TEXT },
    { "showmessagenumbers", HELP_SHOWMESSAGENUMBERS_TEXT },
    { "simplify", HELP_SIMPLIFY_TEXT },
    { "single", HELP_SINGLE_TEXT },
    { "sin", HELP_SIN_TEXT },
    { "sinh", HELP_SINH_TEXT },
    { "sort", HELP_SORT_TEXT },
    { "sqrt", HELP_SQRT_TEXT },
    { "string", HELP_STRING_TEXT },
    { "subpoly", HELP_SUBPOLY_TEXT },
    { "substitute", HELP_SUBSTITUTE_TEXT },
    { "sup", HELP_SUP_TEXT },
    { "supnorm", HELP_SUPNORM_TEXT },
    { "suppressmessage", HELP_SUPPRESSMESSAGE_TEXT },
    { "tail", HELP_TAIL_TEXT },
    { "tan", HELP_TAN_TEXT },
    { "tanh", HELP_TANH_TEXT },
    { "taylorform", HELP_TAYLORFORM_TEXT },
    { "taylor", HELP_TAYLOR_TEXT },
    { "taylorrecursions", HELP_TAYLORRECURSIONS_TEXT },
    { "TD", HELP_TRIPLEDOUBLE_TEXT },
    { "time", HELP_TIME_TEXT },
    { "timing", HELP_TIMING_TEXT },
    { "tripledouble", HELP_TRIPLEDOUBLE_TEXT },
    { "true", HELP_TRUE_TEXT },
    { "unsuppressmessage", HELP_UNSUPPRESSMESSAGE_TEXT },
    { "var", HELP_VAR_TEXT },
    { "verbosity", HELP_VERBOSITY_TEXT },
    { "void", HELP_VOID_TEXT },
    { "worstcase", HELP_WORSTCASE_TEXT },
    { "write", HELP_WRITE_TEXT },
    { "_x_", HELP_XFREEVARIABLE_TEXT },
    { NULL, NULL }
};


const char *sollya_get_help_text(const char *topic) {
  size_t i;

  for (i=((size_t) 0); help_entry_table[i].topic != NULL; i++) {
    if (strcmp(topic, help_entry_table[i].topic) == 0)
      return help_entry_table[i].help_text;
  }
  return NULL;
}

void sollya_print_help_text(const char *topic) {
  const char *text;

  text = sollya_get_help_text(topic);
  if (text == NULL) {
    sollyaPrintf("No help text is available for the topic \"%s\".\n", topic);
  } else {
    sollyaPrintf("%s", text);
  }
}

