/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 1

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1


/* Substitute the variable and function names.  */
#define yyparse         miniyyparse
#define yylex           miniyylex
#define yyerror         miniyyerror
#define yydebug         miniyydebug
#define yynerrs         miniyynerrs

/* First part of user prologue.  */
#line 68 "miniparser.y"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include "base-functions.h"
#include "expression.h"
#include "assignment.h"
#include "chain.h"
#include "general.h"
#include "execute.h"
#include "miniparser.h"

/* Mess with the mallocs used by the parser */
extern void *parserCalloc(size_t, size_t);
extern void *parserMalloc(size_t);
extern void *parserRealloc(void *, size_t);
extern void parserFree(void *);
#undef malloc
#undef realloc
#undef calloc
#undef free
#define malloc parserMalloc
#define realloc parserRealloc
#define calloc parserCalloc
#define free safeFree
/* End of the malloc mess */

#define YYERROR_VERBOSE 1
#define YYFPRINTF sollyaFprintf

extern int miniyylex(YYSTYPE *lvalp, void *scanner);

void miniyyerror(void *myScanner, const char *message) {
  UNUSED_PARAM(myScanner);
  printMessage(1,SOLLYA_MSG_SYNTAX_ERROR_ENCOUNTERED_WHILE_PARSING,"Warning: %s. Will try to continue parsing (expecting \";\"). May leak memory.\n",message);
}


#line 116 "miniparser.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

/* Use api.header.include to #include this header
   instead of duplicating it here.  */
#ifndef YY_MINIYY_MINIPARSER_H_INCLUDED
# define YY_MINIYY_MINIPARSER_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int miniyydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    CONSTANTTOKEN = 258,           /* "decimal constant"  */
    MIDPOINTCONSTANTTOKEN = 259,   /* "interval"  */
    DYADICCONSTANTTOKEN = 260,     /* "dyadic constant"  */
    HEXCONSTANTTOKEN = 261,        /* "constant in memory notation"  */
    HEXADECIMALCONSTANTTOKEN = 262, /* "hexadecimal constant"  */
    BINARYCONSTANTTOKEN = 263,     /* "binary constant"  */
    PITOKEN = 264,                 /* "pi"  */
    IDENTIFIERTOKEN = 265,         /* "identifier"  */
    STRINGTOKEN = 266,             /* "character string"  */
    LPARTOKEN = 267,               /* "("  */
    RPARTOKEN = 268,               /* ")"  */
    LBRACKETTOKEN = 269,           /* "["  */
    RBRACKETTOKEN = 270,           /* "]"  */
    EQUALTOKEN = 271,              /* "="  */
    ASSIGNEQUALTOKEN = 272,        /* ":="  */
    COMPAREEQUALTOKEN = 273,       /* "=="  */
    COMMATOKEN = 274,              /* ","  */
    EXCLAMATIONTOKEN = 275,        /* "!"  */
    SEMICOLONTOKEN = 276,          /* ";"  */
    STARLEFTANGLETOKEN = 277,      /* "*<"  */
    LEFTANGLETOKEN = 278,          /* "<"  */
    RIGHTANGLEUNDERSCORETOKEN = 279, /* ">_"  */
    RIGHTANGLEDOTTOKEN = 280,      /* ">."  */
    RIGHTANGLESTARTOKEN = 281,     /* ">*"  */
    RIGHTANGLETOKEN = 282,         /* ">"  */
    DOTSTOKEN = 283,               /* "..."  */
    DOTTOKEN = 284,                /* "."  */
    QUESTIONMARKTOKEN = 285,       /* "?"  */
    VERTBARTOKEN = 286,            /* "|"  */
    ATTOKEN = 287,                 /* "@"  */
    DOUBLECOLONTOKEN = 288,        /* "::"  */
    COLONTOKEN = 289,              /* ":"  */
    DOTCOLONTOKEN = 290,           /* ".:"  */
    COLONDOTTOKEN = 291,           /* ":."  */
    EXCLAMATIONEQUALTOKEN = 292,   /* "!="  */
    APPROXTOKEN = 293,             /* "~"  */
    ANDTOKEN = 294,                /* "&&"  */
    ORTOKEN = 295,                 /* "||"  */
    PLUSTOKEN = 296,               /* "+"  */
    MINUSTOKEN = 297,              /* "-"  */
    MULTOKEN = 298,                /* "*"  */
    DIVTOKEN = 299,                /* "/"  */
    POWTOKEN = 300,                /* "^"  */
    SQRTTOKEN = 301,               /* "sqrt"  */
    EXPTOKEN = 302,                /* "exp"  */
    FREEVARTOKEN = 303,            /* "_x_"  */
    LOGTOKEN = 304,                /* "log"  */
    LOG2TOKEN = 305,               /* "log2"  */
    LOG10TOKEN = 306,              /* "log10"  */
    SINTOKEN = 307,                /* "sin"  */
    COSTOKEN = 308,                /* "cos"  */
    TANTOKEN = 309,                /* "tan"  */
    ASINTOKEN = 310,               /* "asin"  */
    ACOSTOKEN = 311,               /* "acos"  */
    ATANTOKEN = 312,               /* "atan"  */
    SINHTOKEN = 313,               /* "sinh"  */
    COSHTOKEN = 314,               /* "cosh"  */
    TANHTOKEN = 315,               /* "tanh"  */
    ASINHTOKEN = 316,              /* "asinh"  */
    ACOSHTOKEN = 317,              /* "acosh"  */
    ATANHTOKEN = 318,              /* "atanh"  */
    ABSTOKEN = 319,                /* "abs"  */
    ERFTOKEN = 320,                /* "erf"  */
    ERFCTOKEN = 321,               /* "erfc"  */
    LOG1PTOKEN = 322,              /* "log1p"  */
    EXPM1TOKEN = 323,              /* "expm1"  */
    DOUBLETOKEN = 324,             /* "D"  */
    SINGLETOKEN = 325,             /* "SG"  */
    HALFPRECISIONTOKEN = 326,      /* "HP"  */
    QUADTOKEN = 327,               /* "QD"  */
    DOUBLEDOUBLETOKEN = 328,       /* "DD"  */
    TRIPLEDOUBLETOKEN = 329,       /* "TD"  */
    DOUBLEEXTENDEDTOKEN = 330,     /* "DE"  */
    CEILTOKEN = 331,               /* "ceil"  */
    FLOORTOKEN = 332,              /* "floor"  */
    NEARESTINTTOKEN = 333,         /* "nearestint"  */
    HEADTOKEN = 334,               /* "head"  */
    REVERTTOKEN = 335,             /* "revert"  */
    SORTTOKEN = 336,               /* "sort"  */
    TAILTOKEN = 337,               /* "tail"  */
    MANTISSATOKEN = 338,           /* "mantissa"  */
    EXPONENTTOKEN = 339,           /* "exponent"  */
    PRECISIONTOKEN = 340,          /* "precision"  */
    ROUNDCORRECTLYTOKEN = 341,     /* "roundcorrectly"  */
    PRECTOKEN = 342,               /* "prec"  */
    POINTSTOKEN = 343,             /* "points"  */
    DIAMTOKEN = 344,               /* "diam"  */
    DISPLAYTOKEN = 345,            /* "display"  */
    VERBOSITYTOKEN = 346,          /* "verbosity"  */
    SHOWMESSAGENUMBERSTOKEN = 347, /* "showmessagenumbers"  */
    CANONICALTOKEN = 348,          /* "canonical"  */
    AUTOSIMPLIFYTOKEN = 349,       /* "autosimplify"  */
    TAYLORRECURSIONSTOKEN = 350,   /* "taylorrecursions"  */
    TIMINGTOKEN = 351,             /* "timing"  */
    TIMETOKEN = 352,               /* "time"  */
    FULLPARENTHESESTOKEN = 353,    /* "fullparentheses"  */
    MIDPOINTMODETOKEN = 354,       /* "midpointmode"  */
    DIEONERRORMODETOKEN = 355,     /* "dieonerrormode"  */
    SUPPRESSWARNINGSTOKEN = 356,   /* "roundingwarnings"  */
    RATIONALMODETOKEN = 357,       /* "rationalmode"  */
    HOPITALRECURSIONSTOKEN = 358,  /* "hopitalrecursions"  */
    ONTOKEN = 359,                 /* "on"  */
    OFFTOKEN = 360,                /* "off"  */
    DYADICTOKEN = 361,             /* "dyadic"  */
    POWERSTOKEN = 362,             /* "powers"  */
    BINARYTOKEN = 363,             /* "binary"  */
    HEXADECIMALTOKEN = 364,        /* "hexadecimal"  */
    FILETOKEN = 365,               /* "file"  */
    POSTSCRIPTTOKEN = 366,         /* "postscript"  */
    POSTSCRIPTFILETOKEN = 367,     /* "postscriptfile"  */
    PERTURBTOKEN = 368,            /* "perturb"  */
    MINUSWORDTOKEN = 369,          /* "RD"  */
    PLUSWORDTOKEN = 370,           /* "RU"  */
    ZEROWORDTOKEN = 371,           /* "RZ"  */
    NEARESTTOKEN = 372,            /* "RN"  */
    HONORCOEFFPRECTOKEN = 373,     /* "honorcoeffprec"  */
    TRUETOKEN = 374,               /* "true"  */
    FALSETOKEN = 375,              /* "false"  */
    DEFAULTTOKEN = 376,            /* "default"  */
    MATCHTOKEN = 377,              /* "match"  */
    WITHTOKEN = 378,               /* "with"  */
    ABSOLUTETOKEN = 379,           /* "absolute"  */
    DECIMALTOKEN = 380,            /* "decimal"  */
    RELATIVETOKEN = 381,           /* "relative"  */
    FIXEDTOKEN = 382,              /* "fixed"  */
    FLOATINGTOKEN = 383,           /* "floating"  */
    ERRORTOKEN = 384,              /* "error"  */
    QUITTOKEN = 385,               /* "quit"  */
    FALSEQUITTOKEN = 386,          /* "quit in an included file"  */
    FALSERESTARTTOKEN = 387,       /* "restart"  */
    LIBRARYTOKEN = 388,            /* "library"  */
    LIBRARYCONSTANTTOKEN = 389,    /* "libraryconstant"  */
    DIFFTOKEN = 390,               /* "diff"  */
    DIRTYSIMPLIFYTOKEN = 391,      /* "dirtysimplify"  */
    REMEZTOKEN = 392,              /* "remez"  */
    ANNOTATEFUNCTIONTOKEN = 393,   /* "annotatefunction"  */
    BASHEVALUATETOKEN = 394,       /* "bashevaluate"  */
    GETSUPPRESSEDMESSAGESTOKEN = 395, /* "getsuppressedmessages"  */
    GETBACKTRACETOKEN = 396,       /* "getbacktrace"  */
    FPMINIMAXTOKEN = 397,          /* "fpminimax"  */
    HORNERTOKEN = 398,             /* "horner"  */
    EXPANDTOKEN = 399,             /* "expand"  */
    SIMPLIFYSAFETOKEN = 400,       /* "simplify"  */
    TAYLORTOKEN = 401,             /* "taylor"  */
    TAYLORFORMTOKEN = 402,         /* "taylorform"  */
    CHEBYSHEVFORMTOKEN = 403,      /* "chebyshevform"  */
    AUTODIFFTOKEN = 404,           /* "autodiff"  */
    DEGREETOKEN = 405,             /* "degree"  */
    NUMERATORTOKEN = 406,          /* "numerator"  */
    DENOMINATORTOKEN = 407,        /* "denominator"  */
    SUBSTITUTETOKEN = 408,         /* "substitute"  */
    COMPOSEPOLYNOMIALSTOKEN = 409, /* "composepolynomials"  */
    BEZOUTTOKEN = 410,             /* "bezout"  */
    COEFFTOKEN = 411,              /* "coeff"  */
    SUBPOLYTOKEN = 412,            /* "subpoly"  */
    ROUNDCOEFFICIENTSTOKEN = 413,  /* "roundcoefficients"  */
    RATIONALAPPROXTOKEN = 414,     /* "rationalapprox"  */
    ACCURATEINFNORMTOKEN = 415,    /* "accurateinfnorm"  */
    ROUNDTOFORMATTOKEN = 416,      /* "round"  */
    EVALUATETOKEN = 417,           /* "evaluate"  */
    LENGTHTOKEN = 418,             /* "length"  */
    OBJECTNAMETOKEN = 419,         /* "objectname"  */
    INFTOKEN = 420,                /* "inf"  */
    MIDTOKEN = 421,                /* "mid"  */
    SUPTOKEN = 422,                /* "sup"  */
    MINTOKEN = 423,                /* "min"  */
    MAXTOKEN = 424,                /* "max"  */
    READXMLTOKEN = 425,            /* "readxml"  */
    PARSETOKEN = 426,              /* "parse"  */
    PRINTTOKEN = 427,              /* "print"  */
    PRINTXMLTOKEN = 428,           /* "printxml"  */
    PLOTTOKEN = 429,               /* "plot"  */
    PRINTHEXATOKEN = 430,          /* "printhexa"  */
    PRINTFLOATTOKEN = 431,         /* "printfloat"  */
    PRINTBINARYTOKEN = 432,        /* "printbinary"  */
    SUPPRESSMESSAGETOKEN = 433,    /* "suppressmessage"  */
    UNSUPPRESSMESSAGETOKEN = 434,  /* "unsuppressmessage"  */
    PRINTEXPANSIONTOKEN = 435,     /* "printexpansion"  */
    BASHEXECUTETOKEN = 436,        /* "bashexecute"  */
    EXTERNALPLOTTOKEN = 437,       /* "externalplot"  */
    WRITETOKEN = 438,              /* "write"  */
    ASCIIPLOTTOKEN = 439,          /* "asciiplot"  */
    RENAMETOKEN = 440,             /* "rename"  */
    BINDTOKEN = 441,               /* "bind"  */
    INFNORMTOKEN = 442,            /* "infnorm"  */
    SUPNORMTOKEN = 443,            /* "supnorm"  */
    FINDZEROSTOKEN = 444,          /* "findzeros"  */
    FPFINDZEROSTOKEN = 445,        /* "fpfindzeros"  */
    DIRTYINFNORMTOKEN = 446,       /* "dirtyinfnorm"  */
    GCDTOKEN = 447,                /* "gcd"  */
    EUCLDIVTOKEN = 448,            /* "div"  */
    EUCLMODTOKEN = 449,            /* "mod"  */
    NUMBERROOTSTOKEN = 450,        /* "numberroots"  */
    INTEGRALTOKEN = 451,           /* "integral"  */
    DIRTYINTEGRALTOKEN = 452,      /* "dirtyintegral"  */
    WORSTCASETOKEN = 453,          /* "worstcase"  */
    IMPLEMENTPOLYTOKEN = 454,      /* "implementpoly"  */
    IMPLEMENTCONSTTOKEN = 455,     /* "implementconst"  */
    INTERPOLATETOKEN = 456,        /* "interpolate"  */
    CHECKINFNORMTOKEN = 457,       /* "checkinfnorm"  */
    ZERODENOMINATORSTOKEN = 458,   /* "zerodenominators"  */
    ISEVALUABLETOKEN = 459,        /* "isevaluable"  */
    SEARCHGALTOKEN = 460,          /* "searchgal"  */
    GUESSDEGREETOKEN = 461,        /* "guessdegree"  */
    DIRTYFINDZEROSTOKEN = 462,     /* "dirtyfindzeros"  */
    IFTOKEN = 463,                 /* "if"  */
    THENTOKEN = 464,               /* "then"  */
    ELSETOKEN = 465,               /* "else"  */
    FORTOKEN = 466,                /* "for"  */
    INTOKEN = 467,                 /* "in"  */
    FROMTOKEN = 468,               /* "from"  */
    TOTOKEN = 469,                 /* "to"  */
    BYTOKEN = 470,                 /* "by"  */
    DOTOKEN = 471,                 /* "do"  */
    BEGINTOKEN = 472,              /* "begin"  */
    ENDTOKEN = 473,                /* "end"  */
    LEFTCURLYBRACETOKEN = 474,     /* "{"  */
    RIGHTCURLYBRACETOKEN = 475,    /* "}"  */
    WHILETOKEN = 476,              /* "while"  */
    READFILETOKEN = 477,           /* "readfile"  */
    ISBOUNDTOKEN = 478,            /* "isbound"  */
    EXECUTETOKEN = 479,            /* "execute"  */
    EXTERNALPROCTOKEN = 480,       /* "externalproc"  */
    EXTERNALDATATOKEN = 481,       /* "externaldata"  */
    VOIDTOKEN = 482,               /* "void"  */
    CONSTANTTYPETOKEN = 483,       /* "constant"  */
    FUNCTIONTOKEN = 484,           /* "function"  */
    OBJECTTOKEN = 485,             /* "object"  */
    RANGETOKEN = 486,              /* "range"  */
    INTEGERTOKEN = 487,            /* "integer"  */
    STRINGTYPETOKEN = 488,         /* "string"  */
    BOOLEANTOKEN = 489,            /* "boolean"  */
    LISTTOKEN = 490,               /* "list"  */
    OFTOKEN = 491,                 /* "of"  */
    VARTOKEN = 492,                /* "var"  */
    PROCTOKEN = 493,               /* "proc"  */
    PROCEDURETOKEN = 494,          /* "procedure"  */
    RETURNTOKEN = 495,             /* "return"  */
    NOPTOKEN = 496                 /* "nop"  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif
/* Token kinds.  */
#define YYEMPTY -2
#define YYEOF 0
#define YYerror 256
#define YYUNDEF 257
#define CONSTANTTOKEN 258
#define MIDPOINTCONSTANTTOKEN 259
#define DYADICCONSTANTTOKEN 260
#define HEXCONSTANTTOKEN 261
#define HEXADECIMALCONSTANTTOKEN 262
#define BINARYCONSTANTTOKEN 263
#define PITOKEN 264
#define IDENTIFIERTOKEN 265
#define STRINGTOKEN 266
#define LPARTOKEN 267
#define RPARTOKEN 268
#define LBRACKETTOKEN 269
#define RBRACKETTOKEN 270
#define EQUALTOKEN 271
#define ASSIGNEQUALTOKEN 272
#define COMPAREEQUALTOKEN 273
#define COMMATOKEN 274
#define EXCLAMATIONTOKEN 275
#define SEMICOLONTOKEN 276
#define STARLEFTANGLETOKEN 277
#define LEFTANGLETOKEN 278
#define RIGHTANGLEUNDERSCORETOKEN 279
#define RIGHTANGLEDOTTOKEN 280
#define RIGHTANGLESTARTOKEN 281
#define RIGHTANGLETOKEN 282
#define DOTSTOKEN 283
#define DOTTOKEN 284
#define QUESTIONMARKTOKEN 285
#define VERTBARTOKEN 286
#define ATTOKEN 287
#define DOUBLECOLONTOKEN 288
#define COLONTOKEN 289
#define DOTCOLONTOKEN 290
#define COLONDOTTOKEN 291
#define EXCLAMATIONEQUALTOKEN 292
#define APPROXTOKEN 293
#define ANDTOKEN 294
#define ORTOKEN 295
#define PLUSTOKEN 296
#define MINUSTOKEN 297
#define MULTOKEN 298
#define DIVTOKEN 299
#define POWTOKEN 300
#define SQRTTOKEN 301
#define EXPTOKEN 302
#define FREEVARTOKEN 303
#define LOGTOKEN 304
#define LOG2TOKEN 305
#define LOG10TOKEN 306
#define SINTOKEN 307
#define COSTOKEN 308
#define TANTOKEN 309
#define ASINTOKEN 310
#define ACOSTOKEN 311
#define ATANTOKEN 312
#define SINHTOKEN 313
#define COSHTOKEN 314
#define TANHTOKEN 315
#define ASINHTOKEN 316
#define ACOSHTOKEN 317
#define ATANHTOKEN 318
#define ABSTOKEN 319
#define ERFTOKEN 320
#define ERFCTOKEN 321
#define LOG1PTOKEN 322
#define EXPM1TOKEN 323
#define DOUBLETOKEN 324
#define SINGLETOKEN 325
#define HALFPRECISIONTOKEN 326
#define QUADTOKEN 327
#define DOUBLEDOUBLETOKEN 328
#define TRIPLEDOUBLETOKEN 329
#define DOUBLEEXTENDEDTOKEN 330
#define CEILTOKEN 331
#define FLOORTOKEN 332
#define NEARESTINTTOKEN 333
#define HEADTOKEN 334
#define REVERTTOKEN 335
#define SORTTOKEN 336
#define TAILTOKEN 337
#define MANTISSATOKEN 338
#define EXPONENTTOKEN 339
#define PRECISIONTOKEN 340
#define ROUNDCORRECTLYTOKEN 341
#define PRECTOKEN 342
#define POINTSTOKEN 343
#define DIAMTOKEN 344
#define DISPLAYTOKEN 345
#define VERBOSITYTOKEN 346
#define SHOWMESSAGENUMBERSTOKEN 347
#define CANONICALTOKEN 348
#define AUTOSIMPLIFYTOKEN 349
#define TAYLORRECURSIONSTOKEN 350
#define TIMINGTOKEN 351
#define TIMETOKEN 352
#define FULLPARENTHESESTOKEN 353
#define MIDPOINTMODETOKEN 354
#define DIEONERRORMODETOKEN 355
#define SUPPRESSWARNINGSTOKEN 356
#define RATIONALMODETOKEN 357
#define HOPITALRECURSIONSTOKEN 358
#define ONTOKEN 359
#define OFFTOKEN 360
#define DYADICTOKEN 361
#define POWERSTOKEN 362
#define BINARYTOKEN 363
#define HEXADECIMALTOKEN 364
#define FILETOKEN 365
#define POSTSCRIPTTOKEN 366
#define POSTSCRIPTFILETOKEN 367
#define PERTURBTOKEN 368
#define MINUSWORDTOKEN 369
#define PLUSWORDTOKEN 370
#define ZEROWORDTOKEN 371
#define NEARESTTOKEN 372
#define HONORCOEFFPRECTOKEN 373
#define TRUETOKEN 374
#define FALSETOKEN 375
#define DEFAULTTOKEN 376
#define MATCHTOKEN 377
#define WITHTOKEN 378
#define ABSOLUTETOKEN 379
#define DECIMALTOKEN 380
#define RELATIVETOKEN 381
#define FIXEDTOKEN 382
#define FLOATINGTOKEN 383
#define ERRORTOKEN 384
#define QUITTOKEN 385
#define FALSEQUITTOKEN 386
#define FALSERESTARTTOKEN 387
#define LIBRARYTOKEN 388
#define LIBRARYCONSTANTTOKEN 389
#define DIFFTOKEN 390
#define DIRTYSIMPLIFYTOKEN 391
#define REMEZTOKEN 392
#define ANNOTATEFUNCTIONTOKEN 393
#define BASHEVALUATETOKEN 394
#define GETSUPPRESSEDMESSAGESTOKEN 395
#define GETBACKTRACETOKEN 396
#define FPMINIMAXTOKEN 397
#define HORNERTOKEN 398
#define EXPANDTOKEN 399
#define SIMPLIFYSAFETOKEN 400
#define TAYLORTOKEN 401
#define TAYLORFORMTOKEN 402
#define CHEBYSHEVFORMTOKEN 403
#define AUTODIFFTOKEN 404
#define DEGREETOKEN 405
#define NUMERATORTOKEN 406
#define DENOMINATORTOKEN 407
#define SUBSTITUTETOKEN 408
#define COMPOSEPOLYNOMIALSTOKEN 409
#define BEZOUTTOKEN 410
#define COEFFTOKEN 411
#define SUBPOLYTOKEN 412
#define ROUNDCOEFFICIENTSTOKEN 413
#define RATIONALAPPROXTOKEN 414
#define ACCURATEINFNORMTOKEN 415
#define ROUNDTOFORMATTOKEN 416
#define EVALUATETOKEN 417
#define LENGTHTOKEN 418
#define OBJECTNAMETOKEN 419
#define INFTOKEN 420
#define MIDTOKEN 421
#define SUPTOKEN 422
#define MINTOKEN 423
#define MAXTOKEN 424
#define READXMLTOKEN 425
#define PARSETOKEN 426
#define PRINTTOKEN 427
#define PRINTXMLTOKEN 428
#define PLOTTOKEN 429
#define PRINTHEXATOKEN 430
#define PRINTFLOATTOKEN 431
#define PRINTBINARYTOKEN 432
#define SUPPRESSMESSAGETOKEN 433
#define UNSUPPRESSMESSAGETOKEN 434
#define PRINTEXPANSIONTOKEN 435
#define BASHEXECUTETOKEN 436
#define EXTERNALPLOTTOKEN 437
#define WRITETOKEN 438
#define ASCIIPLOTTOKEN 439
#define RENAMETOKEN 440
#define BINDTOKEN 441
#define INFNORMTOKEN 442
#define SUPNORMTOKEN 443
#define FINDZEROSTOKEN 444
#define FPFINDZEROSTOKEN 445
#define DIRTYINFNORMTOKEN 446
#define GCDTOKEN 447
#define EUCLDIVTOKEN 448
#define EUCLMODTOKEN 449
#define NUMBERROOTSTOKEN 450
#define INTEGRALTOKEN 451
#define DIRTYINTEGRALTOKEN 452
#define WORSTCASETOKEN 453
#define IMPLEMENTPOLYTOKEN 454
#define IMPLEMENTCONSTTOKEN 455
#define INTERPOLATETOKEN 456
#define CHECKINFNORMTOKEN 457
#define ZERODENOMINATORSTOKEN 458
#define ISEVALUABLETOKEN 459
#define SEARCHGALTOKEN 460
#define GUESSDEGREETOKEN 461
#define DIRTYFINDZEROSTOKEN 462
#define IFTOKEN 463
#define THENTOKEN 464
#define ELSETOKEN 465
#define FORTOKEN 466
#define INTOKEN 467
#define FROMTOKEN 468
#define TOTOKEN 469
#define BYTOKEN 470
#define DOTOKEN 471
#define BEGINTOKEN 472
#define ENDTOKEN 473
#define LEFTCURLYBRACETOKEN 474
#define RIGHTCURLYBRACETOKEN 475
#define WHILETOKEN 476
#define READFILETOKEN 477
#define ISBOUNDTOKEN 478
#define EXECUTETOKEN 479
#define EXTERNALPROCTOKEN 480
#define EXTERNALDATATOKEN 481
#define VOIDTOKEN 482
#define CONSTANTTYPETOKEN 483
#define FUNCTIONTOKEN 484
#define OBJECTTOKEN 485
#define RANGETOKEN 486
#define INTEGERTOKEN 487
#define STRINGTYPETOKEN 488
#define BOOLEANTOKEN 489
#define LISTTOKEN 490
#define OFTOKEN 491
#define VARTOKEN 492
#define PROCTOKEN 493
#define PROCEDURETOKEN 494
#define RETURNTOKEN 495
#define NOPTOKEN 496

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 119 "miniparser.y"

  doubleNode *dblnode;
  struct entryStruct *association;
  char *value;
  node *tree;
  chain *list;
  int *integerval;
  int count;
  void *other;

#line 662 "miniparser.c"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif




int miniyyparse (void *myScanner);


#endif /* !YY_MINIYY_MINIPARSER_H_INCLUDED  */
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_CONSTANTTOKEN = 3,              /* "decimal constant"  */
  YYSYMBOL_MIDPOINTCONSTANTTOKEN = 4,      /* "interval"  */
  YYSYMBOL_DYADICCONSTANTTOKEN = 5,        /* "dyadic constant"  */
  YYSYMBOL_HEXCONSTANTTOKEN = 6,           /* "constant in memory notation"  */
  YYSYMBOL_HEXADECIMALCONSTANTTOKEN = 7,   /* "hexadecimal constant"  */
  YYSYMBOL_BINARYCONSTANTTOKEN = 8,        /* "binary constant"  */
  YYSYMBOL_PITOKEN = 9,                    /* "pi"  */
  YYSYMBOL_IDENTIFIERTOKEN = 10,           /* "identifier"  */
  YYSYMBOL_STRINGTOKEN = 11,               /* "character string"  */
  YYSYMBOL_LPARTOKEN = 12,                 /* "("  */
  YYSYMBOL_RPARTOKEN = 13,                 /* ")"  */
  YYSYMBOL_LBRACKETTOKEN = 14,             /* "["  */
  YYSYMBOL_RBRACKETTOKEN = 15,             /* "]"  */
  YYSYMBOL_EQUALTOKEN = 16,                /* "="  */
  YYSYMBOL_ASSIGNEQUALTOKEN = 17,          /* ":="  */
  YYSYMBOL_COMPAREEQUALTOKEN = 18,         /* "=="  */
  YYSYMBOL_COMMATOKEN = 19,                /* ","  */
  YYSYMBOL_EXCLAMATIONTOKEN = 20,          /* "!"  */
  YYSYMBOL_SEMICOLONTOKEN = 21,            /* ";"  */
  YYSYMBOL_STARLEFTANGLETOKEN = 22,        /* "*<"  */
  YYSYMBOL_LEFTANGLETOKEN = 23,            /* "<"  */
  YYSYMBOL_RIGHTANGLEUNDERSCORETOKEN = 24, /* ">_"  */
  YYSYMBOL_RIGHTANGLEDOTTOKEN = 25,        /* ">."  */
  YYSYMBOL_RIGHTANGLESTARTOKEN = 26,       /* ">*"  */
  YYSYMBOL_RIGHTANGLETOKEN = 27,           /* ">"  */
  YYSYMBOL_DOTSTOKEN = 28,                 /* "..."  */
  YYSYMBOL_DOTTOKEN = 29,                  /* "."  */
  YYSYMBOL_QUESTIONMARKTOKEN = 30,         /* "?"  */
  YYSYMBOL_VERTBARTOKEN = 31,              /* "|"  */
  YYSYMBOL_ATTOKEN = 32,                   /* "@"  */
  YYSYMBOL_DOUBLECOLONTOKEN = 33,          /* "::"  */
  YYSYMBOL_COLONTOKEN = 34,                /* ":"  */
  YYSYMBOL_DOTCOLONTOKEN = 35,             /* ".:"  */
  YYSYMBOL_COLONDOTTOKEN = 36,             /* ":."  */
  YYSYMBOL_EXCLAMATIONEQUALTOKEN = 37,     /* "!="  */
  YYSYMBOL_APPROXTOKEN = 38,               /* "~"  */
  YYSYMBOL_ANDTOKEN = 39,                  /* "&&"  */
  YYSYMBOL_ORTOKEN = 40,                   /* "||"  */
  YYSYMBOL_PLUSTOKEN = 41,                 /* "+"  */
  YYSYMBOL_MINUSTOKEN = 42,                /* "-"  */
  YYSYMBOL_MULTOKEN = 43,                  /* "*"  */
  YYSYMBOL_DIVTOKEN = 44,                  /* "/"  */
  YYSYMBOL_POWTOKEN = 45,                  /* "^"  */
  YYSYMBOL_SQRTTOKEN = 46,                 /* "sqrt"  */
  YYSYMBOL_EXPTOKEN = 47,                  /* "exp"  */
  YYSYMBOL_FREEVARTOKEN = 48,              /* "_x_"  */
  YYSYMBOL_LOGTOKEN = 49,                  /* "log"  */
  YYSYMBOL_LOG2TOKEN = 50,                 /* "log2"  */
  YYSYMBOL_LOG10TOKEN = 51,                /* "log10"  */
  YYSYMBOL_SINTOKEN = 52,                  /* "sin"  */
  YYSYMBOL_COSTOKEN = 53,                  /* "cos"  */
  YYSYMBOL_TANTOKEN = 54,                  /* "tan"  */
  YYSYMBOL_ASINTOKEN = 55,                 /* "asin"  */
  YYSYMBOL_ACOSTOKEN = 56,                 /* "acos"  */
  YYSYMBOL_ATANTOKEN = 57,                 /* "atan"  */
  YYSYMBOL_SINHTOKEN = 58,                 /* "sinh"  */
  YYSYMBOL_COSHTOKEN = 59,                 /* "cosh"  */
  YYSYMBOL_TANHTOKEN = 60,                 /* "tanh"  */
  YYSYMBOL_ASINHTOKEN = 61,                /* "asinh"  */
  YYSYMBOL_ACOSHTOKEN = 62,                /* "acosh"  */
  YYSYMBOL_ATANHTOKEN = 63,                /* "atanh"  */
  YYSYMBOL_ABSTOKEN = 64,                  /* "abs"  */
  YYSYMBOL_ERFTOKEN = 65,                  /* "erf"  */
  YYSYMBOL_ERFCTOKEN = 66,                 /* "erfc"  */
  YYSYMBOL_LOG1PTOKEN = 67,                /* "log1p"  */
  YYSYMBOL_EXPM1TOKEN = 68,                /* "expm1"  */
  YYSYMBOL_DOUBLETOKEN = 69,               /* "D"  */
  YYSYMBOL_SINGLETOKEN = 70,               /* "SG"  */
  YYSYMBOL_HALFPRECISIONTOKEN = 71,        /* "HP"  */
  YYSYMBOL_QUADTOKEN = 72,                 /* "QD"  */
  YYSYMBOL_DOUBLEDOUBLETOKEN = 73,         /* "DD"  */
  YYSYMBOL_TRIPLEDOUBLETOKEN = 74,         /* "TD"  */
  YYSYMBOL_DOUBLEEXTENDEDTOKEN = 75,       /* "DE"  */
  YYSYMBOL_CEILTOKEN = 76,                 /* "ceil"  */
  YYSYMBOL_FLOORTOKEN = 77,                /* "floor"  */
  YYSYMBOL_NEARESTINTTOKEN = 78,           /* "nearestint"  */
  YYSYMBOL_HEADTOKEN = 79,                 /* "head"  */
  YYSYMBOL_REVERTTOKEN = 80,               /* "revert"  */
  YYSYMBOL_SORTTOKEN = 81,                 /* "sort"  */
  YYSYMBOL_TAILTOKEN = 82,                 /* "tail"  */
  YYSYMBOL_MANTISSATOKEN = 83,             /* "mantissa"  */
  YYSYMBOL_EXPONENTTOKEN = 84,             /* "exponent"  */
  YYSYMBOL_PRECISIONTOKEN = 85,            /* "precision"  */
  YYSYMBOL_ROUNDCORRECTLYTOKEN = 86,       /* "roundcorrectly"  */
  YYSYMBOL_PRECTOKEN = 87,                 /* "prec"  */
  YYSYMBOL_POINTSTOKEN = 88,               /* "points"  */
  YYSYMBOL_DIAMTOKEN = 89,                 /* "diam"  */
  YYSYMBOL_DISPLAYTOKEN = 90,              /* "display"  */
  YYSYMBOL_VERBOSITYTOKEN = 91,            /* "verbosity"  */
  YYSYMBOL_SHOWMESSAGENUMBERSTOKEN = 92,   /* "showmessagenumbers"  */
  YYSYMBOL_CANONICALTOKEN = 93,            /* "canonical"  */
  YYSYMBOL_AUTOSIMPLIFYTOKEN = 94,         /* "autosimplify"  */
  YYSYMBOL_TAYLORRECURSIONSTOKEN = 95,     /* "taylorrecursions"  */
  YYSYMBOL_TIMINGTOKEN = 96,               /* "timing"  */
  YYSYMBOL_TIMETOKEN = 97,                 /* "time"  */
  YYSYMBOL_FULLPARENTHESESTOKEN = 98,      /* "fullparentheses"  */
  YYSYMBOL_MIDPOINTMODETOKEN = 99,         /* "midpointmode"  */
  YYSYMBOL_DIEONERRORMODETOKEN = 100,      /* "dieonerrormode"  */
  YYSYMBOL_SUPPRESSWARNINGSTOKEN = 101,    /* "roundingwarnings"  */
  YYSYMBOL_RATIONALMODETOKEN = 102,        /* "rationalmode"  */
  YYSYMBOL_HOPITALRECURSIONSTOKEN = 103,   /* "hopitalrecursions"  */
  YYSYMBOL_ONTOKEN = 104,                  /* "on"  */
  YYSYMBOL_OFFTOKEN = 105,                 /* "off"  */
  YYSYMBOL_DYADICTOKEN = 106,              /* "dyadic"  */
  YYSYMBOL_POWERSTOKEN = 107,              /* "powers"  */
  YYSYMBOL_BINARYTOKEN = 108,              /* "binary"  */
  YYSYMBOL_HEXADECIMALTOKEN = 109,         /* "hexadecimal"  */
  YYSYMBOL_FILETOKEN = 110,                /* "file"  */
  YYSYMBOL_POSTSCRIPTTOKEN = 111,          /* "postscript"  */
  YYSYMBOL_POSTSCRIPTFILETOKEN = 112,      /* "postscriptfile"  */
  YYSYMBOL_PERTURBTOKEN = 113,             /* "perturb"  */
  YYSYMBOL_MINUSWORDTOKEN = 114,           /* "RD"  */
  YYSYMBOL_PLUSWORDTOKEN = 115,            /* "RU"  */
  YYSYMBOL_ZEROWORDTOKEN = 116,            /* "RZ"  */
  YYSYMBOL_NEARESTTOKEN = 117,             /* "RN"  */
  YYSYMBOL_HONORCOEFFPRECTOKEN = 118,      /* "honorcoeffprec"  */
  YYSYMBOL_TRUETOKEN = 119,                /* "true"  */
  YYSYMBOL_FALSETOKEN = 120,               /* "false"  */
  YYSYMBOL_DEFAULTTOKEN = 121,             /* "default"  */
  YYSYMBOL_MATCHTOKEN = 122,               /* "match"  */
  YYSYMBOL_WITHTOKEN = 123,                /* "with"  */
  YYSYMBOL_ABSOLUTETOKEN = 124,            /* "absolute"  */
  YYSYMBOL_DECIMALTOKEN = 125,             /* "decimal"  */
  YYSYMBOL_RELATIVETOKEN = 126,            /* "relative"  */
  YYSYMBOL_FIXEDTOKEN = 127,               /* "fixed"  */
  YYSYMBOL_FLOATINGTOKEN = 128,            /* "floating"  */
  YYSYMBOL_ERRORTOKEN = 129,               /* "error"  */
  YYSYMBOL_QUITTOKEN = 130,                /* "quit"  */
  YYSYMBOL_FALSEQUITTOKEN = 131,           /* "quit in an included file"  */
  YYSYMBOL_FALSERESTARTTOKEN = 132,        /* "restart"  */
  YYSYMBOL_LIBRARYTOKEN = 133,             /* "library"  */
  YYSYMBOL_LIBRARYCONSTANTTOKEN = 134,     /* "libraryconstant"  */
  YYSYMBOL_DIFFTOKEN = 135,                /* "diff"  */
  YYSYMBOL_DIRTYSIMPLIFYTOKEN = 136,       /* "dirtysimplify"  */
  YYSYMBOL_REMEZTOKEN = 137,               /* "remez"  */
  YYSYMBOL_ANNOTATEFUNCTIONTOKEN = 138,    /* "annotatefunction"  */
  YYSYMBOL_BASHEVALUATETOKEN = 139,        /* "bashevaluate"  */
  YYSYMBOL_GETSUPPRESSEDMESSAGESTOKEN = 140, /* "getsuppressedmessages"  */
  YYSYMBOL_GETBACKTRACETOKEN = 141,        /* "getbacktrace"  */
  YYSYMBOL_FPMINIMAXTOKEN = 142,           /* "fpminimax"  */
  YYSYMBOL_HORNERTOKEN = 143,              /* "horner"  */
  YYSYMBOL_EXPANDTOKEN = 144,              /* "expand"  */
  YYSYMBOL_SIMPLIFYSAFETOKEN = 145,        /* "simplify"  */
  YYSYMBOL_TAYLORTOKEN = 146,              /* "taylor"  */
  YYSYMBOL_TAYLORFORMTOKEN = 147,          /* "taylorform"  */
  YYSYMBOL_CHEBYSHEVFORMTOKEN = 148,       /* "chebyshevform"  */
  YYSYMBOL_AUTODIFFTOKEN = 149,            /* "autodiff"  */
  YYSYMBOL_DEGREETOKEN = 150,              /* "degree"  */
  YYSYMBOL_NUMERATORTOKEN = 151,           /* "numerator"  */
  YYSYMBOL_DENOMINATORTOKEN = 152,         /* "denominator"  */
  YYSYMBOL_SUBSTITUTETOKEN = 153,          /* "substitute"  */
  YYSYMBOL_COMPOSEPOLYNOMIALSTOKEN = 154,  /* "composepolynomials"  */
  YYSYMBOL_BEZOUTTOKEN = 155,              /* "bezout"  */
  YYSYMBOL_COEFFTOKEN = 156,               /* "coeff"  */
  YYSYMBOL_SUBPOLYTOKEN = 157,             /* "subpoly"  */
  YYSYMBOL_ROUNDCOEFFICIENTSTOKEN = 158,   /* "roundcoefficients"  */
  YYSYMBOL_RATIONALAPPROXTOKEN = 159,      /* "rationalapprox"  */
  YYSYMBOL_ACCURATEINFNORMTOKEN = 160,     /* "accurateinfnorm"  */
  YYSYMBOL_ROUNDTOFORMATTOKEN = 161,       /* "round"  */
  YYSYMBOL_EVALUATETOKEN = 162,            /* "evaluate"  */
  YYSYMBOL_LENGTHTOKEN = 163,              /* "length"  */
  YYSYMBOL_OBJECTNAMETOKEN = 164,          /* "objectname"  */
  YYSYMBOL_INFTOKEN = 165,                 /* "inf"  */
  YYSYMBOL_MIDTOKEN = 166,                 /* "mid"  */
  YYSYMBOL_SUPTOKEN = 167,                 /* "sup"  */
  YYSYMBOL_MINTOKEN = 168,                 /* "min"  */
  YYSYMBOL_MAXTOKEN = 169,                 /* "max"  */
  YYSYMBOL_READXMLTOKEN = 170,             /* "readxml"  */
  YYSYMBOL_PARSETOKEN = 171,               /* "parse"  */
  YYSYMBOL_PRINTTOKEN = 172,               /* "print"  */
  YYSYMBOL_PRINTXMLTOKEN = 173,            /* "printxml"  */
  YYSYMBOL_PLOTTOKEN = 174,                /* "plot"  */
  YYSYMBOL_PRINTHEXATOKEN = 175,           /* "printhexa"  */
  YYSYMBOL_PRINTFLOATTOKEN = 176,          /* "printfloat"  */
  YYSYMBOL_PRINTBINARYTOKEN = 177,         /* "printbinary"  */
  YYSYMBOL_SUPPRESSMESSAGETOKEN = 178,     /* "suppressmessage"  */
  YYSYMBOL_UNSUPPRESSMESSAGETOKEN = 179,   /* "unsuppressmessage"  */
  YYSYMBOL_PRINTEXPANSIONTOKEN = 180,      /* "printexpansion"  */
  YYSYMBOL_BASHEXECUTETOKEN = 181,         /* "bashexecute"  */
  YYSYMBOL_EXTERNALPLOTTOKEN = 182,        /* "externalplot"  */
  YYSYMBOL_WRITETOKEN = 183,               /* "write"  */
  YYSYMBOL_ASCIIPLOTTOKEN = 184,           /* "asciiplot"  */
  YYSYMBOL_RENAMETOKEN = 185,              /* "rename"  */
  YYSYMBOL_BINDTOKEN = 186,                /* "bind"  */
  YYSYMBOL_INFNORMTOKEN = 187,             /* "infnorm"  */
  YYSYMBOL_SUPNORMTOKEN = 188,             /* "supnorm"  */
  YYSYMBOL_FINDZEROSTOKEN = 189,           /* "findzeros"  */
  YYSYMBOL_FPFINDZEROSTOKEN = 190,         /* "fpfindzeros"  */
  YYSYMBOL_DIRTYINFNORMTOKEN = 191,        /* "dirtyinfnorm"  */
  YYSYMBOL_GCDTOKEN = 192,                 /* "gcd"  */
  YYSYMBOL_EUCLDIVTOKEN = 193,             /* "div"  */
  YYSYMBOL_EUCLMODTOKEN = 194,             /* "mod"  */
  YYSYMBOL_NUMBERROOTSTOKEN = 195,         /* "numberroots"  */
  YYSYMBOL_INTEGRALTOKEN = 196,            /* "integral"  */
  YYSYMBOL_DIRTYINTEGRALTOKEN = 197,       /* "dirtyintegral"  */
  YYSYMBOL_WORSTCASETOKEN = 198,           /* "worstcase"  */
  YYSYMBOL_IMPLEMENTPOLYTOKEN = 199,       /* "implementpoly"  */
  YYSYMBOL_IMPLEMENTCONSTTOKEN = 200,      /* "implementconst"  */
  YYSYMBOL_INTERPOLATETOKEN = 201,         /* "interpolate"  */
  YYSYMBOL_CHECKINFNORMTOKEN = 202,        /* "checkinfnorm"  */
  YYSYMBOL_ZERODENOMINATORSTOKEN = 203,    /* "zerodenominators"  */
  YYSYMBOL_ISEVALUABLETOKEN = 204,         /* "isevaluable"  */
  YYSYMBOL_SEARCHGALTOKEN = 205,           /* "searchgal"  */
  YYSYMBOL_GUESSDEGREETOKEN = 206,         /* "guessdegree"  */
  YYSYMBOL_DIRTYFINDZEROSTOKEN = 207,      /* "dirtyfindzeros"  */
  YYSYMBOL_IFTOKEN = 208,                  /* "if"  */
  YYSYMBOL_THENTOKEN = 209,                /* "then"  */
  YYSYMBOL_ELSETOKEN = 210,                /* "else"  */
  YYSYMBOL_FORTOKEN = 211,                 /* "for"  */
  YYSYMBOL_INTOKEN = 212,                  /* "in"  */
  YYSYMBOL_FROMTOKEN = 213,                /* "from"  */
  YYSYMBOL_TOTOKEN = 214,                  /* "to"  */
  YYSYMBOL_BYTOKEN = 215,                  /* "by"  */
  YYSYMBOL_DOTOKEN = 216,                  /* "do"  */
  YYSYMBOL_BEGINTOKEN = 217,               /* "begin"  */
  YYSYMBOL_ENDTOKEN = 218,                 /* "end"  */
  YYSYMBOL_LEFTCURLYBRACETOKEN = 219,      /* "{"  */
  YYSYMBOL_RIGHTCURLYBRACETOKEN = 220,     /* "}"  */
  YYSYMBOL_WHILETOKEN = 221,               /* "while"  */
  YYSYMBOL_READFILETOKEN = 222,            /* "readfile"  */
  YYSYMBOL_ISBOUNDTOKEN = 223,             /* "isbound"  */
  YYSYMBOL_EXECUTETOKEN = 224,             /* "execute"  */
  YYSYMBOL_EXTERNALPROCTOKEN = 225,        /* "externalproc"  */
  YYSYMBOL_EXTERNALDATATOKEN = 226,        /* "externaldata"  */
  YYSYMBOL_VOIDTOKEN = 227,                /* "void"  */
  YYSYMBOL_CONSTANTTYPETOKEN = 228,        /* "constant"  */
  YYSYMBOL_FUNCTIONTOKEN = 229,            /* "function"  */
  YYSYMBOL_OBJECTTOKEN = 230,              /* "object"  */
  YYSYMBOL_RANGETOKEN = 231,               /* "range"  */
  YYSYMBOL_INTEGERTOKEN = 232,             /* "integer"  */
  YYSYMBOL_STRINGTYPETOKEN = 233,          /* "string"  */
  YYSYMBOL_BOOLEANTOKEN = 234,             /* "boolean"  */
  YYSYMBOL_LISTTOKEN = 235,                /* "list"  */
  YYSYMBOL_OFTOKEN = 236,                  /* "of"  */
  YYSYMBOL_VARTOKEN = 237,                 /* "var"  */
  YYSYMBOL_PROCTOKEN = 238,                /* "proc"  */
  YYSYMBOL_PROCEDURETOKEN = 239,           /* "procedure"  */
  YYSYMBOL_RETURNTOKEN = 240,              /* "return"  */
  YYSYMBOL_NOPTOKEN = 241,                 /* "nop"  */
  YYSYMBOL_YYACCEPT = 242,                 /* $accept  */
  YYSYMBOL_startsymbol = 243,              /* startsymbol  */
  YYSYMBOL_startsymbolwitherr = 244,       /* startsymbolwitherr  */
  YYSYMBOL_beginsymbol = 245,              /* beginsymbol  */
  YYSYMBOL_endsymbol = 246,                /* endsymbol  */
  YYSYMBOL_command = 247,                  /* command  */
  YYSYMBOL_ifcommand = 248,                /* ifcommand  */
  YYSYMBOL_forcommand = 249,               /* forcommand  */
  YYSYMBOL_commandlist = 250,              /* commandlist  */
  YYSYMBOL_variabledeclarationlist = 251,  /* variabledeclarationlist  */
  YYSYMBOL_variabledeclaration = 252,      /* variabledeclaration  */
  YYSYMBOL_identifierlist = 253,           /* identifierlist  */
  YYSYMBOL_procbody = 254,                 /* procbody  */
  YYSYMBOL_simplecommand = 255,            /* simplecommand  */
  YYSYMBOL_assignment = 256,               /* assignment  */
  YYSYMBOL_simpleassignment = 257,         /* simpleassignment  */
  YYSYMBOL_structuring = 258,              /* structuring  */
  YYSYMBOL_stateassignment = 259,          /* stateassignment  */
  YYSYMBOL_stillstateassignment = 260,     /* stillstateassignment  */
  YYSYMBOL_thinglist = 261,                /* thinglist  */
  YYSYMBOL_structelementlist = 262,        /* structelementlist  */
  YYSYMBOL_structelementseparator = 263,   /* structelementseparator  */
  YYSYMBOL_structelement = 264,            /* structelement  */
  YYSYMBOL_thing = 265,                    /* thing  */
  YYSYMBOL_supermegaterm = 266,            /* supermegaterm  */
  YYSYMBOL_indexing = 267,                 /* indexing  */
  YYSYMBOL_megaterm = 268,                 /* megaterm  */
  YYSYMBOL_hyperterm = 269,                /* hyperterm  */
  YYSYMBOL_unaryplusminus = 270,           /* unaryplusminus  */
  YYSYMBOL_term = 271,                     /* term  */
  YYSYMBOL_subterm = 272,                  /* subterm  */
  YYSYMBOL_basicthing = 273,               /* basicthing  */
  YYSYMBOL_matchlist = 274,                /* matchlist  */
  YYSYMBOL_matchelement = 275,             /* matchelement  */
  YYSYMBOL_constant = 276,                 /* constant  */
  YYSYMBOL_list = 277,                     /* list  */
  YYSYMBOL_simplelist = 278,               /* simplelist  */
  YYSYMBOL_range = 279,                    /* range  */
  YYSYMBOL_debound = 280,                  /* debound  */
  YYSYMBOL_headfunction = 281,             /* headfunction  */
  YYSYMBOL_egalquestionmark = 282,         /* egalquestionmark  */
  YYSYMBOL_statedereference = 283,         /* statedereference  */
  YYSYMBOL_externalproctype = 284,         /* externalproctype  */
  YYSYMBOL_extendedexternalproctype = 285, /* extendedexternalproctype  */
  YYSYMBOL_externalproctypesimplelist = 286, /* externalproctypesimplelist  */
  YYSYMBOL_externalproctypelist = 287      /* externalproctypelist  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_int16 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if !defined yyoverflow

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* !defined yyoverflow */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  320
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   8690

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  242
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  46
/* YYNRULES -- Number of rules.  */
#define YYNRULES  407
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  1157

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   496


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    97,    98,    99,   100,   101,   102,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   131,   132,   133,   134,
     135,   136,   137,   138,   139,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150,   151,   152,   153,   154,
     155,   156,   157,   158,   159,   160,   161,   162,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   172,   173,   174,
     175,   176,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   191,   192,   193,   194,
     195,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   443,   443,   452,   456,   461,   467,   471,   477,   481,
     487,   491,   495,   499,   503,   507,   511,   515,   521,   525,
     533,   538,   543,   551,   555,   561,   565,   571,   578,   582,
     588,   592,   596,   600,   604,   608,   612,   616,   620,   624,
     628,   632,   636,   640,   644,   648,   652,   656,   660,   664,
     668,   672,   676,   680,   688,   692,   696,   700,   704,   708,
     712,   716,   720,   724,   728,   732,   736,   740,   744,   748,
     752,   756,   760,   764,   768,   772,   776,   780,   784,   788,
     792,   798,   803,   808,   812,   817,   822,   826,   830,   837,
     841,   845,   849,   855,   860,   865,   870,   875,   880,   885,
     889,   895,   902,   906,   910,   914,   918,   922,   926,   930,
     934,   938,   942,   946,   950,   954,   958,   962,   968,   972,
     976,   980,   984,   988,   992,   996,  1000,  1004,  1008,  1012,
    1016,  1020,  1024,  1028,  1034,  1038,  1044,  1048,  1054,  1058,
    1064,  1074,  1078,  1084,  1088,  1092,  1096,  1102,  1111,  1115,
    1119,  1123,  1127,  1131,  1135,  1139,  1145,  1149,  1153,  1157,
    1161,  1165,  1171,  1175,  1179,  1183,  1190,  1194,  1201,  1205,
    1209,  1213,  1220,  1227,  1231,  1237,  1241,  1245,  1252,  1256,
    1260,  1267,  1271,  1275,  1279,  1283,  1287,  1291,  1295,  1299,
    1303,  1307,  1311,  1315,  1319,  1323,  1327,  1331,  1335,  1339,
    1343,  1347,  1351,  1355,  1359,  1363,  1367,  1371,  1375,  1379,
    1383,  1387,  1391,  1395,  1399,  1410,  1414,  1419,  1424,  1429,
    1434,  1438,  1442,  1446,  1450,  1454,  1458,  1462,  1467,  1472,
    1477,  1482,  1486,  1490,  1494,  1500,  1504,  1510,  1514,  1518,
    1522,  1526,  1530,  1534,  1538,  1542,  1548,  1553,  1558,  1563,
    1568,  1573,  1578,  1586,  1590,  1594,  1598,  1604,  1608,  1612,
    1618,  1622,  1626,  1632,  1636,  1640,  1644,  1648,  1652,  1658,
    1662,  1666,  1670,  1674,  1678,  1682,  1686,  1690,  1695,  1699,
    1703,  1707,  1711,  1715,  1719,  1723,  1727,  1731,  1735,  1739,
    1743,  1747,  1751,  1755,  1759,  1763,  1767,  1771,  1775,  1779,
    1783,  1787,  1791,  1795,  1799,  1803,  1807,  1811,  1815,  1819,
    1823,  1827,  1831,  1835,  1839,  1843,  1847,  1851,  1855,  1859,
    1863,  1867,  1871,  1875,  1879,  1883,  1887,  1891,  1895,  1899,
    1903,  1907,  1911,  1915,  1919,  1923,  1927,  1931,  1935,  1939,
    1943,  1947,  1951,  1955,  1959,  1963,  1967,  1971,  1975,  1979,
    1983,  1987,  1991,  1995,  1999,  2003,  2007,  2011,  2015,  2019,
    2023,  2027,  2031,  2035,  2039,  2043,  2047,  2051,  2055,  2059,
    2065,  2070,  2076,  2080,  2084,  2088,  2092,  2096,  2100,  2104,
    2108,  2112,  2116,  2120,  2124,  2128,  2132,  2136,  2143,  2149,
    2155,  2161,  2167,  2173,  2179,  2185,  2191,  2197,  2203,  2209,
    2215,  2221,  2229,  2235,  2242,  2246,  2252,  2256
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "\"decimal constant\"",
  "\"interval\"", "\"dyadic constant\"", "\"constant in memory notation\"",
  "\"hexadecimal constant\"", "\"binary constant\"", "\"pi\"",
  "\"identifier\"", "\"character string\"", "\"(\"", "\")\"", "\"[\"",
  "\"]\"", "\"=\"", "\":=\"", "\"==\"", "\",\"", "\"!\"", "\";\"",
  "\"*<\"", "\"<\"", "\">_\"", "\">.\"", "\">*\"", "\">\"", "\"...\"",
  "\".\"", "\"?\"", "\"|\"", "\"@\"", "\"::\"", "\":\"", "\".:\"",
  "\":.\"", "\"!=\"", "\"~\"", "\"&&\"", "\"||\"", "\"+\"", "\"-\"",
  "\"*\"", "\"/\"", "\"^\"", "\"sqrt\"", "\"exp\"", "\"_x_\"", "\"log\"",
  "\"log2\"", "\"log10\"", "\"sin\"", "\"cos\"", "\"tan\"", "\"asin\"",
  "\"acos\"", "\"atan\"", "\"sinh\"", "\"cosh\"", "\"tanh\"", "\"asinh\"",
  "\"acosh\"", "\"atanh\"", "\"abs\"", "\"erf\"", "\"erfc\"", "\"log1p\"",
  "\"expm1\"", "\"D\"", "\"SG\"", "\"HP\"", "\"QD\"", "\"DD\"", "\"TD\"",
  "\"DE\"", "\"ceil\"", "\"floor\"", "\"nearestint\"", "\"head\"",
  "\"revert\"", "\"sort\"", "\"tail\"", "\"mantissa\"", "\"exponent\"",
  "\"precision\"", "\"roundcorrectly\"", "\"prec\"", "\"points\"",
  "\"diam\"", "\"display\"", "\"verbosity\"", "\"showmessagenumbers\"",
  "\"canonical\"", "\"autosimplify\"", "\"taylorrecursions\"",
  "\"timing\"", "\"time\"", "\"fullparentheses\"", "\"midpointmode\"",
  "\"dieonerrormode\"", "\"roundingwarnings\"", "\"rationalmode\"",
  "\"hopitalrecursions\"", "\"on\"", "\"off\"", "\"dyadic\"", "\"powers\"",
  "\"binary\"", "\"hexadecimal\"", "\"file\"", "\"postscript\"",
  "\"postscriptfile\"", "\"perturb\"", "\"RD\"", "\"RU\"", "\"RZ\"",
  "\"RN\"", "\"honorcoeffprec\"", "\"true\"", "\"false\"", "\"default\"",
  "\"match\"", "\"with\"", "\"absolute\"", "\"decimal\"", "\"relative\"",
  "\"fixed\"", "\"floating\"", "\"error\"", "\"quit\"",
  "\"quit in an included file\"", "\"restart\"", "\"library\"",
  "\"libraryconstant\"", "\"diff\"", "\"dirtysimplify\"", "\"remez\"",
  "\"annotatefunction\"", "\"bashevaluate\"", "\"getsuppressedmessages\"",
  "\"getbacktrace\"", "\"fpminimax\"", "\"horner\"", "\"expand\"",
  "\"simplify\"", "\"taylor\"", "\"taylorform\"", "\"chebyshevform\"",
  "\"autodiff\"", "\"degree\"", "\"numerator\"", "\"denominator\"",
  "\"substitute\"", "\"composepolynomials\"", "\"bezout\"", "\"coeff\"",
  "\"subpoly\"", "\"roundcoefficients\"", "\"rationalapprox\"",
  "\"accurateinfnorm\"", "\"round\"", "\"evaluate\"", "\"length\"",
  "\"objectname\"", "\"inf\"", "\"mid\"", "\"sup\"", "\"min\"", "\"max\"",
  "\"readxml\"", "\"parse\"", "\"print\"", "\"printxml\"", "\"plot\"",
  "\"printhexa\"", "\"printfloat\"", "\"printbinary\"",
  "\"suppressmessage\"", "\"unsuppressmessage\"", "\"printexpansion\"",
  "\"bashexecute\"", "\"externalplot\"", "\"write\"", "\"asciiplot\"",
  "\"rename\"", "\"bind\"", "\"infnorm\"", "\"supnorm\"", "\"findzeros\"",
  "\"fpfindzeros\"", "\"dirtyinfnorm\"", "\"gcd\"", "\"div\"", "\"mod\"",
  "\"numberroots\"", "\"integral\"", "\"dirtyintegral\"", "\"worstcase\"",
  "\"implementpoly\"", "\"implementconst\"", "\"interpolate\"",
  "\"checkinfnorm\"", "\"zerodenominators\"", "\"isevaluable\"",
  "\"searchgal\"", "\"guessdegree\"", "\"dirtyfindzeros\"", "\"if\"",
  "\"then\"", "\"else\"", "\"for\"", "\"in\"", "\"from\"", "\"to\"",
  "\"by\"", "\"do\"", "\"begin\"", "\"end\"", "\"{\"", "\"}\"",
  "\"while\"", "\"readfile\"", "\"isbound\"", "\"execute\"",
  "\"externalproc\"", "\"externaldata\"", "\"void\"", "\"constant\"",
  "\"function\"", "\"object\"", "\"range\"", "\"integer\"", "\"string\"",
  "\"boolean\"", "\"list\"", "\"of\"", "\"var\"", "\"proc\"",
  "\"procedure\"", "\"return\"", "\"nop\"", "$accept", "startsymbol",
  "startsymbolwitherr", "beginsymbol", "endsymbol", "command", "ifcommand",
  "forcommand", "commandlist", "variabledeclarationlist",
  "variabledeclaration", "identifierlist", "procbody", "simplecommand",
  "assignment", "simpleassignment", "structuring", "stateassignment",
  "stillstateassignment", "thinglist", "structelementlist",
  "structelementseparator", "structelement", "thing", "supermegaterm",
  "indexing", "megaterm", "hyperterm", "unaryplusminus", "term", "subterm",
  "basicthing", "matchlist", "matchelement", "constant", "list",
  "simplelist", "range", "debound", "headfunction", "egalquestionmark",
  "statedereference", "externalproctype", "extendedexternalproctype",
  "externalproctypesimplelist", "externalproctypelist", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-1036)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-134)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    3946, -1036, -1036, -1036, -1036, -1036, -1036, -1036, -1036,    10,
   -1036,  6744,  4152,  7422,  6744,  8452,   246,   246,    61,   131,
     168,   174,   179,   224,   226,   232,   248,   304,   335,   423,
     433,   440,   443,   489,   495,   500,   506,   528,   534,   573,
     580,   586,   614,   620,   626,   628,   644,   647,   667,   734,
     770,   771,   775,   779,   783,   792,   794,   806,   819,    63,
      63,    63,    63,    63,    63,    40,    63,    63,    63,   820,
      63,    63,    63,    63,    63,    63, -1036, -1036, -1036, -1036,
   -1036, -1036, -1036, -1036, -1036, -1036, -1036, -1036, -1036, -1036,
   -1036, -1036, -1036, -1036,  6744, -1036, -1036, -1036, -1036, -1036,
   -1036,   826,   829,   833,   839,   849,   858,   893,   900,   902,
     908,   927,   945,   949,   952,   953,   955,   956,   982,   986,
    1005,  1009,  1013,  1024,  1047,  1058,  1063,  1065,  1070,  1073,
    1077,  1099,  1104,  1108,  1109,  1113,  1137,  1139,  1141,  1149,
    1150,  1152,  1163,  1165,  1168,  1178,  1191,  1196,  1204,  1206,
    1207,  1217,  1221,  1242,  1251,  1255,  1257,  1258,  1269,    68,
    1278,  1282, -1036,  1286,  1291,    51, -1036,    29, -1036, -1036,
      30,   133,  8452,   275, -1036,    41, -1036, -1036, -1036, -1036,
   -1036, -1036,  4594,    62,  4800,   116,   790,    30,  1321, -1036,
   -1036, -1036,  6744,  6744,  6744,  6744,  6744,  6744,  6744,  6744,
    6744,  6744,  6744,  6744,  6744,  6744,  6744,  6744,  6744,  6744,
    6744,  6744,  6744,  6744,  6744,  6744,  6744,  6744,  6744,  6744,
    6744,  6744,  6744,  6744,  6744,  6744,  6744,  6744,  6744,  6744,
    6744,  6744,  6744,   333, -1036, -1036, -1036, -1036, -1036, -1036,
    6744, -1036, -1036, -1036, -1036,  3707, -1036, -1036, -1036, -1036,
   -1036, -1036,   294,     6,  6744,  6744,  6744,  6744,  6744,   380,
     382,  6744,  6744,  6744,  6744,  6744,  6744,  6744,  6744,  6744,
    6744,  6744,  6744,  6744,  6744,  6744,  6744,  6744,  6744,  6744,
    6744,  6744,  6744,  6744,  6744,  6744,  6744,  6744,  6744,  6744,
    6744,  6744,  6744,  6744,  6744,  6744,  6744,  6744,  6744,  6744,
    6744,  6744,  6744,  6744,  6744,  6744,  6744,  6744,  6744,  6744,
    6744,  6744,   393,   181,     2,  6744,   406,  6744,    83, -1036,
   -1036, -1036,  7422,  7422,  7422,  6980,  7216,  7422,  7422,  7422,
    7422,  7422,  7422,  7422, -1036,  7628,  7834,  6744,   585,  8246,
    8040, -1036,   386,   313,  1297,   454,   294,    35, -1036, -1036,
    6744,  6744, -1036, -1036, -1036,    64,    67,    69,    75,    77,
      97,    99,   107,   109,   112,   114,   117,   119,   128,   132,
     137,   149,   296,   309,   316,   318,   341,   346,   349,   351,
     371,   374,   379,   381,   383,   385,   387,   389,   391,   399,
     402,   404,   420,   424,   427,   434, -1036,   436,   565,   432,
     494,   872,   901,   976,   990,   562,  1014,  1087,  1111,  1162,
    1201,  1215,  1248,  1264,  1294, -1036, -1036,  1301,  1305,  1306,
    1307,  1324,  1326,  1328,  1329,  1330,  1331,  1332,  1337,  1340,
    1341,  1342,  6744,   731, -1036,    68,  6744,  1344,  1345,  1350,
     742,  1428,  2273,   724, -1036, -1036,   730,   619, -1036,  1095,
   -1036,   625,    60,  6744,   438,   441,   464,   544,    52, -1036,
   -1036,   803,   445,   449,   452,   818,   825,   827,   850,   455,
     457,   459,   862,   864,   868,   876,   879,   887,   891,   903,
     905,   909,   466,   469,   474,   477,   480,   983,  1028,   498,
     502,   913,   915,   932,   939,   941,   943,   947,   965,   970,
     972,   974,   980,   984,  1032,   988,  1010,  1018,  1021,  1147,
    1025,  1029,  1431, -1036, -1036, -1036,    68,   508,  1173,    59,
     105,  -155,  1261,    30,    30,   133,  7422,   133,  7422,   133,
     133,   133,   275,   275,   275,   275,   275,  8452,  8452, -1036,
    8452,  8452, -1036,   638,  1438,  8452, -1036,  8452,  8452, -1036,
   -1036,  6744,  5036, -1036,  5242,   890,  1318,   787,   800, -1036,
   -1036, -1036, -1036, -1036, -1036, -1036, -1036, -1036, -1036, -1036,
   -1036, -1036, -1036, -1036, -1036, -1036, -1036, -1036, -1036, -1036,
   -1036, -1036, -1036, -1036, -1036, -1036, -1036, -1036, -1036, -1036,
   -1036, -1036, -1036, -1036, -1036, -1036, -1036, -1036, -1036, -1036,
   -1036,  4358,  6744,  5448,  5448,  5448,  5448,  5448,  5448,  5448,
    5448,  5448,  5448,  5448,  5448,  5448,  5448,  5448,  5448,  6744,
    6744,  6744,  6744,  6744,  6744,  6744,  6744,  6744,  6744,  6744,
    6744,  6744,    36,  6744, -1036,   -22,   435, -1036,   -31,  6744,
    1274,  1441,  1291,  5684, -1036, -1036,  1516, -1036,  1506,   -92,
    3468,  1508, -1036, -1036,  6744,  6744, -1036,  6744,  6744,  1520,
     139, -1036,  6744, -1036, -1036,  6744,  6744, -1036,  6744,  6744,
   -1036, -1036, -1036,  6744,  6744,  6744,  6744, -1036, -1036, -1036,
    6744,  6744,  6744,  6744,  6744,  6744,  6744,  6744,  6744,  6744,
   -1036, -1036, -1036, -1036, -1036, -1036, -1036, -1036, -1036,  1521,
    6744,  6744,  6744,  6744,  6744,  6744,  6744,  6744,  6744,  6744,
    6744,  6744, -1036,  6744,  6744,  6744,  6744, -1036,  6744,  6744,
    6744, -1036, -1036, -1036, -1036,  6744,  1504,  1516, -1036,  1317,
    -155,   133,   133, -1036, -1036, -1036, -1036, -1036,  5920, -1036,
   -1036, -1036, -1036, -1036,  1532,  1514,   294,  1554, -1036, -1036,
   -1036,  1559,  1560,   294,   294,   610,   693,   808,   853,  1078,
    1184,  1187,  1195,  1205,  1208,  1210,  1212,  1216,  1219,  1222,
    1226,  1561,   511,  1033,   517,   519,   521,  1562,  1564,   526,
     532,  1044,  1575,  1048,  1570,  1571,  1055,  3707,  6744,  6744,
    3707,   536,  1572,  1573, -1036, -1036,   540,  1574, -1036,  3707,
   -1036, -1036,   -92,  1336,   294,   294,   294,   294,   679,    22,
   -1036,  1057,  1060,   549,  1062,  1067,  1074,  1089,  1091,   551,
     554,   557,   560,   606,   612,   621,  1093,  1103,   624,  1576,
    1583,  1105,   631,   654,   659,   687,   704,   708,   715,   717,
     721,  1107,  1586,  1115,   723,   725,  1117,   727,   294,   729,
    1587, -1036,  6744, -1036,  -107,  2512,  1556, -1036,  1588, -1036,
    6744, -1036,  6744,  6744,  1652,  1659,  6744, -1036, -1036, -1036,
   -1036, -1036, -1036, -1036,  6744,  1662,  6744,    37,    39,  6744,
    1480,    19,   -24, -1036, -1036,  6744,  6744, -1036, -1036, -1036,
   -1036,  6744,  1795,  6744,  6744, -1036,  6744,  6744,  6744,  6744,
    6744, -1036, -1036, -1036, -1036, -1036, -1036, -1036,  6744,  6744,
   -1036,  6744, -1036,  6744, -1036, -1036, -1036, -1036, -1036, -1036,
   -1036, -1036, -1036,  6744, -1036,  6744, -1036, -1036,  6744, -1036,
   -1036,  -155,   547,  6744, -1036,  6744, -1036,   -76,  6744, -1036,
     -57,  2751, -1036,   294,   732,   736,  6126,  6332,  1752,  1119,
    6538,   738,  1753,  1755,  1756,  1757,  1129,  3707,  3707,  6744,
    1131,   740,   745,  6744, -1036,   282,  2990,  1758,  1133,  1144,
     757,  1759,   760,   768,  1771,   773,   777,  1148,  1155,   781,
    1773,  2034,   -92,   753,   838,  6744, -1036,   935,  6744, -1036,
    6744, -1036,   472, -1036, -1036,  6744,   294,  6744,   294, -1036,
    6744,  6744,   294, -1036, -1036, -1036, -1036, -1036,  6744, -1036,
   -1036,   -34,   111, -1036, -1036,   994,  6744, -1036,  6744, -1036,
     583, -1036,  6744,  6744, -1036, -1036, -1036, -1036, -1036, -1036,
   -1036,  6744,  6744, -1036, -1036,  6744, -1036,   615,  3229, -1036,
     -92,   -92,  1232,   -92,  1236,  1239,  6744, -1036,   294,   294,
    1157,   294,  1160,  6744,  3707,    18, -1036, -1036, -1036, -1036,
   -1036, -1036, -1036, -1036,  1551, -1036, -1036,  1746,   -92,  1252,
    1256,  6744, -1036,  1776,  1777,  1166,  1170,  1262,  6744, -1036,
    6744, -1036,   616, -1036, -1036,   -92, -1036,   -92,   -92,  1265,
    6744,  6744,    21, -1036,  1772,  1779,  1319,  1781, -1036,   -92,
     -92,  1268, -1036, -1036,  6744,  6744,   -92,  1272,  1276,  6744,
   -1036, -1036, -1036, -1036,   -92,  1172,  1174,  3707,    18, -1036,
   -1036, -1036, -1036, -1036, -1036, -1036, -1036,  1352, -1036, -1036,
     -92,   785,  1182, -1036,   -92,   -92,  1311, -1036,  6744,  6744,
   -1036, -1036,  1797, -1036, -1036,  6744, -1036, -1036,   -92,  1798,
    1799, -1036,  1800, -1036, -1036, -1036, -1036
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int16 yydefact[] =
{
       0,     5,   246,   247,   248,   249,   250,   251,   252,   216,
     214,     0,     0,     0,     0,     0,   162,   163,     0,     0,
     211,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   206,   207,   209,   208,   212,   213,   210,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   371,
     371,   371,   371,   371,   371,   371,   371,   371,   371,     0,
     371,   371,   371,   371,   371,   371,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   191,   192,   193,   194,
     195,   196,   198,   199,     0,   201,   200,   202,   203,   204,
     205,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   197,     0,     0,     0,     2,     3,   141,   227,
     143,   148,     0,   156,   166,   175,   215,   220,   221,   222,
     223,   226,     0,     0,     0,     0,     0,   146,     0,   168,
     164,   165,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   372,   373,   374,   375,   376,   377,
       0,   378,   379,   380,   381,     0,   382,   383,   384,   386,
     385,   387,     0,   141,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   136,     0,     0,     0,     0,   233,
       1,     4,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   167,     0,     0,     0,     0,     0,
       0,   219,     0,   134,   224,     0,   257,     0,   254,   262,
       0,     0,   265,   264,   263,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   370,     0,   216,   371,
     371,   371,   371,   371,   371,   371,   371,   371,   371,   371,
     371,   371,   371,   371,   371,    54,    55,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     6,     7,     0,     0,     0,     0,
       0,    56,     0,     0,    10,    86,    91,     0,    89,     0,
      87,   227,   175,     0,     0,     0,     0,     0,     0,   271,
     272,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   225,   138,   139,     0,     0,     0,     0,
      28,     0,     0,   144,   145,   149,     0,   151,     0,   152,
     155,   150,   159,   160,   161,   157,   158,     0,     0,   169,
       0,     0,   170,     0,   228,     0,   179,     0,     0,   176,
     218,     0,     0,   253,     0,     0,     0,     0,     0,   333,
     334,   335,   338,   339,   340,   341,   342,   343,   344,   345,
     346,   347,   348,   349,   350,   351,   352,   353,   354,   355,
     356,   357,   358,   359,   361,   360,   362,   363,   364,   365,
     366,   367,   324,   327,   328,   332,   329,   330,   331,   325,
     282,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    15,     0,     0,    17,     0,     0,
       0,     0,     0,     0,     8,     9,     0,    14,     0,     0,
       0,     0,   234,    92,     0,     0,    90,     0,     0,     0,
       0,   142,   235,   269,   274,     0,     0,   270,     0,     0,
     281,   283,   284,     0,     0,     0,     0,   289,   290,   291,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     368,   369,   268,   267,   266,   278,   279,   303,   302,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   316,     0,     0,     0,     0,   321,     0,     0,
       0,   137,   326,   217,   336,     0,     0,     0,     7,     0,
       0,   153,   154,   173,   171,   174,   172,   147,     0,   180,
     178,   177,   135,   232,     0,     0,   258,     0,   255,   260,
     261,     0,     0,    93,    94,   102,   103,   104,   105,   106,
     107,   108,   109,   110,   111,   112,   113,   114,   116,   115,
     117,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    88,    58,     0,    28,    27,    23,
      11,    13,     0,    25,    99,   100,    97,    98,   228,     0,
     236,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   140,     0,
       0,    29,     0,    33,     0,     0,     0,   229,     0,   231,
       0,   256,     0,     0,    59,    75,     0,    63,    64,    65,
      66,    67,    68,    69,     0,    71,     0,     0,     0,     0,
      18,     0,     0,    16,    76,     0,     0,    57,    24,    12,
      26,     0,     0,     0,     0,   273,     0,     0,     0,     0,
       0,   292,   293,   294,   295,   296,   297,   298,     0,     0,
     301,     0,   304,     0,   306,   307,   308,   309,   310,   311,
     312,   313,   314,     0,   317,     0,   319,   320,     0,   323,
     337,     0,     0,     0,    30,     0,    32,     0,     0,    41,
       0,     0,   230,   259,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   244,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    31,     0,     0,    38,
       0,    40,     0,    95,    96,     0,    60,     0,    77,    62,
       0,     0,    72,    74,    80,    81,    82,    83,     0,    19,
      22,     0,     0,    85,   245,     0,     0,   242,     0,   240,
       0,   275,     0,     0,   285,   286,   287,   288,   299,   300,
     277,     0,     0,   318,   322,     0,    49,     0,     0,    37,
       0,     0,     0,     0,     0,     0,     0,    39,    61,    78,
       0,    73,     0,     0,     0,     0,   402,   388,   389,   390,
     391,   392,   393,   394,     0,   403,   406,     0,     0,     0,
       0,     0,   238,     0,     0,     0,     0,     0,     0,    46,
       0,    48,     0,    34,    36,     0,    45,     0,     0,     0,
       0,     0,     0,    20,   404,     0,     0,     0,   243,     0,
       0,     0,   276,   280,     0,     0,     0,     0,     0,     0,
      47,    35,    42,    44,     0,     0,     0,     0,     0,   407,
     395,   396,   397,   398,   399,   400,   401,     0,   241,   239,
       0,     0,     0,    53,     0,     0,     0,    43,     0,     0,
      21,   405,     0,   237,   305,     0,    50,    52,     0,     0,
       0,    84,     0,    51,    70,    79,   315
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
   -1036, -1036, -1036,  -497,   200,  -235, -1036, -1036,  -495,  -722,
   -1036,  -627,  1176, -1036, -1036, -1036, -1036, -1036, -1036,  -169,
    1298, -1036, -1036,     0,  1722,    81,    -9,  -283,   -15,    76,
     -12,    85,  1158, -1036, -1036, -1036, -1036, -1036, -1036, -1036,
     -35, -1036, -1035,   692,   703, -1036
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,   165,   166,   442,   647,   648,   634,   637,   649,   650,
     651,   522,   319,   444,   445,   446,   447,   448,   449,   450,
     313,   516,   314,   343,   168,   169,   170,   171,   172,   173,
     174,   175,   661,   662,   176,   177,   347,   178,   179,   180,
     234,   181,  1065,  1066,  1095,  1067
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
     167,   190,   191,   189,   187,   322,   323,   855,   322,   323,
     443,   183,   186,   342,   188,   322,   323,   322,   323,   798,
    1094,   514,   182,   515,   729,   235,   236,   237,   238,   239,
     241,   242,   243,   244,   891,   246,   247,   248,   249,   250,
     251,   525,   527,   529,   530,   531,   784,   952,   324,   954,
     321,   320,   240,   325,   554,   337,   233,   326,   322,   323,
     322,   323,   434,   555,   728,   667,   556,   327,   322,   323,
     338,   668,   724,   192,   337,   344,   339,   559,   725,   233,
     560,   890,   561,  1094,   785,   953,   340,   955,   562,   659,
     563,   322,   323,   520,   252,   339,   521,   312,   322,   323,
     851,   322,   323,   322,   323,   340,   322,   323,   322,   323,
     564,   644,   565,   645,   322,   323,   322,   323,   487,   488,
     566,   726,   567,  1055,   727,   568,   644,   569,   645,   453,
     570,   348,   571,   933,   941,   504,   322,   323,   322,   323,
     509,   572,   644,   193,   645,   573,   322,   323,   322,   323,
     574,   322,   323,   322,   323,   802,   322,   323,   322,   323,
     334,   644,   575,   645,   985,   329,   330,   322,   323,   331,
     966,   322,   323,   809,   332,   333,   322,   323,   322,   323,
     194,  1053,  1054,   988,   346,   790,   195,   787,   322,   323,
     959,   196,   355,   356,   357,   358,   359,   360,   361,   362,
     363,   364,   365,   366,   367,   368,   369,   370,   371,   372,
     373,   374,   375,   376,   377,   378,   379,   380,   381,   382,
     383,   384,   385,   386,   387,   388,   389,   390,   391,   392,
     393,   394,   395,   856,   854,   958,   197,  1117,   198,   434,
     397,   728,   328,   731,   199,   732,  1057,  1058,  1059,  1060,
    1061,  1062,  1063,  1064,   454,   455,   456,   457,   458,  1038,
     200,   461,   462,   463,   464,   465,   466,   467,   468,   469,
     470,   471,   472,   473,   474,   475,   476,   477,   478,   479,
     480,   481,   482,   483,   484,   485,   486,    16,    17,   489,
     490,   491,   492,   493,   494,   495,   496,   497,   498,   499,
     500,   501,   502,   503,   888,   505,   506,   507,   508,   576,
     510,   511,   892,   523,   524,   517,   201,   519,   335,   336,
     538,   541,   577,   539,   542,   548,   451,   546,   549,   578,
     452,   579,   551,   322,   323,   322,   323,   543,  1056,  1057,
    1058,  1059,  1060,  1061,  1062,  1063,  1064,   202,   322,   323,
     557,   558,   322,   323,   580,   322,   323,   322,   323,   581,
     937,   940,   582,   396,   583,   235,   236,   237,   238,   239,
     241,   242,   243,   244,   246,   247,   248,   249,   250,   251,
     322,   323,   742,   744,   584,   322,   323,   585,   322,   323,
     322,   323,   586,   459,   587,   460,   588,   965,   589,   550,
     590,   513,   591,   512,   592,   532,   533,   534,   535,   536,
     322,   323,   593,   322,   323,   594,   518,   595,   322,   323,
     322,   323,   322,   323,   322,   323,   322,   323,   322,   323,
     322,   323,   635,   596,   981,   203,   638,   597,   322,   323,
     598,   322,   323,   322,   323,   204,   992,   599,   603,   600,
     771,   663,   205,   660,   664,   206,   777,   778,   670,   322,
     323,   782,   671,   322,   323,   672,   322,   323,   677,   553,
     678,  1020,   679,   322,   323,   322,   323,   322,   323,   690,
     322,   323,   691,   665,   322,   323,  1037,   692,   322,   323,
     693,   322,   323,   694,   322,   323,   322,   323,   322,   323,
     644,   207,   645,   322,   323,   322,   323,   208,   322,   323,
     604,   697,   209,   322,   323,   698,   322,   323,   210,   322,
     323,   722,  1016,   451,   865,   733,   734,   452,   735,   736,
     867,   830,   868,   739,   869,   740,   741,   322,   323,   872,
     211,   322,   323,  1082,   842,   873,   212,   322,   323,   884,
     322,   323,   880,   887,   746,   883,   322,   323,   322,   323,
     322,   323,   895,   666,   901,   322,   323,   902,   982,   858,
     903,   322,   323,   904,   240,   322,   323,   182,   609,   322,
     323,   601,   602,   322,   323,   213,   322,   323,   322,   323,
     322,   323,   214,   322,   323,   544,   322,   323,   215,   322,
     323,   753,   754,   755,   756,   757,   758,   759,   760,   761,
     762,   763,   764,   765,   766,   767,   768,   769,   770,   905,
     772,   773,   774,   775,   776,   906,   216,   779,   780,   781,
    -118,   783,   217,   786,   907,   654,   655,   910,   218,   791,
     219,   657,   658,   796,   914,   322,   323,   788,   789,   322,
     323,   322,   323,   737,   804,   805,   220,   806,   807,   221,
     322,   323,   660,   322,   323,   811,   812,   915,   813,   814,
     322,   323,   916,   815,   816,   817,   818,   322,   323,   222,
     819,   820,   821,   822,   823,   824,   825,   826,   827,   828,
     644,   738,   645,   322,   323,  -101,  -101,   948,   322,   323,
     917,   831,   832,   833,   834,   835,   836,   837,   838,   839,
     840,   841,  1046,  -119,   843,   844,   845,   918,   846,   847,
     848,   919,  1009,  1010,   967,   849,   322,   323,   920,   971,
     921,   451,   322,   323,   922,   452,   926,   652,   927,   974,
     929,   636,   930,   322,   323,   993,   223,   322,   323,   994,
     653,  1003,   642,  1013,   322,   323,   322,   323,  1014,   980,
     322,   323,   322,   323,   322,   323,   322,   323,   322,   323,
    1024,   322,   323,  1026,  1040,   322,   323,   322,   323,   322,
     323,  1027,   224,   225,   322,   323,  1029,   226,   881,   882,
    1030,   227,   322,   323,  1033,   228,   322,   323,  1144,   322,
     323,   644,   749,   645,   229,   349,   230,   322,   323,   350,
     451,   351,   322,   323,   452,   750,   322,   323,   231,  1093,
     322,   323,   669,  1071,   322,   323,   322,   323,  -120,   322,
     323,   232,   245,   644,   644,   645,   645,   673,   254,   322,
     323,   255,   322,   323,   674,   256,   675,   322,   323,   800,
     801,   257,   932,  1073,  1074,  1078,  1109,   322,   323,  1041,
     943,   258,   944,   945,   322,   323,   322,   323,   451,   676,
     259,   451,   452,  -121,   949,   452,   951,   322,   323,   956,
     451,   680,  1140,   681,   452,   960,   961,   682,   605,   322,
     323,   962,   322,   323,   968,   683,   969,   970,   684,   972,
     973,   322,   323,   322,   323,   260,   685,   322,   323,   975,
     686,   976,   261,   977,   262,   322,   323,   606,   322,   323,
     263,   747,   687,   978,   688,   979,   322,   323,   689,   853,
     322,   323,   699,   983,   700,   984,   451,   451,   987,   264,
     452,   452,   322,   323,   322,   323,   996,   998,   322,   323,
    1002,   701,   322,   323,   322,   323,  1043,   265,   702,  1011,
     703,   266,   704,  1015,   267,   268,   705,   269,   270,  1149,
    1150,   322,   323,   451,   322,   323,  1152,   452,   322,   323,
     322,   323,   322,   323,   706,  1042,   322,   323,  1044,   707,
    1045,   708,   607,   709,   271,  1048,   695,  1049,   272,   710,
    1050,  1051,   889,   711,   322,   323,   608,   713,  1052,   322,
     323,   322,   323,   322,   323,  1068,  1069,   273,  1070,   322,
     323,   274,   451,   322,   323,   275,   452,   322,   323,   714,
     610,  1075,  1076,   322,   323,  1077,   276,   715,   451,   451,
     716,   696,   452,   452,   718,   712,  1089,   451,   719,   322,
     323,   452,   866,  1092,   934,   936,   939,   322,   323,   277,
     322,   323,   451,   874,   322,   323,   452,   876,   322,   323,
     278,  1101,   322,   323,   879,   279,   893,   280,  1107,   894,
    1108,   896,   281,   322,   323,   282,   897,   322,   323,   283,
    1115,  1116,   964,   898,   322,   323,   322,   323,  -122,   322,
     323,   322,   323,   611,  1131,  1132,   322,   323,   899,  1136,
     900,   284,   908,   322,   323,   656,   285,   322,   323,   451,
     286,   287,   909,   452,   913,   288,   923,   612,   322,   323,
     322,   323,   322,   323,   925,   451,   928,   986,  1000,   452,
     989,   991,   322,   323,   322,   323,   322,   323,  1008,   289,
    1012,   290,  1022,   291,   322,   323,   322,   323,   322,   323,
     717,   292,   293,  1023,   294,  1017,  1019,  1031,   322,   323,
     322,   323,   322,   323,  1032,   295,  1090,   296,   613,  1091,
     297,  1036,  1039,   322,   323,  1104,   723,   322,   323,  1105,
     298,  1138,  1047,  1139,   322,   323,   322,   323,   451,   322,
     323,  1145,   452,   299,  -123,   322,   323,  -124,   300,   322,
     323,   322,   323,   322,   323,  -125,   301,   614,   302,   303,
    1072,   322,   323,   322,   323,  -126,   322,   323,  -127,   304,
    -128,   615,  -129,   305,   322,   323,  -130,  1079,  1081,  -132,
    1083,  1084,  -131,  1086,   322,   323,  -133,   322,   323,   322,
     323,   322,   323,  1085,   306,   322,   323,  1087,   322,   323,
    1088,   322,   323,   307,   616,   322,   323,   308,  1098,   309,
     310,   322,   323,  1099,   730,   322,   323,  1100,   322,   323,
     617,   311,  1110,  1106,   792,  1111,  1114,  1112,  1113,  1130,
     315,   322,   323,  1134,   316,   322,   323,  1135,   317,  1128,
    1129,   322,   323,   318,   322,   323,  1133,   322,   323,   552,
     618,   322,   323,   619,  1137,   322,   323,   620,   621,   622,
       2,     3,     4,     5,     6,     7,     8,   398,    10,    11,
    1143,    12,  1148,   748,  1146,  1147,   623,    13,   624,    14,
     625,   626,   627,   628,   629,   352,   353,   354,  1153,   630,
     322,   323,   631,   632,   633,    15,   639,   640,    16,    17,
     322,   323,   641,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,   399,   400,   401,   402,   403,   404,
     405,   406,   407,   408,    69,   409,   410,   411,   412,   413,
     414,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
     643,    95,    96,    97,    98,    99,   100,   720,   415,   416,
     738,   793,   101,   102,   103,   104,   105,   106,   107,   108,
     109,   110,   111,   112,   113,   114,   115,   116,   117,   118,
     119,   120,   121,   122,   123,   124,   125,   126,   127,   128,
     129,   130,   131,   132,   133,   134,   135,   136,   137,   417,
     418,   419,   420,   421,   422,   423,   424,   425,   426,   427,
     428,   429,   430,   138,   139,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   431,   150,   151,   152,   153,
     154,   155,   156,   157,   158,   432,   797,   799,   433,   803,
     808,   829,   850,   860,   434,   644,   435,   645,   436,   160,
     161,   437,   438,   439,   162,   859,   163,  1120,  1121,  1122,
    1123,  1124,  1125,  1126,   646,   164,   440,   852,   441,     2,
       3,     4,     5,     6,     7,     8,   398,    10,    11,   861,
      12,   862,   863,   646,   864,   870,    13,   871,    14,  1056,
    1057,  1058,  1059,  1060,  1061,  1062,  1063,  1064,   875,   877,
     878,   885,   886,   727,    15,   911,   912,    16,    17,   924,
     931,   942,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      56,    57,    58,   399,   400,   401,   402,   403,   404,   405,
     406,   407,   408,    69,   409,   410,   411,   412,   413,   414,
      76,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    90,    91,    92,    93,    94,   946,
      95,    96,    97,    98,    99,   100,   947,   415,   416,   950,
     957,   101,   102,   103,   104,   105,   106,   107,   108,   109,
     110,   111,   112,   113,   114,   115,   116,   117,   118,   119,
     120,   121,   122,   123,   124,   125,   126,   127,   128,   129,
     130,   131,   132,   133,   134,   135,   136,   137,   417,   418,
     419,   420,   421,   422,   423,   424,   425,   426,   427,   428,
     429,   430,   138,   139,   140,   141,   142,   143,   144,   145,
     146,   147,   148,   149,   431,   150,   151,   152,   153,   154,
     155,   156,   157,   158,   432,   999,  1004,   433,  1005,  1006,
    1007,  1021,  1025,   434,   644,   435,   645,   436,   160,   161,
     437,   438,   439,   162,  1028,   163,  1034,  1096,  1097,  1102,
    1103,  1118,  1119,   646,   164,   440,   938,   441,     2,     3,
       4,     5,     6,     7,     8,   398,    10,    11,  1127,    12,
    1151,  1154,  1155,  1156,   721,    13,   253,    14,   794,  1142,
     810,  1141,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    15,     0,     0,    16,    17,     0,     0,
       0,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    58,   399,   400,   401,   402,   403,   404,   405,   406,
     407,   408,    69,   409,   410,   411,   412,   413,   414,    76,
      77,    78,    79,    80,    81,    82,    83,    84,    85,    86,
      87,    88,    89,    90,    91,    92,    93,    94,     0,    95,
      96,    97,    98,    99,   100,     0,   415,   416,     0,     0,
     101,   102,   103,   104,   105,   106,   107,   108,   109,   110,
     111,   112,   113,   114,   115,   116,   117,   118,   119,   120,
     121,   122,   123,   124,   125,   126,   127,   128,   129,   130,
     131,   132,   133,   134,   135,   136,   137,   417,   418,   419,
     420,   421,   422,   423,   424,   425,   426,   427,   428,   429,
     430,   138,   139,   140,   141,   142,   143,   144,   145,   146,
     147,   148,   149,   431,   150,   151,   152,   153,   154,   155,
     156,   157,   158,   432,     0,     0,   433,     0,     0,     0,
       0,     0,   434,   644,   435,   645,   436,   160,   161,   437,
     438,   439,   162,     0,   163,     0,     0,     0,     0,     0,
       0,     0,   646,   164,   440,   963,   441,     2,     3,     4,
       5,     6,     7,     8,   398,    10,    11,     0,    12,     0,
       0,     0,     0,     0,    13,     0,    14,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    15,     0,     0,    16,    17,     0,     0,     0,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    56,    57,
      58,   399,   400,   401,   402,   403,   404,   405,   406,   407,
     408,    69,   409,   410,   411,   412,   413,   414,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    90,    91,    92,    93,    94,     0,    95,    96,
      97,    98,    99,   100,     0,   415,   416,     0,     0,   101,
     102,   103,   104,   105,   106,   107,   108,   109,   110,   111,
     112,   113,   114,   115,   116,   117,   118,   119,   120,   121,
     122,   123,   124,   125,   126,   127,   128,   129,   130,   131,
     132,   133,   134,   135,   136,   137,   417,   418,   419,   420,
     421,   422,   423,   424,   425,   426,   427,   428,   429,   430,
     138,   139,   140,   141,   142,   143,   144,   145,   146,   147,
     148,   149,   431,   150,   151,   152,   153,   154,   155,   156,
     157,   158,   432,     0,     0,   433,     0,     0,     0,     0,
       0,   434,   644,   435,   645,   436,   160,   161,   437,   438,
     439,   162,     0,   163,     0,     0,     0,     0,     0,     0,
       0,   646,   164,   440,  1035,   441,     2,     3,     4,     5,
       6,     7,     8,   398,    10,    11,     0,    12,     0,     0,
       0,     0,     0,    13,     0,    14,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    15,     0,     0,    16,    17,     0,     0,     0,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    56,    57,    58,
     399,   400,   401,   402,   403,   404,   405,   406,   407,   408,
      69,   409,   410,   411,   412,   413,   414,    76,    77,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    87,    88,
      89,    90,    91,    92,    93,    94,     0,    95,    96,    97,
      98,    99,   100,     0,   415,   416,     0,     0,   101,   102,
     103,   104,   105,   106,   107,   108,   109,   110,   111,   112,
     113,   114,   115,   116,   117,   118,   119,   120,   121,   122,
     123,   124,   125,   126,   127,   128,   129,   130,   131,   132,
     133,   134,   135,   136,   137,   417,   418,   419,   420,   421,
     422,   423,   424,   425,   426,   427,   428,   429,   430,   138,
     139,   140,   141,   142,   143,   144,   145,   146,   147,   148,
     149,   431,   150,   151,   152,   153,   154,   155,   156,   157,
     158,   432,     0,     0,   433,     0,     0,     0,     0,     0,
     434,   644,   435,   645,   436,   160,   161,   437,   438,   439,
     162,     0,   163,     0,     0,     0,     0,     0,     0,     0,
     646,   164,   440,     0,   441,     2,     3,     4,     5,     6,
       7,     8,   398,    10,    11,     0,    12,     0,     0,     0,
       0,     0,    13,     0,    14,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      15,     0,     0,    16,    17,     0,     0,     0,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    58,   399,
     400,   401,   402,   403,   404,   405,   406,   407,   408,    69,
     409,   410,   411,   412,   413,   414,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    91,    92,    93,    94,     0,    95,    96,    97,    98,
      99,   100,     0,   415,   416,     0,     0,   101,   102,   103,
     104,   105,   106,   107,   108,   109,   110,   111,   112,   113,
     114,   115,   116,   117,   118,   119,   120,   121,   122,   123,
     124,   125,   126,   127,   128,   129,   130,   131,   132,   133,
     134,   135,   136,   137,   417,   418,   419,   420,   421,   422,
     423,   424,   425,   426,   427,   428,   429,   430,   138,   139,
     140,   141,   142,   143,   144,   145,   146,   147,   148,   149,
     431,   150,   151,   152,   153,   154,   155,   156,   157,   158,
     432,     0,     0,   433,     0,     0,     0,     0,     0,   434,
     644,   435,   645,   436,   160,   161,   437,   438,   439,   162,
       0,   163,     0,     0,     0,     0,     0,     0,     0,     0,
     164,   440,   935,   441,     2,     3,     4,     5,     6,     7,
       8,   398,    10,    11,     0,    12,     0,     0,     0,     0,
       0,    13,     0,    14,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    15,
       0,     0,    16,    17,     0,     0,     0,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    56,    57,    58,   399,   400,
     401,   402,   403,   404,   405,   406,   407,   408,    69,   409,
     410,   411,   412,   413,   414,    76,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    89,    90,
      91,    92,    93,    94,     0,    95,    96,    97,    98,    99,
     100,     0,   415,   416,     0,     0,   101,   102,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   131,   132,   133,   134,
     135,   136,   137,   417,   418,   419,   420,   421,   422,   423,
     424,   425,   426,   427,   428,   429,   430,   138,   139,   140,
     141,   142,   143,   144,   145,   146,   147,   148,   149,   431,
     150,   151,   152,   153,   154,   155,   156,   157,   158,   432,
       0,     0,   433,     0,     0,     0,     0,     0,   434,   644,
     435,   645,   436,   160,   161,   437,   438,   439,   162,     0,
     163,     0,     0,     0,     0,     0,     0,     0,     0,   164,
     440,   990,   441,     2,     3,     4,     5,     6,     7,     8,
     398,    10,    11,     0,    12,     0,     0,     0,     0,     0,
      13,     0,    14,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    15,     0,
       0,    16,    17,     0,     0,     0,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    58,   399,   400,   401,
     402,   403,   404,   405,   406,   407,   408,    69,   409,   410,
     411,   412,   413,   414,    76,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    89,    90,    91,
      92,    93,    94,     0,    95,    96,    97,    98,    99,   100,
       0,   415,   416,     0,     0,   101,   102,   103,   104,   105,
     106,   107,   108,   109,   110,   111,   112,   113,   114,   115,
     116,   117,   118,   119,   120,   121,   122,   123,   124,   125,
     126,   127,   128,   129,   130,   131,   132,   133,   134,   135,
     136,   137,   417,   418,   419,   420,   421,   422,   423,   424,
     425,   426,   427,   428,   429,   430,   138,   139,   140,   141,
     142,   143,   144,   145,   146,   147,   148,   149,   431,   150,
     151,   152,   153,   154,   155,   156,   157,   158,   432,     0,
       0,   433,     0,     0,     0,     0,     0,   434,   644,   435,
     645,   436,   160,   161,   437,   438,   439,   162,     0,   163,
       0,     0,     0,     0,     0,     0,     0,     0,   164,   440,
    1018,   441,     2,     3,     4,     5,     6,     7,     8,   398,
      10,    11,     0,    12,     0,     0,     0,     0,     0,    13,
       0,    14,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    15,     0,     0,
      16,    17,     0,     0,     0,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    56,    57,    58,   399,   400,   401,   402,
     403,   404,   405,   406,   407,   408,    69,   409,   410,   411,
     412,   413,   414,    76,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    88,    89,    90,    91,    92,
      93,    94,     0,    95,    96,    97,    98,    99,   100,     0,
     415,   416,     0,     0,   101,   102,   103,   104,   105,   106,
     107,   108,   109,   110,   111,   112,   113,   114,   115,   116,
     117,   118,   119,   120,   121,   122,   123,   124,   125,   126,
     127,   128,   129,   130,   131,   132,   133,   134,   135,   136,
     137,   417,   418,   419,   420,   421,   422,   423,   424,   425,
     426,   427,   428,   429,   430,   138,   139,   140,   141,   142,
     143,   144,   145,   146,   147,   148,   149,   431,   150,   151,
     152,   153,   154,   155,   156,   157,   158,   432,     0,     0,
     433,     0,     0,     0,     0,     0,   434,   644,   435,   645,
     436,   160,   161,   437,   438,   439,   162,     0,   163,     0,
       0,     0,     0,     0,     0,     0,     0,   164,   440,  1080,
     441,     2,     3,     4,     5,     6,     7,     8,   398,    10,
      11,     0,    12,     0,     0,     0,     0,     0,    13,     0,
      14,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    15,     0,     0,    16,
      17,     0,     0,     0,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    55,    56,    57,    58,   399,   400,   401,   402,   403,
     404,   405,   406,   407,   408,    69,   409,   410,   411,   412,
     413,   414,    76,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    90,    91,    92,    93,
      94,     0,    95,    96,    97,    98,    99,   100,     0,   415,
     416,     0,     0,   101,   102,   103,   104,   105,   106,   107,
     108,   109,   110,   111,   112,   113,   114,   115,   116,   117,
     118,   119,   120,   121,   122,   123,   124,   125,   126,   127,
     128,   129,   130,   131,   132,   133,   134,   135,   136,   137,
     417,   418,   419,   420,   421,   422,   423,   424,   425,   426,
     427,   428,   429,   430,   138,   139,   140,   141,   142,   143,
     144,   145,   146,   147,   148,   149,   431,   150,   151,   152,
     153,   154,   155,   156,   157,   158,   432,     0,     0,   433,
       0,     0,     0,     0,     0,   434,   644,   435,   645,   436,
     160,   161,   437,   438,   439,   162,     0,   163,     0,     0,
       0,     0,     0,     0,     0,     0,   164,   440,     0,   441,
       2,     3,     4,     5,     6,     7,     8,   398,    10,    11,
       0,    12,     0,     0,     0,     0,     0,    13,     0,    14,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    15,     0,     0,    16,    17,
       0,     0,     0,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,   399,   400,   401,   402,   403,   404,
     405,   406,   407,   408,    69,   409,   410,   411,   412,   413,
     414,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
       0,    95,    96,    97,    98,    99,   100,     0,   415,   416,
       0,     0,   101,   102,   103,   104,   105,   106,   107,   108,
     109,   110,   111,   112,   113,   114,   115,   116,   117,   118,
     119,   120,   121,   122,   123,   124,   125,   126,   127,   128,
     129,   130,   131,   132,   133,   134,   135,   136,   137,   417,
     418,   419,   420,   421,   422,   423,   424,   425,   426,   427,
     428,   429,   430,   138,   139,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   431,   150,   151,   152,   153,
     154,   155,   156,   157,   158,   432,     0,     0,   433,     0,
       0,     0,     0,     0,   434,     0,   435,     0,   436,   160,
     161,   437,   438,   439,   162,     0,   163,     0,     0,     0,
       0,     0,     0,     0,     0,   164,   440,     1,   441,     2,
       3,     4,     5,     6,     7,     8,     9,    10,    11,     0,
      12,     0,     0,     0,     0,     0,    13,     0,    14,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    15,     0,     0,    16,    17,     0,
       0,     0,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    68,    69,    70,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    90,    91,    92,    93,    94,     0,
      95,    96,    97,    98,    99,   100,     0,     0,     0,     0,
       0,   101,   102,   103,   104,   105,   106,   107,   108,   109,
     110,   111,   112,   113,   114,   115,   116,   117,   118,   119,
     120,   121,   122,   123,   124,   125,   126,   127,   128,   129,
     130,   131,   132,   133,   134,   135,   136,   137,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   138,   139,   140,   141,   142,   143,   144,   145,
     146,   147,   148,   149,     0,   150,   151,   152,   153,   154,
     155,   156,   157,   158,     0,     2,     3,     4,     5,     6,
       7,     8,     9,    10,    11,   159,    12,     0,   160,   161,
       0,     0,    13,   162,    14,   163,     0,     0,     0,     0,
       0,     0,     0,   184,   164,     0,     0,     0,     0,     0,
      15,     0,   185,    16,    17,     0,     0,     0,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    68,    69,
      70,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    91,    92,    93,    94,     0,    95,    96,    97,    98,
      99,   100,     0,     0,     0,     0,     0,   101,   102,   103,
     104,   105,   106,   107,   108,   109,   110,   111,   112,   113,
     114,   115,   116,   117,   118,   119,   120,   121,   122,   123,
     124,   125,   126,   127,   128,   129,   130,   131,   132,   133,
     134,   135,   136,   137,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   138,   139,
     140,   141,   142,   143,   144,   145,   146,   147,   148,   149,
       0,   150,   151,   152,   153,   154,   155,   156,   157,   158,
       0,     2,     3,     4,     5,     6,     7,     8,     9,    10,
      11,   159,    12,     0,   160,   161,     0,     0,    13,   162,
      14,   163,     0,     0,     0,     0,     0,     0,     0,     0,
     164,     0,     0,     0,     0,     0,    15,     0,     0,    16,
      17,     0,     0,     0,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    68,    69,    70,    71,    72,    73,
      74,    75,    76,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    90,    91,    92,    93,
      94,     0,    95,    96,    97,    98,    99,   100,     0,     0,
       0,   751,   752,   101,   102,   103,   104,   105,   106,   107,
     108,   109,   110,   111,   112,   113,   114,   115,   116,   117,
     118,   119,   120,   121,   122,   123,   124,   125,   126,   127,
     128,   129,   130,   131,   132,   133,   134,   135,   136,   137,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   138,   139,   140,   141,   142,   143,
     144,   145,   146,   147,   148,   149,     0,   150,   151,   152,
     153,   154,   155,   156,   157,   158,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   159,     0,     0,
     160,   161,     0,     0,     0,   162,     0,   163,     0,     0,
       0,     0,     0,     0,     0,     0,   164,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,   341,    12,     0,
       0,     0,     0,     0,    13,     0,    14,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    15,     0,     0,    16,    17,     0,     0,     0,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      68,    69,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    90,    91,    92,    93,    94,     0,    95,    96,
      97,    98,    99,   100,     0,     0,     0,     0,     0,   101,
     102,   103,   104,   105,   106,   107,   108,   109,   110,   111,
     112,   113,   114,   115,   116,   117,   118,   119,   120,   121,
     122,   123,   124,   125,   126,   127,   128,   129,   130,   131,
     132,   133,   134,   135,   136,   137,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     138,   139,   140,   141,   142,   143,   144,   145,   146,   147,
     148,   149,     0,   150,   151,   152,   153,   154,   155,   156,
     157,   158,     0,     2,     3,     4,     5,     6,     7,     8,
       9,    10,    11,   159,    12,     0,   160,   161,     0,     0,
      13,   162,    14,   163,     0,     0,     0,     0,     0,     0,
       0,   345,   164,     0,     0,     0,     0,     0,    15,     0,
       0,    16,    17,     0,     0,     0,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    68,    69,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    89,    90,    91,
      92,    93,    94,     0,    95,    96,    97,    98,    99,   100,
       0,     0,     0,     0,     0,   101,   102,   103,   104,   105,
     106,   107,   108,   109,   110,   111,   112,   113,   114,   115,
     116,   117,   118,   119,   120,   121,   122,   123,   124,   125,
     126,   127,   128,   129,   130,   131,   132,   133,   134,   135,
     136,   137,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   138,   139,   140,   141,
     142,   143,   144,   145,   146,   147,   148,   149,     0,   150,
     151,   152,   153,   154,   155,   156,   157,   158,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   159,
       0,     0,   160,   161,     0,     0,     0,   162,     0,   163,
       0,     0,     0,     0,     0,     0,     0,     0,   164,     2,
       3,     4,     5,     6,     7,     8,     9,    10,    11,   743,
      12,     0,     0,     0,     0,     0,    13,     0,    14,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    15,     0,     0,    16,    17,     0,
       0,     0,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    68,    69,    70,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    90,    91,    92,    93,    94,     0,
      95,    96,    97,    98,    99,   100,     0,     0,     0,     0,
       0,   101,   102,   103,   104,   105,   106,   107,   108,   109,
     110,   111,   112,   113,   114,   115,   116,   117,   118,   119,
     120,   121,   122,   123,   124,   125,   126,   127,   128,   129,
     130,   131,   132,   133,   134,   135,   136,   137,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   138,   139,   140,   141,   142,   143,   144,   145,
     146,   147,   148,   149,     0,   150,   151,   152,   153,   154,
     155,   156,   157,   158,     0,     2,     3,     4,     5,     6,
       7,     8,     9,    10,    11,   159,    12,     0,   160,   161,
       0,     0,    13,   162,    14,   163,     0,     0,     0,     0,
     745,     0,     0,     0,   164,     0,     0,     0,     0,     0,
      15,     0,     0,    16,    17,     0,     0,     0,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    68,    69,
      70,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    91,    92,    93,    94,     0,    95,    96,    97,    98,
      99,   100,     0,     0,     0,     0,     0,   101,   102,   103,
     104,   105,   106,   107,   108,   109,   110,   111,   112,   113,
     114,   115,   116,   117,   118,   119,   120,   121,   122,   123,
     124,   125,   126,   127,   128,   129,   130,   131,   132,   133,
     134,   135,   136,   137,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   138,   139,
     140,   141,   142,   143,   144,   145,   146,   147,   148,   149,
       0,   150,   151,   152,   153,   154,   155,   156,   157,   158,
       0,     2,     3,     4,     5,     6,     7,     8,     9,    10,
      11,   159,    12,     0,   160,   161,     0,     0,    13,   162,
      14,   163,     0,     0,     0,     0,     0,     0,   396,     0,
     164,     0,     0,     0,     0,     0,    15,     0,     0,    16,
      17,     0,     0,     0,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    68,    69,    70,    71,    72,    73,
      74,    75,    76,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    90,    91,    92,    93,
      94,     0,    95,    96,    97,    98,    99,   100,     0,     0,
       0,     0,     0,   101,   102,   103,   104,   105,   106,   107,
     108,   109,   110,   111,   112,   113,   114,   115,   116,   117,
     118,   119,   120,   121,   122,   123,   124,   125,   126,   127,
     128,   129,   130,   131,   132,   133,   134,   135,   136,   137,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   138,   139,   140,   141,   142,   143,
     144,   145,   146,   147,   148,   149,     0,   150,   151,   152,
     153,   154,   155,   156,   157,   158,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   159,     0,     0,
     160,   161,     0,     0,     0,   162,     0,   163,     0,     0,
       0,     0,     0,     0,     0,     0,   164,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,   795,    12,     0,
       0,     0,     0,     0,    13,     0,    14,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    15,     0,     0,    16,    17,     0,     0,     0,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      68,    69,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    90,    91,    92,    93,    94,     0,    95,    96,
      97,    98,    99,   100,     0,     0,     0,     0,     0,   101,
     102,   103,   104,   105,   106,   107,   108,   109,   110,   111,
     112,   113,   114,   115,   116,   117,   118,   119,   120,   121,
     122,   123,   124,   125,   126,   127,   128,   129,   130,   131,
     132,   133,   134,   135,   136,   137,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     138,   139,   140,   141,   142,   143,   144,   145,   146,   147,
     148,   149,     0,   150,   151,   152,   153,   154,   155,   156,
     157,   158,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   159,     0,     0,   160,   161,     0,     0,
       0,   162,     0,   163,     0,     0,     0,     0,     0,     0,
       0,     0,   164,     2,     3,     4,     5,     6,     7,     8,
       9,    10,    11,   857,    12,     0,     0,     0,     0,     0,
      13,     0,    14,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    15,     0,
       0,    16,    17,     0,     0,     0,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    68,    69,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    89,    90,    91,
      92,    93,    94,     0,    95,    96,    97,    98,    99,   100,
       0,     0,     0,     0,     0,   101,   102,   103,   104,   105,
     106,   107,   108,   109,   110,   111,   112,   113,   114,   115,
     116,   117,   118,   119,   120,   121,   122,   123,   124,   125,
     126,   127,   128,   129,   130,   131,   132,   133,   134,   135,
     136,   137,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   138,   139,   140,   141,
     142,   143,   144,   145,   146,   147,   148,   149,     0,   150,
     151,   152,   153,   154,   155,   156,   157,   158,     0,     2,
       3,     4,     5,     6,     7,     8,     9,    10,    11,   159,
      12,     0,   160,   161,     0,     0,    13,   162,    14,   163,
       0,     0,     0,   995,     0,     0,     0,     0,   164,     0,
       0,     0,     0,     0,    15,     0,     0,    16,    17,     0,
       0,     0,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    68,    69,    70,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    90,    91,    92,    93,    94,     0,
      95,    96,    97,    98,    99,   100,     0,     0,     0,     0,
       0,   101,   102,   103,   104,   105,   106,   107,   108,   109,
     110,   111,   112,   113,   114,   115,   116,   117,   118,   119,
     120,   121,   122,   123,   124,   125,   126,   127,   128,   129,
     130,   131,   132,   133,   134,   135,   136,   137,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   138,   139,   140,   141,   142,   143,   144,   145,
     146,   147,   148,   149,     0,   150,   151,   152,   153,   154,
     155,   156,   157,   158,     0,     2,     3,     4,     5,     6,
       7,     8,     9,    10,    11,   159,    12,     0,   160,   161,
       0,     0,    13,   162,    14,   163,     0,     0,     0,   997,
       0,     0,     0,     0,   164,     0,     0,     0,     0,     0,
      15,     0,     0,    16,    17,     0,     0,     0,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    68,    69,
      70,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    91,    92,    93,    94,     0,    95,    96,    97,    98,
      99,   100,     0,     0,     0,     0,     0,   101,   102,   103,
     104,   105,   106,   107,   108,   109,   110,   111,   112,   113,
     114,   115,   116,   117,   118,   119,   120,   121,   122,   123,
     124,   125,   126,   127,   128,   129,   130,   131,   132,   133,
     134,   135,   136,   137,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   138,   139,
     140,   141,   142,   143,   144,   145,   146,   147,   148,   149,
       0,   150,   151,   152,   153,   154,   155,   156,   157,   158,
       0,     2,     3,     4,     5,     6,     7,     8,     9,    10,
      11,   159,    12,     0,   160,   161,     0,     0,    13,   162,
      14,   163,     0,     0,     0,  1001,     0,     0,     0,     0,
     164,     0,     0,     0,     0,     0,    15,     0,     0,    16,
      17,     0,     0,     0,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    68,    69,    70,    71,    72,    73,
      74,    75,    76,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    90,    91,    92,    93,
      94,     0,    95,    96,    97,    98,    99,   100,     0,     0,
       0,     0,     0,   101,   102,   103,   104,   105,   106,   107,
     108,   109,   110,   111,   112,   113,   114,   115,   116,   117,
     118,   119,   120,   121,   122,   123,   124,   125,   126,   127,
     128,   129,   130,   131,   132,   133,   134,   135,   136,   137,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   138,   139,   140,   141,   142,   143,
     144,   145,   146,   147,   148,   149,     0,   150,   151,   152,
     153,   154,   155,   156,   157,   158,     0,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,   159,    12,     0,
     160,   161,     0,     0,    13,   162,    14,   163,     0,     0,
       0,     0,     0,     0,     0,     0,   164,     0,     0,     0,
       0,     0,    15,     0,     0,    16,    17,     0,     0,     0,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      68,    69,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    90,    91,    92,    93,    94,     0,    95,    96,
      97,    98,    99,   100,     0,     0,     0,     0,     0,   101,
     102,   103,   104,   105,   106,   107,   108,   109,   110,   111,
     112,   113,   114,   115,   116,   117,   118,   119,   120,   121,
     122,   123,   124,   125,   126,   127,   128,   129,   130,   131,
     132,   133,   134,   135,   136,   137,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     138,   139,   140,   141,   142,   143,   144,   145,   146,   147,
     148,   149,     0,   150,   151,   152,   153,   154,   155,   156,
     157,   158,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   159,     0,     0,   160,   161,     0,     0,
       0,   162,     0,   163,     0,     0,     0,     0,     0,     0,
       0,     0,   164,     2,     3,     4,     5,     6,     7,     8,
       9,    10,    11,     0,    12,     0,   526,     0,     0,     0,
       0,     0,    14,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    15,     0,
       0,    16,    17,     0,     0,     0,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    68,    69,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    89,    90,    91,
      92,    93,     0,     0,    95,    96,    97,    98,    99,   100,
       0,     0,     0,     0,     0,   101,   102,   103,   104,   105,
     106,   107,   108,   109,   110,   111,   112,   113,   114,   115,
     116,   117,   118,   119,   120,   121,   122,   123,   124,   125,
     126,   127,   128,   129,   130,   131,   132,   133,   134,   135,
     136,   137,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   138,   139,   140,   141,
     142,   143,   144,   145,   146,   147,   148,   149,     0,   150,
     151,   152,   153,   154,   155,   156,   157,   158,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   159,
       0,     0,   160,   161,     0,     0,     0,   162,     0,   163,
       0,     0,     0,     0,     0,     0,     0,     0,   164,     2,
       3,     4,     5,     6,     7,     8,     9,    10,    11,     0,
      12,     0,   528,     0,     0,     0,     0,     0,    14,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    15,     0,     0,    16,    17,     0,
       0,     0,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    68,    69,    70,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    90,    91,    92,    93,     0,     0,
      95,    96,    97,    98,    99,   100,     0,     0,     0,     0,
       0,   101,   102,   103,   104,   105,   106,   107,   108,   109,
     110,   111,   112,   113,   114,   115,   116,   117,   118,   119,
     120,   121,   122,   123,   124,   125,   126,   127,   128,   129,
     130,   131,   132,   133,   134,   135,   136,   137,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   138,   139,   140,   141,   142,   143,   144,   145,
     146,   147,   148,   149,     0,   150,   151,   152,   153,   154,
     155,   156,   157,   158,     0,     2,     3,     4,     5,     6,
       7,     8,     9,    10,    11,   159,    12,     0,   160,   161,
       0,     0,     0,   162,    14,   163,     0,     0,     0,     0,
       0,     0,     0,     0,   164,     0,     0,     0,     0,     0,
      15,     0,     0,    16,    17,     0,     0,     0,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    68,    69,
      70,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    91,    92,    93,     0,     0,    95,    96,    97,    98,
      99,   100,     0,     0,     0,     0,     0,   101,   102,   103,
     104,   105,   106,   107,   108,   109,   110,   111,   112,   113,
     114,   115,   116,   117,   118,   119,   120,   121,   122,   123,
     124,   125,   126,   127,   128,   129,   130,   131,   132,   133,
     134,   135,   136,   137,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   138,   139,
     140,   141,   142,   143,   144,   145,   146,   147,   148,   149,
       0,   150,   151,   152,   153,   154,   155,   156,   157,   158,
       0,     2,     3,     4,     5,     6,     7,     8,     9,    10,
      11,   159,    12,     0,   160,   161,     0,     0,     0,   162,
      14,   163,     0,     0,     0,     0,     0,     0,     0,     0,
     164,     0,     0,     0,     0,     0,   537,     0,     0,    16,
      17,     0,     0,     0,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    68,    69,    70,    71,    72,    73,
      74,    75,    76,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    90,    91,    92,    93,
       0,     0,    95,    96,    97,    98,    99,   100,     0,     0,
       0,     0,     0,   101,   102,   103,   104,   105,   106,   107,
     108,   109,   110,   111,   112,   113,   114,   115,   116,   117,
     118,   119,   120,   121,   122,   123,   124,   125,   126,   127,
     128,   129,   130,   131,   132,   133,   134,   135,   136,   137,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   138,   139,   140,   141,   142,   143,
     144,   145,   146,   147,   148,   149,     0,   150,   151,   152,
     153,   154,   155,   156,   157,   158,     0,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,   159,    12,     0,
     160,   161,     0,     0,     0,   162,    14,   163,     0,     0,
       0,     0,     0,     0,     0,     0,   164,     0,     0,     0,
       0,     0,   540,     0,     0,    16,    17,     0,     0,     0,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      68,    69,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    90,    91,    92,    93,     0,     0,    95,    96,
      97,    98,    99,   100,     0,     0,     0,     0,     0,   101,
     102,   103,   104,   105,   106,   107,   108,   109,   110,   111,
     112,   113,   114,   115,   116,   117,   118,   119,   120,   121,
     122,   123,   124,   125,   126,   127,   128,   129,   130,   131,
     132,   133,   134,   135,   136,   137,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     138,   139,   140,   141,   142,   143,   144,   145,   146,   147,
     148,   149,     0,   150,   151,   152,   153,   154,   155,   156,
     157,   158,     0,     2,     3,     4,     5,     6,     7,     8,
       9,    10,    11,   159,    12,     0,   160,   161,     0,     0,
       0,   162,    14,   163,     0,     0,     0,     0,     0,     0,
       0,     0,   164,     0,     0,     0,     0,     0,   547,     0,
       0,    16,    17,     0,     0,     0,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    68,    69,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    89,    90,    91,
      92,    93,     0,     0,    95,    96,    97,    98,    99,   100,
       0,     0,     0,     0,     0,   101,   102,   103,   104,   105,
     106,   107,   108,   109,   110,   111,   112,   113,   114,   115,
     116,   117,   118,   119,   120,   121,   122,   123,   124,   125,
     126,   127,   128,   129,   130,   131,   132,   133,   134,   135,
     136,   137,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   138,   139,   140,   141,
     142,   143,   144,   145,   146,   147,   148,   149,     0,   150,
     151,   152,   153,   154,   155,   156,   157,   158,     0,     2,
       3,     4,     5,     6,     7,     8,     9,    10,    11,   159,
      12,     0,   160,   161,     0,     0,     0,   162,    14,   163,
       0,     0,     0,     0,     0,     0,     0,     0,   164,     0,
       0,     0,     0,     0,   545,     0,     0,     0,     0,     0,
       0,     0,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    68,    69,    70,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    90,    91,    92,    93,     0,     0,
      95,    96,    97,    98,    99,   100,     0,     0,     0,     0,
       0,   101,   102,   103,   104,   105,   106,   107,   108,   109,
     110,   111,   112,   113,   114,   115,   116,   117,   118,   119,
     120,   121,   122,   123,   124,   125,   126,   127,   128,   129,
     130,   131,   132,   133,   134,   135,   136,   137,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   138,   139,   140,   141,   142,   143,   144,   145,
     146,   147,   148,   149,     0,   150,   151,   152,   153,   154,
     155,   156,   157,   158,     0,     2,     3,     4,     5,     6,
       7,     8,     9,    10,    11,   159,    12,     0,   160,   161,
       0,     0,     0,   162,    14,   163,     0,     0,     0,     0,
       0,     0,     0,     0,   164,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    68,    69,
      70,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    91,    92,    93,     0,     0,    95,    96,    97,    98,
      99,   100,     0,     0,     0,     0,     0,   101,   102,   103,
     104,   105,   106,   107,   108,   109,   110,   111,   112,   113,
     114,   115,   116,   117,   118,   119,   120,   121,   122,   123,
     124,   125,   126,   127,   128,   129,   130,   131,   132,   133,
     134,   135,   136,   137,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   138,   139,
     140,   141,   142,   143,   144,   145,   146,   147,   148,   149,
       0,   150,   151,   152,   153,   154,   155,   156,   157,   158,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   159,     0,     0,   160,   161,     0,     0,     0,   162,
       0,   163,     0,     0,     0,     0,     0,     0,     0,     0,
     164
};

static const yytype_int16 yycheck[] =
{
       0,    16,    17,    15,    13,    39,    40,   729,    39,    40,
     245,    11,    12,   182,    14,    39,    40,    39,    40,   646,
    1055,    19,    12,    21,   521,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    12,    70,    71,    72,    73,    74,
      75,   324,   325,   326,   327,   328,    10,    10,    18,    10,
      21,     0,    12,    23,    19,    14,    16,    27,    39,    40,
      39,    40,   217,    28,   219,    13,    31,    37,    39,    40,
      29,    19,    13,    12,    14,    13,    35,    13,    19,    16,
      13,   803,    13,  1118,    48,    48,    45,    48,    13,    29,
      13,    39,    40,    10,    94,    35,    13,    29,    39,    40,
     727,    39,    40,    39,    40,    45,    39,    40,    39,    40,
      13,   218,    13,   220,    39,    40,    39,    40,   287,   288,
      13,    16,    13,    12,    19,    13,   218,    13,   220,   123,
      13,    15,    13,   240,   856,   304,    39,    40,    39,    40,
     309,    13,   218,    12,   220,    13,    39,    40,    39,    40,
      13,    39,    40,    39,    40,   650,    39,    40,    39,    40,
     172,   218,    13,   220,   240,    32,    33,    39,    40,    36,
     892,    39,    40,    34,    41,    42,    39,    40,    39,    40,
      12,   215,   216,   240,   184,   216,    12,   209,    39,    40,
     214,    12,   192,   193,   194,   195,   196,   197,   198,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   730,   729,   216,    12,   216,    12,   217,
     240,   219,   212,   526,    12,   528,   228,   229,   230,   231,
     232,   233,   234,   235,   254,   255,   256,   257,   258,   981,
      12,   261,   262,   263,   264,   265,   266,   267,   268,   269,
     270,   271,   272,   273,   274,   275,   276,   277,   278,   279,
     280,   281,   282,   283,   284,   285,   286,    41,    42,   289,
     290,   291,   292,   293,   294,   295,   296,   297,   298,   299,
     300,   301,   302,   303,   799,   305,   306,   307,   308,    13,
     310,   311,   809,   322,   323,   315,    12,   317,    43,    44,
     335,   336,    13,   335,   336,   340,   245,   339,   340,    13,
     245,    13,    19,    39,    40,    39,    40,   337,   227,   228,
     229,   230,   231,   232,   233,   234,   235,    12,    39,    40,
     350,   351,    39,    40,    13,    39,    40,    39,    40,    13,
     855,   856,    13,    30,    13,   400,   401,   402,   403,   404,
     405,   406,   407,   408,   409,   410,   411,   412,   413,   414,
      39,    40,   551,   552,    13,    39,    40,    13,    39,    40,
      39,    40,    13,    13,    13,    13,    13,   892,    13,    13,
      13,   220,    13,    10,    13,   329,   330,   331,   332,   333,
      39,    40,    13,    39,    40,    13,    10,    13,    39,    40,
      39,    40,    39,    40,    39,    40,    39,    40,    39,    40,
      39,    40,   432,    13,   931,    12,   436,    13,    39,    40,
      13,    39,    40,    39,    40,    12,   941,    13,    16,    13,
     619,    13,    12,   453,    13,    12,   625,   626,    13,    39,
      40,   630,    13,    39,    40,    13,    39,    40,    13,    15,
      13,   966,    13,    39,    40,    39,    40,    39,    40,    13,
      39,    40,    13,    19,    39,    40,   981,    13,    39,    40,
      13,    39,    40,    13,    39,    40,    39,    40,    39,    40,
     218,    12,   220,    39,    40,    39,    40,    12,    39,    40,
      16,    13,    12,    39,    40,    13,    39,    40,    12,    39,
      40,    13,   240,   442,    13,   537,   538,   442,   540,   541,
      13,   700,    13,   545,    13,   547,   548,    39,    40,    13,
      12,    39,    40,  1038,   713,    13,    12,    39,    40,    13,
      39,    40,   787,    13,   554,   790,    39,    40,    39,    40,
      39,    40,    13,    19,    13,    39,    40,    13,    21,   738,
      13,    39,    40,    13,    12,    39,    40,    12,    16,    39,
      40,    16,    17,    39,    40,    12,    39,    40,    39,    40,
      39,    40,    12,    39,    40,    10,    39,    40,    12,    39,
      40,   601,   602,   603,   604,   605,   606,   607,   608,   609,
     610,   611,   612,   613,   614,   615,   616,   617,   618,    13,
     620,   621,   622,   623,   624,    13,    12,   627,   628,   629,
      20,   631,    12,   633,    13,    16,    17,    13,    12,   639,
      12,    16,    17,   643,    13,    39,    40,   212,   213,    39,
      40,    39,    40,    15,   654,   655,    12,   657,   658,    12,
      39,    40,   662,    39,    40,   665,   666,    13,   668,   669,
      39,    40,    13,   673,   674,   675,   676,    39,    40,    12,
     680,   681,   682,   683,   684,   685,   686,   687,   688,   689,
     218,    12,   220,    39,    40,    16,    17,   866,    39,    40,
      13,   701,   702,   703,   704,   705,   706,   707,   708,   709,
     710,   711,   240,    20,   714,   715,   716,    13,   718,   719,
     720,    13,   957,   958,   893,   725,    39,    40,    13,   898,
      13,   650,    39,    40,    13,   650,    13,    13,    13,   908,
      13,    10,    13,    39,    40,    13,    12,    39,    40,    13,
      20,    13,    10,    13,    39,    40,    39,    40,    13,   928,
      39,    40,    39,    40,    39,    40,    39,    40,    39,    40,
      13,    39,    40,    13,    21,    39,    40,    39,    40,    39,
      40,    13,    12,    12,    39,    40,    13,    12,   788,   789,
      13,    12,    39,    40,    13,    12,    39,    40,    13,    39,
      40,   218,    15,   220,    12,    15,    12,    39,    40,    19,
     729,    21,    39,    40,   729,    15,    39,    40,    12,  1054,
      39,    40,    19,   240,    39,    40,    39,    40,    20,    39,
      40,    12,    12,   218,   218,   220,   220,    19,    12,    39,
      40,    12,    39,    40,    19,    12,    19,    39,    40,   649,
     650,    12,   852,  1022,  1023,   240,   240,    39,    40,    21,
     860,    12,   862,   863,    39,    40,    39,    40,   787,    19,
      12,   790,   787,    20,   874,   790,   876,    39,    40,   879,
     799,    19,  1117,    19,   799,   885,   886,    19,    16,    39,
      40,   891,    39,    40,   894,    19,   896,   897,    19,   899,
     900,    39,    40,    39,    40,    12,    19,    39,    40,   909,
      19,   911,    12,   913,    12,    39,    40,    16,    39,    40,
      12,    31,    19,   923,    19,   925,    39,    40,    19,   729,
      39,    40,    19,   933,    19,   935,   855,   856,   938,    12,
     855,   856,    39,    40,    39,    40,   946,   947,    39,    40,
     950,    19,    39,    40,    39,    40,    21,    12,    19,   959,
      19,    12,    19,   963,    12,    12,    19,    12,    12,  1138,
    1139,    39,    40,   892,    39,    40,  1145,   892,    39,    40,
      39,    40,    39,    40,    19,   985,    39,    40,   988,    19,
     990,    19,    16,    19,    12,   995,    13,   997,    12,    19,
    1000,  1001,   802,    19,    39,    40,    16,    19,  1008,    39,
      40,    39,    40,    39,    40,    21,  1016,    12,  1018,    39,
      40,    12,   941,    39,    40,    12,   941,    39,    40,    19,
      16,  1031,  1032,    39,    40,  1035,    12,    19,   957,   958,
      19,    13,   957,   958,    19,    13,  1046,   966,    19,    39,
      40,   966,    19,  1053,   854,   855,   856,    39,    40,    12,
      39,    40,   981,    19,    39,    40,   981,    19,    39,    40,
      12,  1071,    39,    40,    19,    12,    19,    12,  1078,    19,
    1080,    19,    12,    39,    40,    12,    19,    39,    40,    12,
    1090,  1091,   892,    19,    39,    40,    39,    40,    20,    39,
      40,    39,    40,    16,  1104,  1105,    39,    40,    19,  1109,
      19,    12,    19,    39,    40,    20,    12,    39,    40,  1038,
      12,    12,    19,  1038,    19,    12,    19,    16,    39,    40,
      39,    40,    39,    40,    19,  1054,    19,   937,    19,  1054,
     940,   941,    39,    40,    39,    40,    39,    40,    19,    12,
      19,    12,    19,    12,    39,    40,    39,    40,    39,    40,
      13,    12,    12,    19,    12,   965,   966,    19,    39,    40,
      39,    40,    39,    40,    19,    12,    19,    12,    16,    19,
      12,   981,   982,    39,    40,    19,    13,    39,    40,    19,
      12,    19,   992,    19,    39,    40,    39,    40,  1117,    39,
      40,    19,  1117,    12,    20,    39,    40,    20,    12,    39,
      40,    39,    40,    39,    40,    20,    12,    16,    12,    12,
    1020,    39,    40,    39,    40,    20,    39,    40,    20,    12,
      20,    16,    20,    12,    39,    40,    20,  1037,  1038,    20,
    1040,  1041,    20,  1043,    39,    40,    20,    39,    40,    39,
      40,    39,    40,    21,    12,    39,    40,    21,    39,    40,
      21,    39,    40,    12,    16,    39,    40,    12,  1068,    12,
      12,    39,    40,    21,    13,    39,    40,    21,    39,    40,
      16,    12,  1082,    21,    10,  1085,    21,  1087,  1088,    21,
      12,    39,    40,    21,    12,    39,    40,    21,    12,  1099,
    1100,    39,    40,    12,    39,    40,  1106,    39,    40,    12,
      16,    39,    40,    12,  1114,    39,    40,    12,    12,    12,
       3,     4,     5,     6,     7,     8,     9,    10,    11,    12,
    1130,    14,    21,    15,  1134,  1135,    12,    20,    12,    22,
      12,    12,    12,    12,    12,    24,    25,    26,  1148,    12,
      39,    40,    12,    12,    12,    38,    12,    12,    41,    42,
      39,    40,    12,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,    68,    69,    70,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    88,    89,    90,    91,    92,
      93,    94,    95,    96,    97,    98,    99,   100,   101,   102,
     103,   104,   105,   106,   107,   108,   109,   110,   111,   112,
     113,   114,   115,   116,   117,   118,   119,   120,   121,   122,
      12,   124,   125,   126,   127,   128,   129,    16,   131,   132,
      12,    10,   135,   136,   137,   138,   139,   140,   141,   142,
     143,   144,   145,   146,   147,   148,   149,   150,   151,   152,
     153,   154,   155,   156,   157,   158,   159,   160,   161,   162,
     163,   164,   165,   166,   167,   168,   169,   170,   171,   172,
     173,   174,   175,   176,   177,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   187,   188,   189,   190,   191,   192,
     193,   194,   195,   196,   197,   198,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,    10,    21,   211,    21,
      10,    10,    28,    19,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,    13,   229,   228,   229,   230,
     231,   232,   233,   234,   237,   238,   239,   240,   241,     3,
       4,     5,     6,     7,     8,     9,    10,    11,    12,    15,
      14,    12,    12,   237,    13,    13,    20,    13,    22,   227,
     228,   229,   230,   231,   232,   233,   234,   235,    13,    19,
      19,    19,    19,    19,    38,    19,    13,    41,    42,    13,
      13,    13,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    68,    69,    70,    71,    72,    73,
      74,    75,    76,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    90,    91,    92,    93,
      94,    95,    96,    97,    98,    99,   100,   101,   102,   103,
     104,   105,   106,   107,   108,   109,   110,   111,   112,   113,
     114,   115,   116,   117,   118,   119,   120,   121,   122,    27,
     124,   125,   126,   127,   128,   129,    27,   131,   132,    27,
     210,   135,   136,   137,   138,   139,   140,   141,   142,   143,
     144,   145,   146,   147,   148,   149,   150,   151,   152,   153,
     154,   155,   156,   157,   158,   159,   160,   161,   162,   163,
     164,   165,   166,   167,   168,   169,   170,   171,   172,   173,
     174,   175,   176,   177,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   187,   188,   189,   190,   191,   192,   193,
     194,   195,   196,   197,   198,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,    13,    13,   211,    13,    13,
      13,    13,    13,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,    13,   229,    13,   236,    42,    13,
      13,    19,    13,   237,   238,   239,   240,   241,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    27,    14,
      13,    13,    13,    13,   516,    20,    94,    22,   642,  1127,
     662,  1118,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    38,    -1,    -1,    41,    42,    -1,    -1,
      -1,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    97,    98,    99,   100,   101,   102,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   122,    -1,   124,
     125,   126,   127,   128,   129,    -1,   131,   132,    -1,    -1,
     135,   136,   137,   138,   139,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150,   151,   152,   153,   154,
     155,   156,   157,   158,   159,   160,   161,   162,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   172,   173,   174,
     175,   176,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   191,   192,   193,   194,
     195,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,    -1,    -1,   211,    -1,    -1,    -1,
      -1,    -1,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,    -1,   229,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   237,   238,   239,   240,   241,     3,     4,     5,
       6,     7,     8,     9,    10,    11,    12,    -1,    14,    -1,
      -1,    -1,    -1,    -1,    20,    -1,    22,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    38,    -1,    -1,    41,    42,    -1,    -1,    -1,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    68,    69,    70,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    90,    91,    92,    93,    94,    95,
      96,    97,    98,    99,   100,   101,   102,   103,   104,   105,
     106,   107,   108,   109,   110,   111,   112,   113,   114,   115,
     116,   117,   118,   119,   120,   121,   122,    -1,   124,   125,
     126,   127,   128,   129,    -1,   131,   132,    -1,    -1,   135,
     136,   137,   138,   139,   140,   141,   142,   143,   144,   145,
     146,   147,   148,   149,   150,   151,   152,   153,   154,   155,
     156,   157,   158,   159,   160,   161,   162,   163,   164,   165,
     166,   167,   168,   169,   170,   171,   172,   173,   174,   175,
     176,   177,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   187,   188,   189,   190,   191,   192,   193,   194,   195,
     196,   197,   198,   199,   200,   201,   202,   203,   204,   205,
     206,   207,   208,    -1,    -1,   211,    -1,    -1,    -1,    -1,
      -1,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,    -1,   229,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   237,   238,   239,   240,   241,     3,     4,     5,     6,
       7,     8,     9,    10,    11,    12,    -1,    14,    -1,    -1,
      -1,    -1,    -1,    20,    -1,    22,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    38,    -1,    -1,    41,    42,    -1,    -1,    -1,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,    68,    69,    70,    71,    72,    73,    74,    75,    76,
      77,    78,    79,    80,    81,    82,    83,    84,    85,    86,
      87,    88,    89,    90,    91,    92,    93,    94,    95,    96,
      97,    98,    99,   100,   101,   102,   103,   104,   105,   106,
     107,   108,   109,   110,   111,   112,   113,   114,   115,   116,
     117,   118,   119,   120,   121,   122,    -1,   124,   125,   126,
     127,   128,   129,    -1,   131,   132,    -1,    -1,   135,   136,
     137,   138,   139,   140,   141,   142,   143,   144,   145,   146,
     147,   148,   149,   150,   151,   152,   153,   154,   155,   156,
     157,   158,   159,   160,   161,   162,   163,   164,   165,   166,
     167,   168,   169,   170,   171,   172,   173,   174,   175,   176,
     177,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,   190,   191,   192,   193,   194,   195,   196,
     197,   198,   199,   200,   201,   202,   203,   204,   205,   206,
     207,   208,    -1,    -1,   211,    -1,    -1,    -1,    -1,    -1,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,    -1,   229,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     237,   238,   239,    -1,   241,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    -1,    14,    -1,    -1,    -1,
      -1,    -1,    20,    -1,    22,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      38,    -1,    -1,    41,    42,    -1,    -1,    -1,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      68,    69,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    90,    91,    92,    93,    94,    95,    96,    97,
      98,    99,   100,   101,   102,   103,   104,   105,   106,   107,
     108,   109,   110,   111,   112,   113,   114,   115,   116,   117,
     118,   119,   120,   121,   122,    -1,   124,   125,   126,   127,
     128,   129,    -1,   131,   132,    -1,    -1,   135,   136,   137,
     138,   139,   140,   141,   142,   143,   144,   145,   146,   147,
     148,   149,   150,   151,   152,   153,   154,   155,   156,   157,
     158,   159,   160,   161,   162,   163,   164,   165,   166,   167,
     168,   169,   170,   171,   172,   173,   174,   175,   176,   177,
     178,   179,   180,   181,   182,   183,   184,   185,   186,   187,
     188,   189,   190,   191,   192,   193,   194,   195,   196,   197,
     198,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     208,    -1,    -1,   211,    -1,    -1,    -1,    -1,    -1,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
      -1,   229,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     238,   239,   240,   241,     3,     4,     5,     6,     7,     8,
       9,    10,    11,    12,    -1,    14,    -1,    -1,    -1,    -1,
      -1,    20,    -1,    22,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    38,
      -1,    -1,    41,    42,    -1,    -1,    -1,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    68,
      69,    70,    71,    72,    73,    74,    75,    76,    77,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    87,    88,
      89,    90,    91,    92,    93,    94,    95,    96,    97,    98,
      99,   100,   101,   102,   103,   104,   105,   106,   107,   108,
     109,   110,   111,   112,   113,   114,   115,   116,   117,   118,
     119,   120,   121,   122,    -1,   124,   125,   126,   127,   128,
     129,    -1,   131,   132,    -1,    -1,   135,   136,   137,   138,
     139,   140,   141,   142,   143,   144,   145,   146,   147,   148,
     149,   150,   151,   152,   153,   154,   155,   156,   157,   158,
     159,   160,   161,   162,   163,   164,   165,   166,   167,   168,
     169,   170,   171,   172,   173,   174,   175,   176,   177,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,   190,   191,   192,   193,   194,   195,   196,   197,   198,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
      -1,    -1,   211,    -1,    -1,    -1,    -1,    -1,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,    -1,
     229,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   238,
     239,   240,   241,     3,     4,     5,     6,     7,     8,     9,
      10,    11,    12,    -1,    14,    -1,    -1,    -1,    -1,    -1,
      20,    -1,    22,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    38,    -1,
      -1,    41,    42,    -1,    -1,    -1,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    68,    69,
      70,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    91,    92,    93,    94,    95,    96,    97,    98,    99,
     100,   101,   102,   103,   104,   105,   106,   107,   108,   109,
     110,   111,   112,   113,   114,   115,   116,   117,   118,   119,
     120,   121,   122,    -1,   124,   125,   126,   127,   128,   129,
      -1,   131,   132,    -1,    -1,   135,   136,   137,   138,   139,
     140,   141,   142,   143,   144,   145,   146,   147,   148,   149,
     150,   151,   152,   153,   154,   155,   156,   157,   158,   159,
     160,   161,   162,   163,   164,   165,   166,   167,   168,   169,
     170,   171,   172,   173,   174,   175,   176,   177,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   187,   188,   189,
     190,   191,   192,   193,   194,   195,   196,   197,   198,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   208,    -1,
      -1,   211,    -1,    -1,    -1,    -1,    -1,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,    -1,   229,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   238,   239,
     240,   241,     3,     4,     5,     6,     7,     8,     9,    10,
      11,    12,    -1,    14,    -1,    -1,    -1,    -1,    -1,    20,
      -1,    22,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    38,    -1,    -1,
      41,    42,    -1,    -1,    -1,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    68,    69,    70,
      71,    72,    73,    74,    75,    76,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    89,    90,
      91,    92,    93,    94,    95,    96,    97,    98,    99,   100,
     101,   102,   103,   104,   105,   106,   107,   108,   109,   110,
     111,   112,   113,   114,   115,   116,   117,   118,   119,   120,
     121,   122,    -1,   124,   125,   126,   127,   128,   129,    -1,
     131,   132,    -1,    -1,   135,   136,   137,   138,   139,   140,
     141,   142,   143,   144,   145,   146,   147,   148,   149,   150,
     151,   152,   153,   154,   155,   156,   157,   158,   159,   160,
     161,   162,   163,   164,   165,   166,   167,   168,   169,   170,
     171,   172,   173,   174,   175,   176,   177,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,   190,
     191,   192,   193,   194,   195,   196,   197,   198,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,    -1,    -1,
     211,    -1,    -1,    -1,    -1,    -1,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,    -1,   229,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   238,   239,   240,
     241,     3,     4,     5,     6,     7,     8,     9,    10,    11,
      12,    -1,    14,    -1,    -1,    -1,    -1,    -1,    20,    -1,
      22,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    38,    -1,    -1,    41,
      42,    -1,    -1,    -1,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    68,    69,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    89,    90,    91,
      92,    93,    94,    95,    96,    97,    98,    99,   100,   101,
     102,   103,   104,   105,   106,   107,   108,   109,   110,   111,
     112,   113,   114,   115,   116,   117,   118,   119,   120,   121,
     122,    -1,   124,   125,   126,   127,   128,   129,    -1,   131,
     132,    -1,    -1,   135,   136,   137,   138,   139,   140,   141,
     142,   143,   144,   145,   146,   147,   148,   149,   150,   151,
     152,   153,   154,   155,   156,   157,   158,   159,   160,   161,
     162,   163,   164,   165,   166,   167,   168,   169,   170,   171,
     172,   173,   174,   175,   176,   177,   178,   179,   180,   181,
     182,   183,   184,   185,   186,   187,   188,   189,   190,   191,
     192,   193,   194,   195,   196,   197,   198,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,    -1,    -1,   211,
      -1,    -1,    -1,    -1,    -1,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,    -1,   229,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   238,   239,    -1,   241,
       3,     4,     5,     6,     7,     8,     9,    10,    11,    12,
      -1,    14,    -1,    -1,    -1,    -1,    -1,    20,    -1,    22,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    38,    -1,    -1,    41,    42,
      -1,    -1,    -1,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,    68,    69,    70,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    88,    89,    90,    91,    92,
      93,    94,    95,    96,    97,    98,    99,   100,   101,   102,
     103,   104,   105,   106,   107,   108,   109,   110,   111,   112,
     113,   114,   115,   116,   117,   118,   119,   120,   121,   122,
      -1,   124,   125,   126,   127,   128,   129,    -1,   131,   132,
      -1,    -1,   135,   136,   137,   138,   139,   140,   141,   142,
     143,   144,   145,   146,   147,   148,   149,   150,   151,   152,
     153,   154,   155,   156,   157,   158,   159,   160,   161,   162,
     163,   164,   165,   166,   167,   168,   169,   170,   171,   172,
     173,   174,   175,   176,   177,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   187,   188,   189,   190,   191,   192,
     193,   194,   195,   196,   197,   198,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,    -1,    -1,   211,    -1,
      -1,    -1,    -1,    -1,   217,    -1,   219,    -1,   221,   222,
     223,   224,   225,   226,   227,    -1,   229,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   238,   239,     1,   241,     3,
       4,     5,     6,     7,     8,     9,    10,    11,    12,    -1,
      14,    -1,    -1,    -1,    -1,    -1,    20,    -1,    22,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    38,    -1,    -1,    41,    42,    -1,
      -1,    -1,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    68,    69,    70,    71,    72,    73,
      74,    75,    76,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    90,    91,    92,    93,
      94,    95,    96,    97,    98,    99,   100,   101,   102,   103,
     104,   105,   106,   107,   108,   109,   110,   111,   112,   113,
     114,   115,   116,   117,   118,   119,   120,   121,   122,    -1,
     124,   125,   126,   127,   128,   129,    -1,    -1,    -1,    -1,
      -1,   135,   136,   137,   138,   139,   140,   141,   142,   143,
     144,   145,   146,   147,   148,   149,   150,   151,   152,   153,
     154,   155,   156,   157,   158,   159,   160,   161,   162,   163,
     164,   165,   166,   167,   168,   169,   170,   171,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   186,   187,   188,   189,   190,   191,   192,   193,
     194,   195,   196,   197,    -1,   199,   200,   201,   202,   203,
     204,   205,   206,   207,    -1,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    12,   219,    14,    -1,   222,   223,
      -1,    -1,    20,   227,    22,   229,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    31,   238,    -1,    -1,    -1,    -1,    -1,
      38,    -1,    40,    41,    42,    -1,    -1,    -1,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      68,    69,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    90,    91,    92,    93,    94,    95,    96,    97,
      98,    99,   100,   101,   102,   103,   104,   105,   106,   107,
     108,   109,   110,   111,   112,   113,   114,   115,   116,   117,
     118,   119,   120,   121,   122,    -1,   124,   125,   126,   127,
     128,   129,    -1,    -1,    -1,    -1,    -1,   135,   136,   137,
     138,   139,   140,   141,   142,   143,   144,   145,   146,   147,
     148,   149,   150,   151,   152,   153,   154,   155,   156,   157,
     158,   159,   160,   161,   162,   163,   164,   165,   166,   167,
     168,   169,   170,   171,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   186,   187,
     188,   189,   190,   191,   192,   193,   194,   195,   196,   197,
      -1,   199,   200,   201,   202,   203,   204,   205,   206,   207,
      -1,     3,     4,     5,     6,     7,     8,     9,    10,    11,
      12,   219,    14,    -1,   222,   223,    -1,    -1,    20,   227,
      22,   229,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     238,    -1,    -1,    -1,    -1,    -1,    38,    -1,    -1,    41,
      42,    -1,    -1,    -1,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    68,    69,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    89,    90,    91,
      92,    93,    94,    95,    96,    97,    98,    99,   100,   101,
     102,   103,   104,   105,   106,   107,   108,   109,   110,   111,
     112,   113,   114,   115,   116,   117,   118,   119,   120,   121,
     122,    -1,   124,   125,   126,   127,   128,   129,    -1,    -1,
      -1,   133,   134,   135,   136,   137,   138,   139,   140,   141,
     142,   143,   144,   145,   146,   147,   148,   149,   150,   151,
     152,   153,   154,   155,   156,   157,   158,   159,   160,   161,
     162,   163,   164,   165,   166,   167,   168,   169,   170,   171,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   186,   187,   188,   189,   190,   191,
     192,   193,   194,   195,   196,   197,    -1,   199,   200,   201,
     202,   203,   204,   205,   206,   207,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   219,    -1,    -1,
     222,   223,    -1,    -1,    -1,   227,    -1,   229,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   238,     3,     4,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    -1,
      -1,    -1,    -1,    -1,    20,    -1,    22,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    38,    -1,    -1,    41,    42,    -1,    -1,    -1,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    68,    69,    70,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    90,    91,    92,    93,    94,    95,
      96,    97,    98,    99,   100,   101,   102,   103,   104,   105,
     106,   107,   108,   109,   110,   111,   112,   113,   114,   115,
     116,   117,   118,   119,   120,   121,   122,    -1,   124,   125,
     126,   127,   128,   129,    -1,    -1,    -1,    -1,    -1,   135,
     136,   137,   138,   139,   140,   141,   142,   143,   144,   145,
     146,   147,   148,   149,   150,   151,   152,   153,   154,   155,
     156,   157,   158,   159,   160,   161,   162,   163,   164,   165,
     166,   167,   168,   169,   170,   171,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     186,   187,   188,   189,   190,   191,   192,   193,   194,   195,
     196,   197,    -1,   199,   200,   201,   202,   203,   204,   205,
     206,   207,    -1,     3,     4,     5,     6,     7,     8,     9,
      10,    11,    12,   219,    14,    -1,   222,   223,    -1,    -1,
      20,   227,    22,   229,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    31,   238,    -1,    -1,    -1,    -1,    -1,    38,    -1,
      -1,    41,    42,    -1,    -1,    -1,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    68,    69,
      70,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    91,    92,    93,    94,    95,    96,    97,    98,    99,
     100,   101,   102,   103,   104,   105,   106,   107,   108,   109,
     110,   111,   112,   113,   114,   115,   116,   117,   118,   119,
     120,   121,   122,    -1,   124,   125,   126,   127,   128,   129,
      -1,    -1,    -1,    -1,    -1,   135,   136,   137,   138,   139,
     140,   141,   142,   143,   144,   145,   146,   147,   148,   149,
     150,   151,   152,   153,   154,   155,   156,   157,   158,   159,
     160,   161,   162,   163,   164,   165,   166,   167,   168,   169,
     170,   171,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   186,   187,   188,   189,
     190,   191,   192,   193,   194,   195,   196,   197,    -1,   199,
     200,   201,   202,   203,   204,   205,   206,   207,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   219,
      -1,    -1,   222,   223,    -1,    -1,    -1,   227,    -1,   229,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   238,     3,
       4,     5,     6,     7,     8,     9,    10,    11,    12,    13,
      14,    -1,    -1,    -1,    -1,    -1,    20,    -1,    22,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    38,    -1,    -1,    41,    42,    -1,
      -1,    -1,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    68,    69,    70,    71,    72,    73,
      74,    75,    76,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    90,    91,    92,    93,
      94,    95,    96,    97,    98,    99,   100,   101,   102,   103,
     104,   105,   106,   107,   108,   109,   110,   111,   112,   113,
     114,   115,   116,   117,   118,   119,   120,   121,   122,    -1,
     124,   125,   126,   127,   128,   129,    -1,    -1,    -1,    -1,
      -1,   135,   136,   137,   138,   139,   140,   141,   142,   143,
     144,   145,   146,   147,   148,   149,   150,   151,   152,   153,
     154,   155,   156,   157,   158,   159,   160,   161,   162,   163,
     164,   165,   166,   167,   168,   169,   170,   171,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   186,   187,   188,   189,   190,   191,   192,   193,
     194,   195,   196,   197,    -1,   199,   200,   201,   202,   203,
     204,   205,   206,   207,    -1,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    12,   219,    14,    -1,   222,   223,
      -1,    -1,    20,   227,    22,   229,    -1,    -1,    -1,    -1,
      28,    -1,    -1,    -1,   238,    -1,    -1,    -1,    -1,    -1,
      38,    -1,    -1,    41,    42,    -1,    -1,    -1,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      68,    69,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    90,    91,    92,    93,    94,    95,    96,    97,
      98,    99,   100,   101,   102,   103,   104,   105,   106,   107,
     108,   109,   110,   111,   112,   113,   114,   115,   116,   117,
     118,   119,   120,   121,   122,    -1,   124,   125,   126,   127,
     128,   129,    -1,    -1,    -1,    -1,    -1,   135,   136,   137,
     138,   139,   140,   141,   142,   143,   144,   145,   146,   147,
     148,   149,   150,   151,   152,   153,   154,   155,   156,   157,
     158,   159,   160,   161,   162,   163,   164,   165,   166,   167,
     168,   169,   170,   171,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   186,   187,
     188,   189,   190,   191,   192,   193,   194,   195,   196,   197,
      -1,   199,   200,   201,   202,   203,   204,   205,   206,   207,
      -1,     3,     4,     5,     6,     7,     8,     9,    10,    11,
      12,   219,    14,    -1,   222,   223,    -1,    -1,    20,   227,
      22,   229,    -1,    -1,    -1,    -1,    -1,    -1,    30,    -1,
     238,    -1,    -1,    -1,    -1,    -1,    38,    -1,    -1,    41,
      42,    -1,    -1,    -1,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    68,    69,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    89,    90,    91,
      92,    93,    94,    95,    96,    97,    98,    99,   100,   101,
     102,   103,   104,   105,   106,   107,   108,   109,   110,   111,
     112,   113,   114,   115,   116,   117,   118,   119,   120,   121,
     122,    -1,   124,   125,   126,   127,   128,   129,    -1,    -1,
      -1,    -1,    -1,   135,   136,   137,   138,   139,   140,   141,
     142,   143,   144,   145,   146,   147,   148,   149,   150,   151,
     152,   153,   154,   155,   156,   157,   158,   159,   160,   161,
     162,   163,   164,   165,   166,   167,   168,   169,   170,   171,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   186,   187,   188,   189,   190,   191,
     192,   193,   194,   195,   196,   197,    -1,   199,   200,   201,
     202,   203,   204,   205,   206,   207,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   219,    -1,    -1,
     222,   223,    -1,    -1,    -1,   227,    -1,   229,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   238,     3,     4,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    -1,
      -1,    -1,    -1,    -1,    20,    -1,    22,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    38,    -1,    -1,    41,    42,    -1,    -1,    -1,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    68,    69,    70,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    90,    91,    92,    93,    94,    95,
      96,    97,    98,    99,   100,   101,   102,   103,   104,   105,
     106,   107,   108,   109,   110,   111,   112,   113,   114,   115,
     116,   117,   118,   119,   120,   121,   122,    -1,   124,   125,
     126,   127,   128,   129,    -1,    -1,    -1,    -1,    -1,   135,
     136,   137,   138,   139,   140,   141,   142,   143,   144,   145,
     146,   147,   148,   149,   150,   151,   152,   153,   154,   155,
     156,   157,   158,   159,   160,   161,   162,   163,   164,   165,
     166,   167,   168,   169,   170,   171,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     186,   187,   188,   189,   190,   191,   192,   193,   194,   195,
     196,   197,    -1,   199,   200,   201,   202,   203,   204,   205,
     206,   207,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   219,    -1,    -1,   222,   223,    -1,    -1,
      -1,   227,    -1,   229,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   238,     3,     4,     5,     6,     7,     8,     9,
      10,    11,    12,    13,    14,    -1,    -1,    -1,    -1,    -1,
      20,    -1,    22,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    38,    -1,
      -1,    41,    42,    -1,    -1,    -1,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    68,    69,
      70,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    91,    92,    93,    94,    95,    96,    97,    98,    99,
     100,   101,   102,   103,   104,   105,   106,   107,   108,   109,
     110,   111,   112,   113,   114,   115,   116,   117,   118,   119,
     120,   121,   122,    -1,   124,   125,   126,   127,   128,   129,
      -1,    -1,    -1,    -1,    -1,   135,   136,   137,   138,   139,
     140,   141,   142,   143,   144,   145,   146,   147,   148,   149,
     150,   151,   152,   153,   154,   155,   156,   157,   158,   159,
     160,   161,   162,   163,   164,   165,   166,   167,   168,   169,
     170,   171,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   186,   187,   188,   189,
     190,   191,   192,   193,   194,   195,   196,   197,    -1,   199,
     200,   201,   202,   203,   204,   205,   206,   207,    -1,     3,
       4,     5,     6,     7,     8,     9,    10,    11,    12,   219,
      14,    -1,   222,   223,    -1,    -1,    20,   227,    22,   229,
      -1,    -1,    -1,    27,    -1,    -1,    -1,    -1,   238,    -1,
      -1,    -1,    -1,    -1,    38,    -1,    -1,    41,    42,    -1,
      -1,    -1,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    68,    69,    70,    71,    72,    73,
      74,    75,    76,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    90,    91,    92,    93,
      94,    95,    96,    97,    98,    99,   100,   101,   102,   103,
     104,   105,   106,   107,   108,   109,   110,   111,   112,   113,
     114,   115,   116,   117,   118,   119,   120,   121,   122,    -1,
     124,   125,   126,   127,   128,   129,    -1,    -1,    -1,    -1,
      -1,   135,   136,   137,   138,   139,   140,   141,   142,   143,
     144,   145,   146,   147,   148,   149,   150,   151,   152,   153,
     154,   155,   156,   157,   158,   159,   160,   161,   162,   163,
     164,   165,   166,   167,   168,   169,   170,   171,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   186,   187,   188,   189,   190,   191,   192,   193,
     194,   195,   196,   197,    -1,   199,   200,   201,   202,   203,
     204,   205,   206,   207,    -1,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    12,   219,    14,    -1,   222,   223,
      -1,    -1,    20,   227,    22,   229,    -1,    -1,    -1,    27,
      -1,    -1,    -1,    -1,   238,    -1,    -1,    -1,    -1,    -1,
      38,    -1,    -1,    41,    42,    -1,    -1,    -1,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      68,    69,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    90,    91,    92,    93,    94,    95,    96,    97,
      98,    99,   100,   101,   102,   103,   104,   105,   106,   107,
     108,   109,   110,   111,   112,   113,   114,   115,   116,   117,
     118,   119,   120,   121,   122,    -1,   124,   125,   126,   127,
     128,   129,    -1,    -1,    -1,    -1,    -1,   135,   136,   137,
     138,   139,   140,   141,   142,   143,   144,   145,   146,   147,
     148,   149,   150,   151,   152,   153,   154,   155,   156,   157,
     158,   159,   160,   161,   162,   163,   164,   165,   166,   167,
     168,   169,   170,   171,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   186,   187,
     188,   189,   190,   191,   192,   193,   194,   195,   196,   197,
      -1,   199,   200,   201,   202,   203,   204,   205,   206,   207,
      -1,     3,     4,     5,     6,     7,     8,     9,    10,    11,
      12,   219,    14,    -1,   222,   223,    -1,    -1,    20,   227,
      22,   229,    -1,    -1,    -1,    27,    -1,    -1,    -1,    -1,
     238,    -1,    -1,    -1,    -1,    -1,    38,    -1,    -1,    41,
      42,    -1,    -1,    -1,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    68,    69,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    89,    90,    91,
      92,    93,    94,    95,    96,    97,    98,    99,   100,   101,
     102,   103,   104,   105,   106,   107,   108,   109,   110,   111,
     112,   113,   114,   115,   116,   117,   118,   119,   120,   121,
     122,    -1,   124,   125,   126,   127,   128,   129,    -1,    -1,
      -1,    -1,    -1,   135,   136,   137,   138,   139,   140,   141,
     142,   143,   144,   145,   146,   147,   148,   149,   150,   151,
     152,   153,   154,   155,   156,   157,   158,   159,   160,   161,
     162,   163,   164,   165,   166,   167,   168,   169,   170,   171,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   186,   187,   188,   189,   190,   191,
     192,   193,   194,   195,   196,   197,    -1,   199,   200,   201,
     202,   203,   204,   205,   206,   207,    -1,     3,     4,     5,
       6,     7,     8,     9,    10,    11,    12,   219,    14,    -1,
     222,   223,    -1,    -1,    20,   227,    22,   229,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   238,    -1,    -1,    -1,
      -1,    -1,    38,    -1,    -1,    41,    42,    -1,    -1,    -1,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    68,    69,    70,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    90,    91,    92,    93,    94,    95,
      96,    97,    98,    99,   100,   101,   102,   103,   104,   105,
     106,   107,   108,   109,   110,   111,   112,   113,   114,   115,
     116,   117,   118,   119,   120,   121,   122,    -1,   124,   125,
     126,   127,   128,   129,    -1,    -1,    -1,    -1,    -1,   135,
     136,   137,   138,   139,   140,   141,   142,   143,   144,   145,
     146,   147,   148,   149,   150,   151,   152,   153,   154,   155,
     156,   157,   158,   159,   160,   161,   162,   163,   164,   165,
     166,   167,   168,   169,   170,   171,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     186,   187,   188,   189,   190,   191,   192,   193,   194,   195,
     196,   197,    -1,   199,   200,   201,   202,   203,   204,   205,
     206,   207,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   219,    -1,    -1,   222,   223,    -1,    -1,
      -1,   227,    -1,   229,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   238,     3,     4,     5,     6,     7,     8,     9,
      10,    11,    12,    -1,    14,    -1,    16,    -1,    -1,    -1,
      -1,    -1,    22,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    38,    -1,
      -1,    41,    42,    -1,    -1,    -1,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    68,    69,
      70,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    91,    92,    93,    94,    95,    96,    97,    98,    99,
     100,   101,   102,   103,   104,   105,   106,   107,   108,   109,
     110,   111,   112,   113,   114,   115,   116,   117,   118,   119,
     120,   121,    -1,    -1,   124,   125,   126,   127,   128,   129,
      -1,    -1,    -1,    -1,    -1,   135,   136,   137,   138,   139,
     140,   141,   142,   143,   144,   145,   146,   147,   148,   149,
     150,   151,   152,   153,   154,   155,   156,   157,   158,   159,
     160,   161,   162,   163,   164,   165,   166,   167,   168,   169,
     170,   171,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   186,   187,   188,   189,
     190,   191,   192,   193,   194,   195,   196,   197,    -1,   199,
     200,   201,   202,   203,   204,   205,   206,   207,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   219,
      -1,    -1,   222,   223,    -1,    -1,    -1,   227,    -1,   229,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   238,     3,
       4,     5,     6,     7,     8,     9,    10,    11,    12,    -1,
      14,    -1,    16,    -1,    -1,    -1,    -1,    -1,    22,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    38,    -1,    -1,    41,    42,    -1,
      -1,    -1,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    68,    69,    70,    71,    72,    73,
      74,    75,    76,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    90,    91,    92,    93,
      94,    95,    96,    97,    98,    99,   100,   101,   102,   103,
     104,   105,   106,   107,   108,   109,   110,   111,   112,   113,
     114,   115,   116,   117,   118,   119,   120,   121,    -1,    -1,
     124,   125,   126,   127,   128,   129,    -1,    -1,    -1,    -1,
      -1,   135,   136,   137,   138,   139,   140,   141,   142,   143,
     144,   145,   146,   147,   148,   149,   150,   151,   152,   153,
     154,   155,   156,   157,   158,   159,   160,   161,   162,   163,
     164,   165,   166,   167,   168,   169,   170,   171,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   186,   187,   188,   189,   190,   191,   192,   193,
     194,   195,   196,   197,    -1,   199,   200,   201,   202,   203,
     204,   205,   206,   207,    -1,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    12,   219,    14,    -1,   222,   223,
      -1,    -1,    -1,   227,    22,   229,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   238,    -1,    -1,    -1,    -1,    -1,
      38,    -1,    -1,    41,    42,    -1,    -1,    -1,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      68,    69,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    90,    91,    92,    93,    94,    95,    96,    97,
      98,    99,   100,   101,   102,   103,   104,   105,   106,   107,
     108,   109,   110,   111,   112,   113,   114,   115,   116,   117,
     118,   119,   120,   121,    -1,    -1,   124,   125,   126,   127,
     128,   129,    -1,    -1,    -1,    -1,    -1,   135,   136,   137,
     138,   139,   140,   141,   142,   143,   144,   145,   146,   147,
     148,   149,   150,   151,   152,   153,   154,   155,   156,   157,
     158,   159,   160,   161,   162,   163,   164,   165,   166,   167,
     168,   169,   170,   171,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   186,   187,
     188,   189,   190,   191,   192,   193,   194,   195,   196,   197,
      -1,   199,   200,   201,   202,   203,   204,   205,   206,   207,
      -1,     3,     4,     5,     6,     7,     8,     9,    10,    11,
      12,   219,    14,    -1,   222,   223,    -1,    -1,    -1,   227,
      22,   229,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     238,    -1,    -1,    -1,    -1,    -1,    38,    -1,    -1,    41,
      42,    -1,    -1,    -1,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    68,    69,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    89,    90,    91,
      92,    93,    94,    95,    96,    97,    98,    99,   100,   101,
     102,   103,   104,   105,   106,   107,   108,   109,   110,   111,
     112,   113,   114,   115,   116,   117,   118,   119,   120,   121,
      -1,    -1,   124,   125,   126,   127,   128,   129,    -1,    -1,
      -1,    -1,    -1,   135,   136,   137,   138,   139,   140,   141,
     142,   143,   144,   145,   146,   147,   148,   149,   150,   151,
     152,   153,   154,   155,   156,   157,   158,   159,   160,   161,
     162,   163,   164,   165,   166,   167,   168,   169,   170,   171,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   186,   187,   188,   189,   190,   191,
     192,   193,   194,   195,   196,   197,    -1,   199,   200,   201,
     202,   203,   204,   205,   206,   207,    -1,     3,     4,     5,
       6,     7,     8,     9,    10,    11,    12,   219,    14,    -1,
     222,   223,    -1,    -1,    -1,   227,    22,   229,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   238,    -1,    -1,    -1,
      -1,    -1,    38,    -1,    -1,    41,    42,    -1,    -1,    -1,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    68,    69,    70,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    90,    91,    92,    93,    94,    95,
      96,    97,    98,    99,   100,   101,   102,   103,   104,   105,
     106,   107,   108,   109,   110,   111,   112,   113,   114,   115,
     116,   117,   118,   119,   120,   121,    -1,    -1,   124,   125,
     126,   127,   128,   129,    -1,    -1,    -1,    -1,    -1,   135,
     136,   137,   138,   139,   140,   141,   142,   143,   144,   145,
     146,   147,   148,   149,   150,   151,   152,   153,   154,   155,
     156,   157,   158,   159,   160,   161,   162,   163,   164,   165,
     166,   167,   168,   169,   170,   171,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     186,   187,   188,   189,   190,   191,   192,   193,   194,   195,
     196,   197,    -1,   199,   200,   201,   202,   203,   204,   205,
     206,   207,    -1,     3,     4,     5,     6,     7,     8,     9,
      10,    11,    12,   219,    14,    -1,   222,   223,    -1,    -1,
      -1,   227,    22,   229,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   238,    -1,    -1,    -1,    -1,    -1,    38,    -1,
      -1,    41,    42,    -1,    -1,    -1,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    68,    69,
      70,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    91,    92,    93,    94,    95,    96,    97,    98,    99,
     100,   101,   102,   103,   104,   105,   106,   107,   108,   109,
     110,   111,   112,   113,   114,   115,   116,   117,   118,   119,
     120,   121,    -1,    -1,   124,   125,   126,   127,   128,   129,
      -1,    -1,    -1,    -1,    -1,   135,   136,   137,   138,   139,
     140,   141,   142,   143,   144,   145,   146,   147,   148,   149,
     150,   151,   152,   153,   154,   155,   156,   157,   158,   159,
     160,   161,   162,   163,   164,   165,   166,   167,   168,   169,
     170,   171,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   186,   187,   188,   189,
     190,   191,   192,   193,   194,   195,   196,   197,    -1,   199,
     200,   201,   202,   203,   204,   205,   206,   207,    -1,     3,
       4,     5,     6,     7,     8,     9,    10,    11,    12,   219,
      14,    -1,   222,   223,    -1,    -1,    -1,   227,    22,   229,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   238,    -1,
      -1,    -1,    -1,    -1,    38,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    68,    69,    70,    71,    72,    73,
      74,    75,    76,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    90,    91,    92,    93,
      94,    95,    96,    97,    98,    99,   100,   101,   102,   103,
     104,   105,   106,   107,   108,   109,   110,   111,   112,   113,
     114,   115,   116,   117,   118,   119,   120,   121,    -1,    -1,
     124,   125,   126,   127,   128,   129,    -1,    -1,    -1,    -1,
      -1,   135,   136,   137,   138,   139,   140,   141,   142,   143,
     144,   145,   146,   147,   148,   149,   150,   151,   152,   153,
     154,   155,   156,   157,   158,   159,   160,   161,   162,   163,
     164,   165,   166,   167,   168,   169,   170,   171,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   186,   187,   188,   189,   190,   191,   192,   193,
     194,   195,   196,   197,    -1,   199,   200,   201,   202,   203,
     204,   205,   206,   207,    -1,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    12,   219,    14,    -1,   222,   223,
      -1,    -1,    -1,   227,    22,   229,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   238,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      68,    69,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    90,    91,    92,    93,    94,    95,    96,    97,
      98,    99,   100,   101,   102,   103,   104,   105,   106,   107,
     108,   109,   110,   111,   112,   113,   114,   115,   116,   117,
     118,   119,   120,   121,    -1,    -1,   124,   125,   126,   127,
     128,   129,    -1,    -1,    -1,    -1,    -1,   135,   136,   137,
     138,   139,   140,   141,   142,   143,   144,   145,   146,   147,
     148,   149,   150,   151,   152,   153,   154,   155,   156,   157,
     158,   159,   160,   161,   162,   163,   164,   165,   166,   167,
     168,   169,   170,   171,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   186,   187,
     188,   189,   190,   191,   192,   193,   194,   195,   196,   197,
      -1,   199,   200,   201,   202,   203,   204,   205,   206,   207,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   219,    -1,    -1,   222,   223,    -1,    -1,    -1,   227,
      -1,   229,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     238
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int16 yystos[] =
{
       0,     1,     3,     4,     5,     6,     7,     8,     9,    10,
      11,    12,    14,    20,    22,    38,    41,    42,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      68,    69,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    90,    91,    92,    93,    94,    95,    96,    97,
      98,    99,   100,   101,   102,   103,   104,   105,   106,   107,
     108,   109,   110,   111,   112,   113,   114,   115,   116,   117,
     118,   119,   120,   121,   122,   124,   125,   126,   127,   128,
     129,   135,   136,   137,   138,   139,   140,   141,   142,   143,
     144,   145,   146,   147,   148,   149,   150,   151,   152,   153,
     154,   155,   156,   157,   158,   159,   160,   161,   162,   163,
     164,   165,   166,   167,   168,   169,   170,   171,   186,   187,
     188,   189,   190,   191,   192,   193,   194,   195,   196,   197,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   219,
     222,   223,   227,   229,   238,   243,   244,   265,   266,   267,
     268,   269,   270,   271,   272,   273,   276,   277,   279,   280,
     281,   283,    12,   265,    31,    40,   265,   268,   265,   272,
     270,   270,    12,    12,    12,    12,    12,    12,    12,    12,
      12,    12,    12,    12,    12,    12,    12,    12,    12,    12,
      12,    12,    12,    12,    12,    12,    12,    12,    12,    12,
      12,    12,    12,    12,    12,    12,    12,    12,    12,    12,
      12,    12,    12,    16,   282,   282,   282,   282,   282,   282,
      12,   282,   282,   282,   282,    12,   282,   282,   282,   282,
     282,   282,   265,   266,    12,    12,    12,    12,    12,    12,
      12,    12,    12,    12,    12,    12,    12,    12,    12,    12,
      12,    12,    12,    12,    12,    12,    12,    12,    12,    12,
      12,    12,    12,    12,    12,    12,    12,    12,    12,    12,
      12,    12,    12,    12,    12,    12,    12,    12,    12,    12,
      12,    12,    12,    12,    12,    12,    12,    12,    12,    12,
      12,    12,    29,   262,   264,    12,    12,    12,    12,   254,
       0,    21,    39,    40,    18,    23,    27,    37,   212,    32,
      33,    36,    41,    42,   272,    43,    44,    14,    29,    35,
      45,    13,   261,   265,    13,    31,   265,   278,    15,    15,
      19,    21,    24,    25,    26,   265,   265,   265,   265,   265,
     265,   265,   265,   265,   265,   265,   265,   265,   265,   265,
     265,   265,   265,   265,   265,   265,   265,   265,   265,   265,
     265,   265,   265,   265,   265,   265,   265,   265,   265,   265,
     265,   265,   265,   265,   265,   265,    30,   265,    10,    87,
      88,    89,    90,    91,    92,    93,    94,    95,    96,    98,
      99,   100,   101,   102,   103,   131,   132,   172,   173,   174,
     175,   176,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   198,   208,   211,   217,   219,   221,   224,   225,   226,
     239,   241,   245,   247,   255,   256,   257,   258,   259,   260,
     261,   267,   273,   123,   265,   265,   265,   265,   265,    13,
      13,   265,   265,   265,   265,   265,   265,   265,   265,   265,
     265,   265,   265,   265,   265,   265,   265,   265,   265,   265,
     265,   265,   265,   265,   265,   265,   265,   261,   261,   265,
     265,   265,   265,   265,   265,   265,   265,   265,   265,   265,
     265,   265,   265,   265,   261,   265,   265,   265,   265,   261,
     265,   265,    10,   220,    19,    21,   263,   265,    10,   265,
      10,    13,   253,   268,   268,   269,    16,   269,    16,   269,
     269,   269,   271,   271,   271,   271,   271,    38,   270,   272,
      38,   270,   272,   265,    10,    38,   272,    38,   270,   272,
      13,    19,    12,    15,    19,    28,    31,   265,   265,    13,
      13,    13,    13,    13,    13,    13,    13,    13,    13,    13,
      13,    13,    13,    13,    13,    13,    13,    13,    13,    13,
      13,    13,    13,    13,    13,    13,    13,    13,    13,    13,
      13,    13,    13,    13,    13,    13,    13,    13,    13,    13,
      13,    16,    17,    16,    16,    16,    16,    16,    16,    16,
      16,    16,    16,    16,    16,    16,    16,    16,    16,    12,
      12,    12,    12,    12,    12,    12,    12,    12,    12,    12,
      12,    12,    12,    12,   248,   265,    10,   249,   265,    12,
      12,    12,    10,    12,   218,   220,   237,   246,   247,   250,
     251,   252,    13,    20,    16,    17,    20,    16,    17,    29,
     265,   274,   275,    13,    13,    19,    19,    13,    19,    19,
      13,    13,    13,    19,    19,    19,    19,    13,    13,    13,
      19,    19,    19,    19,    19,    19,    19,    19,    19,    19,
      13,    13,    13,    13,    13,    13,    13,    13,    13,    19,
      19,    19,    19,    19,    19,    19,    19,    19,    19,    19,
      19,    19,    13,    19,    19,    19,    19,    13,    19,    19,
      16,   262,    13,    13,    13,    19,    16,    19,   219,   245,
      13,   269,   269,   272,   272,   272,   272,    15,    12,   272,
     272,   272,   261,    13,   261,    28,   265,    31,    15,    15,
      15,   133,   134,   265,   265,   265,   265,   265,   265,   265,
     265,   265,   265,   265,   265,   265,   265,   265,   265,   265,
     265,   261,   265,   265,   265,   265,   265,   261,   261,   265,
     265,   265,   261,   265,    10,    48,   265,   209,   212,   213,
     216,   265,    10,    10,   254,    13,   265,    10,   253,    21,
     246,   246,   250,    21,   265,   265,   265,   265,    10,    34,
     274,   265,   265,   265,   265,   265,   265,   265,   265,   265,
     265,   265,   265,   265,   265,   265,   265,   265,   265,    10,
     261,   265,   265,   265,   265,   265,   265,   265,   265,   265,
     265,   265,   261,   265,   265,   265,   265,   265,   265,   265,
      28,   253,   240,   246,   250,   251,   245,    13,   261,    13,
      19,    15,    12,    12,    13,    13,    19,    13,    13,    13,
      13,    13,    13,    13,    19,    13,    19,    19,    19,    19,
     247,   265,   265,   247,    13,    19,    19,    13,   250,   246,
     251,    12,   245,    19,    19,    13,    19,    19,    19,    19,
      19,    13,    13,    13,    13,    13,    13,    13,    19,    19,
      13,    19,    13,    19,    13,    13,    13,    13,    13,    13,
      13,    13,    13,    19,    13,    19,    13,    13,    19,    13,
      13,    13,   265,   240,   246,   240,   246,   250,   240,   246,
     250,   251,    13,   265,   265,   265,    27,    27,   261,   265,
      27,   265,    10,    48,    10,    48,   265,   210,   216,   214,
     265,   265,   265,   240,   246,   250,   251,   261,   265,   265,
     265,   261,   265,   265,   261,   265,   265,   265,   265,   265,
     261,   245,    21,   265,   265,   240,   246,   265,   240,   246,
     240,   246,   250,    13,    13,    27,   265,    27,   265,    13,
      19,    27,   265,    13,    13,    13,    13,    13,    19,   247,
     247,   265,    19,    13,    13,   265,   240,   246,   240,   246,
     250,    13,    19,    19,    13,    13,    13,    13,    13,    13,
      13,    19,    19,    13,    13,   240,   246,   250,   251,   246,
      21,    21,   265,    21,   265,   265,   240,   246,   265,   265,
     265,   265,   265,   215,   216,    12,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   284,   285,   287,    21,   265,
     265,   240,   246,   261,   261,   265,   265,   265,   240,   246,
     240,   246,   250,   246,   246,    21,   246,    21,    21,   265,
      19,    19,   265,   247,   284,   286,   236,    42,   246,    21,
      21,   265,    13,    13,    19,    19,    21,   265,   265,   240,
     246,   246,   246,   246,    21,   265,   265,   216,    19,    13,
     228,   229,   230,   231,   232,   233,   234,    27,   246,   246,
      21,   265,   265,   246,    21,    21,   265,   246,    19,    19,
     247,   286,   285,   246,    13,    19,   246,   246,    21,   261,
     261,    13,   261,   246,    13,    13,    13
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int16 yyr1[] =
{
       0,   242,   243,   244,   244,   244,   245,   245,   246,   246,
     247,   247,   247,   247,   247,   247,   247,   247,   248,   248,
     249,   249,   249,   250,   250,   251,   251,   252,   253,   253,
     254,   254,   254,   254,   254,   254,   254,   254,   254,   254,
     254,   254,   254,   254,   254,   254,   254,   254,   254,   254,
     254,   254,   254,   254,   255,   255,   255,   255,   255,   255,
     255,   255,   255,   255,   255,   255,   255,   255,   255,   255,
     255,   255,   255,   255,   255,   255,   255,   255,   255,   255,
     255,   255,   255,   255,   255,   255,   255,   255,   255,   256,
     256,   256,   256,   257,   257,   257,   257,   257,   257,   257,
     257,   258,   259,   259,   259,   259,   259,   259,   259,   259,
     259,   259,   259,   259,   259,   259,   259,   259,   260,   260,
     260,   260,   260,   260,   260,   260,   260,   260,   260,   260,
     260,   260,   260,   260,   261,   261,   262,   262,   263,   263,
     264,   265,   265,   266,   266,   266,   266,   267,   268,   268,
     268,   268,   268,   268,   268,   268,   269,   269,   269,   269,
     269,   269,   270,   270,   270,   270,   271,   271,   271,   271,
     271,   271,   271,   271,   271,   272,   272,   272,   272,   272,
     272,   273,   273,   273,   273,   273,   273,   273,   273,   273,
     273,   273,   273,   273,   273,   273,   273,   273,   273,   273,
     273,   273,   273,   273,   273,   273,   273,   273,   273,   273,
     273,   273,   273,   273,   273,   273,   273,   273,   273,   273,
     273,   273,   273,   273,   273,   273,   273,   273,   273,   273,
     273,   273,   273,   273,   273,   274,   274,   275,   275,   275,
     275,   275,   275,   275,   275,   275,   276,   276,   276,   276,
     276,   276,   276,   277,   277,   277,   277,   278,   278,   278,
     279,   279,   279,   280,   280,   280,   280,   280,   280,   281,
     281,   281,   281,   281,   281,   281,   281,   281,   281,   281,
     281,   281,   281,   281,   281,   281,   281,   281,   281,   281,
     281,   281,   281,   281,   281,   281,   281,   281,   281,   281,
     281,   281,   281,   281,   281,   281,   281,   281,   281,   281,
     281,   281,   281,   281,   281,   281,   281,   281,   281,   281,
     281,   281,   281,   281,   281,   281,   281,   281,   281,   281,
     281,   281,   281,   281,   281,   281,   281,   281,   281,   281,
     281,   281,   281,   281,   281,   281,   281,   281,   281,   281,
     281,   281,   281,   281,   281,   281,   281,   281,   281,   281,
     281,   281,   281,   281,   281,   281,   281,   281,   281,   281,
     282,   282,   283,   283,   283,   283,   283,   283,   283,   283,
     283,   283,   283,   283,   283,   283,   283,   283,   284,   284,
     284,   284,   284,   284,   284,   284,   284,   284,   284,   284,
     284,   284,   285,   285,   286,   286,   287,   287
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     1,     2,     1,     1,     1,     1,     1,
       1,     3,     4,     3,     2,     2,     4,     2,     3,     5,
       7,     9,     5,     2,     3,     2,     3,     2,     1,     3,
       5,     6,     5,     4,     8,     9,     8,     7,     6,     7,
       6,     5,     9,    10,     9,     8,     8,     9,     8,     7,
      11,    12,    11,    10,     1,     1,     1,     4,     3,     4,
       6,     7,     6,     4,     4,     4,     4,     4,     4,     4,
      12,     4,     6,     7,     6,     4,     4,     6,     7,    12,
       6,     6,     6,     6,    11,     6,     1,     1,     3,     1,
       2,     1,     2,     3,     3,     6,     6,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     1,     3,     1,     3,     1,     1,
       4,     1,     4,     1,     3,     3,     2,     4,     1,     3,
       3,     3,     3,     4,     4,     3,     1,     3,     3,     3,
       3,     3,     1,     1,     2,     2,     1,     2,     2,     3,
       3,     4,     4,     4,     4,     1,     3,     4,     4,     3,
       4,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     4,     4,     3,
       1,     1,     1,     1,     3,     3,     1,     1,     3,     5,
       6,     6,     5,     2,     4,     1,     2,     9,     6,     8,
       5,     8,     5,     7,     4,     5,     1,     1,     1,     1,
       1,     1,     1,     4,     3,     5,     6,     1,     3,     5,
       5,     5,     3,     3,     3,     3,     4,     4,     4,     4,
       4,     3,     3,     6,     4,     8,    10,     8,     4,     4,
      10,     4,     4,     4,     4,     8,     8,     8,     8,     4,
       4,     4,     6,     6,     6,     6,     6,     6,     6,     8,
       8,     6,     4,     4,     6,    12,     6,     6,     6,     6,
       6,     6,     6,     6,     6,    14,     4,     6,     8,     6,
       6,     4,     8,     6,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     6,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       2,     0,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     1,     1,
       1,     1,     1,     1,     1,     3,     3,     3,     3,     3,
       3,     3,     1,     1,     1,     3,     1,     3
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (myScanner, YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value, myScanner); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep, void *myScanner)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  YY_USE (myScanner);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep, void *myScanner)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep, myScanner);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule, void *myScanner)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)], myScanner);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule, myScanner); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep, void *myScanner)
{
  YY_USE (yyvaluep);
  YY_USE (myScanner);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}






/*----------.
| yyparse.  |
`----------*/

int
yyparse (void *myScanner)
{
/* Lookahead token kind.  */
int yychar;


/* The semantic value of the lookahead symbol.  */
/* Default value used for initialization, for pacifying older GCCs
   or non-GCC compilers.  */
YY_INITIAL_VALUE (static YYSTYPE yyval_default;)
YYSTYPE yylval YY_INITIAL_VALUE (= yyval_default);

    /* Number of syntax errors so far.  */
    int yynerrs = 0;

    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */

  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */


  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex (&yylval, myScanner);
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 2: /* startsymbol: startsymbolwitherr  */
#line 444 "miniparser.y"
                          {
			    minitree = (yyvsp[0].tree);
			    (yyval.other) = NULL;
			    YYACCEPT;
			  }
#line 4222 "miniparser.c"
    break;

  case 3: /* startsymbolwitherr: thing  */
#line 453 "miniparser.y"
                          {
			    (yyval.tree) = (yyvsp[0].tree);
			  }
#line 4230 "miniparser.c"
    break;

  case 4: /* startsymbolwitherr: thing ";"  */
#line 457 "miniparser.y"
                          {
                            miniparserSemicolonAtEnd = 1;
			    (yyval.tree) = (yyvsp[-1].tree);
			  }
#line 4239 "miniparser.c"
    break;

  case 5: /* startsymbolwitherr: error  */
#line 462 "miniparser.y"
                          {
			    (yyval.tree) = NULL;
			  }
#line 4247 "miniparser.c"
    break;

  case 6: /* beginsymbol: "begin"  */
#line 468 "miniparser.y"
                          {
			    (yyval.other) = NULL;
			  }
#line 4255 "miniparser.c"
    break;

  case 7: /* beginsymbol: "{"  */
#line 472 "miniparser.y"
                          {
			    (yyval.other) = NULL;
			  }
#line 4263 "miniparser.c"
    break;

  case 8: /* endsymbol: "end"  */
#line 478 "miniparser.y"
                          {
			    (yyval.other) = NULL;
			  }
#line 4271 "miniparser.c"
    break;

  case 9: /* endsymbol: "}"  */
#line 482 "miniparser.y"
                          {
			    (yyval.other) = NULL;
			  }
#line 4279 "miniparser.c"
    break;

  case 10: /* command: simplecommand  */
#line 488 "miniparser.y"
                          {
			    (yyval.tree) = (yyvsp[0].tree);
			  }
#line 4287 "miniparser.c"
    break;

  case 11: /* command: beginsymbol commandlist endsymbol  */
#line 492 "miniparser.y"
                          {
			    (yyval.tree) = makeCommandList((yyvsp[-1].list));
                          }
#line 4295 "miniparser.c"
    break;

  case 12: /* command: beginsymbol variabledeclarationlist commandlist endsymbol  */
#line 496 "miniparser.y"
                          {
			    (yyval.tree) = makeCommandList(concatChains((yyvsp[-2].list), (yyvsp[-1].list)));
                          }
#line 4303 "miniparser.c"
    break;

  case 13: /* command: beginsymbol variabledeclarationlist endsymbol  */
#line 500 "miniparser.y"
                          {
			    (yyval.tree) = makeCommandList((yyvsp[-1].list));
                          }
#line 4311 "miniparser.c"
    break;

  case 14: /* command: beginsymbol endsymbol  */
#line 504 "miniparser.y"
                          {
			    (yyval.tree) = makeNop();
                          }
#line 4319 "miniparser.c"
    break;

  case 15: /* command: "if" ifcommand  */
#line 508 "miniparser.y"
                          {
			    (yyval.tree) = (yyvsp[0].tree);
			  }
#line 4327 "miniparser.c"
    break;

  case 16: /* command: "while" thing "do" command  */
#line 512 "miniparser.y"
                          {
			    (yyval.tree) = makeWhile((yyvsp[-2].tree), (yyvsp[0].tree));
			  }
#line 4335 "miniparser.c"
    break;

  case 17: /* command: "for" forcommand  */
#line 516 "miniparser.y"
                          {
			    (yyval.tree) = (yyvsp[0].tree);
			  }
#line 4343 "miniparser.c"
    break;

  case 18: /* ifcommand: thing "then" command  */
#line 522 "miniparser.y"
                          {
			    (yyval.tree) = makeIf((yyvsp[-2].tree), (yyvsp[0].tree));
                          }
#line 4351 "miniparser.c"
    break;

  case 19: /* ifcommand: thing "then" command "else" command  */
#line 526 "miniparser.y"
                          {
			    (yyval.tree) = makeIfElse((yyvsp[-4].tree),(yyvsp[-2].tree),(yyvsp[0].tree));
                          }
#line 4359 "miniparser.c"
    break;

  case 20: /* forcommand: "identifier" "from" thing "to" thing "do" command  */
#line 534 "miniparser.y"
                          {
			    (yyval.tree) = makeFor((yyvsp[-6].value), (yyvsp[-4].tree), (yyvsp[-2].tree), makeConstantDouble(1.0), (yyvsp[0].tree));
			    safeFree((yyvsp[-6].value));
                          }
#line 4368 "miniparser.c"
    break;

  case 21: /* forcommand: "identifier" "from" thing "to" thing "by" thing "do" command  */
#line 539 "miniparser.y"
                          {
			    (yyval.tree) = makeFor((yyvsp[-8].value), (yyvsp[-6].tree), (yyvsp[-4].tree), (yyvsp[-2].tree), (yyvsp[0].tree));
			    safeFree((yyvsp[-8].value));
                          }
#line 4377 "miniparser.c"
    break;

  case 22: /* forcommand: "identifier" "in" thing "do" command  */
#line 544 "miniparser.y"
                          {
			    (yyval.tree) = makeForIn((yyvsp[-4].value), (yyvsp[-2].tree), (yyvsp[0].tree));
			    safeFree((yyvsp[-4].value));
                          }
#line 4386 "miniparser.c"
    break;

  case 23: /* commandlist: command ";"  */
#line 552 "miniparser.y"
                          {
			    (yyval.list) = addElement(NULL, (yyvsp[-1].tree));
			  }
#line 4394 "miniparser.c"
    break;

  case 24: /* commandlist: command ";" commandlist  */
#line 556 "miniparser.y"
                          {
			    (yyval.list) = addElement((yyvsp[0].list), (yyvsp[-2].tree));
			  }
#line 4402 "miniparser.c"
    break;

  case 25: /* variabledeclarationlist: variabledeclaration ";"  */
#line 562 "miniparser.y"
                          {
			    (yyval.list) = addElement(NULL, (yyvsp[-1].tree));
			  }
#line 4410 "miniparser.c"
    break;

  case 26: /* variabledeclarationlist: variabledeclaration ";" variabledeclarationlist  */
#line 566 "miniparser.y"
                          {
			    (yyval.list) = addElement((yyvsp[0].list), (yyvsp[-2].tree));
			  }
#line 4418 "miniparser.c"
    break;

  case 27: /* variabledeclaration: "var" identifierlist  */
#line 572 "miniparser.y"
                          {
			    (yyval.tree) = makeVariableDeclaration((yyvsp[0].list));
			  }
#line 4426 "miniparser.c"
    break;

  case 28: /* identifierlist: "identifier"  */
#line 579 "miniparser.y"
                          {
			    (yyval.list) = addElement(NULL, (yyvsp[0].value));
			  }
#line 4434 "miniparser.c"
    break;

  case 29: /* identifierlist: "identifier" "," identifierlist  */
#line 583 "miniparser.y"
                          {
			    (yyval.list) = addElement((yyvsp[0].list), (yyvsp[-2].value));
			  }
#line 4442 "miniparser.c"
    break;

  case 30: /* procbody: "(" ")" beginsymbol commandlist endsymbol  */
#line 589 "miniparser.y"
                          {
			    (yyval.tree) = makeProc(NULL, makeCommandList((yyvsp[-1].list)), makeUnit());
                          }
#line 4450 "miniparser.c"
    break;

  case 31: /* procbody: "(" ")" beginsymbol variabledeclarationlist commandlist endsymbol  */
#line 593 "miniparser.y"
                          {
			    (yyval.tree) = makeProc(NULL, makeCommandList(concatChains((yyvsp[-2].list), (yyvsp[-1].list))), makeUnit());
                          }
#line 4458 "miniparser.c"
    break;

  case 32: /* procbody: "(" ")" beginsymbol variabledeclarationlist endsymbol  */
#line 597 "miniparser.y"
                          {
			    (yyval.tree) = makeProc(NULL, makeCommandList((yyvsp[-1].list)), makeUnit());
                          }
#line 4466 "miniparser.c"
    break;

  case 33: /* procbody: "(" ")" beginsymbol endsymbol  */
#line 601 "miniparser.y"
                          {
			    (yyval.tree) = makeProc(NULL, makeCommandList(addElement(NULL,makeNop())), makeUnit());
                          }
#line 4474 "miniparser.c"
    break;

  case 34: /* procbody: "(" ")" beginsymbol commandlist "return" thing ";" endsymbol  */
#line 605 "miniparser.y"
                          {
			    (yyval.tree) = makeProc(NULL, makeCommandList((yyvsp[-4].list)), (yyvsp[-2].tree));
                          }
#line 4482 "miniparser.c"
    break;

  case 35: /* procbody: "(" ")" beginsymbol variabledeclarationlist commandlist "return" thing ";" endsymbol  */
#line 609 "miniparser.y"
                          {
			    (yyval.tree) = makeProc(NULL, makeCommandList(concatChains((yyvsp[-5].list), (yyvsp[-4].list))), (yyvsp[-2].tree));
                          }
#line 4490 "miniparser.c"
    break;

  case 36: /* procbody: "(" ")" beginsymbol variabledeclarationlist "return" thing ";" endsymbol  */
#line 613 "miniparser.y"
                          {
			    (yyval.tree) = makeProc(NULL, makeCommandList((yyvsp[-4].list)), (yyvsp[-2].tree));
                          }
#line 4498 "miniparser.c"
    break;

  case 37: /* procbody: "(" ")" beginsymbol "return" thing ";" endsymbol  */
#line 617 "miniparser.y"
                          {
			    (yyval.tree) = makeProc(NULL, makeCommandList(addElement(NULL,makeNop())), (yyvsp[-2].tree));
                          }
#line 4506 "miniparser.c"
    break;

  case 38: /* procbody: "(" identifierlist ")" beginsymbol commandlist endsymbol  */
#line 621 "miniparser.y"
                          {
			    (yyval.tree) = makeProc((yyvsp[-4].list), makeCommandList((yyvsp[-1].list)), makeUnit());
                          }
#line 4514 "miniparser.c"
    break;

  case 39: /* procbody: "(" identifierlist ")" beginsymbol variabledeclarationlist commandlist endsymbol  */
#line 625 "miniparser.y"
                          {
			    (yyval.tree) = makeProc((yyvsp[-5].list), makeCommandList(concatChains((yyvsp[-2].list), (yyvsp[-1].list))), makeUnit());
                          }
#line 4522 "miniparser.c"
    break;

  case 40: /* procbody: "(" identifierlist ")" beginsymbol variabledeclarationlist endsymbol  */
#line 629 "miniparser.y"
                          {
			    (yyval.tree) = makeProc((yyvsp[-4].list), makeCommandList((yyvsp[-1].list)), makeUnit());
                          }
#line 4530 "miniparser.c"
    break;

  case 41: /* procbody: "(" identifierlist ")" beginsymbol endsymbol  */
#line 633 "miniparser.y"
                          {
			    (yyval.tree) = makeProc((yyvsp[-3].list), makeCommandList(addElement(NULL,makeNop())), makeUnit());
                          }
#line 4538 "miniparser.c"
    break;

  case 42: /* procbody: "(" identifierlist ")" beginsymbol commandlist "return" thing ";" endsymbol  */
#line 637 "miniparser.y"
                          {
			    (yyval.tree) = makeProc((yyvsp[-7].list), makeCommandList((yyvsp[-4].list)), (yyvsp[-2].tree));
                          }
#line 4546 "miniparser.c"
    break;

  case 43: /* procbody: "(" identifierlist ")" beginsymbol variabledeclarationlist commandlist "return" thing ";" endsymbol  */
#line 641 "miniparser.y"
                          {
			    (yyval.tree) = makeProc((yyvsp[-8].list), makeCommandList(concatChains((yyvsp[-5].list), (yyvsp[-4].list))), (yyvsp[-2].tree));
                          }
#line 4554 "miniparser.c"
    break;

  case 44: /* procbody: "(" identifierlist ")" beginsymbol variabledeclarationlist "return" thing ";" endsymbol  */
#line 645 "miniparser.y"
                          {
			    (yyval.tree) = makeProc((yyvsp[-7].list), makeCommandList((yyvsp[-4].list)), (yyvsp[-2].tree));
                          }
#line 4562 "miniparser.c"
    break;

  case 45: /* procbody: "(" identifierlist ")" beginsymbol "return" thing ";" endsymbol  */
#line 649 "miniparser.y"
                          {
			    (yyval.tree) = makeProc((yyvsp[-6].list), makeCommandList(addElement(NULL, makeNop())), (yyvsp[-2].tree));
                          }
#line 4570 "miniparser.c"
    break;

  case 46: /* procbody: "(" "identifier" "=" "..." ")" beginsymbol commandlist endsymbol  */
#line 653 "miniparser.y"
                          {
			    (yyval.tree) = makeProcIllim((yyvsp[-6].value), makeCommandList((yyvsp[-1].list)), makeUnit());
                          }
#line 4578 "miniparser.c"
    break;

  case 47: /* procbody: "(" "identifier" "=" "..." ")" beginsymbol variabledeclarationlist commandlist endsymbol  */
#line 657 "miniparser.y"
                          {
			    (yyval.tree) = makeProcIllim((yyvsp[-7].value), makeCommandList(concatChains((yyvsp[-2].list), (yyvsp[-1].list))), makeUnit());
                          }
#line 4586 "miniparser.c"
    break;

  case 48: /* procbody: "(" "identifier" "=" "..." ")" beginsymbol variabledeclarationlist endsymbol  */
#line 661 "miniparser.y"
                          {
			    (yyval.tree) = makeProcIllim((yyvsp[-6].value), makeCommandList((yyvsp[-1].list)), makeUnit());
                          }
#line 4594 "miniparser.c"
    break;

  case 49: /* procbody: "(" "identifier" "=" "..." ")" beginsymbol endsymbol  */
#line 665 "miniparser.y"
                          {
			    (yyval.tree) = makeProcIllim((yyvsp[-5].value), makeCommandList(addElement(NULL,makeNop())), makeUnit());
                          }
#line 4602 "miniparser.c"
    break;

  case 50: /* procbody: "(" "identifier" "=" "..." ")" beginsymbol commandlist "return" thing ";" endsymbol  */
#line 669 "miniparser.y"
                          {
			    (yyval.tree) = makeProcIllim((yyvsp[-9].value), makeCommandList((yyvsp[-4].list)), (yyvsp[-2].tree));
                          }
#line 4610 "miniparser.c"
    break;

  case 51: /* procbody: "(" "identifier" "=" "..." ")" beginsymbol variabledeclarationlist commandlist "return" thing ";" endsymbol  */
#line 673 "miniparser.y"
                          {
			    (yyval.tree) = makeProcIllim((yyvsp[-10].value), makeCommandList(concatChains((yyvsp[-5].list), (yyvsp[-4].list))), (yyvsp[-2].tree));
                          }
#line 4618 "miniparser.c"
    break;

  case 52: /* procbody: "(" "identifier" "=" "..." ")" beginsymbol variabledeclarationlist "return" thing ";" endsymbol  */
#line 677 "miniparser.y"
                          {
			    (yyval.tree) = makeProcIllim((yyvsp[-9].value), makeCommandList((yyvsp[-4].list)), (yyvsp[-2].tree));
                          }
#line 4626 "miniparser.c"
    break;

  case 53: /* procbody: "(" "identifier" "=" "..." ")" beginsymbol "return" thing ";" endsymbol  */
#line 681 "miniparser.y"
                          {
			    (yyval.tree) = makeProcIllim((yyvsp[-8].value), makeCommandList(addElement(NULL, makeNop())), (yyvsp[-2].tree));
                          }
#line 4634 "miniparser.c"
    break;

  case 54: /* simplecommand: "quit in an included file"  */
#line 689 "miniparser.y"
                          {
			    (yyval.tree) = makeQuit();
			  }
#line 4642 "miniparser.c"
    break;

  case 55: /* simplecommand: "restart"  */
#line 693 "miniparser.y"
                          {
			    (yyval.tree) = makeFalseRestart();
			  }
#line 4650 "miniparser.c"
    break;

  case 56: /* simplecommand: "nop"  */
#line 697 "miniparser.y"
                          {
			    (yyval.tree) = makeNop();
			  }
#line 4658 "miniparser.c"
    break;

  case 57: /* simplecommand: "nop" "(" thing ")"  */
#line 701 "miniparser.y"
                          {
			    (yyval.tree) = makeNopArg((yyvsp[-1].tree));
			  }
#line 4666 "miniparser.c"
    break;

  case 58: /* simplecommand: "nop" "(" ")"  */
#line 705 "miniparser.y"
                          {
			    (yyval.tree) = makeNopArg(makeDefault());
			  }
#line 4674 "miniparser.c"
    break;

  case 59: /* simplecommand: "print" "(" thinglist ")"  */
#line 709 "miniparser.y"
                          {
			    (yyval.tree) = makePrint((yyvsp[-1].list));
			  }
#line 4682 "miniparser.c"
    break;

  case 60: /* simplecommand: "print" "(" thinglist ")" ">" thing  */
#line 713 "miniparser.y"
                          {
			    (yyval.tree) = makeNewFilePrint((yyvsp[0].tree), (yyvsp[-3].list));
			  }
#line 4690 "miniparser.c"
    break;

  case 61: /* simplecommand: "print" "(" thinglist ")" ">" ">" thing  */
#line 717 "miniparser.y"
                          {
			    (yyval.tree) = makeAppendFilePrint((yyvsp[0].tree), (yyvsp[-4].list));
			  }
#line 4698 "miniparser.c"
    break;

  case 62: /* simplecommand: "plot" "(" thing "," thinglist ")"  */
#line 721 "miniparser.y"
                          {
			    (yyval.tree) = makePlot(addElement((yyvsp[-1].list), (yyvsp[-3].tree)));
			  }
#line 4706 "miniparser.c"
    break;

  case 63: /* simplecommand: "printhexa" "(" thing ")"  */
#line 725 "miniparser.y"
                          {
			    (yyval.tree) = makePrintHexa((yyvsp[-1].tree));
			  }
#line 4714 "miniparser.c"
    break;

  case 64: /* simplecommand: "printfloat" "(" thing ")"  */
#line 729 "miniparser.y"
                          {
			    (yyval.tree) = makePrintFloat((yyvsp[-1].tree));
			  }
#line 4722 "miniparser.c"
    break;

  case 65: /* simplecommand: "printbinary" "(" thing ")"  */
#line 733 "miniparser.y"
                          {
			    (yyval.tree) = makePrintBinary((yyvsp[-1].tree));
			  }
#line 4730 "miniparser.c"
    break;

  case 66: /* simplecommand: "suppressmessage" "(" thinglist ")"  */
#line 737 "miniparser.y"
                          {
			    (yyval.tree) = makeSuppressMessage((yyvsp[-1].list));
			  }
#line 4738 "miniparser.c"
    break;

  case 67: /* simplecommand: "unsuppressmessage" "(" thinglist ")"  */
#line 741 "miniparser.y"
                          {
			    (yyval.tree) = makeUnsuppressMessage((yyvsp[-1].list));
			  }
#line 4746 "miniparser.c"
    break;

  case 68: /* simplecommand: "printexpansion" "(" thing ")"  */
#line 745 "miniparser.y"
                          {
			    (yyval.tree) = makePrintExpansion((yyvsp[-1].tree));
			  }
#line 4754 "miniparser.c"
    break;

  case 69: /* simplecommand: "bashexecute" "(" thing ")"  */
#line 749 "miniparser.y"
                          {
			    (yyval.tree) = makeBashExecute((yyvsp[-1].tree));
			  }
#line 4762 "miniparser.c"
    break;

  case 70: /* simplecommand: "externalplot" "(" thing "," thing "," thing "," thing "," thinglist ")"  */
#line 753 "miniparser.y"
                          {
			    (yyval.tree) = makeExternalPlot(addElement(addElement(addElement(addElement((yyvsp[-1].list),(yyvsp[-3].tree)),(yyvsp[-5].tree)),(yyvsp[-7].tree)),(yyvsp[-9].tree)));
			  }
#line 4770 "miniparser.c"
    break;

  case 71: /* simplecommand: "write" "(" thinglist ")"  */
#line 757 "miniparser.y"
                          {
			    (yyval.tree) = makeWrite((yyvsp[-1].list));
			  }
#line 4778 "miniparser.c"
    break;

  case 72: /* simplecommand: "write" "(" thinglist ")" ">" thing  */
#line 761 "miniparser.y"
                          {
			    (yyval.tree) = makeNewFileWrite((yyvsp[0].tree), (yyvsp[-3].list));
			  }
#line 4786 "miniparser.c"
    break;

  case 73: /* simplecommand: "write" "(" thinglist ")" ">" ">" thing  */
#line 765 "miniparser.y"
                          {
			    (yyval.tree) = makeAppendFileWrite((yyvsp[0].tree), (yyvsp[-4].list));
			  }
#line 4794 "miniparser.c"
    break;

  case 74: /* simplecommand: "asciiplot" "(" thing "," thing ")"  */
#line 769 "miniparser.y"
                          {
			    (yyval.tree) = makeAsciiPlot((yyvsp[-3].tree), (yyvsp[-1].tree));
			  }
#line 4802 "miniparser.c"
    break;

  case 75: /* simplecommand: "printxml" "(" thing ")"  */
#line 773 "miniparser.y"
                          {
			    (yyval.tree) = makePrintXml((yyvsp[-1].tree));
			  }
#line 4810 "miniparser.c"
    break;

  case 76: /* simplecommand: "execute" "(" thing ")"  */
#line 777 "miniparser.y"
                          {
			    (yyval.tree) = makeExecute((yyvsp[-1].tree));
			  }
#line 4818 "miniparser.c"
    break;

  case 77: /* simplecommand: "printxml" "(" thing ")" ">" thing  */
#line 781 "miniparser.y"
                          {
			    (yyval.tree) = makePrintXmlNewFile((yyvsp[-3].tree),(yyvsp[0].tree));
			  }
#line 4826 "miniparser.c"
    break;

  case 78: /* simplecommand: "printxml" "(" thing ")" ">" ">" thing  */
#line 785 "miniparser.y"
                          {
			    (yyval.tree) = makePrintXmlAppendFile((yyvsp[-4].tree),(yyvsp[0].tree));
			  }
#line 4834 "miniparser.c"
    break;

  case 79: /* simplecommand: "worstcase" "(" thing "," thing "," thing "," thing "," thinglist ")"  */
#line 789 "miniparser.y"
                          {
			    (yyval.tree) = makeWorstCase(addElement(addElement(addElement(addElement((yyvsp[-1].list), (yyvsp[-3].tree)), (yyvsp[-5].tree)), (yyvsp[-7].tree)), (yyvsp[-9].tree)));
			  }
#line 4842 "miniparser.c"
    break;

  case 80: /* simplecommand: "rename" "(" "identifier" "," "identifier" ")"  */
#line 793 "miniparser.y"
                          {
			    (yyval.tree) = makeRename((yyvsp[-3].value), (yyvsp[-1].value));
			    safeFree((yyvsp[-3].value));
			    safeFree((yyvsp[-1].value));
			  }
#line 4852 "miniparser.c"
    break;

  case 81: /* simplecommand: "rename" "(" "identifier" "," "_x_" ")"  */
#line 799 "miniparser.y"
                          {
			    (yyval.tree) = makeRename((yyvsp[-3].value), "_x_");
			    safeFree((yyvsp[-3].value));
			  }
#line 4861 "miniparser.c"
    break;

  case 82: /* simplecommand: "rename" "(" "_x_" "," "identifier" ")"  */
#line 804 "miniparser.y"
                          {
			    (yyval.tree) = makeRename("_x_", (yyvsp[-1].value));
			    safeFree((yyvsp[-1].value));
			  }
#line 4870 "miniparser.c"
    break;

  case 83: /* simplecommand: "rename" "(" "_x_" "," "_x_" ")"  */
#line 809 "miniparser.y"
                          {
			    (yyval.tree) = makeRename("_x_", "_x_");
			  }
#line 4878 "miniparser.c"
    break;

  case 84: /* simplecommand: "externalproc" "(" "identifier" "," thing "," externalproctypelist "-" ">" extendedexternalproctype ")"  */
#line 813 "miniparser.y"
                          {
			    (yyval.tree) = makeExternalProc((yyvsp[-8].value), (yyvsp[-6].tree), addElement((yyvsp[-4].list), (yyvsp[-1].integerval)));
			    safeFree((yyvsp[-8].value));
			  }
#line 4887 "miniparser.c"
    break;

  case 85: /* simplecommand: "externaldata" "(" "identifier" "," thing ")"  */
#line 818 "miniparser.y"
                          {
			    (yyval.tree) = makeExternalData((yyvsp[-3].value), (yyvsp[-1].tree));
			    safeFree((yyvsp[-3].value));
			  }
#line 4896 "miniparser.c"
    break;

  case 86: /* simplecommand: assignment  */
#line 823 "miniparser.y"
                          {
			    (yyval.tree) = (yyvsp[0].tree);
			  }
#line 4904 "miniparser.c"
    break;

  case 87: /* simplecommand: thinglist  */
#line 827 "miniparser.y"
                          {
			    (yyval.tree) = makeAutoprint((yyvsp[0].list));
			  }
#line 4912 "miniparser.c"
    break;

  case 88: /* simplecommand: "procedure" "identifier" procbody  */
#line 831 "miniparser.y"
                          {
			    (yyval.tree) = makeAssignment((yyvsp[-1].value), (yyvsp[0].tree));
			    safeFree((yyvsp[-1].value));
			  }
#line 4921 "miniparser.c"
    break;

  case 89: /* assignment: stateassignment  */
#line 838 "miniparser.y"
                          {
			    (yyval.tree) = (yyvsp[0].tree);
			  }
#line 4929 "miniparser.c"
    break;

  case 90: /* assignment: stillstateassignment "!"  */
#line 842 "miniparser.y"
                          {
			    (yyval.tree) = (yyvsp[-1].tree);
			  }
#line 4937 "miniparser.c"
    break;

  case 91: /* assignment: simpleassignment  */
#line 846 "miniparser.y"
                          {
			    (yyval.tree) = (yyvsp[0].tree);
			  }
#line 4945 "miniparser.c"
    break;

  case 92: /* assignment: simpleassignment "!"  */
#line 850 "miniparser.y"
                          {
			    (yyval.tree) = (yyvsp[-1].tree);
			  }
#line 4953 "miniparser.c"
    break;

  case 93: /* simpleassignment: "identifier" "=" thing  */
#line 856 "miniparser.y"
                          {
			    (yyval.tree) = makeAssignment((yyvsp[-2].value), (yyvsp[0].tree));
			    safeFree((yyvsp[-2].value));
			  }
#line 4962 "miniparser.c"
    break;

  case 94: /* simpleassignment: "identifier" ":=" thing  */
#line 861 "miniparser.y"
                          {
			    (yyval.tree) = makeFloatAssignment((yyvsp[-2].value), (yyvsp[0].tree));
			    safeFree((yyvsp[-2].value));
			  }
#line 4971 "miniparser.c"
    break;

  case 95: /* simpleassignment: "identifier" "=" "library" "(" thing ")"  */
#line 866 "miniparser.y"
                          {
			    (yyval.tree) = makeLibraryBinding((yyvsp[-5].value), (yyvsp[-1].tree));
			    safeFree((yyvsp[-5].value));
			  }
#line 4980 "miniparser.c"
    break;

  case 96: /* simpleassignment: "identifier" "=" "libraryconstant" "(" thing ")"  */
#line 871 "miniparser.y"
                          {
			    (yyval.tree) = makeLibraryConstantBinding((yyvsp[-5].value), (yyvsp[-1].tree));
			    safeFree((yyvsp[-5].value));
			  }
#line 4989 "miniparser.c"
    break;

  case 97: /* simpleassignment: indexing "=" thing  */
#line 876 "miniparser.y"
                          {
			    (yyval.tree) = makeAssignmentInIndexing((yyvsp[-2].dblnode)->a,(yyvsp[-2].dblnode)->b,(yyvsp[0].tree));
			    safeFree((yyvsp[-2].dblnode));
			  }
#line 4998 "miniparser.c"
    break;

  case 98: /* simpleassignment: indexing ":=" thing  */
#line 881 "miniparser.y"
                          {
			    (yyval.tree) = makeFloatAssignmentInIndexing((yyvsp[-2].dblnode)->a,(yyvsp[-2].dblnode)->b,(yyvsp[0].tree));
			    safeFree((yyvsp[-2].dblnode));
			  }
#line 5007 "miniparser.c"
    break;

  case 99: /* simpleassignment: structuring "=" thing  */
#line 886 "miniparser.y"
                          {
			    (yyval.tree) = makeProtoAssignmentInStructure((yyvsp[-2].tree),(yyvsp[0].tree));
			  }
#line 5015 "miniparser.c"
    break;

  case 100: /* simpleassignment: structuring ":=" thing  */
#line 890 "miniparser.y"
                          {
			    (yyval.tree) = makeProtoFloatAssignmentInStructure((yyvsp[-2].tree),(yyvsp[0].tree));
			  }
#line 5023 "miniparser.c"
    break;

  case 101: /* structuring: basicthing "." "identifier"  */
#line 896 "miniparser.y"
                          {
			    (yyval.tree) = makeStructAccess((yyvsp[-2].tree),(yyvsp[0].value));
			    safeFree((yyvsp[0].value));
			  }
#line 5032 "miniparser.c"
    break;

  case 102: /* stateassignment: "prec" "=" thing  */
#line 903 "miniparser.y"
                          {
			    (yyval.tree) = makePrecAssign((yyvsp[0].tree));
			  }
#line 5040 "miniparser.c"
    break;

  case 103: /* stateassignment: "points" "=" thing  */
#line 907 "miniparser.y"
                          {
			    (yyval.tree) = makePointsAssign((yyvsp[0].tree));
			  }
#line 5048 "miniparser.c"
    break;

  case 104: /* stateassignment: "diam" "=" thing  */
#line 911 "miniparser.y"
                          {
			    (yyval.tree) = makeDiamAssign((yyvsp[0].tree));
			  }
#line 5056 "miniparser.c"
    break;

  case 105: /* stateassignment: "display" "=" thing  */
#line 915 "miniparser.y"
                          {
			    (yyval.tree) = makeDisplayAssign((yyvsp[0].tree));
			  }
#line 5064 "miniparser.c"
    break;

  case 106: /* stateassignment: "verbosity" "=" thing  */
#line 919 "miniparser.y"
                          {
			    (yyval.tree) = makeVerbosityAssign((yyvsp[0].tree));
			  }
#line 5072 "miniparser.c"
    break;

  case 107: /* stateassignment: "showmessagenumbers" "=" thing  */
#line 923 "miniparser.y"
                          {
			    (yyval.tree) = makeShowMessageNumbersAssign((yyvsp[0].tree));
			  }
#line 5080 "miniparser.c"
    break;

  case 108: /* stateassignment: "canonical" "=" thing  */
#line 927 "miniparser.y"
                          {
			    (yyval.tree) = makeCanonicalAssign((yyvsp[0].tree));
			  }
#line 5088 "miniparser.c"
    break;

  case 109: /* stateassignment: "autosimplify" "=" thing  */
#line 931 "miniparser.y"
                          {
			    (yyval.tree) = makeAutoSimplifyAssign((yyvsp[0].tree));
			  }
#line 5096 "miniparser.c"
    break;

  case 110: /* stateassignment: "taylorrecursions" "=" thing  */
#line 935 "miniparser.y"
                          {
			    (yyval.tree) = makeTaylorRecursAssign((yyvsp[0].tree));
			  }
#line 5104 "miniparser.c"
    break;

  case 111: /* stateassignment: "timing" "=" thing  */
#line 939 "miniparser.y"
                          {
			    (yyval.tree) = makeTimingAssign((yyvsp[0].tree));
			  }
#line 5112 "miniparser.c"
    break;

  case 112: /* stateassignment: "fullparentheses" "=" thing  */
#line 943 "miniparser.y"
                          {
			    (yyval.tree) = makeFullParenAssign((yyvsp[0].tree));
			  }
#line 5120 "miniparser.c"
    break;

  case 113: /* stateassignment: "midpointmode" "=" thing  */
#line 947 "miniparser.y"
                          {
			    (yyval.tree) = makeMidpointAssign((yyvsp[0].tree));
			  }
#line 5128 "miniparser.c"
    break;

  case 114: /* stateassignment: "dieonerrormode" "=" thing  */
#line 951 "miniparser.y"
                          {
			    (yyval.tree) = makeDieOnErrorAssign((yyvsp[0].tree));
			  }
#line 5136 "miniparser.c"
    break;

  case 115: /* stateassignment: "rationalmode" "=" thing  */
#line 955 "miniparser.y"
                          {
			    (yyval.tree) = makeRationalModeAssign((yyvsp[0].tree));
			  }
#line 5144 "miniparser.c"
    break;

  case 116: /* stateassignment: "roundingwarnings" "=" thing  */
#line 959 "miniparser.y"
                          {
			    (yyval.tree) = makeSuppressWarningsAssign((yyvsp[0].tree));
			  }
#line 5152 "miniparser.c"
    break;

  case 117: /* stateassignment: "hopitalrecursions" "=" thing  */
#line 963 "miniparser.y"
                          {
			    (yyval.tree) = makeHopitalRecursAssign((yyvsp[0].tree));
			  }
#line 5160 "miniparser.c"
    break;

  case 118: /* stillstateassignment: "prec" "=" thing  */
#line 969 "miniparser.y"
                          {
			    (yyval.tree) = makePrecStillAssign((yyvsp[0].tree));
			  }
#line 5168 "miniparser.c"
    break;

  case 119: /* stillstateassignment: "points" "=" thing  */
#line 973 "miniparser.y"
                          {
			    (yyval.tree) = makePointsStillAssign((yyvsp[0].tree));
			  }
#line 5176 "miniparser.c"
    break;

  case 120: /* stillstateassignment: "diam" "=" thing  */
#line 977 "miniparser.y"
                          {
			    (yyval.tree) = makeDiamStillAssign((yyvsp[0].tree));
			  }
#line 5184 "miniparser.c"
    break;

  case 121: /* stillstateassignment: "display" "=" thing  */
#line 981 "miniparser.y"
                          {
			    (yyval.tree) = makeDisplayStillAssign((yyvsp[0].tree));
			  }
#line 5192 "miniparser.c"
    break;

  case 122: /* stillstateassignment: "verbosity" "=" thing  */
#line 985 "miniparser.y"
                          {
			    (yyval.tree) = makeVerbosityStillAssign((yyvsp[0].tree));
			  }
#line 5200 "miniparser.c"
    break;

  case 123: /* stillstateassignment: "showmessagenumbers" "=" thing  */
#line 989 "miniparser.y"
                          {
			    (yyval.tree) = makeShowMessageNumbersStillAssign((yyvsp[0].tree));
			  }
#line 5208 "miniparser.c"
    break;

  case 124: /* stillstateassignment: "canonical" "=" thing  */
#line 993 "miniparser.y"
                          {
			    (yyval.tree) = makeCanonicalStillAssign((yyvsp[0].tree));
			  }
#line 5216 "miniparser.c"
    break;

  case 125: /* stillstateassignment: "autosimplify" "=" thing  */
#line 997 "miniparser.y"
                          {
			    (yyval.tree) = makeAutoSimplifyStillAssign((yyvsp[0].tree));
			  }
#line 5224 "miniparser.c"
    break;

  case 126: /* stillstateassignment: "taylorrecursions" "=" thing  */
#line 1001 "miniparser.y"
                          {
			    (yyval.tree) = makeTaylorRecursStillAssign((yyvsp[0].tree));
			  }
#line 5232 "miniparser.c"
    break;

  case 127: /* stillstateassignment: "timing" "=" thing  */
#line 1005 "miniparser.y"
                          {
			    (yyval.tree) = makeTimingStillAssign((yyvsp[0].tree));
			  }
#line 5240 "miniparser.c"
    break;

  case 128: /* stillstateassignment: "fullparentheses" "=" thing  */
#line 1009 "miniparser.y"
                          {
			    (yyval.tree) = makeFullParenStillAssign((yyvsp[0].tree));
			  }
#line 5248 "miniparser.c"
    break;

  case 129: /* stillstateassignment: "midpointmode" "=" thing  */
#line 1013 "miniparser.y"
                          {
			    (yyval.tree) = makeMidpointStillAssign((yyvsp[0].tree));
			  }
#line 5256 "miniparser.c"
    break;

  case 130: /* stillstateassignment: "dieonerrormode" "=" thing  */
#line 1017 "miniparser.y"
                          {
			    (yyval.tree) = makeDieOnErrorStillAssign((yyvsp[0].tree));
			  }
#line 5264 "miniparser.c"
    break;

  case 131: /* stillstateassignment: "rationalmode" "=" thing  */
#line 1021 "miniparser.y"
                          {
			    (yyval.tree) = makeRationalModeStillAssign((yyvsp[0].tree));
			  }
#line 5272 "miniparser.c"
    break;

  case 132: /* stillstateassignment: "roundingwarnings" "=" thing  */
#line 1025 "miniparser.y"
                          {
			    (yyval.tree) = makeSuppressWarningsStillAssign((yyvsp[0].tree));
			  }
#line 5280 "miniparser.c"
    break;

  case 133: /* stillstateassignment: "hopitalrecursions" "=" thing  */
#line 1029 "miniparser.y"
                          {
			    (yyval.tree) = makeHopitalRecursStillAssign((yyvsp[0].tree));
			  }
#line 5288 "miniparser.c"
    break;

  case 134: /* thinglist: thing  */
#line 1035 "miniparser.y"
                          {
			    (yyval.list) = addElement(NULL, (yyvsp[0].tree));
			  }
#line 5296 "miniparser.c"
    break;

  case 135: /* thinglist: thing "," thinglist  */
#line 1039 "miniparser.y"
                          {
			    (yyval.list) = addElement((yyvsp[0].list), (yyvsp[-2].tree));
			  }
#line 5304 "miniparser.c"
    break;

  case 136: /* structelementlist: structelement  */
#line 1045 "miniparser.y"
                          {
			    (yyval.list) = addElement(NULL, (yyvsp[0].association));
			  }
#line 5312 "miniparser.c"
    break;

  case 137: /* structelementlist: structelement structelementseparator structelementlist  */
#line 1049 "miniparser.y"
                          {
			    (yyval.list) = addElement((yyvsp[0].list), (yyvsp[-2].association));
			  }
#line 5320 "miniparser.c"
    break;

  case 138: /* structelementseparator: ","  */
#line 1055 "miniparser.y"
                          {
			    (yyval.other) = NULL;
			  }
#line 5328 "miniparser.c"
    break;

  case 139: /* structelementseparator: ";"  */
#line 1059 "miniparser.y"
                          {
			    (yyval.other) = NULL;
			  }
#line 5336 "miniparser.c"
    break;

  case 140: /* structelement: "." "identifier" "=" thing  */
#line 1065 "miniparser.y"
                          {
			    (yyval.association) = (entry *) safeMalloc(sizeof(entry));
			    (yyval.association)->name = (char *) safeCalloc(strlen((yyvsp[-2].value)) + 1, sizeof(char));
			    strcpy((yyval.association)->name,(yyvsp[-2].value));
			    safeFree((yyvsp[-2].value));
			    (yyval.association)->value = (void *) ((yyvsp[0].tree));
			  }
#line 5348 "miniparser.c"
    break;

  case 141: /* thing: supermegaterm  */
#line 1075 "miniparser.y"
                         {
			   (yyval.tree) = (yyvsp[0].tree);
			 }
#line 5356 "miniparser.c"
    break;

  case 142: /* thing: "match" supermegaterm "with" matchlist  */
#line 1079 "miniparser.y"
                          {
			    (yyval.tree) = makeMatch((yyvsp[-2].tree),(yyvsp[0].list));
			  }
#line 5364 "miniparser.c"
    break;

  case 143: /* supermegaterm: megaterm  */
#line 1085 "miniparser.y"
                          {
			    (yyval.tree) = (yyvsp[0].tree);
			  }
#line 5372 "miniparser.c"
    break;

  case 144: /* supermegaterm: thing "&&" megaterm  */
#line 1089 "miniparser.y"
                          {
			    (yyval.tree) = makeAnd((yyvsp[-2].tree), (yyvsp[0].tree));
			  }
#line 5380 "miniparser.c"
    break;

  case 145: /* supermegaterm: thing "||" megaterm  */
#line 1093 "miniparser.y"
                          {
			    (yyval.tree) = makeOr((yyvsp[-2].tree), (yyvsp[0].tree));
			  }
#line 5388 "miniparser.c"
    break;

  case 146: /* supermegaterm: "!" megaterm  */
#line 1097 "miniparser.y"
                          {
			    (yyval.tree) = makeNegation((yyvsp[0].tree));
			  }
#line 5396 "miniparser.c"
    break;

  case 147: /* indexing: basicthing "[" thing "]"  */
#line 1103 "miniparser.y"
                          {
			    (yyval.dblnode) = (doubleNode *) safeMalloc(sizeof(doubleNode));
			    (yyval.dblnode)->a = (yyvsp[-3].tree);
			    (yyval.dblnode)->b = (yyvsp[-1].tree);
			  }
#line 5406 "miniparser.c"
    break;

  case 148: /* megaterm: hyperterm  */
#line 1112 "miniparser.y"
                          {
			    (yyval.tree) = (yyvsp[0].tree);
			  }
#line 5414 "miniparser.c"
    break;

  case 149: /* megaterm: megaterm "==" hyperterm  */
#line 1116 "miniparser.y"
                          {
			    (yyval.tree) = makeCompareEqual((yyvsp[-2].tree), (yyvsp[0].tree));
			  }
#line 5422 "miniparser.c"
    break;

  case 150: /* megaterm: megaterm "in" hyperterm  */
#line 1120 "miniparser.y"
                          {
			    (yyval.tree) = makeCompareIn((yyvsp[-2].tree), (yyvsp[0].tree));
			  }
#line 5430 "miniparser.c"
    break;

  case 151: /* megaterm: megaterm "<" hyperterm  */
#line 1124 "miniparser.y"
                          {
			    (yyval.tree) = makeCompareLess((yyvsp[-2].tree), (yyvsp[0].tree));
			  }
#line 5438 "miniparser.c"
    break;

  case 152: /* megaterm: megaterm ">" hyperterm  */
#line 1128 "miniparser.y"
                          {
			    (yyval.tree) = makeCompareGreater((yyvsp[-2].tree), (yyvsp[0].tree));
			  }
#line 5446 "miniparser.c"
    break;

  case 153: /* megaterm: megaterm "<" "=" hyperterm  */
#line 1132 "miniparser.y"
                          {
			    (yyval.tree) = makeCompareLessEqual((yyvsp[-3].tree), (yyvsp[0].tree));
			  }
#line 5454 "miniparser.c"
    break;

  case 154: /* megaterm: megaterm ">" "=" hyperterm  */
#line 1136 "miniparser.y"
                          {
			    (yyval.tree) = makeCompareGreaterEqual((yyvsp[-3].tree), (yyvsp[0].tree));
			  }
#line 5462 "miniparser.c"
    break;

  case 155: /* megaterm: megaterm "!=" hyperterm  */
#line 1140 "miniparser.y"
                          {
			    (yyval.tree) = makeCompareNotEqual((yyvsp[-2].tree), (yyvsp[0].tree));
			  }
#line 5470 "miniparser.c"
    break;

  case 156: /* hyperterm: term  */
#line 1146 "miniparser.y"
                          {
			    (yyval.tree) = (yyvsp[0].tree);
			  }
#line 5478 "miniparser.c"
    break;

  case 157: /* hyperterm: hyperterm "+" term  */
#line 1150 "miniparser.y"
                          {
			    (yyval.tree) = makeAdd((yyvsp[-2].tree), (yyvsp[0].tree));
			  }
#line 5486 "miniparser.c"
    break;

  case 158: /* hyperterm: hyperterm "-" term  */
#line 1154 "miniparser.y"
                          {
			    (yyval.tree) = makeSub((yyvsp[-2].tree), (yyvsp[0].tree));
			  }
#line 5494 "miniparser.c"
    break;

  case 159: /* hyperterm: hyperterm "@" term  */
#line 1158 "miniparser.y"
                          {
			    (yyval.tree) = makeConcat((yyvsp[-2].tree), (yyvsp[0].tree));
			  }
#line 5502 "miniparser.c"
    break;

  case 160: /* hyperterm: hyperterm "::" term  */
#line 1162 "miniparser.y"
                          {
			    (yyval.tree) = makeAddToList((yyvsp[-2].tree), (yyvsp[0].tree));
			  }
#line 5510 "miniparser.c"
    break;

  case 161: /* hyperterm: hyperterm ":." term  */
#line 1166 "miniparser.y"
                          {
			    (yyval.tree) = makeAppend((yyvsp[-2].tree), (yyvsp[0].tree));
			  }
#line 5518 "miniparser.c"
    break;

  case 162: /* unaryplusminus: "+"  */
#line 1172 "miniparser.y"
                          {
                            (yyval.count) = 0;
                          }
#line 5526 "miniparser.c"
    break;

  case 163: /* unaryplusminus: "-"  */
#line 1176 "miniparser.y"
                          {
                            (yyval.count) = 1;
                          }
#line 5534 "miniparser.c"
    break;

  case 164: /* unaryplusminus: "+" unaryplusminus  */
#line 1180 "miniparser.y"
                          {
  	                    (yyval.count) = (yyvsp[0].count);
  	                  }
#line 5542 "miniparser.c"
    break;

  case 165: /* unaryplusminus: "-" unaryplusminus  */
#line 1184 "miniparser.y"
                          {
  	                    (yyval.count) = (yyvsp[0].count)+1;
                          }
#line 5550 "miniparser.c"
    break;

  case 166: /* term: subterm  */
#line 1191 "miniparser.y"
                          {
			    (yyval.tree) = (yyvsp[0].tree);
                          }
#line 5558 "miniparser.c"
    break;

  case 167: /* term: unaryplusminus subterm  */
#line 1195 "miniparser.y"
                          {
			    tempNode = (yyvsp[0].tree);
			    for (tempInteger=0;tempInteger<(yyvsp[-1].count);tempInteger++)
			      tempNode = makeNeg(tempNode);
			    (yyval.tree) = tempNode;
			  }
#line 5569 "miniparser.c"
    break;

  case 168: /* term: "~" subterm  */
#line 1202 "miniparser.y"
                          {
			    (yyval.tree) = makeEvalConst((yyvsp[0].tree));
                          }
#line 5577 "miniparser.c"
    break;

  case 169: /* term: term "*" subterm  */
#line 1206 "miniparser.y"
                          {
			    (yyval.tree) = makeMul((yyvsp[-2].tree), (yyvsp[0].tree));
                          }
#line 5585 "miniparser.c"
    break;

  case 170: /* term: term "/" subterm  */
#line 1210 "miniparser.y"
                          {
			    (yyval.tree) = makeDiv((yyvsp[-2].tree), (yyvsp[0].tree));
                          }
#line 5593 "miniparser.c"
    break;

  case 171: /* term: term "*" unaryplusminus subterm  */
#line 1214 "miniparser.y"
                          {
			    tempNode = (yyvsp[0].tree);
			    for (tempInteger=0;tempInteger<(yyvsp[-1].count);tempInteger++)
			      tempNode = makeNeg(tempNode);
			    (yyval.tree) = makeMul((yyvsp[-3].tree), tempNode);
			  }
#line 5604 "miniparser.c"
    break;

  case 172: /* term: term "/" unaryplusminus subterm  */
#line 1221 "miniparser.y"
                          {
			    tempNode = (yyvsp[0].tree);
			    for (tempInteger=0;tempInteger<(yyvsp[-1].count);tempInteger++)
			      tempNode = makeNeg(tempNode);
			    (yyval.tree) = makeDiv((yyvsp[-3].tree), tempNode);
			  }
#line 5615 "miniparser.c"
    break;

  case 173: /* term: term "*" "~" subterm  */
#line 1228 "miniparser.y"
                          {
			    (yyval.tree) = makeMul((yyvsp[-3].tree), makeEvalConst((yyvsp[0].tree)));
			  }
#line 5623 "miniparser.c"
    break;

  case 174: /* term: term "/" "~" subterm  */
#line 1232 "miniparser.y"
                          {
			    (yyval.tree) = makeDiv((yyvsp[-3].tree), makeEvalConst((yyvsp[0].tree)));
			  }
#line 5631 "miniparser.c"
    break;

  case 175: /* subterm: basicthing  */
#line 1238 "miniparser.y"
                          {
			    (yyval.tree) = (yyvsp[0].tree);
                          }
#line 5639 "miniparser.c"
    break;

  case 176: /* subterm: basicthing "^" subterm  */
#line 1242 "miniparser.y"
                          {
			    (yyval.tree) = makePow((yyvsp[-2].tree), (yyvsp[0].tree));
                          }
#line 5647 "miniparser.c"
    break;

  case 177: /* subterm: basicthing "^" unaryplusminus subterm  */
#line 1246 "miniparser.y"
                          {
			    tempNode = (yyvsp[0].tree);
			    for (tempInteger=0;tempInteger<(yyvsp[-1].count);tempInteger++)
			      tempNode = makeNeg(tempNode);
			    (yyval.tree) = makePow((yyvsp[-3].tree), tempNode);
			  }
#line 5658 "miniparser.c"
    break;

  case 178: /* subterm: basicthing "^" "~" subterm  */
#line 1253 "miniparser.y"
                          {
			    (yyval.tree) = makePow((yyvsp[-3].tree), makeEvalConst((yyvsp[0].tree)));
			  }
#line 5666 "miniparser.c"
    break;

  case 179: /* subterm: basicthing ".:" subterm  */
#line 1257 "miniparser.y"
                          {
			    (yyval.tree) = makePrepend((yyvsp[-2].tree), (yyvsp[0].tree));
			  }
#line 5674 "miniparser.c"
    break;

  case 180: /* subterm: basicthing ".:" "~" subterm  */
#line 1261 "miniparser.y"
                          {
			    (yyval.tree) = makePrepend((yyvsp[-3].tree), makeEvalConst((yyvsp[0].tree)));
			  }
#line 5682 "miniparser.c"
    break;

  case 181: /* basicthing: "on"  */
#line 1268 "miniparser.y"
                          {
			    (yyval.tree) = makeOn();
			  }
#line 5690 "miniparser.c"
    break;

  case 182: /* basicthing: "off"  */
#line 1272 "miniparser.y"
                          {
			    (yyval.tree) = makeOff();
			  }
#line 5698 "miniparser.c"
    break;

  case 183: /* basicthing: "dyadic"  */
#line 1276 "miniparser.y"
                          {
			    (yyval.tree) = makeDyadic();
			  }
#line 5706 "miniparser.c"
    break;

  case 184: /* basicthing: "powers"  */
#line 1280 "miniparser.y"
                          {
			    (yyval.tree) = makePowers();
			  }
#line 5714 "miniparser.c"
    break;

  case 185: /* basicthing: "binary"  */
#line 1284 "miniparser.y"
                          {
			    (yyval.tree) = makeBinaryThing();
			  }
#line 5722 "miniparser.c"
    break;

  case 186: /* basicthing: "hexadecimal"  */
#line 1288 "miniparser.y"
                          {
			    (yyval.tree) = makeHexadecimalThing();
			  }
#line 5730 "miniparser.c"
    break;

  case 187: /* basicthing: "file"  */
#line 1292 "miniparser.y"
                          {
			    (yyval.tree) = makeFile();
			  }
#line 5738 "miniparser.c"
    break;

  case 188: /* basicthing: "postscript"  */
#line 1296 "miniparser.y"
                          {
			    (yyval.tree) = makePostscript();
			  }
#line 5746 "miniparser.c"
    break;

  case 189: /* basicthing: "postscriptfile"  */
#line 1300 "miniparser.y"
                          {
			    (yyval.tree) = makePostscriptFile();
			  }
#line 5754 "miniparser.c"
    break;

  case 190: /* basicthing: "perturb"  */
#line 1304 "miniparser.y"
                          {
			    (yyval.tree) = makePerturb();
			  }
#line 5762 "miniparser.c"
    break;

  case 191: /* basicthing: "RD"  */
#line 1308 "miniparser.y"
                          {
			    (yyval.tree) = makeRoundDown();
			  }
#line 5770 "miniparser.c"
    break;

  case 192: /* basicthing: "RU"  */
#line 1312 "miniparser.y"
                          {
			    (yyval.tree) = makeRoundUp();
			  }
#line 5778 "miniparser.c"
    break;

  case 193: /* basicthing: "RZ"  */
#line 1316 "miniparser.y"
                          {
			    (yyval.tree) = makeRoundToZero();
			  }
#line 5786 "miniparser.c"
    break;

  case 194: /* basicthing: "RN"  */
#line 1320 "miniparser.y"
                          {
			    (yyval.tree) = makeRoundToNearest();
			  }
#line 5794 "miniparser.c"
    break;

  case 195: /* basicthing: "honorcoeffprec"  */
#line 1324 "miniparser.y"
                          {
			    (yyval.tree) = makeHonorCoeff();
			  }
#line 5802 "miniparser.c"
    break;

  case 196: /* basicthing: "true"  */
#line 1328 "miniparser.y"
                          {
			    (yyval.tree) = makeTrue();
			  }
#line 5810 "miniparser.c"
    break;

  case 197: /* basicthing: "void"  */
#line 1332 "miniparser.y"
                          {
			    (yyval.tree) = makeUnit();
			  }
#line 5818 "miniparser.c"
    break;

  case 198: /* basicthing: "false"  */
#line 1336 "miniparser.y"
                          {
			    (yyval.tree) = makeFalse();
			  }
#line 5826 "miniparser.c"
    break;

  case 199: /* basicthing: "default"  */
#line 1340 "miniparser.y"
                          {
			    (yyval.tree) = makeDefault();
			  }
#line 5834 "miniparser.c"
    break;

  case 200: /* basicthing: "decimal"  */
#line 1344 "miniparser.y"
                          {
			    (yyval.tree) = makeDecimal();
			  }
#line 5842 "miniparser.c"
    break;

  case 201: /* basicthing: "absolute"  */
#line 1348 "miniparser.y"
                          {
			    (yyval.tree) = makeAbsolute();
			  }
#line 5850 "miniparser.c"
    break;

  case 202: /* basicthing: "relative"  */
#line 1352 "miniparser.y"
                          {
			    (yyval.tree) = makeRelative();
			  }
#line 5858 "miniparser.c"
    break;

  case 203: /* basicthing: "fixed"  */
#line 1356 "miniparser.y"
                          {
			    (yyval.tree) = makeFixed();
			  }
#line 5866 "miniparser.c"
    break;

  case 204: /* basicthing: "floating"  */
#line 1360 "miniparser.y"
                          {
			    (yyval.tree) = makeFloating();
			  }
#line 5874 "miniparser.c"
    break;

  case 205: /* basicthing: "error"  */
#line 1364 "miniparser.y"
                          {
			    (yyval.tree) = makeError();
			  }
#line 5882 "miniparser.c"
    break;

  case 206: /* basicthing: "D"  */
#line 1368 "miniparser.y"
                          {
			    (yyval.tree) = makeDoubleSymbol();
			  }
#line 5890 "miniparser.c"
    break;

  case 207: /* basicthing: "SG"  */
#line 1372 "miniparser.y"
                          {
			    (yyval.tree) = makeSingleSymbol();
			  }
#line 5898 "miniparser.c"
    break;

  case 208: /* basicthing: "QD"  */
#line 1376 "miniparser.y"
                          {
			    (yyval.tree) = makeQuadSymbol();
			  }
#line 5906 "miniparser.c"
    break;

  case 209: /* basicthing: "HP"  */
#line 1380 "miniparser.y"
                          {
			    (yyval.tree) = makeHalfPrecisionSymbol();
			  }
#line 5914 "miniparser.c"
    break;

  case 210: /* basicthing: "DE"  */
#line 1384 "miniparser.y"
                          {
			    (yyval.tree) = makeDoubleextendedSymbol();
			  }
#line 5922 "miniparser.c"
    break;

  case 211: /* basicthing: "_x_"  */
#line 1388 "miniparser.y"
                          {
			    (yyval.tree) = makeVariable();
			  }
#line 5930 "miniparser.c"
    break;

  case 212: /* basicthing: "DD"  */
#line 1392 "miniparser.y"
                          {
			    (yyval.tree) = makeDoubleDoubleSymbol();
			  }
#line 5938 "miniparser.c"
    break;

  case 213: /* basicthing: "TD"  */
#line 1396 "miniparser.y"
                          {
			    (yyval.tree) = makeTripleDoubleSymbol();
			  }
#line 5946 "miniparser.c"
    break;

  case 214: /* basicthing: "character string"  */
#line 1400 "miniparser.y"
                          {
			    tempString = safeCalloc(strlen((yyvsp[0].value)) + 1, sizeof(char));
			    strcpy(tempString, (yyvsp[0].value));
			    safeFree((yyvsp[0].value));
			    tempString2 = safeCalloc(strlen(tempString) + 1, sizeof(char));
			    strcpy(tempString2, tempString);
			    safeFree(tempString);
			    (yyval.tree) = makeString(tempString2);
			    safeFree(tempString2);
			  }
#line 5961 "miniparser.c"
    break;

  case 215: /* basicthing: constant  */
#line 1411 "miniparser.y"
                          {
			    (yyval.tree) = (yyvsp[0].tree);
			  }
#line 5969 "miniparser.c"
    break;

  case 216: /* basicthing: "identifier"  */
#line 1415 "miniparser.y"
                          {
			    (yyval.tree) = makeTableAccess((yyvsp[0].value));
			    safeFree((yyvsp[0].value));
			  }
#line 5978 "miniparser.c"
    break;

  case 217: /* basicthing: "isbound" "(" "identifier" ")"  */
#line 1420 "miniparser.y"
                          {
			    (yyval.tree) = makeIsBound((yyvsp[-1].value));
			    safeFree((yyvsp[-1].value));
			  }
#line 5987 "miniparser.c"
    break;

  case 218: /* basicthing: "identifier" "(" thinglist ")"  */
#line 1425 "miniparser.y"
                          {
			    (yyval.tree) = makeTableAccessWithSubstitute((yyvsp[-3].value), (yyvsp[-1].list));
			    safeFree((yyvsp[-3].value));
			  }
#line 5996 "miniparser.c"
    break;

  case 219: /* basicthing: "identifier" "(" ")"  */
#line 1430 "miniparser.y"
                          {
			    (yyval.tree) = makeTableAccessWithSubstitute((yyvsp[-2].value), NULL);
			    safeFree((yyvsp[-2].value));
			  }
#line 6005 "miniparser.c"
    break;

  case 220: /* basicthing: list  */
#line 1435 "miniparser.y"
                          {
			    (yyval.tree) = (yyvsp[0].tree);
			  }
#line 6013 "miniparser.c"
    break;

  case 221: /* basicthing: range  */
#line 1439 "miniparser.y"
                          {
			    (yyval.tree) = (yyvsp[0].tree);
			  }
#line 6021 "miniparser.c"
    break;

  case 222: /* basicthing: debound  */
#line 1443 "miniparser.y"
                          {
			    (yyval.tree) = (yyvsp[0].tree);
			  }
#line 6029 "miniparser.c"
    break;

  case 223: /* basicthing: headfunction  */
#line 1447 "miniparser.y"
                          {
			    (yyval.tree) = (yyvsp[0].tree);
			  }
#line 6037 "miniparser.c"
    break;

  case 224: /* basicthing: "(" thing ")"  */
#line 1451 "miniparser.y"
                          {
			    (yyval.tree) = (yyvsp[-1].tree);
			  }
#line 6045 "miniparser.c"
    break;

  case 225: /* basicthing: "{" structelementlist "}"  */
#line 1455 "miniparser.y"
                          {
			    (yyval.tree) = makeStructure((yyvsp[-1].list));
			  }
#line 6053 "miniparser.c"
    break;

  case 226: /* basicthing: statedereference  */
#line 1459 "miniparser.y"
                          {
			    (yyval.tree) = (yyvsp[0].tree);
			  }
#line 6061 "miniparser.c"
    break;

  case 227: /* basicthing: indexing  */
#line 1463 "miniparser.y"
                          {
			    (yyval.tree) = makeIndex((yyvsp[0].dblnode)->a, (yyvsp[0].dblnode)->b);
			    safeFree((yyvsp[0].dblnode));
			  }
#line 6070 "miniparser.c"
    break;

  case 228: /* basicthing: basicthing "." "identifier"  */
#line 1468 "miniparser.y"
                          {
			    (yyval.tree) = makeStructAccess((yyvsp[-2].tree),(yyvsp[0].value));
			    safeFree((yyvsp[0].value));
			  }
#line 6079 "miniparser.c"
    break;

  case 229: /* basicthing: basicthing "." "identifier" "(" ")"  */
#line 1473 "miniparser.y"
                          {
			    (yyval.tree) = makeApply(makeStructAccess((yyvsp[-4].tree),(yyvsp[-2].value)),addElement(NULL, makeUnit()));
			    safeFree((yyvsp[-2].value));
			  }
#line 6088 "miniparser.c"
    break;

  case 230: /* basicthing: basicthing "." "identifier" "(" thinglist ")"  */
#line 1478 "miniparser.y"
                          {
			    (yyval.tree) = makeApply(makeStructAccess((yyvsp[-5].tree),(yyvsp[-3].value)),(yyvsp[-1].list));
			    safeFree((yyvsp[-3].value));
			  }
#line 6097 "miniparser.c"
    break;

  case 231: /* basicthing: "(" thing ")" "(" thinglist ")"  */
#line 1483 "miniparser.y"
                          {
			    (yyval.tree) = makeApply((yyvsp[-4].tree),(yyvsp[-1].list));
			  }
#line 6105 "miniparser.c"
    break;

  case 232: /* basicthing: "(" thing ")" "(" ")"  */
#line 1487 "miniparser.y"
                          {
			    (yyval.tree) = makeApply((yyvsp[-3].tree),addElement(NULL,makeUnit()));
			  }
#line 6113 "miniparser.c"
    break;

  case 233: /* basicthing: "proc" procbody  */
#line 1491 "miniparser.y"
                          {
			    (yyval.tree) = (yyvsp[0].tree);
			  }
#line 6121 "miniparser.c"
    break;

  case 234: /* basicthing: "time" "(" command ")"  */
#line 1495 "miniparser.y"
                          {
			    (yyval.tree) = makeTime((yyvsp[-1].tree));
                          }
#line 6129 "miniparser.c"
    break;

  case 235: /* matchlist: matchelement  */
#line 1501 "miniparser.y"
                          {
			    (yyval.list) = addElement(NULL,(yyvsp[0].tree));
			  }
#line 6137 "miniparser.c"
    break;

  case 236: /* matchlist: matchelement matchlist  */
#line 1505 "miniparser.y"
                          {
			    (yyval.list) = addElement((yyvsp[0].list),(yyvsp[-1].tree));
			  }
#line 6145 "miniparser.c"
    break;

  case 237: /* matchelement: thing ":" beginsymbol variabledeclarationlist commandlist "return" thing ";" endsymbol  */
#line 1511 "miniparser.y"
                          {
			    (yyval.tree) = makeMatchElement((yyvsp[-8].tree),makeCommandList(concatChains((yyvsp[-5].list), (yyvsp[-4].list))),(yyvsp[-2].tree));
			  }
#line 6153 "miniparser.c"
    break;

  case 238: /* matchelement: thing ":" beginsymbol variabledeclarationlist commandlist endsymbol  */
#line 1515 "miniparser.y"
                          {
			    (yyval.tree) = makeMatchElement((yyvsp[-5].tree),makeCommandList(concatChains((yyvsp[-2].list), (yyvsp[-1].list))),makeUnit());
			  }
#line 6161 "miniparser.c"
    break;

  case 239: /* matchelement: thing ":" beginsymbol variabledeclarationlist "return" thing ";" endsymbol  */
#line 1519 "miniparser.y"
                          {
			    (yyval.tree) = makeMatchElement((yyvsp[-7].tree),makeCommandList((yyvsp[-4].list)),(yyvsp[-2].tree));
			  }
#line 6169 "miniparser.c"
    break;

  case 240: /* matchelement: thing ":" beginsymbol variabledeclarationlist endsymbol  */
#line 1523 "miniparser.y"
                          {
			    (yyval.tree) = makeMatchElement((yyvsp[-4].tree),makeCommandList((yyvsp[-1].list)),makeUnit());
			  }
#line 6177 "miniparser.c"
    break;

  case 241: /* matchelement: thing ":" beginsymbol commandlist "return" thing ";" endsymbol  */
#line 1527 "miniparser.y"
                          {
			    (yyval.tree) = makeMatchElement((yyvsp[-7].tree),makeCommandList((yyvsp[-4].list)),(yyvsp[-2].tree));
			  }
#line 6185 "miniparser.c"
    break;

  case 242: /* matchelement: thing ":" beginsymbol commandlist endsymbol  */
#line 1531 "miniparser.y"
                          {
			    (yyval.tree) = makeMatchElement((yyvsp[-4].tree),makeCommandList((yyvsp[-1].list)),makeUnit());
			  }
#line 6193 "miniparser.c"
    break;

  case 243: /* matchelement: thing ":" beginsymbol "return" thing ";" endsymbol  */
#line 1535 "miniparser.y"
                          {
			    (yyval.tree) = makeMatchElement((yyvsp[-6].tree), makeCommandList(addElement(NULL,makeNop())), (yyvsp[-2].tree));
			  }
#line 6201 "miniparser.c"
    break;

  case 244: /* matchelement: thing ":" beginsymbol endsymbol  */
#line 1539 "miniparser.y"
                          {
			    (yyval.tree) = makeMatchElement((yyvsp[-3].tree), makeCommandList(addElement(NULL,makeNop())), makeUnit());
			  }
#line 6209 "miniparser.c"
    break;

  case 245: /* matchelement: thing ":" "(" thing ")"  */
#line 1543 "miniparser.y"
                          {
			    (yyval.tree) = makeMatchElement((yyvsp[-4].tree), makeCommandList(addElement(NULL,makeNop())), (yyvsp[-1].tree));
			  }
#line 6217 "miniparser.c"
    break;

  case 246: /* constant: "decimal constant"  */
#line 1549 "miniparser.y"
                          {
			    (yyval.tree) = makeDecimalConstant((yyvsp[0].value));
			    safeFree((yyvsp[0].value));
			  }
#line 6226 "miniparser.c"
    break;

  case 247: /* constant: "interval"  */
#line 1554 "miniparser.y"
                          {
			    (yyval.tree) = makeMidpointConstant((yyvsp[0].value));
			    safeFree((yyvsp[0].value));
			  }
#line 6235 "miniparser.c"
    break;

  case 248: /* constant: "dyadic constant"  */
#line 1559 "miniparser.y"
                          {
			    (yyval.tree) = makeDyadicConstant((yyvsp[0].value));
			    safeFree((yyvsp[0].value));
			  }
#line 6244 "miniparser.c"
    break;

  case 249: /* constant: "constant in memory notation"  */
#line 1564 "miniparser.y"
                          {
			    (yyval.tree) = makeHexConstant((yyvsp[0].value));
			    safeFree((yyvsp[0].value));
			  }
#line 6253 "miniparser.c"
    break;

  case 250: /* constant: "hexadecimal constant"  */
#line 1569 "miniparser.y"
                          {
			    (yyval.tree) = makeHexadecimalConstant((yyvsp[0].value));
			    safeFree((yyvsp[0].value));
			  }
#line 6262 "miniparser.c"
    break;

  case 251: /* constant: "binary constant"  */
#line 1574 "miniparser.y"
                          {
			    (yyval.tree) = makeBinaryConstant((yyvsp[0].value));
			    safeFree((yyvsp[0].value));
			  }
#line 6271 "miniparser.c"
    break;

  case 252: /* constant: "pi"  */
#line 1579 "miniparser.y"
                          {
			    (yyval.tree) = makePi();
			  }
#line 6279 "miniparser.c"
    break;

  case 253: /* list: "[" "|" "|" "]"  */
#line 1587 "miniparser.y"
                          {
			    (yyval.tree) = makeEmptyList();
			  }
#line 6287 "miniparser.c"
    break;

  case 254: /* list: "[" "||" "]"  */
#line 1591 "miniparser.y"
                          {
			    (yyval.tree) = makeEmptyList();
			  }
#line 6295 "miniparser.c"
    break;

  case 255: /* list: "[" "|" simplelist "|" "]"  */
#line 1595 "miniparser.y"
                          {
			    (yyval.tree) = makeRevertedList((yyvsp[-2].list));
			  }
#line 6303 "miniparser.c"
    break;

  case 256: /* list: "[" "|" simplelist "..." "|" "]"  */
#line 1599 "miniparser.y"
                          {
			    (yyval.tree) = makeRevertedFinalEllipticList((yyvsp[-3].list));
			  }
#line 6311 "miniparser.c"
    break;

  case 257: /* simplelist: thing  */
#line 1605 "miniparser.y"
                          {
			    (yyval.list) = addElement(NULL, (yyvsp[0].tree));
			  }
#line 6319 "miniparser.c"
    break;

  case 258: /* simplelist: simplelist "," thing  */
#line 1609 "miniparser.y"
                          {
			    (yyval.list) = addElement((yyvsp[-2].list), (yyvsp[0].tree));
			  }
#line 6327 "miniparser.c"
    break;

  case 259: /* simplelist: simplelist "," "..." "," thing  */
#line 1613 "miniparser.y"
                          {
			    (yyval.list) = addElement(addElement((yyvsp[-4].list), makeElliptic()), (yyvsp[0].tree));
			  }
#line 6335 "miniparser.c"
    break;

  case 260: /* range: "[" thing "," thing "]"  */
#line 1619 "miniparser.y"
                          {
			    (yyval.tree) = makeRange((yyvsp[-3].tree), (yyvsp[-1].tree));
			  }
#line 6343 "miniparser.c"
    break;

  case 261: /* range: "[" thing ";" thing "]"  */
#line 1623 "miniparser.y"
                          {
			    (yyval.tree) = makeRange((yyvsp[-3].tree), (yyvsp[-1].tree));
			  }
#line 6351 "miniparser.c"
    break;

  case 262: /* range: "[" thing "]"  */
#line 1627 "miniparser.y"
                          {
			    (yyval.tree) = makeRange((yyvsp[-1].tree), copyThing((yyvsp[-1].tree)));
			  }
#line 6359 "miniparser.c"
    break;

  case 263: /* debound: "*<" thing ">*"  */
#line 1633 "miniparser.y"
                          {
			    (yyval.tree) = makeDeboundMax((yyvsp[-1].tree));
			  }
#line 6367 "miniparser.c"
    break;

  case 264: /* debound: "*<" thing ">."  */
#line 1637 "miniparser.y"
                          {
			    (yyval.tree) = makeDeboundMid((yyvsp[-1].tree));
			  }
#line 6375 "miniparser.c"
    break;

  case 265: /* debound: "*<" thing ">_"  */
#line 1641 "miniparser.y"
                          {
			    (yyval.tree) = makeDeboundMin((yyvsp[-1].tree));
			  }
#line 6383 "miniparser.c"
    break;

  case 266: /* debound: "sup" "(" thing ")"  */
#line 1645 "miniparser.y"
                          {
			    (yyval.tree) = makeDeboundMax((yyvsp[-1].tree));
			  }
#line 6391 "miniparser.c"
    break;

  case 267: /* debound: "mid" "(" thing ")"  */
#line 1649 "miniparser.y"
                          {
			    (yyval.tree) = makeDeboundMid((yyvsp[-1].tree));
			  }
#line 6399 "miniparser.c"
    break;

  case 268: /* debound: "inf" "(" thing ")"  */
#line 1653 "miniparser.y"
                          {
			    (yyval.tree) = makeDeboundMin((yyvsp[-1].tree));
			  }
#line 6407 "miniparser.c"
    break;

  case 269: /* headfunction: "diff" "(" thing ")"  */
#line 1659 "miniparser.y"
                          {
			    (yyval.tree) = makeDiff((yyvsp[-1].tree));
			  }
#line 6415 "miniparser.c"
    break;

  case 270: /* headfunction: "bashevaluate" "(" thing ")"  */
#line 1663 "miniparser.y"
                          {
			    (yyval.tree) = makeBashevaluate(addElement(NULL,(yyvsp[-1].tree)));
			  }
#line 6423 "miniparser.c"
    break;

  case 271: /* headfunction: "getsuppressedmessages" "(" ")"  */
#line 1667 "miniparser.y"
                          {
			    (yyval.tree) = makeGetSuppressedMessages();
			  }
#line 6431 "miniparser.c"
    break;

  case 272: /* headfunction: "getbacktrace" "(" ")"  */
#line 1671 "miniparser.y"
                          {
			    (yyval.tree) = makeGetBacktrace();
			  }
#line 6439 "miniparser.c"
    break;

  case 273: /* headfunction: "bashevaluate" "(" thing "," thing ")"  */
#line 1675 "miniparser.y"
                          {
			    (yyval.tree) = makeBashevaluate(addElement(addElement(NULL,(yyvsp[-1].tree)),(yyvsp[-3].tree)));
			  }
#line 6447 "miniparser.c"
    break;

  case 274: /* headfunction: "dirtysimplify" "(" thing ")"  */
#line 1679 "miniparser.y"
                          {
			    (yyval.tree) = makeDirtysimplify((yyvsp[-1].tree));
			  }
#line 6455 "miniparser.c"
    break;

  case 275: /* headfunction: "remez" "(" thing "," thing "," thinglist ")"  */
#line 1683 "miniparser.y"
                          {
			    (yyval.tree) = makeRemez(addElement(addElement((yyvsp[-1].list), (yyvsp[-3].tree)), (yyvsp[-5].tree)));
			  }
#line 6463 "miniparser.c"
    break;

  case 276: /* headfunction: "annotatefunction" "(" thing "," thing "," thing "," thinglist ")"  */
#line 1687 "miniparser.y"
                          {
			    (yyval.tree) = makeAnnotateFunction(addElement(addElement(addElement((yyvsp[-1].list), (yyvsp[-3].tree)), (yyvsp[-5].tree)), (yyvsp[-7].tree)));
			  }
#line 6471 "miniparser.c"
    break;

  case 277: /* headfunction: "bind" "(" thing "," "identifier" "," thing ")"  */
#line 1691 "miniparser.y"
                          {
			    (yyval.tree) = makeBind((yyvsp[-5].tree), (yyvsp[-3].value), (yyvsp[-1].tree));
			    safeFree((yyvsp[-3].value));
			  }
#line 6480 "miniparser.c"
    break;

  case 278: /* headfunction: "min" "(" thinglist ")"  */
#line 1696 "miniparser.y"
                          {
			    (yyval.tree) = makeMin((yyvsp[-1].list));
			  }
#line 6488 "miniparser.c"
    break;

  case 279: /* headfunction: "max" "(" thinglist ")"  */
#line 1700 "miniparser.y"
                          {
			    (yyval.tree) = makeMax((yyvsp[-1].list));
			  }
#line 6496 "miniparser.c"
    break;

  case 280: /* headfunction: "fpminimax" "(" thing "," thing "," thing "," thinglist ")"  */
#line 1704 "miniparser.y"
                          {
			    (yyval.tree) = makeFPminimax(addElement(addElement(addElement((yyvsp[-1].list), (yyvsp[-3].tree)), (yyvsp[-5].tree)), (yyvsp[-7].tree)));
			  }
#line 6504 "miniparser.c"
    break;

  case 281: /* headfunction: "horner" "(" thing ")"  */
#line 1708 "miniparser.y"
                          {
			    (yyval.tree) = makeHorner((yyvsp[-1].tree));
			  }
#line 6512 "miniparser.c"
    break;

  case 282: /* headfunction: "canonical" "(" thing ")"  */
#line 1712 "miniparser.y"
                          {
			    (yyval.tree) = makeCanonicalThing((yyvsp[-1].tree));
			  }
#line 6520 "miniparser.c"
    break;

  case 283: /* headfunction: "expand" "(" thing ")"  */
#line 1716 "miniparser.y"
                          {
			    (yyval.tree) = makeExpand((yyvsp[-1].tree));
			  }
#line 6528 "miniparser.c"
    break;

  case 284: /* headfunction: "simplify" "(" thing ")"  */
#line 1720 "miniparser.y"
                          {
			    (yyval.tree) = makeSimplifySafe((yyvsp[-1].tree));
			  }
#line 6536 "miniparser.c"
    break;

  case 285: /* headfunction: "taylor" "(" thing "," thing "," thing ")"  */
#line 1724 "miniparser.y"
                          {
			    (yyval.tree) = makeTaylor((yyvsp[-5].tree), (yyvsp[-3].tree), (yyvsp[-1].tree));
			  }
#line 6544 "miniparser.c"
    break;

  case 286: /* headfunction: "taylorform" "(" thing "," thing "," thinglist ")"  */
#line 1728 "miniparser.y"
                          {
                            (yyval.tree) = makeTaylorform(addElement(addElement((yyvsp[-1].list), (yyvsp[-3].tree)), (yyvsp[-5].tree)));
			  }
#line 6552 "miniparser.c"
    break;

  case 287: /* headfunction: "chebyshevform" "(" thing "," thing "," thing ")"  */
#line 1732 "miniparser.y"
                          {
                            (yyval.tree) = makeChebyshevform(addElement(addElement(addElement(NULL, (yyvsp[-1].tree)), (yyvsp[-3].tree)), (yyvsp[-5].tree)));
			  }
#line 6560 "miniparser.c"
    break;

  case 288: /* headfunction: "autodiff" "(" thing "," thing "," thing ")"  */
#line 1736 "miniparser.y"
                          {
                            (yyval.tree) = makeAutodiff(addElement(addElement(addElement(NULL, (yyvsp[-1].tree)), (yyvsp[-3].tree)), (yyvsp[-5].tree)));
			  }
#line 6568 "miniparser.c"
    break;

  case 289: /* headfunction: "degree" "(" thing ")"  */
#line 1740 "miniparser.y"
                          {
			    (yyval.tree) = makeDegree((yyvsp[-1].tree));
			  }
#line 6576 "miniparser.c"
    break;

  case 290: /* headfunction: "numerator" "(" thing ")"  */
#line 1744 "miniparser.y"
                          {
			    (yyval.tree) = makeNumerator((yyvsp[-1].tree));
			  }
#line 6584 "miniparser.c"
    break;

  case 291: /* headfunction: "denominator" "(" thing ")"  */
#line 1748 "miniparser.y"
                          {
			    (yyval.tree) = makeDenominator((yyvsp[-1].tree));
			  }
#line 6592 "miniparser.c"
    break;

  case 292: /* headfunction: "substitute" "(" thing "," thing ")"  */
#line 1752 "miniparser.y"
                          {
			    (yyval.tree) = makeSubstitute((yyvsp[-3].tree), (yyvsp[-1].tree));
			  }
#line 6600 "miniparser.c"
    break;

  case 293: /* headfunction: "composepolynomials" "(" thing "," thing ")"  */
#line 1756 "miniparser.y"
                          {
			    (yyval.tree) = makeComposePolynomials((yyvsp[-3].tree), (yyvsp[-1].tree));
			  }
#line 6608 "miniparser.c"
    break;

  case 294: /* headfunction: "bezout" "(" thing "," thing ")"  */
#line 1760 "miniparser.y"
                          {
			    (yyval.tree) = makeBezout((yyvsp[-3].tree), (yyvsp[-1].tree));
			  }
#line 6616 "miniparser.c"
    break;

  case 295: /* headfunction: "coeff" "(" thing "," thing ")"  */
#line 1764 "miniparser.y"
                          {
			    (yyval.tree) = makeCoeff((yyvsp[-3].tree), (yyvsp[-1].tree));
			  }
#line 6624 "miniparser.c"
    break;

  case 296: /* headfunction: "subpoly" "(" thing "," thing ")"  */
#line 1768 "miniparser.y"
                          {
			    (yyval.tree) = makeSubpoly((yyvsp[-3].tree), (yyvsp[-1].tree));
			  }
#line 6632 "miniparser.c"
    break;

  case 297: /* headfunction: "roundcoefficients" "(" thing "," thing ")"  */
#line 1772 "miniparser.y"
                          {
			    (yyval.tree) = makeRoundcoefficients((yyvsp[-3].tree), (yyvsp[-1].tree));
			  }
#line 6640 "miniparser.c"
    break;

  case 298: /* headfunction: "rationalapprox" "(" thing "," thing ")"  */
#line 1776 "miniparser.y"
                          {
			    (yyval.tree) = makeRationalapprox((yyvsp[-3].tree), (yyvsp[-1].tree));
			  }
#line 6648 "miniparser.c"
    break;

  case 299: /* headfunction: "accurateinfnorm" "(" thing "," thing "," thinglist ")"  */
#line 1780 "miniparser.y"
                          {
			    (yyval.tree) = makeAccurateInfnorm(addElement(addElement((yyvsp[-1].list), (yyvsp[-3].tree)), (yyvsp[-5].tree)));
			  }
#line 6656 "miniparser.c"
    break;

  case 300: /* headfunction: "round" "(" thing "," thing "," thing ")"  */
#line 1784 "miniparser.y"
                          {
			    (yyval.tree) = makeRoundToFormat((yyvsp[-5].tree), (yyvsp[-3].tree), (yyvsp[-1].tree));
			  }
#line 6664 "miniparser.c"
    break;

  case 301: /* headfunction: "evaluate" "(" thing "," thing ")"  */
#line 1788 "miniparser.y"
                          {
			    (yyval.tree) = makeEvaluate((yyvsp[-3].tree), (yyvsp[-1].tree));
			  }
#line 6672 "miniparser.c"
    break;

  case 302: /* headfunction: "parse" "(" thing ")"  */
#line 1792 "miniparser.y"
                          {
			    (yyval.tree) = makeParse((yyvsp[-1].tree));
			  }
#line 6680 "miniparser.c"
    break;

  case 303: /* headfunction: "readxml" "(" thing ")"  */
#line 1796 "miniparser.y"
                          {
			    (yyval.tree) = makeReadXml((yyvsp[-1].tree));
			  }
#line 6688 "miniparser.c"
    break;

  case 304: /* headfunction: "infnorm" "(" thing "," thinglist ")"  */
#line 1800 "miniparser.y"
                          {
			    (yyval.tree) = makeInfnorm(addElement((yyvsp[-1].list), (yyvsp[-3].tree)));
			  }
#line 6696 "miniparser.c"
    break;

  case 305: /* headfunction: "supnorm" "(" thing "," thing "," thing "," thing "," thing ")"  */
#line 1804 "miniparser.y"
                          {
			    (yyval.tree) = makeSupnorm(addElement(addElement(addElement(addElement(addElement(NULL,(yyvsp[-1].tree)),(yyvsp[-3].tree)),(yyvsp[-5].tree)),(yyvsp[-7].tree)),(yyvsp[-9].tree)));
			  }
#line 6704 "miniparser.c"
    break;

  case 306: /* headfunction: "findzeros" "(" thing "," thing ")"  */
#line 1808 "miniparser.y"
                          {
			    (yyval.tree) = makeFindZeros((yyvsp[-3].tree), (yyvsp[-1].tree));
			  }
#line 6712 "miniparser.c"
    break;

  case 307: /* headfunction: "fpfindzeros" "(" thing "," thing ")"  */
#line 1812 "miniparser.y"
                          {
			    (yyval.tree) = makeFPFindZeros((yyvsp[-3].tree), (yyvsp[-1].tree));
			  }
#line 6720 "miniparser.c"
    break;

  case 308: /* headfunction: "dirtyinfnorm" "(" thing "," thing ")"  */
#line 1816 "miniparser.y"
                          {
			    (yyval.tree) = makeDirtyInfnorm((yyvsp[-3].tree), (yyvsp[-1].tree));
			  }
#line 6728 "miniparser.c"
    break;

  case 309: /* headfunction: "gcd" "(" thing "," thing ")"  */
#line 1820 "miniparser.y"
                          {
			    (yyval.tree) = makeGcd((yyvsp[-3].tree), (yyvsp[-1].tree));
			  }
#line 6736 "miniparser.c"
    break;

  case 310: /* headfunction: "div" "(" thing "," thing ")"  */
#line 1824 "miniparser.y"
                          {
			    (yyval.tree) = makeEuclDiv((yyvsp[-3].tree), (yyvsp[-1].tree));
			  }
#line 6744 "miniparser.c"
    break;

  case 311: /* headfunction: "mod" "(" thing "," thing ")"  */
#line 1828 "miniparser.y"
                          {
			    (yyval.tree) = makeEuclMod((yyvsp[-3].tree), (yyvsp[-1].tree));
			  }
#line 6752 "miniparser.c"
    break;

  case 312: /* headfunction: "numberroots" "(" thing "," thing ")"  */
#line 1832 "miniparser.y"
                          {
			    (yyval.tree) = makeNumberRoots((yyvsp[-3].tree), (yyvsp[-1].tree));
			  }
#line 6760 "miniparser.c"
    break;

  case 313: /* headfunction: "integral" "(" thing "," thing ")"  */
#line 1836 "miniparser.y"
                          {
			    (yyval.tree) = makeIntegral((yyvsp[-3].tree), (yyvsp[-1].tree));
			  }
#line 6768 "miniparser.c"
    break;

  case 314: /* headfunction: "dirtyintegral" "(" thing "," thing ")"  */
#line 1840 "miniparser.y"
                          {
			    (yyval.tree) = makeDirtyIntegral((yyvsp[-3].tree), (yyvsp[-1].tree));
			  }
#line 6776 "miniparser.c"
    break;

  case 315: /* headfunction: "implementpoly" "(" thing "," thing "," thing "," thing "," thing "," thinglist ")"  */
#line 1844 "miniparser.y"
                          {
			    (yyval.tree) = makeImplementPoly(addElement(addElement(addElement(addElement(addElement((yyvsp[-1].list), (yyvsp[-3].tree)), (yyvsp[-5].tree)), (yyvsp[-7].tree)), (yyvsp[-9].tree)), (yyvsp[-11].tree)));
			  }
#line 6784 "miniparser.c"
    break;

  case 316: /* headfunction: "implementconst" "(" thinglist ")"  */
#line 1848 "miniparser.y"
                          {
			    (yyval.tree) = makeImplementConst((yyvsp[-1].list));
			  }
#line 6792 "miniparser.c"
    break;

  case 317: /* headfunction: "interpolate" "(" thing "," thinglist ")"  */
#line 1852 "miniparser.y"
                          {
			    (yyval.tree) = makeInterpolate(addElement((yyvsp[-1].list), (yyvsp[-3].tree)));
			  }
#line 6800 "miniparser.c"
    break;

  case 318: /* headfunction: "checkinfnorm" "(" thing "," thing "," thing ")"  */
#line 1856 "miniparser.y"
                          {
			    (yyval.tree) = makeCheckInfnorm((yyvsp[-5].tree), (yyvsp[-3].tree), (yyvsp[-1].tree));
			  }
#line 6808 "miniparser.c"
    break;

  case 319: /* headfunction: "zerodenominators" "(" thing "," thing ")"  */
#line 1860 "miniparser.y"
                          {
			    (yyval.tree) = makeZeroDenominators((yyvsp[-3].tree), (yyvsp[-1].tree));
			  }
#line 6816 "miniparser.c"
    break;

  case 320: /* headfunction: "isevaluable" "(" thing "," thing ")"  */
#line 1864 "miniparser.y"
                          {
			    (yyval.tree) = makeIsEvaluable((yyvsp[-3].tree), (yyvsp[-1].tree));
			  }
#line 6824 "miniparser.c"
    break;

  case 321: /* headfunction: "searchgal" "(" thinglist ")"  */
#line 1868 "miniparser.y"
                          {
			    (yyval.tree) = makeSearchGal((yyvsp[-1].list));
			  }
#line 6832 "miniparser.c"
    break;

  case 322: /* headfunction: "guessdegree" "(" thing "," thing "," thinglist ")"  */
#line 1872 "miniparser.y"
                          {
			    (yyval.tree) = makeGuessDegree(addElement(addElement((yyvsp[-1].list), (yyvsp[-3].tree)), (yyvsp[-5].tree)));
			  }
#line 6840 "miniparser.c"
    break;

  case 323: /* headfunction: "dirtyfindzeros" "(" thing "," thing ")"  */
#line 1876 "miniparser.y"
                          {
			    (yyval.tree) = makeDirtyFindZeros((yyvsp[-3].tree), (yyvsp[-1].tree));
			  }
#line 6848 "miniparser.c"
    break;

  case 324: /* headfunction: "head" "(" thing ")"  */
#line 1880 "miniparser.y"
                          {
			    (yyval.tree) = makeHead((yyvsp[-1].tree));
			  }
#line 6856 "miniparser.c"
    break;

  case 325: /* headfunction: "roundcorrectly" "(" thing ")"  */
#line 1884 "miniparser.y"
                          {
			    (yyval.tree) = makeRoundCorrectly((yyvsp[-1].tree));
			  }
#line 6864 "miniparser.c"
    break;

  case 326: /* headfunction: "readfile" "(" thing ")"  */
#line 1888 "miniparser.y"
                          {
			    (yyval.tree) = makeReadFile((yyvsp[-1].tree));
			  }
#line 6872 "miniparser.c"
    break;

  case 327: /* headfunction: "revert" "(" thing ")"  */
#line 1892 "miniparser.y"
                          {
			    (yyval.tree) = makeRevert((yyvsp[-1].tree));
			  }
#line 6880 "miniparser.c"
    break;

  case 328: /* headfunction: "sort" "(" thing ")"  */
#line 1896 "miniparser.y"
                          {
			    (yyval.tree) = makeSort((yyvsp[-1].tree));
			  }
#line 6888 "miniparser.c"
    break;

  case 329: /* headfunction: "mantissa" "(" thing ")"  */
#line 1900 "miniparser.y"
                          {
			    (yyval.tree) = makeMantissa((yyvsp[-1].tree));
			  }
#line 6896 "miniparser.c"
    break;

  case 330: /* headfunction: "exponent" "(" thing ")"  */
#line 1904 "miniparser.y"
                          {
			    (yyval.tree) = makeExponent((yyvsp[-1].tree));
			  }
#line 6904 "miniparser.c"
    break;

  case 331: /* headfunction: "precision" "(" thing ")"  */
#line 1908 "miniparser.y"
                          {
			    (yyval.tree) = makePrecision((yyvsp[-1].tree));
			  }
#line 6912 "miniparser.c"
    break;

  case 332: /* headfunction: "tail" "(" thing ")"  */
#line 1912 "miniparser.y"
                          {
			    (yyval.tree) = makeTail((yyvsp[-1].tree));
			  }
#line 6920 "miniparser.c"
    break;

  case 333: /* headfunction: "sqrt" "(" thing ")"  */
#line 1916 "miniparser.y"
                          {
			    (yyval.tree) = makeSqrt((yyvsp[-1].tree));
			  }
#line 6928 "miniparser.c"
    break;

  case 334: /* headfunction: "exp" "(" thing ")"  */
#line 1920 "miniparser.y"
                          {
			    (yyval.tree) = makeExp((yyvsp[-1].tree));
			  }
#line 6936 "miniparser.c"
    break;

  case 335: /* headfunction: "_x_" "(" thing ")"  */
#line 1924 "miniparser.y"
                          {
			    (yyval.tree) = makeApply(makeVariable(),addElement(NULL,(yyvsp[-1].tree)));
			  }
#line 6944 "miniparser.c"
    break;

  case 336: /* headfunction: "function" "(" thing ")"  */
#line 1928 "miniparser.y"
                          {
			    (yyval.tree) = makeProcedureFunction((yyvsp[-1].tree));
			  }
#line 6952 "miniparser.c"
    break;

  case 337: /* headfunction: "function" "(" thing "," thing ")"  */
#line 1932 "miniparser.y"
                          {
			    (yyval.tree) = makeSubstitute(makeProcedureFunction((yyvsp[-3].tree)),(yyvsp[-1].tree));
			  }
#line 6960 "miniparser.c"
    break;

  case 338: /* headfunction: "log" "(" thing ")"  */
#line 1936 "miniparser.y"
                          {
			    (yyval.tree) = makeLog((yyvsp[-1].tree));
			  }
#line 6968 "miniparser.c"
    break;

  case 339: /* headfunction: "log2" "(" thing ")"  */
#line 1940 "miniparser.y"
                          {
			    (yyval.tree) = makeLog2((yyvsp[-1].tree));
			  }
#line 6976 "miniparser.c"
    break;

  case 340: /* headfunction: "log10" "(" thing ")"  */
#line 1944 "miniparser.y"
                          {
			    (yyval.tree) = makeLog10((yyvsp[-1].tree));
			  }
#line 6984 "miniparser.c"
    break;

  case 341: /* headfunction: "sin" "(" thing ")"  */
#line 1948 "miniparser.y"
                          {
			    (yyval.tree) = makeSin((yyvsp[-1].tree));
			  }
#line 6992 "miniparser.c"
    break;

  case 342: /* headfunction: "cos" "(" thing ")"  */
#line 1952 "miniparser.y"
                          {
			    (yyval.tree) = makeCos((yyvsp[-1].tree));
			  }
#line 7000 "miniparser.c"
    break;

  case 343: /* headfunction: "tan" "(" thing ")"  */
#line 1956 "miniparser.y"
                          {
			    (yyval.tree) = makeTan((yyvsp[-1].tree));
			  }
#line 7008 "miniparser.c"
    break;

  case 344: /* headfunction: "asin" "(" thing ")"  */
#line 1960 "miniparser.y"
                          {
			    (yyval.tree) = makeAsin((yyvsp[-1].tree));
			  }
#line 7016 "miniparser.c"
    break;

  case 345: /* headfunction: "acos" "(" thing ")"  */
#line 1964 "miniparser.y"
                          {
			    (yyval.tree) = makeAcos((yyvsp[-1].tree));
			  }
#line 7024 "miniparser.c"
    break;

  case 346: /* headfunction: "atan" "(" thing ")"  */
#line 1968 "miniparser.y"
                          {
			    (yyval.tree) = makeAtan((yyvsp[-1].tree));
			  }
#line 7032 "miniparser.c"
    break;

  case 347: /* headfunction: "sinh" "(" thing ")"  */
#line 1972 "miniparser.y"
                          {
			    (yyval.tree) = makeSinh((yyvsp[-1].tree));
			  }
#line 7040 "miniparser.c"
    break;

  case 348: /* headfunction: "cosh" "(" thing ")"  */
#line 1976 "miniparser.y"
                          {
			    (yyval.tree) = makeCosh((yyvsp[-1].tree));
			  }
#line 7048 "miniparser.c"
    break;

  case 349: /* headfunction: "tanh" "(" thing ")"  */
#line 1980 "miniparser.y"
                          {
			    (yyval.tree) = makeTanh((yyvsp[-1].tree));
			  }
#line 7056 "miniparser.c"
    break;

  case 350: /* headfunction: "asinh" "(" thing ")"  */
#line 1984 "miniparser.y"
                          {
			    (yyval.tree) = makeAsinh((yyvsp[-1].tree));
			  }
#line 7064 "miniparser.c"
    break;

  case 351: /* headfunction: "acosh" "(" thing ")"  */
#line 1988 "miniparser.y"
                          {
			    (yyval.tree) = makeAcosh((yyvsp[-1].tree));
			  }
#line 7072 "miniparser.c"
    break;

  case 352: /* headfunction: "atanh" "(" thing ")"  */
#line 1992 "miniparser.y"
                          {
			    (yyval.tree) = makeAtanh((yyvsp[-1].tree));
			  }
#line 7080 "miniparser.c"
    break;

  case 353: /* headfunction: "abs" "(" thing ")"  */
#line 1996 "miniparser.y"
                          {
			    (yyval.tree) = makeAbs((yyvsp[-1].tree));
			  }
#line 7088 "miniparser.c"
    break;

  case 354: /* headfunction: "erf" "(" thing ")"  */
#line 2000 "miniparser.y"
                          {
			    (yyval.tree) = makeErf((yyvsp[-1].tree));
			  }
#line 7096 "miniparser.c"
    break;

  case 355: /* headfunction: "erfc" "(" thing ")"  */
#line 2004 "miniparser.y"
                          {
			    (yyval.tree) = makeErfc((yyvsp[-1].tree));
			  }
#line 7104 "miniparser.c"
    break;

  case 356: /* headfunction: "log1p" "(" thing ")"  */
#line 2008 "miniparser.y"
                          {
			    (yyval.tree) = makeLog1p((yyvsp[-1].tree));
			  }
#line 7112 "miniparser.c"
    break;

  case 357: /* headfunction: "expm1" "(" thing ")"  */
#line 2012 "miniparser.y"
                          {
			    (yyval.tree) = makeExpm1((yyvsp[-1].tree));
			  }
#line 7120 "miniparser.c"
    break;

  case 358: /* headfunction: "D" "(" thing ")"  */
#line 2016 "miniparser.y"
                          {
			    (yyval.tree) = makeDouble((yyvsp[-1].tree));
			  }
#line 7128 "miniparser.c"
    break;

  case 359: /* headfunction: "SG" "(" thing ")"  */
#line 2020 "miniparser.y"
                          {
			    (yyval.tree) = makeSingle((yyvsp[-1].tree));
			  }
#line 7136 "miniparser.c"
    break;

  case 360: /* headfunction: "QD" "(" thing ")"  */
#line 2024 "miniparser.y"
                          {
			    (yyval.tree) = makeQuad((yyvsp[-1].tree));
			  }
#line 7144 "miniparser.c"
    break;

  case 361: /* headfunction: "HP" "(" thing ")"  */
#line 2028 "miniparser.y"
                          {
			    (yyval.tree) = makeHalfPrecision((yyvsp[-1].tree));
			  }
#line 7152 "miniparser.c"
    break;

  case 362: /* headfunction: "DD" "(" thing ")"  */
#line 2032 "miniparser.y"
                          {
			    (yyval.tree) = makeDoubledouble((yyvsp[-1].tree));
			  }
#line 7160 "miniparser.c"
    break;

  case 363: /* headfunction: "TD" "(" thing ")"  */
#line 2036 "miniparser.y"
                          {
			    (yyval.tree) = makeTripledouble((yyvsp[-1].tree));
			  }
#line 7168 "miniparser.c"
    break;

  case 364: /* headfunction: "DE" "(" thing ")"  */
#line 2040 "miniparser.y"
                          {
			    (yyval.tree) = makeDoubleextended((yyvsp[-1].tree));
			  }
#line 7176 "miniparser.c"
    break;

  case 365: /* headfunction: "ceil" "(" thing ")"  */
#line 2044 "miniparser.y"
                          {
			    (yyval.tree) = makeCeil((yyvsp[-1].tree));
			  }
#line 7184 "miniparser.c"
    break;

  case 366: /* headfunction: "floor" "(" thing ")"  */
#line 2048 "miniparser.y"
                          {
			    (yyval.tree) = makeFloor((yyvsp[-1].tree));
			  }
#line 7192 "miniparser.c"
    break;

  case 367: /* headfunction: "nearestint" "(" thing ")"  */
#line 2052 "miniparser.y"
                          {
			    (yyval.tree) = makeNearestInt((yyvsp[-1].tree));
			  }
#line 7200 "miniparser.c"
    break;

  case 368: /* headfunction: "length" "(" thing ")"  */
#line 2056 "miniparser.y"
                          {
			    (yyval.tree) = makeLength((yyvsp[-1].tree));
			  }
#line 7208 "miniparser.c"
    break;

  case 369: /* headfunction: "objectname" "(" thing ")"  */
#line 2060 "miniparser.y"
                          {
			    (yyval.tree) = makeObjectName((yyvsp[-1].tree));
			  }
#line 7216 "miniparser.c"
    break;

  case 370: /* egalquestionmark: "=" "?"  */
#line 2066 "miniparser.y"
                          {
			    (yyval.other) = NULL;
			  }
#line 7224 "miniparser.c"
    break;

  case 371: /* egalquestionmark: %empty  */
#line 2070 "miniparser.y"
                          {
			    (yyval.other) = NULL;
			  }
#line 7232 "miniparser.c"
    break;

  case 372: /* statedereference: "prec" egalquestionmark  */
#line 2077 "miniparser.y"
                          {
			    (yyval.tree) = makePrecDeref();
			  }
#line 7240 "miniparser.c"
    break;

  case 373: /* statedereference: "points" egalquestionmark  */
#line 2081 "miniparser.y"
                          {
			    (yyval.tree) = makePointsDeref();
			  }
#line 7248 "miniparser.c"
    break;

  case 374: /* statedereference: "diam" egalquestionmark  */
#line 2085 "miniparser.y"
                          {
			    (yyval.tree) = makeDiamDeref();
			  }
#line 7256 "miniparser.c"
    break;

  case 375: /* statedereference: "display" egalquestionmark  */
#line 2089 "miniparser.y"
                          {
			    (yyval.tree) = makeDisplayDeref();
			  }
#line 7264 "miniparser.c"
    break;

  case 376: /* statedereference: "verbosity" egalquestionmark  */
#line 2093 "miniparser.y"
                          {
			    (yyval.tree) = makeVerbosityDeref();
			  }
#line 7272 "miniparser.c"
    break;

  case 377: /* statedereference: "showmessagenumbers" egalquestionmark  */
#line 2097 "miniparser.y"
                          {
			    (yyval.tree) = makeShowMessageNumbersDeref();
			  }
#line 7280 "miniparser.c"
    break;

  case 378: /* statedereference: "canonical" egalquestionmark  */
#line 2101 "miniparser.y"
                          {
			    (yyval.tree) = makeCanonicalDeref();
			  }
#line 7288 "miniparser.c"
    break;

  case 379: /* statedereference: "autosimplify" egalquestionmark  */
#line 2105 "miniparser.y"
                          {
			    (yyval.tree) = makeAutoSimplifyDeref();
			  }
#line 7296 "miniparser.c"
    break;

  case 380: /* statedereference: "taylorrecursions" egalquestionmark  */
#line 2109 "miniparser.y"
                          {
			    (yyval.tree) = makeTaylorRecursDeref();
			  }
#line 7304 "miniparser.c"
    break;

  case 381: /* statedereference: "timing" egalquestionmark  */
#line 2113 "miniparser.y"
                          {
			    (yyval.tree) = makeTimingDeref();
			  }
#line 7312 "miniparser.c"
    break;

  case 382: /* statedereference: "fullparentheses" egalquestionmark  */
#line 2117 "miniparser.y"
                          {
			    (yyval.tree) = makeFullParenDeref();
			  }
#line 7320 "miniparser.c"
    break;

  case 383: /* statedereference: "midpointmode" egalquestionmark  */
#line 2121 "miniparser.y"
                          {
			    (yyval.tree) = makeMidpointDeref();
			  }
#line 7328 "miniparser.c"
    break;

  case 384: /* statedereference: "dieonerrormode" egalquestionmark  */
#line 2125 "miniparser.y"
                          {
			    (yyval.tree) = makeDieOnErrorDeref();
			  }
#line 7336 "miniparser.c"
    break;

  case 385: /* statedereference: "rationalmode" egalquestionmark  */
#line 2129 "miniparser.y"
                          {
			    (yyval.tree) = makeRationalModeDeref();
			  }
#line 7344 "miniparser.c"
    break;

  case 386: /* statedereference: "roundingwarnings" egalquestionmark  */
#line 2133 "miniparser.y"
                          {
			    (yyval.tree) = makeSuppressWarningsDeref();
			  }
#line 7352 "miniparser.c"
    break;

  case 387: /* statedereference: "hopitalrecursions" egalquestionmark  */
#line 2137 "miniparser.y"
                          {
			    (yyval.tree) = makeHopitalRecursDeref();
			  }
#line 7360 "miniparser.c"
    break;

  case 388: /* externalproctype: "constant"  */
#line 2144 "miniparser.y"
                          {
			    tempIntPtr = (int *) safeMalloc(sizeof(int));
			    *tempIntPtr = CONSTANT_TYPE;
			    (yyval.integerval) = tempIntPtr;
			  }
#line 7370 "miniparser.c"
    break;

  case 389: /* externalproctype: "function"  */
#line 2150 "miniparser.y"
                          {
			    tempIntPtr = (int *) safeMalloc(sizeof(int));
			    *tempIntPtr = FUNCTION_TYPE;
			    (yyval.integerval) = tempIntPtr;
			  }
#line 7380 "miniparser.c"
    break;

  case 390: /* externalproctype: "object"  */
#line 2156 "miniparser.y"
                          {
			    tempIntPtr = (int *) safeMalloc(sizeof(int));
			    *tempIntPtr = OBJECT_TYPE;
			    (yyval.integerval) = tempIntPtr;
			  }
#line 7390 "miniparser.c"
    break;

  case 391: /* externalproctype: "range"  */
#line 2162 "miniparser.y"
                          {
			    tempIntPtr = (int *) safeMalloc(sizeof(int));
			    *tempIntPtr = RANGE_TYPE;
			    (yyval.integerval) = tempIntPtr;
			  }
#line 7400 "miniparser.c"
    break;

  case 392: /* externalproctype: "integer"  */
#line 2168 "miniparser.y"
                          {
			    tempIntPtr = (int *) safeMalloc(sizeof(int));
			    *tempIntPtr = INTEGER_TYPE;
			    (yyval.integerval) = tempIntPtr;
			  }
#line 7410 "miniparser.c"
    break;

  case 393: /* externalproctype: "string"  */
#line 2174 "miniparser.y"
                          {
			    tempIntPtr = (int *) safeMalloc(sizeof(int));
			    *tempIntPtr = STRING_TYPE;
			    (yyval.integerval) = tempIntPtr;
			  }
#line 7420 "miniparser.c"
    break;

  case 394: /* externalproctype: "boolean"  */
#line 2180 "miniparser.y"
                          {
			    tempIntPtr = (int *) safeMalloc(sizeof(int));
			    *tempIntPtr = BOOLEAN_TYPE;
			    (yyval.integerval) = tempIntPtr;
			  }
#line 7430 "miniparser.c"
    break;

  case 395: /* externalproctype: "list" "of" "constant"  */
#line 2186 "miniparser.y"
                          {
			    tempIntPtr = (int *) safeMalloc(sizeof(int));
			    *tempIntPtr = CONSTANT_LIST_TYPE;
			    (yyval.integerval) = tempIntPtr;
			  }
#line 7440 "miniparser.c"
    break;

  case 396: /* externalproctype: "list" "of" "function"  */
#line 2192 "miniparser.y"
                          {
			    tempIntPtr = (int *) safeMalloc(sizeof(int));
			    *tempIntPtr = FUNCTION_LIST_TYPE;
			    (yyval.integerval) = tempIntPtr;
			  }
#line 7450 "miniparser.c"
    break;

  case 397: /* externalproctype: "list" "of" "object"  */
#line 2198 "miniparser.y"
                          {
			    tempIntPtr = (int *) safeMalloc(sizeof(int));
			    *tempIntPtr = OBJECT_LIST_TYPE;
			    (yyval.integerval) = tempIntPtr;
			  }
#line 7460 "miniparser.c"
    break;

  case 398: /* externalproctype: "list" "of" "range"  */
#line 2204 "miniparser.y"
                          {
			    tempIntPtr = (int *) safeMalloc(sizeof(int));
			    *tempIntPtr = RANGE_LIST_TYPE;
			    (yyval.integerval) = tempIntPtr;
			  }
#line 7470 "miniparser.c"
    break;

  case 399: /* externalproctype: "list" "of" "integer"  */
#line 2210 "miniparser.y"
                          {
			    tempIntPtr = (int *) safeMalloc(sizeof(int));
			    *tempIntPtr = INTEGER_LIST_TYPE;
			    (yyval.integerval) = tempIntPtr;
			  }
#line 7480 "miniparser.c"
    break;

  case 400: /* externalproctype: "list" "of" "string"  */
#line 2216 "miniparser.y"
                          {
			    tempIntPtr = (int *) safeMalloc(sizeof(int));
			    *tempIntPtr = STRING_LIST_TYPE;
			    (yyval.integerval) = tempIntPtr;
			  }
#line 7490 "miniparser.c"
    break;

  case 401: /* externalproctype: "list" "of" "boolean"  */
#line 2222 "miniparser.y"
                          {
			    tempIntPtr = (int *) safeMalloc(sizeof(int));
			    *tempIntPtr = BOOLEAN_LIST_TYPE;
			    (yyval.integerval) = tempIntPtr;
			  }
#line 7500 "miniparser.c"
    break;

  case 402: /* extendedexternalproctype: "void"  */
#line 2230 "miniparser.y"
                          {
			    tempIntPtr = (int *) safeMalloc(sizeof(int));
			    *tempIntPtr = VOID_TYPE;
			    (yyval.integerval) = tempIntPtr;
			  }
#line 7510 "miniparser.c"
    break;

  case 403: /* extendedexternalproctype: externalproctype  */
#line 2236 "miniparser.y"
                          {
			    (yyval.integerval) = (yyvsp[0].integerval);
		          }
#line 7518 "miniparser.c"
    break;

  case 404: /* externalproctypesimplelist: externalproctype  */
#line 2243 "miniparser.y"
                          {
			    (yyval.list) = addElement(NULL, (yyvsp[0].integerval));
			  }
#line 7526 "miniparser.c"
    break;

  case 405: /* externalproctypesimplelist: externalproctype "," externalproctypesimplelist  */
#line 2247 "miniparser.y"
                          {
			    (yyval.list) = addElement((yyvsp[0].list), (yyvsp[-2].integerval));
			  }
#line 7534 "miniparser.c"
    break;

  case 406: /* externalproctypelist: extendedexternalproctype  */
#line 2253 "miniparser.y"
                          {
			    (yyval.list) = addElement(NULL, (yyvsp[0].integerval));
			  }
#line 7542 "miniparser.c"
    break;

  case 407: /* externalproctypelist: "(" externalproctypesimplelist ")"  */
#line 2257 "miniparser.y"
                          {
			    (yyval.list) = (yyvsp[-1].list);
			  }
#line 7550 "miniparser.c"
    break;


#line 7554 "miniparser.c"

      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (myScanner, YY_("syntax error"));
    }

  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval, myScanner);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;
  ++yynerrs;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  YY_ACCESSING_SYMBOL (yystate), yyvsp, myScanner);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (myScanner, YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval, myScanner);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp, myScanner);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

