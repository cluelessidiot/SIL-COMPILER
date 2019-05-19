/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

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

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.0.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 1 "arith.y" /* yacc.c:339  */

#include<stdio.h>
#include<stdlib.h>
#include "arith.c"
#define YYSTYPE tnode *
int yyerror(char const *);
int yylex(void);
void createSymbolTableEntry(tnode *);
void createParamNode(TypeTable * , char *, int );
void addParam(param *);
void createLsymbolEntries(param *);
void argcheck(char *, tnode *, param *, int);
void paramcheck(char *);
void addfield();
MemberFuncList *checkMemberFunc(ClassTable *, char *);


#line 84 "y.tab.c" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "y.tab.h".  */
#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    NUM = 258,
    TXT = 259,
    PLUS = 260,
    MINUS = 261,
    MUL = 262,
    DIV = 263,
    ASSIGN = 264,
    WRITE = 265,
    READ = 266,
    ID = 267,
    BEGINTK = 268,
    END = 269,
    EQ = 270,
    NE = 271,
    LT = 272,
    GT = 273,
    LE = 274,
    GE = 275,
    IF = 276,
    THEN = 277,
    ELSE = 278,
    ENDIF = 279,
    WHILE = 280,
    DO = 281,
    ENDWHILE = 282,
    BREAKTK = 283,
    CONTINUETK = 284,
    BRKPTK = 285,
    REPEAT = 286,
    UNTIL = 287,
    DECL = 288,
    ENDDECL = 289,
    INT = 290,
    STR = 291,
    ADDRTK = 292,
    MAINTK = 293,
    RETURN = 294,
    ANDTK = 295,
    ORTK = 296,
    NOTTK = 297,
    TUPLE = 298,
    TYPETK = 299,
    ENDTYPE = 300,
    NULLTK = 301,
    ALLOC = 302,
    INITIALIZE = 303,
    FREE = 304,
    MOD = 305,
    CLASS = 306,
    ENDCLASS = 307,
    DELETE = 308,
    NEW = 309,
    EXTENDS = 310,
    SELF = 311
  };
#endif
/* Tokens.  */
#define NUM 258
#define TXT 259
#define PLUS 260
#define MINUS 261
#define MUL 262
#define DIV 263
#define ASSIGN 264
#define WRITE 265
#define READ 266
#define ID 267
#define BEGINTK 268
#define END 269
#define EQ 270
#define NE 271
#define LT 272
#define GT 273
#define LE 274
#define GE 275
#define IF 276
#define THEN 277
#define ELSE 278
#define ENDIF 279
#define WHILE 280
#define DO 281
#define ENDWHILE 282
#define BREAKTK 283
#define CONTINUETK 284
#define BRKPTK 285
#define REPEAT 286
#define UNTIL 287
#define DECL 288
#define ENDDECL 289
#define INT 290
#define STR 291
#define ADDRTK 292
#define MAINTK 293
#define RETURN 294
#define ANDTK 295
#define ORTK 296
#define NOTTK 297
#define TUPLE 298
#define TYPETK 299
#define ENDTYPE 300
#define NULLTK 301
#define ALLOC 302
#define INITIALIZE 303
#define FREE 304
#define MOD 305
#define CLASS 306
#define ENDCLASS 307
#define DELETE 308
#define NEW 309
#define EXTENDS 310
#define SELF 311

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 247 "y.tab.c" /* yacc.c:358  */

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

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

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
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


#if ! defined yyoverflow || YYERROR_VERBOSE

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
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
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
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  7
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   717

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  66
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  51
/* YYNRULES -- Number of rules.  */
#define YYNRULES  122
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  288

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   311

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      60,    61,     2,     2,    62,     2,    65,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    59,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    63,     2,    64,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    57,     2,    58,     2,     2,     2,     2,
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
      55,    56
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    34,    34,    35,    36,    39,    40,    43,    44,    47,
      49,    50,    53,    54,    57,    59,    60,    63,    65,    66,
      70,    71,    74,    75,    78,    78,    84,    85,    87,    89,
      90,    93,    94,    97,    98,   101,   103,   104,   107,   108,
     112,   113,   116,   125,   126,   127,   130,   132,   141,   142,
     143,   146,   147,   150,   152,   153,   156,   157,   160,   162,
     171,   172,   176,   177,   178,   179,   180,   181,   182,   183,
     186,   189,   191,   193,   194,   197,   199,   201,   203,   204,
     205,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   229,   230,   231,   232,   233,   234,   235,   238,   239,
     240,   243,   246,   248,   251,   252,   254,   257,   301,   321,
     349,   359,   369
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "NUM", "TXT", "PLUS", "MINUS", "MUL",
  "DIV", "ASSIGN", "WRITE", "READ", "ID", "BEGINTK", "END", "EQ", "NE",
  "LT", "GT", "LE", "GE", "IF", "THEN", "ELSE", "ENDIF", "WHILE", "DO",
  "ENDWHILE", "BREAKTK", "CONTINUETK", "BRKPTK", "REPEAT", "UNTIL", "DECL",
  "ENDDECL", "INT", "STR", "ADDRTK", "MAINTK", "RETURN", "ANDTK", "ORTK",
  "NOTTK", "TUPLE", "TYPETK", "ENDTYPE", "NULLTK", "ALLOC", "INITIALIZE",
  "FREE", "MOD", "CLASS", "ENDCLASS", "DELETE", "NEW", "EXTENDS", "SELF",
  "'{'", "'}'", "';'", "'('", "')'", "','", "'['", "']'", "'.'", "$accept",
  "Program", "ClassDefBlock", "ClassDefList", "ClassDef", "Cname",
  "Fieldlists", "Fld", "MethodDecl", "Mdecl", "MethodDefns",
  "TypeDefBlock", "TypeDefList", "TypeDef", "$@1", "FieldDeclList",
  "FieldDecl", "GDeclBlock", "GDeclList", "GDecl", "Tuple", "GidList",
  "Gid", "FDefBlock", "FDef", "ParamList", "Param", "Type", "LDeclBlock",
  "LDeclList", "LDecl", "IdList", "Body", "RetStmt", "MainBlock", "Slist",
  "Stmt", "InputStmt", "OutputStmt", "AsgStmt", "IfStmt", "WhileStmt",
  "DoWhileStmt", "UntilStmt", "PlainStmt", "expr", "ArgList", "Iden",
  "Id1", "Field", "FieldFunction", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   123,   125,    59,
      40,    41,    44,    91,    93,    46
};
# endif

#define YYPACT_NINF -211

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-211)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -27,    29,    34,    25,     1,     8,  -211,  -211,    73,    18,
    -211,  -211,  -211,    32,    -6,  -211,    37,  -211,     4,    88,
      92,  -211,    88,    91,  -211,  -211,   116,  -211,  -211,    27,
    -211,   141,     6,    88,  -211,    21,  -211,    97,    -8,  -211,
     153,  -211,  -211,  -211,  -211,   109,   158,   -23,   106,   -35,
    -211,  -211,   112,   110,  -211,  -211,   117,   118,  -211,  -211,
     121,   171,    88,  -211,   274,   176,   179,  -211,     6,    88,
     180,    88,   136,  -211,   183,  -211,    11,  -211,    13,  -211,
       7,  -211,  -211,    30,     6,   274,  -211,   137,   138,   139,
     140,   145,   131,   274,   216,  -211,  -211,   142,  -211,  -211,
    -211,  -211,    56,  -211,    59,   175,    63,   192,    88,  -211,
       6,    88,   147,  -211,   274,   197,  -211,    84,   156,   159,
       6,     6,   207,   213,   126,   274,   274,   274,   274,   274,
     274,   274,   274,   274,   274,   274,   274,   274,   164,   217,
    -211,   173,    23,   215,  -211,    88,   177,    -2,  -211,   227,
      22,  -211,   667,    65,   182,  -211,  -211,   189,   193,   203,
     198,  -211,   144,   144,   272,   272,    84,    84,    84,    84,
      84,    84,  -211,  -211,   272,   274,   205,   175,  -211,     7,
      43,  -211,   534,   185,    67,  -211,  -211,  -211,  -211,   274,
     274,  -211,  -211,  -211,   274,   255,   274,   215,    40,  -211,
    -211,  -211,   208,   209,   219,   222,   625,   224,   225,   226,
     625,   274,   253,   534,  -211,  -211,  -211,  -211,  -211,  -211,
    -211,  -211,  -211,   267,  -211,   234,   667,    75,    77,  -211,
      94,   236,  -211,     7,   274,     6,   274,   274,   637,  -211,
    -211,  -211,   467,   444,  -211,   283,  -211,   274,  -211,  -211,
    -211,  -211,  -211,  -211,   330,   237,   336,   387,   239,   274,
    -211,  -211,   450,   241,   242,   280,   277,   274,   499,  -211,
    -211,  -211,   625,   625,   393,  -211,   501,   567,    -5,   625,
     245,   247,  -211,   596,  -211,  -211,   248,  -211
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
      21,     0,     0,     6,     0,     0,    23,     1,     0,     0,
      24,    20,    22,    10,     0,     8,     0,    47,     0,     0,
       0,     4,     0,     0,     5,     7,     0,    30,    35,     0,
      32,     0,     0,     0,    41,     0,     3,     0,     0,    27,
       0,    11,    13,    29,    31,     0,     0,   114,     0,     0,
      37,    38,   113,   116,    40,     2,     0,     0,    25,    26,
       0,     0,    45,   115,     0,     0,     0,    33,     0,    45,
       0,    45,     0,    28,     0,    12,     0,    16,     0,    44,
       0,    96,    97,   114,     0,     0,   101,     0,     0,     0,
       0,     0,     0,     0,     0,    98,   113,   116,   107,   117,
     119,    36,     0,   118,     0,    50,     0,     0,     0,    15,
       0,     0,   114,    46,   109,     0,    99,    95,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   111,     0,
      39,     0,     0,     0,    14,    45,     0,     0,    19,     0,
       0,    43,   110,     0,   117,   104,   102,     0,     0,     0,
     119,    86,    81,    82,    83,    84,    91,    92,    87,    88,
      89,    90,    93,    94,    85,     0,   118,    50,    49,     0,
       0,    52,     0,     0,     0,     9,    18,    34,   100,     0,
     109,   103,   105,   106,   109,     0,   109,     0,     0,    55,
      48,    51,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    61,    62,    63,    64,    65,    66,
      67,    68,    69,     0,    59,     0,   108,     0,     0,   112,
       0,     0,    53,     0,     0,     0,     0,     0,     0,    79,
      80,    78,     0,     0,    57,     0,    60,     0,    17,   121,
     120,   122,    42,    54,     0,     0,     0,     0,     0,     0,
      58,    56,     0,     0,     0,     0,     0,     0,     0,    72,
      71,    70,     0,     0,     0,    77,     0,     0,     0,     0,
       0,     0,    76,     0,    74,    75,     0,    73
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -211,  -211,  -211,  -211,   294,  -211,  -211,  -211,  -211,   233,
    -211,  -211,  -211,   305,  -211,  -211,   276,  -211,  -211,   286,
    -211,   214,   249,  -211,   -28,   -62,   218,    -7,   148,  -211,
     146,  -211,   134,   105,    49,  -181,  -210,  -211,  -211,  -211,
    -211,  -211,  -211,  -211,  -211,   -21,  -125,   -24,   -31,   -32,
    -211
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     9,    14,    15,    16,    61,    75,    76,    77,
     147,     3,     5,     6,    22,    38,    39,    19,    29,    30,
      31,    49,    50,    33,    34,    78,    79,    80,   143,   180,
     181,   198,   183,   212,    21,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   152,   153,    95,    96,    97,
      98
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint16 yytable[] =
{
      53,    52,    20,   246,    17,    54,    13,   102,    51,   104,
      17,    32,    35,    46,    46,    40,    17,     1,    47,   112,
       4,   273,    32,   107,    67,   238,    35,    68,   246,   242,
      17,    40,   246,    56,     7,    17,    53,    52,    27,    17,
      64,     4,    65,    94,    51,   108,    24,    28,    53,   113,
      58,    18,    53,    11,   282,    17,   185,   178,    10,    37,
     116,    43,    48,    48,   117,   227,   246,   246,    36,   228,
      28,   230,   124,   246,   110,   111,     8,   200,    53,    52,
     148,   187,    55,   184,    68,    13,    51,    23,    53,    53,
     114,   276,   277,    64,    26,   115,   157,   158,   283,   232,
      17,   149,   233,    41,   162,   163,   164,   165,   166,   167,
     168,   169,   170,   171,   172,   173,   174,   140,   111,   186,
     141,   111,   144,   145,   135,   136,   188,   189,   225,   111,
      37,   125,   126,   127,   128,   179,   249,   189,   250,   189,
     149,   129,   130,   131,   132,   133,   134,    53,   199,    42,
      53,   127,   128,    45,   195,   251,   189,    57,   223,   129,
     130,   131,   132,   133,   134,    60,   135,   136,   226,    62,
      63,    66,    69,   179,    53,    70,   137,    71,    53,    72,
      73,    53,   223,    74,   135,   136,   223,   161,    99,   223,
     243,   100,   103,   105,   137,   106,   123,   118,   119,   120,
     121,    53,   253,    53,   146,   122,    53,   139,   142,   154,
      53,   255,    65,   254,   223,   256,   257,   155,   223,   159,
     156,   125,   126,   127,   128,   160,   262,   175,   182,   176,
     177,   129,   130,   131,   132,   133,   134,   145,   268,    56,
      53,    53,   190,   224,    53,    53,   274,    53,   223,   223,
     191,    53,   223,   223,   192,   223,   135,   136,   194,   223,
     125,   126,   127,   128,   193,   196,   137,   244,   234,   235,
     129,   130,   131,   132,   133,   134,   247,    81,    82,   236,
     138,    46,   237,   239,   240,   241,    83,   129,   130,   131,
     132,   133,   134,   248,   252,   135,   136,   261,   264,   267,
     270,   271,   272,   273,   284,   137,   285,   287,    25,   109,
      12,    84,   135,   136,    59,    44,    85,   101,   245,   229,
      86,    87,    88,    89,   150,   197,   201,    90,    91,   151,
      92,   231,     0,     0,    93,   125,   126,   127,   128,     0,
       0,   125,   126,   127,   128,   129,   130,   131,   132,   133,
     134,   129,   130,   131,   132,   133,   134,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     135,   136,     0,     0,     0,     0,   135,   136,     0,     0,
     137,     0,     0,     0,     0,     0,   137,     0,     0,     0,
       0,   263,   125,   126,   127,   128,     0,   265,   125,   126,
     127,   128,   129,   130,   131,   132,   133,   134,   129,   130,
     131,   132,   133,   134,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   135,   136,     0,
       0,     0,     0,   135,   136,     0,     0,   137,     0,     0,
       0,     0,     0,   137,     0,     0,     0,     0,   266,   125,
     126,   127,   128,     0,   278,   125,   126,   127,   128,   129,
     130,   131,   132,   133,   134,   129,   130,   131,   132,   133,
     134,     0,     0,     0,    46,     0,     0,   202,   203,    47,
       0,     0,     0,     0,   135,   136,     0,     0,   204,     0,
     135,   136,   205,   206,   137,   207,   208,   209,   210,   259,
     137,     0,     0,   260,   125,   126,   127,   128,    46,   269,
       0,   202,   203,    47,   129,   130,   131,   132,   133,   134,
       0,     0,   204,    48,   279,   280,   205,   206,     0,   207,
     208,   209,   210,     0,     0,     0,     0,     0,     0,   135,
     136,    46,     0,     0,   202,   203,    47,     0,     0,   137,
       0,     0,     0,     0,     0,   204,     0,    48,   275,   205,
     206,     0,   207,   208,   209,   210,     0,     0,     0,     0,
       0,     0,     0,   211,    46,     0,     0,   202,   203,    47,
       0,     0,     0,     0,     0,     0,     0,     0,   204,     0,
      48,     0,   205,   206,   281,   207,   208,   209,   210,     0,
       0,     0,     0,    46,     0,     0,   202,   203,    47,     0,
       0,     0,     0,     0,     0,     0,     0,   204,     0,     0,
     286,   205,   206,    48,   207,   208,   209,   210,     0,     0,
       0,     0,    46,     0,     0,   202,   203,    47,     0,     0,
       0,     0,     0,     0,    46,     0,   204,   202,   203,    47,
     205,   206,    48,   207,   208,   209,   210,     0,   204,     0,
       0,     0,   258,   206,     0,   207,   208,   209,   210,     0,
       0,     0,   125,   126,   127,   128,     0,     0,     0,     0,
       0,    48,   129,   130,   131,   132,   133,   134,     0,     0,
       0,     0,     0,    48,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   135,   136,     0,
       0,     0,     0,     0,     0,     0,     0,   137
};

static const yytype_int16 yycheck[] =
{
      32,    32,     9,   213,    12,    33,    12,    69,    32,    71,
      12,    18,    19,     7,     7,    22,    12,    44,    12,    12,
      12,    26,    29,    12,    59,   206,    33,    62,   238,   210,
      12,    38,   242,    12,     0,    12,    68,    68,    34,    12,
      63,    12,    65,    64,    68,    34,    52,    43,    80,    80,
      58,    33,    84,    45,    59,    12,    58,    34,    57,    38,
      84,    34,    56,    56,    85,   190,   276,   277,    19,   194,
      43,   196,    93,   283,    61,    62,    51,    34,   110,   110,
     108,    59,    33,   145,    62,    12,   110,    55,   120,   121,
      60,   272,   273,    63,    57,    65,   120,   121,   279,    59,
      12,   108,    62,    12,   125,   126,   127,   128,   129,   130,
     131,   132,   133,   134,   135,   136,   137,    61,    62,   147,
      61,    62,    59,    60,    40,    41,    61,    62,    61,    62,
      38,     5,     6,     7,     8,   142,    61,    62,    61,    62,
     147,    15,    16,    17,    18,    19,    20,   179,   179,    33,
     182,     7,     8,    12,   175,    61,    62,    60,   182,    15,
      16,    17,    18,    19,    20,    12,    40,    41,   189,    60,
      12,    65,    60,   180,   206,    65,    50,    60,   210,    61,
      59,   213,   206,    12,    40,    41,   210,    61,    12,   213,
     211,    12,    12,    57,    50,    12,    65,    60,    60,    60,
      60,   233,   233,   235,    12,    60,   238,    65,    33,    12,
     242,   235,    65,   234,   238,   236,   237,    61,   242,    12,
      61,     5,     6,     7,     8,    12,   247,    63,    13,    12,
      57,    15,    16,    17,    18,    19,    20,    60,   259,    12,
     272,   273,    60,    58,   276,   277,   267,   279,   272,   273,
      61,   283,   276,   277,    61,   279,    40,    41,    60,   283,
       5,     6,     7,     8,    61,    60,    50,    14,    60,    60,
      15,    16,    17,    18,    19,    20,     9,     3,     4,    60,
      64,     7,    60,    59,    59,    59,    12,    15,    16,    17,
      18,    19,    20,    59,    58,    40,    41,    14,    61,    60,
      59,    59,    22,    26,    59,    50,    59,    59,    14,    76,
       5,    37,    40,    41,    38,    29,    42,    68,   213,    64,
      46,    47,    48,    49,   110,   177,   180,    53,    54,   111,
      56,   197,    -1,    -1,    60,     5,     6,     7,     8,    -1,
      -1,     5,     6,     7,     8,    15,    16,    17,    18,    19,
      20,    15,    16,    17,    18,    19,    20,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      40,    41,    -1,    -1,    -1,    -1,    40,    41,    -1,    -1,
      50,    -1,    -1,    -1,    -1,    -1,    50,    -1,    -1,    -1,
      -1,    61,     5,     6,     7,     8,    -1,    61,     5,     6,
       7,     8,    15,    16,    17,    18,    19,    20,    15,    16,
      17,    18,    19,    20,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    40,    41,    -1,
      -1,    -1,    -1,    40,    41,    -1,    -1,    50,    -1,    -1,
      -1,    -1,    -1,    50,    -1,    -1,    -1,    -1,    61,     5,
       6,     7,     8,    -1,    61,     5,     6,     7,     8,    15,
      16,    17,    18,    19,    20,    15,    16,    17,    18,    19,
      20,    -1,    -1,    -1,     7,    -1,    -1,    10,    11,    12,
      -1,    -1,    -1,    -1,    40,    41,    -1,    -1,    21,    -1,
      40,    41,    25,    26,    50,    28,    29,    30,    31,    32,
      50,    -1,    -1,    59,     5,     6,     7,     8,     7,    59,
      -1,    10,    11,    12,    15,    16,    17,    18,    19,    20,
      -1,    -1,    21,    56,    23,    24,    25,    26,    -1,    28,
      29,    30,    31,    -1,    -1,    -1,    -1,    -1,    -1,    40,
      41,     7,    -1,    -1,    10,    11,    12,    -1,    -1,    50,
      -1,    -1,    -1,    -1,    -1,    21,    -1,    56,    59,    25,
      26,    -1,    28,    29,    30,    31,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    39,     7,    -1,    -1,    10,    11,    12,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    21,    -1,
      56,    -1,    25,    26,    27,    28,    29,    30,    31,    -1,
      -1,    -1,    -1,     7,    -1,    -1,    10,    11,    12,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    21,    -1,    -1,
      24,    25,    26,    56,    28,    29,    30,    31,    -1,    -1,
      -1,    -1,     7,    -1,    -1,    10,    11,    12,    -1,    -1,
      -1,    -1,    -1,    -1,     7,    -1,    21,    10,    11,    12,
      25,    26,    56,    28,    29,    30,    31,    -1,    21,    -1,
      -1,    -1,    25,    26,    -1,    28,    29,    30,    31,    -1,
      -1,    -1,     5,     6,     7,     8,    -1,    -1,    -1,    -1,
      -1,    56,    15,    16,    17,    18,    19,    20,    -1,    -1,
      -1,    -1,    -1,    56,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    40,    41,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    50
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    44,    67,    77,    12,    78,    79,     0,    51,    68,
      57,    45,    79,    12,    69,    70,    71,    12,    33,    83,
      93,   100,    80,    55,    52,    70,    57,    34,    43,    84,
      85,    86,    93,    89,    90,    93,   100,    38,    81,    82,
      93,    12,    33,    34,    85,    12,     7,    12,    56,    87,
      88,   113,   114,   115,    90,   100,    12,    60,    58,    82,
      12,    72,    60,    12,    63,    65,    65,    59,    62,    60,
      65,    60,    61,    59,    12,    73,    74,    75,    91,    92,
      93,     3,     4,    12,    37,    42,    46,    47,    48,    49,
      53,    54,    56,    60,   111,   113,   114,   115,   116,    12,
      12,    88,    91,    12,    91,    57,    12,    12,    34,    75,
      61,    62,    12,   114,    60,    65,   113,   111,    60,    60,
      60,    60,    60,    65,   111,     5,     6,     7,     8,    15,
      16,    17,    18,    19,    20,    40,    41,    50,    64,    65,
      61,    61,    33,    94,    59,    60,    12,    76,    90,    93,
      87,    92,   111,   112,    12,    61,    61,   113,   113,    12,
      12,    61,   111,   111,   111,   111,   111,   111,   111,   111,
     111,   111,   111,   111,   111,    63,    12,    57,    34,    93,
      95,    96,    13,    98,    91,    58,    90,    59,    61,    62,
      60,    61,    61,    61,    60,   111,    60,    94,    97,   114,
      34,    96,    10,    11,    21,    25,    26,    28,    29,    30,
      31,    39,    99,   101,   102,   103,   104,   105,   106,   107,
     108,   109,   110,   113,    58,    61,   111,   112,   112,    64,
     112,    98,    59,    62,    60,    60,    60,    60,   101,    59,
      59,    59,   101,   111,    14,    99,   102,     9,    59,    61,
      61,    61,    58,   114,   111,   113,   111,   111,    25,    32,
      59,    14,   111,    61,    61,    61,    61,    60,   111,    59,
      59,    59,    22,    26,   111,    59,   101,   101,    61,    23,
      24,    27,    59,   101,    59,    59,    24,    59
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    66,    67,    67,    67,    68,    68,    69,    69,    70,
      71,    71,    72,    72,    73,    74,    74,    75,    76,    76,
      77,    77,    78,    78,    80,    79,    81,    81,    82,    83,
      83,    84,    84,    85,    85,    86,    87,    87,    88,    88,
      89,    89,    90,    91,    91,    91,    92,    93,    94,    94,
      94,    95,    95,    96,    97,    97,    98,    98,    99,   100,
     101,   101,   102,   102,   102,   102,   102,   102,   102,   102,
     103,   104,   105,   106,   106,   107,   108,   109,   110,   110,
     110,   111,   111,   111,   111,   111,   111,   111,   111,   111,
     111,   111,   111,   111,   111,   111,   111,   111,   111,   111,
     111,   111,   111,   111,   111,   111,   111,   111,   112,   112,
     112,   113,   113,   113,   114,   114,   114,   115,   115,   115,
     116,   116,   116
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     5,     4,     3,     3,     0,     2,     1,     8,
       1,     3,     2,     0,     3,     2,     1,     6,     2,     1,
       3,     0,     2,     1,     0,     5,     2,     1,     3,     3,
       2,     2,     1,     3,     7,     1,     3,     1,     1,     4,
       2,     1,     9,     3,     1,     0,     2,     1,     3,     2,
       0,     2,     1,     3,     3,     1,     4,     3,     3,     8,
       2,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       5,     5,     4,    10,     8,     8,     7,     5,     2,     2,
       2,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     2,     1,     1,     1,     2,
       4,     1,     3,     4,     3,     4,     4,     1,     3,     0,
       1,     4,     7,     1,     1,     2,     1,     3,     3,     3,
       6,     6,     6
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
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
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;                                                  \
    }                                                           \
while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



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

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
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
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                                              );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
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


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
yystrlen (const char *yystr)
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            /* Fall through.  */
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        YYSTYPE *yyvs1 = yyvs;
        yytype_int16 *yyss1 = yyss;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yystacksize);

        yyss = yyss1;
        yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yytype_int16 *yyss1 = yyss;
        union yyalloc *yyptr =
          (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
                  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

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

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
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

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

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
| yyreduce -- Do a reduction.  |
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
        case 5:
#line 39 "arith.y" /* yacc.c:1646  */
    { sp++; }
#line 1611 "y.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 40 "arith.y" /* yacc.c:1646  */
    {  }
#line 1617 "y.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 43 "arith.y" /* yacc.c:1646  */
    {  }
#line 1623 "y.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 44 "arith.y" /* yacc.c:1646  */
    {  }
#line 1629 "y.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 47 "arith.y" /* yacc.c:1646  */
    { createVfuncTable(); currclass=NULL; }
#line 1635 "y.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 49 "arith.y" /* yacc.c:1646  */
    { currclass=CInstall((yyvsp[0])->varname,NULL); free((yyvsp[0])); }
#line 1641 "y.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 50 "arith.y" /* yacc.c:1646  */
    { currclass=CInstall((yyvsp[-2])->varname, (yyvsp[0])->varname); free((yyvsp[-2])); free((yyvsp[0])); }
#line 1647 "y.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 53 "arith.y" /* yacc.c:1646  */
    {  }
#line 1653 "y.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 54 "arith.y" /* yacc.c:1646  */
    {  }
#line 1659 "y.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 57 "arith.y" /* yacc.c:1646  */
    { Class_Finstall(currclass, (yyvsp[-2])->varname, (yyvsp[-1])->varname); free((yyvsp[-2])); free((yyvsp[-1])); }
#line 1665 "y.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 59 "arith.y" /* yacc.c:1646  */
    {  }
#line 1671 "y.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 60 "arith.y" /* yacc.c:1646  */
    {  }
#line 1677 "y.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 63 "arith.y" /* yacc.c:1646  */
    { Class_Minstall(currclass, (yyvsp[-4])->varname, TLookup((yyvsp[-5])->varname), paramlist); paramlist=NULL; }
#line 1683 "y.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 65 "arith.y" /* yacc.c:1646  */
    {  }
#line 1689 "y.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 66 "arith.y" /* yacc.c:1646  */
    {  }
#line 1695 "y.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 70 "arith.y" /* yacc.c:1646  */
    { printTypeTable(); }
#line 1701 "y.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 71 "arith.y" /* yacc.c:1646  */
    { /*Typedef can be null*/printTypeTable(); }
#line 1707 "y.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 74 "arith.y" /* yacc.c:1646  */
    {  }
#line 1713 "y.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 75 "arith.y" /* yacc.c:1646  */
    {  }
#line 1719 "y.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 78 "arith.y" /* yacc.c:1646  */
    {TInstall((yyvsp[-1])->varname,0,NULL);}
#line 1725 "y.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 78 "arith.y" /* yacc.c:1646  */
    { TypeTable *ttable=TLookup((yyvsp[-4])->varname);
																	 //fieldcheck(fieldlist);
																	 ttable->fields=fieldlist;
																	 fieldlist=NULL;
																	 ttable->size=getSize(ttable);}
#line 1735 "y.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 84 "arith.y" /* yacc.c:1646  */
    { addfield(); }
#line 1741 "y.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 85 "arith.y" /* yacc.c:1646  */
    { field->fieldIndex=0; fieldlist=field; field=NULL; }
#line 1747 "y.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 87 "arith.y" /* yacc.c:1646  */
    { field=(FieldList *)malloc(sizeof(FieldList)); field->name=(yyvsp[-1])->varname; field->type=(yyvsp[-2])->type; field->next=NULL; }
#line 1753 "y.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 89 "arith.y" /* yacc.c:1646  */
    { print_symbol_table(); }
#line 1759 "y.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 90 "arith.y" /* yacc.c:1646  */
    {  }
#line 1765 "y.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 93 "arith.y" /* yacc.c:1646  */
    {  }
#line 1771 "y.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 94 "arith.y" /* yacc.c:1646  */
    {  }
#line 1777 "y.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 97 "arith.y" /* yacc.c:1646  */
    { currtype=NULL; }
#line 1783 "y.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 98 "arith.y" /* yacc.c:1646  */
    { currtype=NULL; paramlist=NULL; declclass=NULL; }
#line 1789 "y.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 101 "arith.y" /* yacc.c:1646  */
    { currtype = TLookup("tuple"); declclass=NULL;}
#line 1795 "y.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 103 "arith.y" /* yacc.c:1646  */
    {  }
#line 1801 "y.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 104 "arith.y" /* yacc.c:1646  */
    {  }
#line 1807 "y.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 107 "arith.y" /* yacc.c:1646  */
    { createSymbolTableEntry((yyvsp[0])); }
#line 1813 "y.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 108 "arith.y" /* yacc.c:1646  */
    { Install((yyvsp[-3])->varname,currtype,0,0,0,paramlist,flabel++); /*currtype=NULL*/; paramlist=NULL;
								if((yyvsp[-3])->nodetype==POINTER){ Gsymbol *p= Lookup((yyvsp[-3])->varname); p->pointer=1; }}
#line 1820 "y.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 112 "arith.y" /* yacc.c:1646  */
    {  }
#line 1826 "y.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 113 "arith.y" /* yacc.c:1646  */
    {  }
#line 1832 "y.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 116 "arith.y" /* yacc.c:1646  */
    { //createLsymbolEntries(paramlist);  
															paramcheck((yyvsp[-7])->varname);
															print_local_table();
															CodeGenerate((yyvsp[-1]), (yyvsp[-7])->varname);
															initialize_local_table();
															paramlist=NULL;
															
															}
#line 1845 "y.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 125 "arith.y" /* yacc.c:1646  */
    { addParam(parameter); parameter=NULL; }
#line 1851 "y.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 126 "arith.y" /* yacc.c:1646  */
    { addParam(parameter), parameter=NULL; }
#line 1857 "y.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 127 "arith.y" /* yacc.c:1646  */
    {  }
#line 1863 "y.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 130 "arith.y" /* yacc.c:1646  */
    { createParamNode((yyvsp[-1])->type,(yyvsp[0])->varname,(yyvsp[0])->nodetype); currtype=oldtype; }
#line 1869 "y.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 132 "arith.y" /* yacc.c:1646  */
    { oldtype=currtype; currtype=TLookup((yyvsp[0])->varname);
			oldclass=declclass; declclass=CLookup((yyvsp[0])->varname); 
			if(declclass!=NULL){
				(yyval)=createTree(0,NULL,(yyvsp[0])->varname,CLASSNODE,NULL,NULL,NULL);
			}else{
				(yyval)=createTree(0,currtype,(yyvsp[0])->varname,TYPE,NULL,NULL,NULL);
			}
			}
#line 1882 "y.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 141 "arith.y" /* yacc.c:1646  */
    { createLsymbolEntries(paramlist);   }
#line 1888 "y.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 142 "arith.y" /* yacc.c:1646  */
    { createLsymbolEntries(paramlist);   }
#line 1894 "y.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 143 "arith.y" /* yacc.c:1646  */
    { createLsymbolEntries(paramlist);   }
#line 1900 "y.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 146 "arith.y" /* yacc.c:1646  */
    {  }
#line 1906 "y.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 147 "arith.y" /* yacc.c:1646  */
    {   }
#line 1912 "y.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 150 "arith.y" /* yacc.c:1646  */
    { currtype=NULL; }
#line 1918 "y.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 152 "arith.y" /* yacc.c:1646  */
    { LInstall((yyvsp[0])->varname, currtype,local_binding++, (yyvsp[0])->nodetype==POINTER ? 1 : 0); }
#line 1924 "y.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 153 "arith.y" /* yacc.c:1646  */
    { LInstall((yyvsp[0])->varname, currtype,local_binding++, (yyvsp[0])->nodetype==POINTER ? 1 : 0); }
#line 1930 "y.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 156 "arith.y" /* yacc.c:1646  */
    { (yyval)=createTree(0,NULL,NULL,CONN,(yyvsp[-2]),NULL,(yyvsp[-1])); }
#line 1936 "y.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 157 "arith.y" /* yacc.c:1646  */
    { (yyval)=(yyvsp[-1]); }
#line 1942 "y.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 160 "arith.y" /* yacc.c:1646  */
    { (yyval)=createTree(0,(yyvsp[-1])->type,NULL,RET, (yyvsp[-1]), NULL, NULL); }
#line 1948 "y.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 162 "arith.y" /* yacc.c:1646  */
    { if((yyvsp[-7])->type != TLookup("int")){
																yyerror("Function Main expects integer return type");
																exit(1);
															}
														print_local_table();
														CodeGenerate((yyvsp[-1]), "main");
														initialize_local_table();
														paramlist=NULL;}
#line 1961 "y.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 171 "arith.y" /* yacc.c:1646  */
    {(yyval)=createTree(0,NULL,NULL,CONN,(yyvsp[-1]),NULL,(yyvsp[0]));}
#line 1967 "y.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 172 "arith.y" /* yacc.c:1646  */
    {(yyval)=(yyvsp[0]);}
#line 1973 "y.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 176 "arith.y" /* yacc.c:1646  */
    {(yyval)=(yyvsp[0]);}
#line 1979 "y.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 177 "arith.y" /* yacc.c:1646  */
    {(yyval)=(yyvsp[0]);}
#line 1985 "y.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 178 "arith.y" /* yacc.c:1646  */
    {(yyval)=(yyvsp[0]);}
#line 1991 "y.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 179 "arith.y" /* yacc.c:1646  */
    {(yyval)=(yyvsp[0]);}
#line 1997 "y.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 180 "arith.y" /* yacc.c:1646  */
    {(yyval)=(yyvsp[0]);}
#line 2003 "y.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 181 "arith.y" /* yacc.c:1646  */
    {(yyval)=(yyvsp[0]);}
#line 2009 "y.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 182 "arith.y" /* yacc.c:1646  */
    {(yyval)=(yyvsp[0]);}
#line 2015 "y.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 183 "arith.y" /* yacc.c:1646  */
    {(yyval)=(yyvsp[0]);}
#line 2021 "y.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 186 "arith.y" /* yacc.c:1646  */
    {typecheck((yyvsp[-2])); (yyval)=createTree(0,NULL,NULL,READOP,(yyvsp[-2]),NULL,NULL);}
#line 2027 "y.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 189 "arith.y" /* yacc.c:1646  */
    {(yyval)=createTree(0,NULL,NULL,WRITEOP,(yyvsp[-2]),NULL,NULL);}
#line 2033 "y.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 191 "arith.y" /* yacc.c:1646  */
    {typecheck((yyvsp[-3])); (yyval)=createTree(0,NULL,NULL,ASS,(yyvsp[-3]),NULL,(yyvsp[-1]));}
#line 2039 "y.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 193 "arith.y" /* yacc.c:1646  */
    {(yyval)=createTree(0,NULL,NULL,IFSTMT,(yyvsp[-7]),(yyvsp[-4]),(yyvsp[-2]));}
#line 2045 "y.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 194 "arith.y" /* yacc.c:1646  */
    {(yyval)=createTree(0,NULL,NULL,IFSTMT,(yyvsp[-5]),(yyvsp[-2]),NULL);}
#line 2051 "y.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 197 "arith.y" /* yacc.c:1646  */
    {(yyval)=createTree(0,NULL,NULL,WHILESTMT,(yyvsp[-5]),NULL,(yyvsp[-2]));}
#line 2057 "y.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 199 "arith.y" /* yacc.c:1646  */
    { (yyval)=createTree(0,NULL,NULL,DOWHILESTMT,(yyvsp[-5]),NULL,(yyvsp[-2])); }
#line 2063 "y.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 201 "arith.y" /* yacc.c:1646  */
    { (yyval)=createTree(0,NULL,NULL,UNTILSTMT,(yyvsp[-3]),NULL,(yyvsp[-1])); }
#line 2069 "y.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 203 "arith.y" /* yacc.c:1646  */
    {(yyval)=createTree(0,NULL,NULL,BRKP,NULL,NULL,NULL);}
#line 2075 "y.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 204 "arith.y" /* yacc.c:1646  */
    {(yyval)=createTree(0,NULL,NULL,BREAK,NULL,NULL,NULL);}
#line 2081 "y.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 205 "arith.y" /* yacc.c:1646  */
    {(yyval)=createTree(0,NULL,NULL,CONTINUE,NULL,NULL,NULL);}
#line 2087 "y.tab.c" /* yacc.c:1646  */
    break;

  case 81:
#line 208 "arith.y" /* yacc.c:1646  */
    {(yyval)=createTree(0,TLookup("int"),NULL,PLUSOP,(yyvsp[-2]),NULL,(yyvsp[0]));}
#line 2093 "y.tab.c" /* yacc.c:1646  */
    break;

  case 82:
#line 209 "arith.y" /* yacc.c:1646  */
    {(yyval)=createTree(0,TLookup("int"),NULL,MINUSOP,(yyvsp[-2]),NULL,(yyvsp[0]));}
#line 2099 "y.tab.c" /* yacc.c:1646  */
    break;

  case 83:
#line 210 "arith.y" /* yacc.c:1646  */
    {(yyval)=createTree(0,TLookup("int"),NULL,MULOP,(yyvsp[-2]),NULL,(yyvsp[0]));}
#line 2105 "y.tab.c" /* yacc.c:1646  */
    break;

  case 84:
#line 211 "arith.y" /* yacc.c:1646  */
    {(yyval)=createTree(0,TLookup("int"),NULL,DIVOP,(yyvsp[-2]),NULL,(yyvsp[0]));}
#line 2111 "y.tab.c" /* yacc.c:1646  */
    break;

  case 85:
#line 212 "arith.y" /* yacc.c:1646  */
    {(yyval)=createTree(0,TLookup("int"),NULL,MODOP,(yyvsp[-2]),NULL,(yyvsp[0])); }
#line 2117 "y.tab.c" /* yacc.c:1646  */
    break;

  case 86:
#line 213 "arith.y" /* yacc.c:1646  */
    {(yyval)=(yyvsp[-1]);}
#line 2123 "y.tab.c" /* yacc.c:1646  */
    break;

  case 87:
#line 214 "arith.y" /* yacc.c:1646  */
    {(yyval)=createTree(0,TLookup("bool"),NULL,LTOP,(yyvsp[-2]),NULL,(yyvsp[0]));}
#line 2129 "y.tab.c" /* yacc.c:1646  */
    break;

  case 88:
#line 215 "arith.y" /* yacc.c:1646  */
    {(yyval)=createTree(0,TLookup("bool"),NULL,GTOP,(yyvsp[-2]),NULL,(yyvsp[0]));}
#line 2135 "y.tab.c" /* yacc.c:1646  */
    break;

  case 89:
#line 216 "arith.y" /* yacc.c:1646  */
    {(yyval)=createTree(0,TLookup("bool"),NULL,LEOP,(yyvsp[-2]),NULL,(yyvsp[0]));}
#line 2141 "y.tab.c" /* yacc.c:1646  */
    break;

  case 90:
#line 217 "arith.y" /* yacc.c:1646  */
    {(yyval)=createTree(0,TLookup("bool"),NULL,GEOP,(yyvsp[-2]),NULL,(yyvsp[0]));}
#line 2147 "y.tab.c" /* yacc.c:1646  */
    break;

  case 91:
#line 218 "arith.y" /* yacc.c:1646  */
    {(yyval)=createTree(0,TLookup("bool"),NULL,EQOP,(yyvsp[-2]),NULL,(yyvsp[0]));}
#line 2153 "y.tab.c" /* yacc.c:1646  */
    break;

  case 92:
#line 219 "arith.y" /* yacc.c:1646  */
    {(yyval)=createTree(0,TLookup("bool"),NULL,NEOP,(yyvsp[-2]),NULL,(yyvsp[0]));}
#line 2159 "y.tab.c" /* yacc.c:1646  */
    break;

  case 93:
#line 220 "arith.y" /* yacc.c:1646  */
    { (yyval)=createTree(0,TLookup("bool"),NULL,AND,(yyvsp[-2]),NULL,(yyvsp[0])); }
#line 2165 "y.tab.c" /* yacc.c:1646  */
    break;

  case 94:
#line 221 "arith.y" /* yacc.c:1646  */
    { (yyval)=createTree(0,TLookup("bool"),NULL,OR,(yyvsp[-2]),NULL,(yyvsp[0])); }
#line 2171 "y.tab.c" /* yacc.c:1646  */
    break;

  case 95:
#line 222 "arith.y" /* yacc.c:1646  */
    { (yyval)=createTree(0,TLookup("bool"),NULL,NOT,(yyvsp[0]),NULL,NULL); }
#line 2177 "y.tab.c" /* yacc.c:1646  */
    break;

  case 96:
#line 223 "arith.y" /* yacc.c:1646  */
    {(yyval)=(yyvsp[0]);}
#line 2183 "y.tab.c" /* yacc.c:1646  */
    break;

  case 97:
#line 224 "arith.y" /* yacc.c:1646  */
    {(yyval)=(yyvsp[0]);}
#line 2189 "y.tab.c" /* yacc.c:1646  */
    break;

  case 98:
#line 225 "arith.y" /* yacc.c:1646  */
    {(yyval)=(yyvsp[0]); typecheck((yyval));}
#line 2195 "y.tab.c" /* yacc.c:1646  */
    break;

  case 99:
#line 226 "arith.y" /* yacc.c:1646  */
    { typecheck((yyvsp[0])); (yyval)=createTree((yyvsp[0])->val,(yyvsp[0])->type,(yyvsp[0])->varname,ADDR,(yyvsp[0])->left,(yyvsp[0])->middle,(yyvsp[0])->right); free((yyvsp[0])); }
#line 2201 "y.tab.c" /* yacc.c:1646  */
    break;

  case 100:
#line 227 "arith.y" /* yacc.c:1646  */
    {  argcheck((yyvsp[-3])->varname, (yyvsp[-1]), NULL, 0);
							(yyval)=createTree((yyvsp[-3])->val, NULL,(yyvsp[-3])->varname, FUNCTION, (yyvsp[-1]), NULL, NULL); free((yyvsp[-3])); }
#line 2208 "y.tab.c" /* yacc.c:1646  */
    break;

  case 101:
#line 229 "arith.y" /* yacc.c:1646  */
    { (yyval)=createTree(0,TLookup("null"),NULL,NULLNODE,NULL,NULL,NULL); }
#line 2214 "y.tab.c" /* yacc.c:1646  */
    break;

  case 102:
#line 230 "arith.y" /* yacc.c:1646  */
    { (yyval)=createTree(0,TLookup("int"),NULL,INITNODE,NULL,NULL,NULL); }
#line 2220 "y.tab.c" /* yacc.c:1646  */
    break;

  case 103:
#line 231 "arith.y" /* yacc.c:1646  */
    { typecheck((yyvsp[-1])); (yyval)=createTree(0,TLookup("int"),NULL,FREENODE,(yyvsp[-1]),NULL,NULL); }
#line 2226 "y.tab.c" /* yacc.c:1646  */
    break;

  case 104:
#line 232 "arith.y" /* yacc.c:1646  */
    { (yyval)=createTree(0,TLookup("null"),NULL,ALLOCNODE,NULL,NULL,NULL); }
#line 2232 "y.tab.c" /* yacc.c:1646  */
    break;

  case 105:
#line 233 "arith.y" /* yacc.c:1646  */
    { typecheck((yyvsp[-1])); (yyval)=createTree(0,TLookup("int"),NULL,FREENODE,(yyvsp[-1]),NULL,NULL); }
#line 2238 "y.tab.c" /* yacc.c:1646  */
    break;

  case 106:
#line 234 "arith.y" /* yacc.c:1646  */
    { (yyval)=createTree(0,NULL,NULL,NEWNODE,NULL,NULL,NULL); (yyval)->ctype=CLookup((yyvsp[-1])->varname); }
#line 2244 "y.tab.c" /* yacc.c:1646  */
    break;

  case 107:
#line 235 "arith.y" /* yacc.c:1646  */
    { (yyval)=(yyvsp[0]); }
#line 2250 "y.tab.c" /* yacc.c:1646  */
    break;

  case 108:
#line 238 "arith.y" /* yacc.c:1646  */
    { (yyvsp[0])->middle=(yyvsp[-2]); (yyval)=(yyvsp[0]); }
#line 2256 "y.tab.c" /* yacc.c:1646  */
    break;

  case 109:
#line 239 "arith.y" /* yacc.c:1646  */
    { (yyval)=NULL; }
#line 2262 "y.tab.c" /* yacc.c:1646  */
    break;

  case 110:
#line 240 "arith.y" /* yacc.c:1646  */
    {(yyval)=(yyvsp[0]);}
#line 2268 "y.tab.c" /* yacc.c:1646  */
    break;

  case 111:
#line 243 "arith.y" /* yacc.c:1646  */
    { (yyval)=createTree((yyvsp[-1])->val,(yyvsp[-3])->type,(yyvsp[-3])->varname,(yyvsp[-3])->nodetype,(yyvsp[-1]),(yyvsp[-3])->middle,(yyvsp[-3])->right); 
				
				 }
#line 2276 "y.tab.c" /* yacc.c:1646  */
    break;

  case 112:
#line 246 "arith.y" /* yacc.c:1646  */
    { (yyval)=createTree((yyvsp[-4])->val,(yyvsp[-6])->type,(yyvsp[-6])->varname,(yyvsp[-6])->nodetype,(yyvsp[-4]),(yyvsp[-6])->middle,(yyvsp[-1])); //typecheck($$);
									free((yyvsp[-6]));}
#line 2283 "y.tab.c" /* yacc.c:1646  */
    break;

  case 113:
#line 248 "arith.y" /* yacc.c:1646  */
    { (yyval)=(yyvsp[0]); }
#line 2289 "y.tab.c" /* yacc.c:1646  */
    break;

  case 114:
#line 251 "arith.y" /* yacc.c:1646  */
    { (yyval)=(yyvsp[0]);}
#line 2295 "y.tab.c" /* yacc.c:1646  */
    break;

  case 115:
#line 252 "arith.y" /* yacc.c:1646  */
    { (yyval)=createTree((yyvsp[0])->val,(yyvsp[0])->type,(yyvsp[0])->varname,POINTER,(yyvsp[0])->left,(yyvsp[0])->middle,(yyvsp[0])->right);
				free((yyvsp[0])); }
#line 2302 "y.tab.c" /* yacc.c:1646  */
    break;

  case 116:
#line 254 "arith.y" /* yacc.c:1646  */
    { (yyval)=(yyvsp[0]); }
#line 2308 "y.tab.c" /* yacc.c:1646  */
    break;

  case 117:
#line 257 "arith.y" /* yacc.c:1646  */
    { typecheck((yyvsp[-2]));
					if((yyvsp[-2])->type==TLookup("tuple")){
						Gsymbol *p= Lookup((yyvsp[-2])->varname);
						TupleList *list= p->tuplelist;
						while(list!=NULL){
							if(!strcmp(list->name,(yyvsp[0])->varname)){
								(yyvsp[-2])->type=list->type;
								(yyvsp[-2])->nodetype=TUPLEFIELD;
								(yyvsp[-2])->tuplefield=(yyvsp[0]);
								(yyval)=(yyvsp[-2]);
								break;
							}
							list=list->next;
						}
						if(list==NULL){
							yyerror("Invalid  Attribute for tuple type");
							exit(1);
						}
								
					}
					else{
						FieldList *f;
						if((yyvsp[-2])->type==TLookup("int") || (yyvsp[-2])->type==TLookup("str")){
							yyerror("invalid field access");
							exit(1);
						}
						f=FLookup((yyvsp[-2])->type,(yyvsp[0])->varname);
						if(f==NULL){
							fprintf(stderr,"error, %d: No field named %s in %s type",line,(yyvsp[0])->varname,(yyvsp[-2])->type->name);
							exit(1);
						}
						if((yyvsp[-2])->ctype !=NULL){
							fprintf(stderr,"error, %d: Cannot access private variable from a class\n",line);
							exit(1);
						}
						(yyvsp[-2])->nodetype=FIELD;
						(yyvsp[-2])->field=(yyvsp[0]);
						(yyvsp[0])->type=f->type;
						(yyvsp[0])->val=f->fieldIndex;
						(yyvsp[-2])->type=(yyvsp[0])->type;
						(yyval)=(yyvsp[-2]);
					}
					
				  }
#line 2357 "y.tab.c" /* yacc.c:1646  */
    break;

  case 118:
#line 301 "arith.y" /* yacc.c:1646  */
    { tnode *t1; FieldList *f;
						 t1=(yyvsp[-2]);
						 while(t1->field!=NULL)
							 t1=t1->field;
						 if(t1->ctype!=NULL){
							 fprintf(stderr,"error, %d : Cannot access private variables of a class\n",line);
							 exit(1);
						 }
						 f=FLookup(t1->type,(yyvsp[0])->varname);
						 if(f==NULL){
							fprintf(stderr,"error, %d: No field named %s in %s type\n",line,(yyvsp[0])->varname,t1->type->name);
							exit(1);
						 }
						 t1->nodetype=FIELD;
						 t1->field=(yyvsp[0]);
						 (yyvsp[0])->type=f->type;
						 (yyvsp[0])->val=f->fieldIndex;
						 (yyvsp[-2])->type=(yyvsp[0])->type;
						 (yyval)=(yyvsp[-2]);
						 }
#line 2382 "y.tab.c" /* yacc.c:1646  */
    break;

  case 119:
#line 321 "arith.y" /* yacc.c:1646  */
    { FieldList *flist;
						//Gsymbol *gs;
						if(currclass==NULL){
							fprintf(stderr,"error, %d:self can only be used inside a class definition\n",line);
							exit(1);
						}
						else
							flist=currclass->memberfield;
						while(flist!=NULL){
							if(!strcmp((yyvsp[0])->varname,flist->name))
								break;
							flist=flist->next;
						}
						if(flist==NULL){
							fprintf(stderr,"error, %d:Undeclared variable %s inside the class %s\n",line,(yyvsp[0])->varname,currclass->name);
							exit(1);
						}
						(yyval)=createTree(0,NULL,"self",FIELD,NULL,NULL,NULL);
						(yyval)->field=(yyvsp[0]);
						(yyvsp[0])->val=flist->fieldIndex;
						(yyvsp[0])->type=flist->type;
						(yyvsp[0])->ctype=flist->ctype;
						(yyval)->type=flist->type;
						(yyval)->ctype=flist->ctype;
						(yyval)->Gentry=(Gsymbol *)LLookup("self");
						}
#line 2413 "y.tab.c" /* yacc.c:1646  */
    break;

  case 120:
#line 349 "arith.y" /* yacc.c:1646  */
    { if(currclass==NULL){ fprintf(stderr,"error %d : self can only be used inside a class definition\n",line); exit(1);}
											  MemberFuncList *mfunc=checkMemberFunc(currclass, (yyvsp[-3])->varname);
											  (yyval)=createTree(0,NULL,"self",FIELDFUNCTION,NULL,NULL,NULL);
											  (yyvsp[-3])->type=mfunc->type;
											  argcheck((yyvsp[-3])->varname, (yyvsp[-1]), mfunc->paramlist, 1);
											  (yyval)->type=(yyvsp[-3])->type;
											  (yyval)->ctype=currclass;
											  (yyval)->field=(yyvsp[-3]);
											  (yyval)->Gentry=(Gsymbol *)LLookup("self");
											  (yyvsp[-3])->left=(yyvsp[-1]);}
#line 2428 "y.tab.c" /* yacc.c:1646  */
    break;

  case 121:
#line 359 "arith.y" /* yacc.c:1646  */
    { typecheck((yyvsp[-5]));
											  MemberFuncList *mfunc=checkMemberFunc((yyvsp[-5])->ctype, (yyvsp[-3])->varname);
											  (yyval)=createTree(0,NULL,(yyvsp[-5])->varname,FIELDFUNCTION,NULL,NULL,NULL);
											  (yyvsp[-3])->type=mfunc->type;
											  argcheck((yyvsp[-3])->varname, (yyvsp[-1]), mfunc->paramlist, 1);
											  (yyval)->type=(yyvsp[-3])->type;
											  (yyval)->ctype=(yyvsp[-5])->ctype;
											  (yyval)->field=(yyvsp[-3]);
											  (yyval)->Gentry=(yyvsp[-5])->Gentry;
											  (yyvsp[-3])->left=(yyvsp[-1]); }
#line 2443 "y.tab.c" /* yacc.c:1646  */
    break;

  case 122:
#line 369 "arith.y" /* yacc.c:1646  */
    { tnode *tmp;
											  MemberFuncList *mfunc;
											  tmp=(yyvsp[-5]);
											  tmp=tmp->field;
											  if(tmp->field!=NULL){
												  fprintf(stderr,"error %d : illegal member function access\n",line);
												  exit(1);
											  }
											  mfunc=checkMemberFunc(tmp->ctype, (yyvsp[-3])->varname);
											  (yyvsp[-5])->nodetype=FIELDFUNCTION;
											  (yyval)=(yyvsp[-5]);
											  (yyvsp[-3])->type=mfunc->type;
											  argcheck((yyvsp[-3])->varname, (yyvsp[-1]), mfunc->paramlist, 1);
											  (yyval)->type=(yyvsp[-3])->type;
											  
											  tmp->field=(yyvsp[-3]);
											  (yyvsp[-3])->left=(yyvsp[-1]);
											}
#line 2466 "y.tab.c" /* yacc.c:1646  */
    break;


#line 2470 "y.tab.c" /* yacc.c:1646  */
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
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
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
                      yytoken, &yylval);
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

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

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

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYTERROR;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
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
                  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}
#line 388 "arith.y" /* yacc.c:1906  */


int yyerror(char const *s){
	fprintf(stderr,"error, %d : %s\n",line,s);
	return 1;
}

void createSymbolTableEntry(tnode *t){
		int r=1,c=1, l=1;
		Gsymbol *p;
		if(t->left)
			r=t->left->val;
		if(t->right)
			c=t->right->val;
		if(currtype==TLookup("tuple")){
			TupleList *list=paramlist;
			int size=0;
			while(list!=NULL){
				size++;
				list=list->next;
			}
			r=size;
		}
		if(declclass!=NULL){
			Install(t->varname,currtype,2,r,c,NULL,-1);
		}
		else
			Install(t->varname,currtype,r*c,r,c,NULL,-1);
		//printf("%s %d\n",t->varname,t->nodetype);
		p=Lookup(t->varname);
		if(t->nodetype == POINTER){
			p->pointer=1;
		}
		else
			p->pointer=0;
		
		if(currtype==TLookup("tuple")){
			p->tuplelist=paramlist;
		}
		else
			p->tuplelist=NULL;
		free(t);
}

void createParamNode(TypeTable *type, char *name, int nodetype){
	param *tmp, *newnode;
	newnode=(param *)malloc(sizeof(param));
	newnode->type=type;
	newnode->name=(char *)malloc((strlen(name)+1)*sizeof(char));
	strcpy(newnode->name,name);
	if(nodetype==POINTER)
		newnode->pointer=1;
	else
		newnode->pointer=0;
	parameter=newnode;
}

void addParam(param *p){
	if(p==NULL){
		yyerror("parameter error");
		exit(1);
	}
	p->next=paramlist;
	paramlist=p;
}

void createLsymbolEntries(param *p){
	param *tmp;
	Lsymbol *lsymbol;
	int binding=-2;
	tmp=p;
	while(tmp!=NULL){
		tmp=tmp->next;
		binding--;
	}
	if(currclass!=NULL){
		binding-=2;
		lsymbol=LInstall("self", NULL, binding, 0);
		binding+=2;
	}
	while(p!=NULL){
		lsymbol=LInstall(p->name, p->type,binding, p->pointer);
		binding=binding+1;
		p=p->next;
	}
}

void paramcheck(char *fname){
	Gsymbol *p;
	param *decl,*decl2, *def;
	MemberFuncList *mfunc;
	int count1,count2;
	count1=0;
	if(currclass==NULL){
		p=Lookup(fname);
		if(p==NULL){
			yyerror("Undeclared Function");
			exit(1);
		}
		
		decl2=p->paramlist;
	}else{
		mfunc=currclass->vfuncptr;
		while(mfunc!=NULL){
			if(!strcmp(mfunc->name, fname))
				break;
			mfunc=mfunc->next;
		}
		if(mfunc==NULL){
			fprintf(stderr,"error, %d: Undeclared function %s inside class %s\n",line,fname,currclass->name);
			exit(1);
		}
		decl2=mfunc->paramlist;
	}
	decl=decl2;
	while(decl!=NULL){
		count1++;
		decl=decl->next;
	}
	def=paramlist;
	count2=0;
	while(def!=NULL){
		count2++;
		def=def->next;
	}
	if(count1!=count2){
		yyerror("Parameters count mismatch with declaration");
		exit(1);
	}
	def=paramlist;
	decl=decl2;
	while(def!=NULL && decl!=NULL){
		if(def->type != decl->type || def->pointer!=decl->pointer){
			yyerror("Parameter Type mismatch with declaration");
			exit(1);
		}
		if(strcmp(def->name, decl->name)){
			yyerror("Parameter name mismatch with declaration");
			exit(1);
		}
		def=def->next;
		decl=decl->next;
	}
}

void argcheck(char *fname, tnode *t, param *paramlist, int flag){
	Gsymbol *p;
	tnode *tmp;
	param *decl, *decl2;
	int count1, count2;
	if(flag==0){
		p=Lookup(fname);
		if(p==NULL){
			yyerror("Undeclared Function");
			exit(1);
		}
		decl2=p->paramlist;
	}else
		decl2=paramlist;
	decl=decl2;
	count1=0;
	while(decl!=NULL){
		count1++;
		decl=decl->next;
	}
	count2=0;
	tmp=t;
	while(tmp!=NULL){
		count2++;
		tmp=tmp->middle;
	}
	if(count1 != count2){
		yyerror("Arguments count mismatch with function definition");
		exit(1);
	}
	tmp=t;
	decl=decl2;
	
	while(tmp!=NULL && decl!=NULL){
		if(tmp->type != decl->type){
			yyerror("Argument type mismatch with definition");
			exit(1);
		}
		if(decl->pointer==1){
			if(!(tmp->nodetype==ADDR) && !(tmp->nodetype== VAR && tmp->Gentry->pointer==1)){
				yyerror("Arguments type mismatch with definition pointer declaration");
				exit(1);
			}
		}
		tmp=tmp->middle;
		decl=decl->next;
	}
}

void addfield(){
	FieldList *tmp=fieldlist;
	while(tmp!=NULL){
		if(!strcmp(tmp->name,field->name)){
			yyerror("Field Redeclared in type declaration");
			exit(1);
		}
		tmp=tmp->next;
	}
	field->fieldIndex=fieldlist->fieldIndex+1; 
	field->next=fieldlist; 
	fieldlist=field;
	field=NULL;
}

MemberFuncList *checkMemberFunc(ClassTable *class, char *name){
	MemberFuncList *mfunc=NULL;
	if(class==NULL){
		fprintf(stderr,"error, %d : Member functions can only be accessed through class variables\n",line);
		exit(1);
	}
	mfunc=class->vfuncptr;
	while(mfunc!=NULL){
		if(!strcmp(mfunc->name,name))
			break;
		mfunc=mfunc->next;
	}
	if(mfunc==NULL){
		fprintf(stderr,"error, %d : Member function %s not defined inside %s class\n",line,name,class->name);
		exit(1);
	}
	return mfunc;
}
