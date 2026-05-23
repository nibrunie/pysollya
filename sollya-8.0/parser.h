/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison interface for Yacc-like parsers in C

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

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

#line 564 "parser.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif




int yyparse (void* scanner);


#endif /* !YY_YY_PARSER_H_INCLUDED  */
