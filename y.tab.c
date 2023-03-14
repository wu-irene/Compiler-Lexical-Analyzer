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
#line 1 "ppc_Final.y" /* yacc.c:339  */

#include <stdio.h>
#include <string>
#include <vector>

#include "nodetypes.h"
#include <sstream>
extern FILE* yyin;
extern int yylex(void);
void yyerror(const char *msg);

extern int currLine;

char *identToken;
int numberToken;
int count_names = 0;
int temp_0 = 0;
int global_variable_counter = 0;
int flag = 0;
int paramCnt = 0;
int loopCnt = -1;
int loopBdyCnt = -1;
int iftrueCnt = 0;
int endifCnt = 0;
int elseCnt = 0;

std::string global_temp_dst = "";
std::string temp_1 = "";
std::string temp_2 = "";
std::string temp_3 = "";
std::string _temp_0 = "";
std::string _temp_1 = "";
std::string _temp_2 = "";
std::string _temp_3 = "";
std::string _temp_4 = "";
std::string Phase4_temp_1 = "";
std::string Phase4_temp_2 = "";
std::string storeCondition = "";
int Phase4_NUM = 0;


enum Type { Integer, Array };
struct Symbol {
  std::string name;
  Type type;
};
struct Function {
  std::string name;
  std::vector<Symbol> declarations;
};

std::vector <Function> symbol_table;


Function *get_function() {
  int last = symbol_table.size()-1;
  return &symbol_table[last];
}

bool find(std::string &value) {
  Function *f = get_function();
  for(int i=0; i < f->declarations.size(); i++) {
    Symbol *s = &f->declarations[i];
    if (s->name == value) {
      return true;
    }
  }
  return false;
}

void add_function_to_symbol_table(std::string &value) {
  Function f; 
  f.name = value; 
  symbol_table.push_back(f);
}

void add_variable_to_symbol_table(std::string &value, Type t) {
  Symbol s;
  s.name = value;
  s.type = t;
  Function *f = get_function();
  f->declarations.push_back(s);
}

void print_symbol_table(void) {
  printf("symbol table:\n");
  printf("--------------------\n");
  for(int i=0; i<symbol_table.size(); i++) {
    printf("function: %s\n", symbol_table[i].name.c_str());
    for(int j=0; j<symbol_table[i].declarations.size(); j++) {
      printf("  locals: %s\n", symbol_table[i].declarations[j].name.c_str());
    }
  }
  printf("--------------------\n");
}



bool isNumber(const std::string& str) {
    std::string::const_iterator it = str.begin();
    while (it != str.end() && std::isdigit(*it)) {
        ++it;
    }
    return !str.empty() && it == str.end();
}

std::string new_label() {
	std::ostringstream os;
	os << "__temp__" << global_variable_counter++;
	return os.str();
}


#line 180 "y.tab.c" /* yacc.c:339  */

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
# define YYERROR_VERBOSE 1
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
    INTEGER = 258,
    BREAK = 259,
    IFF = 260,
    FUNCTION = 261,
    BEGIN_BODY = 262,
    END_BODY = 263,
    ARRAY = 264,
    OF = 265,
    IF = 266,
    THEN = 267,
    ENDIF = 268,
    ELSE = 269,
    WHILE = 270,
    DO = 271,
    CONTINUE = 272,
    READ = 273,
    WRITE = 274,
    NOT = 275,
    TRUE = 276,
    FALSE = 277,
    RETURN = 278,
    MOD = 279,
    EQ = 280,
    NEQ = 281,
    LT = 282,
    GT = 283,
    LTE = 284,
    GTE = 285,
    SEMICOLON = 286,
    COLON = 287,
    COMMA = 288,
    L_SQUARE_BRACKET = 289,
    R_SQUARE_BRACKET = 290,
    EQUAL = 291,
    NUMBER = 292,
    PLUS = 293,
    MINUS = 294,
    MULT = 295,
    DIV = 296,
    L_PAREN = 297,
    R_PAREN = 298,
    ASSIGN = 299,
    INPUT = 300,
    OUTPUT = 301,
    IDENT = 302,
    VOID = 303
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 115 "ppc_Final.y" /* yacc.c:355  */

	char *op_val;
	int int_val;

#line 274 "y.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 291 "y.tab.c" /* yacc.c:358  */

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
#define YYFINAL  8
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   234

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  49
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  32
/* YYNRULES -- Number of rules.  */
#define YYNRULES  77
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  152

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   303

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
      45,    46,    47,    48
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   129,   129,   130,   132,   133,   135,   140,   146,   152,
     153,   155,   156,   163,   168,   173,   174,   177,   178,   179,
     181,   182,   183,   184,   185,   186,   193,   194,   195,   204,
     212,   213,   214,   215,   224,   229,   236,   237,   238,   239,
     240,   242,   243,   244,   245,   246,   252,   257,   264,   270,
     276,   277,   279,   284,   290,   291,   296,   303,   307,   315,
     317,   324,   326,   333,   338,   343,   345,   352,   359,   366,
     373,   377,   397,   407,   417,   427,   437,   447
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 1
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "INTEGER", "BREAK", "IFF", "FUNCTION",
  "BEGIN_BODY", "END_BODY", "ARRAY", "OF", "IF", "THEN", "ENDIF", "ELSE",
  "WHILE", "DO", "CONTINUE", "READ", "WRITE", "NOT", "TRUE", "FALSE",
  "RETURN", "MOD", "EQ", "NEQ", "LT", "GT", "LTE", "GTE", "SEMICOLON",
  "COLON", "COMMA", "L_SQUARE_BRACKET", "R_SQUARE_BRACKET", "EQUAL",
  "NUMBER", "PLUS", "MINUS", "MULT", "DIV", "L_PAREN", "R_PAREN", "ASSIGN",
  "INPUT", "OUTPUT", "IDENT", "VOID", "$accept", "prog_start", "functions",
  "functionstart", "functionend", "parameters", "parameter", "variable",
  "statements", "statement", "breakState", "write", "math", "arrayAccess",
  "arrayUnzip", "functionCall", "arguments", "argument", "return",
  "definition", "ifState", "ifStart", "ifElseState", "ifElseStart",
  "elseStart", "ifEnd", "whileLoop", "whileLoopStart", "whileLoopBody",
  "whileLoopEnd", "assignment", "condition", YY_NULLPTR
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
     295,   296,   297,   298,   299,   300,   301,   302,   303
};
# endif

#define YYPACT_NINF -112

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-112)))

#define YYTABLE_NINF -18

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      32,   -38,   -34,    18,  -112,   -25,  -112,  -112,  -112,    41,
     -18,  -112,    -2,     1,    12,     2,   131,  -112,   -23,    16,
      28,   170,  -112,    72,  -112,  -112,  -112,  -112,  -112,  -112,
    -112,  -112,  -112,    19,  -112,    20,  -112,   -33,  -112,     5,
     -33,   -33,  -112,   148,    34,    36,   -28,  -112,   169,    58,
      41,   -33,   -33,   -33,   -33,   -33,   -33,   -33,  -112,   -33,
     -33,   -33,   -33,    38,  -112,    78,    82,  -112,   200,    49,
    -112,   -33,  -112,  -112,    10,     5,  -112,  -112,    11,    66,
     181,    62,   118,  -112,  -112,    59,  -112,  -112,  -112,  -112,
    -112,  -112,  -112,  -112,  -112,   118,   118,   -33,   -33,   -33,
     -33,   -33,   -33,    91,    67,  -112,   -32,  -112,  -112,  -112,
      93,    64,   106,   106,  -112,  -112,  -112,  -112,  -112,  -112,
    -112,    84,  -112,  -112,    74,    85,  -112,    32,   148,  -112,
    -112,   110,   148,  -112,    89,   -32,  -112,   159,   193,  -112,
     120,   118,  -112,  -112,  -112,  -112,   118,   123,   106,  -112,
    -112,  -112
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       2,     0,     0,     0,     3,     0,     6,     7,     1,    20,
       0,    34,     0,     0,     0,     0,    17,    16,    15,     0,
       9,    31,    14,    17,    23,    30,    29,    32,    33,    28,
      27,    26,    22,     0,    21,     0,    24,     0,    25,    12,
       0,     0,    66,    20,     0,    16,    15,    56,    20,     0,
      20,     0,     0,     0,     0,     0,     0,     0,    18,     0,
       0,     0,     0,    15,    19,     0,     0,    15,     0,     0,
      57,     0,    62,    60,     0,     0,    54,    55,    15,     0,
       0,    33,    20,    10,    40,     0,    37,    36,    38,    39,
      45,    42,    41,    43,    44,    20,    20,     0,     0,     0,
       0,     0,     0,     0,     0,    35,     0,    69,    71,    70,
       0,    48,     0,     0,    76,    77,    72,    73,    74,    75,
      67,     0,    53,    52,     0,    50,     8,     4,    20,    64,
      59,     0,    17,    58,     0,     0,     5,     0,     0,    63,
       0,    20,    49,    51,    47,    46,    20,     0,     0,    68,
      65,    61
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
    -112,  -112,    13,  -112,  -112,    88,  -112,   -29,   -16,   -42,
    -112,  -112,  -112,  -112,    80,  -112,    -3,  -112,  -112,  -112,
    -112,  -112,  -112,  -112,  -112,  -111,  -112,  -112,  -112,  -112,
    -112,    17
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     3,     4,     5,   127,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,   124,   125,    30,    31,
      32,    33,    34,    35,   140,   130,    36,    37,   132,   150,
      38,    69
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      47,    74,   131,    77,    17,   122,    80,    64,    68,     6,
     -13,    68,    68,     7,    67,   123,    48,     9,     8,    79,
     -13,    48,    84,    85,    86,    87,    88,    89,    90,    39,
      91,    92,    93,    94,    57,     1,    70,   151,     2,    71,
      40,   105,   104,    41,    10,    11,    12,    43,    59,    60,
      61,    62,    13,   106,    42,    48,    14,    72,    73,    49,
      15,    50,    65,    66,    16,    82,   110,    76,   114,   115,
     116,   117,   118,   119,   -11,    44,    11,    12,    17,   112,
     113,    75,    48,    13,   -11,    95,   138,    14,    18,    96,
      51,    15,   103,   109,   111,    16,    57,   107,   120,   137,
      52,   126,   121,    58,    53,    54,    55,    56,   128,    17,
      59,    60,    61,    62,   129,   133,   141,   134,   135,    63,
     142,    44,    11,    12,   139,   147,   -17,   146,    81,    13,
     148,   149,   143,    14,    44,    11,    12,    15,    83,     0,
     136,    16,    13,     0,     0,     0,    14,     0,     0,     0,
      15,    44,    11,    12,    16,    17,     0,     0,     0,    13,
       0,     0,     0,    14,     0,    63,     0,    15,    45,     0,
       0,    16,    44,    11,    12,     0,     0,     0,    46,     0,
      13,     0,     0,    51,    14,    17,     0,     0,    15,     0,
     144,     0,    16,    52,    51,    63,     0,    53,    54,    55,
      56,     0,     0,     0,    52,    57,    17,     0,    53,    54,
      55,    56,   108,     0,     0,     0,    78,    57,     0,    59,
      60,    61,    62,     0,   145,    97,    98,    99,   100,   101,
     102,    59,    60,    61,    62
};

static const yytype_int16 yycheck[] =
{
      16,    43,   113,    31,    37,    37,    48,    23,    37,    47,
      33,    40,    41,    47,    47,    47,    44,    42,     0,    48,
      43,    44,    51,    52,    53,    54,    55,    56,    57,    47,
      59,    60,    61,    62,    24,     3,    31,   148,     6,    34,
      42,    31,    71,    42,     3,     4,     5,    45,    38,    39,
      40,    41,    11,    42,    42,    44,    15,    40,    41,    43,
      19,    33,    43,    43,    23,     7,    82,    31,    97,    98,
      99,   100,   101,   102,    33,     3,     4,     5,    37,    95,
      96,    47,    44,    11,    43,     7,   128,    15,    47,     7,
      24,    19,    43,    31,    35,    23,    24,    31,     7,   128,
      34,     8,    35,    31,    38,    39,    40,    41,    44,    37,
      38,    39,    40,    41,     8,    31,   132,    43,    33,    47,
      31,     3,     4,     5,    14,   141,     8,     7,    48,    11,
     146,     8,   135,    15,     3,     4,     5,    19,    50,    -1,
     127,    23,    11,    -1,    -1,    -1,    15,    -1,    -1,    -1,
      19,     3,     4,     5,    23,    37,    -1,    -1,    -1,    11,
      -1,    -1,    -1,    15,    -1,    47,    -1,    19,    37,    -1,
      -1,    23,     3,     4,     5,    -1,    -1,    -1,    47,    -1,
      11,    -1,    -1,    24,    15,    37,    -1,    -1,    19,    -1,
      31,    -1,    23,    34,    24,    47,    -1,    38,    39,    40,
      41,    -1,    -1,    -1,    34,    24,    37,    -1,    38,    39,
      40,    41,    31,    -1,    -1,    -1,    47,    24,    -1,    38,
      39,    40,    41,    -1,    31,    25,    26,    27,    28,    29,
      30,    38,    39,    40,    41
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,     6,    50,    51,    52,    47,    47,     0,    42,
       3,     4,     5,    11,    15,    19,    23,    37,    47,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      67,    68,    69,    70,    71,    72,    75,    76,    79,    47,
      42,    42,    42,    45,     3,    37,    47,    57,    44,    43,
      33,    24,    34,    38,    39,    40,    41,    24,    31,    38,
      39,    40,    41,    47,    57,    43,    43,    47,    56,    80,
      31,    34,    80,    80,    58,    47,    31,    31,    47,    56,
      58,    63,     7,    54,    56,    56,    56,    56,    56,    56,
      56,    56,    56,    56,    56,     7,     7,    25,    26,    27,
      28,    29,    30,    43,    56,    31,    42,    31,    31,    31,
      57,    35,    57,    57,    56,    56,    56,    56,    56,    56,
       7,    35,    37,    47,    65,    66,     8,    53,    44,     8,
      74,    74,    77,    31,    43,    33,    51,    56,    58,    14,
      73,    57,    31,    65,    31,    31,     7,    57,    57,     8,
      78,    74
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    49,    50,    50,    51,    51,    52,    52,    53,    54,
      54,    55,    55,    55,    55,    56,    56,    57,    57,    57,
      58,    58,    58,    58,    58,    58,    58,    58,    58,    58,
      58,    58,    58,    58,    59,    60,    61,    61,    61,    61,
      61,    61,    61,    61,    61,    61,    62,    62,    63,    64,
      65,    65,    66,    66,    67,    67,    67,    68,    68,    69,
      70,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      79,    79,    80,    80,    80,    80,    80,    80
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     0,     1,     7,     8,     2,     2,     1,     1,
       3,     0,     2,     1,     1,     1,     1,     0,     2,     2,
       0,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     4,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     7,     7,     4,     7,
       1,     3,     1,     1,     3,     3,     2,     3,     6,     5,
       3,     9,     3,     1,     1,     8,     2,     0,     1,     4,
       4,     4,     3,     3,     3,     3,     3,     3
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
        case 6:
#line 136 "ppc_Final.y" /* yacc.c:1646  */
    {
	std::string func = (yyvsp[0].op_val);
	printf("func %s\n", func.c_str());
}
#line 1497 "y.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 141 "ppc_Final.y" /* yacc.c:1646  */
    {
	std::string func = (yyvsp[0].op_val);
	printf("func %s\n", func.c_str());
}
#line 1506 "y.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 147 "ppc_Final.y" /* yacc.c:1646  */
    {
	paramCnt = 0;
	printf("endfunc\n");
}
#line 1515 "y.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 157 "ppc_Final.y" /* yacc.c:1646  */
    {
	std::string argIdent = (yyvsp[0].op_val);
	printf(". %s\n", argIdent.c_str());
	printf("= %s, $%i\n", argIdent.c_str(),paramCnt);
	paramCnt++;
}
#line 1526 "y.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 164 "ppc_Final.y" /* yacc.c:1646  */
    {
	std::string ident = (yyvsp[0].op_val);
	printf("param %s\n", ident.c_str());
}
#line 1535 "y.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 168 "ppc_Final.y" /* yacc.c:1646  */
    {
        printf("param %s\n", _temp_0.c_str());
}
#line 1543 "y.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 187 "ppc_Final.y" /* yacc.c:1646  */
    {
        //printf("= %s, %s\n", _temp_0.c_str(), _temp_1.c_str());
}
#line 1551 "y.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 196 "ppc_Final.y" /* yacc.c:1646  */
    {
	_temp_1 = new_label();
	_temp_3 = _temp_1;
	_temp_4 = _temp_3;
	printf(". %s\n", _temp_1.c_str());
	printf("call %s, %s \n", _temp_0.c_str(), global_temp_dst.c_str());

}
#line 1564 "y.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 205 "ppc_Final.y" /* yacc.c:1646  */
    {
	_temp_0 = new_label();
	_temp_3 = _temp_0;
	_temp_4 = _temp_3;
	printf(". %s\n", _temp_0.c_str());
	printf("%s %s, %s, %s\n", temp_3.c_str(), _temp_0.c_str(),temp_1.c_str(), temp_2.c_str());
}
#line 1576 "y.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 213 "ppc_Final.y" /* yacc.c:1646  */
    {_temp_4 = (yyvsp[0].op_val);}
#line 1582 "y.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 215 "ppc_Final.y" /* yacc.c:1646  */
    {
				//assignment try to do 
				_temp_3 = new_label();
				 _temp_4 = _temp_3;
				printf(". %s\n", _temp_3.c_str());
				printf("=[] %s,%s,%s\n", _temp_3.c_str(),temp_2.c_str(),temp_3.c_str());
				flag = 1;
				}
#line 1595 "y.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 225 "ppc_Final.y" /* yacc.c:1646  */
    {
	printf(":= endloop%i\n", loopCnt);
}
#line 1603 "y.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 230 "ppc_Final.y" /* yacc.c:1646  */
    {	
	std::string src = _temp_4;
	printf(".> %s\n", src.c_str());
}
#line 1612 "y.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 236 "ppc_Final.y" /* yacc.c:1646  */
    { temp_1 = (yyvsp[-2].op_val); temp_2 = (yyvsp[0].op_val); temp_3 = "-";}
#line 1618 "y.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 237 "ppc_Final.y" /* yacc.c:1646  */
    { temp_1 = (yyvsp[-2].op_val); temp_2 = (yyvsp[0].op_val); temp_3 = "+"; }
#line 1624 "y.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 238 "ppc_Final.y" /* yacc.c:1646  */
    { temp_1 = (yyvsp[-2].op_val); temp_2 = (yyvsp[0].op_val); temp_3 = "*"; }
#line 1630 "y.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 239 "ppc_Final.y" /* yacc.c:1646  */
    { temp_1 = (yyvsp[-2].op_val); temp_2 = (yyvsp[0].op_val); temp_3 = "/"; }
#line 1636 "y.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 240 "ppc_Final.y" /* yacc.c:1646  */
    { temp_1 = (yyvsp[-2].op_val); temp_2 = (yyvsp[0].op_val); temp_3 = "%"; }
#line 1642 "y.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 242 "ppc_Final.y" /* yacc.c:1646  */
    { temp_1 = _temp_3; temp_2 = (yyvsp[0].op_val); temp_3 = "-";}
#line 1648 "y.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 243 "ppc_Final.y" /* yacc.c:1646  */
    { temp_1 = _temp_3; temp_2 = (yyvsp[0].op_val); temp_3 = "+"; }
#line 1654 "y.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 244 "ppc_Final.y" /* yacc.c:1646  */
    { temp_1 = _temp_3; temp_2 = (yyvsp[0].op_val); temp_3 = "*"; }
#line 1660 "y.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 245 "ppc_Final.y" /* yacc.c:1646  */
    { temp_1 = _temp_3; temp_2 = (yyvsp[0].op_val); temp_3 = "/"; }
#line 1666 "y.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 246 "ppc_Final.y" /* yacc.c:1646  */
    { temp_1 = _temp_3; temp_2 = (yyvsp[0].op_val); temp_3 = "%"; }
#line 1672 "y.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 252 "ppc_Final.y" /* yacc.c:1646  */
    {
                std::string dst = (yyvsp[-6].op_val);
                std::string index = (yyvsp[-4].op_val);
                printf("[]= %s,%s,%s\n", dst.c_str(),index.c_str(),_temp_3.c_str());
                }
#line 1682 "y.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 257 "ppc_Final.y" /* yacc.c:1646  */
    {
                std::string dst = (yyvsp[-6].op_val);
                std::string index = (yyvsp[-4].op_val);
                std::string number = (yyvsp[-1].op_val);
                printf("[]= %s,%s,%s\n", dst.c_str(),index.c_str(),number.c_str());
                }
#line 1693 "y.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 264 "ppc_Final.y" /* yacc.c:1646  */
    {
				temp_2 =(yyvsp[-3].op_val);
				temp_3 =(yyvsp[-1].op_val);
			
				}
#line 1703 "y.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 271 "ppc_Final.y" /* yacc.c:1646  */
    {
	global_temp_dst = (yyvsp[-6].op_val);
	_temp_0 = (yyvsp[-4].op_val);
}
#line 1712 "y.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 280 "ppc_Final.y" /* yacc.c:1646  */
    {
	std::string param = (yyvsp[0].op_val);
	printf("param %s\n", param.c_str());
}
#line 1721 "y.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 285 "ppc_Final.y" /* yacc.c:1646  */
    {
	int param = (yyvsp[0].int_val);
	printf("param %i\n", param);
}
#line 1730 "y.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 292 "ppc_Final.y" /* yacc.c:1646  */
    {
	std::string src = (yyvsp[-1].op_val);
	printf("ret %s\n", src.c_str());
}
#line 1739 "y.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 297 "ppc_Final.y" /* yacc.c:1646  */
    {
	printf("ret %s\n", _temp_0.c_str());

}
#line 1748 "y.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 304 "ppc_Final.y" /* yacc.c:1646  */
    {
	std::string name = (yyvsp[-1].op_val);
	printf(". %s\n", name.c_str());
}
#line 1757 "y.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 308 "ppc_Final.y" /* yacc.c:1646  */
    {
    std::string ident = (yyvsp[-4].op_val);
    std::string size = (yyvsp[-2].op_val);

    printf(".[] %s, %s\n", ident.c_str(), size.c_str());
}
#line 1768 "y.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 318 "ppc_Final.y" /* yacc.c:1646  */
    {
	printf("?:= if_true%i, %s\n", iftrueCnt, storeCondition.c_str());
	printf(":= endif%i\n", endifCnt);
	printf(": if_true%i\n", iftrueCnt);
}
#line 1778 "y.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 327 "ppc_Final.y" /* yacc.c:1646  */
    {
	printf("?:= if_true%i, %s\n", iftrueCnt, storeCondition.c_str());
	printf(":= else%i\n", elseCnt);
	printf(": if_true%i\n", iftrueCnt);
}
#line 1788 "y.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 334 "ppc_Final.y" /* yacc.c:1646  */
    {
	printf(": else%i\n",elseCnt);
}
#line 1796 "y.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 339 "ppc_Final.y" /* yacc.c:1646  */
    {
	printf(": endif%i\n", endifCnt);
}
#line 1804 "y.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 346 "ppc_Final.y" /* yacc.c:1646  */
    {
	loopCnt++;
	printf(": beginloop%i\n", loopCnt);
}
#line 1813 "y.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 352 "ppc_Final.y" /* yacc.c:1646  */
    {
	loopBdyCnt++;
	printf("?:= loopbody%i, %s\n", loopBdyCnt, storeCondition.c_str());
	printf(":= endloop%i\n", loopCnt);
	printf(": loopbody%i\n", loopBdyCnt);
}
#line 1824 "y.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 360 "ppc_Final.y" /* yacc.c:1646  */
    {
	printf(":= beginloop%i\n", loopCnt);
	printf(": endloop%i\n", loopCnt);
	loopCnt--;
}
#line 1834 "y.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 367 "ppc_Final.y" /* yacc.c:1646  */
    {
	std::string dest = (yyvsp[-3].op_val);
	std::string src = (yyvsp[-1].op_val);
	printf("= %s, %s\n", dest.c_str(), src.c_str());

}
#line 1845 "y.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 373 "ppc_Final.y" /* yacc.c:1646  */
    {
  std::string temp_dst = (yyvsp[-3].op_val);
  printf("=[] %s,%s,%s\n",temp_dst.c_str(),temp_2.c_str(),temp_3.c_str());
}
#line 1854 "y.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 377 "ppc_Final.y" /* yacc.c:1646  */
    {
  std::string temp_dst = (yyvsp[-3].op_val);
  printf("%s %s,%s,%s\n", temp_3.c_str(),temp_dst.c_str(),temp_1.c_str(),temp_2.c_str());
}
#line 1863 "y.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 398 "ppc_Final.y" /* yacc.c:1646  */
    {
	Phase4_temp_1 = new_label();
	storeCondition = Phase4_temp_1;
	std::string salsa = Phase4_temp_1;
    std::string burrito = (yyvsp[-2].op_val);
    std::string taco = (yyvsp[0].op_val);
	printf(". %s\n", salsa.c_str());
	printf("< %s, %s, %s\n", salsa.c_str(), burrito.c_str(), taco.c_str());
}
#line 1877 "y.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 408 "ppc_Final.y" /* yacc.c:1646  */
    {
	Phase4_temp_1 = new_label();
	storeCondition = Phase4_temp_1;
	std::string salsa = Phase4_temp_1;
    std::string burrito = (yyvsp[-2].op_val);
    std::string taco = (yyvsp[0].op_val);
	printf(". %s\n", salsa.c_str());
	printf("> %s, %s, %s\n", salsa.c_str(), burrito.c_str(), taco.c_str());
}
#line 1891 "y.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 418 "ppc_Final.y" /* yacc.c:1646  */
    {
	Phase4_temp_1 = new_label();
	storeCondition = Phase4_temp_1;
	std::string salsa = Phase4_temp_1;
    std::string burrito = (yyvsp[-2].op_val);
    std::string taco = (yyvsp[0].op_val);
	printf(". %s\n", salsa.c_str());
	printf("<= %s, %s, %s\n", salsa.c_str(), burrito.c_str(), taco.c_str());
}
#line 1905 "y.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 428 "ppc_Final.y" /* yacc.c:1646  */
    {
	Phase4_temp_1 = new_label();
	storeCondition = Phase4_temp_1;
	std::string salsa = Phase4_temp_1;
    std::string burrito = (yyvsp[-2].op_val);
    std::string taco = (yyvsp[0].op_val);
	printf(". %s\n", salsa.c_str());
	printf(">= %s, %s, %s\n", salsa.c_str(), burrito.c_str(), taco.c_str());
}
#line 1919 "y.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 438 "ppc_Final.y" /* yacc.c:1646  */
    {
	Phase4_temp_1 = new_label();
	storeCondition = Phase4_temp_1;
	std::string salsa = Phase4_temp_1;
    std::string burrito = (yyvsp[-2].op_val);
    std::string taco = (yyvsp[0].op_val);
	printf(". %s\n", salsa.c_str());
	printf("== %s, %s, %s\n", salsa.c_str(), burrito.c_str(), taco.c_str());
}
#line 1933 "y.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 448 "ppc_Final.y" /* yacc.c:1646  */
    {
	Phase4_temp_1 = new_label();
	storeCondition = Phase4_temp_1;
	std::string salsa = Phase4_temp_1;
    std::string burrito = (yyvsp[-2].op_val);
    std::string taco = (yyvsp[0].op_val);
	printf(". %s\n", salsa.c_str());
	printf("!= %s, %s, %s\n", salsa.c_str(), burrito.c_str(), taco.c_str());
}
#line 1947 "y.tab.c" /* yacc.c:1646  */
    break;


#line 1951 "y.tab.c" /* yacc.c:1646  */
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
#line 458 "ppc_Final.y" /* yacc.c:1906  */


int main(int argc, char** argv) {
    if (argc >= 2) {
	yyin = fopen(argv[1], "r");
	if (yyin == NULL) 
		yyin = stdin;
    }  else {
	yyin = stdin;
    }

    yyparse();
	return 0;
}
void yyerror(const char *error_message){
  printf("%s\n", error_message);

}
