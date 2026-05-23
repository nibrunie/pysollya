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
#define yyparse         internyyparse
#define yylex           internyylex
#define yyerror         internyyerror
#define yydebug         internyydebug
#define yynerrs         internyynerrs

/* First part of user prologue.  */
#line 71 "internparser.y"

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
#include "internparser.h"

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
#define free parserFree
/* End of the malloc mess */

#define YYERROR_VERBOSE 1
#define YYFPRINTF sollyaFprintf

extern int internyylex(YYSTYPE *lvalp, void *scanner);
extern FILE *internyyget_in(void *scanner);

 void internyyerror(void *myScanner, const char *message) {
   if (!feof(internyyget_in(myScanner))) {
     printMessage(1,SOLLYA_MSG_SYNTAX_ERROR_ENCOUNTERED_WHILE_PARSING,"Warning: %s.\nWill skip input until next semicolon after the unexpected token. May leak memory.\n",message);
     considerDyingOnError();
   }
 }


#line 119 "internparser.c"

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
#ifndef YY_INTERNYY_INTERNPARSER_H_INCLUDED
# define YY_INTERNYY_INTERNPARSER_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int internyydebug;
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
#line 125 "internparser.y"

  doubleNode *dblnode;
  struct entryStruct *association;
  char *value;
  node *tree;
  chain *list;
  int *integerval;
  int count;
  void *other;

#line 665 "internparser.c"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif




int internyyparse (void *myScanner);


#endif /* !YY_INTERNYY_INTERNPARSER_H_INCLUDED  */
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
#define YYFINAL  418
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   8900

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  242
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  46
/* YYNRULES -- Number of rules.  */
#define YYNRULES  406
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  1158

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
       0,   452,   452,   461,   465,   471,   475,   481,   485,   491,
     495,   499,   503,   507,   511,   515,   519,   525,   529,   537,
     542,   547,   555,   559,   565,   569,   575,   582,   586,   592,
     596,   600,   604,   608,   612,   616,   620,   624,   628,   632,
     636,   640,   644,   648,   652,   656,   660,   664,   668,   672,
     676,   680,   684,   692,   696,   700,   704,   708,   712,   716,
     720,   724,   728,   732,   736,   740,   744,   748,   752,   756,
     760,   764,   768,   772,   776,   780,   784,   788,   792,   796,
     802,   807,   812,   816,   821,   826,   830,   834,   841,   845,
     849,   853,   859,   864,   869,   874,   879,   884,   889,   893,
     899,   906,   910,   914,   918,   922,   926,   930,   934,   938,
     942,   946,   950,   954,   958,   962,   966,   972,   976,   980,
     984,   988,   992,   996,  1000,  1004,  1008,  1012,  1016,  1020,
    1024,  1028,  1032,  1038,  1042,  1048,  1052,  1058,  1062,  1068,
    1078,  1082,  1088,  1092,  1096,  1100,  1106,  1115,  1119,  1123,
    1127,  1131,  1135,  1139,  1143,  1149,  1153,  1157,  1161,  1165,
    1169,  1175,  1179,  1183,  1187,  1194,  1198,  1205,  1209,  1213,
    1217,  1224,  1231,  1235,  1241,  1245,  1249,  1256,  1260,  1264,
    1271,  1275,  1279,  1283,  1287,  1291,  1295,  1299,  1303,  1307,
    1311,  1315,  1319,  1323,  1327,  1331,  1335,  1339,  1343,  1347,
    1351,  1355,  1359,  1363,  1367,  1371,  1375,  1379,  1383,  1387,
    1391,  1395,  1399,  1403,  1414,  1418,  1423,  1428,  1433,  1438,
    1442,  1446,  1450,  1454,  1458,  1462,  1466,  1471,  1476,  1481,
    1486,  1490,  1494,  1498,  1504,  1508,  1514,  1518,  1522,  1526,
    1530,  1534,  1538,  1542,  1546,  1552,  1557,  1562,  1567,  1572,
    1577,  1582,  1590,  1594,  1598,  1602,  1608,  1612,  1616,  1622,
    1626,  1630,  1636,  1640,  1644,  1648,  1652,  1656,  1662,  1666,
    1670,  1674,  1678,  1682,  1686,  1690,  1694,  1699,  1703,  1707,
    1711,  1715,  1719,  1723,  1727,  1731,  1735,  1739,  1743,  1747,
    1751,  1755,  1759,  1763,  1767,  1771,  1775,  1779,  1783,  1787,
    1791,  1795,  1799,  1803,  1807,  1811,  1815,  1819,  1823,  1827,
    1831,  1835,  1839,  1843,  1847,  1851,  1855,  1859,  1863,  1867,
    1871,  1875,  1879,  1883,  1887,  1891,  1895,  1899,  1903,  1907,
    1911,  1915,  1919,  1923,  1927,  1931,  1935,  1939,  1943,  1947,
    1951,  1955,  1959,  1963,  1967,  1971,  1975,  1979,  1983,  1987,
    1991,  1995,  1999,  2003,  2007,  2011,  2015,  2019,  2023,  2027,
    2031,  2035,  2039,  2043,  2047,  2051,  2055,  2059,  2063,  2069,
    2074,  2080,  2084,  2088,  2092,  2096,  2100,  2104,  2108,  2112,
    2116,  2120,  2124,  2128,  2132,  2136,  2140,  2147,  2153,  2159,
    2165,  2171,  2177,  2183,  2189,  2195,  2201,  2207,  2213,  2219,
    2225,  2233,  2239,  2246,  2250,  2256,  2260
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

#define YYPACT_NINF (-996)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-133)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    1316,   -17,  -996,  -996,  -996,  -996,  -996,  -996,  -996,   218,
    -996,  6776,  4184,  7454,  6776,  8484,    -2,    -2,     5,   106,
     148,   170,   182,   201,   209,   226,   286,   288,   293,   337,
     354,   380,   386,   393,   397,   426,   442,   470,   474,   479,
     489,   498,   503,   507,   517,   522,   526,   550,   569,   603,
     631,   638,   641,   643,   655,   667,   690,   695,   700,    13,
      62,   120,   130,   387,   436,    44,   497,   509,   531,   706,
     632,   645,   728,   730,   741,   742,  -996,  -996,  -996,  -996,
    -996,  -996,  -996,  -996,  -996,  -996,  -996,  -996,  -996,  -996,
    -996,  -996,  -996,  -996,  6776,  -996,  -996,  -996,  -996,  -996,
    -996,  -996,  -996,   744,   747,   753,   780,   782,   789,   795,
     799,   806,   817,   830,   832,   864,   869,   872,   873,   880,
     882,   886,   888,   893,   896,   903,   904,   913,   926,   930,
     939,   954,   964,   965,   976,   979,   981,   982,   986,   992,
    1008,  1021,  1026,  1036,  1040,  1053,  1058,  1062,  1063,  1069,
    1070,  1075,  1076,  1078,  1091,  1104,  1106,  1107,  1116,  1147,
    1150,  1152,  1156,  1162,  1167,  1173,  1182,  1183,  1184,  1195,
    1199,  1200,  1202,  1207,  1210,  1215,  6776,    58,  -996,   121,
    6776,  1228,  1233,  1236,  1237,  1244,  -996,  1247,  1258,   195,
    1263,   542,  -996,  2511,   451,  -996,  -996,   485,   343,  -996,
     529,  -996,   151,  -996,   678,     0,  1299,  8484,   657,  -996,
      17,  -996,  -996,  -996,  -996,  -996,  -996,  -996,  4626,  4390,
    6776,  1264,   818,   818,   818,   818,   818,   818,   172,   818,
     818,   818,   818,   818,   818,   818,   818,   818,   121,    32,
    -996,    22,  4832,   551,   774,     0,  1270,  -996,  -996,  -996,
    6776,  6776,  6776,  6776,  6776,  6776,  6776,  6776,  6776,  6776,
    6776,  6776,  6776,  6776,  6776,  6776,  6776,  6776,  6776,  6776,
    6776,  6776,  6776,  6776,  6776,  6776,  6776,  6776,  6776,  6776,
    6776,  6776,  6776,  6776,  6776,  6776,  6776,  6776,  6776,  6776,
    6776,  5038,  -996,  5038,  -996,  5038,  -996,  5038,  -996,  5038,
    -996,  5038,  -996,  6776,  5038,  -996,  5038,  -996,  5038,  -996,
    5038,  -996,  3945,  5038,  -996,  5038,  -996,  5038,  -996,  5038,
    -996,  5038,  -996,  5038,  -996,   712,   473,  6776,  6776,  6776,
    6776,  6776,   652,   790,  6776,  6776,  6776,  6776,  6776,  6776,
    6776,  6776,  6776,  6776,  6776,  6776,  6776,  6776,  6776,  6776,
    6776,  6776,  6776,  6776,  6776,  6776,  6776,  6776,  6776,  6776,
    6776,  6776,  6776,  6776,  6776,  6776,  6776,  6776,  6776,  6776,
    6776,  6776,  6776,  6776,  6776,  6776,  6776,    10,  6776,  6776,
    6776,  6776,  6776,  6776,  6776,  6776,  6776,  6776,  6776,  6776,
    6776,  6776,  6776,  6776,  6776,  6776,  6776,  6776,  6776,  6776,
    -996,    -5,   484,  -996,   836,   585,   206,   -18,  6776,   842,
    6776,   850,   861,  6776,   103,  -996,  1258,  5274,  -996,  -996,
    -996,   970,  -996,   815,    91,  3706,   922,  -996,  -996,  6776,
    6776,  -996,  6776,  7454,  7454,  6776,  6776,  7454,  7012,  7248,
    7454,  7454,  7454,  7454,  7454,  7454,  7454,  -996,  7660,  7866,
    6776,  1105,  8278,  8072,  -996,  1019,  1269,  1272,   712,   712,
    1120,  1280,  1110,  1157,   712,   168,  -996,  -996,  6776,  6776,
    -996,  -996,  -996,    41,    46,    48,    50,    52,    56,    64,
      66,    69,    71,    80,    84,    86,    88,    94,    99,   102,
     104,   108,   116,   118,   122,   124,   127,   132,   136,   138,
     140,   146,   176,   189,   193,   197,   351,   368,   373,   376,
     382,   404,   407,   410,  -996,   134,   593,   863,   983,  1017,
    1138,   435,  1143,  1151,  1153,  1160,  1239,  1164,  1169,  1177,
    1181,  1186,  1198,  6776,   438,   440,   282,   724,    34,  -996,
    -996,   781,   449,   456,   458,   783,   785,   787,   791,   460,
     463,   468,   793,   798,   800,   809,   816,   822,   824,   826,
     828,   834,   472,   477,   481,   491,   493,  1242,  1285,   496,
     501,  1286,   505,   838,   511,   513,   515,  1293,  1298,   524,
     530,   840,  1300,   851,  1204,  1241,   856,   874,   878,   892,
     901,   905,   914,   916,   918,   920,   929,   931,   933,   942,
    1301,   944,   946,   956,   960,  1302,   968,   973,  3945,  6776,
    6776,  1277,  -996,  -996,  -996,   121,  3945,   533,  1303,   535,
    1310,  1314,    36,   395,    70,  1321,  -996,  -996,   543,  1320,
    -996,  3945,  -996,  -996,    91,  1100,   712,   712,  -996,     0,
       0,   712,   712,  1299,  7454,  1299,  7454,  1299,  1299,  1299,
     657,   657,   657,   657,   657,  8484,  8484,  -996,  8484,  8484,
    -996,   153,   384,  8484,  -996,  8484,  8484,  -996,  -996,  6776,
    6776,  5510,  1339,  -996,  5716,  1281,  1337,   769,   776,  -996,
    -996,  -996,  -996,  -996,  -996,  -996,  -996,  -996,  -996,  -996,
    -996,  -996,  -996,  -996,  -996,  -996,  -996,  -996,  -996,  -996,
    -996,  -996,  -996,  -996,  -996,  -996,  -996,  -996,  -996,  -996,
    -996,  -996,  -996,  -996,  -996,  -996,  -996,  -996,  -996,  -996,
    -996,  -996,   537,  -996,  6776,  -996,  -996,  6776,  6776,  -996,
    6776,  6776,  -996,  -996,  -996,  6776,  6776,  6776,  6776,  -996,
    -996,  -996,  6776,  6776,  6776,  6776,  6776,  6776,  6776,  6776,
    6776,  6776,  -996,  -996,  -996,  -996,  -996,  -996,  -996,  -996,
    -996,  1326,  1328,  6776,  -996,  -996,  -996,  -996,  -996,  -996,
    -996,  6776,  1329,  6776,    16,    18,  1349,  6776,  6776,  6776,
    6776,  6776,  6776,  6776,  6776,  6776,  6776,  6776,  6776,  6776,
    -996,  6776,  6776,  6776,  6776,  -996,  6776,  6776,  1229,     2,
      -7,  6776,  -996,  -996,  -996,  -996,  -996,  6776,  6776,  -996,
    6776,  1332,   970,  -996,  1555,    70,  -996,  -996,  -996,  -996,
    1299,  1299,  -996,  -996,  -996,  -996,  -996,  5952,  -996,  -996,
    -996,   545,   547,  -996,  1348,  1427,   712,  1434,  -996,  -996,
    -996,     7,  -996,   991,   996,   552,  1006,  1010,  1015,  1020,
    1022,   554,   565,   567,   577,   582,   584,   587,  1032,  1044,
     589,  6158,  6364,  1437,  1054,  6570,   595,  1512,  1513,  1515,
    1516,  1511,  1518,  1057,   597,   599,   601,   605,   612,   617,
     629,   636,   647,  1059,  1061,  1519,  1066,   649,   651,  1073,
     653,  3945,  3945,  6776,   712,  1085,   659,   664,  1521,  -996,
    6776,  -996,  -170,  2750,  1794,  -996,  1523,  -996,  -996,  -996,
    6776,  -996,  6776,  2033,  6776,  6776,  -996,  6776,  6776,  6776,
    6776,  6776,  -996,  -996,  -996,  -996,  -996,  -996,  -996,  6776,
    6776,  -996,  6776,   712,  6776,   712,  -996,  6776,  6776,   712,
    -996,  -996,  -996,  -996,  -996,  6776,  -996,  6776,  -996,  -996,
    -996,  -996,  -996,  -996,  -996,  -996,  -996,  6776,  6776,  -996,
    6776,  -996,  -996,  6776,  -996,  -996,  -996,   -15,   202,  -996,
    -996,    70,   275,  6776,  -996,  6776,  -996,  -118,  6776,  -996,
     -88,  2989,  -996,   712,   669,  6776,  -996,   -37,  3228,  1531,
    1090,  1092,   671,  1543,   702,   708,  1557,   710,   712,   712,
    1095,   712,   715,  1103,  1108,  1114,   740,  1558,  6776,  3945,
    1318,  -996,  -996,  -996,  -996,  -996,  -996,  -996,  -996,  1336,
    -996,  -996,  1526,  2272,    91,   421,   580,  6776,  -996,   848,
    6776,  -996,  6776,  -996,    63,  -996,  1189,  6776,  -996,  6776,
    -996,   339,  -996,  6776,  6776,  -996,  -996,  -996,  -996,  -996,
    -996,  6776,  -996,  6776,  6776,  6776,  -996,  -996,     4,  -996,
    1554,  1561,  1350,  1549,  6776,  -996,   391,  3467,  -996,    91,
      91,  1203,    91,  1211,  1214,  6776,  -996,    91,  1218,  1223,
    6776,  -996,  1572,  1573,  1117,  1121,  1127,  1130,  3945,  1318,
    -996,  -996,  -996,  -996,  -996,  -996,  -996,  -996,  1115,  1226,
    6776,  -996,  6776,  -996,   465,  -996,  -996,    91,  -996,    91,
      91,  1240,  -996,    91,    91,  1243,  -996,  -996,  6776,  6776,
    6776,  6776,  -996,  -996,  1574,    91,  1246,  1248,  6776,  -996,
    -996,  -996,  -996,    91,  -996,  -996,    91,  1575,   748,  1576,
    1136,  -996,  -996,    91,    91,  1251,  -996,  -996,  -996,  -996,
    -996,  6776,  -996,  -996,    91,  1577,  -996,  -996
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int16 yydefact[] =
{
       0,     0,   245,   246,   247,   248,   249,   250,   251,   215,
     213,     0,     0,     0,     0,     0,   161,   162,     0,     0,
     210,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   205,   206,   208,   207,   211,   212,   209,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   370,
     370,   370,   370,   370,   370,   370,   370,   370,   370,     0,
     370,   370,   370,   370,   370,   370,   180,   181,   182,   183,
     184,   185,   186,   187,   188,   189,   190,   191,   192,   193,
     194,   195,   197,   198,     0,   200,   199,   201,   202,   203,
     204,    53,    54,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     5,     6,
       0,     0,     0,     0,     0,     0,   196,     0,     0,     0,
      55,     0,     2,     0,     0,     9,    85,    90,     0,    88,
       0,    86,   133,   140,   226,   142,   147,     0,   155,   165,
     174,   214,   219,   220,   221,   222,   225,     4,     0,     0,
       0,   215,   370,   370,   370,   370,   370,   370,   370,   370,
     370,   370,   370,   370,   370,   370,   370,   370,     0,     0,
     226,   174,     0,     0,     0,   145,     0,   167,   163,   164,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   371,     0,   372,     0,   373,     0,   374,     0,
     375,     0,   376,     0,     0,   377,     0,   378,     0,   379,
       0,   380,     0,     0,   381,     0,   382,     0,   383,     0,
     385,     0,   384,     0,   386,     0,   140,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      14,     0,     0,    16,     0,     0,   135,     0,     0,     0,
       0,     0,     0,     0,     0,   232,     0,     0,     1,     7,
       8,     0,    13,     0,     0,     0,     0,     3,    91,     0,
       0,    89,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   166,     0,     0,
       0,     0,     0,     0,   218,     0,     0,     0,    92,    93,
       0,   223,     0,     0,   256,     0,   253,   261,     0,     0,
     264,   263,   262,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   369,   101,   102,   103,   104,   105,
     106,     0,   107,   108,   109,   110,     0,   111,   112,   113,
     115,   114,   116,     0,     0,     0,     0,     0,     0,   270,
     271,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   224,   137,   138,     0,     0,     0,     0,     0,
       0,     0,     0,    27,     0,     0,    87,    57,     0,    27,
      26,    22,    10,    12,     0,    24,    98,    99,   134,   143,
     144,    96,    97,   148,     0,   150,     0,   151,   154,   149,
     158,   159,   160,   156,   157,     0,     0,   168,     0,     0,
     169,     0,   227,     0,   178,     0,     0,   175,   217,     0,
       0,     0,   227,   252,     0,     0,     0,     0,     0,   332,
     333,   334,   337,   338,   339,   340,   341,   342,   343,   344,
     345,   346,   347,   348,   349,   350,   351,   352,   353,   354,
     355,   356,   357,   358,   360,   359,   361,   362,   363,   364,
     365,   366,   323,   326,   327,   331,   328,   329,   330,   324,
     281,   233,     0,   141,   234,   268,   273,     0,     0,   269,
       0,     0,   280,   282,   283,     0,     0,     0,     0,   288,
     289,   290,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   367,   368,   267,   266,   265,   277,   278,   302,
     301,    58,    74,     0,    62,    63,    64,    65,    66,    67,
      68,     0,    70,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     315,     0,     0,     0,     0,   320,     0,     0,    17,     0,
       0,     0,   136,    15,   325,   216,    75,     0,     0,   335,
       0,     0,     0,     6,     0,     0,    56,    23,    11,    25,
     152,   153,   172,   170,   173,   171,   146,     0,   179,   177,
     176,     0,     0,   231,     0,     0,   257,     0,   254,   259,
     260,     0,   235,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   139,     0,     0,     0,     0,    28,
       0,    32,     0,     0,     0,   228,     0,    94,    95,   230,
       0,   255,     0,     0,     0,     0,   272,     0,     0,     0,
       0,     0,   291,   292,   293,   294,   295,   296,   297,     0,
       0,   300,     0,    59,     0,    76,    61,     0,     0,    71,
      73,    79,    80,    81,    82,     0,   303,     0,   305,   306,
     307,   308,   309,   310,   311,   312,   313,     0,     0,   316,
       0,   318,   319,     0,   322,    18,    21,     0,     0,    84,
     336,     0,     0,     0,    29,     0,    31,     0,     0,    40,
       0,     0,   229,   258,     0,     0,   243,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    60,    77,
       0,    72,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   401,   387,   388,   389,   390,   391,   392,   393,     0,
     402,   405,     0,     0,     0,     0,     0,     0,    30,     0,
       0,    37,     0,    39,     0,   244,     0,     0,   241,     0,
     239,     0,   274,     0,     0,   284,   285,   286,   287,   298,
     299,     0,   276,     0,     0,     0,   317,   321,     0,    19,
     403,     0,     0,     0,     0,    48,     0,     0,    36,     0,
       0,     0,     0,     0,     0,     0,    38,     0,     0,     0,
       0,   237,     0,     0,     0,     0,     0,     0,     0,     0,
     406,   394,   395,   396,   397,   398,   399,   400,     0,     0,
       0,    45,     0,    47,     0,    33,    35,     0,    44,     0,
       0,     0,   242,     0,     0,     0,   275,   279,     0,     0,
       0,     0,    20,   404,     0,     0,     0,     0,     0,    46,
      34,    41,    43,     0,   240,   238,     0,     0,     0,     0,
       0,    83,    52,     0,     0,     0,    42,   236,    69,   304,
      78,     0,    49,    51,     0,     0,    50,   314
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -996,  -996,  -996,  -618,   164,    38,  -996,  -996,  -420,  -619,
    -996,  -419,  1175,  -996,  -996,  -996,  -996,  -996,  -996,    95,
     977,  -996,  -996,   -11,  1500,    98,    -6,  -427,    -8,   859,
      15,   114,   871,  -996,  -996,  -996,  -996,  -996,  -996,  -996,
    8663,  -996,  -995,   500,   510,  -996
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,   191,   192,   193,   422,   423,   400,   403,   424,   425,
     426,   625,   415,   195,   196,   197,   198,   199,   200,   201,
     405,   615,   406,   202,   203,   240,   205,   206,   207,   208,
     209,   241,   723,   724,   211,   212,   465,   213,   214,   215,
     292,   216,  1020,  1021,  1061,  1022
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
     239,   244,   630,   246,   217,   634,   814,   245,   248,   249,
     643,   645,   647,   648,   649,  1060,   819,   250,   437,   912,
     584,   433,   434,   438,   433,   434,   867,   439,   869,   291,
     247,   450,   433,   434,   433,   434,   450,   440,   194,    16,
      17,   433,   434,   433,   434,   461,   451,   729,   419,   809,
     420,   462,   452,   730,   679,   810,   303,   452,   585,   680,
     304,   681,   453,   682,   868,   683,   870,   453,   402,   684,
     973,   433,   434,   433,   434,   433,   434,   685,   293,   686,
     433,   434,   687,   325,   688,   433,   434,   433,   434,   433,
     434,   433,   434,   689,  1060,   433,   434,   690,   204,   691,
     419,   692,   420,   433,   434,   433,   434,   693,   433,   434,
     433,   434,   694,   623,   210,   695,   624,   696,   251,   433,
     434,   697,  1027,   433,   434,   433,   434,   433,   434,   698,
     419,   699,   420,   433,   434,   700,   295,   701,   433,   434,
     702,   433,   434,   433,   434,   703,   297,   433,   434,   704,
     404,   705,  1030,   706,  -117,   433,   434,   433,   434,   707,
     252,   433,   434,   433,   434,   401,   433,   434,   826,   407,
     432,   433,   434,   433,   434,   433,   434,   433,   434,   433,
     434,   419,   253,   420,   303,   433,   434,   674,   460,   708,
     433,   434,   433,   434,   254,   903,   675,   904,   616,   676,
    1008,  1009,   709,  1037,   608,   416,   710,   893,   458,   459,
     711,   817,   441,   255,  1010,   433,   434,   820,   892,   821,
    1088,   256,   447,   913,   178,   613,   813,   614,   433,   434,
     218,   464,   433,   434,   219,   220,   433,   434,   257,   473,
     474,   475,   476,   477,   478,   479,   480,   481,   482,   483,
     484,   485,   486,   487,   488,   489,   490,   491,   492,   493,
     494,   495,   496,   497,   498,   499,   500,   501,   502,   503,
     504,   505,   506,   507,   508,   509,   510,   511,   512,   513,
     515,   419,   516,   420,   517,   981,   518,   178,   519,   813,
     520,   204,   521,   522,   988,   523,  1024,   524,   258,   525,
     259,   727,   527,  1075,   528,   260,   529,   210,   530,   419,
     531,   420,   532,   455,   433,   434,   534,   535,   536,   537,
     538,   433,   434,   541,   542,   543,   544,   545,   546,   547,
     548,   549,   550,   551,   552,   553,   554,   555,   556,   557,
     558,   559,   560,   561,   562,   563,   564,   565,   566,   261,
     526,   569,   570,  1023,   572,   573,   574,   575,   576,   429,
     430,   579,   580,   581,   712,   583,   262,   586,   587,   588,
     589,   590,   591,   592,   593,   594,   595,   596,   597,   598,
     599,   713,   601,   602,   603,   604,   714,   606,   607,   715,
     433,   434,   263,   899,   902,   716,   827,   617,   264,   619,
    -100,  -100,   622,   299,  1067,   265,   628,   433,   434,   266,
     204,   811,   433,   434,   812,   433,   434,   717,   636,   637,
     718,   433,   434,   719,   641,   642,   210,   639,   640,  1011,
    1012,  1013,  1014,  1015,  1016,  1017,  1018,  1019,   267,   661,
     656,   659,  1069,   433,   434,   666,   433,   434,   720,   433,
     434,   725,   301,   726,   268,   567,   568,   677,   678,   571,
     433,   434,   732,   657,   660,   577,   578,   664,   667,   733,
     582,   734,   427,   739,   433,   434,   740,   433,   434,   433,
     434,   741,   269,   977,   980,   752,   270,   600,   433,   434,
     753,   271,   605,   987,   754,   433,   434,   433,   434,   433,
     434,   272,   433,   434,   755,   428,   756,   433,   434,   759,
     273,   433,   434,   306,   760,   274,   433,   434,   762,   275,
     433,   434,   722,   204,   764,   308,   765,   638,   766,   276,
     433,   434,   433,   434,   277,   433,   434,   769,   278,   210,
     433,   434,   418,   770,   433,   434,   804,   310,   806,   431,
     433,   434,   433,   434,   433,   434,   816,   419,   907,   420,
     908,  1034,   279,   433,   434,   916,   466,   922,  1041,   433,
     434,   841,   433,   434,   433,   434,   433,   434,   923,  1080,
     924,   280,   433,   434,   433,   434,   433,   434,   632,   633,
     925,   433,   434,   433,   434,   926,   533,   927,   799,   800,
     928,  1070,   931,  1066,   433,   434,   433,   434,   940,   419,
     948,   420,   949,  -118,   950,   281,   433,   434,   951,   433,
     434,   433,   434,   433,   434,   952,   433,   434,   433,   434,
     953,  1100,   433,   434,   433,   434,   433,   434,   433,   434,
     433,   434,   954,   282,   433,   434,   798,  1104,   313,   955,
     283,   433,   434,   284,   803,   285,   433,   434,   831,   832,
     956,   315,   961,   836,   962,   539,   964,   286,   433,   434,
     822,   823,   969,   824,   825,   433,   434,   970,   828,   287,
     829,   830,  1035,   419,  1045,   420,   433,   434,   433,   434,
     433,   434,   433,   434,   435,   436,   609,   610,   433,   434,
     448,   449,   288,   433,   434,  1128,   204,   289,   433,   434,
     433,   434,   290,   722,   204,  1047,   843,   844,   312,   845,
     846,  1048,   210,  1050,   847,   848,   849,   850,  1052,   204,
     210,   851,   852,   853,   854,   855,   856,   857,   858,   859,
     860,   433,   434,   728,   317,   210,   319,   433,   434,   433,
     434,   433,   434,  1056,   433,   434,   327,   321,   323,   328,
     864,  1149,   866,   433,   434,   329,   834,   873,   874,   875,
     876,   877,   878,   879,   880,   881,   882,   883,   884,   433,
     434,   886,   887,   888,   839,   889,   890,   433,   434,   467,
     894,   840,   330,   468,   331,   469,   895,   896,   818,   897,
     731,   332,   735,   540,   736,   612,   737,   333,   433,   434,
     738,   334,   742,   433,   434,   433,   434,   743,   335,   744,
     433,   434,   433,   434,   433,   434,   433,   434,   745,   336,
     433,   434,   433,   434,   460,   746,   631,   433,   434,   433,
     434,   747,   337,   748,   338,   749,   611,   750,   433,   434,
     933,   935,   618,   751,   939,   433,   434,   763,   863,   771,
     620,   433,   434,   433,   434,   433,   434,   433,   434,  1072,
     773,   621,   872,   433,   434,   776,   339,   433,   434,   433,
     434,   340,   967,  -119,   341,   342,   885,   433,   434,   972,
     433,   434,   343,   777,   344,   433,   434,   778,   345,   983,
     346,   984,   433,   434,   990,   347,   991,   992,   348,   994,
     995,   779,   204,   433,   434,   349,   350,   433,   434,   997,
     780,   998,   906,   999,   781,   351,  1000,  1001,   210,   965,
     966,   433,   434,   782,  1002,   783,  1003,   784,   352,   785,
     433,   434,   353,   635,   433,   434,  1004,  1005,   786,  1006,
     787,   354,   788,   433,   434,   433,   434,   433,   434,   433,
     434,   789,  1025,   791,  1026,   792,   355,  1029,   433,   434,
     433,   434,   433,   434,  1036,   793,   356,   357,   901,   794,
     629,   433,   434,   433,   434,   433,   434,   796,   358,   204,
     204,   359,   797,   360,   361,   433,   434,  1058,   362,   433,
     434,   204,   204,  -120,   363,   210,   210,   433,   434,   989,
     914,   204,   433,   434,   993,   915,  1071,   210,   210,  1073,
     364,  1074,   433,   434,   996,   917,  1078,   210,  1079,   918,
     433,   434,   668,   365,   919,   433,   434,  -121,   366,   920,
    1084,   921,  1085,  1086,  1087,   433,   434,  1059,   367,   433,
     434,   929,   368,  1099,   433,   434,   433,   434,  1007,   433,
     434,   433,   434,   930,  1111,   369,   974,   976,   979,  1115,
     370,   433,   434,   937,   371,   372,   947,   986,   957,   204,
     958,   373,   374,   433,   434,   960,   204,   375,   376,  1126,
     377,  1127,   963,   433,   434,   210,   433,   434,   433,   434,
     433,   434,   210,   378,   968,   433,   434,   204,  1138,  1043,
    1140,  1044,   433,   434,  1051,   662,   379,  1145,   380,   381,
     672,   204,  1053,   210,   433,   434,  1122,  1054,   382,   433,
     434,   433,   434,  1055,   433,   434,  1118,   210,  1082,  1083,
    1119,  1028,   433,   434,  1031,  1033,  1120,   433,   434,  1121,
     514,  1038,  1040,   433,   434,  1151,   433,   434,  -122,   383,
     433,   434,   384,  -123,   385,   204,   433,   434,   386,   433,
     434,  -124,   673,  -125,   387,   433,   434,   433,   434,   388,
    -126,   210,   433,   434,  -127,   389,   204,  1065,  1068,  -128,
     433,   434,   433,   434,   390,   391,   392,  -129,  1076,   433,
     434,  -131,   210,   433,   434,  1081,  -130,   393,   433,   434,
    1077,   394,   395,  1137,   396,  1139,   433,   434,  -132,   397,
     433,   434,   398,   774,  1107,   433,   434,   399,   433,   434,
    1101,  1103,  1109,  1105,  1106,  1110,  1108,   433,   434,  1113,
     408,  1112,   433,   434,  1114,   409,  1155,  1125,   410,   411,
     433,   434,   721,   433,   434,   757,   412,   433,   434,   413,
     775,  1133,   433,   434,  1136,   433,   434,  1143,  1129,  1144,
     414,  1130,  1154,  1131,  1132,   417,   218,  1134,  1135,   433,
     434,   669,   433,   434,   670,   433,   434,   433,   434,  1142,
     433,   434,   671,   801,   470,   471,   472,  1146,   758,   761,
    1147,   650,   651,   652,   653,   654,   767,  1152,  1153,   433,
     434,   768,   837,   772,   790,   795,   805,     1,  1156,     2,
       3,     4,     5,     6,     7,     8,     9,    10,    11,   807,
      12,   442,   443,   808,   815,   444,    13,   421,    14,   812,
     445,   446,  1011,  1012,  1013,  1014,  1015,  1016,  1017,  1018,
    1019,   827,   838,   861,    15,   862,   865,    16,    17,   871,
     898,   909,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    68,    69,    70,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    90,    91,    92,    93,    94,   891,
      95,    96,    97,    98,    99,   100,   910,   101,   102,   911,
     936,   103,   104,   105,   106,   107,   108,   109,   110,   111,
     112,   113,   114,   115,   116,   117,   118,   119,   120,   121,
     122,   123,   124,   125,   126,   127,   128,   129,   130,   131,
     132,   133,   134,   135,   136,   137,   138,   139,   140,   141,
     142,   143,   144,   145,   146,   147,   148,   149,   150,   151,
     152,   153,   154,   155,   156,   157,   158,   159,   160,   161,
     162,   163,   164,   165,   166,   167,   168,   169,   170,   171,
     172,   173,   174,   175,   176,   941,   942,   177,   943,   944,
     945,   946,   959,   178,   971,   179,   982,   180,   181,   182,
     183,   184,   185,   186,  1042,   187,  1012,  1013,  1014,  1015,
    1016,  1017,  1018,  1019,   188,   189,  1046,   190,     2,     3,
       4,     5,     6,     7,     8,     9,    10,    11,  1063,    12,
    1049,  1057,  1062,  1089,  1090,    13,  1098,    14,  1091,  1092,
    1093,  1094,  1095,  1096,  1097,  1116,  1117,  1141,  1148,  1150,
    1157,   626,   802,    15,   326,   842,    16,    17,  1124,  1123,
       0,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,    68,    69,    70,    71,    72,    73,    74,    75,    76,
      77,    78,    79,    80,    81,    82,    83,    84,    85,    86,
      87,    88,    89,    90,    91,    92,    93,    94,     0,    95,
      96,    97,    98,    99,   100,     0,   101,   102,     0,     0,
     103,   104,   105,   106,   107,   108,   109,   110,   111,   112,
     113,   114,   115,   116,   117,   118,   119,   120,   121,   122,
     123,   124,   125,   126,   127,   128,   129,   130,   131,   132,
     133,   134,   135,   136,   137,   138,   139,   140,   141,   142,
     143,   144,   145,   146,   147,   148,   149,   150,   151,   152,
     153,   154,   155,   156,   157,   158,   159,   160,   161,   162,
     163,   164,   165,   166,   167,   168,   169,   170,   171,   172,
     173,   174,   175,   176,     0,     0,   177,     0,     0,     0,
       0,     0,   178,   419,   179,   420,   180,   181,   182,   183,
     184,   185,   186,     0,   187,     0,     0,     0,     0,     0,
       0,     0,   421,   188,   189,   900,   190,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,     0,    12,     0,
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
      97,    98,    99,   100,     0,   101,   102,     0,     0,   103,
     104,   105,   106,   107,   108,   109,   110,   111,   112,   113,
     114,   115,   116,   117,   118,   119,   120,   121,   122,   123,
     124,   125,   126,   127,   128,   129,   130,   131,   132,   133,
     134,   135,   136,   137,   138,   139,   140,   141,   142,   143,
     144,   145,   146,   147,   148,   149,   150,   151,   152,   153,
     154,   155,   156,   157,   158,   159,   160,   161,   162,   163,
     164,   165,   166,   167,   168,   169,   170,   171,   172,   173,
     174,   175,   176,     0,     0,   177,     0,     0,     0,     0,
       0,   178,   419,   179,   420,   180,   181,   182,   183,   184,
     185,   186,     0,   187,     0,     0,     0,     0,     0,     0,
       0,   421,   188,   189,   978,   190,     2,     3,     4,     5,
       6,     7,     8,     9,    10,    11,     0,    12,     0,     0,
       0,     0,     0,    13,     0,    14,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    15,     0,     0,    16,    17,     0,     0,     0,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    68,
      69,    70,    71,    72,    73,    74,    75,    76,    77,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    87,    88,
      89,    90,    91,    92,    93,    94,     0,    95,    96,    97,
      98,    99,   100,     0,   101,   102,     0,     0,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   131,   132,   133,   134,
     135,   136,   137,   138,   139,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150,   151,   152,   153,   154,
     155,   156,   157,   158,   159,   160,   161,   162,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   172,   173,   174,
     175,   176,     0,     0,   177,     0,     0,     0,     0,     0,
     178,   419,   179,   420,   180,   181,   182,   183,   184,   185,
     186,     0,   187,     0,     0,     0,     0,     0,     0,     0,
     421,   188,   189,   985,   190,     2,     3,     4,     5,     6,
       7,     8,     9,    10,    11,     0,    12,     0,     0,     0,
       0,     0,    13,     0,    14,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      15,     0,     0,    16,    17,     0,     0,     0,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    68,    69,
      70,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    91,    92,    93,    94,     0,    95,    96,    97,    98,
      99,   100,     0,   101,   102,     0,     0,   103,   104,   105,
     106,   107,   108,   109,   110,   111,   112,   113,   114,   115,
     116,   117,   118,   119,   120,   121,   122,   123,   124,   125,
     126,   127,   128,   129,   130,   131,   132,   133,   134,   135,
     136,   137,   138,   139,   140,   141,   142,   143,   144,   145,
     146,   147,   148,   149,   150,   151,   152,   153,   154,   155,
     156,   157,   158,   159,   160,   161,   162,   163,   164,   165,
     166,   167,   168,   169,   170,   171,   172,   173,   174,   175,
     176,     0,     0,   177,     0,     0,     0,     0,     0,   178,
     419,   179,   420,   180,   181,   182,   183,   184,   185,   186,
       0,   187,     0,     0,     0,     0,     0,     0,     0,   421,
     188,   189,  1064,   190,     2,     3,     4,     5,     6,     7,
       8,     9,    10,    11,     0,    12,     0,     0,     0,     0,
       0,    13,     0,    14,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    15,
       0,     0,    16,    17,     0,     0,     0,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    68,    69,    70,
      71,    72,    73,    74,    75,    76,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    89,    90,
      91,    92,    93,    94,     0,    95,    96,    97,    98,    99,
     100,     0,   101,   102,     0,     0,   103,   104,   105,   106,
     107,   108,   109,   110,   111,   112,   113,   114,   115,   116,
     117,   118,   119,   120,   121,   122,   123,   124,   125,   126,
     127,   128,   129,   130,   131,   132,   133,   134,   135,   136,
     137,   138,   139,   140,   141,   142,   143,   144,   145,   146,
     147,   148,   149,   150,   151,   152,   153,   154,   155,   156,
     157,   158,   159,   160,   161,   162,   163,   164,   165,   166,
     167,   168,   169,   170,   171,   172,   173,   174,   175,   176,
       0,     0,   177,     0,     0,     0,     0,     0,   178,   419,
     179,   420,   180,   181,   182,   183,   184,   185,   186,     0,
     187,     0,     0,     0,     0,     0,     0,     0,   421,   188,
     189,     0,   190,     2,     3,     4,     5,     6,     7,     8,
       9,    10,    11,     0,    12,     0,     0,     0,     0,     0,
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
       0,   101,   102,     0,     0,   103,   104,   105,   106,   107,
     108,   109,   110,   111,   112,   113,   114,   115,   116,   117,
     118,   119,   120,   121,   122,   123,   124,   125,   126,   127,
     128,   129,   130,   131,   132,   133,   134,   135,   136,   137,
     138,   139,   140,   141,   142,   143,   144,   145,   146,   147,
     148,   149,   150,   151,   152,   153,   154,   155,   156,   157,
     158,   159,   160,   161,   162,   163,   164,   165,   166,   167,
     168,   169,   170,   171,   172,   173,   174,   175,   176,     0,
       0,   177,     0,     0,     0,     0,     0,   178,   419,   179,
     420,   180,   181,   182,   183,   184,   185,   186,     0,   187,
       0,     0,     0,     0,     0,     0,     0,     0,   188,   189,
     975,   190,     2,     3,     4,     5,     6,     7,     8,     9,
      10,    11,     0,    12,     0,     0,     0,     0,     0,    13,
       0,    14,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    15,     0,     0,
      16,    17,     0,     0,     0,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,    68,    69,    70,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    88,    89,    90,    91,    92,
      93,    94,     0,    95,    96,    97,    98,    99,   100,     0,
     101,   102,     0,     0,   103,   104,   105,   106,   107,   108,
     109,   110,   111,   112,   113,   114,   115,   116,   117,   118,
     119,   120,   121,   122,   123,   124,   125,   126,   127,   128,
     129,   130,   131,   132,   133,   134,   135,   136,   137,   138,
     139,   140,   141,   142,   143,   144,   145,   146,   147,   148,
     149,   150,   151,   152,   153,   154,   155,   156,   157,   158,
     159,   160,   161,   162,   163,   164,   165,   166,   167,   168,
     169,   170,   171,   172,   173,   174,   175,   176,     0,     0,
     177,     0,     0,     0,     0,     0,   178,   419,   179,   420,
     180,   181,   182,   183,   184,   185,   186,     0,   187,     0,
       0,     0,     0,     0,     0,     0,     0,   188,   189,  1032,
     190,     2,     3,     4,     5,     6,     7,     8,     9,    10,
      11,     0,    12,     0,     0,     0,     0,     0,    13,     0,
      14,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    15,     0,     0,    16,
      17,     0,     0,     0,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    68,    69,    70,    71,    72,    73,
      74,    75,    76,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    90,    91,    92,    93,
      94,     0,    95,    96,    97,    98,    99,   100,     0,   101,
     102,     0,     0,   103,   104,   105,   106,   107,   108,   109,
     110,   111,   112,   113,   114,   115,   116,   117,   118,   119,
     120,   121,   122,   123,   124,   125,   126,   127,   128,   129,
     130,   131,   132,   133,   134,   135,   136,   137,   138,   139,
     140,   141,   142,   143,   144,   145,   146,   147,   148,   149,
     150,   151,   152,   153,   154,   155,   156,   157,   158,   159,
     160,   161,   162,   163,   164,   165,   166,   167,   168,   169,
     170,   171,   172,   173,   174,   175,   176,     0,     0,   177,
       0,     0,     0,     0,     0,   178,   419,   179,   420,   180,
     181,   182,   183,   184,   185,   186,     0,   187,     0,     0,
       0,     0,     0,     0,     0,     0,   188,   189,  1039,   190,
       2,     3,     4,     5,     6,     7,     8,     9,    10,    11,
       0,    12,     0,     0,     0,     0,     0,    13,     0,    14,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    15,     0,     0,    16,    17,
       0,     0,     0,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
       0,    95,    96,    97,    98,    99,   100,     0,   101,   102,
       0,     0,   103,   104,   105,   106,   107,   108,   109,   110,
     111,   112,   113,   114,   115,   116,   117,   118,   119,   120,
     121,   122,   123,   124,   125,   126,   127,   128,   129,   130,
     131,   132,   133,   134,   135,   136,   137,   138,   139,   140,
     141,   142,   143,   144,   145,   146,   147,   148,   149,   150,
     151,   152,   153,   154,   155,   156,   157,   158,   159,   160,
     161,   162,   163,   164,   165,   166,   167,   168,   169,   170,
     171,   172,   173,   174,   175,   176,     0,     0,   177,     0,
       0,     0,     0,     0,   178,   419,   179,   420,   180,   181,
     182,   183,   184,   185,   186,     0,   187,     0,     0,     0,
       0,     0,     0,     0,     0,   188,   189,  1102,   190,     2,
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
      95,    96,    97,    98,    99,   100,     0,   101,   102,     0,
       0,   103,   104,   105,   106,   107,   108,   109,   110,   111,
     112,   113,   114,   115,   116,   117,   118,   119,   120,   121,
     122,   123,   124,   125,   126,   127,   128,   129,   130,   131,
     132,   133,   134,   135,   136,   137,   138,   139,   140,   141,
     142,   143,   144,   145,   146,   147,   148,   149,   150,   151,
     152,   153,   154,   155,   156,   157,   158,   159,   160,   161,
     162,   163,   164,   165,   166,   167,   168,   169,   170,   171,
     172,   173,   174,   175,   176,     0,     0,   177,     0,     0,
       0,     0,     0,   178,   419,   179,   420,   180,   181,   182,
     183,   184,   185,   186,     0,   187,     0,     0,     0,     0,
       0,     0,     0,     0,   188,   189,     0,   190,     2,     3,
       4,     5,     6,     7,     8,     9,    10,    11,     0,    12,
       0,     0,     0,     0,     0,    13,     0,    14,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    15,     0,     0,    16,    17,     0,     0,
       0,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,    68,    69,    70,    71,    72,    73,    74,    75,    76,
      77,    78,    79,    80,    81,    82,    83,    84,    85,    86,
      87,    88,    89,    90,    91,    92,    93,    94,     0,    95,
      96,    97,    98,    99,   100,     0,   101,   102,     0,     0,
     103,   104,   105,   106,   107,   108,   109,   110,   111,   112,
     113,   114,   115,   116,   117,   118,   119,   120,   121,   122,
     123,   124,   125,   126,   127,   128,   129,   130,   131,   132,
     133,   134,   135,   136,   137,   138,   139,   140,   141,   142,
     143,   144,   145,   146,   147,   148,   149,   150,   151,   152,
     153,   154,   155,   156,   157,   158,   159,   160,   161,   162,
     163,   164,   165,   166,   167,   168,   169,   170,   171,   172,
     173,   174,   175,   176,     0,     0,   177,     0,     0,     0,
       0,     0,   178,     0,   179,     0,   180,   181,   182,   183,
     184,   185,   186,     0,   187,     0,     0,     0,     0,     0,
       0,     0,     0,   188,   189,     0,   190,     2,     3,     4,
       5,     6,     7,     8,   221,    10,    11,     0,    12,     0,
       0,     0,     0,     0,    13,     0,    14,     0,     0,     0,
       0,     0,     0,     0,     0,   242,     0,     0,     0,     0,
       0,     0,    15,     0,   243,    16,    17,     0,     0,     0,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    56,    57,
      58,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,    69,   232,   233,   234,   235,   236,   237,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    90,    91,    92,    93,    94,     0,    95,    96,
      97,    98,    99,   100,     0,     0,     0,     0,     0,   103,
     104,   105,   106,   107,   108,   109,   110,   111,   112,   113,
     114,   115,   116,   117,   118,   119,   120,   121,   122,   123,
     124,   125,   126,   127,   128,   129,   130,   131,   132,   133,
     134,   135,   136,   137,   138,   139,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     154,   155,   156,   157,   158,   159,   160,   161,   162,   163,
     164,   165,     0,   167,   168,   169,   170,   171,   172,   173,
     174,   175,     0,     2,     3,     4,     5,     6,     7,     8,
     221,    10,    11,   238,    12,     0,   181,   182,     0,     0,
      13,   186,    14,   187,     0,     0,     0,     0,     0,     0,
       0,     0,   188,     0,     0,     0,     0,     0,    15,     0,
       0,    16,    17,     0,     0,     0,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    58,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,    69,   232,   233,
     234,   235,   236,   237,    76,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    89,    90,    91,
      92,    93,    94,     0,    95,    96,    97,    98,    99,   100,
       0,     0,     0,   456,   457,   103,   104,   105,   106,   107,
     108,   109,   110,   111,   112,   113,   114,   115,   116,   117,
     118,   119,   120,   121,   122,   123,   124,   125,   126,   127,
     128,   129,   130,   131,   132,   133,   134,   135,   136,   137,
     138,   139,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   154,   155,   156,   157,
     158,   159,   160,   161,   162,   163,   164,   165,     0,   167,
     168,   169,   170,   171,   172,   173,   174,   175,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   238,
       0,     0,   181,   182,     0,     0,     0,   186,     0,   187,
       0,     0,     0,     0,     0,     0,     0,     0,   188,     2,
       3,     4,     5,     6,     7,     8,   221,    10,    11,   454,
      12,     0,     0,     0,     0,     0,    13,     0,    14,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    15,     0,     0,    16,    17,     0,
       0,     0,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      56,    57,    58,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,    69,   232,   233,   234,   235,   236,   237,
      76,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    90,    91,    92,    93,    94,     0,
      95,    96,    97,    98,    99,   100,     0,     0,     0,     0,
       0,   103,   104,   105,   106,   107,   108,   109,   110,   111,
     112,   113,   114,   115,   116,   117,   118,   119,   120,   121,
     122,   123,   124,   125,   126,   127,   128,   129,   130,   131,
     132,   133,   134,   135,   136,   137,   138,   139,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   154,   155,   156,   157,   158,   159,   160,   161,
     162,   163,   164,   165,     0,   167,   168,   169,   170,   171,
     172,   173,   174,   175,     0,     2,     3,     4,     5,     6,
       7,     8,   221,    10,    11,   238,    12,     0,   181,   182,
       0,     0,    13,   186,    14,   187,     0,     0,     0,     0,
       0,     0,     0,   463,   188,     0,     0,     0,     0,     0,
      15,     0,     0,    16,    17,     0,     0,     0,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    58,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,    69,
     232,   233,   234,   235,   236,   237,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    91,    92,    93,    94,     0,    95,    96,    97,    98,
      99,   100,     0,     0,     0,     0,     0,   103,   104,   105,
     106,   107,   108,   109,   110,   111,   112,   113,   114,   115,
     116,   117,   118,   119,   120,   121,   122,   123,   124,   125,
     126,   127,   128,   129,   130,   131,   132,   133,   134,   135,
     136,   137,   138,   139,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   154,   155,
     156,   157,   158,   159,   160,   161,   162,   163,   164,   165,
       0,   167,   168,   169,   170,   171,   172,   173,   174,   175,
       0,     2,     3,     4,     5,     6,     7,     8,   221,    10,
      11,   238,    12,     0,   181,   182,     0,     0,    13,   186,
      14,   187,     0,     0,     0,     0,     0,     0,   514,     0,
     188,     0,     0,     0,     0,     0,    15,     0,     0,    16,
      17,     0,     0,     0,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    55,    56,    57,    58,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,    69,   232,   233,   234,   235,
     236,   237,    76,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    90,    91,    92,    93,
      94,     0,    95,    96,    97,    98,    99,   100,     0,     0,
       0,     0,     0,   103,   104,   105,   106,   107,   108,   109,
     110,   111,   112,   113,   114,   115,   116,   117,   118,   119,
     120,   121,   122,   123,   124,   125,   126,   127,   128,   129,
     130,   131,   132,   133,   134,   135,   136,   137,   138,   139,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   154,   155,   156,   157,   158,   159,
     160,   161,   162,   163,   164,   165,     0,   167,   168,   169,
     170,   171,   172,   173,   174,   175,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   238,     0,     0,
     181,   182,     0,     0,     0,   186,     0,   187,     0,     0,
       0,     0,     0,     0,     0,     0,   188,     2,     3,     4,
       5,     6,     7,     8,   221,    10,    11,   627,    12,     0,
       0,     0,     0,     0,    13,     0,    14,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    15,     0,     0,    16,    17,     0,     0,     0,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    56,    57,
      58,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,    69,   232,   233,   234,   235,   236,   237,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    90,    91,    92,    93,    94,     0,    95,    96,
      97,    98,    99,   100,     0,     0,     0,     0,     0,   103,
     104,   105,   106,   107,   108,   109,   110,   111,   112,   113,
     114,   115,   116,   117,   118,   119,   120,   121,   122,   123,
     124,   125,   126,   127,   128,   129,   130,   131,   132,   133,
     134,   135,   136,   137,   138,   139,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     154,   155,   156,   157,   158,   159,   160,   161,   162,   163,
     164,   165,     0,   167,   168,   169,   170,   171,   172,   173,
     174,   175,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   238,     0,     0,   181,   182,     0,     0,
       0,   186,     0,   187,     0,     0,     0,     0,     0,     0,
       0,     0,   188,     2,     3,     4,     5,     6,     7,     8,
     221,    10,    11,   833,    12,     0,     0,     0,     0,     0,
      13,     0,    14,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    15,     0,
       0,    16,    17,     0,     0,     0,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    58,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,    69,   232,   233,
     234,   235,   236,   237,    76,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    89,    90,    91,
      92,    93,    94,     0,    95,    96,    97,    98,    99,   100,
       0,     0,     0,     0,     0,   103,   104,   105,   106,   107,
     108,   109,   110,   111,   112,   113,   114,   115,   116,   117,
     118,   119,   120,   121,   122,   123,   124,   125,   126,   127,
     128,   129,   130,   131,   132,   133,   134,   135,   136,   137,
     138,   139,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   154,   155,   156,   157,
     158,   159,   160,   161,   162,   163,   164,   165,     0,   167,
     168,   169,   170,   171,   172,   173,   174,   175,     0,     2,
       3,     4,     5,     6,     7,     8,   221,    10,    11,   238,
      12,     0,   181,   182,     0,     0,    13,   186,    14,   187,
       0,     0,     0,     0,   835,     0,     0,     0,   188,     0,
       0,     0,     0,     0,    15,     0,     0,    16,    17,     0,
       0,     0,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      56,    57,    58,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,    69,   232,   233,   234,   235,   236,   237,
      76,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    90,    91,    92,    93,    94,     0,
      95,    96,    97,    98,    99,   100,     0,     0,     0,     0,
       0,   103,   104,   105,   106,   107,   108,   109,   110,   111,
     112,   113,   114,   115,   116,   117,   118,   119,   120,   121,
     122,   123,   124,   125,   126,   127,   128,   129,   130,   131,
     132,   133,   134,   135,   136,   137,   138,   139,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   154,   155,   156,   157,   158,   159,   160,   161,
     162,   163,   164,   165,     0,   167,   168,   169,   170,   171,
     172,   173,   174,   175,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   238,     0,     0,   181,   182,
       0,     0,     0,   186,     0,   187,     0,     0,     0,     0,
       0,     0,     0,     0,   188,     2,     3,     4,     5,     6,
       7,     8,   221,    10,    11,   905,    12,     0,     0,     0,
       0,     0,    13,     0,    14,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      15,     0,     0,    16,    17,     0,     0,     0,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    58,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,    69,
     232,   233,   234,   235,   236,   237,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    91,    92,    93,    94,     0,    95,    96,    97,    98,
      99,   100,     0,     0,     0,     0,     0,   103,   104,   105,
     106,   107,   108,   109,   110,   111,   112,   113,   114,   115,
     116,   117,   118,   119,   120,   121,   122,   123,   124,   125,
     126,   127,   128,   129,   130,   131,   132,   133,   134,   135,
     136,   137,   138,   139,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   154,   155,
     156,   157,   158,   159,   160,   161,   162,   163,   164,   165,
       0,   167,   168,   169,   170,   171,   172,   173,   174,   175,
       0,     2,     3,     4,     5,     6,     7,     8,   221,    10,
      11,   238,    12,     0,   181,   182,     0,     0,    13,   186,
      14,   187,     0,     0,     0,   932,     0,     0,     0,     0,
     188,     0,     0,     0,     0,     0,    15,     0,     0,    16,
      17,     0,     0,     0,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    55,    56,    57,    58,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,    69,   232,   233,   234,   235,
     236,   237,    76,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    90,    91,    92,    93,
      94,     0,    95,    96,    97,    98,    99,   100,     0,     0,
       0,     0,     0,   103,   104,   105,   106,   107,   108,   109,
     110,   111,   112,   113,   114,   115,   116,   117,   118,   119,
     120,   121,   122,   123,   124,   125,   126,   127,   128,   129,
     130,   131,   132,   133,   134,   135,   136,   137,   138,   139,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   154,   155,   156,   157,   158,   159,
     160,   161,   162,   163,   164,   165,     0,   167,   168,   169,
     170,   171,   172,   173,   174,   175,     0,     2,     3,     4,
       5,     6,     7,     8,   221,    10,    11,   238,    12,     0,
     181,   182,     0,     0,    13,   186,    14,   187,     0,     0,
       0,   934,     0,     0,     0,     0,   188,     0,     0,     0,
       0,     0,    15,     0,     0,    16,    17,     0,     0,     0,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    56,    57,
      58,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,    69,   232,   233,   234,   235,   236,   237,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    90,    91,    92,    93,    94,     0,    95,    96,
      97,    98,    99,   100,     0,     0,     0,     0,     0,   103,
     104,   105,   106,   107,   108,   109,   110,   111,   112,   113,
     114,   115,   116,   117,   118,   119,   120,   121,   122,   123,
     124,   125,   126,   127,   128,   129,   130,   131,   132,   133,
     134,   135,   136,   137,   138,   139,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     154,   155,   156,   157,   158,   159,   160,   161,   162,   163,
     164,   165,     0,   167,   168,   169,   170,   171,   172,   173,
     174,   175,     0,     2,     3,     4,     5,     6,     7,     8,
     221,    10,    11,   238,    12,     0,   181,   182,     0,     0,
      13,   186,    14,   187,     0,     0,     0,   938,     0,     0,
       0,     0,   188,     0,     0,     0,     0,     0,    15,     0,
       0,    16,    17,     0,     0,     0,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    58,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,    69,   232,   233,
     234,   235,   236,   237,    76,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    89,    90,    91,
      92,    93,    94,     0,    95,    96,    97,    98,    99,   100,
       0,     0,     0,     0,     0,   103,   104,   105,   106,   107,
     108,   109,   110,   111,   112,   113,   114,   115,   116,   117,
     118,   119,   120,   121,   122,   123,   124,   125,   126,   127,
     128,   129,   130,   131,   132,   133,   134,   135,   136,   137,
     138,   139,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   154,   155,   156,   157,
     158,   159,   160,   161,   162,   163,   164,   165,     0,   167,
     168,   169,   170,   171,   172,   173,   174,   175,     0,     2,
       3,     4,     5,     6,     7,     8,   221,    10,    11,   238,
      12,     0,   181,   182,     0,     0,    13,   186,    14,   187,
       0,     0,     0,     0,     0,     0,     0,     0,   188,     0,
       0,     0,     0,     0,    15,     0,     0,    16,    17,     0,
       0,     0,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      56,    57,    58,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,    69,   232,   233,   234,   235,   236,   237,
      76,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    90,    91,    92,    93,    94,     0,
      95,    96,    97,    98,    99,   100,     0,     0,     0,     0,
       0,   103,   104,   105,   106,   107,   108,   109,   110,   111,
     112,   113,   114,   115,   116,   117,   118,   119,   120,   121,
     122,   123,   124,   125,   126,   127,   128,   129,   130,   131,
     132,   133,   134,   135,   136,   137,   138,   139,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   154,   155,   156,   157,   158,   159,   160,   161,
     162,   163,   164,   165,     0,   167,   168,   169,   170,   171,
     172,   173,   174,   175,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   238,     0,     0,   181,   182,
       0,     0,     0,   186,     0,   187,     0,     0,     0,     0,
       0,     0,     0,     0,   188,     2,     3,     4,     5,     6,
       7,     8,   221,    10,    11,     0,    12,     0,   644,     0,
       0,     0,     0,     0,    14,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      15,     0,     0,    16,    17,     0,     0,     0,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    58,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,    69,
     232,   233,   234,   235,   236,   237,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    91,    92,    93,     0,     0,    95,    96,    97,    98,
      99,   100,     0,     0,     0,     0,     0,   103,   104,   105,
     106,   107,   108,   109,   110,   111,   112,   113,   114,   115,
     116,   117,   118,   119,   120,   121,   122,   123,   124,   125,
     126,   127,   128,   129,   130,   131,   132,   133,   134,   135,
     136,   137,   138,   139,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   154,   155,
     156,   157,   158,   159,   160,   161,   162,   163,   164,   165,
       0,   167,   168,   169,   170,   171,   172,   173,   174,   175,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   238,     0,     0,   181,   182,     0,     0,     0,   186,
       0,   187,     0,     0,     0,     0,     0,     0,     0,     0,
     188,     2,     3,     4,     5,     6,     7,     8,   221,    10,
      11,     0,    12,     0,   646,     0,     0,     0,     0,     0,
      14,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    15,     0,     0,    16,
      17,     0,     0,     0,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    55,    56,    57,    58,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,    69,   232,   233,   234,   235,
     236,   237,    76,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    90,    91,    92,    93,
       0,     0,    95,    96,    97,    98,    99,   100,     0,     0,
       0,     0,     0,   103,   104,   105,   106,   107,   108,   109,
     110,   111,   112,   113,   114,   115,   116,   117,   118,   119,
     120,   121,   122,   123,   124,   125,   126,   127,   128,   129,
     130,   131,   132,   133,   134,   135,   136,   137,   138,   139,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   154,   155,   156,   157,   158,   159,
     160,   161,   162,   163,   164,   165,     0,   167,   168,   169,
     170,   171,   172,   173,   174,   175,     0,     2,     3,     4,
       5,     6,     7,     8,   221,    10,    11,   238,    12,     0,
     181,   182,     0,     0,     0,   186,    14,   187,     0,     0,
       0,     0,     0,     0,     0,     0,   188,     0,     0,     0,
       0,     0,    15,     0,     0,    16,    17,     0,     0,     0,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    56,    57,
      58,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,    69,   232,   233,   234,   235,   236,   237,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    90,    91,    92,    93,     0,     0,    95,    96,
      97,    98,    99,   100,     0,     0,     0,     0,     0,   103,
     104,   105,   106,   107,   108,   109,   110,   111,   112,   113,
     114,   115,   116,   117,   118,   119,   120,   121,   122,   123,
     124,   125,   126,   127,   128,   129,   130,   131,   132,   133,
     134,   135,   136,   137,   138,   139,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     154,   155,   156,   157,   158,   159,   160,   161,   162,   163,
     164,   165,     0,   167,   168,   169,   170,   171,   172,   173,
     174,   175,     0,     2,     3,     4,     5,     6,     7,     8,
     221,    10,    11,   238,    12,     0,   181,   182,     0,     0,
       0,   186,    14,   187,     0,     0,     0,     0,     0,     0,
       0,     0,   188,     0,     0,     0,     0,     0,   655,     0,
       0,    16,    17,     0,     0,     0,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    58,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,    69,   232,   233,
     234,   235,   236,   237,    76,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    89,    90,    91,
      92,    93,     0,     0,    95,    96,    97,    98,    99,   100,
       0,     0,     0,     0,     0,   103,   104,   105,   106,   107,
     108,   109,   110,   111,   112,   113,   114,   115,   116,   117,
     118,   119,   120,   121,   122,   123,   124,   125,   126,   127,
     128,   129,   130,   131,   132,   133,   134,   135,   136,   137,
     138,   139,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   154,   155,   156,   157,
     158,   159,   160,   161,   162,   163,   164,   165,     0,   167,
     168,   169,   170,   171,   172,   173,   174,   175,     0,     2,
       3,     4,     5,     6,     7,     8,   221,    10,    11,   238,
      12,     0,   181,   182,     0,     0,     0,   186,    14,   187,
       0,     0,     0,     0,     0,     0,     0,     0,   188,     0,
       0,     0,     0,     0,   658,     0,     0,    16,    17,     0,
       0,     0,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      56,    57,    58,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,    69,   232,   233,   234,   235,   236,   237,
      76,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    90,    91,    92,    93,     0,     0,
      95,    96,    97,    98,    99,   100,     0,     0,     0,     0,
       0,   103,   104,   105,   106,   107,   108,   109,   110,   111,
     112,   113,   114,   115,   116,   117,   118,   119,   120,   121,
     122,   123,   124,   125,   126,   127,   128,   129,   130,   131,
     132,   133,   134,   135,   136,   137,   138,   139,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   154,   155,   156,   157,   158,   159,   160,   161,
     162,   163,   164,   165,     0,   167,   168,   169,   170,   171,
     172,   173,   174,   175,     0,     2,     3,     4,     5,     6,
       7,     8,   221,    10,    11,   238,    12,     0,   181,   182,
       0,     0,     0,   186,    14,   187,     0,     0,     0,     0,
       0,     0,     0,     0,   188,     0,     0,     0,     0,     0,
     665,     0,     0,    16,    17,     0,     0,     0,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    58,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,    69,
     232,   233,   234,   235,   236,   237,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    91,    92,    93,     0,     0,    95,    96,    97,    98,
      99,   100,     0,     0,     0,     0,     0,   103,   104,   105,
     106,   107,   108,   109,   110,   111,   112,   113,   114,   115,
     116,   117,   118,   119,   120,   121,   122,   123,   124,   125,
     126,   127,   128,   129,   130,   131,   132,   133,   134,   135,
     136,   137,   138,   139,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   154,   155,
     156,   157,   158,   159,   160,   161,   162,   163,   164,   165,
       0,   167,   168,   169,   170,   171,   172,   173,   174,   175,
       0,     2,     3,     4,     5,     6,     7,     8,   221,    10,
      11,   238,    12,     0,   181,   182,     0,     0,     0,   186,
      14,   187,     0,     0,     0,     0,     0,     0,     0,     0,
     188,     0,     0,     0,     0,     0,   663,     0,     0,     0,
       0,     0,     0,     0,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    55,    56,    57,    58,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,    69,   232,   233,   234,   235,
     236,   237,    76,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    90,    91,    92,    93,
       0,     0,    95,    96,    97,    98,    99,   100,     0,     0,
       0,     0,     0,   103,   104,   105,   106,   107,   108,   109,
     110,   111,   112,   113,   114,   115,   116,   117,   118,   119,
     120,   121,   122,   123,   124,   125,   126,   127,   128,   129,
     130,   131,   132,   133,   134,   135,   136,   137,   138,   139,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   154,   155,   156,   157,   158,   159,
     160,   161,   162,   163,   164,   165,     0,   167,   168,   169,
     170,   171,   172,   173,   174,   175,     0,     2,     3,     4,
       5,     6,     7,     8,   221,    10,    11,   238,    12,     0,
     181,   182,     0,     0,     0,   186,    14,   187,     0,     0,
       0,     0,     0,     0,     0,     0,   188,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    56,    57,
      58,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,    69,   232,   233,   234,   235,   236,   237,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    90,    91,    92,    93,     0,     0,    95,    96,
      97,    98,    99,   100,     0,     0,     0,     0,     0,   103,
     104,   105,   106,   107,   108,   109,   110,   111,   112,   113,
     114,   115,   116,   117,   118,   119,   120,   121,   122,   123,
     124,   125,   126,   127,   128,   129,   130,   131,   132,   133,
     134,   135,   136,   137,   138,   139,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     154,   155,   156,   157,   158,   159,   160,   161,   162,   163,
     164,   165,     0,   167,   168,   169,   170,   171,   172,   173,
     174,   175,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   238,     0,     0,   181,   182,     0,     0,
       0,   186,     0,   187,     0,     0,     0,     0,     0,     0,
       0,     0,   188,   294,   296,   298,   300,   302,   305,   307,
     309,   311,     0,   314,   316,   318,   320,   322,   324,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   294,   296,   298,   300,
     302,   305,   307,   309,   311,   314,   316,   318,   320,   322,
     324
};

static const yytype_int16 yycheck[] =
{
      11,    12,   421,    14,    21,   425,   624,    13,    16,    17,
     437,   438,   439,   440,   441,  1010,   635,    12,    18,    12,
      10,    39,    40,    23,    39,    40,    10,    27,    10,    16,
      15,    14,    39,    40,    39,    40,    14,    37,     0,    41,
      42,    39,    40,    39,    40,    13,    29,    13,   218,    13,
     220,    29,    35,    19,    13,    19,    12,    35,    48,    13,
      16,    13,    45,    13,    48,    13,    48,    45,    10,    13,
     240,    39,    40,    39,    40,    39,    40,    13,    16,    13,
      39,    40,    13,    94,    13,    39,    40,    39,    40,    39,
      40,    39,    40,    13,  1089,    39,    40,    13,     0,    13,
     218,    13,   220,    39,    40,    39,    40,    13,    39,    40,
      39,    40,    13,    10,     0,    13,    13,    13,    12,    39,
      40,    13,   240,    39,    40,    39,    40,    39,    40,    13,
     218,    13,   220,    39,    40,    13,    16,    13,    39,    40,
      13,    39,    40,    39,    40,    13,    16,    39,    40,    13,
      29,    13,   240,    13,    20,    39,    40,    39,    40,    13,
      12,    39,    40,    39,    40,   176,    39,    40,    15,   180,
      19,    39,    40,    39,    40,    39,    40,    39,    40,    39,
      40,   218,    12,   220,    12,    39,    40,    19,    16,    13,
      39,    40,    39,    40,    12,   814,    28,   815,   216,    31,
     215,   216,    13,   240,   209,    10,    13,   214,   219,   220,
      13,   631,   212,    12,    12,    39,    40,   644,   216,   646,
     216,    12,   207,   841,   217,    19,   219,    21,    39,    40,
      12,   242,    39,    40,    16,    17,    39,    40,    12,   250,
     251,   252,   253,   254,   255,   256,   257,   258,   259,   260,
     261,   262,   263,   264,   265,   266,   267,   268,   269,   270,
     271,   272,   273,   274,   275,   276,   277,   278,   279,   280,
     281,   282,   283,   284,   285,   286,   287,   288,   289,   290,
     291,   218,   293,   220,   295,   904,   297,   217,   299,   219,
     301,   193,   303,   304,   913,   306,    21,   308,    12,   310,
      12,    19,   313,   240,   315,    12,   317,   193,   319,   218,
     321,   220,   323,   218,    39,    40,   327,   328,   329,   330,
     331,    39,    40,   334,   335,   336,   337,   338,   339,   340,
     341,   342,   343,   344,   345,   346,   347,   348,   349,   350,
     351,   352,   353,   354,   355,   356,   357,   358,   359,    12,
     312,   362,   363,   971,   365,   366,   367,   368,   369,    16,
      17,   372,   373,   374,    13,   376,    12,   378,   379,   380,
     381,   382,   383,   384,   385,   386,   387,   388,   389,   390,
     391,    13,   393,   394,   395,   396,    13,   398,   399,    13,
      39,    40,    12,   812,   814,    13,    12,   408,    12,   410,
      16,    17,   413,    16,  1023,    12,   417,    39,    40,    12,
     312,    16,    39,    40,    19,    39,    40,    13,   429,   430,
      13,    39,    40,    13,   435,   436,   312,   433,   434,   227,
     228,   229,   230,   231,   232,   233,   234,   235,    12,   450,
     448,   449,    21,    39,    40,   453,    39,    40,    13,    39,
      40,    13,    16,    13,    12,   360,   361,   468,   469,   364,
      39,    40,    13,   448,   449,   370,   371,   452,   453,    13,
     375,    13,    21,    13,    39,    40,    13,    39,    40,    39,
      40,    13,    12,   903,   904,    13,    12,   392,    39,    40,
      13,    12,   397,   913,    13,    39,    40,    39,    40,    39,
      40,    12,    39,    40,    13,    20,    13,    39,    40,    13,
      12,    39,    40,    16,    13,    12,    39,    40,    13,    12,
      39,    40,   533,   425,    13,    16,    13,   432,    13,    12,
      39,    40,    39,    40,    12,    39,    40,    13,    12,   425,
      39,    40,     0,    13,    39,    40,    13,    16,    13,    20,
      39,    40,    39,    40,    39,    40,    13,   218,    13,   220,
      13,   981,    12,    39,    40,    13,    15,    13,   988,    39,
      40,    34,    39,    40,    39,    40,    39,    40,    13,   240,
      13,    12,    39,    40,    39,    40,    39,    40,   424,   425,
      13,    39,    40,    39,    40,    13,   123,    13,   609,   610,
      13,    21,    13,  1023,    39,    40,    39,    40,    13,   218,
      13,   220,    13,    20,    13,    12,    39,    40,    13,    39,
      40,    39,    40,    39,    40,    13,    39,    40,    39,    40,
      13,   240,    39,    40,    39,    40,    39,    40,    39,    40,
      39,    40,    13,    12,    39,    40,   608,  1067,    16,    13,
      12,    39,    40,    12,   616,    12,    39,    40,   669,   670,
      13,    16,    13,   674,    13,    13,    13,    12,    39,    40,
     655,   656,    13,   658,   659,    39,    40,    13,   663,    12,
     665,   666,    13,   218,    13,   220,    39,    40,    39,    40,
      39,    40,    39,    40,    16,    17,   212,   213,    39,    40,
      43,    44,    12,    39,    40,   240,   608,    12,    39,    40,
      39,    40,    12,   724,   616,    13,   727,   728,    12,   730,
     731,    13,   608,    13,   735,   736,   737,   738,    13,   631,
     616,   742,   743,   744,   745,   746,   747,   748,   749,   750,
     751,    39,    40,    19,    16,   631,    16,    39,    40,    39,
      40,    39,    40,    13,    39,    40,    12,    16,    16,    12,
     771,    13,   773,    39,    40,    12,   671,   778,   779,   780,
     781,   782,   783,   784,   785,   786,   787,   788,   789,    39,
      40,   792,   793,   794,    15,   796,   797,    39,    40,    15,
     801,    15,    12,    19,    12,    21,   807,   808,   634,   810,
      19,    12,    19,    13,    19,   220,    19,    12,    39,    40,
      19,    12,    19,    39,    40,    39,    40,    19,    12,    19,
      39,    40,    39,    40,    39,    40,    39,    40,    19,    12,
      39,    40,    39,    40,    16,    19,    21,    39,    40,    39,
      40,    19,    12,    19,    12,    19,    10,    19,    39,    40,
     861,   862,    10,    19,   865,    39,    40,    19,   763,    19,
      10,    39,    40,    39,    40,    39,    40,    39,    40,    21,
      19,    10,   777,    39,    40,    19,    12,    39,    40,    39,
      40,    12,   893,    20,    12,    12,   791,    39,    40,   900,
      39,    40,    12,    19,    12,    39,    40,    19,    12,   910,
      12,   912,    39,    40,   915,    12,   917,   918,    12,   920,
     921,    19,   814,    39,    40,    12,    12,    39,    40,   930,
      19,   932,   827,   934,    19,    12,   937,   938,   814,   891,
     892,    39,    40,    19,   945,    19,   947,    19,    12,    19,
      39,    40,    12,    21,    39,    40,   957,   958,    19,   960,
      19,    12,    19,    39,    40,    39,    40,    39,    40,    39,
      40,    19,   973,    19,   975,    19,    12,   978,    39,    40,
      39,    40,    39,    40,   985,    19,    12,    12,   814,    19,
      10,    39,    40,    39,    40,    39,    40,    19,    12,   891,
     892,    12,    19,    12,    12,    39,    40,  1008,    12,    39,
      40,   903,   904,    20,    12,   891,   892,    39,    40,   914,
      19,   913,    39,    40,   919,    19,  1027,   903,   904,  1030,
      12,  1032,    39,    40,   929,    19,  1037,   913,  1039,    19,
      39,    40,    13,    12,    19,    39,    40,    20,    12,    19,
    1051,    19,  1053,  1054,  1055,    39,    40,  1009,    12,    39,
      40,    19,    12,  1064,    39,    40,    39,    40,   963,    39,
      40,    39,    40,    19,  1075,    12,   902,   903,   904,  1080,
      12,    39,    40,    19,    12,    12,    19,   913,    19,   981,
      19,    12,    12,    39,    40,    19,   988,    12,    12,  1100,
      12,  1102,    19,    39,    40,   981,    39,    40,    39,    40,
      39,    40,   988,    12,    19,    39,    40,  1009,  1119,    19,
    1121,    19,    39,    40,    19,    10,    12,  1128,    12,    12,
      10,  1023,    19,  1009,    39,    40,  1088,    19,    12,    39,
      40,    39,    40,    19,    39,    40,    19,  1023,  1043,  1044,
      19,   977,    39,    40,   980,   981,    19,    39,    40,    19,
      30,   987,   988,    39,    40,    19,    39,    40,    20,    12,
      39,    40,    12,    20,    12,  1067,    39,    40,    12,    39,
      40,    20,    15,    20,    12,    39,    40,    39,    40,    12,
      20,  1067,    39,    40,    20,    12,  1088,  1023,  1024,    20,
      39,    40,    39,    40,    12,    12,    12,    20,  1034,    39,
      40,    20,  1088,    39,    40,  1041,    20,    12,    39,    40,
      21,    12,    12,  1118,    12,  1120,    39,    40,    20,    12,
      39,    40,    12,    19,    21,    39,    40,    12,    39,    40,
    1066,  1067,    21,  1069,  1070,    21,  1072,    39,    40,    21,
      12,  1077,    39,    40,    21,    12,  1151,    21,    12,    12,
      39,    40,    13,    39,    40,    13,    12,    39,    40,    12,
      19,    21,    39,    40,    21,    39,    40,    21,  1104,    21,
      12,  1107,    21,  1109,  1110,    12,    12,  1113,  1114,    39,
      40,    12,    39,    40,    12,    39,    40,    39,    40,  1125,
      39,    40,    12,    16,    24,    25,    26,  1133,    13,    13,
    1136,   442,   443,   444,   445,   446,    13,  1143,  1144,    39,
      40,    13,    31,    13,    13,    13,    13,     1,  1154,     3,
       4,     5,     6,     7,     8,     9,    10,    11,    12,    19,
      14,    32,    33,    19,    13,    36,    20,   237,    22,    19,
      41,    42,   227,   228,   229,   230,   231,   232,   233,   234,
     235,    12,    15,    27,    38,    27,    27,    41,    42,    10,
      28,    13,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    68,    69,    70,    71,    72,    73,
      74,    75,    76,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    90,    91,    92,    93,
      94,    95,    96,    97,    98,    99,   100,   101,   102,   103,
     104,   105,   106,   107,   108,   109,   110,   111,   112,   113,
     114,   115,   116,   117,   118,   119,   120,   121,   122,   210,
     124,   125,   126,   127,   128,   129,    19,   131,   132,    15,
      13,   135,   136,   137,   138,   139,   140,   141,   142,   143,
     144,   145,   146,   147,   148,   149,   150,   151,   152,   153,
     154,   155,   156,   157,   158,   159,   160,   161,   162,   163,
     164,   165,   166,   167,   168,   169,   170,   171,   172,   173,
     174,   175,   176,   177,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   187,   188,   189,   190,   191,   192,   193,
     194,   195,   196,   197,   198,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,    13,    13,   211,    13,    13,
      19,    13,    13,   217,    13,   219,    13,   221,   222,   223,
     224,   225,   226,   227,    13,   229,   228,   229,   230,   231,
     232,   233,   234,   235,   238,   239,    13,   241,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    42,    14,
      13,    13,   236,    19,    13,    20,    27,    22,   228,   229,
     230,   231,   232,   233,   234,    13,    13,    13,    13,    13,
      13,   416,   615,    38,    94,   724,    41,    42,  1098,  1089,
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
     237,   238,   239,   240,   241,     3,     4,     5,     6,     7,
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
      -1,   229,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   237,
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
     229,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   237,   238,
     239,    -1,   241,     3,     4,     5,     6,     7,     8,     9,
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
      -1,    -1,    -1,    -1,    -1,    -1,   238,   239,   240,   241,
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
      -1,    -1,    -1,    -1,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,    -1,   229,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   238,   239,   240,   241,     3,
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
     124,   125,   126,   127,   128,   129,    -1,   131,   132,    -1,
      -1,   135,   136,   137,   138,   139,   140,   141,   142,   143,
     144,   145,   146,   147,   148,   149,   150,   151,   152,   153,
     154,   155,   156,   157,   158,   159,   160,   161,   162,   163,
     164,   165,   166,   167,   168,   169,   170,   171,   172,   173,
     174,   175,   176,   177,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   187,   188,   189,   190,   191,   192,   193,
     194,   195,   196,   197,   198,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,    -1,    -1,   211,    -1,    -1,
      -1,    -1,    -1,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,    -1,   229,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   238,   239,    -1,   241,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    -1,    14,
      -1,    -1,    -1,    -1,    -1,    20,    -1,    22,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
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
      -1,    -1,   217,    -1,   219,    -1,   221,   222,   223,   224,
     225,   226,   227,    -1,   229,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   238,   239,    -1,   241,     3,     4,     5,
       6,     7,     8,     9,    10,    11,    12,    -1,    14,    -1,
      -1,    -1,    -1,    -1,    20,    -1,    22,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    31,    -1,    -1,    -1,    -1,
      -1,    -1,    38,    -1,    40,    41,    42,    -1,    -1,    -1,
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
      -1,    -1,   238,    -1,    -1,    -1,    -1,    -1,    38,    -1,
      -1,    41,    42,    -1,    -1,    -1,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    68,    69,
      70,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    91,    92,    93,    94,    95,    96,    97,    98,    99,
     100,   101,   102,   103,   104,   105,   106,   107,   108,   109,
     110,   111,   112,   113,   114,   115,   116,   117,   118,   119,
     120,   121,   122,    -1,   124,   125,   126,   127,   128,   129,
      -1,    -1,    -1,   133,   134,   135,   136,   137,   138,   139,
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
      -1,    -1,    -1,    31,   238,    -1,    -1,    -1,    -1,    -1,
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
      -1,    -1,    -1,    -1,    28,    -1,    -1,    -1,   238,    -1,
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
     204,   205,   206,   207,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   219,    -1,    -1,   222,   223,
      -1,    -1,    -1,   227,    -1,   229,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   238,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    -1,    -1,    -1,
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
      -1,    27,    -1,    -1,    -1,    -1,   238,    -1,    -1,    -1,
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
      20,   227,    22,   229,    -1,    -1,    -1,    27,    -1,    -1,
      -1,    -1,   238,    -1,    -1,    -1,    -1,    -1,    38,    -1,
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
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   238,    -1,
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
     204,   205,   206,   207,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   219,    -1,    -1,   222,   223,
      -1,    -1,    -1,   227,    -1,   229,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   238,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    -1,    14,    -1,    16,    -1,
      -1,    -1,    -1,    -1,    22,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
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
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   219,    -1,    -1,   222,   223,    -1,    -1,    -1,   227,
      -1,   229,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     238,     3,     4,     5,     6,     7,     8,     9,    10,    11,
      12,    -1,    14,    -1,    16,    -1,    -1,    -1,    -1,    -1,
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
     238,    -1,    -1,    -1,    -1,    -1,    38,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    46,    47,    48,    49,    50,    51,
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
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
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
     206,   207,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   219,    -1,    -1,   222,   223,    -1,    -1,
      -1,   227,    -1,   229,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   238,    60,    61,    62,    63,    64,    65,    66,
      67,    68,    -1,    70,    71,    72,    73,    74,    75,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237
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
     129,   131,   132,   135,   136,   137,   138,   139,   140,   141,
     142,   143,   144,   145,   146,   147,   148,   149,   150,   151,
     152,   153,   154,   155,   156,   157,   158,   159,   160,   161,
     162,   163,   164,   165,   166,   167,   168,   169,   170,   171,
     172,   173,   174,   175,   176,   177,   178,   179,   180,   181,
     182,   183,   184,   185,   186,   187,   188,   189,   190,   191,
     192,   193,   194,   195,   196,   197,   198,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   211,   217,   219,
     221,   222,   223,   224,   225,   226,   227,   229,   238,   239,
     241,   243,   244,   245,   247,   255,   256,   257,   258,   259,
     260,   261,   265,   266,   267,   268,   269,   270,   271,   272,
     273,   276,   277,   279,   280,   281,   283,    21,    12,    16,
      17,    10,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    98,    99,   100,   101,   102,   103,   219,   265,
     267,   273,    31,    40,   265,   268,   265,   272,   270,   270,
      12,    12,    12,    12,    12,    12,    12,    12,    12,    12,
      12,    12,    12,    12,    12,    12,    12,    12,    12,    12,
      12,    12,    12,    12,    12,    12,    12,    12,    12,    12,
      12,    12,    12,    12,    12,    12,    12,    12,    12,    12,
      12,    16,   282,    16,   282,    16,   282,    16,   282,    16,
     282,    16,   282,    12,    16,   282,    16,   282,    16,   282,
      16,   282,    12,    16,   282,    16,   282,    16,   282,    16,
     282,    16,   282,    16,   282,   265,   266,    12,    12,    12,
      12,    12,    12,    12,    12,    12,    12,    12,    12,    12,
      12,    12,    12,    12,    12,    12,    12,    12,    12,    12,
      12,    12,    12,    12,    12,    12,    12,    12,    12,    12,
      12,    12,    12,    12,    12,    12,    12,    12,    12,    12,
      12,    12,    12,    12,    12,    12,    12,    12,    12,    12,
      12,    12,    12,    12,    12,    12,    12,    12,    12,    12,
      12,    12,    12,    12,    12,    12,    12,    12,    12,    12,
     248,   265,    10,   249,    29,   262,   264,   265,    12,    12,
      12,    12,    12,    12,    12,   254,    10,    12,     0,   218,
     220,   237,   246,   247,   250,   251,   252,    21,    20,    16,
      17,    20,    19,    39,    40,    16,    17,    18,    23,    27,
      37,   212,    32,    33,    36,    41,    42,   272,    43,    44,
      14,    29,    35,    45,    13,   261,   133,   134,   265,   265,
      16,    13,    29,    31,   265,   278,    15,    15,    19,    21,
      24,    25,    26,   265,   265,   265,   265,   265,   265,   265,
     265,   265,   265,   265,   265,   265,   265,   265,   265,   265,
     265,   265,   265,   265,   265,   265,   265,   265,   265,   265,
     265,   265,   265,   265,   265,   265,   265,   265,   265,   265,
     265,   265,   265,   265,    30,   265,   265,   265,   265,   265,
     265,   265,   265,   265,   265,   265,   247,   265,   265,   265,
     265,   265,   265,   123,   265,   265,   265,   265,   265,    13,
      13,   265,   265,   265,   265,   265,   265,   265,   265,   265,
     265,   265,   265,   265,   265,   265,   265,   265,   265,   265,
     265,   265,   265,   265,   265,   265,   265,   261,   261,   265,
     265,   261,   265,   265,   265,   265,   265,   261,   261,   265,
     265,   265,   261,   265,    10,    48,   265,   265,   265,   265,
     265,   265,   265,   265,   265,   265,   265,   265,   265,   265,
     261,   265,   265,   265,   265,   261,   265,   265,   209,   212,
     213,    10,   220,    19,    21,   263,   216,   265,    10,   265,
      10,    10,   265,    10,    13,   253,   254,    13,   265,    10,
     253,    21,   246,   246,   250,    21,   265,   265,   261,   268,
     268,   265,   265,   269,    16,   269,    16,   269,   269,   269,
     271,   271,   271,   271,   271,    38,   270,   272,    38,   270,
     272,   265,    10,    38,   272,    38,   270,   272,    13,    12,
      12,    12,    10,    15,    19,    28,    31,   265,   265,    13,
      13,    13,    13,    13,    13,    13,    13,    13,    13,    13,
      13,    13,    13,    13,    13,    13,    13,    13,    13,    13,
      13,    13,    13,    13,    13,    13,    13,    13,    13,    13,
      13,    13,    13,    13,    13,    13,    13,    13,    13,    13,
      13,    13,   265,   274,   275,    13,    13,    19,    19,    13,
      19,    19,    13,    13,    13,    19,    19,    19,    19,    13,
      13,    13,    19,    19,    19,    19,    19,    19,    19,    19,
      19,    19,    13,    13,    13,    13,    13,    13,    13,    13,
      13,    13,    13,    19,    13,    13,    13,    13,    13,    13,
      13,    19,    13,    19,    19,    19,    19,    19,    19,    19,
      19,    19,    19,    19,    19,    19,    19,    19,    19,    19,
      13,    19,    19,    19,    19,    13,    19,    19,   247,   265,
     265,    16,   262,   247,    13,    13,    13,    19,    19,    13,
      19,    16,    19,   219,   245,    13,    13,   250,   246,   251,
     269,   269,   272,   272,   272,   272,    15,    12,   272,   272,
     272,   265,   265,    13,   261,    28,   265,    31,    15,    15,
      15,    34,   274,   265,   265,   265,   265,   265,   265,   265,
     265,   265,   265,   265,   265,   265,   265,   265,   265,   265,
     265,    27,    27,   261,   265,    27,   265,    10,    48,    10,
      48,    10,   261,   265,   265,   265,   265,   265,   265,   265,
     265,   265,   265,   265,   265,   261,   265,   265,   265,   265,
     265,   210,   216,   214,   265,   265,   265,   265,    28,   253,
     240,   246,   250,   251,   245,    13,   261,    13,    13,    13,
      19,    15,    12,   245,    19,    19,    13,    19,    19,    19,
      19,    19,    13,    13,    13,    13,    13,    13,    13,    19,
      19,    13,    27,   265,    27,   265,    13,    19,    27,   265,
      13,    13,    13,    13,    13,    19,    13,    19,    13,    13,
      13,    13,    13,    13,    13,    13,    13,    19,    19,    13,
      19,    13,    13,    19,    13,   247,   247,   265,    19,    13,
      13,    13,   265,   240,   246,   240,   246,   250,   240,   246,
     250,   251,    13,   265,   265,   240,   246,   250,   251,   261,
     265,   265,   265,   261,   265,   265,   261,   265,   265,   265,
     265,   265,   265,   265,   265,   265,   265,   261,   215,   216,
      12,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     284,   285,   287,   245,    21,   265,   265,   240,   246,   265,
     240,   246,   240,   246,   250,    13,   265,   240,   246,   240,
     246,   250,    13,    19,    19,    13,    13,    13,    13,    13,
      13,    19,    13,    19,    19,    19,    13,    13,   265,   247,
     284,   286,   236,    42,   240,   246,   250,   251,   246,    21,
      21,   265,    21,   265,   265,   240,   246,    21,   265,   265,
     240,   246,   261,   261,   265,   265,   265,   265,   216,    19,
      13,   228,   229,   230,   231,   232,   233,   234,    27,   265,
     240,   246,   240,   246,   250,   246,   246,    21,   246,    21,
      21,   265,   246,    21,    21,   265,    13,    13,    19,    19,
      19,    19,   247,   286,   285,    21,   265,   265,   240,   246,
     246,   246,   246,    21,   246,   246,    21,   261,   265,   261,
     265,    13,   246,    21,    21,   265,   246,   246,    13,    13,
      13,    19,   246,   246,    21,   261,   246,    13
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int16 yyr1[] =
{
       0,   242,   243,   244,   244,   245,   245,   246,   246,   247,
     247,   247,   247,   247,   247,   247,   247,   248,   248,   249,
     249,   249,   250,   250,   251,   251,   252,   253,   253,   254,
     254,   254,   254,   254,   254,   254,   254,   254,   254,   254,
     254,   254,   254,   254,   254,   254,   254,   254,   254,   254,
     254,   254,   254,   255,   255,   255,   255,   255,   255,   255,
     255,   255,   255,   255,   255,   255,   255,   255,   255,   255,
     255,   255,   255,   255,   255,   255,   255,   255,   255,   255,
     255,   255,   255,   255,   255,   255,   255,   255,   256,   256,
     256,   256,   257,   257,   257,   257,   257,   257,   257,   257,
     258,   259,   259,   259,   259,   259,   259,   259,   259,   259,
     259,   259,   259,   259,   259,   259,   259,   260,   260,   260,
     260,   260,   260,   260,   260,   260,   260,   260,   260,   260,
     260,   260,   260,   261,   261,   262,   262,   263,   263,   264,
     265,   265,   266,   266,   266,   266,   267,   268,   268,   268,
     268,   268,   268,   268,   268,   269,   269,   269,   269,   269,
     269,   270,   270,   270,   270,   271,   271,   271,   271,   271,
     271,   271,   271,   271,   272,   272,   272,   272,   272,   272,
     273,   273,   273,   273,   273,   273,   273,   273,   273,   273,
     273,   273,   273,   273,   273,   273,   273,   273,   273,   273,
     273,   273,   273,   273,   273,   273,   273,   273,   273,   273,
     273,   273,   273,   273,   273,   273,   273,   273,   273,   273,
     273,   273,   273,   273,   273,   273,   273,   273,   273,   273,
     273,   273,   273,   273,   274,   274,   275,   275,   275,   275,
     275,   275,   275,   275,   275,   276,   276,   276,   276,   276,
     276,   276,   277,   277,   277,   277,   278,   278,   278,   279,
     279,   279,   280,   280,   280,   280,   280,   280,   281,   281,
     281,   281,   281,   281,   281,   281,   281,   281,   281,   281,
     281,   281,   281,   281,   281,   281,   281,   281,   281,   281,
     281,   281,   281,   281,   281,   281,   281,   281,   281,   281,
     281,   281,   281,   281,   281,   281,   281,   281,   281,   281,
     281,   281,   281,   281,   281,   281,   281,   281,   281,   281,
     281,   281,   281,   281,   281,   281,   281,   281,   281,   281,
     281,   281,   281,   281,   281,   281,   281,   281,   281,   281,
     281,   281,   281,   281,   281,   281,   281,   281,   281,   281,
     281,   281,   281,   281,   281,   281,   281,   281,   281,   281,
     281,   281,   281,   281,   281,   281,   281,   281,   281,   282,
     282,   283,   283,   283,   283,   283,   283,   283,   283,   283,
     283,   283,   283,   283,   283,   283,   283,   284,   284,   284,
     284,   284,   284,   284,   284,   284,   284,   284,   284,   284,
     284,   285,   285,   286,   286,   287,   287
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     2,     2,     1,     1,     1,     1,     1,
       3,     4,     3,     2,     2,     4,     2,     3,     5,     7,
       9,     5,     2,     3,     2,     3,     2,     1,     3,     5,
       6,     5,     4,     8,     9,     8,     7,     6,     7,     6,
       5,     9,    10,     9,     8,     8,     9,     8,     7,    11,
      12,    11,    10,     1,     1,     1,     4,     3,     4,     6,
       7,     6,     4,     4,     4,     4,     4,     4,     4,    12,
       4,     6,     7,     6,     4,     4,     6,     7,    12,     6,
       6,     6,     6,    11,     6,     1,     1,     3,     1,     2,
       1,     2,     3,     3,     6,     6,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     1,     3,     1,     3,     1,     1,     4,
       1,     4,     1,     3,     3,     2,     4,     1,     3,     3,
       3,     3,     4,     4,     3,     1,     3,     3,     3,     3,
       3,     1,     1,     2,     2,     1,     2,     2,     3,     3,
       4,     4,     4,     4,     1,     3,     4,     4,     3,     4,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     4,     4,     3,     1,
       1,     1,     1,     3,     3,     1,     1,     3,     5,     6,
       6,     5,     2,     4,     1,     2,     9,     6,     8,     5,
       8,     5,     7,     4,     5,     1,     1,     1,     1,     1,
       1,     1,     4,     3,     5,     6,     1,     3,     5,     5,
       5,     3,     3,     3,     3,     4,     4,     4,     4,     4,
       3,     3,     6,     4,     8,    10,     8,     4,     4,    10,
       4,     4,     4,     4,     8,     8,     8,     8,     4,     4,
       4,     6,     6,     6,     6,     6,     6,     6,     8,     8,
       6,     4,     4,     6,    12,     6,     6,     6,     6,     6,
       6,     6,     6,     6,    14,     4,     6,     8,     6,     6,
       4,     8,     6,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     6,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     2,
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     1,     1,     1,
       1,     1,     1,     1,     3,     3,     3,     3,     3,     3,
       3,     1,     1,     1,     3,     1,     3
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
#line 453 "internparser.y"
                          {
			    parsedThingIntern = (yyvsp[0].tree);
			    (yyval.other) = NULL;
			    YYACCEPT;
			  }
#line 4267 "internparser.c"
    break;

  case 3: /* startsymbolwitherr: command ";"  */
#line 462 "internparser.y"
                          {
			    (yyval.tree) = (yyvsp[-1].tree);
			  }
#line 4275 "internparser.c"
    break;

  case 4: /* startsymbolwitherr: error ";"  */
#line 466 "internparser.y"
                          {
			    (yyval.tree) = NULL;
			  }
#line 4283 "internparser.c"
    break;

  case 5: /* beginsymbol: "begin"  */
#line 472 "internparser.y"
                          {
			    (yyval.other) = NULL;
			  }
#line 4291 "internparser.c"
    break;

  case 6: /* beginsymbol: "{"  */
#line 476 "internparser.y"
                          {
			    (yyval.other) = NULL;
			  }
#line 4299 "internparser.c"
    break;

  case 7: /* endsymbol: "end"  */
#line 482 "internparser.y"
                          {
			    (yyval.other) = NULL;
			  }
#line 4307 "internparser.c"
    break;

  case 8: /* endsymbol: "}"  */
#line 486 "internparser.y"
                          {
			    (yyval.other) = NULL;
			  }
#line 4315 "internparser.c"
    break;

  case 9: /* command: simplecommand  */
#line 492 "internparser.y"
                          {
			    (yyval.tree) = (yyvsp[0].tree);
			  }
#line 4323 "internparser.c"
    break;

  case 10: /* command: beginsymbol commandlist endsymbol  */
#line 496 "internparser.y"
                          {
			    (yyval.tree) = makeCommandList((yyvsp[-1].list));
                          }
#line 4331 "internparser.c"
    break;

  case 11: /* command: beginsymbol variabledeclarationlist commandlist endsymbol  */
#line 500 "internparser.y"
                          {
			    (yyval.tree) = makeCommandList(concatChains((yyvsp[-2].list), (yyvsp[-1].list)));
                          }
#line 4339 "internparser.c"
    break;

  case 12: /* command: beginsymbol variabledeclarationlist endsymbol  */
#line 504 "internparser.y"
                          {
			    (yyval.tree) = makeCommandList((yyvsp[-1].list));
                          }
#line 4347 "internparser.c"
    break;

  case 13: /* command: beginsymbol endsymbol  */
#line 508 "internparser.y"
                          {
			    (yyval.tree) = makeNop();
                          }
#line 4355 "internparser.c"
    break;

  case 14: /* command: "if" ifcommand  */
#line 512 "internparser.y"
                          {
			    (yyval.tree) = (yyvsp[0].tree);
			  }
#line 4363 "internparser.c"
    break;

  case 15: /* command: "while" thing "do" command  */
#line 516 "internparser.y"
                          {
			    (yyval.tree) = makeWhile((yyvsp[-2].tree), (yyvsp[0].tree));
			  }
#line 4371 "internparser.c"
    break;

  case 16: /* command: "for" forcommand  */
#line 520 "internparser.y"
                          {
			    (yyval.tree) = (yyvsp[0].tree);
			  }
#line 4379 "internparser.c"
    break;

  case 17: /* ifcommand: thing "then" command  */
#line 526 "internparser.y"
                          {
			    (yyval.tree) = makeIf((yyvsp[-2].tree), (yyvsp[0].tree));
                          }
#line 4387 "internparser.c"
    break;

  case 18: /* ifcommand: thing "then" command "else" command  */
#line 530 "internparser.y"
                          {
			    (yyval.tree) = makeIfElse((yyvsp[-4].tree),(yyvsp[-2].tree),(yyvsp[0].tree));
                          }
#line 4395 "internparser.c"
    break;

  case 19: /* forcommand: "identifier" "from" thing "to" thing "do" command  */
#line 538 "internparser.y"
                          {
			    (yyval.tree) = makeFor((yyvsp[-6].value), (yyvsp[-4].tree), (yyvsp[-2].tree), makeConstantDouble(1.0), (yyvsp[0].tree));
			    safeFree((yyvsp[-6].value));
                          }
#line 4404 "internparser.c"
    break;

  case 20: /* forcommand: "identifier" "from" thing "to" thing "by" thing "do" command  */
#line 543 "internparser.y"
                          {
			    (yyval.tree) = makeFor((yyvsp[-8].value), (yyvsp[-6].tree), (yyvsp[-4].tree), (yyvsp[-2].tree), (yyvsp[0].tree));
			    safeFree((yyvsp[-8].value));
                          }
#line 4413 "internparser.c"
    break;

  case 21: /* forcommand: "identifier" "in" thing "do" command  */
#line 548 "internparser.y"
                          {
			    (yyval.tree) = makeForIn((yyvsp[-4].value), (yyvsp[-2].tree), (yyvsp[0].tree));
			    safeFree((yyvsp[-4].value));
                          }
#line 4422 "internparser.c"
    break;

  case 22: /* commandlist: command ";"  */
#line 556 "internparser.y"
                          {
			    (yyval.list) = addElement(NULL, (yyvsp[-1].tree));
			  }
#line 4430 "internparser.c"
    break;

  case 23: /* commandlist: command ";" commandlist  */
#line 560 "internparser.y"
                          {
			    (yyval.list) = addElement((yyvsp[0].list), (yyvsp[-2].tree));
			  }
#line 4438 "internparser.c"
    break;

  case 24: /* variabledeclarationlist: variabledeclaration ";"  */
#line 566 "internparser.y"
                          {
			    (yyval.list) = addElement(NULL, (yyvsp[-1].tree));
			  }
#line 4446 "internparser.c"
    break;

  case 25: /* variabledeclarationlist: variabledeclaration ";" variabledeclarationlist  */
#line 570 "internparser.y"
                          {
			    (yyval.list) = addElement((yyvsp[0].list), (yyvsp[-2].tree));
			  }
#line 4454 "internparser.c"
    break;

  case 26: /* variabledeclaration: "var" identifierlist  */
#line 576 "internparser.y"
                          {
			    (yyval.tree) = makeVariableDeclaration((yyvsp[0].list));
			  }
#line 4462 "internparser.c"
    break;

  case 27: /* identifierlist: "identifier"  */
#line 583 "internparser.y"
                          {
			    (yyval.list) = addElement(NULL, (yyvsp[0].value));
			  }
#line 4470 "internparser.c"
    break;

  case 28: /* identifierlist: "identifier" "," identifierlist  */
#line 587 "internparser.y"
                          {
			    (yyval.list) = addElement((yyvsp[0].list), (yyvsp[-2].value));
			  }
#line 4478 "internparser.c"
    break;

  case 29: /* procbody: "(" ")" beginsymbol commandlist endsymbol  */
#line 593 "internparser.y"
                          {
			    (yyval.tree) = makeProc(NULL, makeCommandList((yyvsp[-1].list)), makeUnit());
                          }
#line 4486 "internparser.c"
    break;

  case 30: /* procbody: "(" ")" beginsymbol variabledeclarationlist commandlist endsymbol  */
#line 597 "internparser.y"
                          {
			    (yyval.tree) = makeProc(NULL, makeCommandList(concatChains((yyvsp[-2].list), (yyvsp[-1].list))), makeUnit());
                          }
#line 4494 "internparser.c"
    break;

  case 31: /* procbody: "(" ")" beginsymbol variabledeclarationlist endsymbol  */
#line 601 "internparser.y"
                          {
			    (yyval.tree) = makeProc(NULL, makeCommandList((yyvsp[-1].list)), makeUnit());
                          }
#line 4502 "internparser.c"
    break;

  case 32: /* procbody: "(" ")" beginsymbol endsymbol  */
#line 605 "internparser.y"
                          {
			    (yyval.tree) = makeProc(NULL, makeCommandList(addElement(NULL,makeNop())), makeUnit());
                          }
#line 4510 "internparser.c"
    break;

  case 33: /* procbody: "(" ")" beginsymbol commandlist "return" thing ";" endsymbol  */
#line 609 "internparser.y"
                          {
			    (yyval.tree) = makeProc(NULL, makeCommandList((yyvsp[-4].list)), (yyvsp[-2].tree));
                          }
#line 4518 "internparser.c"
    break;

  case 34: /* procbody: "(" ")" beginsymbol variabledeclarationlist commandlist "return" thing ";" endsymbol  */
#line 613 "internparser.y"
                          {
			    (yyval.tree) = makeProc(NULL, makeCommandList(concatChains((yyvsp[-5].list), (yyvsp[-4].list))), (yyvsp[-2].tree));
                          }
#line 4526 "internparser.c"
    break;

  case 35: /* procbody: "(" ")" beginsymbol variabledeclarationlist "return" thing ";" endsymbol  */
#line 617 "internparser.y"
                          {
			    (yyval.tree) = makeProc(NULL, makeCommandList((yyvsp[-4].list)), (yyvsp[-2].tree));
                          }
#line 4534 "internparser.c"
    break;

  case 36: /* procbody: "(" ")" beginsymbol "return" thing ";" endsymbol  */
#line 621 "internparser.y"
                          {
			    (yyval.tree) = makeProc(NULL, makeCommandList(addElement(NULL,makeNop())), (yyvsp[-2].tree));
                          }
#line 4542 "internparser.c"
    break;

  case 37: /* procbody: "(" identifierlist ")" beginsymbol commandlist endsymbol  */
#line 625 "internparser.y"
                          {
			    (yyval.tree) = makeProc((yyvsp[-4].list), makeCommandList((yyvsp[-1].list)), makeUnit());
                          }
#line 4550 "internparser.c"
    break;

  case 38: /* procbody: "(" identifierlist ")" beginsymbol variabledeclarationlist commandlist endsymbol  */
#line 629 "internparser.y"
                          {
			    (yyval.tree) = makeProc((yyvsp[-5].list), makeCommandList(concatChains((yyvsp[-2].list), (yyvsp[-1].list))), makeUnit());
                          }
#line 4558 "internparser.c"
    break;

  case 39: /* procbody: "(" identifierlist ")" beginsymbol variabledeclarationlist endsymbol  */
#line 633 "internparser.y"
                          {
			    (yyval.tree) = makeProc((yyvsp[-4].list), makeCommandList((yyvsp[-1].list)), makeUnit());
                          }
#line 4566 "internparser.c"
    break;

  case 40: /* procbody: "(" identifierlist ")" beginsymbol endsymbol  */
#line 637 "internparser.y"
                          {
			    (yyval.tree) = makeProc((yyvsp[-3].list), makeCommandList(addElement(NULL,makeNop())), makeUnit());
                          }
#line 4574 "internparser.c"
    break;

  case 41: /* procbody: "(" identifierlist ")" beginsymbol commandlist "return" thing ";" endsymbol  */
#line 641 "internparser.y"
                          {
			    (yyval.tree) = makeProc((yyvsp[-7].list), makeCommandList((yyvsp[-4].list)), (yyvsp[-2].tree));
                          }
#line 4582 "internparser.c"
    break;

  case 42: /* procbody: "(" identifierlist ")" beginsymbol variabledeclarationlist commandlist "return" thing ";" endsymbol  */
#line 645 "internparser.y"
                          {
			    (yyval.tree) = makeProc((yyvsp[-8].list), makeCommandList(concatChains((yyvsp[-5].list), (yyvsp[-4].list))), (yyvsp[-2].tree));
                          }
#line 4590 "internparser.c"
    break;

  case 43: /* procbody: "(" identifierlist ")" beginsymbol variabledeclarationlist "return" thing ";" endsymbol  */
#line 649 "internparser.y"
                          {
			    (yyval.tree) = makeProc((yyvsp[-7].list), makeCommandList((yyvsp[-4].list)), (yyvsp[-2].tree));
                          }
#line 4598 "internparser.c"
    break;

  case 44: /* procbody: "(" identifierlist ")" beginsymbol "return" thing ";" endsymbol  */
#line 653 "internparser.y"
                          {
			    (yyval.tree) = makeProc((yyvsp[-6].list), makeCommandList(addElement(NULL, makeNop())), (yyvsp[-2].tree));
                          }
#line 4606 "internparser.c"
    break;

  case 45: /* procbody: "(" "identifier" "=" "..." ")" beginsymbol commandlist endsymbol  */
#line 657 "internparser.y"
                          {
			    (yyval.tree) = makeProcIllim((yyvsp[-6].value), makeCommandList((yyvsp[-1].list)), makeUnit());
                          }
#line 4614 "internparser.c"
    break;

  case 46: /* procbody: "(" "identifier" "=" "..." ")" beginsymbol variabledeclarationlist commandlist endsymbol  */
#line 661 "internparser.y"
                          {
			    (yyval.tree) = makeProcIllim((yyvsp[-7].value), makeCommandList(concatChains((yyvsp[-2].list), (yyvsp[-1].list))), makeUnit());
                          }
#line 4622 "internparser.c"
    break;

  case 47: /* procbody: "(" "identifier" "=" "..." ")" beginsymbol variabledeclarationlist endsymbol  */
#line 665 "internparser.y"
                          {
			    (yyval.tree) = makeProcIllim((yyvsp[-6].value), makeCommandList((yyvsp[-1].list)), makeUnit());
                          }
#line 4630 "internparser.c"
    break;

  case 48: /* procbody: "(" "identifier" "=" "..." ")" beginsymbol endsymbol  */
#line 669 "internparser.y"
                          {
			    (yyval.tree) = makeProcIllim((yyvsp[-5].value), makeCommandList(addElement(NULL,makeNop())), makeUnit());
                          }
#line 4638 "internparser.c"
    break;

  case 49: /* procbody: "(" "identifier" "=" "..." ")" beginsymbol commandlist "return" thing ";" endsymbol  */
#line 673 "internparser.y"
                          {
			    (yyval.tree) = makeProcIllim((yyvsp[-9].value), makeCommandList((yyvsp[-4].list)), (yyvsp[-2].tree));
                          }
#line 4646 "internparser.c"
    break;

  case 50: /* procbody: "(" "identifier" "=" "..." ")" beginsymbol variabledeclarationlist commandlist "return" thing ";" endsymbol  */
#line 677 "internparser.y"
                          {
			    (yyval.tree) = makeProcIllim((yyvsp[-10].value), makeCommandList(concatChains((yyvsp[-5].list), (yyvsp[-4].list))), (yyvsp[-2].tree));
                          }
#line 4654 "internparser.c"
    break;

  case 51: /* procbody: "(" "identifier" "=" "..." ")" beginsymbol variabledeclarationlist "return" thing ";" endsymbol  */
#line 681 "internparser.y"
                          {
			    (yyval.tree) = makeProcIllim((yyvsp[-9].value), makeCommandList((yyvsp[-4].list)), (yyvsp[-2].tree));
                          }
#line 4662 "internparser.c"
    break;

  case 52: /* procbody: "(" "identifier" "=" "..." ")" beginsymbol "return" thing ";" endsymbol  */
#line 685 "internparser.y"
                          {
			    (yyval.tree) = makeProcIllim((yyvsp[-8].value), makeCommandList(addElement(NULL, makeNop())), (yyvsp[-2].tree));
                          }
#line 4670 "internparser.c"
    break;

  case 53: /* simplecommand: "quit in an included file"  */
#line 693 "internparser.y"
                          {
			    (yyval.tree) = makeQuit();
			  }
#line 4678 "internparser.c"
    break;

  case 54: /* simplecommand: "restart"  */
#line 697 "internparser.y"
                          {
			    (yyval.tree) = makeFalseRestart();
			  }
#line 4686 "internparser.c"
    break;

  case 55: /* simplecommand: "nop"  */
#line 701 "internparser.y"
                          {
			    (yyval.tree) = makeNop();
			  }
#line 4694 "internparser.c"
    break;

  case 56: /* simplecommand: "nop" "(" thing ")"  */
#line 705 "internparser.y"
                          {
			    (yyval.tree) = makeNopArg((yyvsp[-1].tree));
			  }
#line 4702 "internparser.c"
    break;

  case 57: /* simplecommand: "nop" "(" ")"  */
#line 709 "internparser.y"
                          {
			    (yyval.tree) = makeNopArg(makeDefault());
			  }
#line 4710 "internparser.c"
    break;

  case 58: /* simplecommand: "print" "(" thinglist ")"  */
#line 713 "internparser.y"
                          {
			    (yyval.tree) = makePrint((yyvsp[-1].list));
			  }
#line 4718 "internparser.c"
    break;

  case 59: /* simplecommand: "print" "(" thinglist ")" ">" thing  */
#line 717 "internparser.y"
                          {
			    (yyval.tree) = makeNewFilePrint((yyvsp[0].tree), (yyvsp[-3].list));
			  }
#line 4726 "internparser.c"
    break;

  case 60: /* simplecommand: "print" "(" thinglist ")" ">" ">" thing  */
#line 721 "internparser.y"
                          {
			    (yyval.tree) = makeAppendFilePrint((yyvsp[0].tree), (yyvsp[-4].list));
			  }
#line 4734 "internparser.c"
    break;

  case 61: /* simplecommand: "plot" "(" thing "," thinglist ")"  */
#line 725 "internparser.y"
                          {
			    (yyval.tree) = makePlot(addElement((yyvsp[-1].list), (yyvsp[-3].tree)));
			  }
#line 4742 "internparser.c"
    break;

  case 62: /* simplecommand: "printhexa" "(" thing ")"  */
#line 729 "internparser.y"
                          {
			    (yyval.tree) = makePrintHexa((yyvsp[-1].tree));
			  }
#line 4750 "internparser.c"
    break;

  case 63: /* simplecommand: "printfloat" "(" thing ")"  */
#line 733 "internparser.y"
                          {
			    (yyval.tree) = makePrintFloat((yyvsp[-1].tree));
			  }
#line 4758 "internparser.c"
    break;

  case 64: /* simplecommand: "printbinary" "(" thing ")"  */
#line 737 "internparser.y"
                          {
			    (yyval.tree) = makePrintBinary((yyvsp[-1].tree));
			  }
#line 4766 "internparser.c"
    break;

  case 65: /* simplecommand: "suppressmessage" "(" thinglist ")"  */
#line 741 "internparser.y"
                          {
			    (yyval.tree) = makeSuppressMessage((yyvsp[-1].list));
			  }
#line 4774 "internparser.c"
    break;

  case 66: /* simplecommand: "unsuppressmessage" "(" thinglist ")"  */
#line 745 "internparser.y"
                          {
			    (yyval.tree) = makeUnsuppressMessage((yyvsp[-1].list));
			  }
#line 4782 "internparser.c"
    break;

  case 67: /* simplecommand: "printexpansion" "(" thing ")"  */
#line 749 "internparser.y"
                          {
			    (yyval.tree) = makePrintExpansion((yyvsp[-1].tree));
			  }
#line 4790 "internparser.c"
    break;

  case 68: /* simplecommand: "bashexecute" "(" thing ")"  */
#line 753 "internparser.y"
                          {
			    (yyval.tree) = makeBashExecute((yyvsp[-1].tree));
			  }
#line 4798 "internparser.c"
    break;

  case 69: /* simplecommand: "externalplot" "(" thing "," thing "," thing "," thing "," thinglist ")"  */
#line 757 "internparser.y"
                          {
			    (yyval.tree) = makeExternalPlot(addElement(addElement(addElement(addElement((yyvsp[-1].list),(yyvsp[-3].tree)),(yyvsp[-5].tree)),(yyvsp[-7].tree)),(yyvsp[-9].tree)));
			  }
#line 4806 "internparser.c"
    break;

  case 70: /* simplecommand: "write" "(" thinglist ")"  */
#line 761 "internparser.y"
                          {
			    (yyval.tree) = makeWrite((yyvsp[-1].list));
			  }
#line 4814 "internparser.c"
    break;

  case 71: /* simplecommand: "write" "(" thinglist ")" ">" thing  */
#line 765 "internparser.y"
                          {
			    (yyval.tree) = makeNewFileWrite((yyvsp[0].tree), (yyvsp[-3].list));
			  }
#line 4822 "internparser.c"
    break;

  case 72: /* simplecommand: "write" "(" thinglist ")" ">" ">" thing  */
#line 769 "internparser.y"
                          {
			    (yyval.tree) = makeAppendFileWrite((yyvsp[0].tree), (yyvsp[-4].list));
			  }
#line 4830 "internparser.c"
    break;

  case 73: /* simplecommand: "asciiplot" "(" thing "," thing ")"  */
#line 773 "internparser.y"
                          {
			    (yyval.tree) = makeAsciiPlot((yyvsp[-3].tree), (yyvsp[-1].tree));
			  }
#line 4838 "internparser.c"
    break;

  case 74: /* simplecommand: "printxml" "(" thing ")"  */
#line 777 "internparser.y"
                          {
			    (yyval.tree) = makePrintXml((yyvsp[-1].tree));
			  }
#line 4846 "internparser.c"
    break;

  case 75: /* simplecommand: "execute" "(" thing ")"  */
#line 781 "internparser.y"
                          {
			    (yyval.tree) = makeExecute((yyvsp[-1].tree));
			  }
#line 4854 "internparser.c"
    break;

  case 76: /* simplecommand: "printxml" "(" thing ")" ">" thing  */
#line 785 "internparser.y"
                          {
			    (yyval.tree) = makePrintXmlNewFile((yyvsp[-3].tree),(yyvsp[0].tree));
			  }
#line 4862 "internparser.c"
    break;

  case 77: /* simplecommand: "printxml" "(" thing ")" ">" ">" thing  */
#line 789 "internparser.y"
                          {
			    (yyval.tree) = makePrintXmlAppendFile((yyvsp[-4].tree),(yyvsp[0].tree));
			  }
#line 4870 "internparser.c"
    break;

  case 78: /* simplecommand: "worstcase" "(" thing "," thing "," thing "," thing "," thinglist ")"  */
#line 793 "internparser.y"
                          {
			    (yyval.tree) = makeWorstCase(addElement(addElement(addElement(addElement((yyvsp[-1].list), (yyvsp[-3].tree)), (yyvsp[-5].tree)), (yyvsp[-7].tree)), (yyvsp[-9].tree)));
			  }
#line 4878 "internparser.c"
    break;

  case 79: /* simplecommand: "rename" "(" "identifier" "," "identifier" ")"  */
#line 797 "internparser.y"
                          {
			    (yyval.tree) = makeRename((yyvsp[-3].value), (yyvsp[-1].value));
			    safeFree((yyvsp[-3].value));
			    safeFree((yyvsp[-1].value));
			  }
#line 4888 "internparser.c"
    break;

  case 80: /* simplecommand: "rename" "(" "identifier" "," "_x_" ")"  */
#line 803 "internparser.y"
                          {
			    (yyval.tree) = makeRename((yyvsp[-3].value), "_x_");
			    safeFree((yyvsp[-3].value));
			  }
#line 4897 "internparser.c"
    break;

  case 81: /* simplecommand: "rename" "(" "_x_" "," "identifier" ")"  */
#line 808 "internparser.y"
                          {
			    (yyval.tree) = makeRename("_x_", (yyvsp[-1].value));
			    safeFree((yyvsp[-1].value));
			  }
#line 4906 "internparser.c"
    break;

  case 82: /* simplecommand: "rename" "(" "_x_" "," "_x_" ")"  */
#line 813 "internparser.y"
                          {
			    (yyval.tree) = makeRename("_x_", "_x_");
			  }
#line 4914 "internparser.c"
    break;

  case 83: /* simplecommand: "externalproc" "(" "identifier" "," thing "," externalproctypelist "-" ">" extendedexternalproctype ")"  */
#line 817 "internparser.y"
                          {
			    (yyval.tree) = makeExternalProc((yyvsp[-8].value), (yyvsp[-6].tree), addElement((yyvsp[-4].list), (yyvsp[-1].integerval)));
			    safeFree((yyvsp[-8].value));
			  }
#line 4923 "internparser.c"
    break;

  case 84: /* simplecommand: "externaldata" "(" "identifier" "," thing ")"  */
#line 822 "internparser.y"
                          {
			    (yyval.tree) = makeExternalData((yyvsp[-3].value), (yyvsp[-1].tree));
			    safeFree((yyvsp[-3].value));
			  }
#line 4932 "internparser.c"
    break;

  case 85: /* simplecommand: assignment  */
#line 827 "internparser.y"
                          {
			    (yyval.tree) = (yyvsp[0].tree);
			  }
#line 4940 "internparser.c"
    break;

  case 86: /* simplecommand: thinglist  */
#line 831 "internparser.y"
                          {
			    (yyval.tree) = makeAutoprint((yyvsp[0].list));
			  }
#line 4948 "internparser.c"
    break;

  case 87: /* simplecommand: "procedure" "identifier" procbody  */
#line 835 "internparser.y"
                          {
			    (yyval.tree) = makeAssignment((yyvsp[-1].value), (yyvsp[0].tree));
			    safeFree((yyvsp[-1].value));
			  }
#line 4957 "internparser.c"
    break;

  case 88: /* assignment: stateassignment  */
#line 842 "internparser.y"
                          {
			    (yyval.tree) = (yyvsp[0].tree);
			  }
#line 4965 "internparser.c"
    break;

  case 89: /* assignment: stillstateassignment "!"  */
#line 846 "internparser.y"
                          {
			    (yyval.tree) = (yyvsp[-1].tree);
			  }
#line 4973 "internparser.c"
    break;

  case 90: /* assignment: simpleassignment  */
#line 850 "internparser.y"
                          {
			    (yyval.tree) = (yyvsp[0].tree);
			  }
#line 4981 "internparser.c"
    break;

  case 91: /* assignment: simpleassignment "!"  */
#line 854 "internparser.y"
                          {
			    (yyval.tree) = (yyvsp[-1].tree);
			  }
#line 4989 "internparser.c"
    break;

  case 92: /* simpleassignment: "identifier" "=" thing  */
#line 860 "internparser.y"
                          {
			    (yyval.tree) = makeAssignment((yyvsp[-2].value), (yyvsp[0].tree));
			    safeFree((yyvsp[-2].value));
			  }
#line 4998 "internparser.c"
    break;

  case 93: /* simpleassignment: "identifier" ":=" thing  */
#line 865 "internparser.y"
                          {
			    (yyval.tree) = makeFloatAssignment((yyvsp[-2].value), (yyvsp[0].tree));
			    safeFree((yyvsp[-2].value));
			  }
#line 5007 "internparser.c"
    break;

  case 94: /* simpleassignment: "identifier" "=" "library" "(" thing ")"  */
#line 870 "internparser.y"
                          {
			    (yyval.tree) = makeLibraryBinding((yyvsp[-5].value), (yyvsp[-1].tree));
			    safeFree((yyvsp[-5].value));
			  }
#line 5016 "internparser.c"
    break;

  case 95: /* simpleassignment: "identifier" "=" "libraryconstant" "(" thing ")"  */
#line 875 "internparser.y"
                          {
			    (yyval.tree) = makeLibraryConstantBinding((yyvsp[-5].value), (yyvsp[-1].tree));
			    safeFree((yyvsp[-5].value));
			  }
#line 5025 "internparser.c"
    break;

  case 96: /* simpleassignment: indexing "=" thing  */
#line 880 "internparser.y"
                          {
			    (yyval.tree) = makeAssignmentInIndexing((yyvsp[-2].dblnode)->a,(yyvsp[-2].dblnode)->b,(yyvsp[0].tree));
			    safeFree((yyvsp[-2].dblnode));
			  }
#line 5034 "internparser.c"
    break;

  case 97: /* simpleassignment: indexing ":=" thing  */
#line 885 "internparser.y"
                          {
			    (yyval.tree) = makeFloatAssignmentInIndexing((yyvsp[-2].dblnode)->a,(yyvsp[-2].dblnode)->b,(yyvsp[0].tree));
			    safeFree((yyvsp[-2].dblnode));
			  }
#line 5043 "internparser.c"
    break;

  case 98: /* simpleassignment: structuring "=" thing  */
#line 890 "internparser.y"
                          {
			    (yyval.tree) = makeProtoAssignmentInStructure((yyvsp[-2].tree),(yyvsp[0].tree));
			  }
#line 5051 "internparser.c"
    break;

  case 99: /* simpleassignment: structuring ":=" thing  */
#line 894 "internparser.y"
                          {
			    (yyval.tree) = makeProtoFloatAssignmentInStructure((yyvsp[-2].tree),(yyvsp[0].tree));
			  }
#line 5059 "internparser.c"
    break;

  case 100: /* structuring: basicthing "." "identifier"  */
#line 900 "internparser.y"
                          {
			    (yyval.tree) = makeStructAccess((yyvsp[-2].tree),(yyvsp[0].value));
			    safeFree((yyvsp[0].value));
			  }
#line 5068 "internparser.c"
    break;

  case 101: /* stateassignment: "prec" "=" thing  */
#line 907 "internparser.y"
                          {
			    (yyval.tree) = makePrecAssign((yyvsp[0].tree));
			  }
#line 5076 "internparser.c"
    break;

  case 102: /* stateassignment: "points" "=" thing  */
#line 911 "internparser.y"
                          {
			    (yyval.tree) = makePointsAssign((yyvsp[0].tree));
			  }
#line 5084 "internparser.c"
    break;

  case 103: /* stateassignment: "diam" "=" thing  */
#line 915 "internparser.y"
                          {
			    (yyval.tree) = makeDiamAssign((yyvsp[0].tree));
			  }
#line 5092 "internparser.c"
    break;

  case 104: /* stateassignment: "display" "=" thing  */
#line 919 "internparser.y"
                          {
			    (yyval.tree) = makeDisplayAssign((yyvsp[0].tree));
			  }
#line 5100 "internparser.c"
    break;

  case 105: /* stateassignment: "verbosity" "=" thing  */
#line 923 "internparser.y"
                          {
			    (yyval.tree) = makeVerbosityAssign((yyvsp[0].tree));
			  }
#line 5108 "internparser.c"
    break;

  case 106: /* stateassignment: "showmessagenumbers" "=" thing  */
#line 927 "internparser.y"
                          {
			    (yyval.tree) = makeShowMessageNumbersAssign((yyvsp[0].tree));
			  }
#line 5116 "internparser.c"
    break;

  case 107: /* stateassignment: "canonical" "=" thing  */
#line 931 "internparser.y"
                          {
			    (yyval.tree) = makeCanonicalAssign((yyvsp[0].tree));
			  }
#line 5124 "internparser.c"
    break;

  case 108: /* stateassignment: "autosimplify" "=" thing  */
#line 935 "internparser.y"
                          {
			    (yyval.tree) = makeAutoSimplifyAssign((yyvsp[0].tree));
			  }
#line 5132 "internparser.c"
    break;

  case 109: /* stateassignment: "taylorrecursions" "=" thing  */
#line 939 "internparser.y"
                          {
			    (yyval.tree) = makeTaylorRecursAssign((yyvsp[0].tree));
			  }
#line 5140 "internparser.c"
    break;

  case 110: /* stateassignment: "timing" "=" thing  */
#line 943 "internparser.y"
                          {
			    (yyval.tree) = makeTimingAssign((yyvsp[0].tree));
			  }
#line 5148 "internparser.c"
    break;

  case 111: /* stateassignment: "fullparentheses" "=" thing  */
#line 947 "internparser.y"
                          {
			    (yyval.tree) = makeFullParenAssign((yyvsp[0].tree));
			  }
#line 5156 "internparser.c"
    break;

  case 112: /* stateassignment: "midpointmode" "=" thing  */
#line 951 "internparser.y"
                          {
			    (yyval.tree) = makeMidpointAssign((yyvsp[0].tree));
			  }
#line 5164 "internparser.c"
    break;

  case 113: /* stateassignment: "dieonerrormode" "=" thing  */
#line 955 "internparser.y"
                          {
			    (yyval.tree) = makeDieOnErrorAssign((yyvsp[0].tree));
			  }
#line 5172 "internparser.c"
    break;

  case 114: /* stateassignment: "rationalmode" "=" thing  */
#line 959 "internparser.y"
                          {
			    (yyval.tree) = makeRationalModeAssign((yyvsp[0].tree));
			  }
#line 5180 "internparser.c"
    break;

  case 115: /* stateassignment: "roundingwarnings" "=" thing  */
#line 963 "internparser.y"
                          {
			    (yyval.tree) = makeSuppressWarningsAssign((yyvsp[0].tree));
			  }
#line 5188 "internparser.c"
    break;

  case 116: /* stateassignment: "hopitalrecursions" "=" thing  */
#line 967 "internparser.y"
                          {
			    (yyval.tree) = makeHopitalRecursAssign((yyvsp[0].tree));
			  }
#line 5196 "internparser.c"
    break;

  case 117: /* stillstateassignment: "prec" "=" thing  */
#line 973 "internparser.y"
                          {
			    (yyval.tree) = makePrecStillAssign((yyvsp[0].tree));
			  }
#line 5204 "internparser.c"
    break;

  case 118: /* stillstateassignment: "points" "=" thing  */
#line 977 "internparser.y"
                          {
			    (yyval.tree) = makePointsStillAssign((yyvsp[0].tree));
			  }
#line 5212 "internparser.c"
    break;

  case 119: /* stillstateassignment: "diam" "=" thing  */
#line 981 "internparser.y"
                          {
			    (yyval.tree) = makeDiamStillAssign((yyvsp[0].tree));
			  }
#line 5220 "internparser.c"
    break;

  case 120: /* stillstateassignment: "display" "=" thing  */
#line 985 "internparser.y"
                          {
			    (yyval.tree) = makeDisplayStillAssign((yyvsp[0].tree));
			  }
#line 5228 "internparser.c"
    break;

  case 121: /* stillstateassignment: "verbosity" "=" thing  */
#line 989 "internparser.y"
                          {
			    (yyval.tree) = makeVerbosityStillAssign((yyvsp[0].tree));
			  }
#line 5236 "internparser.c"
    break;

  case 122: /* stillstateassignment: "showmessagenumbers" "=" thing  */
#line 993 "internparser.y"
                          {
			    (yyval.tree) = makeShowMessageNumbersStillAssign((yyvsp[0].tree));
			  }
#line 5244 "internparser.c"
    break;

  case 123: /* stillstateassignment: "canonical" "=" thing  */
#line 997 "internparser.y"
                          {
			    (yyval.tree) = makeCanonicalStillAssign((yyvsp[0].tree));
			  }
#line 5252 "internparser.c"
    break;

  case 124: /* stillstateassignment: "autosimplify" "=" thing  */
#line 1001 "internparser.y"
                          {
			    (yyval.tree) = makeAutoSimplifyStillAssign((yyvsp[0].tree));
			  }
#line 5260 "internparser.c"
    break;

  case 125: /* stillstateassignment: "taylorrecursions" "=" thing  */
#line 1005 "internparser.y"
                          {
			    (yyval.tree) = makeTaylorRecursStillAssign((yyvsp[0].tree));
			  }
#line 5268 "internparser.c"
    break;

  case 126: /* stillstateassignment: "timing" "=" thing  */
#line 1009 "internparser.y"
                          {
			    (yyval.tree) = makeTimingStillAssign((yyvsp[0].tree));
			  }
#line 5276 "internparser.c"
    break;

  case 127: /* stillstateassignment: "fullparentheses" "=" thing  */
#line 1013 "internparser.y"
                          {
			    (yyval.tree) = makeFullParenStillAssign((yyvsp[0].tree));
			  }
#line 5284 "internparser.c"
    break;

  case 128: /* stillstateassignment: "midpointmode" "=" thing  */
#line 1017 "internparser.y"
                          {
			    (yyval.tree) = makeMidpointStillAssign((yyvsp[0].tree));
			  }
#line 5292 "internparser.c"
    break;

  case 129: /* stillstateassignment: "dieonerrormode" "=" thing  */
#line 1021 "internparser.y"
                          {
			    (yyval.tree) = makeDieOnErrorStillAssign((yyvsp[0].tree));
			  }
#line 5300 "internparser.c"
    break;

  case 130: /* stillstateassignment: "rationalmode" "=" thing  */
#line 1025 "internparser.y"
                          {
			    (yyval.tree) = makeRationalModeStillAssign((yyvsp[0].tree));
			  }
#line 5308 "internparser.c"
    break;

  case 131: /* stillstateassignment: "roundingwarnings" "=" thing  */
#line 1029 "internparser.y"
                          {
			    (yyval.tree) = makeSuppressWarningsStillAssign((yyvsp[0].tree));
			  }
#line 5316 "internparser.c"
    break;

  case 132: /* stillstateassignment: "hopitalrecursions" "=" thing  */
#line 1033 "internparser.y"
                          {
			    (yyval.tree) = makeHopitalRecursStillAssign((yyvsp[0].tree));
			  }
#line 5324 "internparser.c"
    break;

  case 133: /* thinglist: thing  */
#line 1039 "internparser.y"
                          {
			    (yyval.list) = addElement(NULL, (yyvsp[0].tree));
			  }
#line 5332 "internparser.c"
    break;

  case 134: /* thinglist: thing "," thinglist  */
#line 1043 "internparser.y"
                          {
			    (yyval.list) = addElement((yyvsp[0].list), (yyvsp[-2].tree));
			  }
#line 5340 "internparser.c"
    break;

  case 135: /* structelementlist: structelement  */
#line 1049 "internparser.y"
                          {
			    (yyval.list) = addElement(NULL, (yyvsp[0].association));
			  }
#line 5348 "internparser.c"
    break;

  case 136: /* structelementlist: structelement structelementseparator structelementlist  */
#line 1053 "internparser.y"
                          {
			    (yyval.list) = addElement((yyvsp[0].list), (yyvsp[-2].association));
			  }
#line 5356 "internparser.c"
    break;

  case 137: /* structelementseparator: ","  */
#line 1059 "internparser.y"
                          {
			    (yyval.other) = NULL;
			  }
#line 5364 "internparser.c"
    break;

  case 138: /* structelementseparator: ";"  */
#line 1063 "internparser.y"
                          {
			    (yyval.other) = NULL;
			  }
#line 5372 "internparser.c"
    break;

  case 139: /* structelement: "." "identifier" "=" thing  */
#line 1069 "internparser.y"
                          {
			    (yyval.association) = (entry *) safeMalloc(sizeof(entry));
			    (yyval.association)->name = (char *) safeCalloc(strlen((yyvsp[-2].value)) + 1, sizeof(char));
			    strcpy((yyval.association)->name,(yyvsp[-2].value));
			    safeFree((yyvsp[-2].value));
			    (yyval.association)->value = (void *) ((yyvsp[0].tree));
			  }
#line 5384 "internparser.c"
    break;

  case 140: /* thing: supermegaterm  */
#line 1079 "internparser.y"
                         {
			   (yyval.tree) = (yyvsp[0].tree);
			 }
#line 5392 "internparser.c"
    break;

  case 141: /* thing: "match" supermegaterm "with" matchlist  */
#line 1083 "internparser.y"
                          {
			    (yyval.tree) = makeMatch((yyvsp[-2].tree),(yyvsp[0].list));
			  }
#line 5400 "internparser.c"
    break;

  case 142: /* supermegaterm: megaterm  */
#line 1089 "internparser.y"
                          {
			    (yyval.tree) = (yyvsp[0].tree);
			  }
#line 5408 "internparser.c"
    break;

  case 143: /* supermegaterm: thing "&&" megaterm  */
#line 1093 "internparser.y"
                          {
			    (yyval.tree) = makeAnd((yyvsp[-2].tree), (yyvsp[0].tree));
			  }
#line 5416 "internparser.c"
    break;

  case 144: /* supermegaterm: thing "||" megaterm  */
#line 1097 "internparser.y"
                          {
			    (yyval.tree) = makeOr((yyvsp[-2].tree), (yyvsp[0].tree));
			  }
#line 5424 "internparser.c"
    break;

  case 145: /* supermegaterm: "!" megaterm  */
#line 1101 "internparser.y"
                          {
			    (yyval.tree) = makeNegation((yyvsp[0].tree));
			  }
#line 5432 "internparser.c"
    break;

  case 146: /* indexing: basicthing "[" thing "]"  */
#line 1107 "internparser.y"
                          {
			    (yyval.dblnode) = (doubleNode *) safeMalloc(sizeof(doubleNode));
			    (yyval.dblnode)->a = (yyvsp[-3].tree);
			    (yyval.dblnode)->b = (yyvsp[-1].tree);
			  }
#line 5442 "internparser.c"
    break;

  case 147: /* megaterm: hyperterm  */
#line 1116 "internparser.y"
                          {
			    (yyval.tree) = (yyvsp[0].tree);
			  }
#line 5450 "internparser.c"
    break;

  case 148: /* megaterm: megaterm "==" hyperterm  */
#line 1120 "internparser.y"
                          {
			    (yyval.tree) = makeCompareEqual((yyvsp[-2].tree), (yyvsp[0].tree));
			  }
#line 5458 "internparser.c"
    break;

  case 149: /* megaterm: megaterm "in" hyperterm  */
#line 1124 "internparser.y"
                          {
			    (yyval.tree) = makeCompareIn((yyvsp[-2].tree), (yyvsp[0].tree));
			  }
#line 5466 "internparser.c"
    break;

  case 150: /* megaterm: megaterm "<" hyperterm  */
#line 1128 "internparser.y"
                          {
			    (yyval.tree) = makeCompareLess((yyvsp[-2].tree), (yyvsp[0].tree));
			  }
#line 5474 "internparser.c"
    break;

  case 151: /* megaterm: megaterm ">" hyperterm  */
#line 1132 "internparser.y"
                          {
			    (yyval.tree) = makeCompareGreater((yyvsp[-2].tree), (yyvsp[0].tree));
			  }
#line 5482 "internparser.c"
    break;

  case 152: /* megaterm: megaterm "<" "=" hyperterm  */
#line 1136 "internparser.y"
                          {
			    (yyval.tree) = makeCompareLessEqual((yyvsp[-3].tree), (yyvsp[0].tree));
			  }
#line 5490 "internparser.c"
    break;

  case 153: /* megaterm: megaterm ">" "=" hyperterm  */
#line 1140 "internparser.y"
                          {
			    (yyval.tree) = makeCompareGreaterEqual((yyvsp[-3].tree), (yyvsp[0].tree));
			  }
#line 5498 "internparser.c"
    break;

  case 154: /* megaterm: megaterm "!=" hyperterm  */
#line 1144 "internparser.y"
                          {
			    (yyval.tree) = makeCompareNotEqual((yyvsp[-2].tree), (yyvsp[0].tree));
			  }
#line 5506 "internparser.c"
    break;

  case 155: /* hyperterm: term  */
#line 1150 "internparser.y"
                          {
			    (yyval.tree) = (yyvsp[0].tree);
			  }
#line 5514 "internparser.c"
    break;

  case 156: /* hyperterm: hyperterm "+" term  */
#line 1154 "internparser.y"
                          {
			    (yyval.tree) = makeAdd((yyvsp[-2].tree), (yyvsp[0].tree));
			  }
#line 5522 "internparser.c"
    break;

  case 157: /* hyperterm: hyperterm "-" term  */
#line 1158 "internparser.y"
                          {
			    (yyval.tree) = makeSub((yyvsp[-2].tree), (yyvsp[0].tree));
			  }
#line 5530 "internparser.c"
    break;

  case 158: /* hyperterm: hyperterm "@" term  */
#line 1162 "internparser.y"
                          {
			    (yyval.tree) = makeConcat((yyvsp[-2].tree), (yyvsp[0].tree));
			  }
#line 5538 "internparser.c"
    break;

  case 159: /* hyperterm: hyperterm "::" term  */
#line 1166 "internparser.y"
                          {
			    (yyval.tree) = makeAddToList((yyvsp[-2].tree), (yyvsp[0].tree));
			  }
#line 5546 "internparser.c"
    break;

  case 160: /* hyperterm: hyperterm ":." term  */
#line 1170 "internparser.y"
                          {
			    (yyval.tree) = makeAppend((yyvsp[-2].tree), (yyvsp[0].tree));
			  }
#line 5554 "internparser.c"
    break;

  case 161: /* unaryplusminus: "+"  */
#line 1176 "internparser.y"
                          {
                            (yyval.count) = 0;
                          }
#line 5562 "internparser.c"
    break;

  case 162: /* unaryplusminus: "-"  */
#line 1180 "internparser.y"
                          {
                            (yyval.count) = 1;
                          }
#line 5570 "internparser.c"
    break;

  case 163: /* unaryplusminus: "+" unaryplusminus  */
#line 1184 "internparser.y"
                          {
  	                    (yyval.count) = (yyvsp[0].count);
  	                  }
#line 5578 "internparser.c"
    break;

  case 164: /* unaryplusminus: "-" unaryplusminus  */
#line 1188 "internparser.y"
                          {
  	                    (yyval.count) = (yyvsp[0].count)+1;
                          }
#line 5586 "internparser.c"
    break;

  case 165: /* term: subterm  */
#line 1195 "internparser.y"
                          {
			    (yyval.tree) = (yyvsp[0].tree);
                          }
#line 5594 "internparser.c"
    break;

  case 166: /* term: unaryplusminus subterm  */
#line 1199 "internparser.y"
                          {
			    tempNode = (yyvsp[0].tree);
			    for (tempInteger=0;tempInteger<(yyvsp[-1].count);tempInteger++)
			      tempNode = makeNeg(tempNode);
			    (yyval.tree) = tempNode;
			  }
#line 5605 "internparser.c"
    break;

  case 167: /* term: "~" subterm  */
#line 1206 "internparser.y"
                          {
			    (yyval.tree) = makeEvalConst((yyvsp[0].tree));
                          }
#line 5613 "internparser.c"
    break;

  case 168: /* term: term "*" subterm  */
#line 1210 "internparser.y"
                          {
			    (yyval.tree) = makeMul((yyvsp[-2].tree), (yyvsp[0].tree));
                          }
#line 5621 "internparser.c"
    break;

  case 169: /* term: term "/" subterm  */
#line 1214 "internparser.y"
                          {
			    (yyval.tree) = makeDiv((yyvsp[-2].tree), (yyvsp[0].tree));
                          }
#line 5629 "internparser.c"
    break;

  case 170: /* term: term "*" unaryplusminus subterm  */
#line 1218 "internparser.y"
                          {
			    tempNode = (yyvsp[0].tree);
			    for (tempInteger=0;tempInteger<(yyvsp[-1].count);tempInteger++)
			      tempNode = makeNeg(tempNode);
			    (yyval.tree) = makeMul((yyvsp[-3].tree), tempNode);
			  }
#line 5640 "internparser.c"
    break;

  case 171: /* term: term "/" unaryplusminus subterm  */
#line 1225 "internparser.y"
                          {
			    tempNode = (yyvsp[0].tree);
			    for (tempInteger=0;tempInteger<(yyvsp[-1].count);tempInteger++)
			      tempNode = makeNeg(tempNode);
			    (yyval.tree) = makeDiv((yyvsp[-3].tree), tempNode);
			  }
#line 5651 "internparser.c"
    break;

  case 172: /* term: term "*" "~" subterm  */
#line 1232 "internparser.y"
                          {
			    (yyval.tree) = makeMul((yyvsp[-3].tree), makeEvalConst((yyvsp[0].tree)));
			  }
#line 5659 "internparser.c"
    break;

  case 173: /* term: term "/" "~" subterm  */
#line 1236 "internparser.y"
                          {
			    (yyval.tree) = makeDiv((yyvsp[-3].tree), makeEvalConst((yyvsp[0].tree)));
			  }
#line 5667 "internparser.c"
    break;

  case 174: /* subterm: basicthing  */
#line 1242 "internparser.y"
                          {
			    (yyval.tree) = (yyvsp[0].tree);
                          }
#line 5675 "internparser.c"
    break;

  case 175: /* subterm: basicthing "^" subterm  */
#line 1246 "internparser.y"
                          {
			    (yyval.tree) = makePow((yyvsp[-2].tree), (yyvsp[0].tree));
                          }
#line 5683 "internparser.c"
    break;

  case 176: /* subterm: basicthing "^" unaryplusminus subterm  */
#line 1250 "internparser.y"
                          {
			    tempNode = (yyvsp[0].tree);
			    for (tempInteger=0;tempInteger<(yyvsp[-1].count);tempInteger++)
			      tempNode = makeNeg(tempNode);
			    (yyval.tree) = makePow((yyvsp[-3].tree), tempNode);
			  }
#line 5694 "internparser.c"
    break;

  case 177: /* subterm: basicthing "^" "~" subterm  */
#line 1257 "internparser.y"
                          {
			    (yyval.tree) = makePow((yyvsp[-3].tree), makeEvalConst((yyvsp[0].tree)));
			  }
#line 5702 "internparser.c"
    break;

  case 178: /* subterm: basicthing ".:" subterm  */
#line 1261 "internparser.y"
                          {
			    (yyval.tree) = makePrepend((yyvsp[-2].tree), (yyvsp[0].tree));
			  }
#line 5710 "internparser.c"
    break;

  case 179: /* subterm: basicthing ".:" "~" subterm  */
#line 1265 "internparser.y"
                          {
			    (yyval.tree) = makePrepend((yyvsp[-3].tree), makeEvalConst((yyvsp[0].tree)));
			  }
#line 5718 "internparser.c"
    break;

  case 180: /* basicthing: "on"  */
#line 1272 "internparser.y"
                          {
			    (yyval.tree) = makeOn();
			  }
#line 5726 "internparser.c"
    break;

  case 181: /* basicthing: "off"  */
#line 1276 "internparser.y"
                          {
			    (yyval.tree) = makeOff();
			  }
#line 5734 "internparser.c"
    break;

  case 182: /* basicthing: "dyadic"  */
#line 1280 "internparser.y"
                          {
			    (yyval.tree) = makeDyadic();
			  }
#line 5742 "internparser.c"
    break;

  case 183: /* basicthing: "powers"  */
#line 1284 "internparser.y"
                          {
			    (yyval.tree) = makePowers();
			  }
#line 5750 "internparser.c"
    break;

  case 184: /* basicthing: "binary"  */
#line 1288 "internparser.y"
                          {
			    (yyval.tree) = makeBinaryThing();
			  }
#line 5758 "internparser.c"
    break;

  case 185: /* basicthing: "hexadecimal"  */
#line 1292 "internparser.y"
                          {
			    (yyval.tree) = makeHexadecimalThing();
			  }
#line 5766 "internparser.c"
    break;

  case 186: /* basicthing: "file"  */
#line 1296 "internparser.y"
                          {
			    (yyval.tree) = makeFile();
			  }
#line 5774 "internparser.c"
    break;

  case 187: /* basicthing: "postscript"  */
#line 1300 "internparser.y"
                          {
			    (yyval.tree) = makePostscript();
			  }
#line 5782 "internparser.c"
    break;

  case 188: /* basicthing: "postscriptfile"  */
#line 1304 "internparser.y"
                          {
			    (yyval.tree) = makePostscriptFile();
			  }
#line 5790 "internparser.c"
    break;

  case 189: /* basicthing: "perturb"  */
#line 1308 "internparser.y"
                          {
			    (yyval.tree) = makePerturb();
			  }
#line 5798 "internparser.c"
    break;

  case 190: /* basicthing: "RD"  */
#line 1312 "internparser.y"
                          {
			    (yyval.tree) = makeRoundDown();
			  }
#line 5806 "internparser.c"
    break;

  case 191: /* basicthing: "RU"  */
#line 1316 "internparser.y"
                          {
			    (yyval.tree) = makeRoundUp();
			  }
#line 5814 "internparser.c"
    break;

  case 192: /* basicthing: "RZ"  */
#line 1320 "internparser.y"
                          {
			    (yyval.tree) = makeRoundToZero();
			  }
#line 5822 "internparser.c"
    break;

  case 193: /* basicthing: "RN"  */
#line 1324 "internparser.y"
                          {
			    (yyval.tree) = makeRoundToNearest();
			  }
#line 5830 "internparser.c"
    break;

  case 194: /* basicthing: "honorcoeffprec"  */
#line 1328 "internparser.y"
                          {
			    (yyval.tree) = makeHonorCoeff();
			  }
#line 5838 "internparser.c"
    break;

  case 195: /* basicthing: "true"  */
#line 1332 "internparser.y"
                          {
			    (yyval.tree) = makeTrue();
			  }
#line 5846 "internparser.c"
    break;

  case 196: /* basicthing: "void"  */
#line 1336 "internparser.y"
                          {
			    (yyval.tree) = makeUnit();
			  }
#line 5854 "internparser.c"
    break;

  case 197: /* basicthing: "false"  */
#line 1340 "internparser.y"
                          {
			    (yyval.tree) = makeFalse();
			  }
#line 5862 "internparser.c"
    break;

  case 198: /* basicthing: "default"  */
#line 1344 "internparser.y"
                          {
			    (yyval.tree) = makeDefault();
			  }
#line 5870 "internparser.c"
    break;

  case 199: /* basicthing: "decimal"  */
#line 1348 "internparser.y"
                          {
			    (yyval.tree) = makeDecimal();
			  }
#line 5878 "internparser.c"
    break;

  case 200: /* basicthing: "absolute"  */
#line 1352 "internparser.y"
                          {
			    (yyval.tree) = makeAbsolute();
			  }
#line 5886 "internparser.c"
    break;

  case 201: /* basicthing: "relative"  */
#line 1356 "internparser.y"
                          {
			    (yyval.tree) = makeRelative();
			  }
#line 5894 "internparser.c"
    break;

  case 202: /* basicthing: "fixed"  */
#line 1360 "internparser.y"
                          {
			    (yyval.tree) = makeFixed();
			  }
#line 5902 "internparser.c"
    break;

  case 203: /* basicthing: "floating"  */
#line 1364 "internparser.y"
                          {
			    (yyval.tree) = makeFloating();
			  }
#line 5910 "internparser.c"
    break;

  case 204: /* basicthing: "error"  */
#line 1368 "internparser.y"
                          {
			    (yyval.tree) = makeError();
			  }
#line 5918 "internparser.c"
    break;

  case 205: /* basicthing: "D"  */
#line 1372 "internparser.y"
                          {
			    (yyval.tree) = makeDoubleSymbol();
			  }
#line 5926 "internparser.c"
    break;

  case 206: /* basicthing: "SG"  */
#line 1376 "internparser.y"
                          {
			    (yyval.tree) = makeSingleSymbol();
			  }
#line 5934 "internparser.c"
    break;

  case 207: /* basicthing: "QD"  */
#line 1380 "internparser.y"
                          {
			    (yyval.tree) = makeQuadSymbol();
			  }
#line 5942 "internparser.c"
    break;

  case 208: /* basicthing: "HP"  */
#line 1384 "internparser.y"
                          {
			    (yyval.tree) = makeHalfPrecisionSymbol();
			  }
#line 5950 "internparser.c"
    break;

  case 209: /* basicthing: "DE"  */
#line 1388 "internparser.y"
                          {
			    (yyval.tree) = makeDoubleextendedSymbol();
			  }
#line 5958 "internparser.c"
    break;

  case 210: /* basicthing: "_x_"  */
#line 1392 "internparser.y"
                          {
			    (yyval.tree) = makeVariable();
			  }
#line 5966 "internparser.c"
    break;

  case 211: /* basicthing: "DD"  */
#line 1396 "internparser.y"
                          {
			    (yyval.tree) = makeDoubleDoubleSymbol();
			  }
#line 5974 "internparser.c"
    break;

  case 212: /* basicthing: "TD"  */
#line 1400 "internparser.y"
                          {
			    (yyval.tree) = makeTripleDoubleSymbol();
			  }
#line 5982 "internparser.c"
    break;

  case 213: /* basicthing: "character string"  */
#line 1404 "internparser.y"
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
#line 5997 "internparser.c"
    break;

  case 214: /* basicthing: constant  */
#line 1415 "internparser.y"
                          {
			    (yyval.tree) = (yyvsp[0].tree);
			  }
#line 6005 "internparser.c"
    break;

  case 215: /* basicthing: "identifier"  */
#line 1419 "internparser.y"
                          {
			    (yyval.tree) = makeTableAccess((yyvsp[0].value));
			    safeFree((yyvsp[0].value));
			  }
#line 6014 "internparser.c"
    break;

  case 216: /* basicthing: "isbound" "(" "identifier" ")"  */
#line 1424 "internparser.y"
                          {
			    (yyval.tree) = makeIsBound((yyvsp[-1].value));
			    safeFree((yyvsp[-1].value));
			  }
#line 6023 "internparser.c"
    break;

  case 217: /* basicthing: "identifier" "(" thinglist ")"  */
#line 1429 "internparser.y"
                          {
			    (yyval.tree) = makeTableAccessWithSubstitute((yyvsp[-3].value), (yyvsp[-1].list));
			    safeFree((yyvsp[-3].value));
			  }
#line 6032 "internparser.c"
    break;

  case 218: /* basicthing: "identifier" "(" ")"  */
#line 1434 "internparser.y"
                          {
			    (yyval.tree) = makeTableAccessWithSubstitute((yyvsp[-2].value), NULL);
			    safeFree((yyvsp[-2].value));
			  }
#line 6041 "internparser.c"
    break;

  case 219: /* basicthing: list  */
#line 1439 "internparser.y"
                          {
			    (yyval.tree) = (yyvsp[0].tree);
			  }
#line 6049 "internparser.c"
    break;

  case 220: /* basicthing: range  */
#line 1443 "internparser.y"
                          {
			    (yyval.tree) = (yyvsp[0].tree);
			  }
#line 6057 "internparser.c"
    break;

  case 221: /* basicthing: debound  */
#line 1447 "internparser.y"
                          {
			    (yyval.tree) = (yyvsp[0].tree);
			  }
#line 6065 "internparser.c"
    break;

  case 222: /* basicthing: headfunction  */
#line 1451 "internparser.y"
                          {
			    (yyval.tree) = (yyvsp[0].tree);
			  }
#line 6073 "internparser.c"
    break;

  case 223: /* basicthing: "(" thing ")"  */
#line 1455 "internparser.y"
                          {
			    (yyval.tree) = (yyvsp[-1].tree);
			  }
#line 6081 "internparser.c"
    break;

  case 224: /* basicthing: "{" structelementlist "}"  */
#line 1459 "internparser.y"
                          {
			    (yyval.tree) = makeStructure((yyvsp[-1].list));
			  }
#line 6089 "internparser.c"
    break;

  case 225: /* basicthing: statedereference  */
#line 1463 "internparser.y"
                          {
			    (yyval.tree) = (yyvsp[0].tree);
			  }
#line 6097 "internparser.c"
    break;

  case 226: /* basicthing: indexing  */
#line 1467 "internparser.y"
                          {
			    (yyval.tree) = makeIndex((yyvsp[0].dblnode)->a, (yyvsp[0].dblnode)->b);
			    safeFree((yyvsp[0].dblnode));
			  }
#line 6106 "internparser.c"
    break;

  case 227: /* basicthing: basicthing "." "identifier"  */
#line 1472 "internparser.y"
                          {
			    (yyval.tree) = makeStructAccess((yyvsp[-2].tree),(yyvsp[0].value));
			    safeFree((yyvsp[0].value));
			  }
#line 6115 "internparser.c"
    break;

  case 228: /* basicthing: basicthing "." "identifier" "(" ")"  */
#line 1477 "internparser.y"
                          {
			    (yyval.tree) = makeApply(makeStructAccess((yyvsp[-4].tree),(yyvsp[-2].value)),addElement(NULL, makeUnit()));
			    safeFree((yyvsp[-2].value));
			  }
#line 6124 "internparser.c"
    break;

  case 229: /* basicthing: basicthing "." "identifier" "(" thinglist ")"  */
#line 1482 "internparser.y"
                          {
			    (yyval.tree) = makeApply(makeStructAccess((yyvsp[-5].tree),(yyvsp[-3].value)),(yyvsp[-1].list));
			    safeFree((yyvsp[-3].value));
			  }
#line 6133 "internparser.c"
    break;

  case 230: /* basicthing: "(" thing ")" "(" thinglist ")"  */
#line 1487 "internparser.y"
                          {
			    (yyval.tree) = makeApply((yyvsp[-4].tree),(yyvsp[-1].list));
			  }
#line 6141 "internparser.c"
    break;

  case 231: /* basicthing: "(" thing ")" "(" ")"  */
#line 1491 "internparser.y"
                          {
			    (yyval.tree) = makeApply((yyvsp[-3].tree),addElement(NULL,makeUnit()));
			  }
#line 6149 "internparser.c"
    break;

  case 232: /* basicthing: "proc" procbody  */
#line 1495 "internparser.y"
                          {
			    (yyval.tree) = (yyvsp[0].tree);
			  }
#line 6157 "internparser.c"
    break;

  case 233: /* basicthing: "time" "(" command ")"  */
#line 1499 "internparser.y"
                          {
			    (yyval.tree) = makeTime((yyvsp[-1].tree));
                          }
#line 6165 "internparser.c"
    break;

  case 234: /* matchlist: matchelement  */
#line 1505 "internparser.y"
                          {
			    (yyval.list) = addElement(NULL,(yyvsp[0].tree));
			  }
#line 6173 "internparser.c"
    break;

  case 235: /* matchlist: matchelement matchlist  */
#line 1509 "internparser.y"
                          {
			    (yyval.list) = addElement((yyvsp[0].list),(yyvsp[-1].tree));
			  }
#line 6181 "internparser.c"
    break;

  case 236: /* matchelement: thing ":" beginsymbol variabledeclarationlist commandlist "return" thing ";" endsymbol  */
#line 1515 "internparser.y"
                          {
			    (yyval.tree) = makeMatchElement((yyvsp[-8].tree),makeCommandList(concatChains((yyvsp[-5].list), (yyvsp[-4].list))),(yyvsp[-2].tree));
			  }
#line 6189 "internparser.c"
    break;

  case 237: /* matchelement: thing ":" beginsymbol variabledeclarationlist commandlist endsymbol  */
#line 1519 "internparser.y"
                          {
			    (yyval.tree) = makeMatchElement((yyvsp[-5].tree),makeCommandList(concatChains((yyvsp[-2].list), (yyvsp[-1].list))),makeUnit());
			  }
#line 6197 "internparser.c"
    break;

  case 238: /* matchelement: thing ":" beginsymbol variabledeclarationlist "return" thing ";" endsymbol  */
#line 1523 "internparser.y"
                          {
			    (yyval.tree) = makeMatchElement((yyvsp[-7].tree),makeCommandList((yyvsp[-4].list)),(yyvsp[-2].tree));
			  }
#line 6205 "internparser.c"
    break;

  case 239: /* matchelement: thing ":" beginsymbol variabledeclarationlist endsymbol  */
#line 1527 "internparser.y"
                          {
			    (yyval.tree) = makeMatchElement((yyvsp[-4].tree),makeCommandList((yyvsp[-1].list)),makeUnit());
			  }
#line 6213 "internparser.c"
    break;

  case 240: /* matchelement: thing ":" beginsymbol commandlist "return" thing ";" endsymbol  */
#line 1531 "internparser.y"
                          {
			    (yyval.tree) = makeMatchElement((yyvsp[-7].tree),makeCommandList((yyvsp[-4].list)),(yyvsp[-2].tree));
			  }
#line 6221 "internparser.c"
    break;

  case 241: /* matchelement: thing ":" beginsymbol commandlist endsymbol  */
#line 1535 "internparser.y"
                          {
			    (yyval.tree) = makeMatchElement((yyvsp[-4].tree),makeCommandList((yyvsp[-1].list)),makeUnit());
			  }
#line 6229 "internparser.c"
    break;

  case 242: /* matchelement: thing ":" beginsymbol "return" thing ";" endsymbol  */
#line 1539 "internparser.y"
                          {
			    (yyval.tree) = makeMatchElement((yyvsp[-6].tree), makeCommandList(addElement(NULL,makeNop())), (yyvsp[-2].tree));
			  }
#line 6237 "internparser.c"
    break;

  case 243: /* matchelement: thing ":" beginsymbol endsymbol  */
#line 1543 "internparser.y"
                          {
			    (yyval.tree) = makeMatchElement((yyvsp[-3].tree), makeCommandList(addElement(NULL,makeNop())), makeUnit());
			  }
#line 6245 "internparser.c"
    break;

  case 244: /* matchelement: thing ":" "(" thing ")"  */
#line 1547 "internparser.y"
                          {
			    (yyval.tree) = makeMatchElement((yyvsp[-4].tree), makeCommandList(addElement(NULL,makeNop())), (yyvsp[-1].tree));
			  }
#line 6253 "internparser.c"
    break;

  case 245: /* constant: "decimal constant"  */
#line 1553 "internparser.y"
                          {
			    (yyval.tree) = makeDecimalConstant((yyvsp[0].value));
			    safeFree((yyvsp[0].value));
			  }
#line 6262 "internparser.c"
    break;

  case 246: /* constant: "interval"  */
#line 1558 "internparser.y"
                          {
			    (yyval.tree) = makeMidpointConstant((yyvsp[0].value));
			    safeFree((yyvsp[0].value));
			  }
#line 6271 "internparser.c"
    break;

  case 247: /* constant: "dyadic constant"  */
#line 1563 "internparser.y"
                          {
			    (yyval.tree) = makeDyadicConstant((yyvsp[0].value));
			    safeFree((yyvsp[0].value));
			  }
#line 6280 "internparser.c"
    break;

  case 248: /* constant: "constant in memory notation"  */
#line 1568 "internparser.y"
                          {
			    (yyval.tree) = makeHexConstant((yyvsp[0].value));
			    safeFree((yyvsp[0].value));
			  }
#line 6289 "internparser.c"
    break;

  case 249: /* constant: "hexadecimal constant"  */
#line 1573 "internparser.y"
                          {
			    (yyval.tree) = makeHexadecimalConstant((yyvsp[0].value));
			    safeFree((yyvsp[0].value));
			  }
#line 6298 "internparser.c"
    break;

  case 250: /* constant: "binary constant"  */
#line 1578 "internparser.y"
                          {
			    (yyval.tree) = makeBinaryConstant((yyvsp[0].value));
			    safeFree((yyvsp[0].value));
			  }
#line 6307 "internparser.c"
    break;

  case 251: /* constant: "pi"  */
#line 1583 "internparser.y"
                          {
			    (yyval.tree) = makePi();
			  }
#line 6315 "internparser.c"
    break;

  case 252: /* list: "[" "|" "|" "]"  */
#line 1591 "internparser.y"
                          {
			    (yyval.tree) = makeEmptyList();
			  }
#line 6323 "internparser.c"
    break;

  case 253: /* list: "[" "||" "]"  */
#line 1595 "internparser.y"
                          {
			    (yyval.tree) = makeEmptyList();
			  }
#line 6331 "internparser.c"
    break;

  case 254: /* list: "[" "|" simplelist "|" "]"  */
#line 1599 "internparser.y"
                          {
			    (yyval.tree) = makeRevertedList((yyvsp[-2].list));
			  }
#line 6339 "internparser.c"
    break;

  case 255: /* list: "[" "|" simplelist "..." "|" "]"  */
#line 1603 "internparser.y"
                          {
			    (yyval.tree) = makeRevertedFinalEllipticList((yyvsp[-3].list));
			  }
#line 6347 "internparser.c"
    break;

  case 256: /* simplelist: thing  */
#line 1609 "internparser.y"
                          {
			    (yyval.list) = addElement(NULL, (yyvsp[0].tree));
			  }
#line 6355 "internparser.c"
    break;

  case 257: /* simplelist: simplelist "," thing  */
#line 1613 "internparser.y"
                          {
			    (yyval.list) = addElement((yyvsp[-2].list), (yyvsp[0].tree));
			  }
#line 6363 "internparser.c"
    break;

  case 258: /* simplelist: simplelist "," "..." "," thing  */
#line 1617 "internparser.y"
                          {
			    (yyval.list) = addElement(addElement((yyvsp[-4].list), makeElliptic()), (yyvsp[0].tree));
			  }
#line 6371 "internparser.c"
    break;

  case 259: /* range: "[" thing "," thing "]"  */
#line 1623 "internparser.y"
                          {
			    (yyval.tree) = makeRange((yyvsp[-3].tree), (yyvsp[-1].tree));
			  }
#line 6379 "internparser.c"
    break;

  case 260: /* range: "[" thing ";" thing "]"  */
#line 1627 "internparser.y"
                          {
			    (yyval.tree) = makeRange((yyvsp[-3].tree), (yyvsp[-1].tree));
			  }
#line 6387 "internparser.c"
    break;

  case 261: /* range: "[" thing "]"  */
#line 1631 "internparser.y"
                          {
			    (yyval.tree) = makeRange((yyvsp[-1].tree), copyThing((yyvsp[-1].tree)));
			  }
#line 6395 "internparser.c"
    break;

  case 262: /* debound: "*<" thing ">*"  */
#line 1637 "internparser.y"
                          {
			    (yyval.tree) = makeDeboundMax((yyvsp[-1].tree));
			  }
#line 6403 "internparser.c"
    break;

  case 263: /* debound: "*<" thing ">."  */
#line 1641 "internparser.y"
                          {
			    (yyval.tree) = makeDeboundMid((yyvsp[-1].tree));
			  }
#line 6411 "internparser.c"
    break;

  case 264: /* debound: "*<" thing ">_"  */
#line 1645 "internparser.y"
                          {
			    (yyval.tree) = makeDeboundMin((yyvsp[-1].tree));
			  }
#line 6419 "internparser.c"
    break;

  case 265: /* debound: "sup" "(" thing ")"  */
#line 1649 "internparser.y"
                          {
			    (yyval.tree) = makeDeboundMax((yyvsp[-1].tree));
			  }
#line 6427 "internparser.c"
    break;

  case 266: /* debound: "mid" "(" thing ")"  */
#line 1653 "internparser.y"
                          {
			    (yyval.tree) = makeDeboundMid((yyvsp[-1].tree));
			  }
#line 6435 "internparser.c"
    break;

  case 267: /* debound: "inf" "(" thing ")"  */
#line 1657 "internparser.y"
                          {
			    (yyval.tree) = makeDeboundMin((yyvsp[-1].tree));
			  }
#line 6443 "internparser.c"
    break;

  case 268: /* headfunction: "diff" "(" thing ")"  */
#line 1663 "internparser.y"
                          {
			    (yyval.tree) = makeDiff((yyvsp[-1].tree));
			  }
#line 6451 "internparser.c"
    break;

  case 269: /* headfunction: "bashevaluate" "(" thing ")"  */
#line 1667 "internparser.y"
                          {
			    (yyval.tree) = makeBashevaluate(addElement(NULL,(yyvsp[-1].tree)));
			  }
#line 6459 "internparser.c"
    break;

  case 270: /* headfunction: "getsuppressedmessages" "(" ")"  */
#line 1671 "internparser.y"
                          {
			    (yyval.tree) = makeGetSuppressedMessages();
			  }
#line 6467 "internparser.c"
    break;

  case 271: /* headfunction: "getbacktrace" "(" ")"  */
#line 1675 "internparser.y"
                          {
			    (yyval.tree) = makeGetBacktrace();
			  }
#line 6475 "internparser.c"
    break;

  case 272: /* headfunction: "bashevaluate" "(" thing "," thing ")"  */
#line 1679 "internparser.y"
                          {
			    (yyval.tree) = makeBashevaluate(addElement(addElement(NULL,(yyvsp[-1].tree)),(yyvsp[-3].tree)));
			  }
#line 6483 "internparser.c"
    break;

  case 273: /* headfunction: "dirtysimplify" "(" thing ")"  */
#line 1683 "internparser.y"
                          {
			    (yyval.tree) = makeDirtysimplify((yyvsp[-1].tree));
			  }
#line 6491 "internparser.c"
    break;

  case 274: /* headfunction: "remez" "(" thing "," thing "," thinglist ")"  */
#line 1687 "internparser.y"
                          {
			    (yyval.tree) = makeRemez(addElement(addElement((yyvsp[-1].list), (yyvsp[-3].tree)), (yyvsp[-5].tree)));
			  }
#line 6499 "internparser.c"
    break;

  case 275: /* headfunction: "annotatefunction" "(" thing "," thing "," thing "," thinglist ")"  */
#line 1691 "internparser.y"
                          {
			    (yyval.tree) = makeAnnotateFunction(addElement(addElement(addElement((yyvsp[-1].list), (yyvsp[-3].tree)), (yyvsp[-5].tree)), (yyvsp[-7].tree)));
			  }
#line 6507 "internparser.c"
    break;

  case 276: /* headfunction: "bind" "(" thing "," "identifier" "," thing ")"  */
#line 1695 "internparser.y"
                          {
			    (yyval.tree) = makeBind((yyvsp[-5].tree), (yyvsp[-3].value), (yyvsp[-1].tree));
			    safeFree((yyvsp[-3].value));
			  }
#line 6516 "internparser.c"
    break;

  case 277: /* headfunction: "min" "(" thinglist ")"  */
#line 1700 "internparser.y"
                          {
			    (yyval.tree) = makeMin((yyvsp[-1].list));
			  }
#line 6524 "internparser.c"
    break;

  case 278: /* headfunction: "max" "(" thinglist ")"  */
#line 1704 "internparser.y"
                          {
			    (yyval.tree) = makeMax((yyvsp[-1].list));
			  }
#line 6532 "internparser.c"
    break;

  case 279: /* headfunction: "fpminimax" "(" thing "," thing "," thing "," thinglist ")"  */
#line 1708 "internparser.y"
                          {
			    (yyval.tree) = makeFPminimax(addElement(addElement(addElement((yyvsp[-1].list), (yyvsp[-3].tree)), (yyvsp[-5].tree)), (yyvsp[-7].tree)));
			  }
#line 6540 "internparser.c"
    break;

  case 280: /* headfunction: "horner" "(" thing ")"  */
#line 1712 "internparser.y"
                          {
			    (yyval.tree) = makeHorner((yyvsp[-1].tree));
			  }
#line 6548 "internparser.c"
    break;

  case 281: /* headfunction: "canonical" "(" thing ")"  */
#line 1716 "internparser.y"
                          {
			    (yyval.tree) = makeCanonicalThing((yyvsp[-1].tree));
			  }
#line 6556 "internparser.c"
    break;

  case 282: /* headfunction: "expand" "(" thing ")"  */
#line 1720 "internparser.y"
                          {
			    (yyval.tree) = makeExpand((yyvsp[-1].tree));
			  }
#line 6564 "internparser.c"
    break;

  case 283: /* headfunction: "simplify" "(" thing ")"  */
#line 1724 "internparser.y"
                          {
			    (yyval.tree) = makeSimplifySafe((yyvsp[-1].tree));
			  }
#line 6572 "internparser.c"
    break;

  case 284: /* headfunction: "taylor" "(" thing "," thing "," thing ")"  */
#line 1728 "internparser.y"
                          {
			    (yyval.tree) = makeTaylor((yyvsp[-5].tree), (yyvsp[-3].tree), (yyvsp[-1].tree));
			  }
#line 6580 "internparser.c"
    break;

  case 285: /* headfunction: "taylorform" "(" thing "," thing "," thinglist ")"  */
#line 1732 "internparser.y"
                          {
                            (yyval.tree) = makeTaylorform(addElement(addElement((yyvsp[-1].list), (yyvsp[-3].tree)), (yyvsp[-5].tree)));
			  }
#line 6588 "internparser.c"
    break;

  case 286: /* headfunction: "chebyshevform" "(" thing "," thing "," thing ")"  */
#line 1736 "internparser.y"
                          {
                            (yyval.tree) = makeChebyshevform(addElement(addElement(addElement(NULL, (yyvsp[-1].tree)), (yyvsp[-3].tree)), (yyvsp[-5].tree)));
			  }
#line 6596 "internparser.c"
    break;

  case 287: /* headfunction: "autodiff" "(" thing "," thing "," thing ")"  */
#line 1740 "internparser.y"
                          {
                            (yyval.tree) = makeAutodiff(addElement(addElement(addElement(NULL, (yyvsp[-1].tree)), (yyvsp[-3].tree)), (yyvsp[-5].tree)));
			  }
#line 6604 "internparser.c"
    break;

  case 288: /* headfunction: "degree" "(" thing ")"  */
#line 1744 "internparser.y"
                          {
			    (yyval.tree) = makeDegree((yyvsp[-1].tree));
			  }
#line 6612 "internparser.c"
    break;

  case 289: /* headfunction: "numerator" "(" thing ")"  */
#line 1748 "internparser.y"
                          {
			    (yyval.tree) = makeNumerator((yyvsp[-1].tree));
			  }
#line 6620 "internparser.c"
    break;

  case 290: /* headfunction: "denominator" "(" thing ")"  */
#line 1752 "internparser.y"
                          {
			    (yyval.tree) = makeDenominator((yyvsp[-1].tree));
			  }
#line 6628 "internparser.c"
    break;

  case 291: /* headfunction: "substitute" "(" thing "," thing ")"  */
#line 1756 "internparser.y"
                          {
			    (yyval.tree) = makeSubstitute((yyvsp[-3].tree), (yyvsp[-1].tree));
			  }
#line 6636 "internparser.c"
    break;

  case 292: /* headfunction: "composepolynomials" "(" thing "," thing ")"  */
#line 1760 "internparser.y"
                          {
			    (yyval.tree) = makeComposePolynomials((yyvsp[-3].tree), (yyvsp[-1].tree));
			  }
#line 6644 "internparser.c"
    break;

  case 293: /* headfunction: "bezout" "(" thing "," thing ")"  */
#line 1764 "internparser.y"
                          {
			    (yyval.tree) = makeBezout((yyvsp[-3].tree), (yyvsp[-1].tree));
			  }
#line 6652 "internparser.c"
    break;

  case 294: /* headfunction: "coeff" "(" thing "," thing ")"  */
#line 1768 "internparser.y"
                          {
			    (yyval.tree) = makeCoeff((yyvsp[-3].tree), (yyvsp[-1].tree));
			  }
#line 6660 "internparser.c"
    break;

  case 295: /* headfunction: "subpoly" "(" thing "," thing ")"  */
#line 1772 "internparser.y"
                          {
			    (yyval.tree) = makeSubpoly((yyvsp[-3].tree), (yyvsp[-1].tree));
			  }
#line 6668 "internparser.c"
    break;

  case 296: /* headfunction: "roundcoefficients" "(" thing "," thing ")"  */
#line 1776 "internparser.y"
                          {
			    (yyval.tree) = makeRoundcoefficients((yyvsp[-3].tree), (yyvsp[-1].tree));
			  }
#line 6676 "internparser.c"
    break;

  case 297: /* headfunction: "rationalapprox" "(" thing "," thing ")"  */
#line 1780 "internparser.y"
                          {
			    (yyval.tree) = makeRationalapprox((yyvsp[-3].tree), (yyvsp[-1].tree));
			  }
#line 6684 "internparser.c"
    break;

  case 298: /* headfunction: "accurateinfnorm" "(" thing "," thing "," thinglist ")"  */
#line 1784 "internparser.y"
                          {
			    (yyval.tree) = makeAccurateInfnorm(addElement(addElement((yyvsp[-1].list), (yyvsp[-3].tree)), (yyvsp[-5].tree)));
			  }
#line 6692 "internparser.c"
    break;

  case 299: /* headfunction: "round" "(" thing "," thing "," thing ")"  */
#line 1788 "internparser.y"
                          {
			    (yyval.tree) = makeRoundToFormat((yyvsp[-5].tree), (yyvsp[-3].tree), (yyvsp[-1].tree));
			  }
#line 6700 "internparser.c"
    break;

  case 300: /* headfunction: "evaluate" "(" thing "," thing ")"  */
#line 1792 "internparser.y"
                          {
			    (yyval.tree) = makeEvaluate((yyvsp[-3].tree), (yyvsp[-1].tree));
			  }
#line 6708 "internparser.c"
    break;

  case 301: /* headfunction: "parse" "(" thing ")"  */
#line 1796 "internparser.y"
                          {
			    (yyval.tree) = makeParse((yyvsp[-1].tree));
			  }
#line 6716 "internparser.c"
    break;

  case 302: /* headfunction: "readxml" "(" thing ")"  */
#line 1800 "internparser.y"
                          {
			    (yyval.tree) = makeReadXml((yyvsp[-1].tree));
			  }
#line 6724 "internparser.c"
    break;

  case 303: /* headfunction: "infnorm" "(" thing "," thinglist ")"  */
#line 1804 "internparser.y"
                          {
			    (yyval.tree) = makeInfnorm(addElement((yyvsp[-1].list), (yyvsp[-3].tree)));
			  }
#line 6732 "internparser.c"
    break;

  case 304: /* headfunction: "supnorm" "(" thing "," thing "," thing "," thing "," thing ")"  */
#line 1808 "internparser.y"
                          {
			    (yyval.tree) = makeSupnorm(addElement(addElement(addElement(addElement(addElement(NULL,(yyvsp[-1].tree)),(yyvsp[-3].tree)),(yyvsp[-5].tree)),(yyvsp[-7].tree)),(yyvsp[-9].tree)));
			  }
#line 6740 "internparser.c"
    break;

  case 305: /* headfunction: "findzeros" "(" thing "," thing ")"  */
#line 1812 "internparser.y"
                          {
			    (yyval.tree) = makeFindZeros((yyvsp[-3].tree), (yyvsp[-1].tree));
			  }
#line 6748 "internparser.c"
    break;

  case 306: /* headfunction: "fpfindzeros" "(" thing "," thing ")"  */
#line 1816 "internparser.y"
                          {
			    (yyval.tree) = makeFPFindZeros((yyvsp[-3].tree), (yyvsp[-1].tree));
			  }
#line 6756 "internparser.c"
    break;

  case 307: /* headfunction: "dirtyinfnorm" "(" thing "," thing ")"  */
#line 1820 "internparser.y"
                          {
			    (yyval.tree) = makeDirtyInfnorm((yyvsp[-3].tree), (yyvsp[-1].tree));
			  }
#line 6764 "internparser.c"
    break;

  case 308: /* headfunction: "gcd" "(" thing "," thing ")"  */
#line 1824 "internparser.y"
                          {
			    (yyval.tree) = makeGcd((yyvsp[-3].tree), (yyvsp[-1].tree));
			  }
#line 6772 "internparser.c"
    break;

  case 309: /* headfunction: "div" "(" thing "," thing ")"  */
#line 1828 "internparser.y"
                          {
			    (yyval.tree) = makeEuclDiv((yyvsp[-3].tree), (yyvsp[-1].tree));
			  }
#line 6780 "internparser.c"
    break;

  case 310: /* headfunction: "mod" "(" thing "," thing ")"  */
#line 1832 "internparser.y"
                          {
			    (yyval.tree) = makeEuclMod((yyvsp[-3].tree), (yyvsp[-1].tree));
			  }
#line 6788 "internparser.c"
    break;

  case 311: /* headfunction: "numberroots" "(" thing "," thing ")"  */
#line 1836 "internparser.y"
                          {
			    (yyval.tree) = makeNumberRoots((yyvsp[-3].tree), (yyvsp[-1].tree));
			  }
#line 6796 "internparser.c"
    break;

  case 312: /* headfunction: "integral" "(" thing "," thing ")"  */
#line 1840 "internparser.y"
                          {
			    (yyval.tree) = makeIntegral((yyvsp[-3].tree), (yyvsp[-1].tree));
			  }
#line 6804 "internparser.c"
    break;

  case 313: /* headfunction: "dirtyintegral" "(" thing "," thing ")"  */
#line 1844 "internparser.y"
                          {
			    (yyval.tree) = makeDirtyIntegral((yyvsp[-3].tree), (yyvsp[-1].tree));
			  }
#line 6812 "internparser.c"
    break;

  case 314: /* headfunction: "implementpoly" "(" thing "," thing "," thing "," thing "," thing "," thinglist ")"  */
#line 1848 "internparser.y"
                          {
			    (yyval.tree) = makeImplementPoly(addElement(addElement(addElement(addElement(addElement((yyvsp[-1].list), (yyvsp[-3].tree)), (yyvsp[-5].tree)), (yyvsp[-7].tree)), (yyvsp[-9].tree)), (yyvsp[-11].tree)));
			  }
#line 6820 "internparser.c"
    break;

  case 315: /* headfunction: "implementconst" "(" thinglist ")"  */
#line 1852 "internparser.y"
                          {
			    (yyval.tree) = makeImplementConst((yyvsp[-1].list));
			  }
#line 6828 "internparser.c"
    break;

  case 316: /* headfunction: "interpolate" "(" thing "," thinglist ")"  */
#line 1856 "internparser.y"
                          {
			    (yyval.tree) = makeInterpolate(addElement((yyvsp[-1].list), (yyvsp[-3].tree)));
			  }
#line 6836 "internparser.c"
    break;

  case 317: /* headfunction: "checkinfnorm" "(" thing "," thing "," thing ")"  */
#line 1860 "internparser.y"
                          {
			    (yyval.tree) = makeCheckInfnorm((yyvsp[-5].tree), (yyvsp[-3].tree), (yyvsp[-1].tree));
			  }
#line 6844 "internparser.c"
    break;

  case 318: /* headfunction: "zerodenominators" "(" thing "," thing ")"  */
#line 1864 "internparser.y"
                          {
			    (yyval.tree) = makeZeroDenominators((yyvsp[-3].tree), (yyvsp[-1].tree));
			  }
#line 6852 "internparser.c"
    break;

  case 319: /* headfunction: "isevaluable" "(" thing "," thing ")"  */
#line 1868 "internparser.y"
                          {
			    (yyval.tree) = makeIsEvaluable((yyvsp[-3].tree), (yyvsp[-1].tree));
			  }
#line 6860 "internparser.c"
    break;

  case 320: /* headfunction: "searchgal" "(" thinglist ")"  */
#line 1872 "internparser.y"
                          {
			    (yyval.tree) = makeSearchGal((yyvsp[-1].list));
			  }
#line 6868 "internparser.c"
    break;

  case 321: /* headfunction: "guessdegree" "(" thing "," thing "," thinglist ")"  */
#line 1876 "internparser.y"
                          {
			    (yyval.tree) = makeGuessDegree(addElement(addElement((yyvsp[-1].list), (yyvsp[-3].tree)), (yyvsp[-5].tree)));
			  }
#line 6876 "internparser.c"
    break;

  case 322: /* headfunction: "dirtyfindzeros" "(" thing "," thing ")"  */
#line 1880 "internparser.y"
                          {
			    (yyval.tree) = makeDirtyFindZeros((yyvsp[-3].tree), (yyvsp[-1].tree));
			  }
#line 6884 "internparser.c"
    break;

  case 323: /* headfunction: "head" "(" thing ")"  */
#line 1884 "internparser.y"
                          {
			    (yyval.tree) = makeHead((yyvsp[-1].tree));
			  }
#line 6892 "internparser.c"
    break;

  case 324: /* headfunction: "roundcorrectly" "(" thing ")"  */
#line 1888 "internparser.y"
                          {
			    (yyval.tree) = makeRoundCorrectly((yyvsp[-1].tree));
			  }
#line 6900 "internparser.c"
    break;

  case 325: /* headfunction: "readfile" "(" thing ")"  */
#line 1892 "internparser.y"
                          {
			    (yyval.tree) = makeReadFile((yyvsp[-1].tree));
			  }
#line 6908 "internparser.c"
    break;

  case 326: /* headfunction: "revert" "(" thing ")"  */
#line 1896 "internparser.y"
                          {
			    (yyval.tree) = makeRevert((yyvsp[-1].tree));
			  }
#line 6916 "internparser.c"
    break;

  case 327: /* headfunction: "sort" "(" thing ")"  */
#line 1900 "internparser.y"
                          {
			    (yyval.tree) = makeSort((yyvsp[-1].tree));
			  }
#line 6924 "internparser.c"
    break;

  case 328: /* headfunction: "mantissa" "(" thing ")"  */
#line 1904 "internparser.y"
                          {
			    (yyval.tree) = makeMantissa((yyvsp[-1].tree));
			  }
#line 6932 "internparser.c"
    break;

  case 329: /* headfunction: "exponent" "(" thing ")"  */
#line 1908 "internparser.y"
                          {
			    (yyval.tree) = makeExponent((yyvsp[-1].tree));
			  }
#line 6940 "internparser.c"
    break;

  case 330: /* headfunction: "precision" "(" thing ")"  */
#line 1912 "internparser.y"
                          {
			    (yyval.tree) = makePrecision((yyvsp[-1].tree));
			  }
#line 6948 "internparser.c"
    break;

  case 331: /* headfunction: "tail" "(" thing ")"  */
#line 1916 "internparser.y"
                          {
			    (yyval.tree) = makeTail((yyvsp[-1].tree));
			  }
#line 6956 "internparser.c"
    break;

  case 332: /* headfunction: "sqrt" "(" thing ")"  */
#line 1920 "internparser.y"
                          {
			    (yyval.tree) = makeSqrt((yyvsp[-1].tree));
			  }
#line 6964 "internparser.c"
    break;

  case 333: /* headfunction: "exp" "(" thing ")"  */
#line 1924 "internparser.y"
                          {
			    (yyval.tree) = makeExp((yyvsp[-1].tree));
			  }
#line 6972 "internparser.c"
    break;

  case 334: /* headfunction: "_x_" "(" thing ")"  */
#line 1928 "internparser.y"
                          {
			    (yyval.tree) = makeApply(makeVariable(),addElement(NULL,(yyvsp[-1].tree)));
			  }
#line 6980 "internparser.c"
    break;

  case 335: /* headfunction: "function" "(" thing ")"  */
#line 1932 "internparser.y"
                          {
			    (yyval.tree) = makeProcedureFunction((yyvsp[-1].tree));
			  }
#line 6988 "internparser.c"
    break;

  case 336: /* headfunction: "function" "(" thing "," thing ")"  */
#line 1936 "internparser.y"
                          {
			    (yyval.tree) = makeSubstitute(makeProcedureFunction((yyvsp[-3].tree)),(yyvsp[-1].tree));
			  }
#line 6996 "internparser.c"
    break;

  case 337: /* headfunction: "log" "(" thing ")"  */
#line 1940 "internparser.y"
                          {
			    (yyval.tree) = makeLog((yyvsp[-1].tree));
			  }
#line 7004 "internparser.c"
    break;

  case 338: /* headfunction: "log2" "(" thing ")"  */
#line 1944 "internparser.y"
                          {
			    (yyval.tree) = makeLog2((yyvsp[-1].tree));
			  }
#line 7012 "internparser.c"
    break;

  case 339: /* headfunction: "log10" "(" thing ")"  */
#line 1948 "internparser.y"
                          {
			    (yyval.tree) = makeLog10((yyvsp[-1].tree));
			  }
#line 7020 "internparser.c"
    break;

  case 340: /* headfunction: "sin" "(" thing ")"  */
#line 1952 "internparser.y"
                          {
			    (yyval.tree) = makeSin((yyvsp[-1].tree));
			  }
#line 7028 "internparser.c"
    break;

  case 341: /* headfunction: "cos" "(" thing ")"  */
#line 1956 "internparser.y"
                          {
			    (yyval.tree) = makeCos((yyvsp[-1].tree));
			  }
#line 7036 "internparser.c"
    break;

  case 342: /* headfunction: "tan" "(" thing ")"  */
#line 1960 "internparser.y"
                          {
			    (yyval.tree) = makeTan((yyvsp[-1].tree));
			  }
#line 7044 "internparser.c"
    break;

  case 343: /* headfunction: "asin" "(" thing ")"  */
#line 1964 "internparser.y"
                          {
			    (yyval.tree) = makeAsin((yyvsp[-1].tree));
			  }
#line 7052 "internparser.c"
    break;

  case 344: /* headfunction: "acos" "(" thing ")"  */
#line 1968 "internparser.y"
                          {
			    (yyval.tree) = makeAcos((yyvsp[-1].tree));
			  }
#line 7060 "internparser.c"
    break;

  case 345: /* headfunction: "atan" "(" thing ")"  */
#line 1972 "internparser.y"
                          {
			    (yyval.tree) = makeAtan((yyvsp[-1].tree));
			  }
#line 7068 "internparser.c"
    break;

  case 346: /* headfunction: "sinh" "(" thing ")"  */
#line 1976 "internparser.y"
                          {
			    (yyval.tree) = makeSinh((yyvsp[-1].tree));
			  }
#line 7076 "internparser.c"
    break;

  case 347: /* headfunction: "cosh" "(" thing ")"  */
#line 1980 "internparser.y"
                          {
			    (yyval.tree) = makeCosh((yyvsp[-1].tree));
			  }
#line 7084 "internparser.c"
    break;

  case 348: /* headfunction: "tanh" "(" thing ")"  */
#line 1984 "internparser.y"
                          {
			    (yyval.tree) = makeTanh((yyvsp[-1].tree));
			  }
#line 7092 "internparser.c"
    break;

  case 349: /* headfunction: "asinh" "(" thing ")"  */
#line 1988 "internparser.y"
                          {
			    (yyval.tree) = makeAsinh((yyvsp[-1].tree));
			  }
#line 7100 "internparser.c"
    break;

  case 350: /* headfunction: "acosh" "(" thing ")"  */
#line 1992 "internparser.y"
                          {
			    (yyval.tree) = makeAcosh((yyvsp[-1].tree));
			  }
#line 7108 "internparser.c"
    break;

  case 351: /* headfunction: "atanh" "(" thing ")"  */
#line 1996 "internparser.y"
                          {
			    (yyval.tree) = makeAtanh((yyvsp[-1].tree));
			  }
#line 7116 "internparser.c"
    break;

  case 352: /* headfunction: "abs" "(" thing ")"  */
#line 2000 "internparser.y"
                          {
			    (yyval.tree) = makeAbs((yyvsp[-1].tree));
			  }
#line 7124 "internparser.c"
    break;

  case 353: /* headfunction: "erf" "(" thing ")"  */
#line 2004 "internparser.y"
                          {
			    (yyval.tree) = makeErf((yyvsp[-1].tree));
			  }
#line 7132 "internparser.c"
    break;

  case 354: /* headfunction: "erfc" "(" thing ")"  */
#line 2008 "internparser.y"
                          {
			    (yyval.tree) = makeErfc((yyvsp[-1].tree));
			  }
#line 7140 "internparser.c"
    break;

  case 355: /* headfunction: "log1p" "(" thing ")"  */
#line 2012 "internparser.y"
                          {
			    (yyval.tree) = makeLog1p((yyvsp[-1].tree));
			  }
#line 7148 "internparser.c"
    break;

  case 356: /* headfunction: "expm1" "(" thing ")"  */
#line 2016 "internparser.y"
                          {
			    (yyval.tree) = makeExpm1((yyvsp[-1].tree));
			  }
#line 7156 "internparser.c"
    break;

  case 357: /* headfunction: "D" "(" thing ")"  */
#line 2020 "internparser.y"
                          {
			    (yyval.tree) = makeDouble((yyvsp[-1].tree));
			  }
#line 7164 "internparser.c"
    break;

  case 358: /* headfunction: "SG" "(" thing ")"  */
#line 2024 "internparser.y"
                          {
			    (yyval.tree) = makeSingle((yyvsp[-1].tree));
			  }
#line 7172 "internparser.c"
    break;

  case 359: /* headfunction: "QD" "(" thing ")"  */
#line 2028 "internparser.y"
                          {
			    (yyval.tree) = makeQuad((yyvsp[-1].tree));
			  }
#line 7180 "internparser.c"
    break;

  case 360: /* headfunction: "HP" "(" thing ")"  */
#line 2032 "internparser.y"
                          {
			    (yyval.tree) = makeHalfPrecision((yyvsp[-1].tree));
			  }
#line 7188 "internparser.c"
    break;

  case 361: /* headfunction: "DD" "(" thing ")"  */
#line 2036 "internparser.y"
                          {
			    (yyval.tree) = makeDoubledouble((yyvsp[-1].tree));
			  }
#line 7196 "internparser.c"
    break;

  case 362: /* headfunction: "TD" "(" thing ")"  */
#line 2040 "internparser.y"
                          {
			    (yyval.tree) = makeTripledouble((yyvsp[-1].tree));
			  }
#line 7204 "internparser.c"
    break;

  case 363: /* headfunction: "DE" "(" thing ")"  */
#line 2044 "internparser.y"
                          {
			    (yyval.tree) = makeDoubleextended((yyvsp[-1].tree));
			  }
#line 7212 "internparser.c"
    break;

  case 364: /* headfunction: "ceil" "(" thing ")"  */
#line 2048 "internparser.y"
                          {
			    (yyval.tree) = makeCeil((yyvsp[-1].tree));
			  }
#line 7220 "internparser.c"
    break;

  case 365: /* headfunction: "floor" "(" thing ")"  */
#line 2052 "internparser.y"
                          {
			    (yyval.tree) = makeFloor((yyvsp[-1].tree));
			  }
#line 7228 "internparser.c"
    break;

  case 366: /* headfunction: "nearestint" "(" thing ")"  */
#line 2056 "internparser.y"
                          {
			    (yyval.tree) = makeNearestInt((yyvsp[-1].tree));
			  }
#line 7236 "internparser.c"
    break;

  case 367: /* headfunction: "length" "(" thing ")"  */
#line 2060 "internparser.y"
                          {
			    (yyval.tree) = makeLength((yyvsp[-1].tree));
			  }
#line 7244 "internparser.c"
    break;

  case 368: /* headfunction: "objectname" "(" thing ")"  */
#line 2064 "internparser.y"
                          {
			    (yyval.tree) = makeObjectName((yyvsp[-1].tree));
			  }
#line 7252 "internparser.c"
    break;

  case 369: /* egalquestionmark: "=" "?"  */
#line 2070 "internparser.y"
                          {
			    (yyval.other) = NULL;
			  }
#line 7260 "internparser.c"
    break;

  case 370: /* egalquestionmark: %empty  */
#line 2074 "internparser.y"
                          {
			    (yyval.other) = NULL;
			  }
#line 7268 "internparser.c"
    break;

  case 371: /* statedereference: "prec" egalquestionmark  */
#line 2081 "internparser.y"
                          {
			    (yyval.tree) = makePrecDeref();
			  }
#line 7276 "internparser.c"
    break;

  case 372: /* statedereference: "points" egalquestionmark  */
#line 2085 "internparser.y"
                          {
			    (yyval.tree) = makePointsDeref();
			  }
#line 7284 "internparser.c"
    break;

  case 373: /* statedereference: "diam" egalquestionmark  */
#line 2089 "internparser.y"
                          {
			    (yyval.tree) = makeDiamDeref();
			  }
#line 7292 "internparser.c"
    break;

  case 374: /* statedereference: "display" egalquestionmark  */
#line 2093 "internparser.y"
                          {
			    (yyval.tree) = makeDisplayDeref();
			  }
#line 7300 "internparser.c"
    break;

  case 375: /* statedereference: "verbosity" egalquestionmark  */
#line 2097 "internparser.y"
                          {
			    (yyval.tree) = makeVerbosityDeref();
			  }
#line 7308 "internparser.c"
    break;

  case 376: /* statedereference: "showmessagenumbers" egalquestionmark  */
#line 2101 "internparser.y"
                          {
			    (yyval.tree) = makeShowMessageNumbersDeref();
			  }
#line 7316 "internparser.c"
    break;

  case 377: /* statedereference: "canonical" egalquestionmark  */
#line 2105 "internparser.y"
                          {
			    (yyval.tree) = makeCanonicalDeref();
			  }
#line 7324 "internparser.c"
    break;

  case 378: /* statedereference: "autosimplify" egalquestionmark  */
#line 2109 "internparser.y"
                          {
			    (yyval.tree) = makeAutoSimplifyDeref();
			  }
#line 7332 "internparser.c"
    break;

  case 379: /* statedereference: "taylorrecursions" egalquestionmark  */
#line 2113 "internparser.y"
                          {
			    (yyval.tree) = makeTaylorRecursDeref();
			  }
#line 7340 "internparser.c"
    break;

  case 380: /* statedereference: "timing" egalquestionmark  */
#line 2117 "internparser.y"
                          {
			    (yyval.tree) = makeTimingDeref();
			  }
#line 7348 "internparser.c"
    break;

  case 381: /* statedereference: "fullparentheses" egalquestionmark  */
#line 2121 "internparser.y"
                          {
			    (yyval.tree) = makeFullParenDeref();
			  }
#line 7356 "internparser.c"
    break;

  case 382: /* statedereference: "midpointmode" egalquestionmark  */
#line 2125 "internparser.y"
                          {
			    (yyval.tree) = makeMidpointDeref();
			  }
#line 7364 "internparser.c"
    break;

  case 383: /* statedereference: "dieonerrormode" egalquestionmark  */
#line 2129 "internparser.y"
                          {
			    (yyval.tree) = makeDieOnErrorDeref();
			  }
#line 7372 "internparser.c"
    break;

  case 384: /* statedereference: "rationalmode" egalquestionmark  */
#line 2133 "internparser.y"
                          {
			    (yyval.tree) = makeRationalModeDeref();
			  }
#line 7380 "internparser.c"
    break;

  case 385: /* statedereference: "roundingwarnings" egalquestionmark  */
#line 2137 "internparser.y"
                          {
			    (yyval.tree) = makeSuppressWarningsDeref();
			  }
#line 7388 "internparser.c"
    break;

  case 386: /* statedereference: "hopitalrecursions" egalquestionmark  */
#line 2141 "internparser.y"
                          {
			    (yyval.tree) = makeHopitalRecursDeref();
			  }
#line 7396 "internparser.c"
    break;

  case 387: /* externalproctype: "constant"  */
#line 2148 "internparser.y"
                          {
			    tempIntPtr = (int *) safeMalloc(sizeof(int));
			    *tempIntPtr = CONSTANT_TYPE;
			    (yyval.integerval) = tempIntPtr;
			  }
#line 7406 "internparser.c"
    break;

  case 388: /* externalproctype: "function"  */
#line 2154 "internparser.y"
                          {
			    tempIntPtr = (int *) safeMalloc(sizeof(int));
			    *tempIntPtr = FUNCTION_TYPE;
			    (yyval.integerval) = tempIntPtr;
			  }
#line 7416 "internparser.c"
    break;

  case 389: /* externalproctype: "object"  */
#line 2160 "internparser.y"
                          {
			    tempIntPtr = (int *) safeMalloc(sizeof(int));
			    *tempIntPtr = OBJECT_TYPE;
			    (yyval.integerval) = tempIntPtr;
			  }
#line 7426 "internparser.c"
    break;

  case 390: /* externalproctype: "range"  */
#line 2166 "internparser.y"
                          {
			    tempIntPtr = (int *) safeMalloc(sizeof(int));
			    *tempIntPtr = RANGE_TYPE;
			    (yyval.integerval) = tempIntPtr;
			  }
#line 7436 "internparser.c"
    break;

  case 391: /* externalproctype: "integer"  */
#line 2172 "internparser.y"
                          {
			    tempIntPtr = (int *) safeMalloc(sizeof(int));
			    *tempIntPtr = INTEGER_TYPE;
			    (yyval.integerval) = tempIntPtr;
			  }
#line 7446 "internparser.c"
    break;

  case 392: /* externalproctype: "string"  */
#line 2178 "internparser.y"
                          {
			    tempIntPtr = (int *) safeMalloc(sizeof(int));
			    *tempIntPtr = STRING_TYPE;
			    (yyval.integerval) = tempIntPtr;
			  }
#line 7456 "internparser.c"
    break;

  case 393: /* externalproctype: "boolean"  */
#line 2184 "internparser.y"
                          {
			    tempIntPtr = (int *) safeMalloc(sizeof(int));
			    *tempIntPtr = BOOLEAN_TYPE;
			    (yyval.integerval) = tempIntPtr;
			  }
#line 7466 "internparser.c"
    break;

  case 394: /* externalproctype: "list" "of" "constant"  */
#line 2190 "internparser.y"
                          {
			    tempIntPtr = (int *) safeMalloc(sizeof(int));
			    *tempIntPtr = CONSTANT_LIST_TYPE;
			    (yyval.integerval) = tempIntPtr;
			  }
#line 7476 "internparser.c"
    break;

  case 395: /* externalproctype: "list" "of" "function"  */
#line 2196 "internparser.y"
                          {
			    tempIntPtr = (int *) safeMalloc(sizeof(int));
			    *tempIntPtr = FUNCTION_LIST_TYPE;
			    (yyval.integerval) = tempIntPtr;
			  }
#line 7486 "internparser.c"
    break;

  case 396: /* externalproctype: "list" "of" "object"  */
#line 2202 "internparser.y"
                          {
			    tempIntPtr = (int *) safeMalloc(sizeof(int));
			    *tempIntPtr = OBJECT_LIST_TYPE;
			    (yyval.integerval) = tempIntPtr;
			  }
#line 7496 "internparser.c"
    break;

  case 397: /* externalproctype: "list" "of" "range"  */
#line 2208 "internparser.y"
                          {
			    tempIntPtr = (int *) safeMalloc(sizeof(int));
			    *tempIntPtr = RANGE_LIST_TYPE;
			    (yyval.integerval) = tempIntPtr;
			  }
#line 7506 "internparser.c"
    break;

  case 398: /* externalproctype: "list" "of" "integer"  */
#line 2214 "internparser.y"
                          {
			    tempIntPtr = (int *) safeMalloc(sizeof(int));
			    *tempIntPtr = INTEGER_LIST_TYPE;
			    (yyval.integerval) = tempIntPtr;
			  }
#line 7516 "internparser.c"
    break;

  case 399: /* externalproctype: "list" "of" "string"  */
#line 2220 "internparser.y"
                          {
			    tempIntPtr = (int *) safeMalloc(sizeof(int));
			    *tempIntPtr = STRING_LIST_TYPE;
			    (yyval.integerval) = tempIntPtr;
			  }
#line 7526 "internparser.c"
    break;

  case 400: /* externalproctype: "list" "of" "boolean"  */
#line 2226 "internparser.y"
                          {
			    tempIntPtr = (int *) safeMalloc(sizeof(int));
			    *tempIntPtr = BOOLEAN_LIST_TYPE;
			    (yyval.integerval) = tempIntPtr;
			  }
#line 7536 "internparser.c"
    break;

  case 401: /* extendedexternalproctype: "void"  */
#line 2234 "internparser.y"
                          {
			    tempIntPtr = (int *) safeMalloc(sizeof(int));
			    *tempIntPtr = VOID_TYPE;
			    (yyval.integerval) = tempIntPtr;
			  }
#line 7546 "internparser.c"
    break;

  case 402: /* extendedexternalproctype: externalproctype  */
#line 2240 "internparser.y"
                          {
			    (yyval.integerval) = (yyvsp[0].integerval);
		          }
#line 7554 "internparser.c"
    break;

  case 403: /* externalproctypesimplelist: externalproctype  */
#line 2247 "internparser.y"
                          {
			    (yyval.list) = addElement(NULL, (yyvsp[0].integerval));
			  }
#line 7562 "internparser.c"
    break;

  case 404: /* externalproctypesimplelist: externalproctype "," externalproctypesimplelist  */
#line 2251 "internparser.y"
                          {
			    (yyval.list) = addElement((yyvsp[0].list), (yyvsp[-2].integerval));
			  }
#line 7570 "internparser.c"
    break;

  case 405: /* externalproctypelist: extendedexternalproctype  */
#line 2257 "internparser.y"
                          {
			    (yyval.list) = addElement(NULL, (yyvsp[0].integerval));
			  }
#line 7578 "internparser.c"
    break;

  case 406: /* externalproctypelist: "(" externalproctypesimplelist ")"  */
#line 2261 "internparser.y"
                          {
			    (yyval.list) = (yyvsp[-1].list);
			  }
#line 7586 "internparser.c"
    break;


#line 7590 "internparser.c"

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

