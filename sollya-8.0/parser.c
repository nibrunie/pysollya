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




/* First part of user prologue.  */
#line 69 "parser.y"

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

#include "parser.h"
#include "library.h"
#include "sollya-help.h"
#include "version.h"

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

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

extern int yylex(YYSTYPE *lvalp, void *scanner);
extern FILE *yyget_in(void *scanner);
extern char *getCurrentLexSymbol();

void yyerror(void *scanner, const char *message) {
  char *str;
  if (!feof(yyget_in(scanner))) {
    str = getCurrentLexSymbol();
    printMessage(1,SOLLYA_MSG_SYNTAX_ERROR_ENCOUNTERED_WHILE_PARSING,"Warning: %s.\nThe last symbol read has been \"%s\".\nWill skip input until next semicolon after the unexpected token. May leak memory.\n",message,str);
    safeFree(str);
    promptToBePrinted = 1;
    lastWasSyntaxError = 1;
    considerDyingOnError();
  } 
}

int parserCheckEof() {
  FILE *myFd;

  myFd = yyget_in(scanner);
  if (myFd == NULL) return 0;
  
  return feof(myFd);
}

/* #define WARN_IF_NO_HELP_TEXT 1 */
 

#line 139 "parser.c"

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
#ifndef YY_YY_PARSER_H_INCLUDED
# define YY_YY_PARSER_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
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
    RESTARTTOKEN = 387,            /* "restart"  */
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
    NOPTOKEN = 496,                /* "nop"  */
    HELPTOKEN = 497,               /* "help"  */
    VERSIONTOKEN = 498             /* "version"  */
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
#define RESTARTTOKEN 387
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
#define HELPTOKEN 497
#define VERSIONTOKEN 498

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 146 "parser.y"

  doubleNode *dblnode;
  struct entryStruct *association;
  char *value;
  node *tree;
  chain *list;
  int *integerval;
  int count;
  void *other;

#line 689 "parser.c"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif




int yyparse (void* scanner);


#endif /* !YY_YY_PARSER_H_INCLUDED  */
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
  YYSYMBOL_RESTARTTOKEN = 132,             /* "restart"  */
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
  YYSYMBOL_HELPTOKEN = 242,                /* "help"  */
  YYSYMBOL_VERSIONTOKEN = 243,             /* "version"  */
  YYSYMBOL_YYACCEPT = 244,                 /* $accept  */
  YYSYMBOL_startsymbol = 245,              /* startsymbol  */
  YYSYMBOL_helpmeta = 246,                 /* helpmeta  */
  YYSYMBOL_beginsymbol = 247,              /* beginsymbol  */
  YYSYMBOL_endsymbol = 248,                /* endsymbol  */
  YYSYMBOL_command = 249,                  /* command  */
  YYSYMBOL_ifcommand = 250,                /* ifcommand  */
  YYSYMBOL_forcommand = 251,               /* forcommand  */
  YYSYMBOL_commandlist = 252,              /* commandlist  */
  YYSYMBOL_variabledeclarationlist = 253,  /* variabledeclarationlist  */
  YYSYMBOL_variabledeclaration = 254,      /* variabledeclaration  */
  YYSYMBOL_identifierlist = 255,           /* identifierlist  */
  YYSYMBOL_procbody = 256,                 /* procbody  */
  YYSYMBOL_simplecommand = 257,            /* simplecommand  */
  YYSYMBOL_assignment = 258,               /* assignment  */
  YYSYMBOL_simpleassignment = 259,         /* simpleassignment  */
  YYSYMBOL_structuring = 260,              /* structuring  */
  YYSYMBOL_stateassignment = 261,          /* stateassignment  */
  YYSYMBOL_stillstateassignment = 262,     /* stillstateassignment  */
  YYSYMBOL_thinglist = 263,                /* thinglist  */
  YYSYMBOL_structelementlist = 264,        /* structelementlist  */
  YYSYMBOL_structelementseparator = 265,   /* structelementseparator  */
  YYSYMBOL_structelement = 266,            /* structelement  */
  YYSYMBOL_thing = 267,                    /* thing  */
  YYSYMBOL_supermegaterm = 268,            /* supermegaterm  */
  YYSYMBOL_indexing = 269,                 /* indexing  */
  YYSYMBOL_megaterm = 270,                 /* megaterm  */
  YYSYMBOL_hyperterm = 271,                /* hyperterm  */
  YYSYMBOL_unaryplusminus = 272,           /* unaryplusminus  */
  YYSYMBOL_term = 273,                     /* term  */
  YYSYMBOL_subterm = 274,                  /* subterm  */
  YYSYMBOL_basicthing = 275,               /* basicthing  */
  YYSYMBOL_matchlist = 276,                /* matchlist  */
  YYSYMBOL_matchelement = 277,             /* matchelement  */
  YYSYMBOL_constant = 278,                 /* constant  */
  YYSYMBOL_list = 279,                     /* list  */
  YYSYMBOL_simplelist = 280,               /* simplelist  */
  YYSYMBOL_range = 281,                    /* range  */
  YYSYMBOL_debound = 282,                  /* debound  */
  YYSYMBOL_headfunction = 283,             /* headfunction  */
  YYSYMBOL_egalquestionmark = 284,         /* egalquestionmark  */
  YYSYMBOL_statedereference = 285,         /* statedereference  */
  YYSYMBOL_externalproctype = 286,         /* externalproctype  */
  YYSYMBOL_extendedexternalproctype = 287, /* extendedexternalproctype  */
  YYSYMBOL_externalproctypesimplelist = 288, /* externalproctypesimplelist  */
  YYSYMBOL_externalproctypelist = 289,     /* externalproctypelist  */
  YYSYMBOL_help = 290                      /* help  */
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
#define YYFINAL  423
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   9220

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  244
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  47
/* YYNRULES -- Number of rules.  */
#define YYNRULES  651
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  1406

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   498


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
     235,   236,   237,   238,   239,   240,   241,   242,   243
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   475,   475,   481,   489,   497,   503,   515,   523,   530,
     534,   540,   544,   550,   554,   558,   562,   566,   570,   574,
     578,   584,   588,   596,   601,   606,   614,   618,   624,   628,
     634,   641,   645,   651,   655,   659,   663,   667,   671,   675,
     679,   683,   687,   691,   695,   699,   703,   707,   711,   715,
     719,   723,   727,   731,   735,   739,   743,   750,   754,   758,
     762,   766,   770,   774,   778,   782,   786,   790,   794,   798,
     802,   806,   810,   814,   818,   822,   826,   830,   834,   838,
     842,   846,   850,   854,   858,   862,   868,   873,   878,   882,
     887,   892,   896,   900,   907,   911,   915,   919,   925,   930,
     935,   940,   945,   950,   955,   959,   965,   972,   976,   980,
     984,   988,   992,   996,  1000,  1004,  1008,  1012,  1016,  1020,
    1024,  1028,  1032,  1038,  1042,  1046,  1050,  1054,  1058,  1062,
    1066,  1070,  1074,  1078,  1082,  1086,  1090,  1094,  1098,  1104,
    1108,  1114,  1118,  1124,  1128,  1134,  1144,  1148,  1154,  1158,
    1162,  1166,  1172,  1181,  1185,  1189,  1193,  1197,  1201,  1205,
    1209,  1215,  1219,  1223,  1227,  1231,  1235,  1241,  1245,  1249,
    1253,  1260,  1264,  1271,  1275,  1279,  1283,  1290,  1297,  1301,
    1307,  1311,  1315,  1322,  1326,  1330,  1337,  1341,  1345,  1349,
    1353,  1357,  1361,  1365,  1369,  1373,  1377,  1381,  1385,  1389,
    1393,  1397,  1401,  1405,  1409,  1413,  1417,  1421,  1425,  1429,
    1433,  1437,  1441,  1445,  1449,  1453,  1457,  1461,  1465,  1469,
    1480,  1484,  1489,  1494,  1499,  1504,  1508,  1512,  1516,  1520,
    1524,  1528,  1532,  1537,  1542,  1547,  1552,  1556,  1560,  1564,
    1570,  1574,  1580,  1584,  1588,  1592,  1596,  1600,  1604,  1608,
    1612,  1618,  1623,  1628,  1633,  1638,  1643,  1648,  1656,  1660,
    1664,  1668,  1674,  1678,  1682,  1689,  1693,  1697,  1703,  1707,
    1711,  1715,  1719,  1723,  1729,  1733,  1737,  1741,  1745,  1749,
    1753,  1757,  1761,  1766,  1770,  1774,  1778,  1782,  1786,  1790,
    1794,  1798,  1802,  1806,  1810,  1814,  1818,  1822,  1826,  1830,
    1834,  1838,  1842,  1846,  1850,  1854,  1858,  1862,  1866,  1870,
    1874,  1878,  1882,  1886,  1890,  1894,  1898,  1902,  1906,  1910,
    1914,  1918,  1922,  1926,  1930,  1934,  1938,  1942,  1946,  1950,
    1954,  1958,  1962,  1966,  1970,  1974,  1978,  1982,  1986,  1990,
    1994,  1998,  2002,  2006,  2010,  2014,  2018,  2022,  2026,  2030,
    2034,  2038,  2042,  2046,  2050,  2054,  2058,  2062,  2066,  2070,
    2074,  2078,  2082,  2086,  2090,  2094,  2098,  2102,  2106,  2110,
    2114,  2118,  2122,  2126,  2132,  2137,  2142,  2146,  2150,  2154,
    2158,  2162,  2166,  2170,  2174,  2178,  2182,  2186,  2190,  2194,
    2198,  2202,  2208,  2214,  2220,  2226,  2232,  2238,  2244,  2250,
    2256,  2262,  2268,  2274,  2280,  2286,  2294,  2300,  2307,  2311,
    2317,  2321,  2328,  2333,  2338,  2343,  2348,  2353,  2357,  2362,
    2367,  2371,  2375,  2379,  2383,  2387,  2391,  2395,  2399,  2403,
    2407,  2411,  2415,  2419,  2423,  2427,  2431,  2435,  2439,  2443,
    2447,  2451,  2455,  2459,  2463,  2467,  2471,  2475,  2479,  2483,
    2487,  2491,  2495,  2499,  2503,  2507,  2511,  2515,  2519,  2523,
    2527,  2531,  2535,  2539,  2543,  2547,  2551,  2555,  2559,  2563,
    2567,  2571,  2575,  2579,  2583,  2587,  2591,  2595,  2599,  2603,
    2607,  2611,  2615,  2619,  2623,  2627,  2631,  2635,  2639,  2643,
    2647,  2651,  2655,  2659,  2663,  2667,  2671,  2675,  2679,  2683,
    2687,  2691,  2695,  2699,  2703,  2707,  2711,  2715,  2719,  2723,
    2727,  2731,  2735,  2739,  2743,  2747,  2751,  2755,  2759,  2763,
    2767,  2771,  2775,  2779,  2783,  2787,  2791,  2795,  2799,  2803,
    2807,  2811,  2815,  2819,  2823,  2827,  2831,  2835,  2839,  2843,
    2847,  2851,  2855,  2859,  2863,  2867,  2871,  2875,  2879,  2883,
    2887,  2891,  2895,  2899,  2903,  2907,  2911,  2915,  2919,  2923,
    2927,  2931,  2935,  2939,  2943,  2947,  2951,  2955,  2959,  2963,
    2967,  2971,  2975,  2979,  2983,  2987,  2991,  2995,  2999,  3003,
    3007,  3011,  3015,  3019,  3023,  3027,  3031,  3035,  3039,  3043,
    3047,  3051,  3055,  3059,  3063,  3067,  3071,  3075,  3079,  3083,
    3087,  3091,  3095,  3099,  3103,  3107,  3111,  3115,  3119,  3123,
    3127,  3131,  3135,  3139,  3143,  3147,  3151,  3155,  3159,  3163,
    3167,  3171,  3176,  3180,  3184,  3188,  3192,  3196,  3200,  3204,
    3208,  3212,  3216,  3220,  3224,  3228,  3232,  3236,  3240,  3244,
    3248,  3252,  3256,  3260,  3264,  3268,  3272,  3276,  3280,  3284,
    3288,  3292
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
  "\"procedure\"", "\"return\"", "\"nop\"", "\"help\"", "\"version\"",
  "$accept", "startsymbol", "helpmeta", "beginsymbol", "endsymbol",
  "command", "ifcommand", "forcommand", "commandlist",
  "variabledeclarationlist", "variabledeclaration", "identifierlist",
  "procbody", "simplecommand", "assignment", "simpleassignment",
  "structuring", "stateassignment", "stillstateassignment", "thinglist",
  "structelementlist", "structelementseparator", "structelement", "thing",
  "supermegaterm", "indexing", "megaterm", "hyperterm", "unaryplusminus",
  "term", "subterm", "basicthing", "matchlist", "matchelement", "constant",
  "list", "simplelist", "range", "debound", "headfunction",
  "egalquestionmark", "statedereference", "externalproctype",
  "extendedexternalproctype", "externalproctypesimplelist",
  "externalproctypelist", "help", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-1238)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-139)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    1571,    20, -1238, -1238, -1238, -1238, -1238, -1238, -1238,   105,
   -1238,  7274,  4682,  7952,  7274, -1238,  8982,   164,   164,    78,
     106,   131,   135,   153,   185,   199,   202,   207,   230,   277,
     288,   292,   297,   299,   301,   303,   307,   342,   345,   373,
     383,   443,   454,   486,   538,   543,   546,   559,   566,   596,
     611,   646,   649,   652,   655,   661,   664,   685,   701,   707,
     136,   141,   282,   437,   478,   485,    32,   490,   495,   590,
     728,   595,   673,   679,   688,   695,   726, -1238, -1238, -1238,
   -1238, -1238, -1238, -1238, -1238, -1238, -1238, -1238, -1238, -1238,
   -1238, -1238, -1238, -1238, -1238,  7274, -1238, -1238, -1238, -1238,
   -1238, -1238, -1238, -1238, -1238,   747,   753,   759,   760,   762,
     771,   774,   776,   786,   787,   788,   793,   802,   804,   815,
     817,   819,   826,   833,   848,   855,   856,   857,   859,   861,
     869,   870,   876,   879,   905,   915,   920,   929,   941,   942,
     947,   951,   952,   955,   959,   978,   983,   984,   989,   990,
     993,   994,   996,   998,  1029,  1031,  1058,  1062,  1065,  1070,
    1080,  1084,  1102,  1108,  1110,  1112,  1122,  1123,  1124,  1144,
    1151,  1152,  1153,  1166,  1179,  1181,  1187,  1189,  7274,    35,
   -1238,   379,  7274,  1194,  1196,  1202,  1229,  1232, -1238,  1234,
    1236,   438,  1239, -1238,   425,   458,  1812,  3009,   475, -1238,
   -1238,   440,   347, -1238,   493, -1238,   147, -1238,   377,    -5,
     971,  8982,   419, -1238,    28, -1238, -1238, -1238, -1238, -1238,
   -1238, -1238,  5124,  4888,  7274,  1244,   803,   803,   803,   803,
     803,   803,    94,   803,   803,   803,   803,   803,   803,   803,
     803,   803,   379,    38, -1238,    29,  5330,   500,   183,    -5,
    1258, -1238, -1238, -1238,  7274,  7274,  7274,  7274,  7274,  7274,
    7274,  7274,  7274,  7274,  7274,  7274,  7274,  7274,  7274,  7274,
    7274,  7274,  7274,  7274,  7274,  7274,  7274,  7274,  7274,  7274,
    7274,  7274,  7274,  7274,  7274,  7274,  7274,  7274,  7274,  7274,
    7274,  7274,  7274,  7274,  7274,  5536, -1238,  5536, -1238,  5536,
   -1238,  5536, -1238,  5536, -1238,  5536, -1238,  7274,  5536, -1238,
    5536, -1238,  5536, -1238,  5536, -1238,  4443,  5536, -1238,  5536,
   -1238,  5536, -1238,  5536, -1238,  5536, -1238,  5536, -1238,   524,
     496,  7274,  7274,  7274,  7274,  7274,   600,   602,  7274,  7274,
    7274,  7274,  7274,  7274,  7274,  7274,  7274,  7274,  7274,  7274,
    7274,  7274,  7274,  7274,  7274,  7274,  7274,  7274,  7274,  7274,
    7274,  7274,  7274,  7274,  7274,  7274,  7274,  7274,  7274,  7274,
    7274,  7274,  7274,  7274,  7274,  7274,  7274,  7274,  7274,  7274,
    7274,    21,  7274,  7274,  7274,  7274,  7274,  7274,  7274,  7274,
    7274,  7274,  7274,  7274,  7274,  7274,  7274,  7274,  7274,  7274,
    7274,  7274,  7274,  7274, -1238,    -1,   442, -1238,   641,   397,
      33,   -23,  7274,   780,  7274,   868,  1027,  7274,   182, -1238,
    1236,  5772, -1238, -1238, -1238, -1238, -1238, -1238, -1238, -1238,
   -1238, -1238, -1238, -1238,   634, -1238, -1238, -1238, -1238, -1238,
   -1238, -1238, -1238,   954, -1238, -1238, -1238,  1024, -1238, -1238,
   -1238,   691, -1238, -1238, -1238, -1238, -1238, -1238, -1238, -1238,
   -1238, -1238, -1238, -1238, -1238, -1238, -1238, -1238, -1238, -1238,
   -1238, -1238, -1238, -1238, -1238, -1238, -1238, -1238, -1238, -1238,
   -1238, -1238, -1238, -1238, -1238, -1238, -1238, -1238, -1238, -1238,
   -1238, -1238, -1238, -1238, -1238, -1238, -1238, -1238, -1238, -1238,
   -1238, -1238, -1238, -1238, -1238, -1238, -1238, -1238, -1238, -1238,
   -1238, -1238, -1238, -1238, -1238, -1238, -1238, -1238, -1238, -1238,
   -1238, -1238, -1238, -1238, -1238, -1238, -1238, -1238, -1238, -1238,
   -1238, -1238, -1238, -1238, -1238, -1238, -1238, -1238, -1238, -1238,
   -1238, -1238, -1238, -1238, -1238, -1238, -1238, -1238, -1238, -1238,
   -1238, -1238, -1238, -1238, -1238, -1238, -1238, -1238, -1238, -1238,
   -1238, -1238, -1238, -1238, -1238, -1238, -1238, -1238, -1238, -1238,
   -1238, -1238, -1238, -1238, -1238, -1238, -1238, -1238, -1238, -1238,
   -1238, -1238, -1238, -1238, -1238, -1238, -1238, -1238, -1238, -1238,
   -1238, -1238, -1238, -1238, -1238, -1238, -1238, -1238, -1238, -1238,
   -1238, -1238, -1238, -1238, -1238, -1238, -1238, -1238, -1238, -1238,
   -1238, -1238, -1238, -1238, -1238, -1238, -1238, -1238, -1238, -1238,
   -1238, -1238, -1238, -1238, -1238, -1238, -1238, -1238, -1238, -1238,
   -1238, -1238, -1238, -1238, -1238, -1238, -1238, -1238, -1238, -1238,
   -1238, -1238, -1238, -1238, -1238, -1238, -1238, -1238, -1238, -1238,
   -1238, -1238, -1238, -1238, -1238, -1238, -1238, -1238, -1238, -1238,
   -1238, -1238, -1238, -1238,   736,  1074, -1238,  1138,  -158,  4204,
    1171, -1238, -1238,  7274,  7274, -1238,  7274,  7952,  7952,  7274,
    7274,  7952,  7510,  7746,  7952,  7952,  7952,  7952,  7952,  7952,
    7952, -1238,  8158,  8364,  7274,  1233,  8776,  8570, -1238,   810,
    1245,  1246,   524,   524,  1132,  1256,  1243,  1257,   524,   371,
   -1238, -1238,  7274,  7274, -1238, -1238, -1238,    40,    43,    46,
      48,    52,    55,    57,    68,    76,    80,    86,    88,    90,
      92,    96,    99,   101,   110,   121,   124,   129,   133,   138,
     140,   143,   145,   149,   181,   278,   357,   392,   394,   396,
     398,   400,   411,   428,   430,   432,   434,   436, -1238,   906,
    1087,  1093,  1099,  1101,  1103,   439,  1105,  1111,  1133,  1141,
    1183,  1146,  1148,  1150,  1163,  1178,  1180,  7274,   441,   444,
     197,   286,    27, -1238, -1238,   529,   446,   448,   452,   730,
     737,   739,   741,   464,   469,   480,   745,   754,   756,   763,
     768,   770,   772,   778,   782,   785,   482,   484,   487,   489,
     492,  1191,  1260,   494,   497,  1262,   499,   794,   501,   503,
     505,  1264,  1265,   512,   517,   796,  1266,   807,  1267,  1268,
     809,   811,   813,   818,   822,   825,   835,   837,   840,   844,
     847,   866,   871,   875,  1272,   880,   882,   885,   890,  1276,
     894,   897,  4443,  7274,  7274,  1277, -1238, -1238, -1238,   379,
    4443,   522,  1282,   533,  1280,  1281,    36,    31,    22,  1283,
   -1238, -1238,   536, -1238, -1238, -1238, -1238, -1238,  1292, -1238,
    4443, -1238, -1238,  -158,  1077,   524,   524, -1238,    -5,    -5,
     524,   524,   971,  7952,   971,  7952,   971,   971,   971,   419,
     419,   419,   419,   419,  8982,  8982, -1238,  8982,  8982, -1238,
     194,   158,  8982, -1238,  8982,  8982, -1238, -1238,  7274,  7274,
    6008,  1301, -1238,  6214,  1284,  1303,   620,   635, -1238, -1238,
   -1238, -1238, -1238, -1238, -1238, -1238, -1238, -1238, -1238, -1238,
   -1238, -1238, -1238, -1238, -1238, -1238, -1238, -1238, -1238, -1238,
   -1238, -1238, -1238, -1238, -1238, -1238, -1238, -1238, -1238, -1238,
   -1238, -1238, -1238, -1238, -1238, -1238, -1238, -1238, -1238, -1238,
   -1238,   520, -1238,  7274, -1238, -1238,  7274,  7274, -1238,  7274,
    7274, -1238, -1238, -1238,  7274,  7274,  7274,  7274, -1238, -1238,
   -1238,  7274,  7274,  7274,  7274,  7274,  7274,  7274,  7274,  7274,
    7274, -1238, -1238, -1238, -1238, -1238, -1238, -1238, -1238, -1238,
    1289,  1293,  7274, -1238, -1238, -1238, -1238, -1238, -1238, -1238,
    7274,  1297,  7274,    23,    24,  1309,  7274,  7274,  7274,  7274,
    7274,  7274,  7274,  7274,  7274,  7274,  7274,  7274,  7274, -1238,
    7274,  7274,  7274,  7274, -1238,  7274,  7274,  1115,   -20,    -4,
    7274, -1238, -1238, -1238, -1238, -1238,  7274,  7274, -1238,  7274,
    1298,  1074,  2053,    22, -1238, -1238, -1238, -1238,   971,   971,
   -1238, -1238, -1238, -1238, -1238,  6450, -1238, -1238, -1238,   540,
     557, -1238,  1315,  1310,   524,  1316, -1238, -1238, -1238,    -2,
   -1238,   899,   904,   564,   909,   912,   916,   921,   953,   585,
     587,   589,   592,   594,   597,   599,   958,   960,   601,  6656,
    6862,  1317,   975,  7068,   603,  1320,  1322,  1323,  1325,  1331,
    1338,  1010,   605,   607,   609,   617,   639,   653,   659,   669,
     675,  1017,  1019,  1341,  1023,   677,   681,  1025,   683,  4443,
    4443,  7274,   524,  1028,   690,   692,  1344, -1238,  7274, -1238,
    -116,  3248,  2292, -1238,  1346, -1238, -1238, -1238,  7274, -1238,
    7274,  2531,  7274,  7274, -1238,  7274,  7274,  7274,  7274,  7274,
   -1238, -1238, -1238, -1238, -1238, -1238, -1238,  7274,  7274, -1238,
    7274,   524,  7274,   524, -1238,  7274,  7274,   524, -1238, -1238,
   -1238, -1238, -1238,  7274, -1238,  7274, -1238, -1238, -1238, -1238,
   -1238, -1238, -1238, -1238, -1238,  7274,  7274, -1238,  7274, -1238,
   -1238,  7274, -1238, -1238, -1238,   -25,    -3, -1238, -1238,    22,
     526,  7274, -1238,  7274, -1238,  -107,  7274, -1238,    67,  3487,
   -1238,   524,   694,  7274, -1238,   224,  3726,  1347,  1036,  1047,
     697,  1348,   699,   705,  1350,   711,   524,   524,  1050,   524,
     713,  1054,  1061,  1064,   715,  1351,  7274,  4443,  1114, -1238,
   -1238, -1238, -1238, -1238, -1238, -1238, -1238,  1130, -1238, -1238,
    1326,  2770,  -158,  1012,  1039,  7274, -1238,  1089,  7274, -1238,
    7274, -1238,   381, -1238,  1184,  7274, -1238,  7274, -1238,   507,
   -1238,  7274,  7274, -1238, -1238, -1238, -1238, -1238, -1238,  7274,
   -1238,  7274,  7274,  7274, -1238, -1238,   -16, -1238,  1352,  1354,
    1147,  1343,  7274, -1238,   523,  3965, -1238,  -158,  -158,  1186,
    -158,  1188,  1190,  7274, -1238,  -158,  1192,  1195,  7274, -1238,
    1359,  1361,  1066,  1069,  1072,  1076,  4443,  1114, -1238, -1238,
   -1238, -1238, -1238, -1238, -1238, -1238,  1075,  1200,  7274, -1238,
    7274, -1238,   528, -1238, -1238,  -158, -1238,  -158,  -158,  1215,
   -1238,  -158,  -158,  1221, -1238, -1238,  7274,  7274,  7274,  7274,
   -1238, -1238,  1374,  -158,  1226,  1231,  7274, -1238, -1238, -1238,
   -1238,  -158, -1238, -1238,  -158,  1375,   722,  1376,  1078, -1238,
   -1238,  -158,  -158,  1241, -1238, -1238, -1238, -1238, -1238,  7274,
   -1238, -1238,  -158,  1377, -1238, -1238
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int16 yydefact[] =
{
       0,     0,   251,   252,   253,   254,   255,   256,   257,   221,
     219,     0,     0,     0,     0,     4,     0,   167,   168,     0,
       0,   216,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   211,   212,   214,   213,   217,   218,   215,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     375,   375,   375,   375,   375,   375,   375,   375,   375,   375,
       0,   375,   375,   375,   375,   375,   375,   186,   187,   188,
     189,   190,   191,   192,   193,   194,   195,   196,   197,   198,
     199,   200,   201,   203,   204,     0,   206,   205,   207,   208,
     209,   210,    57,    58,    62,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       9,    10,     0,     0,     0,     0,     0,     0,   202,     0,
       0,     0,    59,     8,     0,     0,     0,     0,     0,    13,
      91,    96,     0,    94,     0,    92,   139,   146,   232,   148,
     153,     0,   161,   171,   180,   220,   225,   226,   227,   228,
     231,     7,     0,     0,     0,   221,   375,   375,   375,   375,
     375,   375,   375,   375,   375,   375,   375,   375,   375,   375,
     375,   375,     0,     0,   232,   180,     0,     0,     0,   151,
       0,   173,   169,   170,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   376,     0,   377,     0,
     378,     0,   379,     0,   380,     0,   381,     0,     0,   382,
       0,   383,     0,   384,     0,   385,     0,     0,   386,     0,
     387,     0,   388,     0,   390,     0,   389,     0,   391,     0,
     146,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    18,     0,     0,    20,     0,     0,
     141,     0,     0,     0,     0,     0,     0,     0,     0,   238,
       0,     0,     6,     1,   412,   413,   414,   415,   416,   417,
     418,   419,   420,   421,   422,   423,   426,   427,   428,   429,
     430,     3,   431,   432,   434,   435,   438,   439,   440,   437,
     441,   442,   443,   444,   445,   446,   447,   452,   448,   449,
     450,   451,   453,   454,   455,   456,   457,   458,   459,   460,
     461,   462,   463,   464,   465,   466,   467,   468,   469,   470,
     471,   472,   473,   474,   475,   476,   477,   478,   479,   480,
     482,   481,   483,   484,   485,   486,   487,   488,   489,   492,
     493,   494,   629,   628,   630,   490,   495,   496,   497,   498,
     499,   500,   501,   502,   503,   504,   505,   506,   507,   508,
     510,   509,   511,   512,   513,   514,   515,   516,   517,   518,
     519,   520,   521,   522,   523,   524,   525,   526,   527,   528,
     529,   530,   531,   532,   533,   534,   535,   536,   537,   538,
     539,   540,   541,   542,   543,   547,   548,   549,   544,   545,
     546,   552,   553,   554,   555,   556,   557,   558,   559,   560,
     561,   562,   563,   564,   565,   566,   567,   568,   569,   570,
     571,   572,   573,   574,   625,   626,   627,   550,   551,   578,
     575,   576,   577,   579,   580,   581,   582,   583,   584,   585,
     586,   587,   588,   589,   590,   591,   592,   593,   594,   595,
     596,   597,   598,   599,   600,   601,   602,   603,   604,   606,
     605,   607,   608,   609,   610,   611,   612,   613,   614,   615,
     616,   617,   618,   619,   620,   621,    11,    10,    12,   624,
     491,   632,   631,   634,   635,   636,   637,   638,   639,   640,
     641,   642,   643,   644,   645,   646,   648,   649,   650,   647,
     651,   633,   622,   623,     0,     0,    17,     0,     0,     0,
       0,     2,    97,     0,     0,    95,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   172,     0,     0,     0,     0,     0,     0,   224,     0,
       0,     0,    98,    99,     0,   229,     0,     0,   262,     0,
     259,   267,     0,     0,   270,   269,   268,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   374,   107,
     108,   109,   110,   111,   112,     0,   113,   114,   115,   116,
       0,   117,   118,   119,   121,   120,   122,     0,     0,     0,
       0,     0,     0,   277,   278,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   230,   143,   144,     0,
       0,     0,     0,     0,     0,     0,     0,    31,     0,     0,
      93,    61,     0,   424,   433,   436,   425,     5,    31,    30,
      26,    14,    16,     0,    28,   104,   105,   140,   149,   150,
     102,   103,   154,     0,   156,     0,   157,   160,   155,   164,
     165,   166,   162,   163,     0,     0,   174,     0,     0,   175,
       0,   233,     0,   184,     0,     0,   181,   223,     0,     0,
       0,   233,   258,     0,     0,     0,     0,     0,   337,   338,
     339,   342,   343,   344,   345,   346,   347,   348,   349,   350,
     351,   352,   353,   354,   355,   356,   357,   358,   359,   360,
     361,   362,   363,   365,   364,   366,   367,   368,   369,   370,
     371,   328,   331,   332,   336,   333,   334,   335,   329,   287,
     239,     0,   147,   240,   274,   275,     0,     0,   276,     0,
       0,   286,   288,   289,     0,     0,     0,     0,   294,   295,
     296,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   372,   373,   273,   272,   271,   283,   284,   308,   307,
      63,    80,     0,    67,    68,    69,    70,    71,    72,    74,
       0,    76,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    73,
       0,     0,     0,     0,   325,     0,     0,    21,     0,     0,
       0,   142,    19,   330,   222,    81,     0,     0,   340,     0,
       0,     0,     0,     0,    60,    27,    15,    29,   158,   159,
     178,   176,   179,   177,   152,     0,   185,   183,   182,     0,
       0,   237,     0,     0,   263,     0,   260,   265,   266,     0,
     241,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   145,     0,     0,     0,     0,    32,     0,    36,
       0,     0,     0,   234,     0,   100,   101,   236,     0,   261,
       0,     0,     0,     0,   279,     0,     0,     0,     0,     0,
     297,   298,   299,   300,   301,   302,   303,     0,     0,   306,
       0,    64,     0,    82,    66,     0,     0,    77,    79,    85,
      86,    87,    88,     0,   309,     0,   311,   312,   313,   314,
     315,   316,   317,   318,   319,     0,     0,   321,     0,   323,
     324,     0,   327,    22,    25,     0,     0,    90,   341,     0,
       0,     0,    33,     0,    35,     0,     0,    44,     0,     0,
     235,   264,     0,     0,   249,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    65,    83,     0,    78,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   406,
     392,   393,   394,   395,   396,   397,   398,     0,   407,   410,
       0,     0,     0,     0,     0,     0,    34,     0,     0,    41,
       0,    43,     0,   250,     0,     0,   247,     0,   245,     0,
     280,     0,     0,   290,   291,   292,   293,   304,   305,     0,
     282,     0,     0,     0,   322,   326,     0,    23,   408,     0,
       0,     0,     0,    52,     0,     0,    40,     0,     0,     0,
       0,     0,     0,     0,    42,     0,     0,     0,     0,   243,
       0,     0,     0,     0,     0,     0,     0,     0,   411,   399,
     400,   401,   402,   403,   404,   405,     0,     0,     0,    49,
       0,    51,     0,    37,    39,     0,    48,     0,     0,     0,
     248,     0,     0,     0,   281,   285,     0,     0,     0,     0,
      24,   409,     0,     0,     0,     0,     0,    50,    38,    45,
      47,     0,   246,   244,     0,     0,     0,     0,     0,    89,
      56,     0,     0,     0,    46,   242,    75,   310,    84,     0,
      53,    55,     0,     0,    54,   320
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
   -1238, -1238, -1238,  -191,   171,    37, -1238, -1238,  -662,  -859,
   -1238,  -657,   972, -1238, -1238, -1238, -1238, -1238, -1238,  -220,
     532, -1238, -1238,   -11,  1299,    98,    -7,  -655,    -6,   696,
     -12,   201,   420, -1238, -1238, -1238, -1238, -1238, -1238, -1238,
     354, -1238, -1237,    49,    60, -1238, -1238
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,   195,   196,   197,   663,   667,   404,   407,   668,   669,
     670,   869,   419,   199,   200,   201,   202,   203,   204,   205,
     409,   859,   410,   206,   207,   244,   209,   210,   211,   212,
     213,   245,   972,   973,   215,   216,   709,   217,   218,   219,
     296,   220,  1268,  1269,  1309,  1270,   664
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
     243,   248,   699,   250,   251,   662,   249,   883,   879,  1258,
    1160,   252,   253,   681,   677,   678,   677,   678,   682,   677,
     678,  1308,   683,   677,   678,  1067,   892,   894,   896,   897,
     898,   828,   684,  1115,  1117,   677,   678,   198,   677,   678,
     978,   221,   694,   694,   307,   406,   979,  1060,   308,  1058,
    1061,   705,   857,   928,   858,  1059,   929,   695,   706,   930,
     636,   931,   638,   696,   696,   932,   677,   678,   933,   829,
     934,  1116,  1118,   697,   697,   677,   678,   677,   678,   677,
     678,   935,   677,   678,   329,   677,   678,   677,   678,   936,
     254,   677,   678,   937,   677,   678,   677,   678,   208,   938,
    1308,   939,   636,   940,   638,   941,   307,   677,   678,   942,
     704,   636,   943,   638,   944,   677,   678,   222,   255,   677,
     678,   223,   224,   945,  1221,   677,   678,   677,   678,   677,
     678,   677,   678,  1275,   946,   677,   678,   947,   677,   678,
     677,   678,   948,   256,   811,   812,   949,   257,   815,   677,
     678,   950,   295,   951,   821,   822,   952,   297,   953,   826,
     677,   678,   954,   677,   678,   258,   676,   405,   677,   678,
    1075,   411,   677,   678,  -106,  -106,   844,   677,   678,   677,
     678,   849,   677,   678,   677,   678,   677,   678,   677,   678,
    1256,  1257,   867,   860,   955,   868,  1140,   259,   711,   691,
    1336,   214,   712,  1151,   713,    17,    18,   685,   852,  1074,
    1141,   260,   702,   703,   261,   180,   976,   637,  1065,   262,
     677,   678,   677,   678,  1259,  1260,  1261,  1262,  1263,  1264,
    1265,  1266,  1267,   677,   678,   708,   677,   678,  1068,   180,
    1069,   637,   263,   717,   718,   719,   720,   721,   722,   723,
     724,   725,   726,   727,   728,   729,   730,   731,   732,   733,
     734,   735,   736,   737,   738,   739,   740,   741,   742,   743,
     744,   745,   746,   747,   748,   749,   750,   751,   752,   753,
     754,   755,   756,   757,   759,   636,   760,   638,   761,   264,
     762,   956,   763,  1229,   764,   208,   765,   766,   299,   767,
     265,   768,  1236,   769,   266,   977,   771,  1278,   772,   267,
     773,   268,   774,   269,   775,   270,   776,   677,   678,   271,
     778,   779,   780,   781,   782,   677,   678,   785,   786,   787,
     788,   789,   790,   791,   792,   793,   794,   795,   796,   797,
     798,   799,   800,   801,   802,   803,   804,   805,   806,   807,
     808,   809,   810,   770,   272,   813,   814,   273,   816,   817,
     818,   819,   820,   673,   674,   823,   824,   825,   666,   827,
     957,   830,   831,   832,   833,   834,   835,   836,   837,   838,
     839,   840,   841,   842,   843,   274,   845,   846,   847,   848,
     923,   850,   851,   679,   680,   275,   677,   678,   214,   924,
    1150,   861,   925,   863,  1147,   958,   866,   959,   408,   960,
     872,   961,  1315,   962,   208,   298,   300,   302,   304,   306,
     309,   311,   313,   315,   963,   318,   320,   322,   324,   326,
     328,   677,   678,   677,   678,   677,   678,   677,   678,   677,
     678,   964,   636,   965,   638,   966,   422,   967,   420,   968,
     677,   678,   969,   301,   974,   276,   887,   975,   423,   981,
     672,   982,   692,   693,  1285,   983,   277,   677,   678,   677,
     678,   677,   678,   677,   678,   677,   678,   988,   677,   678,
     677,   678,   989,   677,   678,   677,   678,   677,   678,  1225,
    1228,   677,   678,   990,   303,  1001,   671,  1002,   278,  1235,
    1003,   305,  1004,   677,   678,  1005,   310,  1008,   677,   678,
    1009,   312,  1011,   675,  1013,   710,  1014,   214,  1015,   677,
     678,   677,   678,   677,   678,  1018,   677,   678,   677,   678,
    1019,   677,   678,   677,   678,  1053,   677,   678,   677,   678,
     677,   678,   677,   678,   677,   678,  1055,  1272,   980,  1064,
     279,   677,   678,  1155,  1089,   280,   677,   678,   281,   677,
     678,   677,   678,   677,   678,   677,   678,  1282,   677,   678,
    1156,   282,   677,   678,  1289,   677,   678,  1164,   283,   677,
     678,   298,   300,   302,   304,   306,   309,   311,   313,   315,
     318,   320,   322,   324,   326,   328,   677,   678,  1170,   636,
    1171,   638,  1172,   677,   678,  1173,   314,  1174,   284,  1314,
    1175,   317,  1176,   783,  1179,   784,  1188,   856,  1196,   777,
    1197,  1323,  1198,   285,   677,   678,   677,   678,   677,   678,
    1199,   677,   678,   677,   678,  1087,   677,   678,   677,   678,
     677,   678,   677,   678,   677,   678,   677,   678,   677,   678,
    1088,   855,  1200,  1352,   853,   854,   677,   678,   286,   677,
     678,   287,   885,   886,   288,   873,  1201,   289,   890,   891,
     888,   889,  1202,   290,   677,   678,   291,  1062,   677,   678,
     906,   909,  1203,   910,   913,   916,   905,   908,  1204,   319,
    1209,   915,   677,   678,  1210,   321,  1212,   292,   677,   678,
    1082,   926,   927,  1217,   323,  1218,   876,  1283,   677,   678,
    1293,   325,  1295,   293,   677,   678,   677,   678,  1296,   294,
     677,   678,   677,   678,  1298,   636,  1300,   638,  1304,   677,
     678,   677,   678,   677,   678,  1397,   677,   678,   677,   678,
     316,   636,   327,   638,   677,   678,   636,  1328,   638,   984,
     677,   678,   677,   678,   677,   678,   985,   877,   986,   331,
     987,   677,   678,  1348,   991,   332,   971,   208,  1376,   677,
     678,   333,   334,   992,   335,   993,   677,   678,   677,   678,
     677,   678,   994,   336,   677,   678,   337,   995,   338,   996,
     862,   997,  1111,   677,   678,   677,   678,   998,   339,   340,
     341,   999,   677,   678,  1000,   342,  1120,   677,   678,   677,
     678,   677,   678,  1012,   343,  1020,   344,   677,   678,   704,
    1133,   677,   678,   917,   677,   678,  1022,   345,  1025,   346,
    1026,   347,  1027,   677,   678,   677,   678,  1028,   348,   881,
     882,  1029,  1048,  1049,  1030,   349,   677,   678,   677,   678,
     677,   678,   677,   678,  1031,  1154,  1032,   677,   678,  1033,
     350,   677,   678,  1034,   677,   678,  1035,   351,   352,   353,
     214,   354,  1152,   355,   677,   678,   677,   678,   864,   677,
     678,   356,   357,   677,   678,  1036,   677,   678,   358,  1047,
    1037,   359,  1070,  1071,  1038,  1072,  1073,  1052,  1161,  1040,
    1076,  1041,  1077,  1078,  1042,   677,   678,  1079,  1080,  1043,
     677,   678,  1084,  1045,   677,   678,  1046,   360,  1162,   677,
     678,   677,   678,  1163,   677,   678,  -123,   361,  1165,   677,
     678,  1166,   362,   677,   678,  1167,   677,   678,   677,   678,
    1168,   363,  1237,   677,   678,   677,   678,  1241,   677,   678,
     208,   677,   678,   364,   365,   677,   678,  1244,   208,   366,
     677,   678,   971,   367,   368,  1091,  1092,   369,  1093,  1094,
     874,   370,  1169,  1095,  1096,  1097,  1098,  1177,   208,  1178,
    1099,  1100,  1101,  1102,  1103,  1104,  1105,  1106,  1107,  1108,
     371,  1255,   677,   678,  1185,   372,   373,   677,   678,   677,
     678,   374,   375,   686,   687,   376,   377,   688,   378,  1112,
     379,  1114,   689,   690,   677,   678,  1121,  1122,  1123,  1124,
    1125,  1126,  1127,  1128,  1129,  1130,  1131,  1132,  1271,  1195,
    1134,  1135,  1136,  1317,  1137,  1138,  1205,   865,  1206,  1142,
     875,   380,  1208,   381,  1211,  1143,  1144,  1216,  1145,   677,
     678,   677,   678,   214,  1066,  1291,   677,   678,   677,   678,
    1318,   214,   677,   678,   677,   678,  1292,   677,   678,  1299,
     382,  1330,  1331,  1301,   383,   677,   678,   384,   677,   678,
    1302,   214,   385,  1303,   878,  1366,   677,   678,  1367,   677,
     678,  1368,   386,   677,   678,  1369,   387,  1399,  1181,  1183,
     677,   678,  1187,   677,   678,   677,   678,  -124,   677,   678,
    1320,   677,   678,  -125,   388,   677,   678,   677,   678,  -126,
     389,  -127,   390,  -128,   391,  -129,   677,   678,   677,   678,
    1215,  -130,   677,   678,   392,   393,   394,  1220,   677,   678,
     677,   678,   677,   678,   677,   678,  1385,  1231,  1387,  1232,
     677,   678,  1238,  -131,  1239,  1240,   395,  1242,  1243,   880,
     208,  -132,   758,   396,   397,   398,  -133,  1245,  -134,  1246,
    -135,  1247,   677,   678,  1248,  1249,  1213,  1214,   399,  1403,
     677,   678,  1250,  -137,  1251,   677,   678,   677,   678,   677,
     678,   400,   884,   401,  1252,  1253,   970,  1254,  -136,   402,
    -138,   403,   677,   678,  1006,  1325,   412,  1355,   413,  1357,
    1273,  1358,  1274,  1361,   414,  1277,  1362,   677,   678,   677,
     678,  1373,  1284,   677,   678,   677,   678,   677,   678,   677,
     678,   677,   678,  1149,   677,   678,  1381,   208,   208,   677,
     678,   415,  1384,   911,   416,  1306,   417,  1391,   418,   208,
     208,   421,  1392,   921,   677,   678,   222,   918,   919,   208,
     677,   678,  1402,   214,  1319,   677,   678,  1321,   920,  1322,
     677,   678,   922,  1007,  1326,  1010,  1327,  1016,  1017,  1021,
     677,   678,   714,   715,   716,  1039,  1023,  1024,  1332,  1044,
    1333,  1334,  1335,  1050,  1307,  1054,  1063,   677,   678,  1056,
    1057,  1347,  1259,  1260,  1261,  1262,  1263,  1264,  1265,  1266,
    1267,  1061,  1359,  1075,   665,  1085,  1109,  1363,  1086,  1119,
    1110,  1222,  1224,  1227,  1113,  1139,  1146,   208,  1157,  1158,
    1184,  1159,  1234,  1189,   208,  1190,  1191,  1374,  1192,  1375,
     214,   214,  1260,  1261,  1262,  1263,  1264,  1265,  1266,  1267,
    1193,  1194,   214,   214,  1207,   208,  1386,  1219,  1388,  1230,
    1290,  1294,   214,  1297,  1305,  1393,  1310,  1338,  1311,   208,
    1346,  1337,  1364,  1370,  1365,  1339,  1340,  1341,  1342,  1343,
    1344,  1345,   899,   900,   901,   902,   903,  1389,  1396,  1398,
    1405,  1051,   870,  1090,   330,  1372,  1276,  1371,     0,  1279,
    1281,     0,     0,     0,     0,     0,  1286,  1288,     0,     0,
       0,     0,     0,   208,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     214,     0,     0,     0,   208,     0,     0,   214,     0,     0,
       0,     0,  1313,  1316,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1324,     0,     0,     0,     0,   214,     0,
    1329,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   214,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1349,  1351,     0,  1353,  1354,
       0,  1356,     0,     0,     0,     0,  1360,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   214,     0,     0,     0,
       0,     0,     0,  1377,     0,     0,  1378,     0,  1379,  1380,
       0,     0,  1382,  1383,     0,     0,     0,   214,     0,     0,
       0,     0,     0,     0,  1390,     0,     0,     0,     0,     0,
       0,     0,  1394,     0,     0,  1395,     0,     0,     0,     0,
       0,     0,  1400,  1401,     0,     0,     0,     0,     0,     0,
       0,     0,     1,  1404,     2,     3,     4,     5,     6,     7,
       8,     9,    10,    11,     0,    12,     0,     0,     0,     0,
       0,    13,     0,    14,     0,     0,     0,     0,     0,     0,
       0,    15,     0,     0,     0,     0,     0,     0,     0,    16,
       0,     0,    17,    18,     0,     0,     0,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    68,    69,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    89,    90,    91,
      92,    93,    94,    95,     0,    96,    97,    98,    99,   100,
     101,   102,   103,   104,     0,     0,   105,   106,   107,   108,
     109,   110,   111,   112,   113,   114,   115,   116,   117,   118,
     119,   120,   121,   122,   123,   124,   125,   126,   127,   128,
     129,   130,   131,   132,   133,   134,   135,   136,   137,   138,
     139,   140,   141,   142,   143,   144,   145,   146,   147,   148,
     149,   150,   151,   152,   153,   154,   155,   156,   157,   158,
     159,   160,   161,   162,   163,   164,   165,   166,   167,   168,
     169,   170,   171,   172,   173,   174,   175,   176,   177,   178,
       0,     0,   179,     0,     0,     0,     0,     0,   180,     0,
     181,     0,   182,   183,   184,   185,   186,   187,   188,     0,
     189,     0,     0,     0,     0,     0,     0,     0,     0,   190,
     191,     0,   192,   193,   194,   424,     0,   425,   426,   427,
     428,   429,   430,   431,   432,   433,   434,   435,   436,   437,
     438,   439,   440,   441,   442,   443,   444,   445,   446,   447,
     448,   449,   450,   451,   452,   453,     0,   454,   455,   456,
     457,   458,   459,   460,   461,   462,   463,   464,   465,   466,
     467,   468,   469,   470,   471,   472,   473,   474,   475,   476,
     477,   478,   479,   480,   481,   482,   483,   484,   485,   486,
     487,   488,   489,   490,   491,   492,   493,   494,   495,   496,
     497,   498,   499,   500,   501,   502,   503,   504,   505,   506,
     507,   508,   509,   510,   511,   512,   513,   514,   515,   516,
     517,   518,   519,   520,   521,   522,   523,   524,   525,   526,
     527,   528,   529,   530,   531,   532,   533,   534,   535,   536,
     537,   538,   539,   540,   541,   542,   543,   544,   545,   546,
     547,   548,   549,   550,   551,   552,   553,   554,   555,   556,
     557,   558,   559,   560,   561,   562,   563,   564,   565,   566,
     567,   568,   569,   570,   571,   572,   573,   574,   575,   576,
     577,   578,   579,   580,   581,   582,   583,   584,   585,   586,
     587,   588,   589,   590,   591,   592,   593,   594,   595,   596,
     597,   598,   599,   600,   601,   602,   603,   604,   605,   606,
     607,   608,   609,   610,   611,   612,   613,   614,   615,   616,
     617,   618,   619,   620,   621,   622,   623,   624,   625,   626,
     627,   628,   629,   630,   631,   632,   633,   634,   635,   180,
     636,   637,   638,   639,   640,   641,   642,   643,   644,   645,
     646,   647,   648,   649,   650,   651,   652,   653,   654,   655,
     656,   657,   658,   659,   660,   661,     2,     3,     4,     5,
       6,     7,     8,     9,    10,    11,     0,    12,     0,     0,
       0,     0,     0,    13,     0,    14,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    16,     0,     0,    17,    18,     0,     0,     0,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    68,    69,
      70,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    91,    92,    93,    94,    95,     0,    96,    97,    98,
      99,   100,   101,   102,   103,   104,     0,     0,   105,   106,
     107,   108,   109,   110,   111,   112,   113,   114,   115,   116,
     117,   118,   119,   120,   121,   122,   123,   124,   125,   126,
     127,   128,   129,   130,   131,   132,   133,   134,   135,   136,
     137,   138,   139,   140,   141,   142,   143,   144,   145,   146,
     147,   148,   149,   150,   151,   152,   153,   154,   155,   156,
     157,   158,   159,   160,   161,   162,   163,   164,   165,   166,
     167,   168,   169,   170,   171,   172,   173,   174,   175,   176,
     177,   178,     0,     0,   179,     0,     0,     0,     0,     0,
     180,   636,   181,   638,   182,   183,   184,   185,   186,   187,
     188,     0,   189,     0,     0,     0,     0,     0,     0,     0,
     665,   190,   191,  1148,   192,     2,     3,     4,     5,     6,
       7,     8,     9,    10,    11,     0,    12,     0,     0,     0,
       0,     0,    13,     0,    14,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      16,     0,     0,    17,    18,     0,     0,     0,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    68,    69,    70,
      71,    72,    73,    74,    75,    76,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    89,    90,
      91,    92,    93,    94,    95,     0,    96,    97,    98,    99,
     100,   101,   102,   103,   104,     0,     0,   105,   106,   107,
     108,   109,   110,   111,   112,   113,   114,   115,   116,   117,
     118,   119,   120,   121,   122,   123,   124,   125,   126,   127,
     128,   129,   130,   131,   132,   133,   134,   135,   136,   137,
     138,   139,   140,   141,   142,   143,   144,   145,   146,   147,
     148,   149,   150,   151,   152,   153,   154,   155,   156,   157,
     158,   159,   160,   161,   162,   163,   164,   165,   166,   167,
     168,   169,   170,   171,   172,   173,   174,   175,   176,   177,
     178,     0,     0,   179,     0,     0,     0,     0,     0,   180,
     636,   181,   638,   182,   183,   184,   185,   186,   187,   188,
       0,   189,     0,     0,     0,     0,     0,     0,     0,   665,
     190,   191,  1226,   192,     2,     3,     4,     5,     6,     7,
       8,     9,    10,    11,     0,    12,     0,     0,     0,     0,
       0,    13,     0,    14,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    16,
       0,     0,    17,    18,     0,     0,     0,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    68,    69,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    89,    90,    91,
      92,    93,    94,    95,     0,    96,    97,    98,    99,   100,
     101,   102,   103,   104,     0,     0,   105,   106,   107,   108,
     109,   110,   111,   112,   113,   114,   115,   116,   117,   118,
     119,   120,   121,   122,   123,   124,   125,   126,   127,   128,
     129,   130,   131,   132,   133,   134,   135,   136,   137,   138,
     139,   140,   141,   142,   143,   144,   145,   146,   147,   148,
     149,   150,   151,   152,   153,   154,   155,   156,   157,   158,
     159,   160,   161,   162,   163,   164,   165,   166,   167,   168,
     169,   170,   171,   172,   173,   174,   175,   176,   177,   178,
       0,     0,   179,     0,     0,     0,     0,     0,   180,   636,
     181,   638,   182,   183,   184,   185,   186,   187,   188,     0,
     189,     0,     0,     0,     0,     0,     0,     0,   665,   190,
     191,  1233,   192,     2,     3,     4,     5,     6,     7,     8,
       9,    10,    11,     0,    12,     0,     0,     0,     0,     0,
      13,     0,    14,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    16,     0,
       0,    17,    18,     0,     0,     0,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,    68,    69,    70,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    88,    89,    90,    91,    92,
      93,    94,    95,     0,    96,    97,    98,    99,   100,   101,
     102,   103,   104,     0,     0,   105,   106,   107,   108,   109,
     110,   111,   112,   113,   114,   115,   116,   117,   118,   119,
     120,   121,   122,   123,   124,   125,   126,   127,   128,   129,
     130,   131,   132,   133,   134,   135,   136,   137,   138,   139,
     140,   141,   142,   143,   144,   145,   146,   147,   148,   149,
     150,   151,   152,   153,   154,   155,   156,   157,   158,   159,
     160,   161,   162,   163,   164,   165,   166,   167,   168,   169,
     170,   171,   172,   173,   174,   175,   176,   177,   178,     0,
       0,   179,     0,     0,     0,     0,     0,   180,   636,   181,
     638,   182,   183,   184,   185,   186,   187,   188,     0,   189,
       0,     0,     0,     0,     0,     0,     0,   665,   190,   191,
    1312,   192,     2,     3,     4,     5,     6,     7,     8,     9,
      10,    11,     0,    12,     0,     0,     0,     0,     0,    13,
       0,    14,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    16,     0,     0,
      17,    18,     0,     0,     0,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    68,    69,    70,    71,    72,    73,
      74,    75,    76,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    90,    91,    92,    93,
      94,    95,     0,    96,    97,    98,    99,   100,   101,   102,
     103,   104,     0,     0,   105,   106,   107,   108,   109,   110,
     111,   112,   113,   114,   115,   116,   117,   118,   119,   120,
     121,   122,   123,   124,   125,   126,   127,   128,   129,   130,
     131,   132,   133,   134,   135,   136,   137,   138,   139,   140,
     141,   142,   143,   144,   145,   146,   147,   148,   149,   150,
     151,   152,   153,   154,   155,   156,   157,   158,   159,   160,
     161,   162,   163,   164,   165,   166,   167,   168,   169,   170,
     171,   172,   173,   174,   175,   176,   177,   178,     0,     0,
     179,     0,     0,     0,     0,     0,   180,   636,   181,   638,
     182,   183,   184,   185,   186,   187,   188,     0,   189,     0,
       0,     0,     0,     0,     0,     0,   665,   190,   191,     0,
     192,     2,     3,     4,     5,     6,     7,     8,     9,    10,
      11,     0,    12,     0,     0,     0,     0,     0,    13,     0,
      14,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    16,     0,     0,    17,
      18,     0,     0,     0,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,     0,    96,    97,    98,    99,   100,   101,   102,   103,
     104,     0,     0,   105,   106,   107,   108,   109,   110,   111,
     112,   113,   114,   115,   116,   117,   118,   119,   120,   121,
     122,   123,   124,   125,   126,   127,   128,   129,   130,   131,
     132,   133,   134,   135,   136,   137,   138,   139,   140,   141,
     142,   143,   144,   145,   146,   147,   148,   149,   150,   151,
     152,   153,   154,   155,   156,   157,   158,   159,   160,   161,
     162,   163,   164,   165,   166,   167,   168,   169,   170,   171,
     172,   173,   174,   175,   176,   177,   178,     0,     0,   179,
       0,     0,     0,     0,     0,   180,   636,   181,   638,   182,
     183,   184,   185,   186,   187,   188,     0,   189,     0,     0,
       0,     0,     0,     0,     0,     0,   190,   191,  1223,   192,
       2,     3,     4,     5,     6,     7,     8,     9,    10,    11,
       0,    12,     0,     0,     0,     0,     0,    13,     0,    14,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    16,     0,     0,    17,    18,
       0,     0,     0,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    68,    69,    70,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    90,    91,    92,    93,    94,    95,
       0,    96,    97,    98,    99,   100,   101,   102,   103,   104,
       0,     0,   105,   106,   107,   108,   109,   110,   111,   112,
     113,   114,   115,   116,   117,   118,   119,   120,   121,   122,
     123,   124,   125,   126,   127,   128,   129,   130,   131,   132,
     133,   134,   135,   136,   137,   138,   139,   140,   141,   142,
     143,   144,   145,   146,   147,   148,   149,   150,   151,   152,
     153,   154,   155,   156,   157,   158,   159,   160,   161,   162,
     163,   164,   165,   166,   167,   168,   169,   170,   171,   172,
     173,   174,   175,   176,   177,   178,     0,     0,   179,     0,
       0,     0,     0,     0,   180,   636,   181,   638,   182,   183,
     184,   185,   186,   187,   188,     0,   189,     0,     0,     0,
       0,     0,     0,     0,     0,   190,   191,  1280,   192,     2,
       3,     4,     5,     6,     7,     8,     9,    10,    11,     0,
      12,     0,     0,     0,     0,     0,    13,     0,    14,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    16,     0,     0,    17,    18,     0,
       0,     0,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,    68,    69,    70,    71,    72,    73,    74,    75,    76,
      77,    78,    79,    80,    81,    82,    83,    84,    85,    86,
      87,    88,    89,    90,    91,    92,    93,    94,    95,     0,
      96,    97,    98,    99,   100,   101,   102,   103,   104,     0,
       0,   105,   106,   107,   108,   109,   110,   111,   112,   113,
     114,   115,   116,   117,   118,   119,   120,   121,   122,   123,
     124,   125,   126,   127,   128,   129,   130,   131,   132,   133,
     134,   135,   136,   137,   138,   139,   140,   141,   142,   143,
     144,   145,   146,   147,   148,   149,   150,   151,   152,   153,
     154,   155,   156,   157,   158,   159,   160,   161,   162,   163,
     164,   165,   166,   167,   168,   169,   170,   171,   172,   173,
     174,   175,   176,   177,   178,     0,     0,   179,     0,     0,
       0,     0,     0,   180,   636,   181,   638,   182,   183,   184,
     185,   186,   187,   188,     0,   189,     0,     0,     0,     0,
       0,     0,     0,     0,   190,   191,  1287,   192,     2,     3,
       4,     5,     6,     7,     8,     9,    10,    11,     0,    12,
       0,     0,     0,     0,     0,    13,     0,    14,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    16,     0,     0,    17,    18,     0,     0,
       0,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      68,    69,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    90,    91,    92,    93,    94,    95,     0,    96,
      97,    98,    99,   100,   101,   102,   103,   104,     0,     0,
     105,   106,   107,   108,   109,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   131,   132,   133,   134,
     135,   136,   137,   138,   139,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150,   151,   152,   153,   154,
     155,   156,   157,   158,   159,   160,   161,   162,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   172,   173,   174,
     175,   176,   177,   178,     0,     0,   179,     0,     0,     0,
       0,     0,   180,   636,   181,   638,   182,   183,   184,   185,
     186,   187,   188,     0,   189,     0,     0,     0,     0,     0,
       0,     0,     0,   190,   191,  1350,   192,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,     0,    12,     0,
       0,     0,     0,     0,    13,     0,    14,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    16,     0,     0,    17,    18,     0,     0,     0,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    68,
      69,    70,    71,    72,    73,    74,    75,    76,    77,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    87,    88,
      89,    90,    91,    92,    93,    94,    95,     0,    96,    97,
      98,    99,   100,   101,   102,   103,   104,     0,     0,   105,
     106,   107,   108,   109,   110,   111,   112,   113,   114,   115,
     116,   117,   118,   119,   120,   121,   122,   123,   124,   125,
     126,   127,   128,   129,   130,   131,   132,   133,   134,   135,
     136,   137,   138,   139,   140,   141,   142,   143,   144,   145,
     146,   147,   148,   149,   150,   151,   152,   153,   154,   155,
     156,   157,   158,   159,   160,   161,   162,   163,   164,   165,
     166,   167,   168,   169,   170,   171,   172,   173,   174,   175,
     176,   177,   178,     0,     0,   179,     0,     0,     0,     0,
       0,   180,   636,   181,   638,   182,   183,   184,   185,   186,
     187,   188,     0,   189,     0,     0,     0,     0,     0,     0,
       0,     0,   190,   191,     0,   192,     2,     3,     4,     5,
       6,     7,     8,     9,    10,    11,     0,    12,     0,     0,
       0,     0,     0,    13,     0,    14,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    16,     0,     0,    17,    18,     0,     0,     0,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    68,    69,
      70,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    91,    92,    93,    94,    95,     0,    96,    97,    98,
      99,   100,   101,   102,   103,   104,     0,     0,   105,   106,
     107,   108,   109,   110,   111,   112,   113,   114,   115,   116,
     117,   118,   119,   120,   121,   122,   123,   124,   125,   126,
     127,   128,   129,   130,   131,   132,   133,   134,   135,   136,
     137,   138,   139,   140,   141,   142,   143,   144,   145,   146,
     147,   148,   149,   150,   151,   152,   153,   154,   155,   156,
     157,   158,   159,   160,   161,   162,   163,   164,   165,   166,
     167,   168,   169,   170,   171,   172,   173,   174,   175,   176,
     177,   178,     0,     0,   179,     0,     0,     0,     0,     0,
     180,     0,   181,     0,   182,   183,   184,   185,   186,   187,
     188,     0,   189,     0,     0,     0,     0,     0,     0,     0,
       0,   190,   191,     0,   192,     2,     3,     4,     5,     6,
       7,     8,   225,    10,    11,     0,    12,     0,     0,     0,
       0,     0,    13,     0,    14,     0,     0,     0,     0,     0,
       0,     0,     0,   246,     0,     0,     0,     0,     0,     0,
      16,     0,   247,    17,    18,     0,     0,     0,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    59,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,    70,
     236,   237,   238,   239,   240,   241,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    89,    90,
      91,    92,    93,    94,    95,     0,    96,    97,    98,    99,
     100,   101,     0,     0,     0,     0,     0,   105,   106,   107,
     108,   109,   110,   111,   112,   113,   114,   115,   116,   117,
     118,   119,   120,   121,   122,   123,   124,   125,   126,   127,
     128,   129,   130,   131,   132,   133,   134,   135,   136,   137,
     138,   139,   140,   141,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   156,   157,
     158,   159,   160,   161,   162,   163,   164,   165,   166,   167,
       0,   169,     0,   171,   172,   173,   174,   175,   176,   177,
       0,     2,     3,     4,     5,     6,     7,     8,   225,    10,
      11,   242,    12,     0,   183,   184,     0,     0,    13,   188,
      14,   189,     0,     0,     0,     0,     0,     0,     0,     0,
     190,     0,     0,     0,     0,     0,    16,     0,     0,    17,
      18,     0,     0,     0,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,    70,   236,   237,   238,   239,
     240,   241,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,     0,    96,    97,    98,    99,   100,   101,     0,     0,
       0,   700,   701,   105,   106,   107,   108,   109,   110,   111,
     112,   113,   114,   115,   116,   117,   118,   119,   120,   121,
     122,   123,   124,   125,   126,   127,   128,   129,   130,   131,
     132,   133,   134,   135,   136,   137,   138,   139,   140,   141,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   156,   157,   158,   159,   160,   161,
     162,   163,   164,   165,   166,   167,     0,   169,     0,   171,
     172,   173,   174,   175,   176,   177,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   242,     0,     0,
     183,   184,     0,     0,     0,   188,     0,   189,     0,     0,
       0,     0,     0,     0,     0,     0,   190,     2,     3,     4,
       5,     6,     7,     8,   225,    10,    11,   698,    12,     0,
       0,     0,     0,     0,    13,     0,    14,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    16,     0,     0,    17,    18,     0,     0,     0,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    56,    57,    58,
      59,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,    70,   236,   237,   238,   239,   240,   241,    77,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    87,    88,
      89,    90,    91,    92,    93,    94,    95,     0,    96,    97,
      98,    99,   100,   101,     0,     0,     0,     0,     0,   105,
     106,   107,   108,   109,   110,   111,   112,   113,   114,   115,
     116,   117,   118,   119,   120,   121,   122,   123,   124,   125,
     126,   127,   128,   129,   130,   131,   132,   133,   134,   135,
     136,   137,   138,   139,   140,   141,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     156,   157,   158,   159,   160,   161,   162,   163,   164,   165,
     166,   167,     0,   169,     0,   171,   172,   173,   174,   175,
     176,   177,     0,     2,     3,     4,     5,     6,     7,     8,
     225,    10,    11,   242,    12,     0,   183,   184,     0,     0,
      13,   188,    14,   189,     0,     0,     0,     0,     0,     0,
       0,   707,   190,     0,     0,     0,     0,     0,    16,     0,
       0,    17,    18,     0,     0,     0,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    59,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,    70,   236,   237,
     238,   239,   240,   241,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    88,    89,    90,    91,    92,
      93,    94,    95,     0,    96,    97,    98,    99,   100,   101,
       0,     0,     0,     0,     0,   105,   106,   107,   108,   109,
     110,   111,   112,   113,   114,   115,   116,   117,   118,   119,
     120,   121,   122,   123,   124,   125,   126,   127,   128,   129,
     130,   131,   132,   133,   134,   135,   136,   137,   138,   139,
     140,   141,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   156,   157,   158,   159,
     160,   161,   162,   163,   164,   165,   166,   167,     0,   169,
       0,   171,   172,   173,   174,   175,   176,   177,     0,     2,
       3,     4,     5,     6,     7,     8,   225,    10,    11,   242,
      12,     0,   183,   184,     0,     0,    13,   188,    14,   189,
       0,     0,     0,     0,     0,     0,   758,     0,   190,     0,
       0,     0,     0,     0,    16,     0,     0,    17,    18,     0,
       0,     0,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    59,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,    70,   236,   237,   238,   239,   240,   241,
      77,    78,    79,    80,    81,    82,    83,    84,    85,    86,
      87,    88,    89,    90,    91,    92,    93,    94,    95,     0,
      96,    97,    98,    99,   100,   101,     0,     0,     0,     0,
       0,   105,   106,   107,   108,   109,   110,   111,   112,   113,
     114,   115,   116,   117,   118,   119,   120,   121,   122,   123,
     124,   125,   126,   127,   128,   129,   130,   131,   132,   133,
     134,   135,   136,   137,   138,   139,   140,   141,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   156,   157,   158,   159,   160,   161,   162,   163,
     164,   165,   166,   167,     0,   169,     0,   171,   172,   173,
     174,   175,   176,   177,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   242,     0,     0,   183,   184,
       0,     0,     0,   188,     0,   189,     0,     0,     0,     0,
       0,     0,     0,     0,   190,     2,     3,     4,     5,     6,
       7,     8,   225,    10,    11,   871,    12,     0,     0,     0,
       0,     0,    13,     0,    14,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      16,     0,     0,    17,    18,     0,     0,     0,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    59,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,    70,
     236,   237,   238,   239,   240,   241,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    89,    90,
      91,    92,    93,    94,    95,     0,    96,    97,    98,    99,
     100,   101,     0,     0,     0,     0,     0,   105,   106,   107,
     108,   109,   110,   111,   112,   113,   114,   115,   116,   117,
     118,   119,   120,   121,   122,   123,   124,   125,   126,   127,
     128,   129,   130,   131,   132,   133,   134,   135,   136,   137,
     138,   139,   140,   141,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   156,   157,
     158,   159,   160,   161,   162,   163,   164,   165,   166,   167,
       0,   169,     0,   171,   172,   173,   174,   175,   176,   177,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   242,     0,     0,   183,   184,     0,     0,     0,   188,
       0,   189,     0,     0,     0,     0,     0,     0,     0,     0,
     190,     2,     3,     4,     5,     6,     7,     8,   225,    10,
      11,  1081,    12,     0,     0,     0,     0,     0,    13,     0,
      14,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    16,     0,     0,    17,
      18,     0,     0,     0,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,    70,   236,   237,   238,   239,
     240,   241,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,     0,    96,    97,    98,    99,   100,   101,     0,     0,
       0,     0,     0,   105,   106,   107,   108,   109,   110,   111,
     112,   113,   114,   115,   116,   117,   118,   119,   120,   121,
     122,   123,   124,   125,   126,   127,   128,   129,   130,   131,
     132,   133,   134,   135,   136,   137,   138,   139,   140,   141,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   156,   157,   158,   159,   160,   161,
     162,   163,   164,   165,   166,   167,     0,   169,     0,   171,
     172,   173,   174,   175,   176,   177,     0,     2,     3,     4,
       5,     6,     7,     8,   225,    10,    11,   242,    12,     0,
     183,   184,     0,     0,    13,   188,    14,   189,     0,     0,
       0,     0,  1083,     0,     0,     0,   190,     0,     0,     0,
       0,     0,    16,     0,     0,    17,    18,     0,     0,     0,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    56,    57,    58,
      59,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,    70,   236,   237,   238,   239,   240,   241,    77,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    87,    88,
      89,    90,    91,    92,    93,    94,    95,     0,    96,    97,
      98,    99,   100,   101,     0,     0,     0,     0,     0,   105,
     106,   107,   108,   109,   110,   111,   112,   113,   114,   115,
     116,   117,   118,   119,   120,   121,   122,   123,   124,   125,
     126,   127,   128,   129,   130,   131,   132,   133,   134,   135,
     136,   137,   138,   139,   140,   141,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     156,   157,   158,   159,   160,   161,   162,   163,   164,   165,
     166,   167,     0,   169,     0,   171,   172,   173,   174,   175,
     176,   177,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   242,     0,     0,   183,   184,     0,     0,
       0,   188,     0,   189,     0,     0,     0,     0,     0,     0,
       0,     0,   190,     2,     3,     4,     5,     6,     7,     8,
     225,    10,    11,  1153,    12,     0,     0,     0,     0,     0,
      13,     0,    14,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    16,     0,
       0,    17,    18,     0,     0,     0,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    59,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,    70,   236,   237,
     238,   239,   240,   241,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    88,    89,    90,    91,    92,
      93,    94,    95,     0,    96,    97,    98,    99,   100,   101,
       0,     0,     0,     0,     0,   105,   106,   107,   108,   109,
     110,   111,   112,   113,   114,   115,   116,   117,   118,   119,
     120,   121,   122,   123,   124,   125,   126,   127,   128,   129,
     130,   131,   132,   133,   134,   135,   136,   137,   138,   139,
     140,   141,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   156,   157,   158,   159,
     160,   161,   162,   163,   164,   165,   166,   167,     0,   169,
       0,   171,   172,   173,   174,   175,   176,   177,     0,     2,
       3,     4,     5,     6,     7,     8,   225,    10,    11,   242,
      12,     0,   183,   184,     0,     0,    13,   188,    14,   189,
       0,     0,     0,  1180,     0,     0,     0,     0,   190,     0,
       0,     0,     0,     0,    16,     0,     0,    17,    18,     0,
       0,     0,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    59,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,    70,   236,   237,   238,   239,   240,   241,
      77,    78,    79,    80,    81,    82,    83,    84,    85,    86,
      87,    88,    89,    90,    91,    92,    93,    94,    95,     0,
      96,    97,    98,    99,   100,   101,     0,     0,     0,     0,
       0,   105,   106,   107,   108,   109,   110,   111,   112,   113,
     114,   115,   116,   117,   118,   119,   120,   121,   122,   123,
     124,   125,   126,   127,   128,   129,   130,   131,   132,   133,
     134,   135,   136,   137,   138,   139,   140,   141,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   156,   157,   158,   159,   160,   161,   162,   163,
     164,   165,   166,   167,     0,   169,     0,   171,   172,   173,
     174,   175,   176,   177,     0,     2,     3,     4,     5,     6,
       7,     8,   225,    10,    11,   242,    12,     0,   183,   184,
       0,     0,    13,   188,    14,   189,     0,     0,     0,  1182,
       0,     0,     0,     0,   190,     0,     0,     0,     0,     0,
      16,     0,     0,    17,    18,     0,     0,     0,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    59,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,    70,
     236,   237,   238,   239,   240,   241,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    89,    90,
      91,    92,    93,    94,    95,     0,    96,    97,    98,    99,
     100,   101,     0,     0,     0,     0,     0,   105,   106,   107,
     108,   109,   110,   111,   112,   113,   114,   115,   116,   117,
     118,   119,   120,   121,   122,   123,   124,   125,   126,   127,
     128,   129,   130,   131,   132,   133,   134,   135,   136,   137,
     138,   139,   140,   141,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   156,   157,
     158,   159,   160,   161,   162,   163,   164,   165,   166,   167,
       0,   169,     0,   171,   172,   173,   174,   175,   176,   177,
       0,     2,     3,     4,     5,     6,     7,     8,   225,    10,
      11,   242,    12,     0,   183,   184,     0,     0,    13,   188,
      14,   189,     0,     0,     0,  1186,     0,     0,     0,     0,
     190,     0,     0,     0,     0,     0,    16,     0,     0,    17,
      18,     0,     0,     0,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,    70,   236,   237,   238,   239,
     240,   241,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,     0,    96,    97,    98,    99,   100,   101,     0,     0,
       0,     0,     0,   105,   106,   107,   108,   109,   110,   111,
     112,   113,   114,   115,   116,   117,   118,   119,   120,   121,
     122,   123,   124,   125,   126,   127,   128,   129,   130,   131,
     132,   133,   134,   135,   136,   137,   138,   139,   140,   141,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   156,   157,   158,   159,   160,   161,
     162,   163,   164,   165,   166,   167,     0,   169,     0,   171,
     172,   173,   174,   175,   176,   177,     0,     2,     3,     4,
       5,     6,     7,     8,   225,    10,    11,   242,    12,     0,
     183,   184,     0,     0,    13,   188,    14,   189,     0,     0,
       0,     0,     0,     0,     0,     0,   190,     0,     0,     0,
       0,     0,    16,     0,     0,    17,    18,     0,     0,     0,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    56,    57,    58,
      59,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,    70,   236,   237,   238,   239,   240,   241,    77,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    87,    88,
      89,    90,    91,    92,    93,    94,    95,     0,    96,    97,
      98,    99,   100,   101,     0,     0,     0,     0,     0,   105,
     106,   107,   108,   109,   110,   111,   112,   113,   114,   115,
     116,   117,   118,   119,   120,   121,   122,   123,   124,   125,
     126,   127,   128,   129,   130,   131,   132,   133,   134,   135,
     136,   137,   138,   139,   140,   141,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     156,   157,   158,   159,   160,   161,   162,   163,   164,   165,
     166,   167,     0,   169,     0,   171,   172,   173,   174,   175,
     176,   177,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   242,     0,     0,   183,   184,     0,     0,
       0,   188,     0,   189,     0,     0,     0,     0,     0,     0,
       0,     0,   190,     2,     3,     4,     5,     6,     7,     8,
     225,    10,    11,     0,    12,     0,   893,     0,     0,     0,
       0,     0,    14,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    16,     0,
       0,    17,    18,     0,     0,     0,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    59,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,    70,   236,   237,
     238,   239,   240,   241,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    88,    89,    90,    91,    92,
      93,    94,     0,     0,    96,    97,    98,    99,   100,   101,
       0,     0,     0,     0,     0,   105,   106,   107,   108,   109,
     110,   111,   112,   113,   114,   115,   116,   117,   118,   119,
     120,   121,   122,   123,   124,   125,   126,   127,   128,   129,
     130,   131,   132,   133,   134,   135,   136,   137,   138,   139,
     140,   141,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   156,   157,   158,   159,
     160,   161,   162,   163,   164,   165,   166,   167,     0,   169,
       0,   171,   172,   173,   174,   175,   176,   177,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   242,
       0,     0,   183,   184,     0,     0,     0,   188,     0,   189,
       0,     0,     0,     0,     0,     0,     0,     0,   190,     2,
       3,     4,     5,     6,     7,     8,   225,    10,    11,     0,
      12,     0,   895,     0,     0,     0,     0,     0,    14,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    16,     0,     0,    17,    18,     0,
       0,     0,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    59,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,    70,   236,   237,   238,   239,   240,   241,
      77,    78,    79,    80,    81,    82,    83,    84,    85,    86,
      87,    88,    89,    90,    91,    92,    93,    94,     0,     0,
      96,    97,    98,    99,   100,   101,     0,     0,     0,     0,
       0,   105,   106,   107,   108,   109,   110,   111,   112,   113,
     114,   115,   116,   117,   118,   119,   120,   121,   122,   123,
     124,   125,   126,   127,   128,   129,   130,   131,   132,   133,
     134,   135,   136,   137,   138,   139,   140,   141,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   156,   157,   158,   159,   160,   161,   162,   163,
     164,   165,   166,   167,     0,   169,     0,   171,   172,   173,
     174,   175,   176,   177,     0,     2,     3,     4,     5,     6,
       7,     8,   225,    10,    11,   242,    12,     0,   183,   184,
       0,     0,     0,   188,    14,   189,     0,     0,     0,     0,
       0,     0,     0,     0,   190,     0,     0,     0,     0,     0,
      16,     0,     0,    17,    18,     0,     0,     0,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    59,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,    70,
     236,   237,   238,   239,   240,   241,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    89,    90,
      91,    92,    93,    94,     0,     0,    96,    97,    98,    99,
     100,   101,     0,     0,     0,     0,     0,   105,   106,   107,
     108,   109,   110,   111,   112,   113,   114,   115,   116,   117,
     118,   119,   120,   121,   122,   123,   124,   125,   126,   127,
     128,   129,   130,   131,   132,   133,   134,   135,   136,   137,
     138,   139,   140,   141,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   156,   157,
     158,   159,   160,   161,   162,   163,   164,   165,   166,   167,
       0,   169,     0,   171,   172,   173,   174,   175,   176,   177,
       0,     2,     3,     4,     5,     6,     7,     8,   225,    10,
      11,   242,    12,     0,   183,   184,     0,     0,     0,   188,
      14,   189,     0,     0,     0,     0,     0,     0,     0,     0,
     190,     0,     0,     0,     0,     0,   904,     0,     0,    17,
      18,     0,     0,     0,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,    70,   236,   237,   238,   239,
     240,   241,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
       0,     0,    96,    97,    98,    99,   100,   101,     0,     0,
       0,     0,     0,   105,   106,   107,   108,   109,   110,   111,
     112,   113,   114,   115,   116,   117,   118,   119,   120,   121,
     122,   123,   124,   125,   126,   127,   128,   129,   130,   131,
     132,   133,   134,   135,   136,   137,   138,   139,   140,   141,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   156,   157,   158,   159,   160,   161,
     162,   163,   164,   165,   166,   167,     0,   169,     0,   171,
     172,   173,   174,   175,   176,   177,     0,     2,     3,     4,
       5,     6,     7,     8,   225,    10,    11,   242,    12,     0,
     183,   184,     0,     0,     0,   188,    14,   189,     0,     0,
       0,     0,     0,     0,     0,     0,   190,     0,     0,     0,
       0,     0,   907,     0,     0,    17,    18,     0,     0,     0,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    56,    57,    58,
      59,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,    70,   236,   237,   238,   239,   240,   241,    77,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    87,    88,
      89,    90,    91,    92,    93,    94,     0,     0,    96,    97,
      98,    99,   100,   101,     0,     0,     0,     0,     0,   105,
     106,   107,   108,   109,   110,   111,   112,   113,   114,   115,
     116,   117,   118,   119,   120,   121,   122,   123,   124,   125,
     126,   127,   128,   129,   130,   131,   132,   133,   134,   135,
     136,   137,   138,   139,   140,   141,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     156,   157,   158,   159,   160,   161,   162,   163,   164,   165,
     166,   167,     0,   169,     0,   171,   172,   173,   174,   175,
     176,   177,     0,     2,     3,     4,     5,     6,     7,     8,
     225,    10,    11,   242,    12,     0,   183,   184,     0,     0,
       0,   188,    14,   189,     0,     0,     0,     0,     0,     0,
       0,     0,   190,     0,     0,     0,     0,     0,   914,     0,
       0,    17,    18,     0,     0,     0,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    59,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,    70,   236,   237,
     238,   239,   240,   241,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    88,    89,    90,    91,    92,
      93,    94,     0,     0,    96,    97,    98,    99,   100,   101,
       0,     0,     0,     0,     0,   105,   106,   107,   108,   109,
     110,   111,   112,   113,   114,   115,   116,   117,   118,   119,
     120,   121,   122,   123,   124,   125,   126,   127,   128,   129,
     130,   131,   132,   133,   134,   135,   136,   137,   138,   139,
     140,   141,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   156,   157,   158,   159,
     160,   161,   162,   163,   164,   165,   166,   167,     0,   169,
       0,   171,   172,   173,   174,   175,   176,   177,     0,     2,
       3,     4,     5,     6,     7,     8,   225,    10,    11,   242,
      12,     0,   183,   184,     0,     0,     0,   188,    14,   189,
       0,     0,     0,     0,     0,     0,     0,     0,   190,     0,
       0,     0,     0,     0,   912,     0,     0,     0,     0,     0,
       0,     0,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    59,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,    70,   236,   237,   238,   239,   240,   241,
      77,    78,    79,    80,    81,    82,    83,    84,    85,    86,
      87,    88,    89,    90,    91,    92,    93,    94,     0,     0,
      96,    97,    98,    99,   100,   101,     0,     0,     0,     0,
       0,   105,   106,   107,   108,   109,   110,   111,   112,   113,
     114,   115,   116,   117,   118,   119,   120,   121,   122,   123,
     124,   125,   126,   127,   128,   129,   130,   131,   132,   133,
     134,   135,   136,   137,   138,   139,   140,   141,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   156,   157,   158,   159,   160,   161,   162,   163,
     164,   165,   166,   167,     0,   169,     0,   171,   172,   173,
     174,   175,   176,   177,     0,     2,     3,     4,     5,     6,
       7,     8,   225,    10,    11,   242,    12,     0,   183,   184,
       0,     0,     0,   188,    14,   189,     0,     0,     0,     0,
       0,     0,     0,     0,   190,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    59,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,    70,
     236,   237,   238,   239,   240,   241,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    89,    90,
      91,    92,    93,    94,     0,     0,    96,    97,    98,    99,
     100,   101,     0,     0,     0,     0,     0,   105,   106,   107,
     108,   109,   110,   111,   112,   113,   114,   115,   116,   117,
     118,   119,   120,   121,   122,   123,   124,   125,   126,   127,
     128,   129,   130,   131,   132,   133,   134,   135,   136,   137,
     138,   139,   140,   141,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   156,   157,
     158,   159,   160,   161,   162,   163,   164,   165,   166,   167,
       0,   169,     0,   171,   172,   173,   174,   175,   176,   177,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   242,     0,     0,   183,   184,     0,     0,     0,   188,
       0,   189,     0,     0,     0,     0,     0,     0,     0,     0,
     190
};

static const yytype_int16 yycheck[] =
{
      11,    12,   222,    14,    16,   196,    13,   669,   665,    12,
      12,    17,    18,    18,    39,    40,    39,    40,    23,    39,
      40,  1258,    27,    39,    40,   884,   681,   682,   683,   684,
     685,    10,    37,    10,    10,    39,    40,     0,    39,    40,
      13,    21,    14,    14,    12,    10,    19,    16,    16,    13,
      19,    13,    19,    13,    21,    19,    13,    29,    29,    13,
     218,    13,   220,    35,    35,    13,    39,    40,    13,    48,
      13,    48,    48,    45,    45,    39,    40,    39,    40,    39,
      40,    13,    39,    40,    95,    39,    40,    39,    40,    13,
      12,    39,    40,    13,    39,    40,    39,    40,     0,    13,
    1337,    13,   218,    13,   220,    13,    12,    39,    40,    13,
      16,   218,    13,   220,    13,    39,    40,    12,    12,    39,
      40,    16,    17,    13,   240,    39,    40,    39,    40,    39,
      40,    39,    40,   240,    13,    39,    40,    13,    39,    40,
      39,    40,    13,    12,   364,   365,    13,    12,   368,    39,
      40,    13,    16,    13,   374,   375,    13,    16,    13,   379,
      39,    40,    13,    39,    40,    12,    19,   178,    39,    40,
      12,   182,    39,    40,    16,    17,   396,    39,    40,    39,
      40,   401,    39,    40,    39,    40,    39,    40,    39,    40,
     215,   216,    10,   216,    13,    13,   216,    12,    15,   211,
     216,     0,    19,  1062,    21,    41,    42,   212,   209,    15,
     214,    12,   223,   224,    12,   217,    19,   219,   880,    12,
      39,    40,    39,    40,   227,   228,   229,   230,   231,   232,
     233,   234,   235,    39,    40,   246,    39,    40,   893,   217,
     895,   219,    12,   254,   255,   256,   257,   258,   259,   260,
     261,   262,   263,   264,   265,   266,   267,   268,   269,   270,
     271,   272,   273,   274,   275,   276,   277,   278,   279,   280,
     281,   282,   283,   284,   285,   286,   287,   288,   289,   290,
     291,   292,   293,   294,   295,   218,   297,   220,   299,    12,
     301,    13,   303,  1152,   305,   197,   307,   308,    16,   310,
      12,   312,  1161,   314,    12,    19,   317,   240,   319,    12,
     321,    12,   323,    12,   325,    12,   327,    39,    40,    12,
     331,   332,   333,   334,   335,    39,    40,   338,   339,   340,
     341,   342,   343,   344,   345,   346,   347,   348,   349,   350,
     351,   352,   353,   354,   355,   356,   357,   358,   359,   360,
     361,   362,   363,   316,    12,   366,   367,    12,   369,   370,
     371,   372,   373,    16,    17,   376,   377,   378,   197,   380,
      13,   382,   383,   384,   385,   386,   387,   388,   389,   390,
     391,   392,   393,   394,   395,    12,   397,   398,   399,   400,
      19,   402,   403,    16,    17,    12,    39,    40,   197,    28,
    1062,   412,    31,   414,  1061,    13,   417,    13,    29,    13,
     421,    13,  1271,    13,   316,    61,    62,    63,    64,    65,
      66,    67,    68,    69,    13,    71,    72,    73,    74,    75,
      76,    39,    40,    39,    40,    39,    40,    39,    40,    39,
      40,    13,   218,    13,   220,    13,    21,    13,    10,    13,
      39,    40,    13,    16,    13,    12,   676,    13,     0,    13,
      20,    13,    43,    44,   240,    13,    12,    39,    40,    39,
      40,    39,    40,    39,    40,    39,    40,    13,    39,    40,
      39,    40,    13,    39,    40,    39,    40,    39,    40,  1151,
    1152,    39,    40,    13,    16,    13,    21,    13,    12,  1161,
      13,    16,    13,    39,    40,    13,    16,    13,    39,    40,
      13,    16,    13,    20,    13,    15,    13,   316,    13,    39,
      40,    39,    40,    39,    40,    13,    39,    40,    39,    40,
      13,    39,    40,    39,    40,    13,    39,    40,    39,    40,
      39,    40,    39,    40,    39,    40,    13,    21,    19,    13,
      12,    39,    40,    13,    34,    12,    39,    40,    12,    39,
      40,    39,    40,    39,    40,    39,    40,  1229,    39,    40,
      13,    12,    39,    40,  1236,    39,    40,    13,    12,    39,
      40,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,    39,    40,    13,   218,
      13,   220,    13,    39,    40,    13,    16,    13,    12,  1271,
      13,    16,    13,    13,    13,    13,    13,   220,    13,   123,
      13,   240,    13,    12,    39,    40,    39,    40,    39,    40,
      13,    39,    40,    39,    40,    15,    39,    40,    39,    40,
      39,    40,    39,    40,    39,    40,    39,    40,    39,    40,
      15,    10,    13,  1315,   212,   213,    39,    40,    12,    39,
      40,    12,   673,   674,    12,    31,    13,    12,   679,   680,
     677,   678,    13,    12,    39,    40,    12,   868,    39,    40,
     692,   693,    13,   694,   696,   697,   692,   693,    13,    16,
      13,   697,    39,    40,    13,    16,    13,    12,    39,    40,
     920,   712,   713,    13,    16,    13,    15,    13,    39,    40,
      13,    16,    13,    12,    39,    40,    39,    40,    13,    12,
      39,    40,    39,    40,    13,   218,    13,   220,    13,    39,
      40,    39,    40,    39,    40,    13,    39,    40,    39,    40,
      12,   218,    16,   220,    39,    40,   218,   240,   220,    19,
      39,    40,    39,    40,    39,    40,    19,    21,    19,    12,
      19,    39,    40,   240,    19,    12,   777,   669,   240,    39,
      40,    12,    12,    19,    12,    19,    39,    40,    39,    40,
      39,    40,    19,    12,    39,    40,    12,    19,    12,    19,
      10,    19,  1012,    39,    40,    39,    40,    19,    12,    12,
      12,    19,    39,    40,    19,    12,  1026,    39,    40,    39,
      40,    39,    40,    19,    12,    19,    12,    39,    40,    16,
    1040,    39,    40,    13,    39,    40,    19,    12,    19,    12,
      19,    12,    19,    39,    40,    39,    40,    19,    12,   668,
     669,    19,   853,   854,    19,    12,    39,    40,    39,    40,
      39,    40,    39,    40,    19,  1075,    19,    39,    40,    19,
      12,    39,    40,    19,    39,    40,    19,    12,    12,    12,
     669,    12,  1063,    12,    39,    40,    39,    40,    10,    39,
      40,    12,    12,    39,    40,    19,    39,    40,    12,   852,
      19,    12,   904,   905,    19,   907,   908,   860,  1089,    19,
     912,    19,   914,   915,    19,    39,    40,   918,   919,    19,
      39,    40,   923,    19,    39,    40,    19,    12,    19,    39,
      40,    39,    40,    19,    39,    40,    20,    12,    19,    39,
      40,    19,    12,    39,    40,    19,    39,    40,    39,    40,
      19,    12,  1162,    39,    40,    39,    40,  1167,    39,    40,
     852,    39,    40,    12,    12,    39,    40,  1177,   860,    12,
      39,    40,   973,    12,    12,   976,   977,    12,   979,   980,
      16,    12,    19,   984,   985,   986,   987,    19,   880,    19,
     991,   992,   993,   994,   995,   996,   997,   998,   999,  1000,
      12,  1211,    39,    40,    19,    12,    12,    39,    40,    39,
      40,    12,    12,    32,    33,    12,    12,    36,    12,  1020,
      12,  1022,    41,    42,    39,    40,  1027,  1028,  1029,  1030,
    1031,  1032,  1033,  1034,  1035,  1036,  1037,  1038,  1219,    19,
    1041,  1042,  1043,    21,  1045,  1046,    19,    10,    19,  1050,
      16,    12,    19,    12,    19,  1056,  1057,    19,  1059,    39,
      40,    39,    40,   852,   883,    19,    39,    40,    39,    40,
      21,   860,    39,    40,    39,    40,    19,    39,    40,    19,
      12,  1291,  1292,    19,    12,    39,    40,    12,    39,    40,
      19,   880,    12,    19,    10,    19,    39,    40,    19,    39,
      40,    19,    12,    39,    40,    19,    12,    19,  1109,  1110,
      39,    40,  1113,    39,    40,    39,    40,    20,    39,    40,
      21,    39,    40,    20,    12,    39,    40,    39,    40,    20,
      12,    20,    12,    20,    12,    20,    39,    40,    39,    40,
    1141,    20,    39,    40,    12,    12,    12,  1148,    39,    40,
      39,    40,    39,    40,    39,    40,  1366,  1158,  1368,  1160,
      39,    40,  1163,    20,  1165,  1166,    12,  1168,  1169,    21,
    1062,    20,    30,    12,    12,    12,    20,  1178,    20,  1180,
      20,  1182,    39,    40,  1185,  1186,  1139,  1140,    12,  1399,
      39,    40,  1193,    20,  1195,    39,    40,    39,    40,    39,
      40,    12,    21,    12,  1205,  1206,    13,  1208,    20,    12,
      20,    12,    39,    40,    13,    21,    12,    21,    12,    21,
    1221,    21,  1223,    21,    12,  1226,    21,    39,    40,    39,
      40,    21,  1233,    39,    40,    39,    40,    39,    40,    39,
      40,    39,    40,  1062,    39,    40,    21,  1139,  1140,    39,
      40,    12,    21,    10,    12,  1256,    12,    21,    12,  1151,
    1152,    12,    21,    10,    39,    40,    12,    12,    12,  1161,
      39,    40,    21,  1062,  1275,    39,    40,  1278,    12,  1280,
      39,    40,    15,    13,  1285,    13,  1287,    13,    13,    13,
      39,    40,    24,    25,    26,    13,    19,    19,  1299,    13,
    1301,  1302,  1303,    16,  1257,    13,    13,    39,    40,    19,
      19,  1312,   227,   228,   229,   230,   231,   232,   233,   234,
     235,    19,  1323,    12,   237,    31,    27,  1328,    15,    10,
      27,  1150,  1151,  1152,    27,   210,    28,  1229,    13,    19,
      13,    15,  1161,    13,  1236,    13,    13,  1348,    13,  1350,
    1139,  1140,   228,   229,   230,   231,   232,   233,   234,   235,
      19,    13,  1151,  1152,    13,  1257,  1367,    13,  1369,    13,
      13,    13,  1161,    13,    13,  1376,   236,    13,    42,  1271,
      27,    19,    13,  1336,    13,   228,   229,   230,   231,   232,
     233,   234,   686,   687,   688,   689,   690,    13,    13,    13,
      13,   859,   420,   973,    95,  1346,  1225,  1337,    -1,  1228,
    1229,    -1,    -1,    -1,    -1,    -1,  1235,  1236,    -1,    -1,
      -1,    -1,    -1,  1315,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1229,    -1,    -1,    -1,  1336,    -1,    -1,  1236,    -1,    -1,
      -1,    -1,  1271,  1272,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1282,    -1,    -1,    -1,    -1,  1257,    -1,
    1289,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1271,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1314,  1315,    -1,  1317,  1318,
      -1,  1320,    -1,    -1,    -1,    -1,  1325,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1315,    -1,    -1,    -1,
      -1,    -1,    -1,  1352,    -1,    -1,  1355,    -1,  1357,  1358,
      -1,    -1,  1361,  1362,    -1,    -1,    -1,  1336,    -1,    -1,
      -1,    -1,    -1,    -1,  1373,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1381,    -1,    -1,  1384,    -1,    -1,    -1,    -1,
      -1,    -1,  1391,  1392,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,     1,  1402,     3,     4,     5,     6,     7,     8,
       9,    10,    11,    12,    -1,    14,    -1,    -1,    -1,    -1,
      -1,    20,    -1,    22,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    30,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    38,
      -1,    -1,    41,    42,    -1,    -1,    -1,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    68,
      69,    70,    71,    72,    73,    74,    75,    76,    77,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    87,    88,
      89,    90,    91,    92,    93,    94,    95,    96,    97,    98,
      99,   100,   101,   102,   103,   104,   105,   106,   107,   108,
     109,   110,   111,   112,   113,   114,   115,   116,   117,   118,
     119,   120,   121,   122,    -1,   124,   125,   126,   127,   128,
     129,   130,   131,   132,    -1,    -1,   135,   136,   137,   138,
     139,   140,   141,   142,   143,   144,   145,   146,   147,   148,
     149,   150,   151,   152,   153,   154,   155,   156,   157,   158,
     159,   160,   161,   162,   163,   164,   165,   166,   167,   168,
     169,   170,   171,   172,   173,   174,   175,   176,   177,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,   190,   191,   192,   193,   194,   195,   196,   197,   198,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
      -1,    -1,   211,    -1,    -1,    -1,    -1,    -1,   217,    -1,
     219,    -1,   221,   222,   223,   224,   225,   226,   227,    -1,
     229,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   238,
     239,    -1,   241,   242,   243,     3,    -1,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    -1,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      68,    69,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    90,    91,    92,    93,    94,    95,    96,    97,
      98,    99,   100,   101,   102,   103,   104,   105,   106,   107,
     108,   109,   110,   111,   112,   113,   114,   115,   116,   117,
     118,   119,   120,   121,   122,   123,   124,   125,   126,   127,
     128,   129,   130,   131,   132,   133,   134,   135,   136,   137,
     138,   139,   140,   141,   142,   143,   144,   145,   146,   147,
     148,   149,   150,   151,   152,   153,   154,   155,   156,   157,
     158,   159,   160,   161,   162,   163,   164,   165,   166,   167,
     168,   169,   170,   171,   172,   173,   174,   175,   176,   177,
     178,   179,   180,   181,   182,   183,   184,   185,   186,   187,
     188,   189,   190,   191,   192,   193,   194,   195,   196,   197,
     198,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,     3,     4,     5,     6,
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
     127,   128,   129,   130,   131,   132,    -1,    -1,   135,   136,
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
     128,   129,   130,   131,   132,    -1,    -1,   135,   136,   137,
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
     129,   130,   131,   132,    -1,    -1,   135,   136,   137,   138,
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
     130,   131,   132,    -1,    -1,   135,   136,   137,   138,   139,
     140,   141,   142,   143,   144,   145,   146,   147,   148,   149,
     150,   151,   152,   153,   154,   155,   156,   157,   158,   159,
     160,   161,   162,   163,   164,   165,   166,   167,   168,   169,
     170,   171,   172,   173,   174,   175,   176,   177,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   187,   188,   189,
     190,   191,   192,   193,   194,   195,   196,   197,   198,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   208,    -1,
      -1,   211,    -1,    -1,    -1,    -1,    -1,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,    -1,   229,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   237,   238,   239,
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
     121,   122,    -1,   124,   125,   126,   127,   128,   129,   130,
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
      -1,    -1,    -1,    -1,    -1,    -1,   237,   238,   239,    -1,
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
     122,    -1,   124,   125,   126,   127,   128,   129,   130,   131,
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
      -1,   124,   125,   126,   127,   128,   129,   130,   131,   132,
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
     124,   125,   126,   127,   128,   129,   130,   131,   132,    -1,
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
      -1,    -1,    -1,    -1,   238,   239,   240,   241,     3,     4,
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
     125,   126,   127,   128,   129,   130,   131,   132,    -1,    -1,
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
      -1,    -1,    -1,   238,   239,   240,   241,     3,     4,     5,
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
     126,   127,   128,   129,   130,   131,   132,    -1,    -1,   135,
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
      -1,    -1,   238,   239,    -1,   241,     3,     4,     5,     6,
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
     127,   128,   129,   130,   131,   132,    -1,    -1,   135,   136,
     137,   138,   139,   140,   141,   142,   143,   144,   145,   146,
     147,   148,   149,   150,   151,   152,   153,   154,   155,   156,
     157,   158,   159,   160,   161,   162,   163,   164,   165,   166,
     167,   168,   169,   170,   171,   172,   173,   174,   175,   176,
     177,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,   190,   191,   192,   193,   194,   195,   196,
     197,   198,   199,   200,   201,   202,   203,   204,   205,   206,
     207,   208,    -1,    -1,   211,    -1,    -1,    -1,    -1,    -1,
     217,    -1,   219,    -1,   221,   222,   223,   224,   225,   226,
     227,    -1,   229,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   238,   239,    -1,   241,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    -1,    14,    -1,    -1,    -1,
      -1,    -1,    20,    -1,    22,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    31,    -1,    -1,    -1,    -1,    -1,    -1,
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
      -1,   199,    -1,   201,   202,   203,   204,   205,   206,   207,
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
     192,   193,   194,   195,   196,   197,    -1,   199,    -1,   201,
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
     196,   197,    -1,   199,    -1,   201,   202,   203,   204,   205,
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
      -1,   201,   202,   203,   204,   205,   206,   207,    -1,     3,
       4,     5,     6,     7,     8,     9,    10,    11,    12,   219,
      14,    -1,   222,   223,    -1,    -1,    20,   227,    22,   229,
      -1,    -1,    -1,    -1,    -1,    -1,    30,    -1,   238,    -1,
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
     194,   195,   196,   197,    -1,   199,    -1,   201,   202,   203,
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
      -1,   199,    -1,   201,   202,   203,   204,   205,   206,   207,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   219,    -1,    -1,   222,   223,    -1,    -1,    -1,   227,
      -1,   229,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     238,     3,     4,     5,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    -1,    -1,    -1,    -1,    -1,    20,    -1,
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
     122,    -1,   124,   125,   126,   127,   128,   129,    -1,    -1,
      -1,    -1,    -1,   135,   136,   137,   138,   139,   140,   141,
     142,   143,   144,   145,   146,   147,   148,   149,   150,   151,
     152,   153,   154,   155,   156,   157,   158,   159,   160,   161,
     162,   163,   164,   165,   166,   167,   168,   169,   170,   171,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   186,   187,   188,   189,   190,   191,
     192,   193,   194,   195,   196,   197,    -1,   199,    -1,   201,
     202,   203,   204,   205,   206,   207,    -1,     3,     4,     5,
       6,     7,     8,     9,    10,    11,    12,   219,    14,    -1,
     222,   223,    -1,    -1,    20,   227,    22,   229,    -1,    -1,
      -1,    -1,    28,    -1,    -1,    -1,   238,    -1,    -1,    -1,
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
     196,   197,    -1,   199,    -1,   201,   202,   203,   204,   205,
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
      -1,   201,   202,   203,   204,   205,   206,   207,    -1,     3,
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
     194,   195,   196,   197,    -1,   199,    -1,   201,   202,   203,
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
      -1,   199,    -1,   201,   202,   203,   204,   205,   206,   207,
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
     192,   193,   194,   195,   196,   197,    -1,   199,    -1,   201,
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
     196,   197,    -1,   199,    -1,   201,   202,   203,   204,   205,
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
      -1,   201,   202,   203,   204,   205,   206,   207,    -1,    -1,
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
     194,   195,   196,   197,    -1,   199,    -1,   201,   202,   203,
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
      -1,   199,    -1,   201,   202,   203,   204,   205,   206,   207,
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
     192,   193,   194,   195,   196,   197,    -1,   199,    -1,   201,
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
     196,   197,    -1,   199,    -1,   201,   202,   203,   204,   205,
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
      -1,   201,   202,   203,   204,   205,   206,   207,    -1,     3,
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
     194,   195,   196,   197,    -1,   199,    -1,   201,   202,   203,
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
      -1,   199,    -1,   201,   202,   203,   204,   205,   206,   207,
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
      11,    12,    14,    20,    22,    30,    38,    41,    42,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,    68,    69,    70,    71,    72,    73,    74,    75,    76,
      77,    78,    79,    80,    81,    82,    83,    84,    85,    86,
      87,    88,    89,    90,    91,    92,    93,    94,    95,    96,
      97,    98,    99,   100,   101,   102,   103,   104,   105,   106,
     107,   108,   109,   110,   111,   112,   113,   114,   115,   116,
     117,   118,   119,   120,   121,   122,   124,   125,   126,   127,
     128,   129,   130,   131,   132,   135,   136,   137,   138,   139,
     140,   141,   142,   143,   144,   145,   146,   147,   148,   149,
     150,   151,   152,   153,   154,   155,   156,   157,   158,   159,
     160,   161,   162,   163,   164,   165,   166,   167,   168,   169,
     170,   171,   172,   173,   174,   175,   176,   177,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   187,   188,   189,
     190,   191,   192,   193,   194,   195,   196,   197,   198,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   211,
     217,   219,   221,   222,   223,   224,   225,   226,   227,   229,
     238,   239,   241,   242,   243,   245,   246,   247,   249,   257,
     258,   259,   260,   261,   262,   263,   267,   268,   269,   270,
     271,   272,   273,   274,   275,   278,   279,   281,   282,   283,
     285,    21,    12,    16,    17,    10,    87,    88,    89,    90,
      91,    92,    93,    94,    95,    96,    98,    99,   100,   101,
     102,   103,   219,   267,   269,   275,    31,    40,   267,   270,
     267,   274,   272,   272,    12,    12,    12,    12,    12,    12,
      12,    12,    12,    12,    12,    12,    12,    12,    12,    12,
      12,    12,    12,    12,    12,    12,    12,    12,    12,    12,
      12,    12,    12,    12,    12,    12,    12,    12,    12,    12,
      12,    12,    12,    12,    12,    16,   284,    16,   284,    16,
     284,    16,   284,    16,   284,    16,   284,    12,    16,   284,
      16,   284,    16,   284,    16,   284,    12,    16,   284,    16,
     284,    16,   284,    16,   284,    16,   284,    16,   284,   267,
     268,    12,    12,    12,    12,    12,    12,    12,    12,    12,
      12,    12,    12,    12,    12,    12,    12,    12,    12,    12,
      12,    12,    12,    12,    12,    12,    12,    12,    12,    12,
      12,    12,    12,    12,    12,    12,    12,    12,    12,    12,
      12,    12,    12,    12,    12,    12,    12,    12,    12,    12,
      12,    12,    12,    12,    12,    12,    12,    12,    12,    12,
      12,    12,    12,    12,    12,    12,    12,    12,    12,    12,
      12,    12,    12,    12,   250,   267,    10,   251,    29,   264,
     266,   267,    12,    12,    12,    12,    12,    12,    12,   256,
      10,    12,    21,     0,     3,     5,     6,     7,     8,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    68,    69,    70,
      71,    72,    73,    74,    75,    76,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    89,    90,
      91,    92,    93,    94,    95,    96,    97,    98,    99,   100,
     101,   102,   103,   104,   105,   106,   107,   108,   109,   110,
     111,   112,   113,   114,   115,   116,   117,   118,   119,   120,
     121,   122,   123,   124,   125,   126,   127,   128,   129,   130,
     131,   132,   133,   134,   135,   136,   137,   138,   139,   140,
     141,   142,   143,   144,   145,   146,   147,   148,   149,   150,
     151,   152,   153,   154,   155,   156,   157,   158,   159,   160,
     161,   162,   163,   164,   165,   166,   167,   168,   169,   170,
     171,   172,   173,   174,   175,   176,   177,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,   190,
     191,   192,   193,   194,   195,   196,   197,   198,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   247,   248,   290,   237,   248,   249,   252,   253,
     254,    21,    20,    16,    17,    20,    19,    39,    40,    16,
      17,    18,    23,    27,    37,   212,    32,    33,    36,    41,
      42,   274,    43,    44,    14,    29,    35,    45,    13,   263,
     133,   134,   267,   267,    16,    13,    29,    31,   267,   280,
      15,    15,    19,    21,    24,    25,    26,   267,   267,   267,
     267,   267,   267,   267,   267,   267,   267,   267,   267,   267,
     267,   267,   267,   267,   267,   267,   267,   267,   267,   267,
     267,   267,   267,   267,   267,   267,   267,   267,   267,   267,
     267,   267,   267,   267,   267,   267,   267,   267,    30,   267,
     267,   267,   267,   267,   267,   267,   267,   267,   267,   267,
     249,   267,   267,   267,   267,   267,   267,   123,   267,   267,
     267,   267,   267,    13,    13,   267,   267,   267,   267,   267,
     267,   267,   267,   267,   267,   267,   267,   267,   267,   267,
     267,   267,   267,   267,   267,   267,   267,   267,   267,   267,
     267,   263,   263,   267,   267,   263,   267,   267,   267,   267,
     267,   263,   263,   267,   267,   267,   263,   267,    10,    48,
     267,   267,   267,   267,   267,   267,   267,   267,   267,   267,
     267,   267,   267,   267,   263,   267,   267,   267,   267,   263,
     267,   267,   209,   212,   213,    10,   220,    19,    21,   265,
     216,   267,    10,   267,    10,    10,   267,    10,    13,   255,
     256,    13,   267,    31,    16,    16,    15,    21,    10,   255,
      21,   248,   248,   252,    21,   267,   267,   263,   270,   270,
     267,   267,   271,    16,   271,    16,   271,   271,   271,   273,
     273,   273,   273,   273,    38,   272,   274,    38,   272,   274,
     267,    10,    38,   274,    38,   272,   274,    13,    12,    12,
      12,    10,    15,    19,    28,    31,   267,   267,    13,    13,
      13,    13,    13,    13,    13,    13,    13,    13,    13,    13,
      13,    13,    13,    13,    13,    13,    13,    13,    13,    13,
      13,    13,    13,    13,    13,    13,    13,    13,    13,    13,
      13,    13,    13,    13,    13,    13,    13,    13,    13,    13,
      13,   267,   276,   277,    13,    13,    19,    19,    13,    19,
      19,    13,    13,    13,    19,    19,    19,    19,    13,    13,
      13,    19,    19,    19,    19,    19,    19,    19,    19,    19,
      19,    13,    13,    13,    13,    13,    13,    13,    13,    13,
      13,    13,    19,    13,    13,    13,    13,    13,    13,    13,
      19,    13,    19,    19,    19,    19,    19,    19,    19,    19,
      19,    19,    19,    19,    19,    19,    19,    19,    19,    13,
      19,    19,    19,    19,    13,    19,    19,   249,   267,   267,
      16,   264,   249,    13,    13,    13,    19,    19,    13,    19,
      16,    19,   247,    13,    13,   252,   248,   253,   271,   271,
     274,   274,   274,   274,    15,    12,   274,   274,   274,   267,
     267,    13,   263,    28,   267,    31,    15,    15,    15,    34,
     276,   267,   267,   267,   267,   267,   267,   267,   267,   267,
     267,   267,   267,   267,   267,   267,   267,   267,   267,    27,
      27,   263,   267,    27,   267,    10,    48,    10,    48,    10,
     263,   267,   267,   267,   267,   267,   267,   267,   267,   267,
     267,   267,   267,   263,   267,   267,   267,   267,   267,   210,
     216,   214,   267,   267,   267,   267,    28,   255,   240,   248,
     252,   253,   247,    13,   263,    13,    13,    13,    19,    15,
      12,   247,    19,    19,    13,    19,    19,    19,    19,    19,
      13,    13,    13,    13,    13,    13,    13,    19,    19,    13,
      27,   267,    27,   267,    13,    19,    27,   267,    13,    13,
      13,    13,    13,    19,    13,    19,    13,    13,    13,    13,
      13,    13,    13,    13,    13,    19,    19,    13,    19,    13,
      13,    19,    13,   249,   249,   267,    19,    13,    13,    13,
     267,   240,   248,   240,   248,   252,   240,   248,   252,   253,
      13,   267,   267,   240,   248,   252,   253,   263,   267,   267,
     267,   263,   267,   267,   263,   267,   267,   267,   267,   267,
     267,   267,   267,   267,   267,   263,   215,   216,    12,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   286,   287,
     289,   247,    21,   267,   267,   240,   248,   267,   240,   248,
     240,   248,   252,    13,   267,   240,   248,   240,   248,   252,
      13,    19,    19,    13,    13,    13,    13,    13,    13,    19,
      13,    19,    19,    19,    13,    13,   267,   249,   286,   288,
     236,    42,   240,   248,   252,   253,   248,    21,    21,   267,
      21,   267,   267,   240,   248,    21,   267,   267,   240,   248,
     263,   263,   267,   267,   267,   267,   216,    19,    13,   228,
     229,   230,   231,   232,   233,   234,    27,   267,   240,   248,
     240,   248,   252,   248,   248,    21,   248,    21,    21,   267,
     248,    21,    21,   267,    13,    13,    19,    19,    19,    19,
     249,   288,   287,    21,   267,   267,   240,   248,   248,   248,
     248,    21,   248,   248,    21,   263,   267,   263,   267,    13,
     248,    21,    21,   267,   248,   248,    13,    13,    13,    19,
     248,   248,    21,   263,   248,    13
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int16 yyr1[] =
{
       0,   244,   245,   245,   245,   245,   245,   245,   246,   247,
     247,   248,   248,   249,   249,   249,   249,   249,   249,   249,
     249,   250,   250,   251,   251,   251,   252,   252,   253,   253,
     254,   255,   255,   256,   256,   256,   256,   256,   256,   256,
     256,   256,   256,   256,   256,   256,   256,   256,   256,   256,
     256,   256,   256,   256,   256,   256,   256,   257,   257,   257,
     257,   257,   257,   257,   257,   257,   257,   257,   257,   257,
     257,   257,   257,   257,   257,   257,   257,   257,   257,   257,
     257,   257,   257,   257,   257,   257,   257,   257,   257,   257,
     257,   257,   257,   257,   258,   258,   258,   258,   259,   259,
     259,   259,   259,   259,   259,   259,   260,   261,   261,   261,
     261,   261,   261,   261,   261,   261,   261,   261,   261,   261,
     261,   261,   261,   262,   262,   262,   262,   262,   262,   262,
     262,   262,   262,   262,   262,   262,   262,   262,   262,   263,
     263,   264,   264,   265,   265,   266,   267,   267,   268,   268,
     268,   268,   269,   270,   270,   270,   270,   270,   270,   270,
     270,   271,   271,   271,   271,   271,   271,   272,   272,   272,
     272,   273,   273,   273,   273,   273,   273,   273,   273,   273,
     274,   274,   274,   274,   274,   274,   275,   275,   275,   275,
     275,   275,   275,   275,   275,   275,   275,   275,   275,   275,
     275,   275,   275,   275,   275,   275,   275,   275,   275,   275,
     275,   275,   275,   275,   275,   275,   275,   275,   275,   275,
     275,   275,   275,   275,   275,   275,   275,   275,   275,   275,
     275,   275,   275,   275,   275,   275,   275,   275,   275,   275,
     276,   276,   277,   277,   277,   277,   277,   277,   277,   277,
     277,   278,   278,   278,   278,   278,   278,   278,   279,   279,
     279,   279,   280,   280,   280,   281,   281,   281,   282,   282,
     282,   282,   282,   282,   283,   283,   283,   283,   283,   283,
     283,   283,   283,   283,   283,   283,   283,   283,   283,   283,
     283,   283,   283,   283,   283,   283,   283,   283,   283,   283,
     283,   283,   283,   283,   283,   283,   283,   283,   283,   283,
     283,   283,   283,   283,   283,   283,   283,   283,   283,   283,
     283,   283,   283,   283,   283,   283,   283,   283,   283,   283,
     283,   283,   283,   283,   283,   283,   283,   283,   283,   283,
     283,   283,   283,   283,   283,   283,   283,   283,   283,   283,
     283,   283,   283,   283,   283,   283,   283,   283,   283,   283,
     283,   283,   283,   283,   283,   283,   283,   283,   283,   283,
     283,   283,   283,   283,   284,   284,   285,   285,   285,   285,
     285,   285,   285,   285,   285,   285,   285,   285,   285,   285,
     285,   285,   286,   286,   286,   286,   286,   286,   286,   286,
     286,   286,   286,   286,   286,   286,   287,   287,   288,   288,
     289,   289,   290,   290,   290,   290,   290,   290,   290,   290,
     290,   290,   290,   290,   290,   290,   290,   290,   290,   290,
     290,   290,   290,   290,   290,   290,   290,   290,   290,   290,
     290,   290,   290,   290,   290,   290,   290,   290,   290,   290,
     290,   290,   290,   290,   290,   290,   290,   290,   290,   290,
     290,   290,   290,   290,   290,   290,   290,   290,   290,   290,
     290,   290,   290,   290,   290,   290,   290,   290,   290,   290,
     290,   290,   290,   290,   290,   290,   290,   290,   290,   290,
     290,   290,   290,   290,   290,   290,   290,   290,   290,   290,
     290,   290,   290,   290,   290,   290,   290,   290,   290,   290,
     290,   290,   290,   290,   290,   290,   290,   290,   290,   290,
     290,   290,   290,   290,   290,   290,   290,   290,   290,   290,
     290,   290,   290,   290,   290,   290,   290,   290,   290,   290,
     290,   290,   290,   290,   290,   290,   290,   290,   290,   290,
     290,   290,   290,   290,   290,   290,   290,   290,   290,   290,
     290,   290,   290,   290,   290,   290,   290,   290,   290,   290,
     290,   290,   290,   290,   290,   290,   290,   290,   290,   290,
     290,   290,   290,   290,   290,   290,   290,   290,   290,   290,
     290,   290,   290,   290,   290,   290,   290,   290,   290,   290,
     290,   290,   290,   290,   290,   290,   290,   290,   290,   290,
     290,   290,   290,   290,   290,   290,   290,   290,   290,   290,
     290,   290,   290,   290,   290,   290,   290,   290,   290,   290,
     290,   290,   290,   290,   290,   290,   290,   290,   290,   290,
     290,   290,   290,   290,   290,   290,   290,   290,   290,   290,
     290,   290
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     2,     2,     1,     3,     2,     2,     1,     1,
       1,     1,     1,     1,     3,     4,     3,     2,     2,     4,
       2,     3,     5,     7,     9,     5,     2,     3,     2,     3,
       2,     1,     3,     5,     6,     5,     4,     8,     9,     8,
       7,     6,     7,     6,     5,     9,    10,     9,     8,     8,
       9,     8,     7,    11,    12,    11,    10,     1,     1,     1,
       4,     3,     1,     4,     6,     7,     6,     4,     4,     4,
       4,     4,     4,     4,     4,    12,     4,     6,     7,     6,
       4,     4,     6,     7,    12,     6,     6,     6,     6,    11,
       6,     1,     1,     3,     1,     2,     1,     2,     3,     3,
       6,     6,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     1,
       3,     1,     3,     1,     1,     4,     1,     4,     1,     3,
       3,     2,     4,     1,     3,     3,     3,     3,     4,     4,
       3,     1,     3,     3,     3,     3,     3,     1,     1,     2,
       2,     1,     2,     2,     3,     3,     4,     4,     4,     4,
       1,     3,     4,     4,     3,     4,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     4,     4,     3,     1,     1,     1,     1,     3,
       3,     1,     1,     3,     5,     6,     6,     5,     2,     4,
       1,     2,     9,     6,     8,     5,     8,     5,     7,     4,
       5,     1,     1,     1,     1,     1,     1,     1,     4,     3,
       5,     6,     1,     3,     5,     5,     5,     3,     3,     3,
       3,     4,     4,     4,     4,     4,     4,     3,     3,     6,
       8,    10,     8,     4,     4,    10,     4,     4,     4,     4,
       8,     8,     8,     8,     4,     4,     4,     6,     6,     6,
       6,     6,     6,     6,     8,     8,     6,     4,     4,     6,
      12,     6,     6,     6,     6,     6,     6,     6,     6,     6,
      14,     6,     8,     6,     6,     4,     8,     6,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     6,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     2,     0,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     1,     1,     1,     1,     1,     1,     1,     3,
       3,     3,     3,     3,     3,     3,     1,     1,     1,     3,
       1,     3,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     2,     2,     1,     1,     1,     1,
       1,     1,     1,     2,     1,     1,     2,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1
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
        yyerror (scanner, YY_("syntax error: cannot back up")); \
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
                  Kind, Value, scanner); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep, void* scanner)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  YY_USE (scanner);
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
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep, void* scanner)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep, scanner);
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
                 int yyrule, void* scanner)
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
                       &yyvsp[(yyi + 1) - (yynrhs)], scanner);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule, scanner); \
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
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep, void* scanner)
{
  YY_USE (yyvaluep);
  YY_USE (scanner);
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
yyparse (void* scanner)
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
      yychar = yylex (&yylval, scanner);
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
  case 2: /* startsymbol: command ";"  */
#line 476 "parser.y"
                          {
			    parsedThing = (yyvsp[-1].tree);
			    (yyval.other) = NULL;
			    YYACCEPT;
			  }
#line 4509 "parser.c"
    break;

  case 3: /* startsymbol: helpmeta ";"  */
#line 482 "parser.y"
                          {
			    outputMode();
                            sollyaPrintf("This is %s.\nType 'help help;' for the list of available commands. Type 'help <command>;' for help on the specific command <command>.\nType 'quit;' for quitting the %s interpreter.\n\nYou can get moral support and help with bugs by writing to %s.\n\n",PACKAGE_NAME,PACKAGE_NAME,PACKAGE_BUGREPORT);
			    parsedThing = NULL;
			    (yyval.other) = NULL;
			    YYACCEPT;
			  }
#line 4521 "parser.c"
    break;

  case 4: /* startsymbol: "?"  */
#line 490 "parser.y"
                          {
			    outputMode();
                            sollyaPrintf("This is %s.\nType 'help help;' for the list of available commands. Type 'help <command>;' for help on the specific command <command>.\nType 'quit;' for quitting the %s interpreter.\n\nYou can get moral support and help with bugs by writing to %s.\n\n",PACKAGE_NAME,PACKAGE_NAME,PACKAGE_BUGREPORT);
			    parsedThing = NULL;
			    (yyval.other) = NULL;
			    YYACCEPT;
			  }
#line 4533 "parser.c"
    break;

  case 5: /* startsymbol: helpmeta help ";"  */
#line 498 "parser.y"
                          {
			    parsedThing = NULL;
			    (yyval.other) = NULL;
			    YYACCEPT;
			  }
#line 4543 "parser.c"
    break;

  case 6: /* startsymbol: "version" ";"  */
#line 504 "parser.y"
                          {
			    outputMode();
			    sollyaPrintf("This is\n\n\t%s.\n\n"	VERSION_COPYRIGHT_TEXT "\nSend bug reports to <%s>\n\nThis build of %s is based on GMP %s, MPFR %s and MPFI %s.\n",PACKAGE_STRING,PACKAGE_BUGREPORT,PACKAGE_STRING,gmp_version,mpfr_get_version(),sollya_mpfi_get_version());
#if defined(HAVE_FPLLL_VERSION_STRING)
			    sollyaPrintf("It uses FPLLL as: \"%s\"\n",HAVE_FPLLL_VERSION_STRING);
#endif
			    sollyaPrintf("\n");
			    parsedThing = NULL;
			    (yyval.other) = NULL;
			    YYACCEPT;
			  }
#line 4559 "parser.c"
    break;

  case 7: /* startsymbol: error ";"  */
#line 516 "parser.y"
                          {
			    parsedThing = NULL;
			    (yyval.other) = NULL;
			    YYACCEPT;
			  }
#line 4569 "parser.c"
    break;

  case 8: /* helpmeta: "help"  */
#line 524 "parser.y"
                          {
			    helpNotFinished = 1;
			    (yyval.other) = NULL;
			  }
#line 4578 "parser.c"
    break;

  case 9: /* beginsymbol: "begin"  */
#line 531 "parser.y"
                          {
			    (yyval.other) = NULL;
			  }
#line 4586 "parser.c"
    break;

  case 10: /* beginsymbol: "{"  */
#line 535 "parser.y"
                          {
			    (yyval.other) = NULL;
			  }
#line 4594 "parser.c"
    break;

  case 11: /* endsymbol: "end"  */
#line 541 "parser.y"
                          {
			    (yyval.other) = NULL;
			  }
#line 4602 "parser.c"
    break;

  case 12: /* endsymbol: "}"  */
#line 545 "parser.y"
                          {
			    (yyval.other) = NULL;
			  }
#line 4610 "parser.c"
    break;

  case 13: /* command: simplecommand  */
#line 551 "parser.y"
                          {
			    (yyval.tree) = (yyvsp[0].tree);
			  }
#line 4618 "parser.c"
    break;

  case 14: /* command: beginsymbol commandlist endsymbol  */
#line 555 "parser.y"
                          {
			    (yyval.tree) = makeCommandList((yyvsp[-1].list));
                          }
#line 4626 "parser.c"
    break;

  case 15: /* command: beginsymbol variabledeclarationlist commandlist endsymbol  */
#line 559 "parser.y"
                          {
			    (yyval.tree) = makeCommandList(concatChains((yyvsp[-2].list), (yyvsp[-1].list)));
                          }
#line 4634 "parser.c"
    break;

  case 16: /* command: beginsymbol variabledeclarationlist endsymbol  */
#line 563 "parser.y"
                          {
			    (yyval.tree) = makeCommandList((yyvsp[-1].list));
                          }
#line 4642 "parser.c"
    break;

  case 17: /* command: beginsymbol endsymbol  */
#line 567 "parser.y"
                          {
			    (yyval.tree) = makeNop();
                          }
#line 4650 "parser.c"
    break;

  case 18: /* command: "if" ifcommand  */
#line 571 "parser.y"
                          {
			    (yyval.tree) = (yyvsp[0].tree);
			  }
#line 4658 "parser.c"
    break;

  case 19: /* command: "while" thing "do" command  */
#line 575 "parser.y"
                          {
			    (yyval.tree) = makeWhile((yyvsp[-2].tree), (yyvsp[0].tree));
			  }
#line 4666 "parser.c"
    break;

  case 20: /* command: "for" forcommand  */
#line 579 "parser.y"
                          {
			    (yyval.tree) = (yyvsp[0].tree);
			  }
#line 4674 "parser.c"
    break;

  case 21: /* ifcommand: thing "then" command  */
#line 585 "parser.y"
                          {
			    (yyval.tree) = makeIf((yyvsp[-2].tree), (yyvsp[0].tree));
                          }
#line 4682 "parser.c"
    break;

  case 22: /* ifcommand: thing "then" command "else" command  */
#line 589 "parser.y"
                          {
			    (yyval.tree) = makeIfElse((yyvsp[-4].tree),(yyvsp[-2].tree),(yyvsp[0].tree));
                          }
#line 4690 "parser.c"
    break;

  case 23: /* forcommand: "identifier" "from" thing "to" thing "do" command  */
#line 597 "parser.y"
                          {
			    (yyval.tree) = makeFor((yyvsp[-6].value), (yyvsp[-4].tree), (yyvsp[-2].tree), makeConstantDouble(1.0), (yyvsp[0].tree));
			    safeFree((yyvsp[-6].value));
                          }
#line 4699 "parser.c"
    break;

  case 24: /* forcommand: "identifier" "from" thing "to" thing "by" thing "do" command  */
#line 602 "parser.y"
                          {
			    (yyval.tree) = makeFor((yyvsp[-8].value), (yyvsp[-6].tree), (yyvsp[-4].tree), (yyvsp[-2].tree), (yyvsp[0].tree));
			    safeFree((yyvsp[-8].value));
                          }
#line 4708 "parser.c"
    break;

  case 25: /* forcommand: "identifier" "in" thing "do" command  */
#line 607 "parser.y"
                          {
			    (yyval.tree) = makeForIn((yyvsp[-4].value), (yyvsp[-2].tree), (yyvsp[0].tree));
			    safeFree((yyvsp[-4].value));
                          }
#line 4717 "parser.c"
    break;

  case 26: /* commandlist: command ";"  */
#line 615 "parser.y"
                          {
			    (yyval.list) = addElement(NULL, (yyvsp[-1].tree));
			  }
#line 4725 "parser.c"
    break;

  case 27: /* commandlist: command ";" commandlist  */
#line 619 "parser.y"
                          {
			    (yyval.list) = addElement((yyvsp[0].list), (yyvsp[-2].tree));
			  }
#line 4733 "parser.c"
    break;

  case 28: /* variabledeclarationlist: variabledeclaration ";"  */
#line 625 "parser.y"
                          {
			    (yyval.list) = addElement(NULL, (yyvsp[-1].tree));
			  }
#line 4741 "parser.c"
    break;

  case 29: /* variabledeclarationlist: variabledeclaration ";" variabledeclarationlist  */
#line 629 "parser.y"
                          {
			    (yyval.list) = addElement((yyvsp[0].list), (yyvsp[-2].tree));
			  }
#line 4749 "parser.c"
    break;

  case 30: /* variabledeclaration: "var" identifierlist  */
#line 635 "parser.y"
                          {
			    (yyval.tree) = makeVariableDeclaration((yyvsp[0].list));
			  }
#line 4757 "parser.c"
    break;

  case 31: /* identifierlist: "identifier"  */
#line 642 "parser.y"
                          {
			    (yyval.list) = addElement(NULL, (yyvsp[0].value));
			  }
#line 4765 "parser.c"
    break;

  case 32: /* identifierlist: "identifier" "," identifierlist  */
#line 646 "parser.y"
                          {
			    (yyval.list) = addElement((yyvsp[0].list), (yyvsp[-2].value));
			  }
#line 4773 "parser.c"
    break;

  case 33: /* procbody: "(" ")" beginsymbol commandlist endsymbol  */
#line 652 "parser.y"
                          {
			    (yyval.tree) = makeProc(NULL, makeCommandList((yyvsp[-1].list)), makeUnit());
                          }
#line 4781 "parser.c"
    break;

  case 34: /* procbody: "(" ")" beginsymbol variabledeclarationlist commandlist endsymbol  */
#line 656 "parser.y"
                          {
			    (yyval.tree) = makeProc(NULL, makeCommandList(concatChains((yyvsp[-2].list), (yyvsp[-1].list))), makeUnit());
                          }
#line 4789 "parser.c"
    break;

  case 35: /* procbody: "(" ")" beginsymbol variabledeclarationlist endsymbol  */
#line 660 "parser.y"
                          {
			    (yyval.tree) = makeProc(NULL, makeCommandList((yyvsp[-1].list)), makeUnit());
                          }
#line 4797 "parser.c"
    break;

  case 36: /* procbody: "(" ")" beginsymbol endsymbol  */
#line 664 "parser.y"
                          {
			    (yyval.tree) = makeProc(NULL, makeCommandList(addElement(NULL,makeNop())), makeUnit());
                          }
#line 4805 "parser.c"
    break;

  case 37: /* procbody: "(" ")" beginsymbol commandlist "return" thing ";" endsymbol  */
#line 668 "parser.y"
                          {
			    (yyval.tree) = makeProc(NULL, makeCommandList((yyvsp[-4].list)), (yyvsp[-2].tree));
                          }
#line 4813 "parser.c"
    break;

  case 38: /* procbody: "(" ")" beginsymbol variabledeclarationlist commandlist "return" thing ";" endsymbol  */
#line 672 "parser.y"
                          {
			    (yyval.tree) = makeProc(NULL, makeCommandList(concatChains((yyvsp[-5].list), (yyvsp[-4].list))), (yyvsp[-2].tree));
                          }
#line 4821 "parser.c"
    break;

  case 39: /* procbody: "(" ")" beginsymbol variabledeclarationlist "return" thing ";" endsymbol  */
#line 676 "parser.y"
                          {
			    (yyval.tree) = makeProc(NULL, makeCommandList((yyvsp[-4].list)), (yyvsp[-2].tree));
                          }
#line 4829 "parser.c"
    break;

  case 40: /* procbody: "(" ")" beginsymbol "return" thing ";" endsymbol  */
#line 680 "parser.y"
                          {
			    (yyval.tree) = makeProc(NULL, makeCommandList(addElement(NULL,makeNop())), (yyvsp[-2].tree));
                          }
#line 4837 "parser.c"
    break;

  case 41: /* procbody: "(" identifierlist ")" beginsymbol commandlist endsymbol  */
#line 684 "parser.y"
                          {
			    (yyval.tree) = makeProc((yyvsp[-4].list), makeCommandList((yyvsp[-1].list)), makeUnit());
                          }
#line 4845 "parser.c"
    break;

  case 42: /* procbody: "(" identifierlist ")" beginsymbol variabledeclarationlist commandlist endsymbol  */
#line 688 "parser.y"
                          {
			    (yyval.tree) = makeProc((yyvsp[-5].list), makeCommandList(concatChains((yyvsp[-2].list), (yyvsp[-1].list))), makeUnit());
                          }
#line 4853 "parser.c"
    break;

  case 43: /* procbody: "(" identifierlist ")" beginsymbol variabledeclarationlist endsymbol  */
#line 692 "parser.y"
                          {
			    (yyval.tree) = makeProc((yyvsp[-4].list), makeCommandList((yyvsp[-1].list)), makeUnit());
                          }
#line 4861 "parser.c"
    break;

  case 44: /* procbody: "(" identifierlist ")" beginsymbol endsymbol  */
#line 696 "parser.y"
                          {
			    (yyval.tree) = makeProc((yyvsp[-3].list), makeCommandList(addElement(NULL,makeNop())), makeUnit());
                          }
#line 4869 "parser.c"
    break;

  case 45: /* procbody: "(" identifierlist ")" beginsymbol commandlist "return" thing ";" endsymbol  */
#line 700 "parser.y"
                          {
			    (yyval.tree) = makeProc((yyvsp[-7].list), makeCommandList((yyvsp[-4].list)), (yyvsp[-2].tree));
                          }
#line 4877 "parser.c"
    break;

  case 46: /* procbody: "(" identifierlist ")" beginsymbol variabledeclarationlist commandlist "return" thing ";" endsymbol  */
#line 704 "parser.y"
                          {
			    (yyval.tree) = makeProc((yyvsp[-8].list), makeCommandList(concatChains((yyvsp[-5].list), (yyvsp[-4].list))), (yyvsp[-2].tree));
                          }
#line 4885 "parser.c"
    break;

  case 47: /* procbody: "(" identifierlist ")" beginsymbol variabledeclarationlist "return" thing ";" endsymbol  */
#line 708 "parser.y"
                          {
			    (yyval.tree) = makeProc((yyvsp[-7].list), makeCommandList((yyvsp[-4].list)), (yyvsp[-2].tree));
                          }
#line 4893 "parser.c"
    break;

  case 48: /* procbody: "(" identifierlist ")" beginsymbol "return" thing ";" endsymbol  */
#line 712 "parser.y"
                          {
			    (yyval.tree) = makeProc((yyvsp[-6].list), makeCommandList(addElement(NULL, makeNop())), (yyvsp[-2].tree));
                          }
#line 4901 "parser.c"
    break;

  case 49: /* procbody: "(" "identifier" "=" "..." ")" beginsymbol commandlist endsymbol  */
#line 716 "parser.y"
                          {
			    (yyval.tree) = makeProcIllim((yyvsp[-6].value), makeCommandList((yyvsp[-1].list)), makeUnit());
                          }
#line 4909 "parser.c"
    break;

  case 50: /* procbody: "(" "identifier" "=" "..." ")" beginsymbol variabledeclarationlist commandlist endsymbol  */
#line 720 "parser.y"
                          {
			    (yyval.tree) = makeProcIllim((yyvsp[-7].value), makeCommandList(concatChains((yyvsp[-2].list), (yyvsp[-1].list))), makeUnit());
                          }
#line 4917 "parser.c"
    break;

  case 51: /* procbody: "(" "identifier" "=" "..." ")" beginsymbol variabledeclarationlist endsymbol  */
#line 724 "parser.y"
                          {
			    (yyval.tree) = makeProcIllim((yyvsp[-6].value), makeCommandList((yyvsp[-1].list)), makeUnit());
                          }
#line 4925 "parser.c"
    break;

  case 52: /* procbody: "(" "identifier" "=" "..." ")" beginsymbol endsymbol  */
#line 728 "parser.y"
                          {
			    (yyval.tree) = makeProcIllim((yyvsp[-5].value), makeCommandList(addElement(NULL,makeNop())), makeUnit());
                          }
#line 4933 "parser.c"
    break;

  case 53: /* procbody: "(" "identifier" "=" "..." ")" beginsymbol commandlist "return" thing ";" endsymbol  */
#line 732 "parser.y"
                          {
			    (yyval.tree) = makeProcIllim((yyvsp[-9].value), makeCommandList((yyvsp[-4].list)), (yyvsp[-2].tree));
                          }
#line 4941 "parser.c"
    break;

  case 54: /* procbody: "(" "identifier" "=" "..." ")" beginsymbol variabledeclarationlist commandlist "return" thing ";" endsymbol  */
#line 736 "parser.y"
                          {
			    (yyval.tree) = makeProcIllim((yyvsp[-10].value), makeCommandList(concatChains((yyvsp[-5].list), (yyvsp[-4].list))), (yyvsp[-2].tree));
                          }
#line 4949 "parser.c"
    break;

  case 55: /* procbody: "(" "identifier" "=" "..." ")" beginsymbol variabledeclarationlist "return" thing ";" endsymbol  */
#line 740 "parser.y"
                          {
			    (yyval.tree) = makeProcIllim((yyvsp[-9].value), makeCommandList((yyvsp[-4].list)), (yyvsp[-2].tree));
                          }
#line 4957 "parser.c"
    break;

  case 56: /* procbody: "(" "identifier" "=" "..." ")" beginsymbol "return" thing ";" endsymbol  */
#line 744 "parser.y"
                          {
			    (yyval.tree) = makeProcIllim((yyvsp[-8].value), makeCommandList(addElement(NULL, makeNop())), (yyvsp[-2].tree));
                          }
#line 4965 "parser.c"
    break;

  case 57: /* simplecommand: "quit"  */
#line 751 "parser.y"
                          {
			    (yyval.tree) = makeQuit();
			  }
#line 4973 "parser.c"
    break;

  case 58: /* simplecommand: "quit in an included file"  */
#line 755 "parser.y"
                          {
			    (yyval.tree) = makeFalseQuit();
			  }
#line 4981 "parser.c"
    break;

  case 59: /* simplecommand: "nop"  */
#line 759 "parser.y"
                          {
			    (yyval.tree) = makeNop();
			  }
#line 4989 "parser.c"
    break;

  case 60: /* simplecommand: "nop" "(" thing ")"  */
#line 763 "parser.y"
                          {
			    (yyval.tree) = makeNopArg((yyvsp[-1].tree));
			  }
#line 4997 "parser.c"
    break;

  case 61: /* simplecommand: "nop" "(" ")"  */
#line 767 "parser.y"
                          {
			    (yyval.tree) = makeNopArg(makeDefault());
			  }
#line 5005 "parser.c"
    break;

  case 62: /* simplecommand: "restart"  */
#line 771 "parser.y"
                          {
			    (yyval.tree) = makeRestart();
			  }
#line 5013 "parser.c"
    break;

  case 63: /* simplecommand: "print" "(" thinglist ")"  */
#line 775 "parser.y"
                          {
			    (yyval.tree) = makePrint((yyvsp[-1].list));
			  }
#line 5021 "parser.c"
    break;

  case 64: /* simplecommand: "print" "(" thinglist ")" ">" thing  */
#line 779 "parser.y"
                          {
			    (yyval.tree) = makeNewFilePrint((yyvsp[0].tree), (yyvsp[-3].list));
			  }
#line 5029 "parser.c"
    break;

  case 65: /* simplecommand: "print" "(" thinglist ")" ">" ">" thing  */
#line 783 "parser.y"
                          {
			    (yyval.tree) = makeAppendFilePrint((yyvsp[0].tree), (yyvsp[-4].list));
			  }
#line 5037 "parser.c"
    break;

  case 66: /* simplecommand: "plot" "(" thing "," thinglist ")"  */
#line 787 "parser.y"
                          {
			    (yyval.tree) = makePlot(addElement((yyvsp[-1].list), (yyvsp[-3].tree)));
			  }
#line 5045 "parser.c"
    break;

  case 67: /* simplecommand: "printhexa" "(" thing ")"  */
#line 791 "parser.y"
                          {
			    (yyval.tree) = makePrintHexa((yyvsp[-1].tree));
			  }
#line 5053 "parser.c"
    break;

  case 68: /* simplecommand: "printfloat" "(" thing ")"  */
#line 795 "parser.y"
                          {
			    (yyval.tree) = makePrintFloat((yyvsp[-1].tree));
			  }
#line 5061 "parser.c"
    break;

  case 69: /* simplecommand: "printbinary" "(" thing ")"  */
#line 799 "parser.y"
                          {
			    (yyval.tree) = makePrintBinary((yyvsp[-1].tree));
			  }
#line 5069 "parser.c"
    break;

  case 70: /* simplecommand: "suppressmessage" "(" thinglist ")"  */
#line 803 "parser.y"
                          {
			    (yyval.tree) = makeSuppressMessage((yyvsp[-1].list));
			  }
#line 5077 "parser.c"
    break;

  case 71: /* simplecommand: "unsuppressmessage" "(" thinglist ")"  */
#line 807 "parser.y"
                          {
			    (yyval.tree) = makeUnsuppressMessage((yyvsp[-1].list));
			  }
#line 5085 "parser.c"
    break;

  case 72: /* simplecommand: "printexpansion" "(" thing ")"  */
#line 811 "parser.y"
                          {
			    (yyval.tree) = makePrintExpansion((yyvsp[-1].tree));
			  }
#line 5093 "parser.c"
    break;

  case 73: /* simplecommand: "implementconst" "(" thinglist ")"  */
#line 815 "parser.y"
                          {
			    (yyval.tree) = makeImplementConst((yyvsp[-1].list));
			  }
#line 5101 "parser.c"
    break;

  case 74: /* simplecommand: "bashexecute" "(" thing ")"  */
#line 819 "parser.y"
                          {
			    (yyval.tree) = makeBashExecute((yyvsp[-1].tree));
			  }
#line 5109 "parser.c"
    break;

  case 75: /* simplecommand: "externalplot" "(" thing "," thing "," thing "," thing "," thinglist ")"  */
#line 823 "parser.y"
                          {
			    (yyval.tree) = makeExternalPlot(addElement(addElement(addElement(addElement((yyvsp[-1].list),(yyvsp[-3].tree)),(yyvsp[-5].tree)),(yyvsp[-7].tree)),(yyvsp[-9].tree)));
			  }
#line 5117 "parser.c"
    break;

  case 76: /* simplecommand: "write" "(" thinglist ")"  */
#line 827 "parser.y"
                          {
			    (yyval.tree) = makeWrite((yyvsp[-1].list));
			  }
#line 5125 "parser.c"
    break;

  case 77: /* simplecommand: "write" "(" thinglist ")" ">" thing  */
#line 831 "parser.y"
                          {
			    (yyval.tree) = makeNewFileWrite((yyvsp[0].tree), (yyvsp[-3].list));
			  }
#line 5133 "parser.c"
    break;

  case 78: /* simplecommand: "write" "(" thinglist ")" ">" ">" thing  */
#line 835 "parser.y"
                          {
			    (yyval.tree) = makeAppendFileWrite((yyvsp[0].tree), (yyvsp[-4].list));
			  }
#line 5141 "parser.c"
    break;

  case 79: /* simplecommand: "asciiplot" "(" thing "," thing ")"  */
#line 839 "parser.y"
                          {
			    (yyval.tree) = makeAsciiPlot((yyvsp[-3].tree), (yyvsp[-1].tree));
			  }
#line 5149 "parser.c"
    break;

  case 80: /* simplecommand: "printxml" "(" thing ")"  */
#line 843 "parser.y"
                          {
			    (yyval.tree) = makePrintXml((yyvsp[-1].tree));
			  }
#line 5157 "parser.c"
    break;

  case 81: /* simplecommand: "execute" "(" thing ")"  */
#line 847 "parser.y"
                          {
			    (yyval.tree) = makeExecute((yyvsp[-1].tree));
			  }
#line 5165 "parser.c"
    break;

  case 82: /* simplecommand: "printxml" "(" thing ")" ">" thing  */
#line 851 "parser.y"
                          {
			    (yyval.tree) = makePrintXmlNewFile((yyvsp[-3].tree),(yyvsp[0].tree));
			  }
#line 5173 "parser.c"
    break;

  case 83: /* simplecommand: "printxml" "(" thing ")" ">" ">" thing  */
#line 855 "parser.y"
                          {
			    (yyval.tree) = makePrintXmlAppendFile((yyvsp[-4].tree),(yyvsp[0].tree));
			  }
#line 5181 "parser.c"
    break;

  case 84: /* simplecommand: "worstcase" "(" thing "," thing "," thing "," thing "," thinglist ")"  */
#line 859 "parser.y"
                          {
			    (yyval.tree) = makeWorstCase(addElement(addElement(addElement(addElement((yyvsp[-1].list), (yyvsp[-3].tree)), (yyvsp[-5].tree)), (yyvsp[-7].tree)), (yyvsp[-9].tree)));
			  }
#line 5189 "parser.c"
    break;

  case 85: /* simplecommand: "rename" "(" "identifier" "," "identifier" ")"  */
#line 863 "parser.y"
                          {
			    (yyval.tree) = makeRename((yyvsp[-3].value), (yyvsp[-1].value));
			    safeFree((yyvsp[-3].value));
			    safeFree((yyvsp[-1].value));
			  }
#line 5199 "parser.c"
    break;

  case 86: /* simplecommand: "rename" "(" "identifier" "," "_x_" ")"  */
#line 869 "parser.y"
                          {
			    (yyval.tree) = makeRename((yyvsp[-3].value), "_x_");
			    safeFree((yyvsp[-3].value));
			  }
#line 5208 "parser.c"
    break;

  case 87: /* simplecommand: "rename" "(" "_x_" "," "identifier" ")"  */
#line 874 "parser.y"
                          {
			    (yyval.tree) = makeRename("_x_", (yyvsp[-1].value));
			    safeFree((yyvsp[-1].value));
			  }
#line 5217 "parser.c"
    break;

  case 88: /* simplecommand: "rename" "(" "_x_" "," "_x_" ")"  */
#line 879 "parser.y"
                          {
			    (yyval.tree) = makeRename("_x_", "_x_");
			  }
#line 5225 "parser.c"
    break;

  case 89: /* simplecommand: "externalproc" "(" "identifier" "," thing "," externalproctypelist "-" ">" extendedexternalproctype ")"  */
#line 883 "parser.y"
                          {
			    (yyval.tree) = makeExternalProc((yyvsp[-8].value), (yyvsp[-6].tree), addElement((yyvsp[-4].list), (yyvsp[-1].integerval)));
			    safeFree((yyvsp[-8].value));
			  }
#line 5234 "parser.c"
    break;

  case 90: /* simplecommand: "externaldata" "(" "identifier" "," thing ")"  */
#line 888 "parser.y"
                          {
			    (yyval.tree) = makeExternalData((yyvsp[-3].value), (yyvsp[-1].tree));
			    safeFree((yyvsp[-3].value));
			  }
#line 5243 "parser.c"
    break;

  case 91: /* simplecommand: assignment  */
#line 893 "parser.y"
                          {
			    (yyval.tree) = (yyvsp[0].tree);
			  }
#line 5251 "parser.c"
    break;

  case 92: /* simplecommand: thinglist  */
#line 897 "parser.y"
                          {
			    (yyval.tree) = makeAutoprint((yyvsp[0].list));
			  }
#line 5259 "parser.c"
    break;

  case 93: /* simplecommand: "procedure" "identifier" procbody  */
#line 901 "parser.y"
                          {
			    (yyval.tree) = makeAssignment((yyvsp[-1].value), (yyvsp[0].tree));
			    safeFree((yyvsp[-1].value));
			  }
#line 5268 "parser.c"
    break;

  case 94: /* assignment: stateassignment  */
#line 908 "parser.y"
                          {
			    (yyval.tree) = (yyvsp[0].tree);
			  }
#line 5276 "parser.c"
    break;

  case 95: /* assignment: stillstateassignment "!"  */
#line 912 "parser.y"
                          {
			    (yyval.tree) = (yyvsp[-1].tree);
			  }
#line 5284 "parser.c"
    break;

  case 96: /* assignment: simpleassignment  */
#line 916 "parser.y"
                          {
			    (yyval.tree) = (yyvsp[0].tree);
			  }
#line 5292 "parser.c"
    break;

  case 97: /* assignment: simpleassignment "!"  */
#line 920 "parser.y"
                          {
			    (yyval.tree) = (yyvsp[-1].tree);
			  }
#line 5300 "parser.c"
    break;

  case 98: /* simpleassignment: "identifier" "=" thing  */
#line 926 "parser.y"
                          {
			    (yyval.tree) = makeAssignment((yyvsp[-2].value), (yyvsp[0].tree));
			    safeFree((yyvsp[-2].value));
			  }
#line 5309 "parser.c"
    break;

  case 99: /* simpleassignment: "identifier" ":=" thing  */
#line 931 "parser.y"
                          {
			    (yyval.tree) = makeFloatAssignment((yyvsp[-2].value), (yyvsp[0].tree));
			    safeFree((yyvsp[-2].value));
			  }
#line 5318 "parser.c"
    break;

  case 100: /* simpleassignment: "identifier" "=" "library" "(" thing ")"  */
#line 936 "parser.y"
                          {
			    (yyval.tree) = makeLibraryBinding((yyvsp[-5].value), (yyvsp[-1].tree));
			    safeFree((yyvsp[-5].value));
			  }
#line 5327 "parser.c"
    break;

  case 101: /* simpleassignment: "identifier" "=" "libraryconstant" "(" thing ")"  */
#line 941 "parser.y"
                          {
			    (yyval.tree) = makeLibraryConstantBinding((yyvsp[-5].value), (yyvsp[-1].tree));
			    safeFree((yyvsp[-5].value));
			  }
#line 5336 "parser.c"
    break;

  case 102: /* simpleassignment: indexing "=" thing  */
#line 946 "parser.y"
                          {
			    (yyval.tree) = makeAssignmentInIndexing((yyvsp[-2].dblnode)->a,(yyvsp[-2].dblnode)->b,(yyvsp[0].tree));
			    safeFree((yyvsp[-2].dblnode));
			  }
#line 5345 "parser.c"
    break;

  case 103: /* simpleassignment: indexing ":=" thing  */
#line 951 "parser.y"
                          {
			    (yyval.tree) = makeFloatAssignmentInIndexing((yyvsp[-2].dblnode)->a,(yyvsp[-2].dblnode)->b,(yyvsp[0].tree));
			    safeFree((yyvsp[-2].dblnode));
			  }
#line 5354 "parser.c"
    break;

  case 104: /* simpleassignment: structuring "=" thing  */
#line 956 "parser.y"
                          {
			    (yyval.tree) = makeProtoAssignmentInStructure((yyvsp[-2].tree),(yyvsp[0].tree));
			  }
#line 5362 "parser.c"
    break;

  case 105: /* simpleassignment: structuring ":=" thing  */
#line 960 "parser.y"
                          {
			    (yyval.tree) = makeProtoFloatAssignmentInStructure((yyvsp[-2].tree),(yyvsp[0].tree));
			  }
#line 5370 "parser.c"
    break;

  case 106: /* structuring: basicthing "." "identifier"  */
#line 966 "parser.y"
                          {
			    (yyval.tree) = makeStructAccess((yyvsp[-2].tree),(yyvsp[0].value));
			    safeFree((yyvsp[0].value));
			  }
#line 5379 "parser.c"
    break;

  case 107: /* stateassignment: "prec" "=" thing  */
#line 973 "parser.y"
                          {
			    (yyval.tree) = makePrecAssign((yyvsp[0].tree));
			  }
#line 5387 "parser.c"
    break;

  case 108: /* stateassignment: "points" "=" thing  */
#line 977 "parser.y"
                          {
			    (yyval.tree) = makePointsAssign((yyvsp[0].tree));
			  }
#line 5395 "parser.c"
    break;

  case 109: /* stateassignment: "diam" "=" thing  */
#line 981 "parser.y"
                          {
			    (yyval.tree) = makeDiamAssign((yyvsp[0].tree));
			  }
#line 5403 "parser.c"
    break;

  case 110: /* stateassignment: "display" "=" thing  */
#line 985 "parser.y"
                          {
			    (yyval.tree) = makeDisplayAssign((yyvsp[0].tree));
			  }
#line 5411 "parser.c"
    break;

  case 111: /* stateassignment: "verbosity" "=" thing  */
#line 989 "parser.y"
                          {
			    (yyval.tree) = makeVerbosityAssign((yyvsp[0].tree));
			  }
#line 5419 "parser.c"
    break;

  case 112: /* stateassignment: "showmessagenumbers" "=" thing  */
#line 993 "parser.y"
                          {
			    (yyval.tree) = makeShowMessageNumbersAssign((yyvsp[0].tree));
			  }
#line 5427 "parser.c"
    break;

  case 113: /* stateassignment: "canonical" "=" thing  */
#line 997 "parser.y"
                          {
			    (yyval.tree) = makeCanonicalAssign((yyvsp[0].tree));
			  }
#line 5435 "parser.c"
    break;

  case 114: /* stateassignment: "autosimplify" "=" thing  */
#line 1001 "parser.y"
                          {
			    (yyval.tree) = makeAutoSimplifyAssign((yyvsp[0].tree));
			  }
#line 5443 "parser.c"
    break;

  case 115: /* stateassignment: "taylorrecursions" "=" thing  */
#line 1005 "parser.y"
                          {
			    (yyval.tree) = makeTaylorRecursAssign((yyvsp[0].tree));
			  }
#line 5451 "parser.c"
    break;

  case 116: /* stateassignment: "timing" "=" thing  */
#line 1009 "parser.y"
                          {
			    (yyval.tree) = makeTimingAssign((yyvsp[0].tree));
			  }
#line 5459 "parser.c"
    break;

  case 117: /* stateassignment: "fullparentheses" "=" thing  */
#line 1013 "parser.y"
                          {
			    (yyval.tree) = makeFullParenAssign((yyvsp[0].tree));
			  }
#line 5467 "parser.c"
    break;

  case 118: /* stateassignment: "midpointmode" "=" thing  */
#line 1017 "parser.y"
                          {
			    (yyval.tree) = makeMidpointAssign((yyvsp[0].tree));
			  }
#line 5475 "parser.c"
    break;

  case 119: /* stateassignment: "dieonerrormode" "=" thing  */
#line 1021 "parser.y"
                          {
			    (yyval.tree) = makeDieOnErrorAssign((yyvsp[0].tree));
			  }
#line 5483 "parser.c"
    break;

  case 120: /* stateassignment: "rationalmode" "=" thing  */
#line 1025 "parser.y"
                          {
			    (yyval.tree) = makeRationalModeAssign((yyvsp[0].tree));
			  }
#line 5491 "parser.c"
    break;

  case 121: /* stateassignment: "roundingwarnings" "=" thing  */
#line 1029 "parser.y"
                          {
			    (yyval.tree) = makeSuppressWarningsAssign((yyvsp[0].tree));
			  }
#line 5499 "parser.c"
    break;

  case 122: /* stateassignment: "hopitalrecursions" "=" thing  */
#line 1033 "parser.y"
                          {
			    (yyval.tree) = makeHopitalRecursAssign((yyvsp[0].tree));
			  }
#line 5507 "parser.c"
    break;

  case 123: /* stillstateassignment: "prec" "=" thing  */
#line 1039 "parser.y"
                          {
			    (yyval.tree) = makePrecStillAssign((yyvsp[0].tree));
			  }
#line 5515 "parser.c"
    break;

  case 124: /* stillstateassignment: "points" "=" thing  */
#line 1043 "parser.y"
                          {
			    (yyval.tree) = makePointsStillAssign((yyvsp[0].tree));
			  }
#line 5523 "parser.c"
    break;

  case 125: /* stillstateassignment: "diam" "=" thing  */
#line 1047 "parser.y"
                          {
			    (yyval.tree) = makeDiamStillAssign((yyvsp[0].tree));
			  }
#line 5531 "parser.c"
    break;

  case 126: /* stillstateassignment: "display" "=" thing  */
#line 1051 "parser.y"
                          {
			    (yyval.tree) = makeDisplayStillAssign((yyvsp[0].tree));
			  }
#line 5539 "parser.c"
    break;

  case 127: /* stillstateassignment: "verbosity" "=" thing  */
#line 1055 "parser.y"
                          {
			    (yyval.tree) = makeVerbosityStillAssign((yyvsp[0].tree));
			  }
#line 5547 "parser.c"
    break;

  case 128: /* stillstateassignment: "showmessagenumbers" "=" thing  */
#line 1059 "parser.y"
                          {
			    (yyval.tree) = makeShowMessageNumbersStillAssign((yyvsp[0].tree));
			  }
#line 5555 "parser.c"
    break;

  case 129: /* stillstateassignment: "canonical" "=" thing  */
#line 1063 "parser.y"
                          {
			    (yyval.tree) = makeCanonicalStillAssign((yyvsp[0].tree));
			  }
#line 5563 "parser.c"
    break;

  case 130: /* stillstateassignment: "autosimplify" "=" thing  */
#line 1067 "parser.y"
                          {
			    (yyval.tree) = makeAutoSimplifyStillAssign((yyvsp[0].tree));
			  }
#line 5571 "parser.c"
    break;

  case 131: /* stillstateassignment: "taylorrecursions" "=" thing  */
#line 1071 "parser.y"
                          {
			    (yyval.tree) = makeTaylorRecursStillAssign((yyvsp[0].tree));
			  }
#line 5579 "parser.c"
    break;

  case 132: /* stillstateassignment: "timing" "=" thing  */
#line 1075 "parser.y"
                          {
			    (yyval.tree) = makeTimingStillAssign((yyvsp[0].tree));
			  }
#line 5587 "parser.c"
    break;

  case 133: /* stillstateassignment: "fullparentheses" "=" thing  */
#line 1079 "parser.y"
                          {
			    (yyval.tree) = makeFullParenStillAssign((yyvsp[0].tree));
			  }
#line 5595 "parser.c"
    break;

  case 134: /* stillstateassignment: "midpointmode" "=" thing  */
#line 1083 "parser.y"
                          {
			    (yyval.tree) = makeMidpointStillAssign((yyvsp[0].tree));
			  }
#line 5603 "parser.c"
    break;

  case 135: /* stillstateassignment: "dieonerrormode" "=" thing  */
#line 1087 "parser.y"
                          {
			    (yyval.tree) = makeDieOnErrorStillAssign((yyvsp[0].tree));
			  }
#line 5611 "parser.c"
    break;

  case 136: /* stillstateassignment: "rationalmode" "=" thing  */
#line 1091 "parser.y"
                          {
			    (yyval.tree) = makeRationalModeStillAssign((yyvsp[0].tree));
			  }
#line 5619 "parser.c"
    break;

  case 137: /* stillstateassignment: "roundingwarnings" "=" thing  */
#line 1095 "parser.y"
                          {
			    (yyval.tree) = makeSuppressWarningsStillAssign((yyvsp[0].tree));
			  }
#line 5627 "parser.c"
    break;

  case 138: /* stillstateassignment: "hopitalrecursions" "=" thing  */
#line 1099 "parser.y"
                          {
			    (yyval.tree) = makeHopitalRecursStillAssign((yyvsp[0].tree));
			  }
#line 5635 "parser.c"
    break;

  case 139: /* thinglist: thing  */
#line 1105 "parser.y"
                          {
			    (yyval.list) = addElement(NULL, (yyvsp[0].tree));
			  }
#line 5643 "parser.c"
    break;

  case 140: /* thinglist: thing "," thinglist  */
#line 1109 "parser.y"
                          {
			    (yyval.list) = addElement((yyvsp[0].list), (yyvsp[-2].tree));
			  }
#line 5651 "parser.c"
    break;

  case 141: /* structelementlist: structelement  */
#line 1115 "parser.y"
                          {
			    (yyval.list) = addElement(NULL, (yyvsp[0].association));
			  }
#line 5659 "parser.c"
    break;

  case 142: /* structelementlist: structelement structelementseparator structelementlist  */
#line 1119 "parser.y"
                          {
			    (yyval.list) = addElement((yyvsp[0].list), (yyvsp[-2].association));
			  }
#line 5667 "parser.c"
    break;

  case 143: /* structelementseparator: ","  */
#line 1125 "parser.y"
                          {
			    (yyval.other) = NULL;
			  }
#line 5675 "parser.c"
    break;

  case 144: /* structelementseparator: ";"  */
#line 1129 "parser.y"
                          {
			    (yyval.other) = NULL;
			  }
#line 5683 "parser.c"
    break;

  case 145: /* structelement: "." "identifier" "=" thing  */
#line 1135 "parser.y"
                          {
			    (yyval.association) = (entry *) safeMalloc(sizeof(entry));
			    (yyval.association)->name = (char *) safeCalloc(strlen((yyvsp[-2].value)) + 1, sizeof(char));
			    strcpy((yyval.association)->name,(yyvsp[-2].value));
			    safeFree((yyvsp[-2].value));
			    (yyval.association)->value = (void *) ((yyvsp[0].tree));
			  }
#line 5695 "parser.c"
    break;

  case 146: /* thing: supermegaterm  */
#line 1145 "parser.y"
                         {
			   (yyval.tree) = (yyvsp[0].tree);
			 }
#line 5703 "parser.c"
    break;

  case 147: /* thing: "match" supermegaterm "with" matchlist  */
#line 1149 "parser.y"
                          {
			    (yyval.tree) = makeMatch((yyvsp[-2].tree),(yyvsp[0].list));
			  }
#line 5711 "parser.c"
    break;

  case 148: /* supermegaterm: megaterm  */
#line 1155 "parser.y"
                          {
			    (yyval.tree) = (yyvsp[0].tree);
			  }
#line 5719 "parser.c"
    break;

  case 149: /* supermegaterm: thing "&&" megaterm  */
#line 1159 "parser.y"
                          {
			    (yyval.tree) = makeAnd((yyvsp[-2].tree), (yyvsp[0].tree));
			  }
#line 5727 "parser.c"
    break;

  case 150: /* supermegaterm: thing "||" megaterm  */
#line 1163 "parser.y"
                          {
			    (yyval.tree) = makeOr((yyvsp[-2].tree), (yyvsp[0].tree));
			  }
#line 5735 "parser.c"
    break;

  case 151: /* supermegaterm: "!" megaterm  */
#line 1167 "parser.y"
                          {
			    (yyval.tree) = makeNegation((yyvsp[0].tree));
			  }
#line 5743 "parser.c"
    break;

  case 152: /* indexing: basicthing "[" thing "]"  */
#line 1173 "parser.y"
                          {
			    (yyval.dblnode) = (doubleNode *) safeMalloc(sizeof(doubleNode));
			    (yyval.dblnode)->a = (yyvsp[-3].tree);
			    (yyval.dblnode)->b = (yyvsp[-1].tree);
			  }
#line 5753 "parser.c"
    break;

  case 153: /* megaterm: hyperterm  */
#line 1182 "parser.y"
                          {
			    (yyval.tree) = (yyvsp[0].tree);
			  }
#line 5761 "parser.c"
    break;

  case 154: /* megaterm: megaterm "==" hyperterm  */
#line 1186 "parser.y"
                          {
			    (yyval.tree) = makeCompareEqual((yyvsp[-2].tree), (yyvsp[0].tree));
			  }
#line 5769 "parser.c"
    break;

  case 155: /* megaterm: megaterm "in" hyperterm  */
#line 1190 "parser.y"
                          {
			    (yyval.tree) = makeCompareIn((yyvsp[-2].tree), (yyvsp[0].tree));
			  }
#line 5777 "parser.c"
    break;

  case 156: /* megaterm: megaterm "<" hyperterm  */
#line 1194 "parser.y"
                          {
			    (yyval.tree) = makeCompareLess((yyvsp[-2].tree), (yyvsp[0].tree));
			  }
#line 5785 "parser.c"
    break;

  case 157: /* megaterm: megaterm ">" hyperterm  */
#line 1198 "parser.y"
                          {
			    (yyval.tree) = makeCompareGreater((yyvsp[-2].tree), (yyvsp[0].tree));
			  }
#line 5793 "parser.c"
    break;

  case 158: /* megaterm: megaterm "<" "=" hyperterm  */
#line 1202 "parser.y"
                          {
			    (yyval.tree) = makeCompareLessEqual((yyvsp[-3].tree), (yyvsp[0].tree));
			  }
#line 5801 "parser.c"
    break;

  case 159: /* megaterm: megaterm ">" "=" hyperterm  */
#line 1206 "parser.y"
                          {
			    (yyval.tree) = makeCompareGreaterEqual((yyvsp[-3].tree), (yyvsp[0].tree));
			  }
#line 5809 "parser.c"
    break;

  case 160: /* megaterm: megaterm "!=" hyperterm  */
#line 1210 "parser.y"
                          {
			    (yyval.tree) = makeCompareNotEqual((yyvsp[-2].tree), (yyvsp[0].tree));
			  }
#line 5817 "parser.c"
    break;

  case 161: /* hyperterm: term  */
#line 1216 "parser.y"
                          {
			    (yyval.tree) = (yyvsp[0].tree);
			  }
#line 5825 "parser.c"
    break;

  case 162: /* hyperterm: hyperterm "+" term  */
#line 1220 "parser.y"
                          {
			    (yyval.tree) = makeAdd((yyvsp[-2].tree), (yyvsp[0].tree));
			  }
#line 5833 "parser.c"
    break;

  case 163: /* hyperterm: hyperterm "-" term  */
#line 1224 "parser.y"
                          {
			    (yyval.tree) = makeSub((yyvsp[-2].tree), (yyvsp[0].tree));
			  }
#line 5841 "parser.c"
    break;

  case 164: /* hyperterm: hyperterm "@" term  */
#line 1228 "parser.y"
                          {
			    (yyval.tree) = makeConcat((yyvsp[-2].tree), (yyvsp[0].tree));
			  }
#line 5849 "parser.c"
    break;

  case 165: /* hyperterm: hyperterm "::" term  */
#line 1232 "parser.y"
                          {
			    (yyval.tree) = makeAddToList((yyvsp[-2].tree), (yyvsp[0].tree));
			  }
#line 5857 "parser.c"
    break;

  case 166: /* hyperterm: hyperterm ":." term  */
#line 1236 "parser.y"
                          {
			    (yyval.tree) = makeAppend((yyvsp[-2].tree), (yyvsp[0].tree));
			  }
#line 5865 "parser.c"
    break;

  case 167: /* unaryplusminus: "+"  */
#line 1242 "parser.y"
                          {
			    (yyval.count) = 0;
                          }
#line 5873 "parser.c"
    break;

  case 168: /* unaryplusminus: "-"  */
#line 1246 "parser.y"
                          {
			    (yyval.count) = 1;
                          }
#line 5881 "parser.c"
    break;

  case 169: /* unaryplusminus: "+" unaryplusminus  */
#line 1250 "parser.y"
                          {
			    (yyval.count) = (yyvsp[0].count);
                          }
#line 5889 "parser.c"
    break;

  case 170: /* unaryplusminus: "-" unaryplusminus  */
#line 1254 "parser.y"
                          {
			    (yyval.count) = (yyvsp[0].count)+1;
                          }
#line 5897 "parser.c"
    break;

  case 171: /* term: subterm  */
#line 1261 "parser.y"
                          {
			    (yyval.tree) = (yyvsp[0].tree);
                          }
#line 5905 "parser.c"
    break;

  case 172: /* term: unaryplusminus subterm  */
#line 1265 "parser.y"
                          {
			    tempNode = (yyvsp[0].tree);
			    for (tempInteger=0;tempInteger<(yyvsp[-1].count);tempInteger++)
			      tempNode = makeNeg(tempNode);
			    (yyval.tree) = tempNode;
                          }
#line 5916 "parser.c"
    break;

  case 173: /* term: "~" subterm  */
#line 1272 "parser.y"
                          {
			    (yyval.tree) = makeEvalConst((yyvsp[0].tree));
                          }
#line 5924 "parser.c"
    break;

  case 174: /* term: term "*" subterm  */
#line 1276 "parser.y"
                          {
			    (yyval.tree) = makeMul((yyvsp[-2].tree), (yyvsp[0].tree));
                          }
#line 5932 "parser.c"
    break;

  case 175: /* term: term "/" subterm  */
#line 1280 "parser.y"
                          {
			    (yyval.tree) = makeDiv((yyvsp[-2].tree), (yyvsp[0].tree));
                          }
#line 5940 "parser.c"
    break;

  case 176: /* term: term "*" unaryplusminus subterm  */
#line 1284 "parser.y"
                          {
			    tempNode = (yyvsp[0].tree);
			    for (tempInteger=0;tempInteger<(yyvsp[-1].count);tempInteger++)
			      tempNode = makeNeg(tempNode);
			    (yyval.tree) = makeMul((yyvsp[-3].tree), tempNode);
                          }
#line 5951 "parser.c"
    break;

  case 177: /* term: term "/" unaryplusminus subterm  */
#line 1291 "parser.y"
                          {
			    tempNode = (yyvsp[0].tree);
			    for (tempInteger=0;tempInteger<(yyvsp[-1].count);tempInteger++)
			      tempNode = makeNeg(tempNode);
			    (yyval.tree) = makeDiv((yyvsp[-3].tree), tempNode);
                          }
#line 5962 "parser.c"
    break;

  case 178: /* term: term "*" "~" subterm  */
#line 1298 "parser.y"
                          {
			    (yyval.tree) = makeMul((yyvsp[-3].tree), makeEvalConst((yyvsp[0].tree)));
                          }
#line 5970 "parser.c"
    break;

  case 179: /* term: term "/" "~" subterm  */
#line 1302 "parser.y"
                          {
			    (yyval.tree) = makeDiv((yyvsp[-3].tree), makeEvalConst((yyvsp[0].tree)));
                          }
#line 5978 "parser.c"
    break;

  case 180: /* subterm: basicthing  */
#line 1308 "parser.y"
                          {
			    (yyval.tree) = (yyvsp[0].tree);
                          }
#line 5986 "parser.c"
    break;

  case 181: /* subterm: basicthing "^" subterm  */
#line 1312 "parser.y"
                          {
			    (yyval.tree) = makePow((yyvsp[-2].tree), (yyvsp[0].tree));
                          }
#line 5994 "parser.c"
    break;

  case 182: /* subterm: basicthing "^" unaryplusminus subterm  */
#line 1316 "parser.y"
                          {
			    tempNode = (yyvsp[0].tree);
			    for (tempInteger=0;tempInteger<(yyvsp[-1].count);tempInteger++)
			      tempNode = makeNeg(tempNode);
			    (yyval.tree) = makePow((yyvsp[-3].tree), tempNode);
                          }
#line 6005 "parser.c"
    break;

  case 183: /* subterm: basicthing "^" "~" subterm  */
#line 1323 "parser.y"
                          {
			    (yyval.tree) = makePow((yyvsp[-3].tree), makeEvalConst((yyvsp[0].tree)));
                          }
#line 6013 "parser.c"
    break;

  case 184: /* subterm: basicthing ".:" subterm  */
#line 1327 "parser.y"
                          {
			    (yyval.tree) = makePrepend((yyvsp[-2].tree), (yyvsp[0].tree));
			  }
#line 6021 "parser.c"
    break;

  case 185: /* subterm: basicthing ".:" "~" subterm  */
#line 1331 "parser.y"
                          {
			    (yyval.tree) = makePrepend((yyvsp[-3].tree), makeEvalConst((yyvsp[0].tree)));
			  }
#line 6029 "parser.c"
    break;

  case 186: /* basicthing: "on"  */
#line 1338 "parser.y"
                          {
			    (yyval.tree) = makeOn();
			  }
#line 6037 "parser.c"
    break;

  case 187: /* basicthing: "off"  */
#line 1342 "parser.y"
                          {
			    (yyval.tree) = makeOff();
			  }
#line 6045 "parser.c"
    break;

  case 188: /* basicthing: "dyadic"  */
#line 1346 "parser.y"
                          {
			    (yyval.tree) = makeDyadic();
			  }
#line 6053 "parser.c"
    break;

  case 189: /* basicthing: "powers"  */
#line 1350 "parser.y"
                          {
			    (yyval.tree) = makePowers();
			  }
#line 6061 "parser.c"
    break;

  case 190: /* basicthing: "binary"  */
#line 1354 "parser.y"
                          {
			    (yyval.tree) = makeBinaryThing();
			  }
#line 6069 "parser.c"
    break;

  case 191: /* basicthing: "hexadecimal"  */
#line 1358 "parser.y"
                          {
			    (yyval.tree) = makeHexadecimalThing();
			  }
#line 6077 "parser.c"
    break;

  case 192: /* basicthing: "file"  */
#line 1362 "parser.y"
                          {
			    (yyval.tree) = makeFile();
			  }
#line 6085 "parser.c"
    break;

  case 193: /* basicthing: "postscript"  */
#line 1366 "parser.y"
                          {
			    (yyval.tree) = makePostscript();
			  }
#line 6093 "parser.c"
    break;

  case 194: /* basicthing: "postscriptfile"  */
#line 1370 "parser.y"
                          {
			    (yyval.tree) = makePostscriptFile();
			  }
#line 6101 "parser.c"
    break;

  case 195: /* basicthing: "perturb"  */
#line 1374 "parser.y"
                          {
			    (yyval.tree) = makePerturb();
			  }
#line 6109 "parser.c"
    break;

  case 196: /* basicthing: "RD"  */
#line 1378 "parser.y"
                          {
			    (yyval.tree) = makeRoundDown();
			  }
#line 6117 "parser.c"
    break;

  case 197: /* basicthing: "RU"  */
#line 1382 "parser.y"
                          {
			    (yyval.tree) = makeRoundUp();
			  }
#line 6125 "parser.c"
    break;

  case 198: /* basicthing: "RZ"  */
#line 1386 "parser.y"
                          {
			    (yyval.tree) = makeRoundToZero();
			  }
#line 6133 "parser.c"
    break;

  case 199: /* basicthing: "RN"  */
#line 1390 "parser.y"
                          {
			    (yyval.tree) = makeRoundToNearest();
			  }
#line 6141 "parser.c"
    break;

  case 200: /* basicthing: "honorcoeffprec"  */
#line 1394 "parser.y"
                          {
			    (yyval.tree) = makeHonorCoeff();
			  }
#line 6149 "parser.c"
    break;

  case 201: /* basicthing: "true"  */
#line 1398 "parser.y"
                          {
			    (yyval.tree) = makeTrue();
			  }
#line 6157 "parser.c"
    break;

  case 202: /* basicthing: "void"  */
#line 1402 "parser.y"
                          {
			    (yyval.tree) = makeUnit();
			  }
#line 6165 "parser.c"
    break;

  case 203: /* basicthing: "false"  */
#line 1406 "parser.y"
                          {
			    (yyval.tree) = makeFalse();
			  }
#line 6173 "parser.c"
    break;

  case 204: /* basicthing: "default"  */
#line 1410 "parser.y"
                          {
			    (yyval.tree) = makeDefault();
			  }
#line 6181 "parser.c"
    break;

  case 205: /* basicthing: "decimal"  */
#line 1414 "parser.y"
                          {
			    (yyval.tree) = makeDecimal();
			  }
#line 6189 "parser.c"
    break;

  case 206: /* basicthing: "absolute"  */
#line 1418 "parser.y"
                          {
			    (yyval.tree) = makeAbsolute();
			  }
#line 6197 "parser.c"
    break;

  case 207: /* basicthing: "relative"  */
#line 1422 "parser.y"
                          {
			    (yyval.tree) = makeRelative();
			  }
#line 6205 "parser.c"
    break;

  case 208: /* basicthing: "fixed"  */
#line 1426 "parser.y"
                          {
			    (yyval.tree) = makeFixed();
			  }
#line 6213 "parser.c"
    break;

  case 209: /* basicthing: "floating"  */
#line 1430 "parser.y"
                          {
			    (yyval.tree) = makeFloating();
			  }
#line 6221 "parser.c"
    break;

  case 210: /* basicthing: "error"  */
#line 1434 "parser.y"
                          {
			    (yyval.tree) = makeError();
			  }
#line 6229 "parser.c"
    break;

  case 211: /* basicthing: "D"  */
#line 1438 "parser.y"
                          {
			    (yyval.tree) = makeDoubleSymbol();
			  }
#line 6237 "parser.c"
    break;

  case 212: /* basicthing: "SG"  */
#line 1442 "parser.y"
                          {
			    (yyval.tree) = makeSingleSymbol();
			  }
#line 6245 "parser.c"
    break;

  case 213: /* basicthing: "QD"  */
#line 1446 "parser.y"
                          {
			    (yyval.tree) = makeQuadSymbol();
			  }
#line 6253 "parser.c"
    break;

  case 214: /* basicthing: "HP"  */
#line 1450 "parser.y"
                          {
			    (yyval.tree) = makeHalfPrecisionSymbol();
			  }
#line 6261 "parser.c"
    break;

  case 215: /* basicthing: "DE"  */
#line 1454 "parser.y"
                          {
			    (yyval.tree) = makeDoubleextendedSymbol();
			  }
#line 6269 "parser.c"
    break;

  case 216: /* basicthing: "_x_"  */
#line 1458 "parser.y"
                          {
			    (yyval.tree) = makeVariable();
			  }
#line 6277 "parser.c"
    break;

  case 217: /* basicthing: "DD"  */
#line 1462 "parser.y"
                          {
			    (yyval.tree) = makeDoubleDoubleSymbol();
			  }
#line 6285 "parser.c"
    break;

  case 218: /* basicthing: "TD"  */
#line 1466 "parser.y"
                          {
			    (yyval.tree) = makeTripleDoubleSymbol();
			  }
#line 6293 "parser.c"
    break;

  case 219: /* basicthing: "character string"  */
#line 1470 "parser.y"
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
#line 6308 "parser.c"
    break;

  case 220: /* basicthing: constant  */
#line 1481 "parser.y"
                          {
			    (yyval.tree) = (yyvsp[0].tree);
			  }
#line 6316 "parser.c"
    break;

  case 221: /* basicthing: "identifier"  */
#line 1485 "parser.y"
                          {
			    (yyval.tree) = makeTableAccess((yyvsp[0].value));
			    safeFree((yyvsp[0].value));
			  }
#line 6325 "parser.c"
    break;

  case 222: /* basicthing: "isbound" "(" "identifier" ")"  */
#line 1490 "parser.y"
                          {
			    (yyval.tree) = makeIsBound((yyvsp[-1].value));
			    safeFree((yyvsp[-1].value));
			  }
#line 6334 "parser.c"
    break;

  case 223: /* basicthing: "identifier" "(" thinglist ")"  */
#line 1495 "parser.y"
                          {
			    (yyval.tree) = makeTableAccessWithSubstitute((yyvsp[-3].value), (yyvsp[-1].list));
			    safeFree((yyvsp[-3].value));
			  }
#line 6343 "parser.c"
    break;

  case 224: /* basicthing: "identifier" "(" ")"  */
#line 1500 "parser.y"
                          {
			    (yyval.tree) = makeTableAccessWithSubstitute((yyvsp[-2].value), NULL);
			    safeFree((yyvsp[-2].value));
			  }
#line 6352 "parser.c"
    break;

  case 225: /* basicthing: list  */
#line 1505 "parser.y"
                          {
			    (yyval.tree) = (yyvsp[0].tree);
			  }
#line 6360 "parser.c"
    break;

  case 226: /* basicthing: range  */
#line 1509 "parser.y"
                          {
			    (yyval.tree) = (yyvsp[0].tree);
			  }
#line 6368 "parser.c"
    break;

  case 227: /* basicthing: debound  */
#line 1513 "parser.y"
                          {
			    (yyval.tree) = (yyvsp[0].tree);
			  }
#line 6376 "parser.c"
    break;

  case 228: /* basicthing: headfunction  */
#line 1517 "parser.y"
                          {
			    (yyval.tree) = (yyvsp[0].tree);
			  }
#line 6384 "parser.c"
    break;

  case 229: /* basicthing: "(" thing ")"  */
#line 1521 "parser.y"
                          {
			    (yyval.tree) = (yyvsp[-1].tree);
			  }
#line 6392 "parser.c"
    break;

  case 230: /* basicthing: "{" structelementlist "}"  */
#line 1525 "parser.y"
                          {
			    (yyval.tree) = makeStructure((yyvsp[-1].list));
			  }
#line 6400 "parser.c"
    break;

  case 231: /* basicthing: statedereference  */
#line 1529 "parser.y"
                          {
			    (yyval.tree) = (yyvsp[0].tree);
			  }
#line 6408 "parser.c"
    break;

  case 232: /* basicthing: indexing  */
#line 1533 "parser.y"
                          {
			    (yyval.tree) = makeIndex((yyvsp[0].dblnode)->a, (yyvsp[0].dblnode)->b);
			    safeFree((yyvsp[0].dblnode));
			  }
#line 6417 "parser.c"
    break;

  case 233: /* basicthing: basicthing "." "identifier"  */
#line 1538 "parser.y"
                          {
			    (yyval.tree) = makeStructAccess((yyvsp[-2].tree),(yyvsp[0].value));
			    safeFree((yyvsp[0].value));
			  }
#line 6426 "parser.c"
    break;

  case 234: /* basicthing: basicthing "." "identifier" "(" ")"  */
#line 1543 "parser.y"
                          {
			    (yyval.tree) = makeApply(makeStructAccess((yyvsp[-4].tree),(yyvsp[-2].value)),addElement(NULL, makeUnit()));
			    safeFree((yyvsp[-2].value));
			  }
#line 6435 "parser.c"
    break;

  case 235: /* basicthing: basicthing "." "identifier" "(" thinglist ")"  */
#line 1548 "parser.y"
                          {
			    (yyval.tree) = makeApply(makeStructAccess((yyvsp[-5].tree),(yyvsp[-3].value)),(yyvsp[-1].list));
			    safeFree((yyvsp[-3].value));
			  }
#line 6444 "parser.c"
    break;

  case 236: /* basicthing: "(" thing ")" "(" thinglist ")"  */
#line 1553 "parser.y"
                          {
			    (yyval.tree) = makeApply((yyvsp[-4].tree),(yyvsp[-1].list));
			  }
#line 6452 "parser.c"
    break;

  case 237: /* basicthing: "(" thing ")" "(" ")"  */
#line 1557 "parser.y"
                          {
			    (yyval.tree) = makeApply((yyvsp[-3].tree),addElement(NULL,makeUnit()));
			  }
#line 6460 "parser.c"
    break;

  case 238: /* basicthing: "proc" procbody  */
#line 1561 "parser.y"
                          {
			    (yyval.tree) = (yyvsp[0].tree);
			  }
#line 6468 "parser.c"
    break;

  case 239: /* basicthing: "time" "(" command ")"  */
#line 1565 "parser.y"
                          {
			    (yyval.tree) = makeTime((yyvsp[-1].tree));
                          }
#line 6476 "parser.c"
    break;

  case 240: /* matchlist: matchelement  */
#line 1571 "parser.y"
                          {
			    (yyval.list) = addElement(NULL,(yyvsp[0].tree));
			  }
#line 6484 "parser.c"
    break;

  case 241: /* matchlist: matchelement matchlist  */
#line 1575 "parser.y"
                          {
			    (yyval.list) = addElement((yyvsp[0].list),(yyvsp[-1].tree));
			  }
#line 6492 "parser.c"
    break;

  case 242: /* matchelement: thing ":" beginsymbol variabledeclarationlist commandlist "return" thing ";" endsymbol  */
#line 1581 "parser.y"
                          {
			    (yyval.tree) = makeMatchElement((yyvsp[-8].tree),makeCommandList(concatChains((yyvsp[-5].list), (yyvsp[-4].list))),(yyvsp[-2].tree));
			  }
#line 6500 "parser.c"
    break;

  case 243: /* matchelement: thing ":" beginsymbol variabledeclarationlist commandlist endsymbol  */
#line 1585 "parser.y"
                          {
			    (yyval.tree) = makeMatchElement((yyvsp[-5].tree),makeCommandList(concatChains((yyvsp[-2].list), (yyvsp[-1].list))),makeUnit());
			  }
#line 6508 "parser.c"
    break;

  case 244: /* matchelement: thing ":" beginsymbol variabledeclarationlist "return" thing ";" endsymbol  */
#line 1589 "parser.y"
                          {
			    (yyval.tree) = makeMatchElement((yyvsp[-7].tree),makeCommandList((yyvsp[-4].list)),(yyvsp[-2].tree));
			  }
#line 6516 "parser.c"
    break;

  case 245: /* matchelement: thing ":" beginsymbol variabledeclarationlist endsymbol  */
#line 1593 "parser.y"
                          {
			    (yyval.tree) = makeMatchElement((yyvsp[-4].tree),makeCommandList((yyvsp[-1].list)),makeUnit());
			  }
#line 6524 "parser.c"
    break;

  case 246: /* matchelement: thing ":" beginsymbol commandlist "return" thing ";" endsymbol  */
#line 1597 "parser.y"
                          {
			    (yyval.tree) = makeMatchElement((yyvsp[-7].tree),makeCommandList((yyvsp[-4].list)),(yyvsp[-2].tree));
			  }
#line 6532 "parser.c"
    break;

  case 247: /* matchelement: thing ":" beginsymbol commandlist endsymbol  */
#line 1601 "parser.y"
                          {
			    (yyval.tree) = makeMatchElement((yyvsp[-4].tree),makeCommandList((yyvsp[-1].list)),makeUnit());
			  }
#line 6540 "parser.c"
    break;

  case 248: /* matchelement: thing ":" beginsymbol "return" thing ";" endsymbol  */
#line 1605 "parser.y"
                          {
			    (yyval.tree) = makeMatchElement((yyvsp[-6].tree), makeCommandList(addElement(NULL,makeNop())), (yyvsp[-2].tree));
			  }
#line 6548 "parser.c"
    break;

  case 249: /* matchelement: thing ":" beginsymbol endsymbol  */
#line 1609 "parser.y"
                          {
			    (yyval.tree) = makeMatchElement((yyvsp[-3].tree), makeCommandList(addElement(NULL,makeNop())), makeUnit());
			  }
#line 6556 "parser.c"
    break;

  case 250: /* matchelement: thing ":" "(" thing ")"  */
#line 1613 "parser.y"
                          {
			    (yyval.tree) = makeMatchElement((yyvsp[-4].tree), makeCommandList(addElement(NULL,makeNop())), (yyvsp[-1].tree));
			  }
#line 6564 "parser.c"
    break;

  case 251: /* constant: "decimal constant"  */
#line 1619 "parser.y"
                          {
			    (yyval.tree) = makeDecimalConstant((yyvsp[0].value));
			    safeFree((yyvsp[0].value));
			  }
#line 6573 "parser.c"
    break;

  case 252: /* constant: "interval"  */
#line 1624 "parser.y"
                          {
			    (yyval.tree) = makeMidpointConstant((yyvsp[0].value));
			    safeFree((yyvsp[0].value));
			  }
#line 6582 "parser.c"
    break;

  case 253: /* constant: "dyadic constant"  */
#line 1629 "parser.y"
                          {
			    (yyval.tree) = makeDyadicConstant((yyvsp[0].value));
			    safeFree((yyvsp[0].value));
			  }
#line 6591 "parser.c"
    break;

  case 254: /* constant: "constant in memory notation"  */
#line 1634 "parser.y"
                          {
			    (yyval.tree) = makeHexConstant((yyvsp[0].value));
			    safeFree((yyvsp[0].value));
			  }
#line 6600 "parser.c"
    break;

  case 255: /* constant: "hexadecimal constant"  */
#line 1639 "parser.y"
                          {
			    (yyval.tree) = makeHexadecimalConstant((yyvsp[0].value));
			    safeFree((yyvsp[0].value));
			  }
#line 6609 "parser.c"
    break;

  case 256: /* constant: "binary constant"  */
#line 1644 "parser.y"
                          {
			    (yyval.tree) = makeBinaryConstant((yyvsp[0].value));
			    safeFree((yyvsp[0].value));
			  }
#line 6618 "parser.c"
    break;

  case 257: /* constant: "pi"  */
#line 1649 "parser.y"
                          {
			    (yyval.tree) = makePi();
			  }
#line 6626 "parser.c"
    break;

  case 258: /* list: "[" "|" "|" "]"  */
#line 1657 "parser.y"
                          {
			    (yyval.tree) = makeEmptyList();
			  }
#line 6634 "parser.c"
    break;

  case 259: /* list: "[" "||" "]"  */
#line 1661 "parser.y"
                          {
			    (yyval.tree) = makeEmptyList();
			  }
#line 6642 "parser.c"
    break;

  case 260: /* list: "[" "|" simplelist "|" "]"  */
#line 1665 "parser.y"
                          {
			    (yyval.tree) = makeRevertedList((yyvsp[-2].list));
			  }
#line 6650 "parser.c"
    break;

  case 261: /* list: "[" "|" simplelist "..." "|" "]"  */
#line 1669 "parser.y"
                          {
			    (yyval.tree) = makeRevertedFinalEllipticList((yyvsp[-3].list));
			  }
#line 6658 "parser.c"
    break;

  case 262: /* simplelist: thing  */
#line 1675 "parser.y"
                          {
			    (yyval.list) = addElement(NULL, (yyvsp[0].tree));
			  }
#line 6666 "parser.c"
    break;

  case 263: /* simplelist: simplelist "," thing  */
#line 1679 "parser.y"
                          {
			    (yyval.list) = addElement((yyvsp[-2].list), (yyvsp[0].tree));
			  }
#line 6674 "parser.c"
    break;

  case 264: /* simplelist: simplelist "," "..." "," thing  */
#line 1683 "parser.y"
                          {
			    (yyval.list) = addElement(addElement((yyvsp[-4].list), makeElliptic()), (yyvsp[0].tree));
			  }
#line 6682 "parser.c"
    break;

  case 265: /* range: "[" thing "," thing "]"  */
#line 1690 "parser.y"
                          {
			    (yyval.tree) = makeRange((yyvsp[-3].tree), (yyvsp[-1].tree));
			  }
#line 6690 "parser.c"
    break;

  case 266: /* range: "[" thing ";" thing "]"  */
#line 1694 "parser.y"
                          {
			    (yyval.tree) = makeRange((yyvsp[-3].tree), (yyvsp[-1].tree));
			  }
#line 6698 "parser.c"
    break;

  case 267: /* range: "[" thing "]"  */
#line 1698 "parser.y"
                          {
			    (yyval.tree) = makeRange((yyvsp[-1].tree), copyThing((yyvsp[-1].tree)));
			  }
#line 6706 "parser.c"
    break;

  case 268: /* debound: "*<" thing ">*"  */
#line 1704 "parser.y"
                          {
			    (yyval.tree) = makeDeboundMax((yyvsp[-1].tree));
			  }
#line 6714 "parser.c"
    break;

  case 269: /* debound: "*<" thing ">."  */
#line 1708 "parser.y"
                          {
			    (yyval.tree) = makeDeboundMid((yyvsp[-1].tree));
			  }
#line 6722 "parser.c"
    break;

  case 270: /* debound: "*<" thing ">_"  */
#line 1712 "parser.y"
                          {
			    (yyval.tree) = makeDeboundMin((yyvsp[-1].tree));
			  }
#line 6730 "parser.c"
    break;

  case 271: /* debound: "sup" "(" thing ")"  */
#line 1716 "parser.y"
                          {
			    (yyval.tree) = makeDeboundMax((yyvsp[-1].tree));
			  }
#line 6738 "parser.c"
    break;

  case 272: /* debound: "mid" "(" thing ")"  */
#line 1720 "parser.y"
                          {
			    (yyval.tree) = makeDeboundMid((yyvsp[-1].tree));
			  }
#line 6746 "parser.c"
    break;

  case 273: /* debound: "inf" "(" thing ")"  */
#line 1724 "parser.y"
                          {
			    (yyval.tree) = makeDeboundMin((yyvsp[-1].tree));
			  }
#line 6754 "parser.c"
    break;

  case 274: /* headfunction: "diff" "(" thing ")"  */
#line 1730 "parser.y"
                          {
			    (yyval.tree) = makeDiff((yyvsp[-1].tree));
			  }
#line 6762 "parser.c"
    break;

  case 275: /* headfunction: "dirtysimplify" "(" thing ")"  */
#line 1734 "parser.y"
                          {
			    (yyval.tree) = makeDirtysimplify((yyvsp[-1].tree));
			  }
#line 6770 "parser.c"
    break;

  case 276: /* headfunction: "bashevaluate" "(" thing ")"  */
#line 1738 "parser.y"
                          {
			    (yyval.tree) = makeBashevaluate(addElement(NULL,(yyvsp[-1].tree)));
			  }
#line 6778 "parser.c"
    break;

  case 277: /* headfunction: "getsuppressedmessages" "(" ")"  */
#line 1742 "parser.y"
                          {
			    (yyval.tree) = makeGetSuppressedMessages();
			  }
#line 6786 "parser.c"
    break;

  case 278: /* headfunction: "getbacktrace" "(" ")"  */
#line 1746 "parser.y"
                          {
			    (yyval.tree) = makeGetBacktrace();
			  }
#line 6794 "parser.c"
    break;

  case 279: /* headfunction: "bashevaluate" "(" thing "," thing ")"  */
#line 1750 "parser.y"
                          {
			    (yyval.tree) = makeBashevaluate(addElement(addElement(NULL,(yyvsp[-1].tree)),(yyvsp[-3].tree)));
			  }
#line 6802 "parser.c"
    break;

  case 280: /* headfunction: "remez" "(" thing "," thing "," thinglist ")"  */
#line 1754 "parser.y"
                          {
			    (yyval.tree) = makeRemez(addElement(addElement((yyvsp[-1].list), (yyvsp[-3].tree)), (yyvsp[-5].tree)));
			  }
#line 6810 "parser.c"
    break;

  case 281: /* headfunction: "annotatefunction" "(" thing "," thing "," thing "," thinglist ")"  */
#line 1758 "parser.y"
                          {
			    (yyval.tree) = makeAnnotateFunction(addElement(addElement(addElement((yyvsp[-1].list), (yyvsp[-3].tree)), (yyvsp[-5].tree)), (yyvsp[-7].tree)));
			  }
#line 6818 "parser.c"
    break;

  case 282: /* headfunction: "bind" "(" thing "," "identifier" "," thing ")"  */
#line 1762 "parser.y"
                          {
			    (yyval.tree) = makeBind((yyvsp[-5].tree), (yyvsp[-3].value), (yyvsp[-1].tree));
			    safeFree((yyvsp[-3].value));
			  }
#line 6827 "parser.c"
    break;

  case 283: /* headfunction: "min" "(" thinglist ")"  */
#line 1767 "parser.y"
                          {
			    (yyval.tree) = makeMin((yyvsp[-1].list));
			  }
#line 6835 "parser.c"
    break;

  case 284: /* headfunction: "max" "(" thinglist ")"  */
#line 1771 "parser.y"
                          {
			    (yyval.tree) = makeMax((yyvsp[-1].list));
			  }
#line 6843 "parser.c"
    break;

  case 285: /* headfunction: "fpminimax" "(" thing "," thing "," thing "," thinglist ")"  */
#line 1775 "parser.y"
                          {
			    (yyval.tree) = makeFPminimax(addElement(addElement(addElement((yyvsp[-1].list), (yyvsp[-3].tree)), (yyvsp[-5].tree)), (yyvsp[-7].tree)));
			  }
#line 6851 "parser.c"
    break;

  case 286: /* headfunction: "horner" "(" thing ")"  */
#line 1779 "parser.y"
                          {
			    (yyval.tree) = makeHorner((yyvsp[-1].tree));
			  }
#line 6859 "parser.c"
    break;

  case 287: /* headfunction: "canonical" "(" thing ")"  */
#line 1783 "parser.y"
                          {
			    (yyval.tree) = makeCanonicalThing((yyvsp[-1].tree));
			  }
#line 6867 "parser.c"
    break;

  case 288: /* headfunction: "expand" "(" thing ")"  */
#line 1787 "parser.y"
                          {
			    (yyval.tree) = makeExpand((yyvsp[-1].tree));
			  }
#line 6875 "parser.c"
    break;

  case 289: /* headfunction: "simplify" "(" thing ")"  */
#line 1791 "parser.y"
                          {
			    (yyval.tree) = makeSimplifySafe((yyvsp[-1].tree));
			  }
#line 6883 "parser.c"
    break;

  case 290: /* headfunction: "taylor" "(" thing "," thing "," thing ")"  */
#line 1795 "parser.y"
                          {
			    (yyval.tree) = makeTaylor((yyvsp[-5].tree), (yyvsp[-3].tree), (yyvsp[-1].tree));
			  }
#line 6891 "parser.c"
    break;

  case 291: /* headfunction: "taylorform" "(" thing "," thing "," thinglist ")"  */
#line 1799 "parser.y"
                          {
                            (yyval.tree) = makeTaylorform(addElement(addElement((yyvsp[-1].list), (yyvsp[-3].tree)), (yyvsp[-5].tree)));
			  }
#line 6899 "parser.c"
    break;

  case 292: /* headfunction: "chebyshevform" "(" thing "," thing "," thing ")"  */
#line 1803 "parser.y"
                          {
                            (yyval.tree) = makeChebyshevform(addElement(addElement(addElement(NULL, (yyvsp[-1].tree)), (yyvsp[-3].tree)), (yyvsp[-5].tree)));
			  }
#line 6907 "parser.c"
    break;

  case 293: /* headfunction: "autodiff" "(" thing "," thing "," thing ")"  */
#line 1807 "parser.y"
                          {
                            (yyval.tree) = makeAutodiff(addElement(addElement(addElement(NULL, (yyvsp[-1].tree)), (yyvsp[-3].tree)), (yyvsp[-5].tree)));
			  }
#line 6915 "parser.c"
    break;

  case 294: /* headfunction: "degree" "(" thing ")"  */
#line 1811 "parser.y"
                          {
			    (yyval.tree) = makeDegree((yyvsp[-1].tree));
			  }
#line 6923 "parser.c"
    break;

  case 295: /* headfunction: "numerator" "(" thing ")"  */
#line 1815 "parser.y"
                          {
			    (yyval.tree) = makeNumerator((yyvsp[-1].tree));
			  }
#line 6931 "parser.c"
    break;

  case 296: /* headfunction: "denominator" "(" thing ")"  */
#line 1819 "parser.y"
                          {
			    (yyval.tree) = makeDenominator((yyvsp[-1].tree));
			  }
#line 6939 "parser.c"
    break;

  case 297: /* headfunction: "substitute" "(" thing "," thing ")"  */
#line 1823 "parser.y"
                          {
			    (yyval.tree) = makeSubstitute((yyvsp[-3].tree), (yyvsp[-1].tree));
			  }
#line 6947 "parser.c"
    break;

  case 298: /* headfunction: "composepolynomials" "(" thing "," thing ")"  */
#line 1827 "parser.y"
                          {
			    (yyval.tree) = makeComposePolynomials((yyvsp[-3].tree), (yyvsp[-1].tree));
			  }
#line 6955 "parser.c"
    break;

  case 299: /* headfunction: "bezout" "(" thing "," thing ")"  */
#line 1831 "parser.y"
                          {
			    (yyval.tree) = makeBezout((yyvsp[-3].tree), (yyvsp[-1].tree));
			  }
#line 6963 "parser.c"
    break;

  case 300: /* headfunction: "coeff" "(" thing "," thing ")"  */
#line 1835 "parser.y"
                          {
			    (yyval.tree) = makeCoeff((yyvsp[-3].tree), (yyvsp[-1].tree));
			  }
#line 6971 "parser.c"
    break;

  case 301: /* headfunction: "subpoly" "(" thing "," thing ")"  */
#line 1839 "parser.y"
                          {
			    (yyval.tree) = makeSubpoly((yyvsp[-3].tree), (yyvsp[-1].tree));
			  }
#line 6979 "parser.c"
    break;

  case 302: /* headfunction: "roundcoefficients" "(" thing "," thing ")"  */
#line 1843 "parser.y"
                          {
			    (yyval.tree) = makeRoundcoefficients((yyvsp[-3].tree), (yyvsp[-1].tree));
			  }
#line 6987 "parser.c"
    break;

  case 303: /* headfunction: "rationalapprox" "(" thing "," thing ")"  */
#line 1847 "parser.y"
                          {
			    (yyval.tree) = makeRationalapprox((yyvsp[-3].tree), (yyvsp[-1].tree));
			  }
#line 6995 "parser.c"
    break;

  case 304: /* headfunction: "accurateinfnorm" "(" thing "," thing "," thinglist ")"  */
#line 1851 "parser.y"
                          {
			    (yyval.tree) = makeAccurateInfnorm(addElement(addElement((yyvsp[-1].list), (yyvsp[-3].tree)), (yyvsp[-5].tree)));
			  }
#line 7003 "parser.c"
    break;

  case 305: /* headfunction: "round" "(" thing "," thing "," thing ")"  */
#line 1855 "parser.y"
                          {
			    (yyval.tree) = makeRoundToFormat((yyvsp[-5].tree), (yyvsp[-3].tree), (yyvsp[-1].tree));
			  }
#line 7011 "parser.c"
    break;

  case 306: /* headfunction: "evaluate" "(" thing "," thing ")"  */
#line 1859 "parser.y"
                          {
			    (yyval.tree) = makeEvaluate((yyvsp[-3].tree), (yyvsp[-1].tree));
			  }
#line 7019 "parser.c"
    break;

  case 307: /* headfunction: "parse" "(" thing ")"  */
#line 1863 "parser.y"
                          {
			    (yyval.tree) = makeParse((yyvsp[-1].tree));
			  }
#line 7027 "parser.c"
    break;

  case 308: /* headfunction: "readxml" "(" thing ")"  */
#line 1867 "parser.y"
                          {
			    (yyval.tree) = makeReadXml((yyvsp[-1].tree));
			  }
#line 7035 "parser.c"
    break;

  case 309: /* headfunction: "infnorm" "(" thing "," thinglist ")"  */
#line 1871 "parser.y"
                          {
			    (yyval.tree) = makeInfnorm(addElement((yyvsp[-1].list), (yyvsp[-3].tree)));
			  }
#line 7043 "parser.c"
    break;

  case 310: /* headfunction: "supnorm" "(" thing "," thing "," thing "," thing "," thing ")"  */
#line 1875 "parser.y"
                          {
			    (yyval.tree) = makeSupnorm(addElement(addElement(addElement(addElement(addElement(NULL,(yyvsp[-1].tree)),(yyvsp[-3].tree)),(yyvsp[-5].tree)),(yyvsp[-7].tree)),(yyvsp[-9].tree)));
			  }
#line 7051 "parser.c"
    break;

  case 311: /* headfunction: "findzeros" "(" thing "," thing ")"  */
#line 1879 "parser.y"
                          {
			    (yyval.tree) = makeFindZeros((yyvsp[-3].tree), (yyvsp[-1].tree));
			  }
#line 7059 "parser.c"
    break;

  case 312: /* headfunction: "fpfindzeros" "(" thing "," thing ")"  */
#line 1883 "parser.y"
                          {
			    (yyval.tree) = makeFPFindZeros((yyvsp[-3].tree), (yyvsp[-1].tree));
			  }
#line 7067 "parser.c"
    break;

  case 313: /* headfunction: "dirtyinfnorm" "(" thing "," thing ")"  */
#line 1887 "parser.y"
                          {
			    (yyval.tree) = makeDirtyInfnorm((yyvsp[-3].tree), (yyvsp[-1].tree));
			  }
#line 7075 "parser.c"
    break;

  case 314: /* headfunction: "gcd" "(" thing "," thing ")"  */
#line 1891 "parser.y"
                          {
			    (yyval.tree) = makeGcd((yyvsp[-3].tree), (yyvsp[-1].tree));
			  }
#line 7083 "parser.c"
    break;

  case 315: /* headfunction: "div" "(" thing "," thing ")"  */
#line 1895 "parser.y"
                          {
			    (yyval.tree) = makeEuclDiv((yyvsp[-3].tree), (yyvsp[-1].tree));
			  }
#line 7091 "parser.c"
    break;

  case 316: /* headfunction: "mod" "(" thing "," thing ")"  */
#line 1899 "parser.y"
                          {
			    (yyval.tree) = makeEuclMod((yyvsp[-3].tree), (yyvsp[-1].tree));
			  }
#line 7099 "parser.c"
    break;

  case 317: /* headfunction: "numberroots" "(" thing "," thing ")"  */
#line 1903 "parser.y"
                          {
			    (yyval.tree) = makeNumberRoots((yyvsp[-3].tree), (yyvsp[-1].tree));
			  }
#line 7107 "parser.c"
    break;

  case 318: /* headfunction: "integral" "(" thing "," thing ")"  */
#line 1907 "parser.y"
                          {
			    (yyval.tree) = makeIntegral((yyvsp[-3].tree), (yyvsp[-1].tree));
			  }
#line 7115 "parser.c"
    break;

  case 319: /* headfunction: "dirtyintegral" "(" thing "," thing ")"  */
#line 1911 "parser.y"
                          {
			    (yyval.tree) = makeDirtyIntegral((yyvsp[-3].tree), (yyvsp[-1].tree));
			  }
#line 7123 "parser.c"
    break;

  case 320: /* headfunction: "implementpoly" "(" thing "," thing "," thing "," thing "," thing "," thinglist ")"  */
#line 1915 "parser.y"
                          {
			    (yyval.tree) = makeImplementPoly(addElement(addElement(addElement(addElement(addElement((yyvsp[-1].list), (yyvsp[-3].tree)), (yyvsp[-5].tree)), (yyvsp[-7].tree)), (yyvsp[-9].tree)), (yyvsp[-11].tree)));
			  }
#line 7131 "parser.c"
    break;

  case 321: /* headfunction: "interpolate" "(" thing "," thinglist ")"  */
#line 1919 "parser.y"
                          {
			    (yyval.tree) = makeInterpolate(addElement((yyvsp[-1].list), (yyvsp[-3].tree)));
			  }
#line 7139 "parser.c"
    break;

  case 322: /* headfunction: "checkinfnorm" "(" thing "," thing "," thing ")"  */
#line 1923 "parser.y"
                          {
			    (yyval.tree) = makeCheckInfnorm((yyvsp[-5].tree), (yyvsp[-3].tree), (yyvsp[-1].tree));
			  }
#line 7147 "parser.c"
    break;

  case 323: /* headfunction: "zerodenominators" "(" thing "," thing ")"  */
#line 1927 "parser.y"
                          {
			    (yyval.tree) = makeZeroDenominators((yyvsp[-3].tree), (yyvsp[-1].tree));
			  }
#line 7155 "parser.c"
    break;

  case 324: /* headfunction: "isevaluable" "(" thing "," thing ")"  */
#line 1931 "parser.y"
                          {
			    (yyval.tree) = makeIsEvaluable((yyvsp[-3].tree), (yyvsp[-1].tree));
			  }
#line 7163 "parser.c"
    break;

  case 325: /* headfunction: "searchgal" "(" thinglist ")"  */
#line 1935 "parser.y"
                          {
			    (yyval.tree) = makeSearchGal((yyvsp[-1].list));
			  }
#line 7171 "parser.c"
    break;

  case 326: /* headfunction: "guessdegree" "(" thing "," thing "," thinglist ")"  */
#line 1939 "parser.y"
                          {
			    (yyval.tree) = makeGuessDegree(addElement(addElement((yyvsp[-1].list), (yyvsp[-3].tree)), (yyvsp[-5].tree)));
			  }
#line 7179 "parser.c"
    break;

  case 327: /* headfunction: "dirtyfindzeros" "(" thing "," thing ")"  */
#line 1943 "parser.y"
                          {
			    (yyval.tree) = makeDirtyFindZeros((yyvsp[-3].tree), (yyvsp[-1].tree));
			  }
#line 7187 "parser.c"
    break;

  case 328: /* headfunction: "head" "(" thing ")"  */
#line 1947 "parser.y"
                          {
			    (yyval.tree) = makeHead((yyvsp[-1].tree));
			  }
#line 7195 "parser.c"
    break;

  case 329: /* headfunction: "roundcorrectly" "(" thing ")"  */
#line 1951 "parser.y"
                          {
			    (yyval.tree) = makeRoundCorrectly((yyvsp[-1].tree));
			  }
#line 7203 "parser.c"
    break;

  case 330: /* headfunction: "readfile" "(" thing ")"  */
#line 1955 "parser.y"
                          {
			    (yyval.tree) = makeReadFile((yyvsp[-1].tree));
			  }
#line 7211 "parser.c"
    break;

  case 331: /* headfunction: "revert" "(" thing ")"  */
#line 1959 "parser.y"
                          {
			    (yyval.tree) = makeRevert((yyvsp[-1].tree));
			  }
#line 7219 "parser.c"
    break;

  case 332: /* headfunction: "sort" "(" thing ")"  */
#line 1963 "parser.y"
                          {
			    (yyval.tree) = makeSort((yyvsp[-1].tree));
			  }
#line 7227 "parser.c"
    break;

  case 333: /* headfunction: "mantissa" "(" thing ")"  */
#line 1967 "parser.y"
                          {
			    (yyval.tree) = makeMantissa((yyvsp[-1].tree));
			  }
#line 7235 "parser.c"
    break;

  case 334: /* headfunction: "exponent" "(" thing ")"  */
#line 1971 "parser.y"
                          {
			    (yyval.tree) = makeExponent((yyvsp[-1].tree));
			  }
#line 7243 "parser.c"
    break;

  case 335: /* headfunction: "precision" "(" thing ")"  */
#line 1975 "parser.y"
                          {
			    (yyval.tree) = makePrecision((yyvsp[-1].tree));
			  }
#line 7251 "parser.c"
    break;

  case 336: /* headfunction: "tail" "(" thing ")"  */
#line 1979 "parser.y"
                          {
			    (yyval.tree) = makeTail((yyvsp[-1].tree));
			  }
#line 7259 "parser.c"
    break;

  case 337: /* headfunction: "sqrt" "(" thing ")"  */
#line 1983 "parser.y"
                          {
			    (yyval.tree) = makeSqrt((yyvsp[-1].tree));
			  }
#line 7267 "parser.c"
    break;

  case 338: /* headfunction: "exp" "(" thing ")"  */
#line 1987 "parser.y"
                          {
			    (yyval.tree) = makeExp((yyvsp[-1].tree));
			  }
#line 7275 "parser.c"
    break;

  case 339: /* headfunction: "_x_" "(" thing ")"  */
#line 1991 "parser.y"
                          {
			    (yyval.tree) = makeApply(makeVariable(),addElement(NULL,(yyvsp[-1].tree)));
			  }
#line 7283 "parser.c"
    break;

  case 340: /* headfunction: "function" "(" thing ")"  */
#line 1995 "parser.y"
                          {
			    (yyval.tree) = makeProcedureFunction((yyvsp[-1].tree));
			  }
#line 7291 "parser.c"
    break;

  case 341: /* headfunction: "function" "(" thing "," thing ")"  */
#line 1999 "parser.y"
                          {
			    (yyval.tree) = makeSubstitute(makeProcedureFunction((yyvsp[-3].tree)),(yyvsp[-1].tree));
			  }
#line 7299 "parser.c"
    break;

  case 342: /* headfunction: "log" "(" thing ")"  */
#line 2003 "parser.y"
                          {
			    (yyval.tree) = makeLog((yyvsp[-1].tree));
			  }
#line 7307 "parser.c"
    break;

  case 343: /* headfunction: "log2" "(" thing ")"  */
#line 2007 "parser.y"
                          {
			    (yyval.tree) = makeLog2((yyvsp[-1].tree));
			  }
#line 7315 "parser.c"
    break;

  case 344: /* headfunction: "log10" "(" thing ")"  */
#line 2011 "parser.y"
                          {
			    (yyval.tree) = makeLog10((yyvsp[-1].tree));
			  }
#line 7323 "parser.c"
    break;

  case 345: /* headfunction: "sin" "(" thing ")"  */
#line 2015 "parser.y"
                          {
			    (yyval.tree) = makeSin((yyvsp[-1].tree));
			  }
#line 7331 "parser.c"
    break;

  case 346: /* headfunction: "cos" "(" thing ")"  */
#line 2019 "parser.y"
                          {
			    (yyval.tree) = makeCos((yyvsp[-1].tree));
			  }
#line 7339 "parser.c"
    break;

  case 347: /* headfunction: "tan" "(" thing ")"  */
#line 2023 "parser.y"
                          {
			    (yyval.tree) = makeTan((yyvsp[-1].tree));
			  }
#line 7347 "parser.c"
    break;

  case 348: /* headfunction: "asin" "(" thing ")"  */
#line 2027 "parser.y"
                          {
			    (yyval.tree) = makeAsin((yyvsp[-1].tree));
			  }
#line 7355 "parser.c"
    break;

  case 349: /* headfunction: "acos" "(" thing ")"  */
#line 2031 "parser.y"
                          {
			    (yyval.tree) = makeAcos((yyvsp[-1].tree));
			  }
#line 7363 "parser.c"
    break;

  case 350: /* headfunction: "atan" "(" thing ")"  */
#line 2035 "parser.y"
                          {
			    (yyval.tree) = makeAtan((yyvsp[-1].tree));
			  }
#line 7371 "parser.c"
    break;

  case 351: /* headfunction: "sinh" "(" thing ")"  */
#line 2039 "parser.y"
                          {
			    (yyval.tree) = makeSinh((yyvsp[-1].tree));
			  }
#line 7379 "parser.c"
    break;

  case 352: /* headfunction: "cosh" "(" thing ")"  */
#line 2043 "parser.y"
                          {
			    (yyval.tree) = makeCosh((yyvsp[-1].tree));
			  }
#line 7387 "parser.c"
    break;

  case 353: /* headfunction: "tanh" "(" thing ")"  */
#line 2047 "parser.y"
                          {
			    (yyval.tree) = makeTanh((yyvsp[-1].tree));
			  }
#line 7395 "parser.c"
    break;

  case 354: /* headfunction: "asinh" "(" thing ")"  */
#line 2051 "parser.y"
                          {
			    (yyval.tree) = makeAsinh((yyvsp[-1].tree));
			  }
#line 7403 "parser.c"
    break;

  case 355: /* headfunction: "acosh" "(" thing ")"  */
#line 2055 "parser.y"
                          {
			    (yyval.tree) = makeAcosh((yyvsp[-1].tree));
			  }
#line 7411 "parser.c"
    break;

  case 356: /* headfunction: "atanh" "(" thing ")"  */
#line 2059 "parser.y"
                          {
			    (yyval.tree) = makeAtanh((yyvsp[-1].tree));
			  }
#line 7419 "parser.c"
    break;

  case 357: /* headfunction: "abs" "(" thing ")"  */
#line 2063 "parser.y"
                          {
			    (yyval.tree) = makeAbs((yyvsp[-1].tree));
			  }
#line 7427 "parser.c"
    break;

  case 358: /* headfunction: "erf" "(" thing ")"  */
#line 2067 "parser.y"
                          {
			    (yyval.tree) = makeErf((yyvsp[-1].tree));
			  }
#line 7435 "parser.c"
    break;

  case 359: /* headfunction: "erfc" "(" thing ")"  */
#line 2071 "parser.y"
                          {
			    (yyval.tree) = makeErfc((yyvsp[-1].tree));
			  }
#line 7443 "parser.c"
    break;

  case 360: /* headfunction: "log1p" "(" thing ")"  */
#line 2075 "parser.y"
                          {
			    (yyval.tree) = makeLog1p((yyvsp[-1].tree));
			  }
#line 7451 "parser.c"
    break;

  case 361: /* headfunction: "expm1" "(" thing ")"  */
#line 2079 "parser.y"
                          {
			    (yyval.tree) = makeExpm1((yyvsp[-1].tree));
			  }
#line 7459 "parser.c"
    break;

  case 362: /* headfunction: "D" "(" thing ")"  */
#line 2083 "parser.y"
                          {
			    (yyval.tree) = makeDouble((yyvsp[-1].tree));
			  }
#line 7467 "parser.c"
    break;

  case 363: /* headfunction: "SG" "(" thing ")"  */
#line 2087 "parser.y"
                          {
			    (yyval.tree) = makeSingle((yyvsp[-1].tree));
			  }
#line 7475 "parser.c"
    break;

  case 364: /* headfunction: "QD" "(" thing ")"  */
#line 2091 "parser.y"
                          {
			    (yyval.tree) = makeQuad((yyvsp[-1].tree));
			  }
#line 7483 "parser.c"
    break;

  case 365: /* headfunction: "HP" "(" thing ")"  */
#line 2095 "parser.y"
                          {
			    (yyval.tree) = makeHalfPrecision((yyvsp[-1].tree));
			  }
#line 7491 "parser.c"
    break;

  case 366: /* headfunction: "DD" "(" thing ")"  */
#line 2099 "parser.y"
                          {
			    (yyval.tree) = makeDoubledouble((yyvsp[-1].tree));
			  }
#line 7499 "parser.c"
    break;

  case 367: /* headfunction: "TD" "(" thing ")"  */
#line 2103 "parser.y"
                          {
			    (yyval.tree) = makeTripledouble((yyvsp[-1].tree));
			  }
#line 7507 "parser.c"
    break;

  case 368: /* headfunction: "DE" "(" thing ")"  */
#line 2107 "parser.y"
                          {
			    (yyval.tree) = makeDoubleextended((yyvsp[-1].tree));
			  }
#line 7515 "parser.c"
    break;

  case 369: /* headfunction: "ceil" "(" thing ")"  */
#line 2111 "parser.y"
                          {
			    (yyval.tree) = makeCeil((yyvsp[-1].tree));
			  }
#line 7523 "parser.c"
    break;

  case 370: /* headfunction: "floor" "(" thing ")"  */
#line 2115 "parser.y"
                          {
			    (yyval.tree) = makeFloor((yyvsp[-1].tree));
			  }
#line 7531 "parser.c"
    break;

  case 371: /* headfunction: "nearestint" "(" thing ")"  */
#line 2119 "parser.y"
                          {
			    (yyval.tree) = makeNearestInt((yyvsp[-1].tree));
			  }
#line 7539 "parser.c"
    break;

  case 372: /* headfunction: "length" "(" thing ")"  */
#line 2123 "parser.y"
                          {
			    (yyval.tree) = makeLength((yyvsp[-1].tree));
			  }
#line 7547 "parser.c"
    break;

  case 373: /* headfunction: "objectname" "(" thing ")"  */
#line 2127 "parser.y"
                          {
			    (yyval.tree) = makeObjectName((yyvsp[-1].tree));
			  }
#line 7555 "parser.c"
    break;

  case 374: /* egalquestionmark: "=" "?"  */
#line 2133 "parser.y"
                          {
			    (yyval.other) = NULL;
			  }
#line 7563 "parser.c"
    break;

  case 375: /* egalquestionmark: %empty  */
#line 2137 "parser.y"
                          {
			    (yyval.other) = NULL;
			  }
#line 7571 "parser.c"
    break;

  case 376: /* statedereference: "prec" egalquestionmark  */
#line 2143 "parser.y"
                          {
			    (yyval.tree) = makePrecDeref();
			  }
#line 7579 "parser.c"
    break;

  case 377: /* statedereference: "points" egalquestionmark  */
#line 2147 "parser.y"
                          {
			    (yyval.tree) = makePointsDeref();
			  }
#line 7587 "parser.c"
    break;

  case 378: /* statedereference: "diam" egalquestionmark  */
#line 2151 "parser.y"
                          {
			    (yyval.tree) = makeDiamDeref();
			  }
#line 7595 "parser.c"
    break;

  case 379: /* statedereference: "display" egalquestionmark  */
#line 2155 "parser.y"
                          {
			    (yyval.tree) = makeDisplayDeref();
			  }
#line 7603 "parser.c"
    break;

  case 380: /* statedereference: "verbosity" egalquestionmark  */
#line 2159 "parser.y"
                          {
			    (yyval.tree) = makeVerbosityDeref();
			  }
#line 7611 "parser.c"
    break;

  case 381: /* statedereference: "showmessagenumbers" egalquestionmark  */
#line 2163 "parser.y"
                          {
			    (yyval.tree) = makeShowMessageNumbersDeref();
			  }
#line 7619 "parser.c"
    break;

  case 382: /* statedereference: "canonical" egalquestionmark  */
#line 2167 "parser.y"
                          {
			    (yyval.tree) = makeCanonicalDeref();
			  }
#line 7627 "parser.c"
    break;

  case 383: /* statedereference: "autosimplify" egalquestionmark  */
#line 2171 "parser.y"
                          {
			    (yyval.tree) = makeAutoSimplifyDeref();
			  }
#line 7635 "parser.c"
    break;

  case 384: /* statedereference: "taylorrecursions" egalquestionmark  */
#line 2175 "parser.y"
                          {
			    (yyval.tree) = makeTaylorRecursDeref();
			  }
#line 7643 "parser.c"
    break;

  case 385: /* statedereference: "timing" egalquestionmark  */
#line 2179 "parser.y"
                          {
			    (yyval.tree) = makeTimingDeref();
			  }
#line 7651 "parser.c"
    break;

  case 386: /* statedereference: "fullparentheses" egalquestionmark  */
#line 2183 "parser.y"
                          {
			    (yyval.tree) = makeFullParenDeref();
			  }
#line 7659 "parser.c"
    break;

  case 387: /* statedereference: "midpointmode" egalquestionmark  */
#line 2187 "parser.y"
                          {
			    (yyval.tree) = makeMidpointDeref();
			  }
#line 7667 "parser.c"
    break;

  case 388: /* statedereference: "dieonerrormode" egalquestionmark  */
#line 2191 "parser.y"
                          {
			    (yyval.tree) = makeDieOnErrorDeref();
			  }
#line 7675 "parser.c"
    break;

  case 389: /* statedereference: "rationalmode" egalquestionmark  */
#line 2195 "parser.y"
                          {
			    (yyval.tree) = makeRationalModeDeref();
			  }
#line 7683 "parser.c"
    break;

  case 390: /* statedereference: "roundingwarnings" egalquestionmark  */
#line 2199 "parser.y"
                          {
			    (yyval.tree) = makeSuppressWarningsDeref();
			  }
#line 7691 "parser.c"
    break;

  case 391: /* statedereference: "hopitalrecursions" egalquestionmark  */
#line 2203 "parser.y"
                          {
			    (yyval.tree) = makeHopitalRecursDeref();
			  }
#line 7699 "parser.c"
    break;

  case 392: /* externalproctype: "constant"  */
#line 2209 "parser.y"
                          {
			    tempIntPtr = (int *) safeMalloc(sizeof(int));
			    *tempIntPtr = CONSTANT_TYPE;
			    (yyval.integerval) = tempIntPtr;
			  }
#line 7709 "parser.c"
    break;

  case 393: /* externalproctype: "function"  */
#line 2215 "parser.y"
                          {
			    tempIntPtr = (int *) safeMalloc(sizeof(int));
			    *tempIntPtr = FUNCTION_TYPE;
			    (yyval.integerval) = tempIntPtr;
			  }
#line 7719 "parser.c"
    break;

  case 394: /* externalproctype: "object"  */
#line 2221 "parser.y"
                          {
			    tempIntPtr = (int *) safeMalloc(sizeof(int));
			    *tempIntPtr = OBJECT_TYPE;
			    (yyval.integerval) = tempIntPtr;
			  }
#line 7729 "parser.c"
    break;

  case 395: /* externalproctype: "range"  */
#line 2227 "parser.y"
                          {
			    tempIntPtr = (int *) safeMalloc(sizeof(int));
			    *tempIntPtr = RANGE_TYPE;
			    (yyval.integerval) = tempIntPtr;
			  }
#line 7739 "parser.c"
    break;

  case 396: /* externalproctype: "integer"  */
#line 2233 "parser.y"
                          {
			    tempIntPtr = (int *) safeMalloc(sizeof(int));
			    *tempIntPtr = INTEGER_TYPE;
			    (yyval.integerval) = tempIntPtr;
			  }
#line 7749 "parser.c"
    break;

  case 397: /* externalproctype: "string"  */
#line 2239 "parser.y"
                          {
			    tempIntPtr = (int *) safeMalloc(sizeof(int));
			    *tempIntPtr = STRING_TYPE;
			    (yyval.integerval) = tempIntPtr;
			  }
#line 7759 "parser.c"
    break;

  case 398: /* externalproctype: "boolean"  */
#line 2245 "parser.y"
                          {
			    tempIntPtr = (int *) safeMalloc(sizeof(int));
			    *tempIntPtr = BOOLEAN_TYPE;
			    (yyval.integerval) = tempIntPtr;
			  }
#line 7769 "parser.c"
    break;

  case 399: /* externalproctype: "list" "of" "constant"  */
#line 2251 "parser.y"
                          {
			    tempIntPtr = (int *) safeMalloc(sizeof(int));
			    *tempIntPtr = CONSTANT_LIST_TYPE;
			    (yyval.integerval) = tempIntPtr;
			  }
#line 7779 "parser.c"
    break;

  case 400: /* externalproctype: "list" "of" "function"  */
#line 2257 "parser.y"
                          {
			    tempIntPtr = (int *) safeMalloc(sizeof(int));
			    *tempIntPtr = FUNCTION_LIST_TYPE;
			    (yyval.integerval) = tempIntPtr;
			  }
#line 7789 "parser.c"
    break;

  case 401: /* externalproctype: "list" "of" "object"  */
#line 2263 "parser.y"
                          {
			    tempIntPtr = (int *) safeMalloc(sizeof(int));
			    *tempIntPtr = OBJECT_LIST_TYPE;
			    (yyval.integerval) = tempIntPtr;
			  }
#line 7799 "parser.c"
    break;

  case 402: /* externalproctype: "list" "of" "range"  */
#line 2269 "parser.y"
                          {
			    tempIntPtr = (int *) safeMalloc(sizeof(int));
			    *tempIntPtr = RANGE_LIST_TYPE;
			    (yyval.integerval) = tempIntPtr;
			  }
#line 7809 "parser.c"
    break;

  case 403: /* externalproctype: "list" "of" "integer"  */
#line 2275 "parser.y"
                          {
			    tempIntPtr = (int *) safeMalloc(sizeof(int));
			    *tempIntPtr = INTEGER_LIST_TYPE;
			    (yyval.integerval) = tempIntPtr;
			  }
#line 7819 "parser.c"
    break;

  case 404: /* externalproctype: "list" "of" "string"  */
#line 2281 "parser.y"
                          {
			    tempIntPtr = (int *) safeMalloc(sizeof(int));
			    *tempIntPtr = STRING_LIST_TYPE;
			    (yyval.integerval) = tempIntPtr;
			  }
#line 7829 "parser.c"
    break;

  case 405: /* externalproctype: "list" "of" "boolean"  */
#line 2287 "parser.y"
                          {
			    tempIntPtr = (int *) safeMalloc(sizeof(int));
			    *tempIntPtr = BOOLEAN_LIST_TYPE;
			    (yyval.integerval) = tempIntPtr;
			  }
#line 7839 "parser.c"
    break;

  case 406: /* extendedexternalproctype: "void"  */
#line 2295 "parser.y"
                          {
			    tempIntPtr = (int *) safeMalloc(sizeof(int));
			    *tempIntPtr = VOID_TYPE;
			    (yyval.integerval) = tempIntPtr;
			  }
#line 7849 "parser.c"
    break;

  case 407: /* extendedexternalproctype: externalproctype  */
#line 2301 "parser.y"
                          {
			    (yyval.integerval) = (yyvsp[0].integerval);
		          }
#line 7857 "parser.c"
    break;

  case 408: /* externalproctypesimplelist: externalproctype  */
#line 2308 "parser.y"
                          {
			    (yyval.list) = addElement(NULL, (yyvsp[0].integerval));
			  }
#line 7865 "parser.c"
    break;

  case 409: /* externalproctypesimplelist: externalproctype "," externalproctypesimplelist  */
#line 2312 "parser.y"
                          {
			    (yyval.list) = addElement((yyvsp[0].list), (yyvsp[-2].integerval));
			  }
#line 7873 "parser.c"
    break;

  case 410: /* externalproctypelist: extendedexternalproctype  */
#line 2318 "parser.y"
                          {
			    (yyval.list) = addElement(NULL, (yyvsp[0].integerval));
			  }
#line 7881 "parser.c"
    break;

  case 411: /* externalproctypelist: "(" externalproctypesimplelist ")"  */
#line 2322 "parser.y"
                          {
			    (yyval.list) = (yyvsp[-1].list);
			  }
#line 7889 "parser.c"
    break;

  case 412: /* help: "decimal constant"  */
#line 2329 "parser.y"
                          {
			    outputMode(); sollyaPrintf("\"%s\" is recognized as a base 10 constant.\n",(yyvsp[0].value));
			    safeFree((yyvsp[0].value));
			  }
#line 7898 "parser.c"
    break;

  case 413: /* help: "dyadic constant"  */
#line 2334 "parser.y"
                          {
			    outputMode(); sollyaPrintf("\"%s\" is recognized as a dyadic number constant.\n",(yyvsp[0].value));
			    safeFree((yyvsp[0].value));
                          }
#line 7907 "parser.c"
    break;

  case 414: /* help: "constant in memory notation"  */
#line 2339 "parser.y"
                          {
			    outputMode(); sollyaPrintf("\"%s\" is recognized as a double or single precision constant.\n",(yyvsp[0].value));
			    safeFree((yyvsp[0].value));
                          }
#line 7916 "parser.c"
    break;

  case 415: /* help: "hexadecimal constant"  */
#line 2344 "parser.y"
                          {
			    outputMode(); sollyaPrintf("\"%s\" is recognized as a hexadecimal constant.\n",(yyvsp[0].value));
			    safeFree((yyvsp[0].value));
                          }
#line 7925 "parser.c"
    break;

  case 416: /* help: "binary constant"  */
#line 2349 "parser.y"
                          {
			    outputMode(); sollyaPrintf("\"%s_2\" is recognized as a base 2 constant.\n",(yyvsp[0].value));
			    safeFree((yyvsp[0].value));
                          }
#line 7934 "parser.c"
    break;

  case 417: /* help: "pi"  */
#line 2354 "parser.y"
                          {
			    outputMode(); sollya_print_help_text("pi");
                          }
#line 7942 "parser.c"
    break;

  case 418: /* help: "identifier"  */
#line 2358 "parser.y"
                          {
			    outputMode(); sollyaPrintf("\"%s\" is an identifier.\n",(yyvsp[0].value));
			    safeFree((yyvsp[0].value));
                          }
#line 7951 "parser.c"
    break;

  case 419: /* help: "character string"  */
#line 2363 "parser.y"
                          {
			    outputMode(); sollyaPrintf("\"%s\" is a string constant.\n",(yyvsp[0].value));
			    safeFree((yyvsp[0].value));
                          }
#line 7960 "parser.c"
    break;

  case 420: /* help: "("  */
#line 2368 "parser.y"
                          {
			    outputMode(); sollyaPrintf("Left parenthesis.\n");
                          }
#line 7968 "parser.c"
    break;

  case 421: /* help: ")"  */
#line 2372 "parser.y"
                          {
			    outputMode(); sollyaPrintf("Right parenthesis.\n");
                          }
#line 7976 "parser.c"
    break;

  case 422: /* help: "["  */
#line 2376 "parser.y"
                          {
			    outputMode(); sollyaPrintf("Left bracket - indicates a range.\n");
                          }
#line 7984 "parser.c"
    break;

  case 423: /* help: "]"  */
#line 2380 "parser.y"
                          {
			    outputMode(); sollyaPrintf("Right bracket - indicates a range.\n");
                          }
#line 7992 "parser.c"
    break;

  case 424: /* help: "[" "|"  */
#line 2384 "parser.y"
                          {
			    outputMode(); sollyaPrintf("Left bracket-bar - indicates a list.\n");
                          }
#line 8000 "parser.c"
    break;

  case 425: /* help: "|" "]"  */
#line 2388 "parser.y"
                          {
			    outputMode(); sollyaPrintf("Bar-right bracket - indicates a list.\n");
                          }
#line 8008 "parser.c"
    break;

  case 426: /* help: "="  */
#line 2392 "parser.y"
                          {
			    outputMode(); sollya_print_help_text("=");
                          }
#line 8016 "parser.c"
    break;

  case 427: /* help: ":="  */
#line 2396 "parser.y"
                          {
			    outputMode(); sollya_print_help_text(":=");
                          }
#line 8024 "parser.c"
    break;

  case 428: /* help: "=="  */
#line 2400 "parser.y"
                          {
			    outputMode(); sollya_print_help_text("==");
                          }
#line 8032 "parser.c"
    break;

  case 429: /* help: ","  */
#line 2404 "parser.y"
                          {
			    outputMode(); sollyaPrintf("Separator in lists, ranges or structures.\n");
                          }
#line 8040 "parser.c"
    break;

  case 430: /* help: "!"  */
#line 2408 "parser.y"
                          {
			    outputMode(); sollya_print_help_text("!");
                          }
#line 8048 "parser.c"
    break;

  case 431: /* help: "*<"  */
#line 2412 "parser.y"
                          {
			    outputMode(); sollyaPrintf("Dereferences range bounds.\n");
                          }
#line 8056 "parser.c"
    break;

  case 432: /* help: "<"  */
#line 2416 "parser.y"
                          {
			    outputMode(); sollya_print_help_text("<");
                          }
#line 8064 "parser.c"
    break;

  case 433: /* help: "<" "="  */
#line 2420 "parser.y"
                          {
			    outputMode(); sollya_print_help_text("<=");
                          }
#line 8072 "parser.c"
    break;

  case 434: /* help: ">_"  */
#line 2424 "parser.y"
                          {
			    outputMode(); sollyaPrintf("Dereferences the lower range bound.\n");
                          }
#line 8080 "parser.c"
    break;

  case 435: /* help: ">."  */
#line 2428 "parser.y"
                          {
			    outputMode(); sollyaPrintf("Dereferences the mid-point of a range.\n");
                          }
#line 8088 "parser.c"
    break;

  case 436: /* help: ">" "="  */
#line 2432 "parser.y"
                          {
			    outputMode(); sollya_print_help_text(">=");
			  }
#line 8096 "parser.c"
    break;

  case 437: /* help: "."  */
#line 2436 "parser.y"
                          {
			    outputMode(); sollyaPrintf("Accessing an element in a structured type.\n");
			  }
#line 8104 "parser.c"
    break;

  case 438: /* help: ">*"  */
#line 2440 "parser.y"
                          {
			    outputMode(); sollyaPrintf("Dereferences the upper range bound.\n");
                          }
#line 8112 "parser.c"
    break;

  case 439: /* help: ">"  */
#line 2444 "parser.y"
                          {
			    outputMode(); sollya_print_help_text(">");
                          }
#line 8120 "parser.c"
    break;

  case 440: /* help: "..."  */
#line 2448 "parser.y"
                          {
			    outputMode(); sollyaPrintf("Ellipsis.\n");
                          }
#line 8128 "parser.c"
    break;

  case 441: /* help: "?"  */
#line 2452 "parser.y"
                          {
			    outputMode(); sollyaPrintf("Dereferences global environment variables.\n");
                          }
#line 8136 "parser.c"
    break;

  case 442: /* help: "|"  */
#line 2456 "parser.y"
                          {
			    outputMode(); sollyaPrintf("Starts or ends a list.\n");
                          }
#line 8144 "parser.c"
    break;

  case 443: /* help: "@"  */
#line 2460 "parser.y"
                          {
			    outputMode(); sollya_print_help_text("@");
                          }
#line 8152 "parser.c"
    break;

  case 444: /* help: "::"  */
#line 2464 "parser.y"
                          {
			    outputMode(); sollyaPrintf("a::b prepends a to list b or appends b to list a, preprending list a to list b if both are lists.\n");
                          }
#line 8160 "parser.c"
    break;

  case 445: /* help: ".:"  */
#line 2468 "parser.y"
                          {
			    outputMode(); sollya_print_help_text(".:");
                          }
#line 8168 "parser.c"
    break;

  case 446: /* help: ":."  */
#line 2472 "parser.y"
                          {
			    outputMode(); sollya_print_help_text(":.");
                          }
#line 8176 "parser.c"
    break;

  case 447: /* help: "!="  */
#line 2476 "parser.y"
                          {
			    outputMode(); sollya_print_help_text("!=");
                          }
#line 8184 "parser.c"
    break;

  case 448: /* help: "&&"  */
#line 2480 "parser.y"
                          {
			    outputMode(); sollya_print_help_text("&&");
                          }
#line 8192 "parser.c"
    break;

  case 449: /* help: "||"  */
#line 2484 "parser.y"
                          {
			    outputMode(); sollya_print_help_text("||");
                          }
#line 8200 "parser.c"
    break;

  case 450: /* help: "+"  */
#line 2488 "parser.y"
                          {
			    outputMode(); sollya_print_help_text("+");
                          }
#line 8208 "parser.c"
    break;

  case 451: /* help: "-"  */
#line 2492 "parser.y"
                          {
			    outputMode(); sollya_print_help_text("-");
                          }
#line 8216 "parser.c"
    break;

  case 452: /* help: "~"  */
#line 2496 "parser.y"
                          {
			    outputMode(); sollya_print_help_text("~");
                          }
#line 8224 "parser.c"
    break;

  case 453: /* help: "*"  */
#line 2500 "parser.y"
                          {
			    outputMode(); sollya_print_help_text("*");
                          }
#line 8232 "parser.c"
    break;

  case 454: /* help: "/"  */
#line 2504 "parser.y"
                          {
			    outputMode(); sollya_print_help_text("/");
                          }
#line 8240 "parser.c"
    break;

  case 455: /* help: "^"  */
#line 2508 "parser.y"
                          {
			    outputMode(); sollya_print_help_text("^");
                          }
#line 8248 "parser.c"
    break;

  case 456: /* help: "sqrt"  */
#line 2512 "parser.y"
                          {
			    outputMode(); sollya_print_help_text("sqrt");
                          }
#line 8256 "parser.c"
    break;

  case 457: /* help: "exp"  */
#line 2516 "parser.y"
                          {
			    outputMode(); sollya_print_help_text("exp");
                          }
#line 8264 "parser.c"
    break;

  case 458: /* help: "_x_"  */
#line 2520 "parser.y"
                          {
			    outputMode(); sollya_print_help_text("_x_");
                          }
#line 8272 "parser.c"
    break;

  case 459: /* help: "log"  */
#line 2524 "parser.y"
                          {
			    outputMode(); sollya_print_help_text("log");
                          }
#line 8280 "parser.c"
    break;

  case 460: /* help: "log2"  */
#line 2528 "parser.y"
                          {
			    outputMode(); sollya_print_help_text("log2");
                          }
#line 8288 "parser.c"
    break;

  case 461: /* help: "log10"  */
#line 2532 "parser.y"
                          {
			    outputMode(); sollya_print_help_text("log10");
                          }
#line 8296 "parser.c"
    break;

  case 462: /* help: "sin"  */
#line 2536 "parser.y"
                          {
			    outputMode(); sollya_print_help_text("sin");
                          }
#line 8304 "parser.c"
    break;

  case 463: /* help: "cos"  */
#line 2540 "parser.y"
                          {
			    outputMode(); sollya_print_help_text("cos");
                          }
#line 8312 "parser.c"
    break;

  case 464: /* help: "tan"  */
#line 2544 "parser.y"
                          {
			    outputMode(); sollya_print_help_text("tan");
                          }
#line 8320 "parser.c"
    break;

  case 465: /* help: "asin"  */
#line 2548 "parser.y"
                          {
			    outputMode(); sollya_print_help_text("asin");
                          }
#line 8328 "parser.c"
    break;

  case 466: /* help: "acos"  */
#line 2552 "parser.y"
                          {
			    outputMode(); sollya_print_help_text("acos");
                          }
#line 8336 "parser.c"
    break;

  case 467: /* help: "atan"  */
#line 2556 "parser.y"
                          {
			    outputMode(); sollya_print_help_text("atan");
                          }
#line 8344 "parser.c"
    break;

  case 468: /* help: "sinh"  */
#line 2560 "parser.y"
                          {
			    outputMode(); sollya_print_help_text("sinh");
                          }
#line 8352 "parser.c"
    break;

  case 469: /* help: "cosh"  */
#line 2564 "parser.y"
                          {
			    outputMode(); sollya_print_help_text("cosh");
                          }
#line 8360 "parser.c"
    break;

  case 470: /* help: "tanh"  */
#line 2568 "parser.y"
                          {
			    outputMode(); sollya_print_help_text("tanh");
                          }
#line 8368 "parser.c"
    break;

  case 471: /* help: "asinh"  */
#line 2572 "parser.y"
                          {
			    outputMode(); sollya_print_help_text("asinh");
                          }
#line 8376 "parser.c"
    break;

  case 472: /* help: "acosh"  */
#line 2576 "parser.y"
                          {
			    outputMode(); sollya_print_help_text("acosh");
                          }
#line 8384 "parser.c"
    break;

  case 473: /* help: "atanh"  */
#line 2580 "parser.y"
                          {
			    outputMode(); sollya_print_help_text("atanh");
                          }
#line 8392 "parser.c"
    break;

  case 474: /* help: "abs"  */
#line 2584 "parser.y"
                          {
			    outputMode(); sollya_print_help_text("abs");
                          }
#line 8400 "parser.c"
    break;

  case 475: /* help: "erf"  */
#line 2588 "parser.y"
                          {
			    outputMode(); sollya_print_help_text("erf");
                          }
#line 8408 "parser.c"
    break;

  case 476: /* help: "erfc"  */
#line 2592 "parser.y"
                          {
			    outputMode(); sollya_print_help_text("erfc");
                          }
#line 8416 "parser.c"
    break;

  case 477: /* help: "log1p"  */
#line 2596 "parser.y"
                          {
			    outputMode(); sollya_print_help_text("log1p");
                          }
#line 8424 "parser.c"
    break;

  case 478: /* help: "expm1"  */
#line 2600 "parser.y"
                          {
			    outputMode(); sollya_print_help_text("expm1");
                          }
#line 8432 "parser.c"
    break;

  case 479: /* help: "D"  */
#line 2604 "parser.y"
                          {
			    outputMode(); sollya_print_help_text("double");
                          }
#line 8440 "parser.c"
    break;

  case 480: /* help: "SG"  */
#line 2608 "parser.y"
                          {
			    outputMode(); sollya_print_help_text("single");
                          }
#line 8448 "parser.c"
    break;

  case 481: /* help: "QD"  */
#line 2612 "parser.y"
                          {
			    outputMode(); sollya_print_help_text("quad");
                          }
#line 8456 "parser.c"
    break;

  case 482: /* help: "HP"  */
#line 2616 "parser.y"
                          {
			    outputMode(); sollya_print_help_text("halfprecision");
                          }
#line 8464 "parser.c"
    break;

  case 483: /* help: "DD"  */
#line 2620 "parser.y"
                          {
			    outputMode(); sollya_print_help_text("doubledouble");
                          }
#line 8472 "parser.c"
    break;

  case 484: /* help: "TD"  */
#line 2624 "parser.y"
                          {
			    outputMode(); sollya_print_help_text("tripledouble");
                          }
#line 8480 "parser.c"
    break;

  case 485: /* help: "DE"  */
#line 2628 "parser.y"
                          {
			    outputMode(); sollya_print_help_text("doubleextended");
                          }
#line 8488 "parser.c"
    break;

  case 486: /* help: "ceil"  */
#line 2632 "parser.y"
                          {
			    outputMode(); sollya_print_help_text("ceil");
                          }
#line 8496 "parser.c"
    break;

  case 487: /* help: "floor"  */
#line 2636 "parser.y"
                          {
			    outputMode(); sollya_print_help_text("floor");
                          }
#line 8504 "parser.c"
    break;

  case 488: /* help: "nearestint"  */
#line 2640 "parser.y"
                          {
			    outputMode(); sollya_print_help_text("nearestint");
                          }
#line 8512 "parser.c"
    break;

  case 489: /* help: "head"  */
#line 2644 "parser.y"
                          {
			    outputMode(); sollya_print_help_text("head");
                          }
#line 8520 "parser.c"
    break;

  case 490: /* help: "roundcorrectly"  */
#line 2648 "parser.y"
                          {
			    outputMode(); sollya_print_help_text("roundcorrectly");
                          }
#line 8528 "parser.c"
    break;

  case 491: /* help: "readfile"  */
#line 2652 "parser.y"
                          {
			    outputMode(); sollya_print_help_text("readfile");
                          }
#line 8536 "parser.c"
    break;

  case 492: /* help: "revert"  */
#line 2656 "parser.y"
                          {
			    outputMode(); sollya_print_help_text("revert");
                          }
#line 8544 "parser.c"
    break;

  case 493: /* help: "sort"  */
#line 2660 "parser.y"
                          {
			    outputMode(); sollya_print_help_text("sort");
                          }
#line 8552 "parser.c"
    break;

  case 494: /* help: "tail"  */
#line 2664 "parser.y"
                          {
			    outputMode(); sollya_print_help_text("tail");
                          }
#line 8560 "parser.c"
    break;

  case 495: /* help: "prec"  */
#line 2668 "parser.y"
                          {
			    outputMode(); sollya_print_help_text("prec");
                          }
#line 8568 "parser.c"
    break;

  case 496: /* help: "points"  */
#line 2672 "parser.y"
                          {
			    outputMode(); sollya_print_help_text("points");
                          }
#line 8576 "parser.c"
    break;

  case 497: /* help: "diam"  */
#line 2676 "parser.y"
                          {
			    outputMode(); sollya_print_help_text("diam");
                          }
#line 8584 "parser.c"
    break;

  case 498: /* help: "display"  */
#line 2680 "parser.y"
                          {
			    outputMode(); sollya_print_help_text("display");
                          }
#line 8592 "parser.c"
    break;

  case 499: /* help: "verbosity"  */
#line 2684 "parser.y"
                          {
			    outputMode(); sollya_print_help_text("verbosity");
                          }
#line 8600 "parser.c"
    break;

  case 500: /* help: "showmessagenumbers"  */
#line 2688 "parser.y"
                          {
			    outputMode(); sollya_print_help_text("showmessagenumbers");
                          }
#line 8608 "parser.c"
    break;

  case 501: /* help: "canonical"  */
#line 2692 "parser.y"
                          {
			    outputMode(); sollya_print_help_text("canonical");
                          }
#line 8616 "parser.c"
    break;

  case 502: /* help: "autosimplify"  */
#line 2696 "parser.y"
                          {
			    outputMode(); sollya_print_help_text("autosimplify");
                          }
#line 8624 "parser.c"
    break;

  case 503: /* help: "taylorrecursions"  */
#line 2700 "parser.y"
                          {
			    outputMode(); sollya_print_help_text("taylorrecursions");
                          }
#line 8632 "parser.c"
    break;

  case 504: /* help: "timing"  */
#line 2704 "parser.y"
                          {
			    outputMode(); sollya_print_help_text("timing");
                          }
#line 8640 "parser.c"
    break;

  case 505: /* help: "time"  */
#line 2708 "parser.y"
                          {
			    outputMode(); sollya_print_help_text("time");
                          }
#line 8648 "parser.c"
    break;

  case 506: /* help: "fullparentheses"  */
#line 2712 "parser.y"
                          {
			    outputMode(); sollya_print_help_text("fullparentheses");
                          }
#line 8656 "parser.c"
    break;

  case 507: /* help: "midpointmode"  */
#line 2716 "parser.y"
                          {
			    outputMode(); sollya_print_help_text("midpointmode");
                          }
#line 8664 "parser.c"
    break;

  case 508: /* help: "dieonerrormode"  */
#line 2720 "parser.y"
                          {
			    outputMode(); sollya_print_help_text("dieonerrormode");
                          }
#line 8672 "parser.c"
    break;

  case 509: /* help: "rationalmode"  */
#line 2724 "parser.y"
                          {
			    outputMode(); sollya_print_help_text("rationalmode");
                          }
#line 8680 "parser.c"
    break;

  case 510: /* help: "roundingwarnings"  */
#line 2728 "parser.y"
                          {
			    outputMode(); sollya_print_help_text("roundingwarnings");
                          }
#line 8688 "parser.c"
    break;

  case 511: /* help: "hopitalrecursions"  */
#line 2732 "parser.y"
                          {
			    outputMode(); sollya_print_help_text("hopitalrecursions");
                          }
#line 8696 "parser.c"
    break;

  case 512: /* help: "on"  */
#line 2736 "parser.y"
                          {
			    outputMode(); sollya_print_help_text("on");
                          }
#line 8704 "parser.c"
    break;

  case 513: /* help: "off"  */
#line 2740 "parser.y"
                          {
			    outputMode(); sollya_print_help_text("off");
                          }
#line 8712 "parser.c"
    break;

  case 514: /* help: "dyadic"  */
#line 2744 "parser.y"
                          {
			    outputMode(); sollya_print_help_text("dyadic");
                          }
#line 8720 "parser.c"
    break;

  case 515: /* help: "powers"  */
#line 2748 "parser.y"
                          {
			    outputMode(); sollya_print_help_text("powers");
                          }
#line 8728 "parser.c"
    break;

  case 516: /* help: "binary"  */
#line 2752 "parser.y"
                          {
			    outputMode(); sollya_print_help_text("binary");
                          }
#line 8736 "parser.c"
    break;

  case 517: /* help: "hexadecimal"  */
#line 2756 "parser.y"
                          {
			    outputMode(); sollya_print_help_text("hexadecimal");
                          }
#line 8744 "parser.c"
    break;

  case 518: /* help: "file"  */
#line 2760 "parser.y"
                          {
			    outputMode(); sollya_print_help_text("file");
                          }
#line 8752 "parser.c"
    break;

  case 519: /* help: "postscript"  */
#line 2764 "parser.y"
                          {
			    outputMode(); sollya_print_help_text("postscript");
                          }
#line 8760 "parser.c"
    break;

  case 520: /* help: "postscriptfile"  */
#line 2768 "parser.y"
                          {
			    outputMode(); sollya_print_help_text("postscriptfile");
                          }
#line 8768 "parser.c"
    break;

  case 521: /* help: "perturb"  */
#line 2772 "parser.y"
                          {
			    outputMode(); sollya_print_help_text("perturb");
                          }
#line 8776 "parser.c"
    break;

  case 522: /* help: "RD"  */
#line 2776 "parser.y"
                          {
			    outputMode(); sollya_print_help_text("RD");
                          }
#line 8784 "parser.c"
    break;

  case 523: /* help: "RU"  */
#line 2780 "parser.y"
                          {
			    outputMode(); sollya_print_help_text("RU");
                          }
#line 8792 "parser.c"
    break;

  case 524: /* help: "RZ"  */
#line 2784 "parser.y"
                          {
			    outputMode(); sollya_print_help_text("RZ");
                          }
#line 8800 "parser.c"
    break;

  case 525: /* help: "RN"  */
#line 2788 "parser.y"
                          {
			    outputMode(); sollya_print_help_text("RN");
                          }
#line 8808 "parser.c"
    break;

  case 526: /* help: "honorcoeffprec"  */
#line 2792 "parser.y"
                          {
			    outputMode(); sollya_print_help_text("honorcoeffprec");
                          }
#line 8816 "parser.c"
    break;

  case 527: /* help: "true"  */
#line 2796 "parser.y"
                          {
			    outputMode(); sollya_print_help_text("true");
                          }
#line 8824 "parser.c"
    break;

  case 528: /* help: "false"  */
#line 2800 "parser.y"
                          {
			    outputMode(); sollya_print_help_text("false");
                          }
#line 8832 "parser.c"
    break;

  case 529: /* help: "default"  */
#line 2804 "parser.y"
                          {
			    outputMode(); sollya_print_help_text("default");
                          }
#line 8840 "parser.c"
    break;

  case 530: /* help: "match"  */
#line 2808 "parser.y"
                          {
			    outputMode(); sollya_print_help_text("match");
                          }
#line 8848 "parser.c"
    break;

  case 531: /* help: "with"  */
#line 2812 "parser.y"
                          {
			    outputMode(); sollya_print_help_text("with");
                          }
#line 8856 "parser.c"
    break;

  case 532: /* help: "absolute"  */
#line 2816 "parser.y"
                          {
			    outputMode(); sollya_print_help_text("absolute");
                          }
#line 8864 "parser.c"
    break;

  case 533: /* help: "decimal"  */
#line 2820 "parser.y"
                          {
			    outputMode(); sollya_print_help_text("decimal");
                          }
#line 8872 "parser.c"
    break;

  case 534: /* help: "relative"  */
#line 2824 "parser.y"
                          {
			    outputMode(); sollya_print_help_text("relative");
                          }
#line 8880 "parser.c"
    break;

  case 535: /* help: "fixed"  */
#line 2828 "parser.y"
                          {
			    outputMode(); sollya_print_help_text("fixed");
                          }
#line 8888 "parser.c"
    break;

  case 536: /* help: "floating"  */
#line 2832 "parser.y"
                          {
			    outputMode(); sollya_print_help_text("floating");
                          }
#line 8896 "parser.c"
    break;

  case 537: /* help: "error"  */
#line 2836 "parser.y"
                          {
			    outputMode(); sollya_print_help_text("error");
                          }
#line 8904 "parser.c"
    break;

  case 538: /* help: "quit"  */
#line 2840 "parser.y"
                          {
			    outputMode(); sollya_print_help_text("quit");
                          }
#line 8912 "parser.c"
    break;

  case 539: /* help: "quit in an included file"  */
#line 2844 "parser.y"
                          {
			    outputMode(); sollya_print_help_text("quit");
                          }
#line 8920 "parser.c"
    break;

  case 540: /* help: "restart"  */
#line 2848 "parser.y"
                          {
			    outputMode(); sollya_print_help_text("restart");
                          }
#line 8928 "parser.c"
    break;

  case 541: /* help: "library"  */
#line 2852 "parser.y"
                          {
			    outputMode(); sollya_print_help_text("library");
                          }
#line 8936 "parser.c"
    break;

  case 542: /* help: "libraryconstant"  */
#line 2856 "parser.y"
                          {
			    outputMode(); sollya_print_help_text("libraryconstant");
                          }
#line 8944 "parser.c"
    break;

  case 543: /* help: "diff"  */
#line 2860 "parser.y"
                          {
			    outputMode(); sollya_print_help_text("diff");
                          }
#line 8952 "parser.c"
    break;

  case 544: /* help: "bashevaluate"  */
#line 2864 "parser.y"
                          {
			    outputMode(); sollya_print_help_text("bashevaluate");
                          }
#line 8960 "parser.c"
    break;

  case 545: /* help: "getsuppressedmessages"  */
#line 2868 "parser.y"
                          {
			    outputMode(); sollya_print_help_text("getsuppressedmessages");
                          }
#line 8968 "parser.c"
    break;

  case 546: /* help: "getbacktrace"  */
#line 2872 "parser.y"
                          {
			    outputMode(); sollya_print_help_text("getbacktrace");
                          }
#line 8976 "parser.c"
    break;

  case 547: /* help: "dirtysimplify"  */
#line 2876 "parser.y"
                          {
			    outputMode(); sollya_print_help_text("dirtysimplify");
                          }
#line 8984 "parser.c"
    break;

  case 548: /* help: "remez"  */
#line 2880 "parser.y"
                          {
			    outputMode(); sollya_print_help_text("remez");
                          }
#line 8992 "parser.c"
    break;

  case 549: /* help: "annotatefunction"  */
#line 2884 "parser.y"
                          {
			    outputMode(); sollya_print_help_text("annotatefunction");
                          }
#line 9000 "parser.c"
    break;

  case 550: /* help: "min"  */
#line 2888 "parser.y"
                          {
			    outputMode(); sollya_print_help_text("min");
                          }
#line 9008 "parser.c"
    break;

  case 551: /* help: "max"  */
#line 2892 "parser.y"
                          {
			    outputMode(); sollya_print_help_text("max");
                          }
#line 9016 "parser.c"
    break;

  case 552: /* help: "fpminimax"  */
#line 2896 "parser.y"
                          {
			    outputMode(); sollya_print_help_text("fpminimax");
                          }
#line 9024 "parser.c"
    break;

  case 553: /* help: "horner"  */
#line 2900 "parser.y"
                          {
			    outputMode(); sollya_print_help_text("horner");
                          }
#line 9032 "parser.c"
    break;

  case 554: /* help: "expand"  */
#line 2904 "parser.y"
                          {
			    outputMode(); sollya_print_help_text("expand");
                          }
#line 9040 "parser.c"
    break;

  case 555: /* help: "simplify"  */
#line 2908 "parser.y"
                          {
			    outputMode(); sollya_print_help_text("simplify");
                          }
#line 9048 "parser.c"
    break;

  case 556: /* help: "taylor"  */
#line 2912 "parser.y"
                          {
			    outputMode(); sollya_print_help_text("taylor");
                          }
#line 9056 "parser.c"
    break;

  case 557: /* help: "taylorform"  */
#line 2916 "parser.y"
                          {
			    outputMode(); sollya_print_help_text("taylorform");
                          }
#line 9064 "parser.c"
    break;

  case 558: /* help: "chebyshevform"  */
#line 2920 "parser.y"
                          {
			    outputMode(); sollya_print_help_text("chebyshevform");
                          }
#line 9072 "parser.c"
    break;

  case 559: /* help: "autodiff"  */
#line 2924 "parser.y"
                          {
			    outputMode(); sollya_print_help_text("autodiff");
                          }
#line 9080 "parser.c"
    break;

  case 560: /* help: "degree"  */
#line 2928 "parser.y"
                          {
			    outputMode(); sollya_print_help_text("degree");
                          }
#line 9088 "parser.c"
    break;

  case 561: /* help: "numerator"  */
#line 2932 "parser.y"
                          {
			    outputMode(); sollya_print_help_text("numerator");
                          }
#line 9096 "parser.c"
    break;

  case 562: /* help: "denominator"  */
#line 2936 "parser.y"
                          {
			    outputMode(); sollya_print_help_text("denominator");
                          }
#line 9104 "parser.c"
    break;

  case 563: /* help: "substitute"  */
#line 2940 "parser.y"
                          {
			    outputMode(); sollya_print_help_text("substitute");
                          }
#line 9112 "parser.c"
    break;

  case 564: /* help: "composepolynomials"  */
#line 2944 "parser.y"
                          {
			    outputMode(); sollya_print_help_text("composepolynomials");
                          }
#line 9120 "parser.c"
    break;

  case 565: /* help: "bezout"  */
#line 2948 "parser.y"
                          {
			    outputMode(); sollya_print_help_text("bezout");
                          }
#line 9128 "parser.c"
    break;

  case 566: /* help: "coeff"  */
#line 2952 "parser.y"
                          {
			    outputMode(); sollya_print_help_text("coeff");
                          }
#line 9136 "parser.c"
    break;

  case 567: /* help: "subpoly"  */
#line 2956 "parser.y"
                          {
			    outputMode(); sollya_print_help_text("subpoly");
                          }
#line 9144 "parser.c"
    break;

  case 568: /* help: "roundcoefficients"  */
#line 2960 "parser.y"
                          {
			    outputMode(); sollya_print_help_text("roundcoefficients");
                          }
#line 9152 "parser.c"
    break;

  case 569: /* help: "rationalapprox"  */
#line 2964 "parser.y"
                          {
			    outputMode(); sollya_print_help_text("rationalapprox");
                          }
#line 9160 "parser.c"
    break;

  case 570: /* help: "accurateinfnorm"  */
#line 2968 "parser.y"
                          {
			    outputMode(); sollya_print_help_text("accurateinfnorm");
                          }
#line 9168 "parser.c"
    break;

  case 571: /* help: "round"  */
#line 2972 "parser.y"
                          {
			    outputMode(); sollya_print_help_text("round");
                          }
#line 9176 "parser.c"
    break;

  case 572: /* help: "evaluate"  */
#line 2976 "parser.y"
                          {
			    outputMode(); sollya_print_help_text("evaluate");
                          }
#line 9184 "parser.c"
    break;

  case 573: /* help: "length"  */
#line 2980 "parser.y"
                          {
			    outputMode(); sollya_print_help_text("length");
                          }
#line 9192 "parser.c"
    break;

  case 574: /* help: "objectname"  */
#line 2984 "parser.y"
                          {
			    outputMode(); sollya_print_help_text("objectname");
                          }
#line 9200 "parser.c"
    break;

  case 575: /* help: "parse"  */
#line 2988 "parser.y"
                          {
			    outputMode(); sollya_print_help_text("parse");
                          }
#line 9208 "parser.c"
    break;

  case 576: /* help: "print"  */
#line 2992 "parser.y"
                          {
			    outputMode(); sollya_print_help_text("print");
                          }
#line 9216 "parser.c"
    break;

  case 577: /* help: "printxml"  */
#line 2996 "parser.y"
                          {
			    outputMode(); sollya_print_help_text("printxml");
                          }
#line 9224 "parser.c"
    break;

  case 578: /* help: "readxml"  */
#line 3000 "parser.y"
                          {
			    outputMode(); sollya_print_help_text("readxml");
                          }
#line 9232 "parser.c"
    break;

  case 579: /* help: "plot"  */
#line 3004 "parser.y"
                          {
			    outputMode(); sollya_print_help_text("plot");
                          }
#line 9240 "parser.c"
    break;

  case 580: /* help: "printhexa"  */
#line 3008 "parser.y"
                          {
			    outputMode(); sollya_print_help_text("printdouble");
                          }
#line 9248 "parser.c"
    break;

  case 581: /* help: "printfloat"  */
#line 3012 "parser.y"
                          {
			    outputMode(); sollya_print_help_text("printsingle");
                          }
#line 9256 "parser.c"
    break;

  case 582: /* help: "printbinary"  */
#line 3016 "parser.y"
                          {
			    outputMode(); sollya_print_help_text("printbinary");
                          }
#line 9264 "parser.c"
    break;

  case 583: /* help: "suppressmessage"  */
#line 3020 "parser.y"
                          {
			    outputMode(); sollya_print_help_text("suppressmessage");
                          }
#line 9272 "parser.c"
    break;

  case 584: /* help: "unsuppressmessage"  */
#line 3024 "parser.y"
                          {
			    outputMode(); sollya_print_help_text("unsuppressmessage");
                          }
#line 9280 "parser.c"
    break;

  case 585: /* help: "printexpansion"  */
#line 3028 "parser.y"
                          {
			    outputMode(); sollya_print_help_text("printexpansion");
                          }
#line 9288 "parser.c"
    break;

  case 586: /* help: "bashexecute"  */
#line 3032 "parser.y"
                          {
			    outputMode(); sollya_print_help_text("bashexecute");
                          }
#line 9296 "parser.c"
    break;

  case 587: /* help: "externalplot"  */
#line 3036 "parser.y"
                          {
			    outputMode(); sollya_print_help_text("externalplot");
                          }
#line 9304 "parser.c"
    break;

  case 588: /* help: "write"  */
#line 3040 "parser.y"
                          {
			    outputMode(); sollya_print_help_text("write");
                          }
#line 9312 "parser.c"
    break;

  case 589: /* help: "asciiplot"  */
#line 3044 "parser.y"
                          {
			    outputMode(); sollya_print_help_text("asciiplot");
                          }
#line 9320 "parser.c"
    break;

  case 590: /* help: "rename"  */
#line 3048 "parser.y"
                          {
			    outputMode(); sollya_print_help_text("rename");
                          }
#line 9328 "parser.c"
    break;

  case 591: /* help: "bind"  */
#line 3052 "parser.y"
                          {
			    outputMode(); sollya_print_help_text("bind");
                          }
#line 9336 "parser.c"
    break;

  case 592: /* help: "infnorm"  */
#line 3056 "parser.y"
                          {
			    outputMode(); sollya_print_help_text("infnorm");
                          }
#line 9344 "parser.c"
    break;

  case 593: /* help: "supnorm"  */
#line 3060 "parser.y"
                          {
			    outputMode(); sollya_print_help_text("supnorm");
                          }
#line 9352 "parser.c"
    break;

  case 594: /* help: "findzeros"  */
#line 3064 "parser.y"
                          {
			    outputMode(); sollya_print_help_text("findzeros");
                          }
#line 9360 "parser.c"
    break;

  case 595: /* help: "fpfindzeros"  */
#line 3068 "parser.y"
                          {
			    outputMode(); sollya_print_help_text("fpfindzeros");
                          }
#line 9368 "parser.c"
    break;

  case 596: /* help: "dirtyinfnorm"  */
#line 3072 "parser.y"
                          {
			    outputMode(); sollya_print_help_text("dirtyinfnorm");
			  }
#line 9376 "parser.c"
    break;

  case 597: /* help: "gcd"  */
#line 3076 "parser.y"
                          {
			    outputMode(); sollya_print_help_text("gcd");
			  }
#line 9384 "parser.c"
    break;

  case 598: /* help: "div"  */
#line 3080 "parser.y"
                          {
			    outputMode(); sollya_print_help_text("div");
			  }
#line 9392 "parser.c"
    break;

  case 599: /* help: "mod"  */
#line 3084 "parser.y"
                          {
			    outputMode(); sollya_print_help_text("mod");
			  }
#line 9400 "parser.c"
    break;

  case 600: /* help: "numberroots"  */
#line 3088 "parser.y"
                          {
			    outputMode(); sollya_print_help_text("numberroots");
                          }
#line 9408 "parser.c"
    break;

  case 601: /* help: "integral"  */
#line 3092 "parser.y"
                          {
			    outputMode(); sollya_print_help_text("integral");
                          }
#line 9416 "parser.c"
    break;

  case 602: /* help: "dirtyintegral"  */
#line 3096 "parser.y"
                          {
			    outputMode(); sollya_print_help_text("dirtyintegral");
                          }
#line 9424 "parser.c"
    break;

  case 603: /* help: "worstcase"  */
#line 3100 "parser.y"
                          {
			    outputMode(); sollya_print_help_text("worstcase");
                          }
#line 9432 "parser.c"
    break;

  case 604: /* help: "implementpoly"  */
#line 3104 "parser.y"
                          {
			    outputMode(); sollya_print_help_text("implementpoly");
			  }
#line 9440 "parser.c"
    break;

  case 605: /* help: "interpolate"  */
#line 3108 "parser.y"
                          {
			    outputMode(); sollya_print_help_text("interpolate");
			  }
#line 9448 "parser.c"
    break;

  case 606: /* help: "implementconst"  */
#line 3112 "parser.y"
                          {
			    outputMode(); sollya_print_help_text("implementconstant");
                          }
#line 9456 "parser.c"
    break;

  case 607: /* help: "checkinfnorm"  */
#line 3116 "parser.y"
                          {
			    outputMode(); sollya_print_help_text("checkinfnorm");
                          }
#line 9464 "parser.c"
    break;

  case 608: /* help: "zerodenominators"  */
#line 3120 "parser.y"
                          {
			    outputMode(); sollya_print_help_text("zerodenominators");
                          }
#line 9472 "parser.c"
    break;

  case 609: /* help: "isevaluable"  */
#line 3124 "parser.y"
                          {
			    outputMode(); sollya_print_help_text("isevaluable");
                          }
#line 9480 "parser.c"
    break;

  case 610: /* help: "searchgal"  */
#line 3128 "parser.y"
                          {
			    outputMode(); sollya_print_help_text("searchgal");
                          }
#line 9488 "parser.c"
    break;

  case 611: /* help: "guessdegree"  */
#line 3132 "parser.y"
                          {
			    outputMode(); sollya_print_help_text("guessdegree");
                          }
#line 9496 "parser.c"
    break;

  case 612: /* help: "dirtyfindzeros"  */
#line 3136 "parser.y"
                          {
			    outputMode(); sollya_print_help_text("dirtyfindzeros");
                          }
#line 9504 "parser.c"
    break;

  case 613: /* help: "if"  */
#line 3140 "parser.y"
                          {
			    outputMode(); sollyaPrintf("If construct: if condition then command or if condition then command else command.\n");
                          }
#line 9512 "parser.c"
    break;

  case 614: /* help: "then"  */
#line 3144 "parser.y"
                          {
			    outputMode(); sollyaPrintf("If construct: if condition then command or if condition then command else command.\n");
                          }
#line 9520 "parser.c"
    break;

  case 615: /* help: "else"  */
#line 3148 "parser.y"
                          {
			    outputMode(); sollyaPrintf("If construct: if condition then command else command\n");
                          }
#line 9528 "parser.c"
    break;

  case 616: /* help: "for"  */
#line 3152 "parser.y"
                          {
			    outputMode(); sollyaPrintf("For construct: for i from const to const2 [by const3] do command\nor for i in list do command.\n");
                          }
#line 9536 "parser.c"
    break;

  case 617: /* help: "in"  */
#line 3156 "parser.y"
                          {
			    outputMode(); sollya_print_help_text("in");
                          }
#line 9544 "parser.c"
    break;

  case 618: /* help: "from"  */
#line 3160 "parser.y"
                          {
			    outputMode(); sollyaPrintf("For construct: for i from const to const2 [by const3] do command.\n");
                          }
#line 9552 "parser.c"
    break;

  case 619: /* help: "to"  */
#line 3164 "parser.y"
                          {
			    outputMode(); sollyaPrintf("For construct: for i from const to const2 [by const3] do command.\n");
                          }
#line 9560 "parser.c"
    break;

  case 620: /* help: "by"  */
#line 3168 "parser.y"
                          {
			    outputMode(); sollyaPrintf("For construct: for i from const to const2 by const3 do command.\n");
                          }
#line 9568 "parser.c"
    break;

  case 621: /* help: "do"  */
#line 3172 "parser.y"
                          {
			    outputMode(); sollyaPrintf("For construct: for i from const to const2 [by const3] do command.\n");
			    outputMode(); sollyaPrintf("While construct: while condition do command.\n");
                          }
#line 9577 "parser.c"
    break;

  case 622: /* help: beginsymbol  */
#line 3177 "parser.y"
                          {
			    outputMode(); sollyaPrintf("Begin-end construct: begin command; command; ... end.\n");
                          }
#line 9585 "parser.c"
    break;

  case 623: /* help: endsymbol  */
#line 3181 "parser.y"
                          {
			    outputMode(); sollyaPrintf("Begin-end construct: begin command; command; ... end.\n");
                          }
#line 9593 "parser.c"
    break;

  case 624: /* help: "while"  */
#line 3185 "parser.y"
                          {
			    outputMode(); sollyaPrintf("While construct: while condition do command.\n");
                          }
#line 9601 "parser.c"
    break;

  case 625: /* help: "inf"  */
#line 3189 "parser.y"
                          {
			    outputMode(); sollya_print_help_text("inf");
                          }
#line 9609 "parser.c"
    break;

  case 626: /* help: "mid"  */
#line 3193 "parser.y"
                          {
			    outputMode(); sollya_print_help_text("mid");
                          }
#line 9617 "parser.c"
    break;

  case 627: /* help: "sup"  */
#line 3197 "parser.y"
                          {
			    outputMode(); sollya_print_help_text("sup");
                          }
#line 9625 "parser.c"
    break;

  case 628: /* help: "exponent"  */
#line 3201 "parser.y"
                          {
			    outputMode(); sollya_print_help_text("exponent");
                          }
#line 9633 "parser.c"
    break;

  case 629: /* help: "mantissa"  */
#line 3205 "parser.y"
                          {
			    outputMode(); sollya_print_help_text("mantissa");
                          }
#line 9641 "parser.c"
    break;

  case 630: /* help: "precision"  */
#line 3209 "parser.y"
                          {
			    outputMode(); sollya_print_help_text("precision");
                          }
#line 9649 "parser.c"
    break;

  case 631: /* help: "execute"  */
#line 3213 "parser.y"
                          {
			    outputMode(); sollya_print_help_text("execute");
                          }
#line 9657 "parser.c"
    break;

  case 632: /* help: "isbound"  */
#line 3217 "parser.y"
                          {
			    outputMode(); sollya_print_help_text("isbound");
                          }
#line 9665 "parser.c"
    break;

  case 633: /* help: "version"  */
#line 3221 "parser.y"
                          {
			    outputMode(); sollyaPrintf("Prints the version of the software.\n");
                          }
#line 9673 "parser.c"
    break;

  case 634: /* help: "externalproc"  */
#line 3225 "parser.y"
                          {
			    outputMode(); sollya_print_help_text("externalproc");
			  }
#line 9681 "parser.c"
    break;

  case 635: /* help: "externaldata"  */
#line 3229 "parser.y"
                          {
			    outputMode(); sollya_print_help_text("externaldata");
                          }
#line 9689 "parser.c"
    break;

  case 636: /* help: "void"  */
#line 3233 "parser.y"
                          {
			    outputMode(); sollya_print_help_text("void");
                          }
#line 9697 "parser.c"
    break;

  case 637: /* help: "constant"  */
#line 3237 "parser.y"
                          {
			    outputMode(); sollya_print_help_text("constant");
			  }
#line 9705 "parser.c"
    break;

  case 638: /* help: "function"  */
#line 3241 "parser.y"
                          {
			    outputMode(); sollya_print_help_text("function");
			  }
#line 9713 "parser.c"
    break;

  case 639: /* help: "object"  */
#line 3245 "parser.y"
                          {
			    outputMode(); sollya_print_help_text("object");
                          }
#line 9721 "parser.c"
    break;

  case 640: /* help: "range"  */
#line 3249 "parser.y"
                          {
			    outputMode(); sollya_print_help_text("range");
                          }
#line 9729 "parser.c"
    break;

  case 641: /* help: "integer"  */
#line 3253 "parser.y"
                          {
			    outputMode(); sollya_print_help_text("integer");
                          }
#line 9737 "parser.c"
    break;

  case 642: /* help: "string"  */
#line 3257 "parser.y"
                          {
			    outputMode(); sollya_print_help_text("string");
                          }
#line 9745 "parser.c"
    break;

  case 643: /* help: "boolean"  */
#line 3261 "parser.y"
                          {
			    outputMode(); sollya_print_help_text("boolean");
                          }
#line 9753 "parser.c"
    break;

  case 644: /* help: "list"  */
#line 3265 "parser.y"
                          {
			    outputMode(); sollya_print_help_text("list");
			  }
#line 9761 "parser.c"
    break;

  case 645: /* help: "of"  */
#line 3269 "parser.y"
                          {
			    outputMode(); sollya_print_help_text("of");
			  }
#line 9769 "parser.c"
    break;

  case 646: /* help: "var"  */
#line 3273 "parser.y"
                          {
			    outputMode(); sollya_print_help_text("var");
                          }
#line 9777 "parser.c"
    break;

  case 647: /* help: "nop"  */
#line 3277 "parser.y"
                          {
			    outputMode(); sollya_print_help_text("nop");
                          }
#line 9785 "parser.c"
    break;

  case 648: /* help: "proc"  */
#line 3281 "parser.y"
                          {
			    outputMode(); sollya_print_help_text("proc");
                          }
#line 9793 "parser.c"
    break;

  case 649: /* help: "procedure"  */
#line 3285 "parser.y"
                          {
			    outputMode(); sollya_print_help_text("procedure");
                          }
#line 9801 "parser.c"
    break;

  case 650: /* help: "return"  */
#line 3289 "parser.y"
                          {
			    outputMode(); sollya_print_help_text("return");
                          }
#line 9809 "parser.c"
    break;

  case 651: /* help: "help"  */
#line 3293 "parser.y"
                          {
#if defined(WARN_IF_NO_HELP_TEXT) && WARN_IF_NO_HELP_TEXT
#warning "The old WARN_IF_NO_HELP_TEXT option is no longer supported. Run something like 'grep \"sollya_print_help_text\" parser.y | sed -n -e 's/^.*sollya_print_help_text(\"\\([^\"]*\\)\");.*$/\\1/gp;' | sort | while read topic; do  if ! grep -q '\"'\"$topic\"'\"' sollya-help.c; then echo \"$topic\"; fi; done' for a similar result."
#endif

			    outputMode(); sollyaPrintf("Type \"help <keyword>;\" for help on the keyword <keyword>.\nFor example type \"help implementpoly;\" for help on the command \"implementpoly\".\n\n");
			    sollyaPrintf("Possible keywords in %s are:\n",PACKAGE_NAME);
			    sollyaPrintf("- !\n");
			    sollyaPrintf("- !=\n");
			    sollyaPrintf("- &&\n");
			    sollyaPrintf("- (\n");
			    sollyaPrintf("- )\n");
			    sollyaPrintf("- *\n");
			    sollyaPrintf("- +\n");
			    sollyaPrintf("- ,\n");
			    sollyaPrintf("- -\n");
			    sollyaPrintf("- .\n");
			    sollyaPrintf("- ...\n");
			    sollyaPrintf("- .:\n");
			    sollyaPrintf("- /\n");
			    sollyaPrintf("- :.\n");
			    sollyaPrintf("- :=\n");
			    sollyaPrintf("- ; (separator in ranges)\n");
			    sollyaPrintf("- <\n");
			    sollyaPrintf("- =\n");
			    sollyaPrintf("- ==\n");
			    sollyaPrintf("- >\n");
			    sollyaPrintf("- @\n");
			    sollyaPrintf("- {\n");
			    sollyaPrintf("- [|\n");
			    sollyaPrintf("- |]\n");
			    sollyaPrintf("- ||\n");
			    sollyaPrintf("- }\n");
			    sollyaPrintf("- ~\n");
			    sollyaPrintf("- [\n");
			    sollyaPrintf("- ]\n");
			    sollyaPrintf("- ^\n");
			    sollyaPrintf("- _x_\n");
			    sollyaPrintf("- D\n");
			    sollyaPrintf("- DD\n");
			    sollyaPrintf("- DE\n");
			    sollyaPrintf("- HP\n");
			    sollyaPrintf("- QD\n");
			    sollyaPrintf("- Pi\n");
			    sollyaPrintf("- RD\n");
			    sollyaPrintf("- RN\n");
			    sollyaPrintf("- RU\n");
			    sollyaPrintf("- RZ\n");
			    sollyaPrintf("- SG\n");
			    sollyaPrintf("- TD\n");
			    sollyaPrintf("- abs\n");
			    sollyaPrintf("- absolute\n");
			    sollyaPrintf("- accurateinfnorm\n");
			    sollyaPrintf("- acos\n");
			    sollyaPrintf("- acosh\n");
			    sollyaPrintf("- annotatefunction\n");
			    sollyaPrintf("- asciiplot\n");
			    sollyaPrintf("- asin\n");
			    sollyaPrintf("- asinh\n");
			    sollyaPrintf("- atan\n");
			    sollyaPrintf("- atanh\n");
			    sollyaPrintf("- autodiff\n");
			    sollyaPrintf("- autosimplify\n");
			    sollyaPrintf("- bashevaluate\n");
			    sollyaPrintf("- bashexecute\n");
			    sollyaPrintf("- begin\n");
			    sollyaPrintf("- bezout\n");
			    sollyaPrintf("- binary\n");
			    sollyaPrintf("- bind\n");
			    sollyaPrintf("- boolean\n");
			    sollyaPrintf("- by\n");
			    sollyaPrintf("- canonical\n");
			    sollyaPrintf("- ceil\n");
			    sollyaPrintf("- chebyshevform\n");
			    sollyaPrintf("- checkinfnorm\n");
			    sollyaPrintf("- coeff\n");
			    sollyaPrintf("- composepolynomials\n");
			    sollyaPrintf("- constant\n");
			    sollyaPrintf("- cos\n");
			    sollyaPrintf("- cosh\n");
			    sollyaPrintf("- decimal\n");
			    sollyaPrintf("- default\n");
			    sollyaPrintf("- degree\n");
			    sollyaPrintf("- denominator\n");
			    sollyaPrintf("- diam\n");
			    sollyaPrintf("- dieonerrormode\n");
			    sollyaPrintf("- diff\n");
			    sollyaPrintf("- dirtyfindzeros\n");
			    sollyaPrintf("- dirtyinfnorm\n");
			    sollyaPrintf("- dirtyintegral\n");
			    sollyaPrintf("- dirtysimplify\n");
			    sollyaPrintf("- display\n");
			    sollyaPrintf("- div\n");
			    sollyaPrintf("- do\n");
			    sollyaPrintf("- double\n");
			    sollyaPrintf("- doubledouble\n");
			    sollyaPrintf("- doubleextended\n");
			    sollyaPrintf("- dyadic\n");
			    sollyaPrintf("- else\n");
			    sollyaPrintf("- end\n");
			    sollyaPrintf("- erf\n");
			    sollyaPrintf("- erfc\n");
			    sollyaPrintf("- error\n");
			    sollyaPrintf("- evaluate\n");
			    sollyaPrintf("- execute\n");
			    sollyaPrintf("- exp\n");
			    sollyaPrintf("- expand\n");
			    sollyaPrintf("- expm1\n");
			    sollyaPrintf("- exponent\n");
			    sollyaPrintf("- externaldata\n");
			    sollyaPrintf("- externalplot\n");
			    sollyaPrintf("- externalproc\n");
			    sollyaPrintf("- false\n");
			    sollyaPrintf("- file\n");
			    sollyaPrintf("- findzeros\n");
			    sollyaPrintf("- fixed\n");
			    sollyaPrintf("- floating\n");
			    sollyaPrintf("- floor\n");
			    sollyaPrintf("- for\n");
			    sollyaPrintf("- fpfindzeros\n");
			    sollyaPrintf("- fpminimax\n");
			    sollyaPrintf("- from\n");
			    sollyaPrintf("- fullparentheses\n");
			    sollyaPrintf("- function\n");
			    sollyaPrintf("- gcd\n");
			    sollyaPrintf("- getsuppressedmessages\n");
			    sollyaPrintf("- getbacktrace\n");
			    sollyaPrintf("- guessdegree\n");
			    sollyaPrintf("- halfprecision\n");
			    sollyaPrintf("- head\n");
			    sollyaPrintf("- help\n");
			    sollyaPrintf("- hexadecimal\n");
			    sollyaPrintf("- honorcoeffprec\n");
			    sollyaPrintf("- hopitalrecursions\n");
			    sollyaPrintf("- horner\n");
			    sollyaPrintf("- if\n");
			    sollyaPrintf("- interpolate\n");
			    sollyaPrintf("- implementpoly\n");
			    sollyaPrintf("- implementconstant\n");
			    sollyaPrintf("- in\n");
			    sollyaPrintf("- inf\n");
			    sollyaPrintf("- infnorm\n");
			    sollyaPrintf("- integer\n");
			    sollyaPrintf("- integral\n");
			    sollyaPrintf("- isbound\n");
			    sollyaPrintf("- isevaluable\n");
			    sollyaPrintf("- length\n");
			    sollyaPrintf("- library\n");
			    sollyaPrintf("- libraryconstant\n");
			    sollyaPrintf("- list\n");
			    sollyaPrintf("- log\n");
			    sollyaPrintf("- log10\n");
			    sollyaPrintf("- log1p\n");
			    sollyaPrintf("- log2\n");
			    sollyaPrintf("- mantissa\n");
			    sollyaPrintf("- match\n");
			    sollyaPrintf("- max\n");
			    sollyaPrintf("- mid\n");
			    sollyaPrintf("- midpointmode\n");
			    sollyaPrintf("- min\n");
			    sollyaPrintf("- mod\n");
			    sollyaPrintf("- nearestint\n");
			    sollyaPrintf("- numberroots\n");
			    sollyaPrintf("- nop\n");
			    sollyaPrintf("- numerator\n");
			    sollyaPrintf("- object\n");
			    sollyaPrintf("- objectname\n");
			    sollyaPrintf("- of\n");
			    sollyaPrintf("- off\n");
			    sollyaPrintf("- on\n");
			    sollyaPrintf("- parse\n");
			    sollyaPrintf("- perturb\n");
			    sollyaPrintf("- pi\n");
			    sollyaPrintf("- plot\n");
			    sollyaPrintf("- points\n");
			    sollyaPrintf("- postscript\n");
			    sollyaPrintf("- postscriptfile\n");
			    sollyaPrintf("- powers\n");
			    sollyaPrintf("- prec\n");
			    sollyaPrintf("- precision\n");
			    sollyaPrintf("- print\n");
			    sollyaPrintf("- printbinary\n");
			    sollyaPrintf("- printdouble\n");
			    sollyaPrintf("- printexpansion\n");
			    sollyaPrintf("- printfloat\n");
			    sollyaPrintf("- printhexa\n");
			    sollyaPrintf("- printsingle\n");
			    sollyaPrintf("- printxml\n");
			    sollyaPrintf("- proc\n");
			    sollyaPrintf("- procedure\n");
			    sollyaPrintf("- quad\n");
			    sollyaPrintf("- quit\n");
			    sollyaPrintf("- range\n");
			    sollyaPrintf("- rationalapprox\n");
			    sollyaPrintf("- rationalmode\n");
			    sollyaPrintf("- readfile\n");
			    sollyaPrintf("- readxml\n");
			    sollyaPrintf("- relative\n");
			    sollyaPrintf("- remez\n");
			    sollyaPrintf("- rename\n");
			    sollyaPrintf("- restart\n");
			    sollyaPrintf("- return\n");
			    sollyaPrintf("- revert\n");
			    sollyaPrintf("- round\n");
			    sollyaPrintf("- roundcoefficients\n");
			    sollyaPrintf("- roundcorrectly\n");
			    sollyaPrintf("- roundingwarnings\n");
			    sollyaPrintf("- searchgal\n");
			    sollyaPrintf("- showmessagenumbers\n");
			    sollyaPrintf("- simplify\n");
			    sollyaPrintf("- sin\n");
			    sollyaPrintf("- single\n");
			    sollyaPrintf("- sinh\n");
			    sollyaPrintf("- sort\n");
			    sollyaPrintf("- sqrt\n");
			    sollyaPrintf("- string\n");
			    sollyaPrintf("- subpoly\n");
			    sollyaPrintf("- substitute\n");
			    sollyaPrintf("- sup\n");
			    sollyaPrintf("- supnorm\n");
			    sollyaPrintf("- suppressmessage\n");
			    sollyaPrintf("- tail\n");
			    sollyaPrintf("- tan\n");
			    sollyaPrintf("- tanh\n");
			    sollyaPrintf("- taylor\n");
			    sollyaPrintf("- taylorform\n");
			    sollyaPrintf("- taylorrecursions\n");
			    sollyaPrintf("- then\n");
			    sollyaPrintf("- time\n");
			    sollyaPrintf("- timing\n");
			    sollyaPrintf("- to\n");
			    sollyaPrintf("- tripledouble\n");
			    sollyaPrintf("- true\n");
			    sollyaPrintf("- unsuppressmessage\n");
			    sollyaPrintf("- var\n");
			    sollyaPrintf("- verbosity\n");
			    sollyaPrintf("- version\n");
			    sollyaPrintf("- void\n");
			    sollyaPrintf("- while\n");
			    sollyaPrintf("- with\n");
			    sollyaPrintf("- worstcase\n");
			    sollyaPrintf("- write\n");
			    sollyaPrintf("- zerodenominators\n");
			    sollyaPrintf("\n");
                          }
#line 10059 "parser.c"
    break;


#line 10063 "parser.c"

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
      yyerror (scanner, YY_("syntax error"));
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
                      yytoken, &yylval, scanner);
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
                  YY_ACCESSING_SYMBOL (yystate), yyvsp, scanner);
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
  yyerror (scanner, YY_("memory exhausted"));
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
                  yytoken, &yylval, scanner);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp, scanner);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

