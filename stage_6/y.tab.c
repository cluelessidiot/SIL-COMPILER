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

#include "symboltable.c"
#include "function_helper.c"
#define YYSTYPE tnode *
int yyerror(char const *);
int yylex(void);

#line 79 "y.tab.c" /* yacc.c:339  */

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
    STRNG = 259,
    PLUS = 260,
    MINUS = 261,
    MUL = 262,
    DIV = 263,
    ASSIGN = 264,
    WRITE = 265,
    READ = 266,
    ID = 267,
    PBEGIN = 268,
    PEND = 269,
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
    BREAK_L = 283,
    CONTINUE_L = 284,
    BRKP_L = 285,
    REPEAT = 286,
    UNTIL = 287,
    DECL = 288,
    ENDDECL = 289,
    INT = 290,
    STR = 291,
    AMPERCANT = 292,
    MTOKEN = 293,
    RETURN = 294,
    AND_ = 295,
    OR_ = 296,
    NOT_ = 297,
    TUPLE = 298,
    TYPE_ST = 299,
    ENDTYPE = 300,
    NULLTK = 301,
    ALLOC = 302,
    INITIALIZE = 303,
    FREE = 304,
    MOD = 305
  };
#endif
/* Tokens.  */
#define NUM 258
#define STRNG 259
#define PLUS 260
#define MINUS 261
#define MUL 262
#define DIV 263
#define ASSIGN 264
#define WRITE 265
#define READ 266
#define ID 267
#define PBEGIN 268
#define PEND 269
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
#define BREAK_L 283
#define CONTINUE_L 284
#define BRKP_L 285
#define REPEAT 286
#define UNTIL 287
#define DECL 288
#define ENDDECL 289
#define INT 290
#define STR 291
#define AMPERCANT 292
#define MTOKEN 293
#define RETURN 294
#define AND_ 295
#define OR_ 296
#define NOT_ 297
#define TUPLE 298
#define TYPE_ST 299
#define ENDTYPE 300
#define NULLTK 301
#define ALLOC 302
#define INITIALIZE 303
#define FREE 304
#define MOD 305

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

#line 230 "y.tab.c" /* yacc.c:358  */

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
#define YYLAST   592

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  60
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  41
/* YYNRULES -- Number of rules.  */
#define YYNRULES  99
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  226

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   305

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
      54,    55,     2,     2,    56,     2,    59,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    53,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    57,     2,    58,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    51,     2,    52,     2,     2,     2,     2,
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
      45,    46,    47,    48,    49,    50
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    28,    28,    29,    30,    33,    34,    37,    38,    41,
      41,    50,    51,    53,    55,    56,    59,    60,    63,    64,
      67,    69,    70,    73,    74,    82,    83,    86,    91,    92,
      93,    96,    98,   100,   101,   102,   105,   106,   109,   111,
     112,   115,   117,   119,   127,   128,   132,   133,   134,   135,
     136,   137,   138,   139,   142,   145,   147,   149,   150,   153,
     155,   157,   159,   160,   161,   164,   165,   166,   167,   168,
     169,   170,   171,   172,   173,   174,   175,   176,   177,   178,
     179,   180,   181,   182,   183,   184,   188,   189,   190,   191,
     194,   195,   199,   200,   201,   204,   205,   207,   210,   214
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "NUM", "STRNG", "PLUS", "MINUS", "MUL",
  "DIV", "ASSIGN", "WRITE", "READ", "ID", "PBEGIN", "PEND", "EQ", "NE",
  "LT", "GT", "LE", "GE", "IF", "THEN", "ELSE", "ENDIF", "WHILE", "DO",
  "ENDWHILE", "BREAK_L", "CONTINUE_L", "BRKP_L", "REPEAT", "UNTIL", "DECL",
  "ENDDECL", "INT", "STR", "AMPERCANT", "MTOKEN", "RETURN", "AND_", "OR_",
  "NOT_", "TUPLE", "TYPE_ST", "ENDTYPE", "NULLTK", "ALLOC", "INITIALIZE",
  "FREE", "MOD", "'{'", "'}'", "';'", "'('", "')'", "','", "'['", "']'",
  "'.'", "$accept", "Program", "TypeDefBlock", "TypeDefList", "TypeDef",
  "$@1", "FieldDeclList", "FieldDecl", "GDeclBlock", "GDeclList", "GDecl",
  "Tuple", "GidList", "Gid", "FDefBlock", "FDef", "ParamList", "Param",
  "Type", "LDeclBlock", "LDeclList", "LDecl", "IdList", "Body", "RetStmt",
  "MainBlock", "Slist", "Stmt", "InputStmt", "OutputStmt", "AsgStmt",
  "IfStmt", "WhileStmt", "DoWhileStmt", "UntilStmt", "PlainStmt", "expr",
  "ArgList", "Iden", "Id1", "Field", YY_NULLPTR
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
     305,   123,   125,    59,    40,    41,    44,    91,    93,    46
};
# endif

#define YYPACT_NINF -157

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-157)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -11,    54,    62,    -2,    41,    -7,  -157,  -157,  -157,     2,
      84,    70,  -157,  -157,  -157,  -157,  -157,  -157,     3,  -157,
      97,    11,    84,  -157,    -6,  -157,    56,    84,  -157,  -157,
      57,   100,   -32,   -37,  -157,  -157,    59,    60,  -157,  -157,
      64,    61,    -8,  -157,   108,    84,  -157,   180,   109,  -157,
      11,    84,   113,    84,    75,  -157,  -157,    74,    17,  -157,
      42,  -157,  -157,    -4,    11,   180,  -157,    87,    88,    89,
     180,    82,  -157,  -157,  -157,  -157,    39,  -157,    48,    95,
    -157,    11,    84,    77,  -157,   127,  -157,    16,    90,    98,
      11,   225,   180,   180,   180,   180,   180,   180,   180,   180,
     180,   180,   180,   180,   180,    72,  -157,    93,     1,   139,
      -5,  -157,  -157,   417,    50,  -157,  -157,    99,  -157,   431,
     431,   131,   131,    16,    16,    16,    16,    16,    16,  -157,
    -157,   131,   180,    95,  -157,    42,     8,  -157,   549,   105,
    -157,  -157,   180,  -157,   196,   139,    15,  -157,  -157,  -157,
     111,   112,   114,   123,   549,   126,   132,   135,   549,   449,
    -157,  -157,  -157,  -157,  -157,  -157,  -157,  -157,  -157,   153,
    -157,   417,  -157,   128,  -157,    42,   180,    11,   180,   180,
     561,  -157,  -157,  -157,   475,   180,   177,  -157,   180,  -157,
    -157,   242,   140,   271,   288,   143,   180,   334,  -157,   363,
     145,   146,   183,   181,   180,   390,  -157,  -157,  -157,  -157,
     549,   549,   317,  -157,   487,   512,   -14,   549,   155,   156,
    -157,   524,  -157,  -157,   157,  -157
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       6,     0,     0,     0,     0,     0,     8,     1,    32,     0,
       0,     0,     4,     9,     5,     7,    15,    20,     0,    17,
       0,     0,     0,    26,     0,     3,     0,     0,    14,    16,
       0,     0,    95,     0,    22,    23,    94,    97,    25,     2,
       0,     0,     0,    12,     0,    30,    96,     0,     0,    18,
       0,    30,     0,    30,     0,    10,    11,     0,     0,    29,
       0,    80,    81,    95,     0,     0,    86,     0,     0,     0,
       0,     0,    82,    94,    98,    21,     0,    99,     0,    35,
      13,     0,     0,    95,    31,     0,    83,    79,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    92,    24,     0,     0,     0,
       0,    28,    84,    91,     0,    89,    87,     0,    70,    65,
      66,    67,    68,    75,    76,    71,    72,    73,    74,    77,
      78,    69,     0,    35,    34,     0,     0,    37,     0,     0,
      19,    85,     0,    88,     0,     0,     0,    40,    33,    36,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      45,    46,    47,    48,    49,    50,    51,    52,    53,     0,
      43,    90,    93,     0,    38,     0,     0,     0,     0,     0,
       0,    63,    64,    62,     0,     0,     0,    44,     0,    27,
      39,     0,     0,     0,     0,     0,     0,     0,    41,     0,
       0,     0,     0,     0,     0,     0,    42,    56,    55,    54,
       0,     0,     0,    61,     0,     0,     0,     0,     0,     0,
      60,     0,    58,    59,     0,    57
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -157,  -157,  -157,  -157,   201,  -157,  -157,   176,  -157,  -157,
     202,  -157,   138,   171,  -157,   203,    40,   141,    -1,    91,
    -157,   102,  -157,    94,  -157,    12,  -147,  -156,  -157,  -157,
    -157,  -157,  -157,  -157,  -157,  -157,   -18,  -157,   -21,   -20,
    -157
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,     5,     6,    27,    42,    43,    10,    18,
      19,    20,    33,    34,    22,    23,    58,    59,    60,   109,
     136,   137,   146,   139,   186,    12,   159,   160,   161,   162,
     163,   164,   165,   166,   167,   168,    71,   114,    72,    73,
      37
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      35,    36,    11,   187,     8,     4,    40,   180,    21,    24,
       8,   184,   211,     8,     8,     8,    49,    21,    31,    50,
       8,    24,    25,    32,   187,    47,    44,    48,   187,    35,
      36,     9,    26,     1,    39,   134,    16,    28,    14,   220,
      84,    44,   148,    86,    55,    17,    17,    87,   140,    31,
      85,    50,    91,    47,    83,    48,   102,   103,   187,   187,
      35,    36,     7,   214,   215,   187,     4,   113,   174,   117,
     221,   175,    81,    82,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   131,    92,    93,    94,
      95,    76,    13,    78,   106,    82,     8,    96,    97,    98,
      99,   100,   101,   107,    82,   141,   142,   135,    26,    30,
      41,    45,    46,    51,   144,   147,    54,   169,    53,    52,
      57,    74,   102,   103,   171,    77,    79,    80,   108,   132,
      61,    62,   104,   169,    31,   135,    48,   169,   169,    63,
     105,    88,    89,    90,   133,   115,    96,    97,    98,    99,
     100,   101,   138,   116,   143,   190,   192,   170,   191,   169,
     193,   194,   188,   169,    64,   176,   177,   197,   178,    65,
     199,   102,   103,    66,    67,    68,    69,   179,   205,   181,
     189,    70,   112,    61,    62,   182,   212,    31,   183,   169,
     169,   198,    63,   169,   169,   201,   169,   204,   208,   209,
     169,    92,    93,    94,    95,   210,    15,   211,   222,   223,
     225,    96,    97,    98,    99,   100,   101,    64,    56,   110,
      29,    75,    65,   111,   145,    38,    66,    67,    68,    69,
      92,    93,    94,    95,    70,     0,   102,   103,   149,   173,
      96,    97,    98,    99,   100,   101,   104,    92,    93,    94,
      95,     0,     0,     0,   172,     0,     0,    96,    97,    98,
      99,   100,   101,     0,     0,   102,   103,     0,     0,     0,
       0,     0,     0,     0,     0,   104,    92,    93,    94,    95,
     118,     0,   102,   103,     0,     0,    96,    97,    98,    99,
     100,   101,   104,    92,    93,    94,    95,   200,     0,     0,
       0,     0,     0,    96,    97,    98,    99,   100,   101,     0,
       0,   102,   103,     0,     0,     0,     0,     0,     0,     0,
       0,   104,    92,    93,    94,    95,   202,     0,   102,   103,
       0,     0,    96,    97,    98,    99,   100,   101,   104,    92,
      93,    94,    95,   203,     0,     0,     0,     0,     0,    96,
      97,    98,    99,   100,   101,     0,     0,   102,   103,     0,
       0,     0,     0,     0,     0,     0,     0,   104,    92,    93,
      94,    95,   216,     0,   102,   103,     0,     0,    96,    97,
      98,    99,   100,   101,   104,     0,     0,   206,     0,     0,
       0,     0,     0,     0,     0,    92,    93,    94,    95,     0,
       0,     0,     0,   102,   103,    96,    97,    98,    99,   100,
     101,     0,     0,   104,     0,     0,   207,     0,     0,     0,
       0,     0,    92,    93,    94,    95,     0,     0,     0,     0,
     102,   103,    96,    97,    98,    99,   100,   101,    94,    95,
     104,     0,     0,   213,     0,     0,    96,    97,    98,    99,
     100,   101,     0,     0,     0,     0,    31,   102,   103,   150,
     151,    32,     0,     0,     0,     0,     0,   104,     0,     0,
     152,   102,   103,     0,   153,   154,     0,   155,   156,   157,
     158,   104,    31,     0,     0,   150,   151,    32,   185,     0,
       0,     0,     0,     0,    31,     0,   152,   150,   151,    32,
     153,   154,     0,   155,   156,   157,   158,   196,   152,     0,
     217,   218,   153,   154,     0,   155,   156,   157,   158,    31,
       0,     0,   150,   151,    32,     0,     0,     0,     0,     0,
       0,    31,     0,   152,   150,   151,    32,   153,   154,   219,
     155,   156,   157,   158,     0,   152,     0,     0,   224,   153,
     154,     0,   155,   156,   157,   158,    31,     0,     0,   150,
     151,    32,     0,     0,     0,     0,     0,     0,    31,     0,
     152,   150,   151,    32,   153,   154,     0,   155,   156,   157,
     158,     0,   152,     0,     0,     0,   195,   154,     0,   155,
     156,   157,   158
};

static const yytype_int16 yycheck[] =
{
      21,    21,     3,   159,    12,    12,    12,   154,     9,    10,
      12,   158,    26,    12,    12,    12,    53,    18,     7,    56,
      12,    22,    10,    12,   180,    57,    27,    59,   184,    50,
      50,    33,    38,    44,    22,    34,    34,    34,    45,    53,
      60,    42,    34,    64,    52,    43,    43,    65,    53,     7,
      54,    56,    70,    57,    12,    59,    40,    41,   214,   215,
      81,    81,     0,   210,   211,   221,    12,    85,    53,    90,
     217,    56,    55,    56,    92,    93,    94,    95,    96,    97,
      98,    99,   100,   101,   102,   103,   104,     5,     6,     7,
       8,    51,    51,    53,    55,    56,    12,    15,    16,    17,
      18,    19,    20,    55,    56,    55,    56,   108,    38,    12,
      54,    54,    12,    54,   132,   135,    55,   138,    54,    59,
      12,    12,    40,    41,   142,    12,    51,    53,    33,    57,
       3,     4,    50,   154,     7,   136,    59,   158,   159,    12,
      58,    54,    54,    54,    51,    55,    15,    16,    17,    18,
      19,    20,    13,    55,    55,   175,   177,    52,   176,   180,
     178,   179,     9,   184,    37,    54,    54,   185,    54,    42,
     188,    40,    41,    46,    47,    48,    49,    54,   196,    53,
      52,    54,    55,     3,     4,    53,   204,     7,    53,   210,
     211,    14,    12,   214,   215,    55,   217,    54,    53,    53,
     221,     5,     6,     7,     8,    22,     5,    26,    53,    53,
      53,    15,    16,    17,    18,    19,    20,    37,    42,    81,
      18,    50,    42,    82,   133,    22,    46,    47,    48,    49,
       5,     6,     7,     8,    54,    -1,    40,    41,   136,   145,
      15,    16,    17,    18,    19,    20,    50,     5,     6,     7,
       8,    -1,    -1,    -1,    58,    -1,    -1,    15,    16,    17,
      18,    19,    20,    -1,    -1,    40,    41,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    50,     5,     6,     7,     8,
      55,    -1,    40,    41,    -1,    -1,    15,    16,    17,    18,
      19,    20,    50,     5,     6,     7,     8,    55,    -1,    -1,
      -1,    -1,    -1,    15,    16,    17,    18,    19,    20,    -1,
      -1,    40,    41,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    50,     5,     6,     7,     8,    55,    -1,    40,    41,
      -1,    -1,    15,    16,    17,    18,    19,    20,    50,     5,
       6,     7,     8,    55,    -1,    -1,    -1,    -1,    -1,    15,
      16,    17,    18,    19,    20,    -1,    -1,    40,    41,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    50,     5,     6,
       7,     8,    55,    -1,    40,    41,    -1,    -1,    15,    16,
      17,    18,    19,    20,    50,    -1,    -1,    53,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,     5,     6,     7,     8,    -1,
      -1,    -1,    -1,    40,    41,    15,    16,    17,    18,    19,
      20,    -1,    -1,    50,    -1,    -1,    53,    -1,    -1,    -1,
      -1,    -1,     5,     6,     7,     8,    -1,    -1,    -1,    -1,
      40,    41,    15,    16,    17,    18,    19,    20,     7,     8,
      50,    -1,    -1,    53,    -1,    -1,    15,    16,    17,    18,
      19,    20,    -1,    -1,    -1,    -1,     7,    40,    41,    10,
      11,    12,    -1,    -1,    -1,    -1,    -1,    50,    -1,    -1,
      21,    40,    41,    -1,    25,    26,    -1,    28,    29,    30,
      31,    50,     7,    -1,    -1,    10,    11,    12,    39,    -1,
      -1,    -1,    -1,    -1,     7,    -1,    21,    10,    11,    12,
      25,    26,    -1,    28,    29,    30,    31,    32,    21,    -1,
      23,    24,    25,    26,    -1,    28,    29,    30,    31,     7,
      -1,    -1,    10,    11,    12,    -1,    -1,    -1,    -1,    -1,
      -1,     7,    -1,    21,    10,    11,    12,    25,    26,    27,
      28,    29,    30,    31,    -1,    21,    -1,    -1,    24,    25,
      26,    -1,    28,    29,    30,    31,     7,    -1,    -1,    10,
      11,    12,    -1,    -1,    -1,    -1,    -1,    -1,     7,    -1,
      21,    10,    11,    12,    25,    26,    -1,    28,    29,    30,
      31,    -1,    21,    -1,    -1,    -1,    25,    26,    -1,    28,
      29,    30,    31
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    44,    61,    62,    12,    63,    64,     0,    12,    33,
      68,    78,    85,    51,    45,    64,    34,    43,    69,    70,
      71,    78,    74,    75,    78,    85,    38,    65,    34,    70,
      12,     7,    12,    72,    73,    98,    99,   100,    75,    85,
      12,    54,    66,    67,    78,    54,    12,    57,    59,    53,
      56,    54,    59,    54,    55,    52,    67,    12,    76,    77,
      78,     3,     4,    12,    37,    42,    46,    47,    48,    49,
      54,    96,    98,    99,    12,    73,    76,    12,    76,    51,
      53,    55,    56,    12,    99,    54,    98,    96,    54,    54,
      54,    96,     5,     6,     7,     8,    15,    16,    17,    18,
      19,    20,    40,    41,    50,    58,    55,    55,    33,    79,
      72,    77,    55,    96,    97,    55,    55,    98,    55,    96,
      96,    96,    96,    96,    96,    96,    96,    96,    96,    96,
      96,    96,    57,    51,    34,    78,    80,    81,    13,    83,
      53,    55,    56,    55,    96,    79,    82,    99,    34,    81,
      10,    11,    21,    25,    26,    28,    29,    30,    31,    86,
      87,    88,    89,    90,    91,    92,    93,    94,    95,    98,
      52,    96,    58,    83,    53,    56,    54,    54,    54,    54,
      86,    53,    53,    53,    86,    39,    84,    87,     9,    52,
      99,    96,    98,    96,    96,    25,    32,    96,    14,    96,
      55,    55,    55,    55,    54,    96,    53,    53,    53,    53,
      22,    26,    96,    53,    86,    86,    55,    23,    24,    27,
      53,    86,    53,    53,    24,    53
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    60,    61,    61,    61,    62,    62,    63,    63,    65,
      64,    66,    66,    67,    68,    68,    69,    69,    70,    70,
      71,    72,    72,    73,    73,    74,    74,    75,    76,    76,
      76,    77,    78,    79,    79,    79,    80,    80,    81,    82,
      82,    83,    84,    85,    86,    86,    87,    87,    87,    87,
      87,    87,    87,    87,    88,    89,    90,    91,    91,    92,
      93,    94,    95,    95,    95,    96,    96,    96,    96,    96,
      96,    96,    96,    96,    96,    96,    96,    96,    96,    96,
      96,    96,    96,    96,    96,    96,    96,    96,    96,    96,
      97,    97,    98,    98,    98,    99,    99,    99,   100,   100
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     4,     3,     2,     3,     0,     2,     1,     0,
       5,     2,     1,     3,     3,     2,     2,     1,     3,     7,
       1,     3,     1,     1,     4,     2,     1,     9,     3,     1,
       0,     2,     1,     3,     2,     0,     2,     1,     3,     3,
       1,     4,     3,     8,     2,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     5,     5,     4,    10,     8,     8,
       7,     5,     2,     2,     2,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     2,
       1,     1,     1,     2,     3,     4,     1,     3,     4,     3,
       3,     1,     4,     7,     1,     1,     2,     1,     3,     3
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
#line 33 "arith.y" /* yacc.c:1646  */
    { printTypeTable(); }
#line 1536 "y.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 34 "arith.y" /* yacc.c:1646  */
    { printTypeTable(); }
#line 1542 "y.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 37 "arith.y" /* yacc.c:1646  */
    {  }
#line 1548 "y.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 38 "arith.y" /* yacc.c:1646  */
    {  }
#line 1554 "y.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 41 "arith.y" /* yacc.c:1646  */
    {TInstall((yyvsp[-1])->varname,0,NULL);}
#line 1560 "y.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 41 "arith.y" /* yacc.c:1646  */
    { type_table_configure((yyvsp[-4])->varname);
								/*  TypeTable *type_table=TLookup($1->varname);
								  fieldcheck(fieldlist);
								  type_table->fields=fieldlist;
								  fieldlist=NULL;
								  type_table->size=getSize(type_table);*/
								}
#line 1572 "y.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 50 "arith.y" /* yacc.c:1646  */
    { addfield(); }
#line 1578 "y.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 51 "arith.y" /* yacc.c:1646  */
    { field->fieldIndex=0; fieldlist=field; field=NULL; }
#line 1584 "y.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 53 "arith.y" /* yacc.c:1646  */
    { field=(FieldList *)malloc(sizeof(FieldList)); field->name=(yyvsp[-1])->varname; field->type=(yyvsp[-2])->type; field->next=NULL; }
#line 1590 "y.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 55 "arith.y" /* yacc.c:1646  */
    { print_symbol_table(); }
#line 1596 "y.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 56 "arith.y" /* yacc.c:1646  */
    {  }
#line 1602 "y.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 59 "arith.y" /* yacc.c:1646  */
    {  }
#line 1608 "y.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 60 "arith.y" /* yacc.c:1646  */
    { }
#line 1614 "y.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 63 "arith.y" /* yacc.c:1646  */
    { currtype=NULL; }
#line 1620 "y.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 64 "arith.y" /* yacc.c:1646  */
    { currtype=NULL; paramlist=NULL; }
#line 1626 "y.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 67 "arith.y" /* yacc.c:1646  */
    { currtype = TLookup("tuple");}
#line 1632 "y.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 69 "arith.y" /* yacc.c:1646  */
    {  }
#line 1638 "y.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 70 "arith.y" /* yacc.c:1646  */
    {  }
#line 1644 "y.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 73 "arith.y" /* yacc.c:1646  */
    { createSymbolTableEntry((yyvsp[0])); }
#line 1650 "y.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 74 "arith.y" /* yacc.c:1646  */
    { GInstall((yyvsp[-3])->varname,currtype,0,0,0,paramlist,flabel++);
				 //for filling pointer field in pointer returned function..... 
				 paramlist=NULL;
				if((yyvsp[-3])->nodetype==POINTER){ 
					Gsymbol *p= GLookup((yyvsp[-3])->varname); 
					p->pointer=1; }	}
#line 1661 "y.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 82 "arith.y" /* yacc.c:1646  */
    {  }
#line 1667 "y.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 83 "arith.y" /* yacc.c:1646  */
    {  }
#line 1673 "y.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 86 "arith.y" /* yacc.c:1646  */
    {                       function_call((yyvsp[-1]),(yyvsp[-7])->varname);
											
															
															}
#line 1682 "y.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 91 "arith.y" /* yacc.c:1646  */
    { create_param_list(parameter); parameter=NULL; }
#line 1688 "y.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 92 "arith.y" /* yacc.c:1646  */
    { create_param_list(parameter), parameter=NULL; }
#line 1694 "y.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 93 "arith.y" /* yacc.c:1646  */
    {  }
#line 1700 "y.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 96 "arith.y" /* yacc.c:1646  */
    { createParamNode((yyvsp[-1])->type,(yyvsp[0])->varname,(yyvsp[0])->nodetype); currtype=oldtype; }
#line 1706 "y.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 98 "arith.y" /* yacc.c:1646  */
    { oldtype=currtype; currtype=TLookup((yyvsp[0])->varname); (yyval)=createTree(0,currtype,(yyvsp[0])->varname,TYPE,NULL,NULL,NULL); }
#line 1712 "y.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 100 "arith.y" /* yacc.c:1646  */
    { createLsymbolEntries(paramlist);   }
#line 1718 "y.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 101 "arith.y" /* yacc.c:1646  */
    { createLsymbolEntries(paramlist);   }
#line 1724 "y.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 102 "arith.y" /* yacc.c:1646  */
    { createLsymbolEntries(paramlist);   }
#line 1730 "y.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 105 "arith.y" /* yacc.c:1646  */
    { }
#line 1736 "y.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 106 "arith.y" /* yacc.c:1646  */
    {  }
#line 1742 "y.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 109 "arith.y" /* yacc.c:1646  */
    { currtype=NULL; }
#line 1748 "y.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 111 "arith.y" /* yacc.c:1646  */
    { LInstall((yyvsp[0])->varname, currtype,local_binding++, (yyvsp[0])->nodetype==POINTER ? 1 : 0); }
#line 1754 "y.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 112 "arith.y" /* yacc.c:1646  */
    { LInstall((yyvsp[0])->varname, currtype,local_binding++, (yyvsp[0])->nodetype==POINTER ? 1 : 0); }
#line 1760 "y.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 115 "arith.y" /* yacc.c:1646  */
    { (yyval)=createTree(0,NULL,NULL,CONN,(yyvsp[-2]),NULL,(yyvsp[-1])); }
#line 1766 "y.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 117 "arith.y" /* yacc.c:1646  */
    { (yyval)=createTree(0,(yyvsp[-1])->type,NULL,RET, (yyvsp[-1]), NULL, NULL); }
#line 1772 "y.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 119 "arith.y" /* yacc.c:1646  */
    { if((yyvsp[-7])->type != TLookup("int")){
											yyerror("Main expects integer return type");
											exit(1);
											}
															char *marg="main";
															function_call((yyvsp[-1]),marg);
							}
#line 1784 "y.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 127 "arith.y" /* yacc.c:1646  */
    {(yyval)=createTree(0,NULL,NULL,CONN,(yyvsp[-1]),NULL,(yyvsp[0]));}
#line 1790 "y.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 128 "arith.y" /* yacc.c:1646  */
    {(yyval)=(yyvsp[0]);}
#line 1796 "y.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 132 "arith.y" /* yacc.c:1646  */
    {(yyval)=(yyvsp[0]);}
#line 1802 "y.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 133 "arith.y" /* yacc.c:1646  */
    {(yyval)=(yyvsp[0]);}
#line 1808 "y.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 134 "arith.y" /* yacc.c:1646  */
    {(yyval)=(yyvsp[0]);}
#line 1814 "y.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 135 "arith.y" /* yacc.c:1646  */
    {(yyval)=(yyvsp[0]);}
#line 1820 "y.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 136 "arith.y" /* yacc.c:1646  */
    {(yyval)=(yyvsp[0]);}
#line 1826 "y.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 137 "arith.y" /* yacc.c:1646  */
    {(yyval)=(yyvsp[0]);}
#line 1832 "y.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 138 "arith.y" /* yacc.c:1646  */
    {(yyval)=(yyvsp[0]);}
#line 1838 "y.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 139 "arith.y" /* yacc.c:1646  */
    {(yyval)=(yyvsp[0]);}
#line 1844 "y.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 142 "arith.y" /* yacc.c:1646  */
    {typecheck((yyvsp[-2])); (yyval)=createTree(0,NULL,NULL,READOP,(yyvsp[-2]),NULL,NULL);}
#line 1850 "y.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 145 "arith.y" /* yacc.c:1646  */
    {(yyval)=createTree(0,NULL,NULL,WRITEOP,(yyvsp[-2]),NULL,NULL);}
#line 1856 "y.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 147 "arith.y" /* yacc.c:1646  */
    {typecheck((yyvsp[-3])); (yyval)=createTree(0,NULL,NULL,ASS,(yyvsp[-3]),NULL,(yyvsp[-1]));}
#line 1862 "y.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 149 "arith.y" /* yacc.c:1646  */
    {(yyval)=createTree(0,NULL,NULL,IFSTMT,(yyvsp[-7]),(yyvsp[-4]),(yyvsp[-2]));}
#line 1868 "y.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 150 "arith.y" /* yacc.c:1646  */
    {(yyval)=createTree(0,NULL,NULL,IFSTMT,(yyvsp[-5]),(yyvsp[-2]),NULL);}
#line 1874 "y.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 153 "arith.y" /* yacc.c:1646  */
    {(yyval)=createTree(0,NULL,NULL,WHILESTMT,(yyvsp[-5]),NULL,(yyvsp[-2]));}
#line 1880 "y.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 155 "arith.y" /* yacc.c:1646  */
    { (yyval)=createTree(0,NULL,NULL,DOWHILESTMT,(yyvsp[-5]),NULL,(yyvsp[-2])); }
#line 1886 "y.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 157 "arith.y" /* yacc.c:1646  */
    { (yyval)=createTree(0,NULL,NULL,UNTILSTMT,(yyvsp[-3]),NULL,(yyvsp[-1])); }
#line 1892 "y.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 159 "arith.y" /* yacc.c:1646  */
    {(yyval)=createTree(0,NULL,NULL,BRKP,NULL,NULL,NULL);}
#line 1898 "y.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 160 "arith.y" /* yacc.c:1646  */
    {(yyval)=createTree(0,NULL,NULL,BREAK,NULL,NULL,NULL);}
#line 1904 "y.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 161 "arith.y" /* yacc.c:1646  */
    {(yyval)=createTree(0,NULL,NULL,CONTINUE,NULL,NULL,NULL);}
#line 1910 "y.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 164 "arith.y" /* yacc.c:1646  */
    {(yyval)=createTree(0,TLookup("int"),NULL,PLUSOP,(yyvsp[-2]),NULL,(yyvsp[0]));}
#line 1916 "y.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 165 "arith.y" /* yacc.c:1646  */
    {(yyval)=createTree(0,TLookup("int"),NULL,MINUSOP,(yyvsp[-2]),NULL,(yyvsp[0]));}
#line 1922 "y.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 166 "arith.y" /* yacc.c:1646  */
    {(yyval)=createTree(0,TLookup("int"),NULL,MULOP,(yyvsp[-2]),NULL,(yyvsp[0]));}
#line 1928 "y.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 167 "arith.y" /* yacc.c:1646  */
    {(yyval)=createTree(0,TLookup("int"),NULL,DIVOP,(yyvsp[-2]),NULL,(yyvsp[0]));}
#line 1934 "y.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 168 "arith.y" /* yacc.c:1646  */
    {(yyval)=createTree(0,TLookup("int"),NULL,MODOP,(yyvsp[-2]),NULL,(yyvsp[0])); }
#line 1940 "y.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 169 "arith.y" /* yacc.c:1646  */
    {(yyval)=(yyvsp[-1]);}
#line 1946 "y.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 170 "arith.y" /* yacc.c:1646  */
    {(yyval)=createTree(0,TLookup("bool"),NULL,LTOP,(yyvsp[-2]),NULL,(yyvsp[0]));}
#line 1952 "y.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 171 "arith.y" /* yacc.c:1646  */
    {(yyval)=createTree(0,TLookup("bool"),NULL,GTOP,(yyvsp[-2]),NULL,(yyvsp[0]));}
#line 1958 "y.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 172 "arith.y" /* yacc.c:1646  */
    {(yyval)=createTree(0,TLookup("bool"),NULL,LEOP,(yyvsp[-2]),NULL,(yyvsp[0]));}
#line 1964 "y.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 173 "arith.y" /* yacc.c:1646  */
    {(yyval)=createTree(0,TLookup("bool"),NULL,GEOP,(yyvsp[-2]),NULL,(yyvsp[0]));}
#line 1970 "y.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 174 "arith.y" /* yacc.c:1646  */
    {(yyval)=createTree(0,TLookup("bool"),NULL,EQOP,(yyvsp[-2]),NULL,(yyvsp[0]));}
#line 1976 "y.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 175 "arith.y" /* yacc.c:1646  */
    {(yyval)=createTree(0,TLookup("bool"),NULL,NEOP,(yyvsp[-2]),NULL,(yyvsp[0]));}
#line 1982 "y.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 176 "arith.y" /* yacc.c:1646  */
    { (yyval)=createTree(0,TLookup("bool"),NULL,AND,(yyvsp[-2]),NULL,(yyvsp[0])); }
#line 1988 "y.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 177 "arith.y" /* yacc.c:1646  */
    { (yyval)=createTree(0,TLookup("bool"),NULL,OR,(yyvsp[-2]),NULL,(yyvsp[0])); }
#line 1994 "y.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 178 "arith.y" /* yacc.c:1646  */
    { (yyval)=createTree(0,TLookup("bool"),NULL,NOT,(yyvsp[0]),NULL,NULL); }
#line 2000 "y.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 179 "arith.y" /* yacc.c:1646  */
    {(yyval)=(yyvsp[0]);}
#line 2006 "y.tab.c" /* yacc.c:1646  */
    break;

  case 81:
#line 180 "arith.y" /* yacc.c:1646  */
    {(yyval)=(yyvsp[0]);}
#line 2012 "y.tab.c" /* yacc.c:1646  */
    break;

  case 82:
#line 181 "arith.y" /* yacc.c:1646  */
    {(yyval)=(yyvsp[0]); typecheck((yyval));}
#line 2018 "y.tab.c" /* yacc.c:1646  */
    break;

  case 83:
#line 182 "arith.y" /* yacc.c:1646  */
    { typecheck((yyvsp[0])); (yyval)=createTree((yyvsp[0])->val,(yyvsp[0])->type,(yyvsp[0])->varname,ADDR,(yyvsp[0])->left,(yyvsp[0])->middle,(yyvsp[0])->right);  }
#line 2024 "y.tab.c" /* yacc.c:1646  */
    break;

  case 84:
#line 183 "arith.y" /* yacc.c:1646  */
    { (yyval)=createTree((yyvsp[-2])->val, NULL,(yyvsp[-2])->varname, FUNCTION, NULL, NULL, NULL);  }
#line 2030 "y.tab.c" /* yacc.c:1646  */
    break;

  case 85:
#line 184 "arith.y" /* yacc.c:1646  */
    {  			argcheck((yyvsp[-3])->varname, (yyvsp[-1]));
							(yyval)=createTree((yyvsp[-3])->val, NULL,(yyvsp[-3])->varname, FUNCTION, (yyvsp[-1]), NULL, NULL); 
			     }
#line 2038 "y.tab.c" /* yacc.c:1646  */
    break;

  case 86:
#line 188 "arith.y" /* yacc.c:1646  */
    { (yyval)=createTree(0,TLookup("null"),NULL,NULLNODE,NULL,NULL,NULL); }
#line 2044 "y.tab.c" /* yacc.c:1646  */
    break;

  case 87:
#line 189 "arith.y" /* yacc.c:1646  */
    { (yyval)=createTree(0,TLookup("int"),NULL,INITNODE,NULL,NULL,NULL); }
#line 2050 "y.tab.c" /* yacc.c:1646  */
    break;

  case 88:
#line 190 "arith.y" /* yacc.c:1646  */
    { typecheck((yyvsp[-1])); (yyval)=createTree(0,TLookup("int"),NULL,FREENODE,(yyvsp[-1]),NULL,NULL); }
#line 2056 "y.tab.c" /* yacc.c:1646  */
    break;

  case 89:
#line 191 "arith.y" /* yacc.c:1646  */
    { (yyval)=createTree(0,TLookup("null"),NULL,ALLOCNODE,NULL,NULL,NULL); }
#line 2062 "y.tab.c" /* yacc.c:1646  */
    break;

  case 90:
#line 194 "arith.y" /* yacc.c:1646  */
    { (yyvsp[0])->middle=(yyvsp[-2]); (yyval)=(yyvsp[0]); }
#line 2068 "y.tab.c" /* yacc.c:1646  */
    break;

  case 91:
#line 195 "arith.y" /* yacc.c:1646  */
    { (yyval)=(yyvsp[0]); }
#line 2074 "y.tab.c" /* yacc.c:1646  */
    break;

  case 92:
#line 199 "arith.y" /* yacc.c:1646  */
    { (yyval)=createTree((yyvsp[-1])->val,(yyvsp[-3])->type,(yyvsp[-3])->varname,(yyvsp[-3])->nodetype,(yyvsp[-1]),(yyvsp[-3])->middle,(yyvsp[-3])->right); }
#line 2080 "y.tab.c" /* yacc.c:1646  */
    break;

  case 93:
#line 200 "arith.y" /* yacc.c:1646  */
    { (yyval)=createTree((yyvsp[-4])->val,(yyvsp[-6])->type,(yyvsp[-6])->varname,(yyvsp[-6])->nodetype,(yyvsp[-4]),(yyvsp[-6])->middle,(yyvsp[-1]));}
#line 2086 "y.tab.c" /* yacc.c:1646  */
    break;

  case 94:
#line 201 "arith.y" /* yacc.c:1646  */
    { (yyval)=(yyvsp[0]); }
#line 2092 "y.tab.c" /* yacc.c:1646  */
    break;

  case 95:
#line 204 "arith.y" /* yacc.c:1646  */
    { (yyval)=(yyvsp[0]);}
#line 2098 "y.tab.c" /* yacc.c:1646  */
    break;

  case 96:
#line 205 "arith.y" /* yacc.c:1646  */
    { (yyval)=createTree((yyvsp[0])->val,(yyvsp[0])->type,(yyvsp[0])->varname,POINTER,(yyvsp[0])->left,(yyvsp[0])->middle,(yyvsp[0])->right);
				free((yyvsp[0])); }
#line 2105 "y.tab.c" /* yacc.c:1646  */
    break;

  case 97:
#line 207 "arith.y" /* yacc.c:1646  */
    { (yyval)=(yyvsp[0]); }
#line 2111 "y.tab.c" /* yacc.c:1646  */
    break;

  case 98:
#line 210 "arith.y" /* yacc.c:1646  */
    { typecheck((yyvsp[-2]));  tuple_type_check((yyvsp[-2]),(yyvsp[0]),(yyval));
					
					
				  }
#line 2120 "y.tab.c" /* yacc.c:1646  */
    break;

  case 99:
#line 214 "arith.y" /* yacc.c:1646  */
    { tnode *t1; FieldList *f;
						 t1=(yyvsp[-2]);
						 while(t1->field!=NULL)
							 t1=t1->field;
						 f=FLookup(t1->type,(yyvsp[0])->varname);
						 if(f==NULL){
							fprintf(stderr,"error, %d: No field named %s in %s type",line,(yyvsp[0])->varname,t1->type->name);
							exit(1);
						 }
						 t1->nodetype=FIELD;
						 t1->field=(yyvsp[0]);
						 (yyvsp[0])->type=f->type;
						 (yyvsp[0])->val=f->fieldIndex;
						 (yyvsp[-2])->type=(yyvsp[0])->type;
						 (yyval)=(yyvsp[-2]);
						 }
#line 2141 "y.tab.c" /* yacc.c:1646  */
    break;


#line 2145 "y.tab.c" /* yacc.c:1646  */
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
#line 231 "arith.y" /* yacc.c:1906  */


int yyerror(char const *s){
	fprintf(stderr,"error, %d : %s\n",line,s);
	return 1;
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
void type_table_configure(char *name)
{
								  TypeTable *type_table=TLookup(name);
								  //fieldcheck(fieldlist);
								  type_table->fields=fieldlist;
								  fieldlist=NULL;
								  type_table->size=getSize(type_table);

}
void function_call(tnode *t,char *name)
{
											if(strcmp(name,"main")!=0)
											paramcheck(name);
											print_local_table();
											CodeGenerate(t, name);
											Lsymbol_table=NULL;
											local_binding=1;
											paramlist=NULL;
}
void tuple_type_check (tnode *t,tnode *q,tnode * r)
{
	if(t->type==TLookup("tuple")){
		Gsymbol *p= GLookup(t->varname);
		TupleList *list= p->tuplelist;
		while(list!=NULL){
				if(!strcmp(list->name,q->varname)){
					t->type=list->type;
					t->nodetype=TUPLEFIELD;
					t->tuplefield=q;
					r=t;
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
		if(t->type==TLookup("int") || t->type==TLookup("str")){
		    yyerror("invalid field access");
		    exit(1);
		}
		f=FLookup(t->type,q->varname);
		if(f==NULL){
			    fprintf(stderr,"error, %d: No field named %s in %s type",line,q->varname,t->type->name);
			    exit(1);
		           }
			t->nodetype=FIELD;
			t->field=q;
			q->type=f->type;
			q->val=f->fieldIndex;
			t->type=q->type;
			r=t;
					}

}
int main(int argc, char *argv[]){
	
	extern int reg;
	char ch;
	if(argc==3){
		yyin=fopen(argv[1],"r");
		out=fopen(argv[2],"w+");
	}else if(argc==2){
		yyin=stdin;
		out=fopen(argv[1],"w+");
	}
	else{
		yyin=stdin;
		out=stdout;
	}
	reg=0;
	xsm_file=fopen(".xsm_file","w");
	TypeTableCreate();
	yyparse();
	generateCode();
	
	
	fclose(xsm_file);
	xsm_file=fopen(".xsm_file","r");
	while((ch=fgetc(xsm_file))!=EOF){
		fputc(ch, out);
	}
	fclose(out);
	fclose(yyin);
	
	return 0;
}

