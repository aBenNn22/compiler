/* A Bison parser, made by GNU Bison 3.5.1.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2020 Free Software Foundation,
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

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.5.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 4 "sysy.y"

#include "stdio.h"
#include "math.h"
#include "string.h"
#include "def.h"
extern int yylineno;
extern char *yytext;
extern FILE *yyin;
void yyerror(const char* fmt, ...);
void display(struct node *,int);
int yylex();
char filename[32];

#line 84 "sysy.tab.c"

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

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 1
#endif

/* Use api.header.include to #include this header
   instead of duplicating it here.  */
#ifndef YY_YY_SYSY_TAB_H_INCLUDED
# define YY_YY_SYSY_TAB_H_INCLUDED
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
    INT = 258,
    FLOAT = 259,
    VOID = 260,
    CONST = 261,
    RETURN = 262,
    IF = 263,
    ELSE = 264,
    FOR = 265,
    WHILE = 266,
    DO = 267,
    BREAK = 268,
    CONTINUE = 269,
    LP = 270,
    RP = 271,
    LB = 272,
    RB = 273,
    LC = 274,
    RC = 275,
    COMMA = 276,
    SEMICOLON = 277,
    QUESTION = 278,
    COLON = 279,
    MINUS = 280,
    NOT = 281,
    TILDE = 282,
    ASSIGN = 283,
    ADD = 284,
    MUL = 285,
    DIV = 286,
    MOD = 287,
    AND = 288,
    OR = 289,
    ID = 290,
    EQ = 291,
    NE = 292,
    LT = 293,
    LE = 294,
    GT = 295,
    GE = 296,
    INT_LIT = 297,
    FLOAT_LIT = 298,
    LEX_ERR = 299,
    PLUS = 300,
    AUTOADD = 301,
    AUTOMINUS = 302,
    UADD = 303,
    UMINUS = 304,
    LOWER_THEN_ELSE = 305
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 18 "sysy.y"

	int    type_int;
	float  type_float;
	char   type_id[32];
	struct node *ptr;

#line 194 "sysy.tab.c"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif

/* Location type.  */
#if ! defined YYLTYPE && ! defined YYLTYPE_IS_DECLARED
typedef struct YYLTYPE YYLTYPE;
struct YYLTYPE
{
  int first_line;
  int first_column;
  int last_line;
  int last_column;
};
# define YYLTYPE_IS_DECLARED 1
# define YYLTYPE_IS_TRIVIAL 1
#endif


extern YYSTYPE yylval;
extern YYLTYPE yylloc;
int yyparse (void);

#endif /* !YY_YY_SYSY_TAB_H_INCLUDED  */



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
typedef yytype_uint8 yy_state_t;

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
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && ! defined __ICC && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                            \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
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
         || (defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL \
             && defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
  YYLTYPE yyls_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE) \
             + YYSIZEOF (YYLTYPE)) \
      + 2 * YYSTACK_GAP_MAXIMUM)

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
#define YYFINAL  14
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   274

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  51
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  43
/* YYNRULES -- Number of rules.  */
#define YYNRULES  111
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  200

#define YYUNDEFTOK  2
#define YYMAXUTOK   305


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
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
      45,    46,    47,    48,    49,    50
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    63,    63,    65,    66,    67,    68,    71,    72,    73,
      74,    77,    82,    83,    90,    91,    94,    95,    98,   101,
     102,   105,   106,   109,   110,   113,   116,   117,   124,   127,
     128,   131,   132,   133,   136,   137,   140,   143,   144,   145,
     149,   150,   153,   154,   155,   158,   159,   160,   161,   162,
     163,   164,   165,   166,   167,   168,   169,   172,   173,   174,
     175,   176,   177,   178,   179,   182,   183,   185,   187,   188,
     191,   194,   197,   198,   200,   204,   205,   206,   209,   210,
     213,   214,   215,   216,   217,   220,   221,   224,   225,   226,
     229,   230,   233,   234,   235,   236,   239,   240,   241,   244,
     245,   246,   247,   248,   251,   252,   253,   256,   257,   260,
     261,   264
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 1
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "INT", "FLOAT", "VOID", "CONST",
  "RETURN", "IF", "ELSE", "FOR", "WHILE", "DO", "BREAK", "CONTINUE", "LP",
  "RP", "LB", "RB", "LC", "RC", "COMMA", "SEMICOLON", "QUESTION", "COLON",
  "MINUS", "NOT", "TILDE", "ASSIGN", "ADD", "MUL", "DIV", "MOD", "AND",
  "OR", "ID", "EQ", "NE", "LT", "LE", "GT", "GE", "INT_LIT", "FLOAT_LIT",
  "LEX_ERR", "PLUS", "AUTOADD", "AUTOMINUS", "UADD", "UMINUS",
  "LOWER_THEN_ELSE", "$accept", "CompUnits", "CompUnit", "FuncDef",
  "FuncType", "FuncFParams", "FuncfFParam", "BlockMul", "Block",
  "BlockItem", "Decl", "ConstDeclMul", "ConstDecl", "BType", "ConstDef",
  "ConstInitValMul", "ConstInitVal", "VarDeclMul", "VarDecl", "VarDef",
  "InitValMul", "InitVal", "Stmt", "ForDec", "ForExp1", "ForExp2",
  "ForExp3", "Exp", "Cond", "LVal", "PrimaryExp", "Number", "UnaryExp",
  "AutoOp", "UnaryOp", "FuncRParams", "MulExp", "AddExp", "RelExp",
  "EqExp", "LAndExp", "LOrExp", "ConstExp", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_int16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305
};
# endif

#define YYPACT_NINF (-149)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     130,  -149,  -149,  -149,    13,    52,   130,  -149,    21,  -149,
    -149,    25,  -149,    27,  -149,  -149,  -149,    51,     3,    56,
    -149,    47,    98,  -149,    91,   114,    40,   157,    49,  -149,
     176,    27,  -149,    97,    58,  -149,    89,    97,    72,   108,
     226,    61,  -149,  -149,  -149,     7,  -149,  -149,  -149,  -149,
    -149,  -149,  -149,    76,   226,    67,   -10,    -5,  -149,    86,
    -149,   -10,  -149,  -149,  -149,  -149,    97,    13,   124,  -149,
      97,   128,   115,  -149,   118,  -149,   178,   105,  -149,  -149,
    -149,    76,   226,   226,   226,   226,   226,  -149,   123,  -149,
      22,  -149,  -149,   143,  -149,   122,  -149,  -149,   157,  -149,
    -149,    93,   153,    76,    76,    76,    67,    67,  -149,   176,
     200,   158,   160,   170,   165,   166,  -149,  -149,  -149,  -149,
    -149,    49,  -149,   167,   168,  -149,   188,  -149,  -149,   226,
     191,  -149,  -149,   187,   226,    50,   226,  -149,  -149,  -149,
     226,  -149,  -149,   175,  -149,   196,   -10,   232,   113,   181,
     182,   202,  -149,   201,   214,   224,   216,   211,   218,   155,
     226,   226,   226,   226,   226,   226,   226,   226,   226,   212,
    -149,  -149,    97,   226,   225,   155,  -149,  -149,   229,   -10,
     -10,   -10,   -10,   232,   232,   113,   181,  -149,   219,   226,
    -149,  -149,   226,  -149,   155,   226,  -149,  -149,  -149,  -149
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,    26,    27,    11,     0,     0,     2,     6,     0,     5,
      21,     0,    22,     0,     1,     4,     3,     0,    37,     0,
      34,     0,     0,    23,     0,     0,     0,     0,     0,    36,
       0,     0,    25,     0,     0,    12,     0,     0,     0,     0,
       0,     0,    88,    89,    87,    72,    78,    79,    38,    42,
      76,    80,    77,    92,     0,    96,    70,    37,    35,     0,
      28,   111,    31,    24,    16,     9,     0,     0,    14,     7,
       0,     0,     0,    43,     0,    40,     0,     0,    85,    86,
      84,    83,     0,     0,     0,     0,     0,    32,     0,    29,
       0,    10,    13,     0,     8,     0,    75,    44,     0,    81,
      90,     0,     0,    93,    94,    95,    98,    97,    33,     0,
       0,     0,     0,     0,     0,     0,    18,    46,    48,    17,
      19,     0,    20,     0,    76,    15,     0,    41,    82,     0,
      74,    30,    55,     0,     0,     0,     0,    52,    53,    47,
       0,    39,    91,     0,    54,     0,    99,   104,   107,   109,
      71,     0,    65,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    64,     0,
      67,    66,     0,    60,     0,     0,    45,    73,    49,   100,
     102,   101,   103,   105,   106,   108,   110,    63,    69,    62,
      56,    58,    59,    51,     0,     0,    61,    57,    50,    68
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -149,  -149,  -149,   242,  -149,   231,   190,  -149,   -32,  -149,
       1,  -149,  -149,     2,   223,  -149,   -50,  -149,   125,   -25,
    -149,   -31,  -148,  -149,  -149,   103,  -134,   -27,   -91,   -86,
    -149,  -149,   -14,  -149,  -149,  -149,    74,    -9,    14,    96,
     107,  -149,  -149
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     5,     6,     7,     8,    34,    35,    90,   118,   119,
       9,    22,    10,    36,    23,    88,    60,    19,    12,    20,
      74,    48,   122,   154,   155,   169,   187,   188,   170,    50,
      51,    52,    53,    80,    54,   101,    55,    56,   147,   148,
     149,   150,    62
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      49,    65,    11,    58,   124,    69,    13,    16,    11,    89,
      75,   178,    26,    72,    49,    85,     1,     2,    25,    86,
      26,    61,    76,    27,    77,     1,     2,   193,     4,   110,
     111,    27,   112,   113,    91,   114,   115,    40,    94,   191,
      81,    64,   116,   145,   117,   156,   198,    42,    43,   100,
      61,    44,    14,     1,     2,   196,    17,    45,   197,   131,
      18,   199,    21,   123,    46,    47,    24,   127,   103,   104,
     105,    49,   151,   124,    66,    30,    40,    28,    29,    67,
      41,    73,    39,   133,    57,    57,    42,    43,    70,   124,
      44,   120,   121,    67,     1,     2,    45,    82,    83,    84,
      61,    40,   142,    46,    47,    59,    87,    33,   124,   128,
     153,    42,    43,   157,   129,    44,    64,     1,     2,    31,
      32,    45,    78,    79,    68,   146,    71,   146,    46,    47,
      37,    96,   123,     1,     2,     3,     4,   121,    97,    98,
     190,    93,   146,   108,   109,    95,   146,   102,   123,   164,
     165,   179,   180,   181,   182,   146,   146,   146,   146,   106,
     107,   125,   110,   111,   126,   112,   113,   123,   114,   115,
      40,   130,    40,   134,    64,   135,    41,   117,   183,   184,
      42,    43,    42,    43,    44,   136,    44,   137,   138,   139,
      45,    40,    45,    40,    99,    59,   140,    46,    47,    46,
      47,    42,    43,    42,    43,    44,   141,    44,   143,   144,
     158,    45,   159,    45,   166,    40,   167,    40,    46,    47,
      46,    47,   132,   171,   168,    42,    43,    42,    43,    44,
     172,    44,   175,   176,   189,    45,   177,    45,   194,    40,
     195,    40,    46,    47,    46,    47,   173,   192,    15,    42,
      43,    42,    43,    44,    63,    44,    38,    92,   174,    45,
     152,    45,   185,     0,     0,     0,    46,    47,    46,    47,
     160,   161,   162,   163,   186
};

static const yytype_int16 yycheck[] =
{
      27,    33,     0,    28,    90,    37,     4,     6,     6,    59,
      41,   159,    17,    40,    41,    25,     3,     4,    15,    29,
      17,    30,    15,    28,    17,     3,     4,   175,     6,     7,
       8,    28,    10,    11,    66,    13,    14,    15,    70,   173,
      54,    19,    20,   134,    22,   136,   194,    25,    26,    76,
      59,    29,     0,     3,     4,   189,    35,    35,   192,   109,
      35,   195,    35,    90,    42,    43,    15,    98,    82,    83,
      84,    98,    22,   159,    16,    28,    15,    21,    22,    21,
      19,    20,    42,   110,    35,    35,    25,    26,    16,   175,
      29,    90,    90,    21,     3,     4,    35,    30,    31,    32,
     109,    15,   129,    42,    43,    19,    20,    16,   194,    16,
     135,    25,    26,   140,    21,    29,    19,     3,     4,    21,
      22,    35,    46,    47,    35,   134,    18,   136,    42,    43,
      16,    16,   159,     3,     4,     5,     6,   135,    20,    21,
     172,    17,   151,    20,    21,    17,   155,    42,   175,    36,
      37,   160,   161,   162,   163,   164,   165,   166,   167,    85,
      86,    18,     7,     8,    42,    10,    11,   194,    13,    14,
      15,    18,    15,    15,    19,    15,    19,    22,   164,   165,
      25,    26,    25,    26,    29,    15,    29,    22,    22,    22,
      35,    15,    35,    15,    16,    19,    28,    42,    43,    42,
      43,    25,    26,    25,    26,    29,    18,    29,    17,    22,
      35,    35,    16,    35,    33,    15,    34,    15,    42,    43,
      42,    43,    22,    22,    22,    25,    26,    25,    26,    29,
      16,    29,    16,    22,    22,    35,    18,    35,     9,    15,
      21,    15,    42,    43,    42,    43,    22,    22,     6,    25,
      26,    25,    26,    29,    31,    29,    25,    67,   155,    35,
     135,    35,   166,    -1,    -1,    -1,    42,    43,    42,    43,
      38,    39,    40,    41,   167
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     3,     4,     5,     6,    52,    53,    54,    55,    61,
      63,    64,    69,    64,     0,    54,    61,    35,    35,    68,
      70,    35,    62,    65,    15,    15,    17,    28,    21,    22,
      28,    21,    22,    16,    56,    57,    64,    16,    56,    42,
      15,    19,    25,    26,    29,    35,    42,    43,    72,    78,
      80,    81,    82,    83,    85,    87,    88,    35,    70,    19,
      67,    88,    93,    65,    19,    59,    16,    21,    35,    59,
      16,    18,    78,    20,    71,    72,    15,    17,    46,    47,
      84,    83,    30,    31,    32,    25,    29,    20,    66,    67,
      58,    59,    57,    17,    59,    17,    16,    20,    21,    16,
      78,    86,    42,    83,    83,    83,    87,    87,    20,    21,
       7,     8,    10,    11,    13,    14,    20,    22,    59,    60,
      61,    64,    73,    78,    80,    18,    42,    72,    16,    21,
      18,    67,    22,    78,    15,    15,    15,    22,    22,    22,
      28,    18,    78,    17,    22,    79,    88,    89,    90,    91,
      92,    22,    69,    70,    74,    75,    79,    78,    35,    16,
      38,    39,    40,    41,    36,    37,    33,    34,    22,    76,
      79,    22,    16,    22,    76,    16,    22,    18,    73,    88,
      88,    88,    88,    89,    89,    90,    91,    77,    78,    22,
      59,    77,    22,    73,     9,    21,    77,    77,    73,    77
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    51,    52,    53,    53,    53,    53,    54,    54,    54,
      54,    55,    56,    56,    57,    57,    58,    58,    59,    60,
      60,    61,    61,    62,    62,    63,    64,    64,    65,    66,
      66,    67,    67,    67,    68,    68,    69,    70,    70,    70,
      71,    71,    72,    72,    72,    73,    73,    73,    73,    73,
      73,    73,    73,    73,    73,    73,    73,    74,    74,    74,
      74,    74,    74,    74,    74,    75,    75,    76,    77,    77,
      78,    79,    80,    80,    80,    81,    81,    81,    82,    82,
      83,    83,    83,    83,    83,    84,    84,    85,    85,    85,
      86,    86,    87,    87,    87,    87,    88,    88,    88,    89,
      89,    89,    89,    89,    90,    90,    90,    91,    91,    92,
      92,    93
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     2,     2,     1,     1,     5,     6,     5,
       6,     1,     1,     3,     2,     4,     0,     2,     3,     1,
       1,     1,     1,     1,     3,     4,     1,     1,     3,     1,
       3,     1,     2,     3,     1,     3,     3,     1,     3,     7,
       1,     3,     1,     2,     3,     4,     1,     2,     1,     5,
       7,     5,     2,     2,     3,     2,     5,     4,     3,     3,
       2,     4,     3,     3,     2,     1,     2,     1,     3,     1,
       1,     1,     1,     7,     4,     3,     1,     1,     1,     1,
       1,     3,     4,     2,     2,     1,     1,     1,     1,     1,
       1,     3,     1,     3,     3,     3,     1,     3,     3,     1,
       3,     3,     3,     3,     1,     3,     3,     1,     3,     1,
       3,     1
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


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
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)                                \
    do                                                                  \
      if (N)                                                            \
        {                                                               \
          (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;        \
          (Current).first_column = YYRHSLOC (Rhs, 1).first_column;      \
          (Current).last_line    = YYRHSLOC (Rhs, N).last_line;         \
          (Current).last_column  = YYRHSLOC (Rhs, N).last_column;       \
        }                                                               \
      else                                                              \
        {                                                               \
          (Current).first_line   = (Current).last_line   =              \
            YYRHSLOC (Rhs, 0).last_line;                                \
          (Current).first_column = (Current).last_column =              \
            YYRHSLOC (Rhs, 0).last_column;                              \
        }                                                               \
    while (0)
#endif

#define YYRHSLOC(Rhs, K) ((Rhs)[K])


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


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL

/* Print *YYLOCP on YYO.  Private, do not rely on its existence. */

YY_ATTRIBUTE_UNUSED
static int
yy_location_print_ (FILE *yyo, YYLTYPE const * const yylocp)
{
  int res = 0;
  int end_col = 0 != yylocp->last_column ? yylocp->last_column - 1 : 0;
  if (0 <= yylocp->first_line)
    {
      res += YYFPRINTF (yyo, "%d", yylocp->first_line);
      if (0 <= yylocp->first_column)
        res += YYFPRINTF (yyo, ".%d", yylocp->first_column);
    }
  if (0 <= yylocp->last_line)
    {
      if (yylocp->first_line < yylocp->last_line)
        {
          res += YYFPRINTF (yyo, "-%d", yylocp->last_line);
          if (0 <= end_col)
            res += YYFPRINTF (yyo, ".%d", end_col);
        }
      else if (0 <= end_col && yylocp->first_column < end_col)
        res += YYFPRINTF (yyo, "-%d", end_col);
    }
  return res;
 }

#  define YY_LOCATION_PRINT(File, Loc)          \
  yy_location_print_ (File, &(Loc))

# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value, Location); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
{
  FILE *yyoutput = yyo;
  YYUSE (yyoutput);
  YYUSE (yylocationp);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyo, yytoknum[yytype], *yyvaluep);
# endif
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
{
  YYFPRINTF (yyo, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  YY_LOCATION_PRINT (yyo, *yylocationp);
  YYFPRINTF (yyo, ": ");
  yy_symbol_value_print (yyo, yytype, yyvaluep, yylocationp);
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
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp, YYLTYPE *yylsp, int yyrule)
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
                       yystos[+yyssp[yyi + 1 - yynrhs]],
                       &yyvsp[(yyi + 1) - (yynrhs)]
                       , &(yylsp[(yyi + 1) - (yynrhs)])                       );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, yylsp, Rule); \
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
#   define yystrlen(S) (YY_CAST (YYPTRDIFF_T, strlen (S)))
#  else
/* Return the length of YYSTR.  */
static YYPTRDIFF_T
yystrlen (const char *yystr)
{
  YYPTRDIFF_T yylen;
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
static YYPTRDIFF_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYPTRDIFF_T yyn = 0;
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
            else
              goto append;

          append:
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

  if (yyres)
    return yystpcpy (yyres, yystr) - yyres;
  else
    return yystrlen (yystr);
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
yysyntax_error (YYPTRDIFF_T *yymsg_alloc, char **yymsg,
                yy_state_t *yyssp, int yytoken)
{
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat: reported tokens (one for the "unexpected",
     one per "expected"). */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Actual size of YYARG. */
  int yycount = 0;
  /* Cumulated lengths of YYARG.  */
  YYPTRDIFF_T yysize = 0;

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
      int yyn = yypact[+*yyssp];
      YYPTRDIFF_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
      yysize = yysize0;
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
                  YYPTRDIFF_T yysize1
                    = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
                    yysize = yysize1;
                  else
                    return 2;
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
    default: /* Avoid compiler warnings. */
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    /* Don't count the "%s"s in the final size, but reserve room for
       the terminator.  */
    YYPTRDIFF_T yysize1 = yysize + (yystrlen (yyformat) - 2 * yycount) + 1;
    if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
      yysize = yysize1;
    else
      return 2;
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
          ++yyp;
          ++yyformat;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep, YYLTYPE *yylocationp)
{
  YYUSE (yyvaluep);
  YYUSE (yylocationp);
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
/* Location data for the lookahead symbol.  */
YYLTYPE yylloc
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
  = { 1, 1, 1, 1 }
# endif
;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.
       'yyls': related to locations.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss;
    yy_state_t *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    /* The location stack.  */
    YYLTYPE yylsa[YYINITDEPTH];
    YYLTYPE *yyls;
    YYLTYPE *yylsp;

    /* The locations where the error started and ended.  */
    YYLTYPE yyerror_range[3];

    YYPTRDIFF_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;
  YYLTYPE yyloc;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYPTRDIFF_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N), yylsp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yylsp = yyls = yylsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  yylsp[0] = yylloc;
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

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    goto yyexhaustedlab;
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
        YYLTYPE *yyls1 = yyls;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yyls1, yysize * YYSIZEOF (*yylsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
        yyls = yyls1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
        YYSTACK_RELOCATE (yyls_alloc, yyls);
# undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;
      yylsp = yyls + yysize - 1;

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
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END
  *++yylsp = yylloc;

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

  /* Default location. */
  YYLLOC_DEFAULT (yyloc, (yylsp - yylen), yylen);
  yyerror_range[1] = yyloc;
  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 2:
#line 63 "sysy.y"
                    {display((yyvsp[0].ptr),0);}
#line 1642 "sysy.tab.c"
    break;

  case 3:
#line 65 "sysy.y"
                        {(yyval.ptr)=mknode(COMP_UNIT,(yyvsp[-1].ptr),(yyvsp[0].ptr),NULL,yylineno);}
#line 1648 "sysy.tab.c"
    break;

  case 4:
#line 66 "sysy.y"
                           {(yyval.ptr)=mknode(COMP_UNIT,(yyvsp[-1].ptr),(yyvsp[0].ptr),NULL,yylineno);}
#line 1654 "sysy.tab.c"
    break;

  case 5:
#line 67 "sysy.y"
               {(yyval.ptr)=mknode(COMP_UNIT,NULL,(yyvsp[0].ptr),NULL,yylineno);}
#line 1660 "sysy.tab.c"
    break;

  case 6:
#line 68 "sysy.y"
                  {(yyval.ptr)=mknode(COMP_UNIT,NULL,(yyvsp[0].ptr),NULL,yylineno);}
#line 1666 "sysy.tab.c"
    break;

  case 7:
#line 71 "sysy.y"
                              {(yyval.ptr)=mknode(FUNC_DEF,(yyvsp[-4].ptr),(yyvsp[0].ptr),NULL,yylineno); strcpy((yyval.ptr)->type_id,(yyvsp[-3].type_id));}
#line 1672 "sysy.tab.c"
    break;

  case 8:
#line 72 "sysy.y"
                                           {(yyval.ptr)=mknode(FUNC_DEF,(yyvsp[-5].ptr),(yyvsp[-2].ptr),(yyvsp[0].ptr),yylineno); strcpy((yyval.ptr)->type_id,(yyvsp[-4].type_id));}
#line 1678 "sysy.tab.c"
    break;

  case 9:
#line 73 "sysy.y"
                                  {(yyval.ptr)=mknode(FUNC_DEF,(yyvsp[-4].ptr),(yyvsp[0].ptr),NULL,yylineno); strcpy((yyval.ptr)->type_id,(yyvsp[-3].type_id));}
#line 1684 "sysy.tab.c"
    break;

  case 10:
#line 74 "sysy.y"
                                              {(yyval.ptr)=mknode(FUNC_DEF,(yyvsp[-5].ptr),(yyvsp[-2].ptr),(yyvsp[0].ptr),yylineno); strcpy((yyval.ptr)->type_id,(yyvsp[-4].type_id));}
#line 1690 "sysy.tab.c"
    break;

  case 11:
#line 77 "sysy.y"
               {(yyval.ptr)=mknode(FUNC_TYPE,NULL,NULL,NULL,yylineno); strcpy((yyval.ptr)->type_id,"void");}
#line 1696 "sysy.tab.c"
    break;

  case 12:
#line 82 "sysy.y"
                         {(yyval.ptr)=mknode(FUNC_PARAMS,NULL,(yyvsp[0].ptr),NULL,yylineno);}
#line 1702 "sysy.tab.c"
    break;

  case 13:
#line 83 "sysy.y"
                                        {(yyval.ptr)=mknode(FUNC_PARAMS,(yyvsp[-2].ptr),(yyvsp[0].ptr),NULL,yylineno);}
#line 1708 "sysy.tab.c"
    break;

  case 14:
#line 90 "sysy.y"
                      {(yyval.ptr)=mknode(FUNC_PARAM,(yyvsp[-1].ptr),NULL,NULL,yylineno); strcpy((yyval.ptr)->type_id,(yyvsp[0].type_id));}
#line 1714 "sysy.tab.c"
    break;

  case 15:
#line 91 "sysy.y"
                         {(yyval.ptr)=mknode(FUNC_PARAM,(yyvsp[-3].ptr),NULL,NULL,yylineno); strcpy((yyval.ptr)->type_id,(yyvsp[-2].type_id));}
#line 1720 "sysy.tab.c"
    break;

  case 16:
#line 94 "sysy.y"
          {(yyval.ptr)=NULL;}
#line 1726 "sysy.tab.c"
    break;

  case 17:
#line 95 "sysy.y"
                             {(yyval.ptr)=mknode(BLOCK_MUL,(yyvsp[-1].ptr),(yyvsp[0].ptr),NULL,yylineno);}
#line 1732 "sysy.tab.c"
    break;

  case 18:
#line 98 "sysy.y"
                      {(yyval.ptr)=mknode(BLOCK,(yyvsp[-1].ptr),NULL,NULL,yylineno);}
#line 1738 "sysy.tab.c"
    break;

  case 19:
#line 101 "sysy.y"
                {(yyval.ptr)=mknode(BLOCK_ITEM,(yyvsp[0].ptr),NULL,NULL,yylineno);}
#line 1744 "sysy.tab.c"
    break;

  case 20:
#line 102 "sysy.y"
               {(yyval.ptr)=mknode(BLOCK_ITEM,(yyvsp[0].ptr),NULL,NULL,yylineno);}
#line 1750 "sysy.tab.c"
    break;

  case 21:
#line 105 "sysy.y"
                {(yyval.ptr)=mknode(DECL,(yyvsp[0].ptr),NULL,NULL,yylineno);}
#line 1756 "sysy.tab.c"
    break;

  case 22:
#line 106 "sysy.y"
                  {(yyval.ptr)=mknode(DECL,(yyvsp[0].ptr),NULL,NULL,yylineno);}
#line 1762 "sysy.tab.c"
    break;

  case 23:
#line 109 "sysy.y"
                       {(yyval.ptr)=mknode(CONST_DECL_MUL,NULL,(yyvsp[0].ptr),NULL,yylineno);}
#line 1768 "sysy.tab.c"
    break;

  case 24:
#line 110 "sysy.y"
                                      {(yyval.ptr)=mknode(CONST_DECL_MUL,(yyvsp[-2].ptr),(yyvsp[0].ptr),NULL,yylineno);}
#line 1774 "sysy.tab.c"
    break;

  case 25:
#line 113 "sysy.y"
                                              {(yyval.ptr)=mknode(CONST_DECL,(yyvsp[-2].ptr),(yyvsp[-1].ptr),NULL,yylineno); strcpy((yyval.ptr)->type_id,"const");}
#line 1780 "sysy.tab.c"
    break;

  case 26:
#line 116 "sysy.y"
           {(yyval.ptr)=mknode(BTYPE,NULL,NULL,NULL,yylineno); strcpy((yyval.ptr)->type_id,"int");}
#line 1786 "sysy.tab.c"
    break;

  case 27:
#line 117 "sysy.y"
                {(yyval.ptr)=mknode(BTYPE,NULL,NULL,NULL,yylineno); strcpy((yyval.ptr)->type_id,"float");}
#line 1792 "sysy.tab.c"
    break;

  case 28:
#line 124 "sysy.y"
                                 {(yyval.ptr)=mknode(CONST_DEF,(yyvsp[0].ptr),NULL,NULL,yylineno); strcpy((yyval.ptr)->type_id,(yyvsp[-2].type_id));}
#line 1798 "sysy.tab.c"
    break;

  case 29:
#line 127 "sysy.y"
                              {(yyval.ptr)=mknode(CONST_INIT_VAL_MUL,NULL,(yyvsp[0].ptr),NULL,yylineno);}
#line 1804 "sysy.tab.c"
    break;

  case 30:
#line 128 "sysy.y"
                                             {(yyval.ptr)=mknode(CONST_INIT_VAL_MUL,(yyvsp[-2].ptr),(yyvsp[0].ptr),NULL,yylineno);}
#line 1810 "sysy.tab.c"
    break;

  case 31:
#line 131 "sysy.y"
                       {(yyval.ptr)=mknode(CONST_INIT_VAL,(yyvsp[0].ptr),NULL,NULL,yylineno);}
#line 1816 "sysy.tab.c"
    break;

  case 32:
#line 132 "sysy.y"
                {(yyval.ptr)=mknode(CONST_INIT_VAL,NULL,NULL,NULL,yylineno);}
#line 1822 "sysy.tab.c"
    break;

  case 33:
#line 133 "sysy.y"
                                {(yyval.ptr)=mknode(CONST_INIT_VAL,(yyvsp[-1].ptr),NULL,NULL,yylineno);}
#line 1828 "sysy.tab.c"
    break;

  case 34:
#line 136 "sysy.y"
                   {(yyval.ptr)=mknode(VAR_DECL_MUL,NULL,(yyvsp[0].ptr),NULL,yylineno);}
#line 1834 "sysy.tab.c"
    break;

  case 35:
#line 137 "sysy.y"
                                  {(yyval.ptr)=mknode(VAR_DECL_MUL,(yyvsp[-2].ptr),(yyvsp[0].ptr),NULL,yylineno);}
#line 1840 "sysy.tab.c"
    break;

  case 36:
#line 140 "sysy.y"
                                    {(yyval.ptr)=mknode(VAR_DECL,(yyvsp[-2].ptr),(yyvsp[-1].ptr),NULL,yylineno);}
#line 1846 "sysy.tab.c"
    break;

  case 37:
#line 143 "sysy.y"
            {(yyval.ptr)=mknode(VAR_DEF,NULL,NULL,NULL,yylineno); strcpy((yyval.ptr)->type_id,(yyvsp[0].type_id));}
#line 1852 "sysy.tab.c"
    break;

  case 38:
#line 144 "sysy.y"
                            {(yyval.ptr)=mknode(VAR_DEF,(yyvsp[0].ptr),NULL,NULL,yylineno); strcpy((yyval.ptr)->type_id,(yyvsp[-2].type_id));}
#line 1858 "sysy.tab.c"
    break;

  case 39:
#line 145 "sysy.y"
                                        {(yyval.ptr)=mknode(VAR_ARRAY,NULL,NULL,NULL,yylineno); strcpy((yyval.ptr)->type_id,(yyvsp[-6].type_id)); 
                                (yyval.ptr)->type_int1 = (yyvsp[-4].type_int); (yyval.ptr)->type_int2 = (yyvsp[-1].type_int);}
#line 1865 "sysy.tab.c"
    break;

  case 40:
#line 149 "sysy.y"
                    {(yyval.ptr)=mknode(INIT_VAL_MUL,NULL,(yyvsp[0].ptr),NULL,yylineno);}
#line 1871 "sysy.tab.c"
    break;

  case 41:
#line 150 "sysy.y"
                                   {(yyval.ptr)=mknode(INIT_VAL_MUL,(yyvsp[-2].ptr),(yyvsp[0].ptr),NULL,yylineno);}
#line 1877 "sysy.tab.c"
    break;

  case 42:
#line 153 "sysy.y"
             {(yyval.ptr)=mknode(INIT_VAL,(yyvsp[0].ptr),NULL,NULL,yylineno);}
#line 1883 "sysy.tab.c"
    break;

  case 43:
#line 154 "sysy.y"
                {(yyval.ptr)=mknode(INIT_VAL,NULL,NULL,NULL,yylineno);}
#line 1889 "sysy.tab.c"
    break;

  case 44:
#line 155 "sysy.y"
                           {(yyval.ptr)=mknode(INIT_VAL,(yyvsp[-1].ptr),NULL,NULL,yylineno);}
#line 1895 "sysy.tab.c"
    break;

  case 45:
#line 158 "sysy.y"
                                {(yyval.ptr)=mknode(ASSIGN,(yyvsp[-3].ptr),(yyvsp[-1].ptr),NULL,yylineno);}
#line 1901 "sysy.tab.c"
    break;

  case 46:
#line 159 "sysy.y"
                    {(yyval.ptr)=mknode(STMT,NULL,NULL,NULL,yylineno);}
#line 1907 "sysy.tab.c"
    break;

  case 47:
#line 160 "sysy.y"
                        {(yyval.ptr)=mknode(EXP_STMT,(yyvsp[-1].ptr),NULL,NULL,yylineno);}
#line 1913 "sysy.tab.c"
    break;

  case 48:
#line 161 "sysy.y"
                {(yyval.ptr)=(yyvsp[0].ptr);}
#line 1919 "sysy.tab.c"
    break;

  case 49:
#line 162 "sysy.y"
                                                  {(yyval.ptr)=mknode(IF_THEN,(yyvsp[-2].ptr),(yyvsp[0].ptr),NULL,yylineno);}
#line 1925 "sysy.tab.c"
    break;

  case 50:
#line 163 "sysy.y"
                                       {(yyval.ptr)=mknode(IF_THEN_ELSE,(yyvsp[-4].ptr),(yyvsp[-2].ptr),(yyvsp[0].ptr),yylineno);}
#line 1931 "sysy.tab.c"
    break;

  case 51:
#line 164 "sysy.y"
                                {(yyval.ptr)=mknode(WHILE,(yyvsp[-2].ptr),(yyvsp[0].ptr),NULL,yylineno);}
#line 1937 "sysy.tab.c"
    break;

  case 52:
#line 165 "sysy.y"
                          {(yyval.ptr)=mknode(BREAK,NULL,NULL,NULL,yylineno);}
#line 1943 "sysy.tab.c"
    break;

  case 53:
#line 166 "sysy.y"
                             {(yyval.ptr)=mknode(CONTINUE,NULL,NULL,NULL,yylineno);}
#line 1949 "sysy.tab.c"
    break;

  case 54:
#line 167 "sysy.y"
                               {(yyval.ptr)=mknode(RETURN,(yyvsp[-1].ptr),NULL,NULL,yylineno);}
#line 1955 "sysy.tab.c"
    break;

  case 55:
#line 168 "sysy.y"
                           {(yyval.ptr)=mknode(RETURN,NULL,NULL,NULL,yylineno);}
#line 1961 "sysy.tab.c"
    break;

  case 56:
#line 169 "sysy.y"
                                 {(yyval.ptr)=mknode(FOR,(yyvsp[-2].ptr),(yyvsp[0].ptr),NULL,yylineno);}
#line 1967 "sysy.tab.c"
    break;

  case 57:
#line 172 "sysy.y"
                                           {(yyval.ptr)=mknode(FOR_DEC,(yyvsp[-3].ptr),(yyvsp[-2].ptr),(yyvsp[0].ptr),yylineno);}
#line 1973 "sysy.tab.c"
    break;

  case 58:
#line 173 "sysy.y"
                                     {(yyval.ptr)=mknode(FOR_DEC,(yyvsp[-2].ptr),(yyvsp[0].ptr),NULL,yylineno);}
#line 1979 "sysy.tab.c"
    break;

  case 59:
#line 174 "sysy.y"
                                     {(yyval.ptr)=mknode(FOR_DEC,(yyvsp[-2].ptr),(yyvsp[-1].ptr),NULL,yylineno);}
#line 1985 "sysy.tab.c"
    break;

  case 60:
#line 175 "sysy.y"
                             {(yyval.ptr)=mknode(FOR_DEC,(yyvsp[-1].ptr),NULL,NULL,yylineno);}
#line 1991 "sysy.tab.c"
    break;

  case 61:
#line 176 "sysy.y"
                                              {(yyval.ptr)=mknode(FOR_DEC,(yyvsp[-2].ptr),(yyvsp[0].ptr),NULL,yylineno);}
#line 1997 "sysy.tab.c"
    break;

  case 62:
#line 177 "sysy.y"
                                       {(yyval.ptr)=mknode(FOR_DEC,(yyvsp[-1].ptr),NULL,NULL,yylineno);}
#line 2003 "sysy.tab.c"
    break;

  case 63:
#line 178 "sysy.y"
                                      {(yyval.ptr)=mknode(FOR_DEC,(yyvsp[0].ptr),NULL,NULL,yylineno);}
#line 2009 "sysy.tab.c"
    break;

  case 64:
#line 179 "sysy.y"
                              {(yyval.ptr)=mknode(FOR_DEC,NULL,NULL,NULL,yylineno);}
#line 2015 "sysy.tab.c"
    break;

  case 65:
#line 182 "sysy.y"
                  {(yyval.ptr)=mknode(FOR_EXP1,(yyvsp[0].ptr),NULL,NULL,yylineno);}
#line 2021 "sysy.tab.c"
    break;

  case 66:
#line 183 "sysy.y"
                           {(yyval.ptr)=mknode(FOR_EXP1,(yyvsp[-1].ptr),NULL,NULL,yylineno);}
#line 2027 "sysy.tab.c"
    break;

  case 67:
#line 185 "sysy.y"
              {(yyval.ptr)=mknode(FOR_EXP2,(yyvsp[0].ptr),NULL,NULL,yylineno);}
#line 2033 "sysy.tab.c"
    break;

  case 68:
#line 187 "sysy.y"
                            {(yyval.ptr)=mknode(FOR_EXP3,(yyvsp[-2].ptr),(yyvsp[0].ptr),NULL,yylineno);}
#line 2039 "sysy.tab.c"
    break;

  case 69:
#line 188 "sysy.y"
              {(yyval.ptr)=mknode(FOR_EXP3,(yyvsp[0].ptr),NULL,NULL,yylineno);}
#line 2045 "sysy.tab.c"
    break;

  case 70:
#line 191 "sysy.y"
            {(yyval.ptr)=mknode(EXP,(yyvsp[0].ptr),NULL,NULL,yylineno);}
#line 2051 "sysy.tab.c"
    break;

  case 71:
#line 194 "sysy.y"
             {(yyval.ptr)=mknode(COND,(yyvsp[0].ptr),NULL,NULL,yylineno);}
#line 2057 "sysy.tab.c"
    break;

  case 72:
#line 197 "sysy.y"
         {(yyval.ptr)=mknode(LVAL,NULL,NULL,NULL,yylineno); strcpy((yyval.ptr)->type_id,(yyvsp[0].type_id));}
#line 2063 "sysy.tab.c"
    break;

  case 73:
#line 198 "sysy.y"
                                    {(yyval.ptr)=mknode(LVAL_ARRAY,NULL,NULL,NULL,yylineno); strcpy((yyval.ptr)->type_id,(yyvsp[-6].type_id));
                                strcpy((yyval.ptr)->type_id1,(yyvsp[-1].type_id)); (yyval.ptr)->type_int1 = (yyvsp[-4].type_int);}
#line 2070 "sysy.tab.c"
    break;

  case 74:
#line 200 "sysy.y"
                           {(yyval.ptr)=mknode(LVAL_ARRAY,NULL,NULL,NULL,yylineno); strcpy((yyval.ptr)->type_id,(yyvsp[-3].type_id));
                                (yyval.ptr)->type_int1 = (yyvsp[-1].type_int);}
#line 2077 "sysy.tab.c"
    break;

  case 75:
#line 204 "sysy.y"
                      {(yyval.ptr)=mknode(PRIMARY_EXP,(yyvsp[-1].ptr),NULL,NULL,yylineno);}
#line 2083 "sysy.tab.c"
    break;

  case 76:
#line 205 "sysy.y"
               {(yyval.ptr)=mknode(PRIMARY_EXP,(yyvsp[0].ptr),NULL,NULL,yylineno);}
#line 2089 "sysy.tab.c"
    break;

  case 77:
#line 206 "sysy.y"
                 {(yyval.ptr)=mknode(PRIMARY_EXP,(yyvsp[0].ptr),NULL,NULL,yylineno);}
#line 2095 "sysy.tab.c"
    break;

  case 78:
#line 209 "sysy.y"
                {(yyval.ptr)=mknode(INT_LIT,NULL,NULL,NULL,yylineno); (yyval.ptr)->type_int = (yyvsp[0].type_int);}
#line 2101 "sysy.tab.c"
    break;

  case 79:
#line 210 "sysy.y"
                    {(yyval.ptr)=mknode(FLOAT_LIT,NULL,NULL,NULL,yylineno); (yyval.ptr)->type_float = (yyvsp[0].type_float);}
#line 2107 "sysy.tab.c"
    break;

  case 80:
#line 213 "sysy.y"
                     {(yyval.ptr)=mknode(UNARY_EXP,(yyvsp[0].ptr),NULL,NULL,yylineno);}
#line 2113 "sysy.tab.c"
    break;

  case 81:
#line 214 "sysy.y"
                   {(yyval.ptr)=mknode(FUNC_CALL,NULL,NULL,NULL,yylineno); strcpy((yyval.ptr)->type_id,(yyvsp[-2].type_id));}
#line 2119 "sysy.tab.c"
    break;

  case 82:
#line 215 "sysy.y"
                               {(yyval.ptr)=mknode(FUNC_CALL,(yyvsp[-1].ptr),NULL,NULL,yylineno); strcpy((yyval.ptr)->type_id,(yyvsp[-3].type_id));}
#line 2125 "sysy.tab.c"
    break;

  case 83:
#line 216 "sysy.y"
                           {(yyval.ptr)=mknode(UNARY_EXP,(yyvsp[-1].ptr),(yyvsp[0].ptr),NULL,yylineno);}
#line 2131 "sysy.tab.c"
    break;

  case 84:
#line 217 "sysy.y"
                          {(yyval.ptr)=mknode(UNARY_EXP,(yyvsp[-1].ptr),(yyvsp[0].ptr),NULL,yylineno);}
#line 2137 "sysy.tab.c"
    break;

  case 85:
#line 220 "sysy.y"
                {(yyval.ptr)=mknode(AUTOADD,NULL,NULL,NULL,yylineno);}
#line 2143 "sysy.tab.c"
    break;

  case 86:
#line 221 "sysy.y"
                    {(yyval.ptr)=mknode(AUTOMINUS,NULL,NULL,NULL,yylineno);}
#line 2149 "sysy.tab.c"
    break;

  case 87:
#line 224 "sysy.y"
             {(yyval.ptr)=mknode(UADD,NULL,NULL,NULL,yylineno);}
#line 2155 "sysy.tab.c"
    break;

  case 88:
#line 225 "sysy.y"
                {(yyval.ptr)=mknode(UMINUS,NULL,NULL,NULL,yylineno);}
#line 2161 "sysy.tab.c"
    break;

  case 89:
#line 226 "sysy.y"
              {(yyval.ptr)=mknode(NOT,NULL,NULL,NULL,yylineno);}
#line 2167 "sysy.tab.c"
    break;

  case 90:
#line 229 "sysy.y"
                 {(yyval.ptr)=mknode(FUNCR_PARAMS,NULL,(yyvsp[0].ptr),NULL,yylineno);}
#line 2173 "sysy.tab.c"
    break;

  case 91:
#line 230 "sysy.y"
                                {(yyval.ptr)=mknode(FUNC_PARAMS,(yyvsp[-2].ptr),(yyvsp[0].ptr),NULL,yylineno);}
#line 2179 "sysy.tab.c"
    break;

  case 92:
#line 233 "sysy.y"
                 {(yyval.ptr)=mknode(MUL_EXP,(yyvsp[0].ptr),NULL,NULL,yylineno);}
#line 2185 "sysy.tab.c"
    break;

  case 93:
#line 234 "sysy.y"
                              {(yyval.ptr)=mknode(MUL,(yyvsp[-2].ptr),(yyvsp[0].ptr),NULL,yylineno);}
#line 2191 "sysy.tab.c"
    break;

  case 94:
#line 235 "sysy.y"
                              {(yyval.ptr)=mknode(DIV,(yyvsp[-2].ptr),(yyvsp[0].ptr),NULL,yylineno);}
#line 2197 "sysy.tab.c"
    break;

  case 95:
#line 236 "sysy.y"
                              {(yyval.ptr)=mknode(MOD,(yyvsp[-2].ptr),(yyvsp[0].ptr),NULL,yylineno);}
#line 2203 "sysy.tab.c"
    break;

  case 96:
#line 239 "sysy.y"
               {(yyval.ptr)=mknode(ADD_EXP,(yyvsp[0].ptr),NULL,NULL,yylineno);}
#line 2209 "sysy.tab.c"
    break;

  case 97:
#line 240 "sysy.y"
                            {(yyval.ptr)=mknode(ADD,(yyvsp[-2].ptr),(yyvsp[0].ptr),NULL,yylineno);}
#line 2215 "sysy.tab.c"
    break;

  case 98:
#line 241 "sysy.y"
                              {(yyval.ptr)=mknode(MINUS,(yyvsp[-2].ptr),(yyvsp[0].ptr),NULL,yylineno);}
#line 2221 "sysy.tab.c"
    break;

  case 99:
#line 244 "sysy.y"
               {(yyval.ptr)=mknode(REL_EXP,(yyvsp[0].ptr),NULL,NULL,yylineno);}
#line 2227 "sysy.tab.c"
    break;

  case 100:
#line 245 "sysy.y"
                           {(yyval.ptr)=mknode(LT,(yyvsp[-2].ptr),(yyvsp[0].ptr),NULL,yylineno);}
#line 2233 "sysy.tab.c"
    break;

  case 101:
#line 246 "sysy.y"
                           {(yyval.ptr)=mknode(GT,(yyvsp[-2].ptr),(yyvsp[0].ptr),NULL,yylineno);}
#line 2239 "sysy.tab.c"
    break;

  case 102:
#line 247 "sysy.y"
                           {(yyval.ptr)=mknode(LE,(yyvsp[-2].ptr),(yyvsp[0].ptr),NULL,yylineno);}
#line 2245 "sysy.tab.c"
    break;

  case 103:
#line 248 "sysy.y"
                           {(yyval.ptr)=mknode(GE,(yyvsp[-2].ptr),(yyvsp[0].ptr),NULL,yylineno);}
#line 2251 "sysy.tab.c"
    break;

  case 104:
#line 251 "sysy.y"
              {(yyval.ptr)=mknode(EQ_EXP,(yyvsp[0].ptr),NULL,NULL,yylineno);}
#line 2257 "sysy.tab.c"
    break;

  case 105:
#line 252 "sysy.y"
                          {(yyval.ptr)=mknode(EQ,(yyvsp[-2].ptr),(yyvsp[0].ptr),NULL,yylineno);}
#line 2263 "sysy.tab.c"
    break;

  case 106:
#line 253 "sysy.y"
                          {(yyval.ptr)=mknode(NE,(yyvsp[-2].ptr),(yyvsp[0].ptr),NULL,yylineno);}
#line 2269 "sysy.tab.c"
    break;

  case 107:
#line 256 "sysy.y"
               {(yyval.ptr)=mknode(LAND_EXP,(yyvsp[0].ptr),NULL,NULL,yylineno);}
#line 2275 "sysy.tab.c"
    break;

  case 108:
#line 257 "sysy.y"
                            {(yyval.ptr)=mknode(AND,(yyvsp[-2].ptr),(yyvsp[0].ptr),NULL,yylineno);}
#line 2281 "sysy.tab.c"
    break;

  case 109:
#line 260 "sysy.y"
                {(yyval.ptr)=mknode(LOR_EXP,(yyvsp[0].ptr),NULL,NULL,yylineno);}
#line 2287 "sysy.tab.c"
    break;

  case 110:
#line 261 "sysy.y"
                            {(yyval.ptr)=mknode(OR,(yyvsp[-2].ptr),(yyvsp[0].ptr),NULL,yylineno);}
#line 2293 "sysy.tab.c"
    break;

  case 111:
#line 264 "sysy.y"
                 {(yyval.ptr)=mknode(CONST_EXP,(yyvsp[0].ptr),NULL,NULL,yylineno);}
#line 2299 "sysy.tab.c"
    break;


#line 2303 "sysy.tab.c"

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
  *++yylsp = yyloc;

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
            yymsg = YY_CAST (char *, YYSTACK_ALLOC (YY_CAST (YYSIZE_T, yymsg_alloc)));
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

  yyerror_range[1] = yylloc;

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
                      yytoken, &yylval, &yylloc);
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

      yyerror_range[1] = *yylsp;
      yydestruct ("Error: popping",
                  yystos[yystate], yyvsp, yylsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  yyerror_range[2] = yylloc;
  /* Using YYLLOC is tempting, but would change the location of
     the lookahead.  YYLOC is available though.  */
  YYLLOC_DEFAULT (yyloc, yyerror_range, 2);
  *++yylsp = yyloc;

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


/*-----------------------------------------------------.
| yyreturn -- parsing is finished, return the result.  |
`-----------------------------------------------------*/
yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval, &yylloc);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[+*yyssp], yyvsp, yylsp);
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
#line 338 "sysy.y"


int main(int argc, char *argv[]){
	yyin=fopen(argv[1],"r");
	if (!yyin) return 0;
        strcpy(filename,strrchr(argv[1],'/')+1);
	yylineno=1;
	yyparse();
	return 0;
}

#include<stdarg.h>
void yyerror(const char* fmt, ...)
{
        va_list ap;
        va_start(ap, fmt);
        fprintf(stderr,"%s:",filename);
        fprintf(stderr, "%d:%d: ", yylloc.first_line,yylloc.first_column);
        vfprintf(stderr, fmt, ap);
        fprintf(stderr, ".\n");
}	
