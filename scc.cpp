/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C

   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 51 Franklin Street, Fifth Floor,
   Boston, MA 02110-1301, USA.  */

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
#define YYBISON_VERSION "2.3"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     STRUCT = 258,
     RETURN = 259,
     IF = 260,
     ELSE = 261,
     BREAK = 262,
     CONTINUE = 263,
     FOR = 264,
     TYPE = 265,
     SEMI = 266,
     COMMA = 267,
     LP = 268,
     RP = 269,
     LB = 270,
     RB = 271,
     LC = 272,
     RC = 273,
     OCTAL = 274,
     HEXADECIMAL = 275,
     DECIMAL = 276,
     ID = 277,
     ASSIGNSHIFTR = 278,
     ASSIGNSHIFTL = 279,
     ASSIGNORBIT = 280,
     ASSIGNXORBIT = 281,
     ASSIGNANDBIT = 282,
     ASSIGNDIV = 283,
     ASSIGNMINUS = 284,
     ASSIGNMULT = 285,
     ASSIGNPLUS = 286,
     ASSIGN = 287,
     OR = 288,
     AND = 289,
     BITOR = 290,
     BITXOR = 291,
     BITAND = 292,
     EQ = 293,
     NE = 294,
     GT = 295,
     GE = 296,
     LT = 297,
     LE = 298,
     SHIFTLEFT = 299,
     SHIFTRIGHT = 300,
     PLUS = 301,
     MINUS = 302,
     MULT = 303,
     DIV = 304,
     MOD = 305,
     UNARYNOT = 306,
     UNARYINCR = 307,
     UNARYDECR = 308,
     UNARYBITNOT = 309,
     UMINUS = 310,
     DOT = 311
   };
#endif
/* Tokens.  */
#define STRUCT 258
#define RETURN 259
#define IF 260
#define ELSE 261
#define BREAK 262
#define CONTINUE 263
#define FOR 264
#define TYPE 265
#define SEMI 266
#define COMMA 267
#define LP 268
#define RP 269
#define LB 270
#define RB 271
#define LC 272
#define RC 273
#define OCTAL 274
#define HEXADECIMAL 275
#define DECIMAL 276
#define ID 277
#define ASSIGNSHIFTR 278
#define ASSIGNSHIFTL 279
#define ASSIGNORBIT 280
#define ASSIGNXORBIT 281
#define ASSIGNANDBIT 282
#define ASSIGNDIV 283
#define ASSIGNMINUS 284
#define ASSIGNMULT 285
#define ASSIGNPLUS 286
#define ASSIGN 287
#define OR 288
#define AND 289
#define BITOR 290
#define BITXOR 291
#define BITAND 292
#define EQ 293
#define NE 294
#define GT 295
#define GE 296
#define LT 297
#define LE 298
#define SHIFTLEFT 299
#define SHIFTRIGHT 300
#define PLUS 301
#define MINUS 302
#define MULT 303
#define DIV 304
#define MOD 305
#define UNARYNOT 306
#define UNARYINCR 307
#define UNARYDECR 308
#define UNARYBITNOT 309
#define UMINUS 310
#define DOT 311




/* Copy the first part of user declarations.  */
#line 5 "scc.y"

    #include <stdio.h>
	#include <stdlib.h>
	#include "treenode.h"
	#include "semantictree.h"
	#include "llvmbuild.h"
	
	// Lexer prototype required by bison
	extern int yylex();
	void yyerror(const char *s) { std::printf("Error: %s\n", s);std::exit(1); }
	// Root node
	struct NodeT * node = NULL;
	
	

/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif

#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 21 "scc.y"
{
	char * valeur;
	char * name;
	struct NodeT * node;
}
/* Line 193 of yacc.c.  */
#line 229 "scc.cpp"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */
#line 242 "scc.cpp"

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
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
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
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
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
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int i)
#else
static int
YYID (i)
    int i;
#endif
{
  return i;
}
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
#    if ! defined _ALLOCA_H && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef _STDLIB_H
#      define _STDLIB_H 1
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
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
#  if (defined __cplusplus && ! defined _STDLIB_H \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef _STDLIB_H
#    define _STDLIB_H 1
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
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
  yytype_int16 yyss;
  YYSTYPE yyvs;
  };

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack)					\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack, Stack, yysize);				\
	Stack = &yyptr->Stack;						\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  10
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   677

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  57
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  24
/* YYNRULES -- Number of rules.  */
#define YYNRULES  90
/* YYNRULES -- Number of states.  */
#define YYNSTATES  173

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   311

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
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
      55,    56
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     5,     8,     9,    13,    17,    19,    23,
      24,    26,    28,    34,    37,    39,    40,    42,    47,    52,
      57,    62,    66,    68,    69,    72,    77,    80,    81,    84,
      86,    90,    97,   107,   110,   113,   116,   117,   120,   121,
     125,   129,   131,   133,   137,   139,   143,   147,   151,   155,
     159,   163,   167,   171,   175,   179,   183,   187,   191,   195,
     199,   203,   207,   211,   215,   219,   223,   227,   231,   235,
     239,   243,   247,   251,   255,   258,   261,   264,   267,   270,
     274,   279,   282,   286,   288,   290,   292,   293,   298,   299,
     303
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      58,     0,    -1,    59,    -1,    60,    59,    -1,    -1,    62,
      61,    11,    -1,    62,    66,    69,    -1,    76,    -1,    76,
      12,    61,    -1,    -1,    10,    -1,    63,    -1,     3,    64,
      17,    73,    18,    -1,     3,    22,    -1,    22,    -1,    -1,
      22,    -1,    65,    15,    19,    16,    -1,    65,    15,    20,
      16,    -1,    65,    15,    21,    16,    -1,    22,    13,    67,
      14,    -1,    68,    12,    67,    -1,    68,    -1,    -1,    62,
      65,    -1,    17,    73,    70,    18,    -1,    71,    70,    -1,
      -1,    78,    11,    -1,    69,    -1,     4,    78,    11,    -1,
       5,    13,    78,    14,    71,    72,    -1,     9,    13,    78,
      11,    78,    11,    78,    14,    71,    -1,     8,    11,    -1,
       7,    11,    -1,     6,    71,    -1,    -1,    74,    73,    -1,
      -1,    62,    75,    11,    -1,    76,    12,    75,    -1,    76,
      -1,    65,    -1,    65,    32,    77,    -1,    78,    -1,    17,
      80,    18,    -1,    78,    48,    78,    -1,    78,    49,    78,
      -1,    78,    50,    78,    -1,    78,    46,    78,    -1,    78,
      47,    78,    -1,    78,    40,    78,    -1,    78,    41,    78,
      -1,    78,    42,    78,    -1,    78,    43,    78,    -1,    78,
      38,    78,    -1,    78,    39,    78,    -1,    78,    44,    78,
      -1,    78,    45,    78,    -1,    78,    37,    78,    -1,    78,
      36,    78,    -1,    78,    35,    78,    -1,    78,    34,    78,
      -1,    78,    33,    78,    -1,    78,    32,    78,    -1,    78,
      23,    78,    -1,    78,    24,    78,    -1,    78,    25,    78,
      -1,    78,    26,    78,    -1,    78,    27,    78,    -1,    78,
      28,    78,    -1,    78,    29,    78,    -1,    78,    30,    78,
      -1,    78,    31,    78,    -1,    47,    78,    -1,    51,    78,
      -1,    52,    78,    -1,    53,    78,    -1,    54,    78,    -1,
      13,    78,    14,    -1,    22,    13,    80,    14,    -1,    22,
      79,    -1,    78,    56,    22,    -1,    19,    -1,    20,    -1,
      21,    -1,    -1,    15,    78,    16,    79,    -1,    -1,    78,
      12,    80,    -1,    78,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    57,    57,    61,    62,    66,    67,    71,    72,    73,
      77,    78,    82,    83,    87,    88,    92,    93,    94,    95,
      99,   103,   104,   105,   109,   113,   117,   118,   122,   123,
     124,   125,   126,   128,   129,   133,   134,   138,   139,   143,
     147,   148,   152,   153,   157,   158,   162,   163,   164,   165,
     166,   167,   168,   169,   170,   171,   172,   173,   174,   175,
     176,   177,   178,   179,   180,   182,   183,   184,   185,   186,
     187,   188,   189,   190,   192,   193,   194,   195,   196,   197,
     198,   199,   200,   201,   202,   203,   204,   208,   209,   213,
     214
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "STRUCT", "RETURN", "IF", "ELSE",
  "BREAK", "CONTINUE", "FOR", "TYPE", "SEMI", "COMMA", "LP", "RP", "LB",
  "RB", "LC", "RC", "OCTAL", "HEXADECIMAL", "DECIMAL", "ID",
  "ASSIGNSHIFTR", "ASSIGNSHIFTL", "ASSIGNORBIT", "ASSIGNXORBIT",
  "ASSIGNANDBIT", "ASSIGNDIV", "ASSIGNMINUS", "ASSIGNMULT", "ASSIGNPLUS",
  "ASSIGN", "OR", "AND", "BITOR", "BITXOR", "BITAND", "EQ", "NE", "GT",
  "GE", "LT", "LE", "SHIFTLEFT", "SHIFTRIGHT", "PLUS", "MINUS", "MULT",
  "DIV", "MOD", "UNARYNOT", "UNARYINCR", "UNARYDECR", "UNARYBITNOT",
  "UMINUS", "DOT", "$accept", "program", "extdefs", "extdef", "extvars",
  "spec", "stspec", "opttag", "var", "func", "paras", "para", "stmtblock",
  "stmts", "stmt", "estmt", "defs", "def", "decs", "dec", "init", "exp",
  "arrs", "args", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    57,    58,    59,    59,    60,    60,    61,    61,    61,
      62,    62,    63,    63,    64,    64,    65,    65,    65,    65,
      66,    67,    67,    67,    68,    69,    70,    70,    71,    71,
      71,    71,    71,    71,    71,    72,    72,    73,    73,    74,
      75,    75,    76,    76,    77,    77,    78,    78,    78,    78,
      78,    78,    78,    78,    78,    78,    78,    78,    78,    78,
      78,    78,    78,    78,    78,    78,    78,    78,    78,    78,
      78,    78,    78,    78,    78,    78,    78,    78,    78,    78,
      78,    78,    78,    78,    78,    78,    78,    79,    79,    80,
      80
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     0,     3,     3,     1,     3,     0,
       1,     1,     5,     2,     1,     0,     1,     4,     4,     4,
       4,     3,     1,     0,     2,     4,     2,     0,     2,     1,
       3,     6,     9,     2,     2,     2,     0,     2,     0,     3,
       3,     1,     1,     3,     1,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     2,     2,     2,     2,     2,     3,
       4,     2,     3,     1,     1,     1,     0,     4,     0,     3,
       1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       4,    15,    10,     0,     2,     4,     9,    11,    13,     0,
       1,     3,    16,     0,    42,     0,     7,    38,    23,     5,
       0,    86,    38,     6,     9,     0,     0,    38,     0,     0,
      22,     0,     0,     0,    86,    86,    83,    84,    85,    88,
      86,    86,    86,    86,    86,    43,    44,    86,    16,     8,
       0,    41,    12,    37,    24,    20,    23,    17,    18,    19,
       0,    90,     0,    86,    86,    81,    74,    75,    76,    77,
      78,    86,    86,    86,    86,    86,    86,    86,    86,    86,
      86,    86,    86,    86,    86,    86,    86,    86,    86,    86,
      86,    86,    86,    86,    86,    86,    86,    86,    86,     0,
      86,     0,     0,     0,     0,    29,     0,    86,     0,    39,
       0,    21,    79,    86,    45,     0,     0,    65,    66,    67,
      68,    69,    70,    71,    72,    73,    64,    63,    62,    61,
      60,    59,    55,    56,    51,    52,    53,    54,    57,    58,
      49,    50,    46,    47,    48,    82,     0,    86,    34,    33,
      86,    25,    26,    28,    40,    89,    80,    88,    30,     0,
       0,    87,    86,    86,    36,     0,    86,    31,    86,    35,
       0,    86,    32
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     3,     4,     5,    13,    25,     7,     9,    14,    15,
      29,    30,   105,   106,   107,   167,    26,    27,    50,    16,
      45,   108,    65,    62
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -58
static const yytype_int16 yypact[] =
{
       8,     5,   -58,    29,   -58,     8,    10,   -58,    23,    24,
     -58,   -58,    36,    69,    -8,    64,    71,     8,     8,   -58,
      27,   440,     8,   -58,    68,    68,    73,     8,    68,    81,
      82,    94,    95,    97,   450,   450,   -58,   -58,   -58,     2,
     450,   450,   450,   450,   450,   -58,   516,    80,   -58,   -58,
      85,   103,   -58,   -58,   102,   -58,     8,   -58,   -58,   -58,
     328,   291,   104,   450,   450,   -58,    67,    67,    67,    67,
      67,   450,   450,   450,   450,   450,   450,   450,   450,   450,
     450,   450,   450,   450,   450,   450,   450,   450,   450,   450,
     450,   450,   450,   450,   450,   450,   450,   450,   450,   106,
     450,   111,   114,   119,   122,   -58,   118,    80,   132,   -58,
      68,   -58,   -58,   450,   -58,   123,   482,   516,   516,   516,
     516,   516,   516,   516,   516,   516,   516,   539,   561,   582,
     602,   621,   433,   433,   -11,   -11,   -11,   -11,   -44,   -44,
     -40,   -40,    67,    67,    67,   -58,   172,   450,   -58,   -58,
     450,   -58,   -58,   -58,   -58,   -58,   -58,   124,   -58,   365,
     212,   -58,    99,   450,   134,   252,    99,   -58,   450,   -58,
     402,    99,   -58
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -58,   -58,   133,   -58,   117,    26,   -58,   -58,   116,   -58,
      89,   -58,   139,    41,   -57,   -58,     3,   -58,    39,   -24,
     -58,   -21,    28,   -35
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -28
static const yytype_int16 yytable[] =
{
      46,    51,    94,    95,    96,    97,    98,    20,    96,    97,
      98,     1,    99,    60,    61,    63,    99,    64,     2,    66,
      67,    68,    69,    70,    21,    47,     6,     8,   115,    10,
      53,     6,    12,    92,    93,    94,    95,    96,    97,    98,
     -14,    17,    61,   116,    28,    99,    31,    32,    33,    18,
     117,   118,   119,   120,   121,   122,   123,   124,   125,   126,
     127,   128,   129,   130,   131,   132,   133,   134,   135,   136,
     137,   138,   139,   140,   141,   142,   143,   144,   155,   146,
      19,    22,    28,    24,   100,   101,    51,   102,   103,   104,
      48,    52,    61,    34,    56,    55,   109,    22,   -27,    36,
      37,    38,    39,   100,   101,   164,   102,   103,   104,   169,
      57,    58,    34,    59,   172,   110,    22,    20,    36,    37,
      38,    39,   114,    99,   147,   148,   159,    40,   145,   160,
     149,    41,    42,    43,    44,   150,   151,   156,    11,    64,
     166,    49,   165,   153,    54,   111,    40,   170,   152,   154,
      41,    42,    43,    44,    23,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    90,    91,    92,    93,    94,    95,
      96,    97,    98,   158,     0,   161,     0,     0,    99,     0,
       0,     0,     0,     0,     0,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    90,    91,    92,    93,    94,    95,
      96,    97,    98,   163,     0,     0,     0,     0,    99,     0,
       0,     0,     0,     0,     0,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    90,    91,    92,    93,    94,    95,
      96,    97,    98,   168,     0,     0,     0,     0,    99,     0,
       0,     0,     0,     0,     0,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    90,    91,    92,    93,    94,    95,
      96,    97,    98,   113,     0,     0,     0,     0,    99,     0,
       0,     0,     0,     0,    71,    72,    73,    74,    75,    76,
      77,    78,    79,    80,    81,    82,    83,    84,    85,    86,
      87,    88,    89,    90,    91,    92,    93,    94,    95,    96,
      97,    98,   112,     0,     0,     0,     0,    99,     0,     0,
       0,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    91,    92,    93,    94,    95,    96,    97,    98,   162,
       0,     0,     0,     0,    99,     0,     0,     0,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    88,    89,    90,    91,    92,
      93,    94,    95,    96,    97,    98,   171,     0,     0,     0,
       0,    99,     0,     0,     0,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    90,    91,    92,    93,    94,    95,
      96,    97,    98,    34,     0,     0,     0,    35,    99,    36,
      37,    38,    39,    34,     0,     0,     0,     0,     0,    36,
      37,    38,    39,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    97,    98,     0,     0,     0,    40,     0,    99,
       0,    41,    42,    43,    44,     0,     0,    40,   157,     0,
       0,    41,    42,    43,    44,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    90,    91,    92,    93,    94,    95,
      96,    97,    98,     0,     0,     0,     0,     0,    99,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    89,    90,    91,
      92,    93,    94,    95,    96,    97,    98,     0,     0,     0,
       0,     0,    99,    82,    83,    84,    85,    86,    87,    88,
      89,    90,    91,    92,    93,    94,    95,    96,    97,    98,
       0,     0,     0,     0,     0,    99,    83,    84,    85,    86,
      87,    88,    89,    90,    91,    92,    93,    94,    95,    96,
      97,    98,     0,     0,     0,     0,     0,    99,    84,    85,
      86,    87,    88,    89,    90,    91,    92,    93,    94,    95,
      96,    97,    98,     0,     0,     0,     0,     0,    99,    85,
      86,    87,    88,    89,    90,    91,    92,    93,    94,    95,
      96,    97,    98,     0,     0,     0,     0,     0,    99,    86,
      87,    88,    89,    90,    91,    92,    93,    94,    95,    96,
      97,    98,     0,     0,     0,     0,     0,    99
};

static const yytype_int16 yycheck[] =
{
      21,    25,    46,    47,    48,    49,    50,    15,    48,    49,
      50,     3,    56,    34,    35,    13,    56,    15,    10,    40,
      41,    42,    43,    44,    32,    22,     0,    22,    63,     0,
      27,     5,    22,    44,    45,    46,    47,    48,    49,    50,
      17,    17,    63,    64,    18,    56,    19,    20,    21,    13,
      71,    72,    73,    74,    75,    76,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    89,    90,
      91,    92,    93,    94,    95,    96,    97,    98,   113,   100,
      11,    17,    56,    12,     4,     5,   110,     7,     8,     9,
      22,    18,   113,    13,    12,    14,    11,    17,    18,    19,
      20,    21,    22,     4,     5,   162,     7,     8,     9,   166,
      16,    16,    13,    16,   171,    12,    17,    15,    19,    20,
      21,    22,    18,    56,    13,    11,   147,    47,    22,   150,
      11,    51,    52,    53,    54,    13,    18,    14,     5,    15,
       6,    24,   163,    11,    28,    56,    47,   168,   107,   110,
      51,    52,    53,    54,    15,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    11,    -1,   157,    -1,    -1,    56,    -1,
      -1,    -1,    -1,    -1,    -1,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    11,    -1,    -1,    -1,    -1,    56,    -1,
      -1,    -1,    -1,    -1,    -1,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    11,    -1,    -1,    -1,    -1,    56,    -1,
      -1,    -1,    -1,    -1,    -1,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    12,    -1,    -1,    -1,    -1,    56,    -1,
      -1,    -1,    -1,    -1,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    14,    -1,    -1,    -1,    -1,    56,    -1,    -1,
      -1,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    14,
      -1,    -1,    -1,    -1,    56,    -1,    -1,    -1,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    14,    -1,    -1,    -1,
      -1,    56,    -1,    -1,    -1,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    13,    -1,    -1,    -1,    17,    56,    19,
      20,    21,    22,    13,    -1,    -1,    -1,    -1,    -1,    19,
      20,    21,    22,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    -1,    -1,    -1,    47,    -1,    56,
      -1,    51,    52,    53,    54,    -1,    -1,    47,    16,    -1,
      -1,    51,    52,    53,    54,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    -1,    -1,    -1,    -1,    -1,    56,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    -1,    -1,    -1,
      -1,    -1,    56,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      -1,    -1,    -1,    -1,    -1,    56,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    -1,    -1,    -1,    -1,    -1,    56,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    -1,    -1,    -1,    -1,    -1,    56,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    -1,    -1,    -1,    -1,    -1,    56,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    -1,    -1,    -1,    -1,    -1,    56
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,    10,    58,    59,    60,    62,    63,    22,    64,
       0,    59,    22,    61,    65,    66,    76,    17,    13,    11,
      15,    32,    17,    69,    12,    62,    73,    74,    62,    67,
      68,    19,    20,    21,    13,    17,    19,    20,    21,    22,
      47,    51,    52,    53,    54,    77,    78,    73,    22,    61,
      75,    76,    18,    73,    65,    14,    12,    16,    16,    16,
      78,    78,    80,    13,    15,    79,    78,    78,    78,    78,
      78,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    56,
       4,     5,     7,     8,     9,    69,    70,    71,    78,    11,
      12,    67,    14,    12,    18,    80,    78,    78,    78,    78,
      78,    78,    78,    78,    78,    78,    78,    78,    78,    78,
      78,    78,    78,    78,    78,    78,    78,    78,    78,    78,
      78,    78,    78,    78,    78,    22,    78,    13,    11,    11,
      13,    18,    70,    11,    75,    80,    14,    16,    11,    78,
      78,    79,    14,    11,    71,    78,     6,    72,    11,    71,
      78,    14,    71
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */

#define YYFAIL		goto yyerrlab

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
	      (Loc).first_line, (Loc).first_column,	\
	      (Loc).last_line,  (Loc).last_column)
# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
	break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *bottom, yytype_int16 *top)
#else
static void
yy_stack_print (bottom, top)
    yytype_int16 *bottom;
    yytype_int16 *top;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; bottom <= top; ++bottom)
    YYFPRINTF (stderr, " %d", *bottom);
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      fprintf (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      fprintf (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

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
#ifndef	YYINITDEPTH
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
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
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
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
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

/* Copy into YYRESULT an error message about the unexpected token
   YYCHAR while in state YYSTATE.  Return the number of bytes copied,
   including the terminating null byte.  If YYRESULT is null, do not
   copy anything; just return the number of bytes that would be
   copied.  As a special case, return 0 if an ordinary "syntax error"
   message will do.  Return YYSIZE_MAXIMUM if overflow occurs during
   size calculation.  */
static YYSIZE_T
yysyntax_error (char *yyresult, int yystate, int yychar)
{
  int yyn = yypact[yystate];

  if (! (YYPACT_NINF < yyn && yyn <= YYLAST))
    return 0;
  else
    {
      int yytype = YYTRANSLATE (yychar);
      YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
      YYSIZE_T yysize = yysize0;
      YYSIZE_T yysize1;
      int yysize_overflow = 0;
      enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
      char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
      int yyx;

# if 0
      /* This is so xgettext sees the translatable formats that are
	 constructed on the fly.  */
      YY_("syntax error, unexpected %s");
      YY_("syntax error, unexpected %s, expecting %s");
      YY_("syntax error, unexpected %s, expecting %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
# endif
      char *yyfmt;
      char const *yyf;
      static char const yyunexpected[] = "syntax error, unexpected %s";
      static char const yyexpecting[] = ", expecting %s";
      static char const yyor[] = " or %s";
      char yyformat[sizeof yyunexpected
		    + sizeof yyexpecting - 1
		    + ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
		       * (sizeof yyor - 1))];
      char const *yyprefix = yyexpecting;

      /* Start YYX at -YYN if negative to avoid negative indexes in
	 YYCHECK.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;

      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yycount = 1;

      yyarg[0] = yytname[yytype];
      yyfmt = yystpcpy (yyformat, yyunexpected);

      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	  {
	    if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
	      {
		yycount = 1;
		yysize = yysize0;
		yyformat[sizeof yyunexpected - 1] = '\0';
		break;
	      }
	    yyarg[yycount++] = yytname[yyx];
	    yysize1 = yysize + yytnamerr (0, yytname[yyx]);
	    yysize_overflow |= (yysize1 < yysize);
	    yysize = yysize1;
	    yyfmt = yystpcpy (yyfmt, yyprefix);
	    yyprefix = yyor;
	  }

      yyf = YY_(yyformat);
      yysize1 = yysize + yystrlen (yyf);
      yysize_overflow |= (yysize1 < yysize);
      yysize = yysize1;

      if (yysize_overflow)
	return YYSIZE_MAXIMUM;

      if (yyresult)
	{
	  /* Avoid sprintf, as that infringes on the user's name space.
	     Don't have undefined behavior even if the translation
	     produced a string with the wrong number of "%s"s.  */
	  char *yyp = yyresult;
	  int yyi = 0;
	  while ((*yyp = *yyf) != '\0')
	    {
	      if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
		{
		  yyp += yytnamerr (yyp, yyarg[yyi++]);
		  yyf += 2;
		}
	      else
		{
		  yyp++;
		  yyf++;
		}
	    }
	}
      return yysize;
    }
}
#endif /* YYERROR_VERBOSE */


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
	break;
    }
}


/* Prevent warnings from -Wmissing-prototypes.  */

#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */



/* The look-ahead symbol.  */
int yychar;

/* The semantic value of the look-ahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



/*----------.
| yyparse.  |
`----------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{
  
  int yystate;
  int yyn;
  int yyresult;
  /* Number of tokens to shift before error messages enabled.  */
  int yyerrstatus;
  /* Look-ahead token as an internal (translated) token number.  */
  int yytoken = 0;
#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

  /* Three stacks and their tools:
     `yyss': related to states,
     `yyvs': related to semantic values,
     `yyls': related to locations.

     Refer to the stacks thru separate pointers, to allow yyoverflow
     to reallocate them elsewhere.  */

  /* The state stack.  */
  yytype_int16 yyssa[YYINITDEPTH];
  yytype_int16 *yyss = yyssa;
  yytype_int16 *yyssp;

  /* The semantic value stack.  */
  YYSTYPE yyvsa[YYINITDEPTH];
  YYSTYPE *yyvs = yyvsa;
  YYSTYPE *yyvsp;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  YYSIZE_T yystacksize = YYINITDEPTH;

  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;


  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY;		/* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */

  yyssp = yyss;
  yyvsp = yyvs;

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
	YYSTACK_RELOCATE (yyss);
	YYSTACK_RELOCATE (yyvs);

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

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     look-ahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to look-ahead token.  */
  yyn = yypact[yystate];
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a look-ahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid look-ahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
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
      if (yyn == 0 || yyn == YYTABLE_NINF)
	goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the look-ahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token unless it is eof.  */
  if (yychar != YYEOF)
    yychar = YYEMPTY;

  yystate = yyn;
  *++yyvsp = yylval;

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
     `$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:
#line 57 "scc.y"
    {node = Treenode::CreateNode(_PROGRAM, NULL); Treenode::AddNode(node, (yyvsp[(1) - (1)].node));;}
    break;

  case 3:
#line 61 "scc.y"
    {(yyval.node) = Treenode::CreateNode(_EXTDEFS, NULL); Treenode::AddNode((yyval.node), (yyvsp[(1) - (2)].node)); Treenode::AddNode((yyval.node), (yyvsp[(2) - (2)].node));;}
    break;

  case 4:
#line 62 "scc.y"
    {(yyval.node) = Treenode::CreateNode(_EXTDEFS, NULL);;}
    break;

  case 5:
#line 66 "scc.y"
    {(yyval.node) = Treenode::CreateNode(_EXTDEF, NULL); Treenode::AddNode((yyval.node), (yyvsp[(1) - (3)].node)); Treenode::AddNode((yyval.node), (yyvsp[(2) - (3)].node)); Treenode::AddNode((yyval.node), Treenode::CreateNode(_SEMI, NULL));;}
    break;

  case 6:
#line 67 "scc.y"
    {(yyval.node) = Treenode::CreateNode(_EXTDEF, NULL); Treenode::AddNode((yyval.node), (yyvsp[(1) - (3)].node)); Treenode::AddNode((yyval.node), (yyvsp[(2) - (3)].node)); Treenode::AddNode((yyval.node), (yyvsp[(3) - (3)].node));;}
    break;

  case 7:
#line 71 "scc.y"
    {(yyval.node) = Treenode::CreateNode(_EXTVARS, NULL); Treenode::AddNode((yyval.node), (yyvsp[(1) - (1)].node));;}
    break;

  case 8:
#line 72 "scc.y"
    {(yyval.node) = Treenode::CreateNode(_EXTVARS, NULL); Treenode::AddNode((yyval.node), (yyvsp[(1) - (3)].node)); Treenode::AddNode((yyval.node), Treenode::CreateNode(_COMMA, NULL)); Treenode::AddNode((yyval.node), (yyvsp[(3) - (3)].node));;}
    break;

  case 9:
#line 73 "scc.y"
    {(yyval.node) = Treenode::CreateNode(_EXTVARS, NULL);;}
    break;

  case 10:
#line 77 "scc.y"
    {(yyval.node) = Treenode::CreateNode(_SPEC, NULL); Treenode::AddNode((yyval.node), Treenode::CreateNode(_TYPE, NULL));;}
    break;

  case 11:
#line 78 "scc.y"
    {(yyval.node) = Treenode::CreateNode(_SPEC, NULL); Treenode::AddNode((yyval.node), (yyvsp[(1) - (1)].node));;}
    break;

  case 12:
#line 82 "scc.y"
    {(yyval.node) = Treenode::CreateNode(_STSPEC, NULL); Treenode::AddNode((yyval.node), Treenode::CreateNode(_STRUCT, NULL)); Treenode::AddNode((yyval.node), (yyvsp[(2) - (5)].node)); Treenode::AddNode((yyval.node), Treenode::CreateNode(_LC, NULL)); Treenode::AddNode((yyval.node), (yyvsp[(4) - (5)].node)); Treenode::AddNode((yyval.node), Treenode::CreateNode(_RC, NULL));;}
    break;

  case 13:
#line 83 "scc.y"
    {(yyval.node) = Treenode::CreateNode(_STSPEC, NULL); Treenode::AddNode((yyval.node), Treenode::CreateNode(_STRUCT, NULL)); Treenode::AddNode((yyval.node), Treenode::CreateNode(_ID, (yyvsp[(2) - (2)].name)));;}
    break;

  case 14:
#line 87 "scc.y"
    {(yyval.node) = Treenode::CreateNode(_OPTTAG, NULL); Treenode::AddNode((yyval.node), Treenode::CreateNode(_ID, (yyvsp[(1) - (1)].name))); ;}
    break;

  case 15:
#line 88 "scc.y"
    {(yyval.node) = Treenode::CreateNode(_OPTTAG, NULL);;}
    break;

  case 16:
#line 92 "scc.y"
    {(yyval.node) = Treenode::CreateNode(_VAR, NULL); Treenode::AddNode((yyval.node), Treenode::CreateNode(_ID, (yyvsp[(1) - (1)].name)));;}
    break;

  case 17:
#line 93 "scc.y"
    {(yyval.node) = Treenode::CreateNode(_VAR, NULL); Treenode::AddNode((yyval.node), (yyvsp[(1) - (4)].node)); Treenode::AddNode((yyval.node), Treenode::CreateNode(_LB, NULL)); Treenode::AddNode((yyval.node), Treenode::CreateNode(_OCTAL, (yyvsp[(3) - (4)].valeur))); Treenode::AddNode((yyval.node), Treenode::CreateNode(_RB, NULL));;}
    break;

  case 18:
#line 94 "scc.y"
    {(yyval.node) = Treenode::CreateNode(_VAR, NULL); Treenode::AddNode((yyval.node), (yyvsp[(1) - (4)].node)); Treenode::AddNode((yyval.node), Treenode::CreateNode(_LB, NULL)); Treenode::AddNode((yyval.node), Treenode::CreateNode(_HEXADECIMAL, (yyvsp[(3) - (4)].valeur))); Treenode::AddNode((yyval.node), Treenode::CreateNode(_RB, NULL));;}
    break;

  case 19:
#line 95 "scc.y"
    {(yyval.node) = Treenode::CreateNode(_VAR, NULL); Treenode::AddNode((yyval.node), (yyvsp[(1) - (4)].node)); Treenode::AddNode((yyval.node), Treenode::CreateNode(_LB, NULL)); Treenode::AddNode((yyval.node), Treenode::CreateNode(_DECIMAL, (yyvsp[(3) - (4)].valeur))); Treenode::AddNode((yyval.node), Treenode::CreateNode(_RB, NULL));;}
    break;

  case 20:
#line 99 "scc.y"
    {(yyval.node) = Treenode::CreateNode(_FUNC, NULL); Treenode::AddNode((yyval.node), Treenode::CreateNode(_ID, (yyvsp[(1) - (4)].name))); Treenode::AddNode((yyval.node), Treenode::CreateNode(_LP, NULL)); Treenode::AddNode((yyval.node), (yyvsp[(3) - (4)].node)); Treenode::AddNode((yyval.node), Treenode::CreateNode(_RP, NULL));;}
    break;

  case 21:
#line 103 "scc.y"
    {(yyval.node) = Treenode::CreateNode(_PARAS, NULL); Treenode::AddNode((yyval.node), (yyvsp[(1) - (3)].node)); Treenode::AddNode((yyval.node), Treenode::CreateNode(_COMMA, NULL)); Treenode::AddNode((yyval.node), (yyvsp[(3) - (3)].node));;}
    break;

  case 22:
#line 104 "scc.y"
    {(yyval.node) = Treenode::CreateNode(_PARAS, NULL); Treenode::AddNode((yyval.node), (yyvsp[(1) - (1)].node));;}
    break;

  case 23:
#line 105 "scc.y"
    {(yyval.node) = Treenode::CreateNode(_PARAS, NULL);;}
    break;

  case 24:
#line 109 "scc.y"
    {(yyval.node) = Treenode::CreateNode(_PARA, NULL); Treenode::AddNode((yyval.node), (yyvsp[(1) - (2)].node)); Treenode::AddNode((yyval.node), (yyvsp[(2) - (2)].node));;}
    break;

  case 25:
#line 113 "scc.y"
    {(yyval.node) = Treenode::CreateNode(_STMTBLOCK, NULL); Treenode::AddNode((yyval.node), Treenode::CreateNode(_LC, NULL)); Treenode::AddNode((yyval.node), (yyvsp[(2) - (4)].node)); Treenode::AddNode((yyval.node), (yyvsp[(3) - (4)].node)); Treenode::AddNode((yyval.node), Treenode::CreateNode(_RC, NULL));;}
    break;

  case 26:
#line 117 "scc.y"
    {(yyval.node) = Treenode::CreateNode(_STMTS, NULL); Treenode::AddNode((yyval.node), (yyvsp[(1) - (2)].node)); Treenode::AddNode((yyval.node), (yyvsp[(2) - (2)].node));;}
    break;

  case 27:
#line 118 "scc.y"
    {(yyval.node) = Treenode::CreateNode(_STMTS, NULL);;}
    break;

  case 28:
#line 122 "scc.y"
    {(yyval.node) = Treenode::CreateNode(_STMT, NULL); Treenode::AddNode((yyval.node), (yyvsp[(1) - (2)].node)); Treenode::AddNode((yyval.node), Treenode::CreateNode(_SEMI, NULL));;}
    break;

  case 29:
#line 123 "scc.y"
    {(yyval.node) = Treenode::CreateNode(_STMT, NULL); Treenode::AddNode((yyval.node), (yyvsp[(1) - (1)].node));;}
    break;

  case 30:
#line 124 "scc.y"
    {(yyval.node) = Treenode::CreateNode(_STMT, NULL); Treenode::AddNode((yyval.node), Treenode::CreateNode(_RETURN, NULL)); Treenode::AddNode((yyval.node), (yyvsp[(2) - (3)].node)); Treenode::AddNode((yyval.node), Treenode::CreateNode(_SEMI, NULL));;}
    break;

  case 31:
#line 125 "scc.y"
    {(yyval.node) = Treenode::CreateNode(_STMT, NULL); Treenode::AddNode((yyval.node), Treenode::CreateNode(_IF, NULL)); Treenode::AddNode((yyval.node), Treenode::CreateNode(_LP, NULL)); Treenode::AddNode((yyval.node), (yyvsp[(3) - (6)].node)); Treenode::AddNode((yyval.node), Treenode::CreateNode(_RP, NULL)); Treenode::AddNode((yyval.node), (yyvsp[(5) - (6)].node)); Treenode::AddNode((yyval.node), (yyvsp[(6) - (6)].node));;}
    break;

  case 32:
#line 127 "scc.y"
    {(yyval.node) = Treenode::CreateNode(_STMT, NULL); Treenode::AddNode((yyval.node), Treenode::CreateNode(_FOR, NULL)); Treenode::AddNode((yyval.node), Treenode::CreateNode(_LP, NULL)); Treenode::AddNode((yyval.node), (yyvsp[(3) - (9)].node)); Treenode::AddNode((yyval.node), Treenode::CreateNode(_SEMI, NULL)); Treenode::AddNode((yyval.node), (yyvsp[(5) - (9)].node)); Treenode::AddNode((yyval.node), Treenode::CreateNode(_SEMI, NULL)); Treenode::AddNode((yyval.node), (yyvsp[(7) - (9)].node)); Treenode::AddNode((yyval.node), Treenode::CreateNode(_RP, NULL)); Treenode::AddNode((yyval.node), (yyvsp[(9) - (9)].node));;}
    break;

  case 33:
#line 128 "scc.y"
    {(yyval.node) = Treenode::CreateNode(_STMT, NULL); Treenode::AddNode((yyval.node), Treenode::CreateNode(_CONTINUE, NULL)); Treenode::AddNode((yyval.node), Treenode::CreateNode(_SEMI, NULL));;}
    break;

  case 34:
#line 129 "scc.y"
    {(yyval.node) = Treenode::CreateNode(_STMT, NULL); Treenode::AddNode((yyval.node), Treenode::CreateNode(_BREAK, NULL)); Treenode::AddNode((yyval.node), Treenode::CreateNode(_SEMI, NULL));;}
    break;

  case 35:
#line 133 "scc.y"
    {(yyval.node) = Treenode::CreateNode(_ESTMT, NULL); Treenode::AddNode((yyval.node), Treenode::CreateNode(_ELSE, NULL)); Treenode::AddNode((yyval.node), (yyvsp[(2) - (2)].node));;}
    break;

  case 36:
#line 134 "scc.y"
    {(yyval.node) = Treenode::CreateNode(_ESTMT, NULL);;}
    break;

  case 37:
#line 138 "scc.y"
    {(yyval.node) = Treenode::CreateNode(_DEFS, NULL); Treenode::AddNode((yyval.node), (yyvsp[(1) - (2)].node)); Treenode::AddNode((yyval.node), (yyvsp[(2) - (2)].node));;}
    break;

  case 38:
#line 139 "scc.y"
    {(yyval.node) = Treenode::CreateNode(_DEFS, NULL);;}
    break;

  case 39:
#line 143 "scc.y"
    {(yyval.node) = Treenode::CreateNode(_DEF, NULL); Treenode::AddNode((yyval.node), (yyvsp[(1) - (3)].node)); Treenode::AddNode((yyval.node), (yyvsp[(2) - (3)].node)); Treenode::AddNode((yyval.node), Treenode::CreateNode(_SEMI, NULL));;}
    break;

  case 40:
#line 147 "scc.y"
    {(yyval.node) = Treenode::CreateNode(_DECS, NULL); Treenode::AddNode((yyval.node), (yyvsp[(1) - (3)].node)); Treenode::AddNode((yyval.node), Treenode::CreateNode(_COMMA, NULL)); Treenode::AddNode((yyval.node), (yyvsp[(3) - (3)].node));;}
    break;

  case 41:
#line 148 "scc.y"
    {(yyval.node) = Treenode::CreateNode(_DECS, NULL); Treenode::AddNode((yyval.node), (yyvsp[(1) - (1)].node));;}
    break;

  case 42:
#line 152 "scc.y"
    {(yyval.node) = Treenode::CreateNode(_DEC, NULL); Treenode::AddNode((yyval.node), (yyvsp[(1) - (1)].node));;}
    break;

  case 43:
#line 153 "scc.y"
    {(yyval.node) = Treenode::CreateNode(_DEC, NULL); Treenode::AddNode((yyval.node), (yyvsp[(1) - (3)].node)); Treenode::AddNode((yyval.node), Treenode::CreateNode(_ASSIGN, NULL)); Treenode::AddNode((yyval.node), (yyvsp[(3) - (3)].node));;}
    break;

  case 44:
#line 157 "scc.y"
    {(yyval.node) = Treenode::CreateNode(_INIT, NULL); Treenode::AddNode((yyval.node), (yyvsp[(1) - (1)].node));;}
    break;

  case 45:
#line 158 "scc.y"
    {(yyval.node) = Treenode::CreateNode(_INIT, NULL); Treenode::AddNode((yyval.node), Treenode::CreateNode(_LC, NULL)); Treenode::AddNode((yyval.node), (yyvsp[(2) - (3)].node)); Treenode::AddNode((yyval.node), Treenode::CreateNode(_RC, NULL));;}
    break;

  case 46:
#line 162 "scc.y"
    {(yyval.node) = Treenode::CreateNode(_EXP, NULL); Treenode::AddNode((yyval.node), (yyvsp[(1) - (3)].node)); Treenode::AddNode((yyval.node), Treenode::CreateNode(_MULT, NULL)); Treenode::AddNode((yyval.node), (yyvsp[(3) - (3)].node));;}
    break;

  case 47:
#line 163 "scc.y"
    {(yyval.node) = Treenode::CreateNode(_EXP, NULL); Treenode::AddNode((yyval.node), (yyvsp[(1) - (3)].node)); Treenode::AddNode((yyval.node), Treenode::CreateNode(_DIV, NULL)); Treenode::AddNode((yyval.node), (yyvsp[(3) - (3)].node));;}
    break;

  case 48:
#line 164 "scc.y"
    {(yyval.node) = Treenode::CreateNode(_EXP, NULL); Treenode::AddNode((yyval.node), (yyvsp[(1) - (3)].node)); Treenode::AddNode((yyval.node), Treenode::CreateNode(_MOD, NULL)); Treenode::AddNode((yyval.node), (yyvsp[(3) - (3)].node));;}
    break;

  case 49:
#line 165 "scc.y"
    {(yyval.node) = Treenode::CreateNode(_EXP, NULL); Treenode::AddNode((yyval.node), (yyvsp[(1) - (3)].node)); Treenode::AddNode((yyval.node), Treenode::CreateNode(_PLUS, NULL)); Treenode::AddNode((yyval.node), (yyvsp[(3) - (3)].node));;}
    break;

  case 50:
#line 166 "scc.y"
    {(yyval.node) = Treenode::CreateNode(_EXP, NULL); Treenode::AddNode((yyval.node), (yyvsp[(1) - (3)].node)); Treenode::AddNode((yyval.node), Treenode::CreateNode(_MINUS, NULL)); Treenode::AddNode((yyval.node), (yyvsp[(3) - (3)].node));;}
    break;

  case 51:
#line 167 "scc.y"
    {(yyval.node) = Treenode::CreateNode(_EXP, NULL); Treenode::AddNode((yyval.node), (yyvsp[(1) - (3)].node)); Treenode::AddNode((yyval.node), Treenode::CreateNode(_GT, NULL)); Treenode::AddNode((yyval.node), (yyvsp[(3) - (3)].node));;}
    break;

  case 52:
#line 168 "scc.y"
    {(yyval.node) = Treenode::CreateNode(_EXP, NULL); Treenode::AddNode((yyval.node), (yyvsp[(1) - (3)].node)); Treenode::AddNode((yyval.node), Treenode::CreateNode(_GE, NULL)); Treenode::AddNode((yyval.node), (yyvsp[(3) - (3)].node));;}
    break;

  case 53:
#line 169 "scc.y"
    {(yyval.node) = Treenode::CreateNode(_EXP, NULL); Treenode::AddNode((yyval.node), (yyvsp[(1) - (3)].node)); Treenode::AddNode((yyval.node), Treenode::CreateNode(_LT, NULL)); Treenode::AddNode((yyval.node), (yyvsp[(3) - (3)].node));;}
    break;

  case 54:
#line 170 "scc.y"
    {(yyval.node) = Treenode::CreateNode(_EXP, NULL); Treenode::AddNode((yyval.node), (yyvsp[(1) - (3)].node)); Treenode::AddNode((yyval.node), Treenode::CreateNode(_LE, NULL)); Treenode::AddNode((yyval.node), (yyvsp[(3) - (3)].node));;}
    break;

  case 55:
#line 171 "scc.y"
    {(yyval.node) = Treenode::CreateNode(_EXP, NULL); Treenode::AddNode((yyval.node), (yyvsp[(1) - (3)].node)); Treenode::AddNode((yyval.node), Treenode::CreateNode(_EQ, NULL)); Treenode::AddNode((yyval.node), (yyvsp[(3) - (3)].node));;}
    break;

  case 56:
#line 172 "scc.y"
    {(yyval.node) = Treenode::CreateNode(_EXP, NULL); Treenode::AddNode((yyval.node), (yyvsp[(1) - (3)].node)); Treenode::AddNode((yyval.node), Treenode::CreateNode(_NE, NULL)); Treenode::AddNode((yyval.node), (yyvsp[(3) - (3)].node));;}
    break;

  case 57:
#line 173 "scc.y"
    {(yyval.node) = Treenode::CreateNode(_EXP, NULL); Treenode::AddNode((yyval.node), (yyvsp[(1) - (3)].node)); Treenode::AddNode((yyval.node), Treenode::CreateNode(_SHIFTLEFT, NULL)); Treenode::AddNode((yyval.node), (yyvsp[(3) - (3)].node));;}
    break;

  case 58:
#line 174 "scc.y"
    {(yyval.node) = Treenode::CreateNode(_EXP, NULL); Treenode::AddNode((yyval.node), (yyvsp[(1) - (3)].node)); Treenode::AddNode((yyval.node), Treenode::CreateNode(_SHIFTRIGHT, NULL)); Treenode::AddNode((yyval.node), (yyvsp[(3) - (3)].node));;}
    break;

  case 59:
#line 175 "scc.y"
    {(yyval.node) = Treenode::CreateNode(_EXP, NULL); Treenode::AddNode((yyval.node), (yyvsp[(1) - (3)].node)); Treenode::AddNode((yyval.node), Treenode::CreateNode(_BITAND, NULL)); Treenode::AddNode((yyval.node), (yyvsp[(3) - (3)].node));;}
    break;

  case 60:
#line 176 "scc.y"
    {(yyval.node) = Treenode::CreateNode(_EXP, NULL); Treenode::AddNode((yyval.node), (yyvsp[(1) - (3)].node)); Treenode::AddNode((yyval.node), Treenode::CreateNode(_BITXOR, NULL)); Treenode::AddNode((yyval.node), (yyvsp[(3) - (3)].node));;}
    break;

  case 61:
#line 177 "scc.y"
    {(yyval.node) = Treenode::CreateNode(_EXP, NULL); Treenode::AddNode((yyval.node), (yyvsp[(1) - (3)].node)); Treenode::AddNode((yyval.node), Treenode::CreateNode(_BITOR, NULL)); Treenode::AddNode((yyval.node), (yyvsp[(3) - (3)].node));;}
    break;

  case 62:
#line 178 "scc.y"
    {(yyval.node) = Treenode::CreateNode(_EXP, NULL); Treenode::AddNode((yyval.node), (yyvsp[(1) - (3)].node)); Treenode::AddNode((yyval.node), Treenode::CreateNode(_AND, NULL)); Treenode::AddNode((yyval.node), (yyvsp[(3) - (3)].node));;}
    break;

  case 63:
#line 179 "scc.y"
    {(yyval.node) = Treenode::CreateNode(_EXP, NULL); Treenode::AddNode((yyval.node), (yyvsp[(1) - (3)].node)); Treenode::AddNode((yyval.node), Treenode::CreateNode(_OR, NULL)); Treenode::AddNode((yyval.node), (yyvsp[(3) - (3)].node));;}
    break;

  case 64:
#line 180 "scc.y"
    {(yyval.node) = Treenode::CreateNode(_EXP, NULL); Treenode::AddNode((yyval.node), (yyvsp[(1) - (3)].node)); Treenode::AddNode((yyval.node), Treenode::CreateNode(_ASSIGN, NULL)); Treenode::AddNode((yyval.node), (yyvsp[(3) - (3)].node));;}
    break;

  case 65:
#line 182 "scc.y"
    {(yyval.node) = Treenode::CreateNode(_EXP, NULL); Treenode::AddNode((yyval.node), (yyvsp[(1) - (3)].node)); Treenode::AddNode((yyval.node), Treenode::CreateNode(_ASSIGNSHIFTR, NULL)); Treenode::AddNode((yyval.node), (yyvsp[(3) - (3)].node));;}
    break;

  case 66:
#line 183 "scc.y"
    {(yyval.node) = Treenode::CreateNode(_EXP, NULL); Treenode::AddNode((yyval.node), (yyvsp[(1) - (3)].node)); Treenode::AddNode((yyval.node), Treenode::CreateNode(_ASSIGNSHIFTL, NULL)); Treenode::AddNode((yyval.node), (yyvsp[(3) - (3)].node));;}
    break;

  case 67:
#line 184 "scc.y"
    {(yyval.node) = Treenode::CreateNode(_EXP, NULL); Treenode::AddNode((yyval.node), (yyvsp[(1) - (3)].node)); Treenode::AddNode((yyval.node), Treenode::CreateNode(_ASSIGNORBIT, NULL)); Treenode::AddNode((yyval.node), (yyvsp[(3) - (3)].node));;}
    break;

  case 68:
#line 185 "scc.y"
    {(yyval.node) = Treenode::CreateNode(_EXP, NULL); Treenode::AddNode((yyval.node), (yyvsp[(1) - (3)].node)); Treenode::AddNode((yyval.node), Treenode::CreateNode(_ASSIGNXORBIT, NULL)); Treenode::AddNode((yyval.node), (yyvsp[(3) - (3)].node));;}
    break;

  case 69:
#line 186 "scc.y"
    {(yyval.node) = Treenode::CreateNode(_EXP, NULL); Treenode::AddNode((yyval.node), (yyvsp[(1) - (3)].node)); Treenode::AddNode((yyval.node), Treenode::CreateNode(_ASSIGNANDBIT, NULL)); Treenode::AddNode((yyval.node), (yyvsp[(3) - (3)].node));;}
    break;

  case 70:
#line 187 "scc.y"
    {(yyval.node) = Treenode::CreateNode(_EXP, NULL); Treenode::AddNode((yyval.node), (yyvsp[(1) - (3)].node)); Treenode::AddNode((yyval.node), Treenode::CreateNode(_ASSIGNDIV, NULL)); Treenode::AddNode((yyval.node), (yyvsp[(3) - (3)].node));;}
    break;

  case 71:
#line 188 "scc.y"
    {(yyval.node) = Treenode::CreateNode(_EXP, NULL); Treenode::AddNode((yyval.node), (yyvsp[(1) - (3)].node)); Treenode::AddNode((yyval.node), Treenode::CreateNode(_ASSIGNMINUS, NULL)); Treenode::AddNode((yyval.node), (yyvsp[(3) - (3)].node));;}
    break;

  case 72:
#line 189 "scc.y"
    {(yyval.node) = Treenode::CreateNode(_EXP, NULL); Treenode::AddNode((yyval.node), (yyvsp[(1) - (3)].node)); Treenode::AddNode((yyval.node), Treenode::CreateNode(_ASSIGNMULT, NULL)); Treenode::AddNode((yyval.node), (yyvsp[(3) - (3)].node));;}
    break;

  case 73:
#line 190 "scc.y"
    {(yyval.node) = Treenode::CreateNode(_EXP, NULL); Treenode::AddNode((yyval.node), (yyvsp[(1) - (3)].node)); Treenode::AddNode((yyval.node), Treenode::CreateNode(_ASSIGNPLUS, NULL)); Treenode::AddNode((yyval.node), (yyvsp[(3) - (3)].node));;}
    break;

  case 74:
#line 192 "scc.y"
    {(yyval.node) = Treenode::CreateNode(_EXP, NULL); Treenode::AddNode((yyval.node), Treenode::CreateNode(_MINUS, NULL)); Treenode::AddNode((yyval.node), (yyvsp[(2) - (2)].node));;}
    break;

  case 75:
#line 193 "scc.y"
    {(yyval.node) = Treenode::CreateNode(_EXP, NULL); Treenode::AddNode((yyval.node), Treenode::CreateNode(_UNARYNOT, NULL)); Treenode::AddNode((yyval.node), (yyvsp[(2) - (2)].node));;}
    break;

  case 76:
#line 194 "scc.y"
    {(yyval.node) = Treenode::CreateNode(_EXP, NULL); Treenode::AddNode((yyval.node), Treenode::CreateNode(_UNARYINCR, NULL)); Treenode::AddNode((yyval.node), (yyvsp[(2) - (2)].node));;}
    break;

  case 77:
#line 195 "scc.y"
    {(yyval.node) = Treenode::CreateNode(_EXP, NULL); Treenode::AddNode((yyval.node), Treenode::CreateNode(_UNARYDECR, NULL)); Treenode::AddNode((yyval.node), (yyvsp[(2) - (2)].node));;}
    break;

  case 78:
#line 196 "scc.y"
    {(yyval.node) = Treenode::CreateNode(_EXP, NULL); Treenode::AddNode((yyval.node), Treenode::CreateNode(_UNARYBITNOT, NULL)); Treenode::AddNode((yyval.node), (yyvsp[(2) - (2)].node));;}
    break;

  case 79:
#line 197 "scc.y"
    {(yyval.node) = Treenode::CreateNode(_EXP, NULL); Treenode::AddNode((yyval.node), Treenode::CreateNode(_LP, NULL)); Treenode::AddNode((yyval.node), (yyvsp[(2) - (3)].node)); Treenode::AddNode((yyval.node), Treenode::CreateNode(_RP, NULL));;}
    break;

  case 80:
#line 198 "scc.y"
    {(yyval.node) = Treenode::CreateNode(_EXP, NULL); Treenode::AddNode((yyval.node), Treenode::CreateNode(_ID, (yyvsp[(1) - (4)].name))); Treenode::AddNode((yyval.node), Treenode::CreateNode(_LP, NULL)); Treenode::AddNode((yyval.node), (yyvsp[(3) - (4)].node)); Treenode::AddNode((yyval.node), Treenode::CreateNode(_RP, NULL));;}
    break;

  case 81:
#line 199 "scc.y"
    {(yyval.node) = Treenode::CreateNode(_EXP, NULL); Treenode::AddNode((yyval.node), Treenode::CreateNode(_ID, (yyvsp[(1) - (2)].name))); Treenode::AddNode((yyval.node), (yyvsp[(2) - (2)].node));;}
    break;

  case 82:
#line 200 "scc.y"
    {(yyval.node) = Treenode::CreateNode(_EXP, NULL); Treenode::AddNode((yyval.node), (yyvsp[(1) - (3)].node)); Treenode::AddNode((yyval.node), Treenode::CreateNode(_DOT, NULL)); Treenode::AddNode((yyval.node), Treenode::CreateNode(_ID, (yyvsp[(3) - (3)].name)));;}
    break;

  case 83:
#line 201 "scc.y"
    {(yyval.node) = Treenode::CreateNode(_EXP, NULL); Treenode::AddNode((yyval.node), Treenode::CreateNode(_OCTAL, (yyvsp[(1) - (1)].valeur)));;}
    break;

  case 84:
#line 202 "scc.y"
    {(yyval.node) = Treenode::CreateNode(_EXP, NULL); Treenode::AddNode((yyval.node), Treenode::CreateNode(_HEXADECIMAL, (yyvsp[(1) - (1)].valeur)));;}
    break;

  case 85:
#line 203 "scc.y"
    {(yyval.node) = Treenode::CreateNode(_EXP, NULL); Treenode::AddNode((yyval.node), Treenode::CreateNode(_DECIMAL, (yyvsp[(1) - (1)].valeur)));;}
    break;

  case 86:
#line 204 "scc.y"
    {(yyval.node) = Treenode::CreateNode(_EXP, NULL);;}
    break;

  case 87:
#line 208 "scc.y"
    {(yyval.node) = Treenode::CreateNode(_ARRS, NULL); Treenode::AddNode((yyval.node), Treenode::CreateNode(_LB, NULL)); Treenode::AddNode((yyval.node), (yyvsp[(2) - (4)].node)); Treenode::AddNode((yyval.node), Treenode::CreateNode(_RB, NULL)); Treenode::AddNode((yyval.node), (yyvsp[(4) - (4)].node));;}
    break;

  case 88:
#line 209 "scc.y"
    {(yyval.node) = Treenode::CreateNode(_ARRS, NULL);;}
    break;

  case 89:
#line 213 "scc.y"
    {(yyval.node) = Treenode::CreateNode(_ARGS, NULL); Treenode::AddNode((yyval.node), (yyvsp[(1) - (3)].node)); Treenode::AddNode((yyval.node), Treenode::CreateNode(_COMMA, NULL)); Treenode::AddNode((yyval.node), (yyvsp[(3) - (3)].node)); ;}
    break;

  case 90:
#line 214 "scc.y"
    {(yyval.node) = Treenode::CreateNode(_ARGS, NULL); Treenode::AddNode((yyval.node), (yyvsp[(1) - (1)].node));;}
    break;


/* Line 1267 of yacc.c.  */
#line 2142 "scc.cpp"
      default: break;
    }
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;


  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
      {
	YYSIZE_T yysize = yysyntax_error (0, yystate, yychar);
	if (yymsg_alloc < yysize && yymsg_alloc < YYSTACK_ALLOC_MAXIMUM)
	  {
	    YYSIZE_T yyalloc = 2 * yysize;
	    if (! (yysize <= yyalloc && yyalloc <= YYSTACK_ALLOC_MAXIMUM))
	      yyalloc = YYSTACK_ALLOC_MAXIMUM;
	    if (yymsg != yymsgbuf)
	      YYSTACK_FREE (yymsg);
	    yymsg = (char *) YYSTACK_ALLOC (yyalloc);
	    if (yymsg)
	      yymsg_alloc = yyalloc;
	    else
	      {
		yymsg = yymsgbuf;
		yymsg_alloc = sizeof yymsgbuf;
	      }
	  }

	if (0 < yysize && yysize <= yymsg_alloc)
	  {
	    (void) yysyntax_error (yymsg, yystate, yychar);
	    yyerror (yymsg);
	  }
	else
	  {
	    yyerror (YY_("syntax error"));
	    if (yysize != 0)
	      goto yyexhaustedlab;
	  }
      }
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse look-ahead token after an
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

  /* Else will try to reuse look-ahead token after shifting the error
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

  /* Do not reclaim the symbols of the rule which action triggered
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
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (yyn != YYPACT_NINF)
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

  if (yyn == YYFINAL)
    YYACCEPT;

  *++yyvsp = yylval;


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

#ifndef yyoverflow
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEOF && yychar != YYEMPTY)
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval);
  /* Do not reclaim the symbols of the rule which action triggered
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
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}


#line 217 "scc.y"

// When the scanner receives an end-of-file, just return 1 means ok
int yywrap(void)
{
	return 1;
}

// Run
void Run(char *file)
{
	LLVMBuild::BuildLLVM(node, file);
	//Treenode::PrintNode(node, 0, file);
}

// Free memories
void EraseTreeNode()
{
	Treenode::EraseTree(node);
}

// Print the message error
void yyerror(char *msg)
{
	fprintf(stderr, "%s\n", msg);
	Treenode::SetWellFormed(false);
}


