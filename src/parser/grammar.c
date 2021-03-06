/*
** 2000-05-29
**
** The author disclaims copyright to this source code.  In place of
** a legal notice, here is a blessing:
**
**    May you do good and not evil.
**    May you find forgiveness for yourself and forgive others.
**    May you share freely, never taking more than you give.
**
*************************************************************************
** Driver template for the LEMON parser generator.
**
** The "lemon" program processes an LALR(1) input grammar file, then uses
** this template to construct a parser.  The "lemon" program inserts text
** at each "%%" line.  Also, any "P-a-r-s-e" identifer prefix (without the
** interstitial "-" characters) contained in this template is changed into
** the value of the %name directive from the grammar.  Otherwise, the content
** of this template is copied straight through into the generate parser
** source file.
**
** The following is the concatenation of all %include directives from the
** input grammar file:
*/
#include <stdio.h>
/************ Begin %include sections from the grammar ************************/
#line 9 "grammar.y"

	#include <stdlib.h>
	#include <stdio.h>
	#include <assert.h>
	#include <limits.h>
	#include "token.h"	
	#include "grammar.h"
	#include "ast.h"
	#include "./clauses/clauses.h"
	#include "parse.h"
	#include "../value.h"
	#include "../util/arr.h"

	void yyerror(char *s);

	/*
	**    YYSTACKDEPTH       is the maximum depth of the parser's stack.  If
	**                       zero the stack is dynamically sized using realloc()
	*/
	// Increase depth from 100 to 1000 to handel deep recursion.
	#define YYSTACKDEPTH 1000
#line 50 "grammar.c"
/**************** End of %include directives **********************************/
/* These constants specify the various numeric values for terminal symbols
** in a format understandable to "makeheaders".  This section is blank unless
** "lemon" is run with the "-m" command-line option.
***************** Begin makeheaders token definitions *************************/
/**************** End makeheaders token definitions ***************************/

/* The next sections is a series of control #defines.
** various aspects of the generated parser.
**    YYCODETYPE         is the data type used to store the integer codes
**                       that represent terminal and non-terminal symbols.
**                       "unsigned char" is used if there are fewer than
**                       256 symbols.  Larger types otherwise.
**    YYNOCODE           is a number of type YYCODETYPE that is not used for
**                       any terminal or nonterminal symbol.
**    YYFALLBACK         If defined, this indicates that one or more tokens
**                       (also known as: "terminal symbols") have fall-back
**                       values which should be used if the original symbol
**                       would not parse.  This permits keywords to sometimes
**                       be used as identifiers, for example.
**    YYACTIONTYPE       is the data type used for "action codes" - numbers
**                       that indicate what to do in response to the next
**                       token.
**    ParseTOKENTYPE     is the data type used for minor type for terminal
**                       symbols.  Background: A "minor type" is a semantic
**                       value associated with a terminal or non-terminal
**                       symbols.  For example, for an "ID" terminal symbol,
**                       the minor type might be the name of the identifier.
**                       Each non-terminal can have a different minor type.
**                       Terminal symbols all have the same minor type, though.
**                       This macros defines the minor type for terminal 
**                       symbols.
**    YYMINORTYPE        is the data type used for all minor types.
**                       This is typically a union of many types, one of
**                       which is ParseTOKENTYPE.  The entry in the union
**                       for terminal symbols is called "yy0".
**    YYSTACKDEPTH       is the maximum depth of the parser's stack.  If
**                       zero the stack is dynamically sized using realloc()
**    ParseARG_SDECL     A static variable declaration for the %extra_argument
**    ParseARG_PDECL     A parameter declaration for the %extra_argument
**    ParseARG_STORE     Code to store %extra_argument into yypParser
**    ParseARG_FETCH     Code to extract %extra_argument from yypParser
**    YYERRORSYMBOL      is the code number of the error symbol.  If not
**                       defined, then do no error processing.
**    YYNSTATE           the combined number of states.
**    YYNRULE            the number of rules in the grammar
**    YYNTOKEN           Number of terminal symbols
**    YY_MAX_SHIFT       Maximum value for shift actions
**    YY_MIN_SHIFTREDUCE Minimum value for shift-reduce actions
**    YY_MAX_SHIFTREDUCE Maximum value for shift-reduce actions
**    YY_ERROR_ACTION    The yy_action[] code for syntax error
**    YY_ACCEPT_ACTION   The yy_action[] code for accept
**    YY_NO_ACTION       The yy_action[] code for no-op
**    YY_MIN_REDUCE      Minimum value for reduce actions
**    YY_MAX_REDUCE      Maximum value for reduce actions
*/
#ifndef INTERFACE
# define INTERFACE 1
#endif
/************* Begin control #defines *****************************************/
#define YYCODETYPE unsigned char
#define YYNOCODE 96
#define YYACTIONTYPE unsigned short int
#define ParseTOKENTYPE Token
typedef union {
  int yyinit;
  ParseTOKENTYPE yy0;
  AST_MergeNode* yy10;
  AST_OrderNode* yy28;
  AST_ReturnElementNode* yy34;
  AST_LinkEntity* yy35;
  AST_ReturnElementNode** yy66;
  AST* yy67;
  AST_IndexNode* yy74;
  AST_LimitNode* yy77;
  char** yy83;
  AST_FilterNode* yy86;
  AST_NodeEntity* yy89;
  AST_CreateNode* yy96;
  AST_IndexOpType yy105;
  char* yy106;
  AST_DeleteNode * yy115;
  Vector* yy116;
  AST_Variable* yy120;
  int yy122;
  AST_SetElement* yy124;
  AST_SetNode* yy130;
  AST_UnwindNode* yy137;
  AST_LinkLength* yy140;
  AST_ArithmeticExpressionNode* yy154;
  AST_MatchNode* yy155;
  AST_SkipNode* yy173;
  AST_WhereNode* yy181;
  AST_ReturnNode* yy188;
  SIValue yy189;
} YYMINORTYPE;
#ifndef YYSTACKDEPTH
#define YYSTACKDEPTH 100
#endif
#define ParseARG_SDECL  parseCtx *ctx ;
#define ParseARG_PDECL , parseCtx *ctx 
#define ParseARG_FETCH  parseCtx *ctx  = yypParser->ctx 
#define ParseARG_STORE yypParser->ctx  = ctx 
#define YYNSTATE             125
#define YYNRULE              109
#define YYNTOKEN             52
#define YY_MAX_SHIFT         124
#define YY_MIN_SHIFTREDUCE   197
#define YY_MAX_SHIFTREDUCE   305
#define YY_ERROR_ACTION      306
#define YY_ACCEPT_ACTION     307
#define YY_NO_ACTION         308
#define YY_MIN_REDUCE        309
#define YY_MAX_REDUCE        417
/************* End control #defines *******************************************/

/* Define the yytestcase() macro to be a no-op if is not already defined
** otherwise.
**
** Applications can choose to define yytestcase() in the %include section
** to a macro that can assist in verifying code coverage.  For production
** code the yytestcase() macro should be turned off.  But it is useful
** for testing.
*/
#ifndef yytestcase
# define yytestcase(X)
#endif


/* Next are the tables used to determine what action to take based on the
** current state and lookahead token.  These tables are used to implement
** functions that take a state number and lookahead value and return an
** action integer.  
**
** Suppose the action integer is N.  Then the action is determined as
** follows
**
**   0 <= N <= YY_MAX_SHIFT             Shift N.  That is, push the lookahead
**                                      token onto the stack and goto state N.
**
**   N between YY_MIN_SHIFTREDUCE       Shift to an arbitrary state then
**     and YY_MAX_SHIFTREDUCE           reduce by rule N-YY_MIN_SHIFTREDUCE.
**
**   N == YY_ERROR_ACTION               A syntax error has occurred.
**
**   N == YY_ACCEPT_ACTION              The parser accepts its input.
**
**   N == YY_NO_ACTION                  No such action.  Denotes unused
**                                      slots in the yy_action[] table.
**
**   N between YY_MIN_REDUCE            Reduce by rule N-YY_MIN_REDUCE
**     and YY_MAX_REDUCE
**
** The action table is constructed as a single large table named yy_action[].
** Given state S and lookahead X, the action is computed as either:
**
**    (A)   N = yy_action[ yy_shift_ofst[S] + X ]
**    (B)   N = yy_default[S]
**
** The (A) formula is preferred.  The B formula is used instead if
** yy_lookahead[yy_shift_ofst[S]+X] is not equal to X.
**
** The formulas above are for computing the action when the lookahead is
** a terminal symbol.  If the lookahead is a non-terminal (as occurs after
** a reduce action) then the yy_reduce_ofst[] array is used in place of
** the yy_shift_ofst[] array.
**
** The following are the tables generated in this section:
**
**  yy_action[]        A single table containing all actions.
**  yy_lookahead[]     A table containing the lookahead for each entry in
**                     yy_action.  Used to detect hash collisions.
**  yy_shift_ofst[]    For each state, the offset into yy_action for
**                     shifting terminals.
**  yy_reduce_ofst[]   For each state, the offset into yy_action for
**                     shifting non-terminals after a reduce.
**  yy_default[]       Default action for each state.
**
*********** Begin parsing tables **********************************************/
#define YY_ACTTAB_COUNT (336)
static const YYACTIONTYPE yy_action[] = {
 /*     0 */   124,  307,   65,   13,  315,  319,   77,  268,   96,  337,
 /*    10 */    95,   12,  317,  318,   42,  322,  111,   56,  327,   89,
 /*    20 */    79,   20,   19,   18,   17,   16,  292,  293,  296,  294,
 /*    30 */   295,   26,  298,   77,  268,  390,   68,  107,    2,  271,
 /*    40 */    25,   33,   45,  390,   66,   94,  389,   79,   20,  300,
 /*    50 */   301,  303,  304,  305,  389,  390,   66,  119,  379,  298,
 /*    60 */    19,   18,   17,   16,   49,  297,  389,   36,  358,  117,
 /*    70 */   379,  101,    6,    8,   37,  358,  300,  301,  303,  304,
 /*    80 */   305,   19,   18,   17,   16,  292,  293,  296,  294,  295,
 /*    90 */    77,  261,   24,   23,  118,   77,  220,  338,   95,   99,
 /*   100 */    77,   27,  390,   66,   79,   20,   64,   99,   22,   79,
 /*   110 */     7,  312,   60,  389,   53,    1,  298,  378,   34,   56,
 /*   120 */   327,  298,   53,  340,  297,   84,  298,   39,   19,   18,
 /*   130 */    17,   16,  340,  300,  301,  303,  304,  305,  300,  301,
 /*   140 */   303,  304,  305,  300,  301,  303,  304,  305,   19,   18,
 /*   150 */    17,   16,  109,   38,   50,  390,   71,  390,   31,  390,
 /*   160 */    69,  390,   30,  390,   31,  271,  389,   53,  389,   91,
 /*   170 */   389,   74,  389,   72,  389,  374,   46,    6,    8,  390,
 /*   180 */    31,  390,   71,  390,   71,  299,   76,  116,   15,   55,
 /*   190 */   389,   75,  389,   35,  389,  316,   44,   78,  340,   73,
 /*   200 */   390,   70,   26,  302,  390,  387,  285,  286,   56,  327,
 /*   210 */    48,  389,  390,  386,   10,  389,   47,  390,   80,  390,
 /*   220 */    81,  390,   67,  389,    1,   90,   48,  115,  389,   53,
 /*   230 */   389,   35,  389,  120,   15,  100,  340,  104,  102,   83,
 /*   240 */   276,  110,   53,   15,   17,   16,   87,  330,   85,   24,
 /*   250 */    40,  323,  123,  320,   43,  122,  233,   93,   97,   21,
 /*   260 */    53,   98,   99,   76,  112,  105,  359,  341,  106,  108,
 /*   270 */   369,  114,   26,  113,  328,  314,   57,   58,    1,  121,
 /*   280 */    59,    9,  310,   61,   62,  291,    3,   63,   82,    5,
 /*   290 */   221,  222,   86,   41,   88,    8,   29,  234,   92,  120,
 /*   300 */    28,   14,  240,  245,  243,   11,  309,   51,  238,  244,
 /*   310 */   242,  308,  236,  251,  249,  241,  239,  103,   52,  237,
 /*   320 */    32,  235,   54,  255,  308,    4,  270,  282,  308,  308,
 /*   330 */   288,  308,  308,  308,  308,  290,
};
static const YYCODETYPE yy_lookahead[] = {
 /*     0 */    53,   54,   55,   91,   57,   58,    4,    5,   76,   77,
 /*    10 */    78,   64,   65,   66,   67,   68,   89,   70,   71,   72,
 /*    20 */    18,   19,    3,    4,    5,    6,    7,    8,    9,   10,
 /*    30 */    11,   13,   30,    4,    5,   78,   79,   83,   36,   20,
 /*    40 */    22,   19,   24,   78,   79,   18,   89,   18,   19,   47,
 /*    50 */    48,   49,   50,   51,   89,   78,   79,   92,   93,   30,
 /*    60 */     3,    4,    5,    6,   83,   46,   89,   86,   87,   92,
 /*    70 */    93,   83,    1,    2,   86,   87,   47,   48,   49,   50,
 /*    80 */    51,    3,    4,    5,    6,    7,    8,    9,   10,   11,
 /*    90 */     4,   20,   12,   13,   37,    4,   16,   77,   78,   17,
 /*   100 */     4,   21,   78,   79,   18,   19,   57,   17,   18,   18,
 /*   110 */    19,   62,   63,   89,   32,   35,   30,   93,   75,   70,
 /*   120 */    71,   30,   32,   80,   46,   45,   30,   75,    3,    4,
 /*   130 */     5,    6,   80,   47,   48,   49,   50,   51,   47,   48,
 /*   140 */    49,   50,   51,   47,   48,   49,   50,   51,    3,    4,
 /*   150 */     5,    6,   17,   18,    4,   78,   79,   78,   79,   78,
 /*   160 */    79,   78,   79,   78,   79,   20,   89,   32,   89,   90,
 /*   170 */    89,   94,   89,   90,   89,   90,   26,    1,    2,   78,
 /*   180 */    79,   78,   79,   78,   79,   30,    5,   69,   23,   81,
 /*   190 */    89,   90,   89,   75,   89,   57,   58,   94,   80,   94,
 /*   200 */    78,   79,   13,   48,   78,   79,   41,   42,   70,   71,
 /*   210 */    29,   89,   78,   79,   19,   89,   85,   78,   79,   78,
 /*   220 */    79,   78,   79,   89,   35,   69,   29,   17,   89,   32,
 /*   230 */    89,   75,   89,   38,   23,   83,   80,   30,   31,   28,
 /*   240 */    20,   83,   32,   23,    5,    6,   19,   74,   17,   12,
 /*   250 */    73,   68,   44,   61,   60,   43,   18,   82,   84,   27,
 /*   260 */    32,   83,   17,    5,   18,   85,   87,   80,   84,   83,
 /*   270 */    88,   83,   13,   88,   71,   61,   60,   59,   35,   39,
 /*   280 */    58,   34,   61,   60,   59,   18,   56,   58,   37,   27,
 /*   290 */    18,   20,   18,   15,   14,    2,   23,   18,   23,   38,
 /*   300 */    23,    7,    4,   18,   28,   40,    0,   18,   20,   28,
 /*   310 */    28,   95,   20,   30,   30,   28,   25,   31,   23,   20,
 /*   320 */    17,   20,   18,   33,   95,   23,   18,   18,   95,   95,
 /*   330 */    30,   95,   95,   95,   95,   30,   95,   95,   95,   95,
 /*   340 */    95,   95,   95,   95,   95,   95,   95,   95,   95,   95,
 /*   350 */    95,   95,   95,   95,   95,   95,   95,   95,   95,   95,
 /*   360 */    95,   95,   95,   95,   95,   95,   95,   95,   95,   95,
 /*   370 */    95,   95,   95,   95,   95,   95,   95,   95,   95,   95,
 /*   380 */    95,   95,   95,   95,   95,   95,   95,   95,
};
#define YY_SHIFT_COUNT    (124)
#define YY_SHIFT_MIN      (0)
#define YY_SHIFT_MAX      (309)
static const unsigned short int yy_shift_ofst[] = {
 /*     0 */    80,    2,   29,   18,   29,   86,   91,   91,   91,   91,
 /*    10 */    86,   86,  189,   86,   86,   86,   86,   86,   86,   86,
 /*    20 */    86,   90,   82,   22,   22,   27,   22,   22,   27,   22,
 /*    30 */    19,   78,   96,  135,  150,  150,  181,  197,  210,  150,
 /*    40 */   227,  231,  237,  208,  212,  238,  232,  228,  245,  258,
 /*    50 */   232,  228,  246,  246,  228,   22,  259,  208,  212,  240,
 /*    60 */   243,  208,  212,  240,  243,  247,   57,  145,  125,  125,
 /*    70 */   125,  125,   71,  165,  211,  176,  207,  155,  220,  195,
 /*    80 */   239,  239,  267,  251,  262,  272,  271,  274,  278,  280,
 /*    90 */   273,  293,  279,  275,  261,  294,  277,  298,  276,  285,
 /*   100 */   281,  282,  283,  284,  286,  287,  291,  288,  292,  289,
 /*   110 */   299,  295,  303,  290,  301,  304,  273,  302,  308,  302,
 /*   120 */   309,  265,  300,  305,  306,
};
#define YY_REDUCE_COUNT (65)
#define YY_REDUCE_MIN   (-88)
#define YY_REDUCE_MAX   (230)
static const short yy_reduce_ofst[] = {
 /*     0 */   -53,  -35,  -23,   49,   24,   77,   79,   83,   85,  101,
 /*    10 */   103,  105,  138,  -43,   81,  122,  126,  134,  139,  141,
 /*    20 */   143,  -19,  -12,  118,  156,  -68,  118,   43,   20,   52,
 /*    30 */   -88,  -88,  -73,  -46,  108,  108,  131,  152,  158,  108,
 /*    40 */   173,  177,  183,  192,  194,  175,  174,  178,  179,  180,
 /*    50 */   184,  186,  182,  185,  188,  187,  203,  214,  216,  218,
 /*    60 */   222,  221,  223,  225,  229,  230,
};
static const YYACTIONTYPE yy_default[] = {
 /*     0 */   325,  306,  306,  325,  306,  306,  306,  306,  306,  306,
 /*    10 */   306,  306,  325,  306,  306,  306,  306,  306,  306,  306,
 /*    20 */   306,  366,  366,  331,  306,  306,  306,  306,  306,  306,
 /*    30 */   306,  306,  306,  366,  335,  342,  360,  366,  366,  343,
 /*    40 */   306,  306,  321,  401,  399,  306,  306,  366,  306,  360,
 /*    50 */   306,  366,  306,  306,  366,  306,  326,  401,  399,  395,
 /*    60 */   313,  401,  399,  395,  311,  370,  381,  306,  372,  339,
 /*    70 */   391,  392,  306,  396,  306,  371,  365,  306,  306,  393,
 /*    80 */   385,  384,  306,  306,  306,  306,  306,  306,  306,  306,
 /*    90 */   324,  375,  306,  344,  393,  306,  336,  306,  306,  306,
 /*   100 */   306,  306,  306,  362,  364,  306,  306,  306,  306,  306,
 /*   110 */   306,  368,  306,  306,  306,  306,  329,  377,  306,  376,
 /*   120 */   306,  306,  306,  306,  306,
};
/********** End of lemon-generated parsing tables *****************************/

/* The next table maps tokens (terminal symbols) into fallback tokens.  
** If a construct like the following:
** 
**      %fallback ID X Y Z.
**
** appears in the grammar, then ID becomes a fallback token for X, Y,
** and Z.  Whenever one of the tokens X, Y, or Z is input to the parser
** but it does not parse, the type of the token is changed to ID and
** the parse is retried before an error is thrown.
**
** This feature can be used, for example, to cause some keywords in a language
** to revert to identifiers if they keyword does not apply in the context where
** it appears.
*/
#ifdef YYFALLBACK
static const YYCODETYPE yyFallback[] = {
};
#endif /* YYFALLBACK */

/* The following structure represents a single element of the
** parser's stack.  Information stored includes:
**
**   +  The state number for the parser at this level of the stack.
**
**   +  The value of the token stored at this level of the stack.
**      (In other words, the "major" token.)
**
**   +  The semantic value stored at this level of the stack.  This is
**      the information used by the action routines in the grammar.
**      It is sometimes called the "minor" token.
**
** After the "shift" half of a SHIFTREDUCE action, the stateno field
** actually contains the reduce action for the second half of the
** SHIFTREDUCE.
*/
struct yyStackEntry {
  YYACTIONTYPE stateno;  /* The state-number, or reduce action in SHIFTREDUCE */
  YYCODETYPE major;      /* The major token value.  This is the code
                         ** number for the token at this stack level */
  YYMINORTYPE minor;     /* The user-supplied minor token value.  This
                         ** is the value of the token  */
};
typedef struct yyStackEntry yyStackEntry;

/* The state of the parser is completely contained in an instance of
** the following structure */
struct yyParser {
  yyStackEntry *yytos;          /* Pointer to top element of the stack */
#ifdef YYTRACKMAXSTACKDEPTH
  int yyhwm;                    /* High-water mark of the stack */
#endif
#ifndef YYNOERRORRECOVERY
  int yyerrcnt;                 /* Shifts left before out of the error */
#endif
  ParseARG_SDECL                /* A place to hold %extra_argument */
#if YYSTACKDEPTH<=0
  int yystksz;                  /* Current side of the stack */
  yyStackEntry *yystack;        /* The parser's stack */
  yyStackEntry yystk0;          /* First stack entry */
#else
  yyStackEntry yystack[YYSTACKDEPTH];  /* The parser's stack */
  yyStackEntry *yystackEnd;            /* Last entry in the stack */
#endif
};
typedef struct yyParser yyParser;

#ifndef NDEBUG
#include <stdio.h>
static FILE *yyTraceFILE = 0;
static char *yyTracePrompt = 0;
#endif /* NDEBUG */

#ifndef NDEBUG
/* 
** Turn parser tracing on by giving a stream to which to write the trace
** and a prompt to preface each trace message.  Tracing is turned off
** by making either argument NULL 
**
** Inputs:
** <ul>
** <li> A FILE* to which trace output should be written.
**      If NULL, then tracing is turned off.
** <li> A prefix string written at the beginning of every
**      line of trace output.  If NULL, then tracing is
**      turned off.
** </ul>
**
** Outputs:
** None.
*/
void ParseTrace(FILE *TraceFILE, char *zTracePrompt){
  yyTraceFILE = TraceFILE;
  yyTracePrompt = zTracePrompt;
  if( yyTraceFILE==0 ) yyTracePrompt = 0;
  else if( yyTracePrompt==0 ) yyTraceFILE = 0;
}
#endif /* NDEBUG */

#if defined(YYCOVERAGE) || !defined(NDEBUG)
/* For tracing shifts, the names of all terminals and nonterminals
** are required.  The following table supplies these names */
static const char *const yyTokenName[] = { 
  /*    0 */ "$",
  /*    1 */ "OR",
  /*    2 */ "AND",
  /*    3 */ "ADD",
  /*    4 */ "DASH",
  /*    5 */ "MUL",
  /*    6 */ "DIV",
  /*    7 */ "EQ",
  /*    8 */ "GT",
  /*    9 */ "GE",
  /*   10 */ "LT",
  /*   11 */ "LE",
  /*   12 */ "MATCH",
  /*   13 */ "CREATE",
  /*   14 */ "INDEX",
  /*   15 */ "ON",
  /*   16 */ "DROP",
  /*   17 */ "COLON",
  /*   18 */ "UQSTRING",
  /*   19 */ "LEFT_PARENTHESIS",
  /*   20 */ "RIGHT_PARENTHESIS",
  /*   21 */ "MERGE",
  /*   22 */ "SET",
  /*   23 */ "COMMA",
  /*   24 */ "DELETE",
  /*   25 */ "RIGHT_ARROW",
  /*   26 */ "LEFT_ARROW",
  /*   27 */ "LEFT_BRACKET",
  /*   28 */ "RIGHT_BRACKET",
  /*   29 */ "PIPE",
  /*   30 */ "INTEGER",
  /*   31 */ "DOTDOT",
  /*   32 */ "LEFT_CURLY_BRACKET",
  /*   33 */ "RIGHT_CURLY_BRACKET",
  /*   34 */ "WHERE",
  /*   35 */ "RETURN",
  /*   36 */ "DISTINCT",
  /*   37 */ "AS",
  /*   38 */ "DOT",
  /*   39 */ "ORDER",
  /*   40 */ "BY",
  /*   41 */ "ASC",
  /*   42 */ "DESC",
  /*   43 */ "SKIP",
  /*   44 */ "LIMIT",
  /*   45 */ "UNWIND",
  /*   46 */ "NE",
  /*   47 */ "STRING",
  /*   48 */ "FLOAT",
  /*   49 */ "TRUE",
  /*   50 */ "FALSE",
  /*   51 */ "NULLVAL",
  /*   52 */ "error",
  /*   53 */ "expr",
  /*   54 */ "query",
  /*   55 */ "multipleMatchClause",
  /*   56 */ "whereClause",
  /*   57 */ "multipleCreateClause",
  /*   58 */ "returnClause",
  /*   59 */ "orderClause",
  /*   60 */ "skipClause",
  /*   61 */ "limitClause",
  /*   62 */ "deleteClause",
  /*   63 */ "setClause",
  /*   64 */ "unwindClause",
  /*   65 */ "indexClause",
  /*   66 */ "mergeClause",
  /*   67 */ "matchClauses",
  /*   68 */ "matchClause",
  /*   69 */ "chains",
  /*   70 */ "createClauses",
  /*   71 */ "createClause",
  /*   72 */ "indexOpToken",
  /*   73 */ "indexLabel",
  /*   74 */ "indexProp",
  /*   75 */ "chain",
  /*   76 */ "setList",
  /*   77 */ "setElement",
  /*   78 */ "variable",
  /*   79 */ "arithmetic_expression",
  /*   80 */ "node",
  /*   81 */ "link",
  /*   82 */ "deleteExpression",
  /*   83 */ "properties",
  /*   84 */ "edge",
  /*   85 */ "edgeLength",
  /*   86 */ "edgeLabels",
  /*   87 */ "edgeLabel",
  /*   88 */ "mapLiteral",
  /*   89 */ "value",
  /*   90 */ "cond",
  /*   91 */ "relation",
  /*   92 */ "returnElements",
  /*   93 */ "returnElement",
  /*   94 */ "arithmetic_expression_list",
};
#endif /* defined(YYCOVERAGE) || !defined(NDEBUG) */

#ifndef NDEBUG
/* For tracing reduce actions, the names of all rules are required.
*/
static const char *const yyRuleName[] = {
 /*   0 */ "query ::= expr",
 /*   1 */ "expr ::= multipleMatchClause whereClause multipleCreateClause returnClause orderClause skipClause limitClause",
 /*   2 */ "expr ::= multipleMatchClause whereClause multipleCreateClause",
 /*   3 */ "expr ::= multipleMatchClause whereClause deleteClause",
 /*   4 */ "expr ::= multipleMatchClause whereClause setClause",
 /*   5 */ "expr ::= multipleMatchClause whereClause setClause returnClause orderClause skipClause limitClause",
 /*   6 */ "expr ::= multipleCreateClause",
 /*   7 */ "expr ::= unwindClause multipleCreateClause",
 /*   8 */ "expr ::= indexClause",
 /*   9 */ "expr ::= mergeClause",
 /*  10 */ "expr ::= returnClause",
 /*  11 */ "expr ::= unwindClause returnClause skipClause limitClause",
 /*  12 */ "multipleMatchClause ::= matchClauses",
 /*  13 */ "matchClauses ::= matchClause",
 /*  14 */ "matchClauses ::= matchClauses matchClause",
 /*  15 */ "matchClause ::= MATCH chains",
 /*  16 */ "multipleCreateClause ::=",
 /*  17 */ "multipleCreateClause ::= createClauses",
 /*  18 */ "createClauses ::= createClause",
 /*  19 */ "createClauses ::= createClauses createClause",
 /*  20 */ "createClause ::= CREATE chains",
 /*  21 */ "indexClause ::= indexOpToken INDEX ON indexLabel indexProp",
 /*  22 */ "indexOpToken ::= CREATE",
 /*  23 */ "indexOpToken ::= DROP",
 /*  24 */ "indexLabel ::= COLON UQSTRING",
 /*  25 */ "indexProp ::= LEFT_PARENTHESIS UQSTRING RIGHT_PARENTHESIS",
 /*  26 */ "mergeClause ::= MERGE chain",
 /*  27 */ "setClause ::= SET setList",
 /*  28 */ "setList ::= setElement",
 /*  29 */ "setList ::= setList COMMA setElement",
 /*  30 */ "setElement ::= variable EQ arithmetic_expression",
 /*  31 */ "chain ::= node",
 /*  32 */ "chain ::= chain link node",
 /*  33 */ "chains ::= chain",
 /*  34 */ "chains ::= chains COMMA chain",
 /*  35 */ "deleteClause ::= DELETE deleteExpression",
 /*  36 */ "deleteExpression ::= UQSTRING",
 /*  37 */ "deleteExpression ::= deleteExpression COMMA UQSTRING",
 /*  38 */ "node ::= LEFT_PARENTHESIS UQSTRING COLON UQSTRING properties RIGHT_PARENTHESIS",
 /*  39 */ "node ::= LEFT_PARENTHESIS COLON UQSTRING properties RIGHT_PARENTHESIS",
 /*  40 */ "node ::= LEFT_PARENTHESIS UQSTRING properties RIGHT_PARENTHESIS",
 /*  41 */ "node ::= LEFT_PARENTHESIS properties RIGHT_PARENTHESIS",
 /*  42 */ "link ::= DASH edge RIGHT_ARROW",
 /*  43 */ "link ::= LEFT_ARROW edge DASH",
 /*  44 */ "edge ::= LEFT_BRACKET properties edgeLength RIGHT_BRACKET",
 /*  45 */ "edge ::= LEFT_BRACKET UQSTRING properties RIGHT_BRACKET",
 /*  46 */ "edge ::= LEFT_BRACKET edgeLabels edgeLength properties RIGHT_BRACKET",
 /*  47 */ "edge ::= LEFT_BRACKET UQSTRING edgeLabels properties RIGHT_BRACKET",
 /*  48 */ "edgeLabel ::= COLON UQSTRING",
 /*  49 */ "edgeLabels ::= edgeLabel",
 /*  50 */ "edgeLabels ::= edgeLabels PIPE edgeLabel",
 /*  51 */ "edgeLength ::=",
 /*  52 */ "edgeLength ::= MUL INTEGER DOTDOT INTEGER",
 /*  53 */ "edgeLength ::= MUL INTEGER DOTDOT",
 /*  54 */ "edgeLength ::= MUL DOTDOT INTEGER",
 /*  55 */ "edgeLength ::= MUL INTEGER",
 /*  56 */ "edgeLength ::= MUL",
 /*  57 */ "properties ::=",
 /*  58 */ "properties ::= LEFT_CURLY_BRACKET mapLiteral RIGHT_CURLY_BRACKET",
 /*  59 */ "mapLiteral ::= UQSTRING COLON value",
 /*  60 */ "mapLiteral ::= UQSTRING COLON value COMMA mapLiteral",
 /*  61 */ "whereClause ::=",
 /*  62 */ "whereClause ::= WHERE cond",
 /*  63 */ "cond ::= arithmetic_expression relation arithmetic_expression",
 /*  64 */ "cond ::= LEFT_PARENTHESIS cond RIGHT_PARENTHESIS",
 /*  65 */ "cond ::= cond AND cond",
 /*  66 */ "cond ::= cond OR cond",
 /*  67 */ "returnClause ::= RETURN returnElements",
 /*  68 */ "returnClause ::= RETURN DISTINCT returnElements",
 /*  69 */ "returnElements ::= returnElements COMMA returnElement",
 /*  70 */ "returnElements ::= returnElement",
 /*  71 */ "returnElement ::= MUL",
 /*  72 */ "returnElement ::= arithmetic_expression",
 /*  73 */ "returnElement ::= arithmetic_expression AS UQSTRING",
 /*  74 */ "arithmetic_expression ::= LEFT_PARENTHESIS arithmetic_expression RIGHT_PARENTHESIS",
 /*  75 */ "arithmetic_expression ::= arithmetic_expression ADD arithmetic_expression",
 /*  76 */ "arithmetic_expression ::= arithmetic_expression DASH arithmetic_expression",
 /*  77 */ "arithmetic_expression ::= arithmetic_expression MUL arithmetic_expression",
 /*  78 */ "arithmetic_expression ::= arithmetic_expression DIV arithmetic_expression",
 /*  79 */ "arithmetic_expression ::= UQSTRING LEFT_PARENTHESIS arithmetic_expression_list RIGHT_PARENTHESIS",
 /*  80 */ "arithmetic_expression ::= value",
 /*  81 */ "arithmetic_expression ::= variable",
 /*  82 */ "arithmetic_expression_list ::= arithmetic_expression_list COMMA arithmetic_expression",
 /*  83 */ "arithmetic_expression_list ::= arithmetic_expression",
 /*  84 */ "variable ::= UQSTRING",
 /*  85 */ "variable ::= UQSTRING DOT UQSTRING",
 /*  86 */ "orderClause ::=",
 /*  87 */ "orderClause ::= ORDER BY arithmetic_expression_list",
 /*  88 */ "orderClause ::= ORDER BY arithmetic_expression_list ASC",
 /*  89 */ "orderClause ::= ORDER BY arithmetic_expression_list DESC",
 /*  90 */ "skipClause ::=",
 /*  91 */ "skipClause ::= SKIP INTEGER",
 /*  92 */ "limitClause ::=",
 /*  93 */ "limitClause ::= LIMIT INTEGER",
 /*  94 */ "unwindClause ::= UNWIND LEFT_BRACKET arithmetic_expression_list RIGHT_BRACKET AS UQSTRING",
 /*  95 */ "relation ::= EQ",
 /*  96 */ "relation ::= GT",
 /*  97 */ "relation ::= LT",
 /*  98 */ "relation ::= LE",
 /*  99 */ "relation ::= GE",
 /* 100 */ "relation ::= NE",
 /* 101 */ "value ::= INTEGER",
 /* 102 */ "value ::= DASH INTEGER",
 /* 103 */ "value ::= STRING",
 /* 104 */ "value ::= FLOAT",
 /* 105 */ "value ::= DASH FLOAT",
 /* 106 */ "value ::= TRUE",
 /* 107 */ "value ::= FALSE",
 /* 108 */ "value ::= NULLVAL",
};
#endif /* NDEBUG */


#if YYSTACKDEPTH<=0
/*
** Try to increase the size of the parser stack.  Return the number
** of errors.  Return 0 on success.
*/
static int yyGrowStack(yyParser *p){
  int newSize;
  int idx;
  yyStackEntry *pNew;

  newSize = p->yystksz*2 + 100;
  idx = p->yytos ? (int)(p->yytos - p->yystack) : 0;
  if( p->yystack==&p->yystk0 ){
    pNew = malloc(newSize*sizeof(pNew[0]));
    if( pNew ) pNew[0] = p->yystk0;
  }else{
    pNew = realloc(p->yystack, newSize*sizeof(pNew[0]));
  }
  if( pNew ){
    p->yystack = pNew;
    p->yytos = &p->yystack[idx];
#ifndef NDEBUG
    if( yyTraceFILE ){
      fprintf(yyTraceFILE,"%sStack grows from %d to %d entries.\n",
              yyTracePrompt, p->yystksz, newSize);
    }
#endif
    p->yystksz = newSize;
  }
  return pNew==0; 
}
#endif

/* Datatype of the argument to the memory allocated passed as the
** second argument to ParseAlloc() below.  This can be changed by
** putting an appropriate #define in the %include section of the input
** grammar.
*/
#ifndef YYMALLOCARGTYPE
# define YYMALLOCARGTYPE size_t
#endif

/* Initialize a new parser that has already been allocated.
*/
void ParseInit(void *yypParser){
  yyParser *pParser = (yyParser*)yypParser;
#ifdef YYTRACKMAXSTACKDEPTH
  pParser->yyhwm = 0;
#endif
#if YYSTACKDEPTH<=0
  pParser->yytos = NULL;
  pParser->yystack = NULL;
  pParser->yystksz = 0;
  if( yyGrowStack(pParser) ){
    pParser->yystack = &pParser->yystk0;
    pParser->yystksz = 1;
  }
#endif
#ifndef YYNOERRORRECOVERY
  pParser->yyerrcnt = -1;
#endif
  pParser->yytos = pParser->yystack;
  pParser->yystack[0].stateno = 0;
  pParser->yystack[0].major = 0;
#if YYSTACKDEPTH>0
  pParser->yystackEnd = &pParser->yystack[YYSTACKDEPTH-1];
#endif
}

#ifndef Parse_ENGINEALWAYSONSTACK
/* 
** This function allocates a new parser.
** The only argument is a pointer to a function which works like
** malloc.
**
** Inputs:
** A pointer to the function used to allocate memory.
**
** Outputs:
** A pointer to a parser.  This pointer is used in subsequent calls
** to Parse and ParseFree.
*/
void *ParseAlloc(void *(*mallocProc)(YYMALLOCARGTYPE)){
  yyParser *pParser;
  pParser = (yyParser*)(*mallocProc)( (YYMALLOCARGTYPE)sizeof(yyParser) );
  if( pParser ) ParseInit(pParser);
  return pParser;
}
#endif /* Parse_ENGINEALWAYSONSTACK */


/* The following function deletes the "minor type" or semantic value
** associated with a symbol.  The symbol can be either a terminal
** or nonterminal. "yymajor" is the symbol code, and "yypminor" is
** a pointer to the value to be deleted.  The code used to do the 
** deletions is derived from the %destructor and/or %token_destructor
** directives of the input grammar.
*/
static void yy_destructor(
  yyParser *yypParser,    /* The parser */
  YYCODETYPE yymajor,     /* Type code for object to destroy */
  YYMINORTYPE *yypminor   /* The object to be destroyed */
){
  ParseARG_FETCH;
  switch( yymajor ){
    /* Here is inserted the actions which take place when a
    ** terminal or non-terminal is destroyed.  This can happen
    ** when the symbol is popped from the stack during a
    ** reduce or during error processing or when a parser is 
    ** being destroyed before it is finished parsing.
    **
    ** Note: during a reduce, the only symbols destroyed are those
    ** which appear on the RHS of the rule, but which are *not* used
    ** inside the C code.
    */
/********* Begin destructor definitions ***************************************/
    case 90: /* cond */
{
#line 389 "grammar.y"
 Free_AST_FilterNode((yypminor->yy86)); 
#line 792 "grammar.c"
}
      break;
/********* End destructor definitions *****************************************/
    default:  break;   /* If no destructor action specified: do nothing */
  }
}

/*
** Pop the parser's stack once.
**
** If there is a destructor routine associated with the token which
** is popped from the stack, then call it.
*/
static void yy_pop_parser_stack(yyParser *pParser){
  yyStackEntry *yytos;
  assert( pParser->yytos!=0 );
  assert( pParser->yytos > pParser->yystack );
  yytos = pParser->yytos--;
#ifndef NDEBUG
  if( yyTraceFILE ){
    fprintf(yyTraceFILE,"%sPopping %s\n",
      yyTracePrompt,
      yyTokenName[yytos->major]);
  }
#endif
  yy_destructor(pParser, yytos->major, &yytos->minor);
}

/*
** Clear all secondary memory allocations from the parser
*/
void ParseFinalize(void *p){
  yyParser *pParser = (yyParser*)p;
  while( pParser->yytos>pParser->yystack ) yy_pop_parser_stack(pParser);
#if YYSTACKDEPTH<=0
  if( pParser->yystack!=&pParser->yystk0 ) free(pParser->yystack);
#endif
}

#ifndef Parse_ENGINEALWAYSONSTACK
/* 
** Deallocate and destroy a parser.  Destructors are called for
** all stack elements before shutting the parser down.
**
** If the YYPARSEFREENEVERNULL macro exists (for example because it
** is defined in a %include section of the input grammar) then it is
** assumed that the input pointer is never NULL.
*/
void ParseFree(
  void *p,                    /* The parser to be deleted */
  void (*freeProc)(void*)     /* Function used to reclaim memory */
){
#ifndef YYPARSEFREENEVERNULL
  if( p==0 ) return;
#endif
  ParseFinalize(p);
  (*freeProc)(p);
}
#endif /* Parse_ENGINEALWAYSONSTACK */

/*
** Return the peak depth of the stack for a parser.
*/
#ifdef YYTRACKMAXSTACKDEPTH
int ParseStackPeak(void *p){
  yyParser *pParser = (yyParser*)p;
  return pParser->yyhwm;
}
#endif

/* This array of booleans keeps track of the parser statement
** coverage.  The element yycoverage[X][Y] is set when the parser
** is in state X and has a lookahead token Y.  In a well-tested
** systems, every element of this matrix should end up being set.
*/
#if defined(YYCOVERAGE)
static unsigned char yycoverage[YYNSTATE][YYNTOKEN];
#endif

/*
** Write into out a description of every state/lookahead combination that
**
**   (1)  has not been used by the parser, and
**   (2)  is not a syntax error.
**
** Return the number of missed state/lookahead combinations.
*/
#if defined(YYCOVERAGE)
int ParseCoverage(FILE *out){
  int stateno, iLookAhead, i;
  int nMissed = 0;
  for(stateno=0; stateno<YYNSTATE; stateno++){
    i = yy_shift_ofst[stateno];
    for(iLookAhead=0; iLookAhead<YYNTOKEN; iLookAhead++){
      if( yy_lookahead[i+iLookAhead]!=iLookAhead ) continue;
      if( yycoverage[stateno][iLookAhead]==0 ) nMissed++;
      if( out ){
        fprintf(out,"State %d lookahead %s %s\n", stateno,
                yyTokenName[iLookAhead],
                yycoverage[stateno][iLookAhead] ? "ok" : "missed");
      }
    }
  }
  return nMissed;
}
#endif

/*
** Find the appropriate action for a parser given the terminal
** look-ahead token iLookAhead.
*/
static unsigned int yy_find_shift_action(
  yyParser *pParser,        /* The parser */
  YYCODETYPE iLookAhead     /* The look-ahead token */
){
  int i;
  int stateno = pParser->yytos->stateno;
 
  if( stateno>YY_MAX_SHIFT ) return stateno;
  assert( stateno <= YY_SHIFT_COUNT );
#if defined(YYCOVERAGE)
  yycoverage[stateno][iLookAhead] = 1;
#endif
  do{
    i = yy_shift_ofst[stateno];
    assert( i>=0 );
    assert( i+YYNTOKEN<=(int)sizeof(yy_lookahead)/sizeof(yy_lookahead[0]) );
    assert( iLookAhead!=YYNOCODE );
    assert( iLookAhead < YYNTOKEN );
    i += iLookAhead;
    if( yy_lookahead[i]!=iLookAhead ){
#ifdef YYFALLBACK
      YYCODETYPE iFallback;            /* Fallback token */
      if( iLookAhead<sizeof(yyFallback)/sizeof(yyFallback[0])
             && (iFallback = yyFallback[iLookAhead])!=0 ){
#ifndef NDEBUG
        if( yyTraceFILE ){
          fprintf(yyTraceFILE, "%sFALLBACK %s => %s\n",
             yyTracePrompt, yyTokenName[iLookAhead], yyTokenName[iFallback]);
        }
#endif
        assert( yyFallback[iFallback]==0 ); /* Fallback loop must terminate */
        iLookAhead = iFallback;
        continue;
      }
#endif
#ifdef YYWILDCARD
      {
        int j = i - iLookAhead + YYWILDCARD;
        if( 
#if YY_SHIFT_MIN+YYWILDCARD<0
          j>=0 &&
#endif
#if YY_SHIFT_MAX+YYWILDCARD>=YY_ACTTAB_COUNT
          j<YY_ACTTAB_COUNT &&
#endif
          yy_lookahead[j]==YYWILDCARD && iLookAhead>0
        ){
#ifndef NDEBUG
          if( yyTraceFILE ){
            fprintf(yyTraceFILE, "%sWILDCARD %s => %s\n",
               yyTracePrompt, yyTokenName[iLookAhead],
               yyTokenName[YYWILDCARD]);
          }
#endif /* NDEBUG */
          return yy_action[j];
        }
      }
#endif /* YYWILDCARD */
      return yy_default[stateno];
    }else{
      return yy_action[i];
    }
  }while(1);
}

/*
** Find the appropriate action for a parser given the non-terminal
** look-ahead token iLookAhead.
*/
static int yy_find_reduce_action(
  int stateno,              /* Current state number */
  YYCODETYPE iLookAhead     /* The look-ahead token */
){
  int i;
#ifdef YYERRORSYMBOL
  if( stateno>YY_REDUCE_COUNT ){
    return yy_default[stateno];
  }
#else
  assert( stateno<=YY_REDUCE_COUNT );
#endif
  i = yy_reduce_ofst[stateno];
  assert( iLookAhead!=YYNOCODE );
  i += iLookAhead;
#ifdef YYERRORSYMBOL
  if( i<0 || i>=YY_ACTTAB_COUNT || yy_lookahead[i]!=iLookAhead ){
    return yy_default[stateno];
  }
#else
  assert( i>=0 && i<YY_ACTTAB_COUNT );
  assert( yy_lookahead[i]==iLookAhead );
#endif
  return yy_action[i];
}

/*
** The following routine is called if the stack overflows.
*/
static void yyStackOverflow(yyParser *yypParser){
   ParseARG_FETCH;
#ifndef NDEBUG
   if( yyTraceFILE ){
     fprintf(yyTraceFILE,"%sStack Overflow!\n",yyTracePrompt);
   }
#endif
   while( yypParser->yytos>yypParser->yystack ) yy_pop_parser_stack(yypParser);
   /* Here code is inserted which will execute if the parser
   ** stack every overflows */
/******** Begin %stack_overflow code ******************************************/
/******** End %stack_overflow code ********************************************/
   ParseARG_STORE; /* Suppress warning about unused %extra_argument var */
}

/*
** Print tracing information for a SHIFT action
*/
#ifndef NDEBUG
static void yyTraceShift(yyParser *yypParser, int yyNewState, const char *zTag){
  if( yyTraceFILE ){
    if( yyNewState<YYNSTATE ){
      fprintf(yyTraceFILE,"%s%s '%s', go to state %d\n",
         yyTracePrompt, zTag, yyTokenName[yypParser->yytos->major],
         yyNewState);
    }else{
      fprintf(yyTraceFILE,"%s%s '%s', pending reduce %d\n",
         yyTracePrompt, zTag, yyTokenName[yypParser->yytos->major],
         yyNewState - YY_MIN_REDUCE);
    }
  }
}
#else
# define yyTraceShift(X,Y,Z)
#endif

/*
** Perform a shift action.
*/
static void yy_shift(
  yyParser *yypParser,          /* The parser to be shifted */
  int yyNewState,               /* The new state to shift in */
  int yyMajor,                  /* The major token to shift in */
  ParseTOKENTYPE yyMinor        /* The minor token to shift in */
){
  yyStackEntry *yytos;
  yypParser->yytos++;
#ifdef YYTRACKMAXSTACKDEPTH
  if( (int)(yypParser->yytos - yypParser->yystack)>yypParser->yyhwm ){
    yypParser->yyhwm++;
    assert( yypParser->yyhwm == (int)(yypParser->yytos - yypParser->yystack) );
  }
#endif
#if YYSTACKDEPTH>0 
  if( yypParser->yytos>yypParser->yystackEnd ){
    yypParser->yytos--;
    yyStackOverflow(yypParser);
    return;
  }
#else
  if( yypParser->yytos>=&yypParser->yystack[yypParser->yystksz] ){
    if( yyGrowStack(yypParser) ){
      yypParser->yytos--;
      yyStackOverflow(yypParser);
      return;
    }
  }
#endif
  if( yyNewState > YY_MAX_SHIFT ){
    yyNewState += YY_MIN_REDUCE - YY_MIN_SHIFTREDUCE;
  }
  yytos = yypParser->yytos;
  yytos->stateno = (YYACTIONTYPE)yyNewState;
  yytos->major = (YYCODETYPE)yyMajor;
  yytos->minor.yy0 = yyMinor;
  yyTraceShift(yypParser, yyNewState, "Shift");
}

/* The following table contains information about every rule that
** is used during the reduce.
*/
static const struct {
  YYCODETYPE lhs;       /* Symbol on the left-hand side of the rule */
  signed char nrhs;     /* Negative of the number of RHS symbols in the rule */
} yyRuleInfo[] = {
  {   54,   -1 }, /* (0) query ::= expr */
  {   53,   -7 }, /* (1) expr ::= multipleMatchClause whereClause multipleCreateClause returnClause orderClause skipClause limitClause */
  {   53,   -3 }, /* (2) expr ::= multipleMatchClause whereClause multipleCreateClause */
  {   53,   -3 }, /* (3) expr ::= multipleMatchClause whereClause deleteClause */
  {   53,   -3 }, /* (4) expr ::= multipleMatchClause whereClause setClause */
  {   53,   -7 }, /* (5) expr ::= multipleMatchClause whereClause setClause returnClause orderClause skipClause limitClause */
  {   53,   -1 }, /* (6) expr ::= multipleCreateClause */
  {   53,   -2 }, /* (7) expr ::= unwindClause multipleCreateClause */
  {   53,   -1 }, /* (8) expr ::= indexClause */
  {   53,   -1 }, /* (9) expr ::= mergeClause */
  {   53,   -1 }, /* (10) expr ::= returnClause */
  {   53,   -4 }, /* (11) expr ::= unwindClause returnClause skipClause limitClause */
  {   55,   -1 }, /* (12) multipleMatchClause ::= matchClauses */
  {   67,   -1 }, /* (13) matchClauses ::= matchClause */
  {   67,   -2 }, /* (14) matchClauses ::= matchClauses matchClause */
  {   68,   -2 }, /* (15) matchClause ::= MATCH chains */
  {   57,    0 }, /* (16) multipleCreateClause ::= */
  {   57,   -1 }, /* (17) multipleCreateClause ::= createClauses */
  {   70,   -1 }, /* (18) createClauses ::= createClause */
  {   70,   -2 }, /* (19) createClauses ::= createClauses createClause */
  {   71,   -2 }, /* (20) createClause ::= CREATE chains */
  {   65,   -5 }, /* (21) indexClause ::= indexOpToken INDEX ON indexLabel indexProp */
  {   72,   -1 }, /* (22) indexOpToken ::= CREATE */
  {   72,   -1 }, /* (23) indexOpToken ::= DROP */
  {   73,   -2 }, /* (24) indexLabel ::= COLON UQSTRING */
  {   74,   -3 }, /* (25) indexProp ::= LEFT_PARENTHESIS UQSTRING RIGHT_PARENTHESIS */
  {   66,   -2 }, /* (26) mergeClause ::= MERGE chain */
  {   63,   -2 }, /* (27) setClause ::= SET setList */
  {   76,   -1 }, /* (28) setList ::= setElement */
  {   76,   -3 }, /* (29) setList ::= setList COMMA setElement */
  {   77,   -3 }, /* (30) setElement ::= variable EQ arithmetic_expression */
  {   75,   -1 }, /* (31) chain ::= node */
  {   75,   -3 }, /* (32) chain ::= chain link node */
  {   69,   -1 }, /* (33) chains ::= chain */
  {   69,   -3 }, /* (34) chains ::= chains COMMA chain */
  {   62,   -2 }, /* (35) deleteClause ::= DELETE deleteExpression */
  {   82,   -1 }, /* (36) deleteExpression ::= UQSTRING */
  {   82,   -3 }, /* (37) deleteExpression ::= deleteExpression COMMA UQSTRING */
  {   80,   -6 }, /* (38) node ::= LEFT_PARENTHESIS UQSTRING COLON UQSTRING properties RIGHT_PARENTHESIS */
  {   80,   -5 }, /* (39) node ::= LEFT_PARENTHESIS COLON UQSTRING properties RIGHT_PARENTHESIS */
  {   80,   -4 }, /* (40) node ::= LEFT_PARENTHESIS UQSTRING properties RIGHT_PARENTHESIS */
  {   80,   -3 }, /* (41) node ::= LEFT_PARENTHESIS properties RIGHT_PARENTHESIS */
  {   81,   -3 }, /* (42) link ::= DASH edge RIGHT_ARROW */
  {   81,   -3 }, /* (43) link ::= LEFT_ARROW edge DASH */
  {   84,   -4 }, /* (44) edge ::= LEFT_BRACKET properties edgeLength RIGHT_BRACKET */
  {   84,   -4 }, /* (45) edge ::= LEFT_BRACKET UQSTRING properties RIGHT_BRACKET */
  {   84,   -5 }, /* (46) edge ::= LEFT_BRACKET edgeLabels edgeLength properties RIGHT_BRACKET */
  {   84,   -5 }, /* (47) edge ::= LEFT_BRACKET UQSTRING edgeLabels properties RIGHT_BRACKET */
  {   87,   -2 }, /* (48) edgeLabel ::= COLON UQSTRING */
  {   86,   -1 }, /* (49) edgeLabels ::= edgeLabel */
  {   86,   -3 }, /* (50) edgeLabels ::= edgeLabels PIPE edgeLabel */
  {   85,    0 }, /* (51) edgeLength ::= */
  {   85,   -4 }, /* (52) edgeLength ::= MUL INTEGER DOTDOT INTEGER */
  {   85,   -3 }, /* (53) edgeLength ::= MUL INTEGER DOTDOT */
  {   85,   -3 }, /* (54) edgeLength ::= MUL DOTDOT INTEGER */
  {   85,   -2 }, /* (55) edgeLength ::= MUL INTEGER */
  {   85,   -1 }, /* (56) edgeLength ::= MUL */
  {   83,    0 }, /* (57) properties ::= */
  {   83,   -3 }, /* (58) properties ::= LEFT_CURLY_BRACKET mapLiteral RIGHT_CURLY_BRACKET */
  {   88,   -3 }, /* (59) mapLiteral ::= UQSTRING COLON value */
  {   88,   -5 }, /* (60) mapLiteral ::= UQSTRING COLON value COMMA mapLiteral */
  {   56,    0 }, /* (61) whereClause ::= */
  {   56,   -2 }, /* (62) whereClause ::= WHERE cond */
  {   90,   -3 }, /* (63) cond ::= arithmetic_expression relation arithmetic_expression */
  {   90,   -3 }, /* (64) cond ::= LEFT_PARENTHESIS cond RIGHT_PARENTHESIS */
  {   90,   -3 }, /* (65) cond ::= cond AND cond */
  {   90,   -3 }, /* (66) cond ::= cond OR cond */
  {   58,   -2 }, /* (67) returnClause ::= RETURN returnElements */
  {   58,   -3 }, /* (68) returnClause ::= RETURN DISTINCT returnElements */
  {   92,   -3 }, /* (69) returnElements ::= returnElements COMMA returnElement */
  {   92,   -1 }, /* (70) returnElements ::= returnElement */
  {   93,   -1 }, /* (71) returnElement ::= MUL */
  {   93,   -1 }, /* (72) returnElement ::= arithmetic_expression */
  {   93,   -3 }, /* (73) returnElement ::= arithmetic_expression AS UQSTRING */
  {   79,   -3 }, /* (74) arithmetic_expression ::= LEFT_PARENTHESIS arithmetic_expression RIGHT_PARENTHESIS */
  {   79,   -3 }, /* (75) arithmetic_expression ::= arithmetic_expression ADD arithmetic_expression */
  {   79,   -3 }, /* (76) arithmetic_expression ::= arithmetic_expression DASH arithmetic_expression */
  {   79,   -3 }, /* (77) arithmetic_expression ::= arithmetic_expression MUL arithmetic_expression */
  {   79,   -3 }, /* (78) arithmetic_expression ::= arithmetic_expression DIV arithmetic_expression */
  {   79,   -4 }, /* (79) arithmetic_expression ::= UQSTRING LEFT_PARENTHESIS arithmetic_expression_list RIGHT_PARENTHESIS */
  {   79,   -1 }, /* (80) arithmetic_expression ::= value */
  {   79,   -1 }, /* (81) arithmetic_expression ::= variable */
  {   94,   -3 }, /* (82) arithmetic_expression_list ::= arithmetic_expression_list COMMA arithmetic_expression */
  {   94,   -1 }, /* (83) arithmetic_expression_list ::= arithmetic_expression */
  {   78,   -1 }, /* (84) variable ::= UQSTRING */
  {   78,   -3 }, /* (85) variable ::= UQSTRING DOT UQSTRING */
  {   59,    0 }, /* (86) orderClause ::= */
  {   59,   -3 }, /* (87) orderClause ::= ORDER BY arithmetic_expression_list */
  {   59,   -4 }, /* (88) orderClause ::= ORDER BY arithmetic_expression_list ASC */
  {   59,   -4 }, /* (89) orderClause ::= ORDER BY arithmetic_expression_list DESC */
  {   60,    0 }, /* (90) skipClause ::= */
  {   60,   -2 }, /* (91) skipClause ::= SKIP INTEGER */
  {   61,    0 }, /* (92) limitClause ::= */
  {   61,   -2 }, /* (93) limitClause ::= LIMIT INTEGER */
  {   64,   -6 }, /* (94) unwindClause ::= UNWIND LEFT_BRACKET arithmetic_expression_list RIGHT_BRACKET AS UQSTRING */
  {   91,   -1 }, /* (95) relation ::= EQ */
  {   91,   -1 }, /* (96) relation ::= GT */
  {   91,   -1 }, /* (97) relation ::= LT */
  {   91,   -1 }, /* (98) relation ::= LE */
  {   91,   -1 }, /* (99) relation ::= GE */
  {   91,   -1 }, /* (100) relation ::= NE */
  {   89,   -1 }, /* (101) value ::= INTEGER */
  {   89,   -2 }, /* (102) value ::= DASH INTEGER */
  {   89,   -1 }, /* (103) value ::= STRING */
  {   89,   -1 }, /* (104) value ::= FLOAT */
  {   89,   -2 }, /* (105) value ::= DASH FLOAT */
  {   89,   -1 }, /* (106) value ::= TRUE */
  {   89,   -1 }, /* (107) value ::= FALSE */
  {   89,   -1 }, /* (108) value ::= NULLVAL */
};

static void yy_accept(yyParser*);  /* Forward Declaration */

/*
** Perform a reduce action and the shift that must immediately
** follow the reduce.
**
** The yyLookahead and yyLookaheadToken parameters provide reduce actions
** access to the lookahead token (if any).  The yyLookahead will be YYNOCODE
** if the lookahead token has already been consumed.  As this procedure is
** only called from one place, optimizing compilers will in-line it, which
** means that the extra parameters have no performance impact.
*/
static void yy_reduce(
  yyParser *yypParser,         /* The parser */
  unsigned int yyruleno,       /* Number of the rule by which to reduce */
  int yyLookahead,             /* Lookahead token, or YYNOCODE if none */
  ParseTOKENTYPE yyLookaheadToken  /* Value of the lookahead token */
){
  int yygoto;                     /* The next state */
  int yyact;                      /* The next action */
  yyStackEntry *yymsp;            /* The top of the parser's stack */
  int yysize;                     /* Amount to pop the stack */
  ParseARG_FETCH;
  (void)yyLookahead;
  (void)yyLookaheadToken;
  yymsp = yypParser->yytos;
#ifndef NDEBUG
  if( yyTraceFILE && yyruleno<(int)(sizeof(yyRuleName)/sizeof(yyRuleName[0])) ){
    yysize = yyRuleInfo[yyruleno].nrhs;
    if( yysize ){
      fprintf(yyTraceFILE, "%sReduce %d [%s], go to state %d.\n",
        yyTracePrompt,
        yyruleno, yyRuleName[yyruleno], yymsp[yysize].stateno);
    }else{
      fprintf(yyTraceFILE, "%sReduce %d [%s].\n",
        yyTracePrompt, yyruleno, yyRuleName[yyruleno]);
    }
  }
#endif /* NDEBUG */

  /* Check that the stack is large enough to grow by a single entry
  ** if the RHS of the rule is empty.  This ensures that there is room
  ** enough on the stack to push the LHS value */
  if( yyRuleInfo[yyruleno].nrhs==0 ){
#ifdef YYTRACKMAXSTACKDEPTH
    if( (int)(yypParser->yytos - yypParser->yystack)>yypParser->yyhwm ){
      yypParser->yyhwm++;
      assert( yypParser->yyhwm == (int)(yypParser->yytos - yypParser->yystack));
    }
#endif
#if YYSTACKDEPTH>0 
    if( yypParser->yytos>=yypParser->yystackEnd ){
      yyStackOverflow(yypParser);
      return;
    }
#else
    if( yypParser->yytos>=&yypParser->yystack[yypParser->yystksz-1] ){
      if( yyGrowStack(yypParser) ){
        yyStackOverflow(yypParser);
        return;
      }
      yymsp = yypParser->yytos;
    }
#endif
  }

  switch( yyruleno ){
  /* Beginning here are the reduction cases.  A typical example
  ** follows:
  **   case 0:
  **  #line <lineno> <grammarfile>
  **     { ... }           // User supplied code
  **  #line <lineno> <thisfile>
  **     break;
  */
/********** Begin reduce actions **********************************************/
        YYMINORTYPE yylhsminor;
      case 0: /* query ::= expr */
#line 45 "grammar.y"
{ ctx->root = yymsp[0].minor.yy67; }
#line 1278 "grammar.c"
        break;
      case 1: /* expr ::= multipleMatchClause whereClause multipleCreateClause returnClause orderClause skipClause limitClause */
#line 47 "grammar.y"
{
	yylhsminor.yy67 = AST_New(yymsp[-6].minor.yy155, yymsp[-5].minor.yy181, yymsp[-4].minor.yy96, NULL, NULL, NULL, yymsp[-3].minor.yy188, yymsp[-2].minor.yy28, yymsp[-1].minor.yy173, yymsp[0].minor.yy77, NULL, NULL);
}
#line 1285 "grammar.c"
  yymsp[-6].minor.yy67 = yylhsminor.yy67;
        break;
      case 2: /* expr ::= multipleMatchClause whereClause multipleCreateClause */
#line 51 "grammar.y"
{
	yylhsminor.yy67 = AST_New(yymsp[-2].minor.yy155, yymsp[-1].minor.yy181, yymsp[0].minor.yy96, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL);
}
#line 1293 "grammar.c"
  yymsp[-2].minor.yy67 = yylhsminor.yy67;
        break;
      case 3: /* expr ::= multipleMatchClause whereClause deleteClause */
#line 55 "grammar.y"
{
	yylhsminor.yy67 = AST_New(yymsp[-2].minor.yy155, yymsp[-1].minor.yy181, NULL, NULL, NULL, yymsp[0].minor.yy115, NULL, NULL, NULL, NULL, NULL, NULL);
}
#line 1301 "grammar.c"
  yymsp[-2].minor.yy67 = yylhsminor.yy67;
        break;
      case 4: /* expr ::= multipleMatchClause whereClause setClause */
#line 59 "grammar.y"
{
	yylhsminor.yy67 = AST_New(yymsp[-2].minor.yy155, yymsp[-1].minor.yy181, NULL, NULL, yymsp[0].minor.yy130, NULL, NULL, NULL, NULL, NULL, NULL, NULL);
}
#line 1309 "grammar.c"
  yymsp[-2].minor.yy67 = yylhsminor.yy67;
        break;
      case 5: /* expr ::= multipleMatchClause whereClause setClause returnClause orderClause skipClause limitClause */
#line 63 "grammar.y"
{
	yylhsminor.yy67 = AST_New(yymsp[-6].minor.yy155, yymsp[-5].minor.yy181, NULL, NULL, yymsp[-4].minor.yy130, NULL, yymsp[-3].minor.yy188, yymsp[-2].minor.yy28, yymsp[-1].minor.yy173, yymsp[0].minor.yy77, NULL, NULL);
}
#line 1317 "grammar.c"
  yymsp[-6].minor.yy67 = yylhsminor.yy67;
        break;
      case 6: /* expr ::= multipleCreateClause */
#line 67 "grammar.y"
{
	yylhsminor.yy67 = AST_New(NULL, NULL, yymsp[0].minor.yy96, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL);
}
#line 1325 "grammar.c"
  yymsp[0].minor.yy67 = yylhsminor.yy67;
        break;
      case 7: /* expr ::= unwindClause multipleCreateClause */
#line 71 "grammar.y"
{
	yylhsminor.yy67 = AST_New(NULL, NULL, yymsp[0].minor.yy96, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, yymsp[-1].minor.yy137);
}
#line 1333 "grammar.c"
  yymsp[-1].minor.yy67 = yylhsminor.yy67;
        break;
      case 8: /* expr ::= indexClause */
#line 75 "grammar.y"
{
	yylhsminor.yy67 = AST_New(NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, yymsp[0].minor.yy74, NULL);
}
#line 1341 "grammar.c"
  yymsp[0].minor.yy67 = yylhsminor.yy67;
        break;
      case 9: /* expr ::= mergeClause */
#line 79 "grammar.y"
{
	yylhsminor.yy67 = AST_New(NULL, NULL, NULL, yymsp[0].minor.yy10, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL);
}
#line 1349 "grammar.c"
  yymsp[0].minor.yy67 = yylhsminor.yy67;
        break;
      case 10: /* expr ::= returnClause */
#line 83 "grammar.y"
{
	yylhsminor.yy67 = AST_New(NULL, NULL, NULL, NULL, NULL, NULL, yymsp[0].minor.yy188, NULL, NULL, NULL, NULL, NULL);
}
#line 1357 "grammar.c"
  yymsp[0].minor.yy67 = yylhsminor.yy67;
        break;
      case 11: /* expr ::= unwindClause returnClause skipClause limitClause */
#line 87 "grammar.y"
{
	yylhsminor.yy67 = AST_New(NULL, NULL, NULL, NULL, NULL, NULL, yymsp[-2].minor.yy188, NULL, yymsp[-1].minor.yy173, yymsp[0].minor.yy77, NULL, yymsp[-3].minor.yy137);
}
#line 1365 "grammar.c"
  yymsp[-3].minor.yy67 = yylhsminor.yy67;
        break;
      case 12: /* multipleMatchClause ::= matchClauses */
#line 92 "grammar.y"
{
	yylhsminor.yy155 = New_AST_MatchNode(yymsp[0].minor.yy116);
}
#line 1373 "grammar.c"
  yymsp[0].minor.yy155 = yylhsminor.yy155;
        break;
      case 13: /* matchClauses ::= matchClause */
      case 18: /* createClauses ::= createClause */ yytestcase(yyruleno==18);
#line 98 "grammar.y"
{
	yylhsminor.yy116 = yymsp[0].minor.yy116;
}
#line 1382 "grammar.c"
  yymsp[0].minor.yy116 = yylhsminor.yy116;
        break;
      case 14: /* matchClauses ::= matchClauses matchClause */
      case 19: /* createClauses ::= createClauses createClause */ yytestcase(yyruleno==19);
#line 102 "grammar.y"
{
	Vector *v;
	while(Vector_Pop(yymsp[0].minor.yy116, &v)) Vector_Push(yymsp[-1].minor.yy116, v);
	Vector_Free(yymsp[0].minor.yy116);
	yylhsminor.yy116 = yymsp[-1].minor.yy116;
}
#line 1394 "grammar.c"
  yymsp[-1].minor.yy116 = yylhsminor.yy116;
        break;
      case 15: /* matchClause ::= MATCH chains */
      case 20: /* createClause ::= CREATE chains */ yytestcase(yyruleno==20);
#line 111 "grammar.y"
{
	yymsp[-1].minor.yy116 = yymsp[0].minor.yy116;
}
#line 1403 "grammar.c"
        break;
      case 16: /* multipleCreateClause ::= */
#line 116 "grammar.y"
{
	yymsp[1].minor.yy96 = NULL;
}
#line 1410 "grammar.c"
        break;
      case 17: /* multipleCreateClause ::= createClauses */
#line 120 "grammar.y"
{
	yylhsminor.yy96 = New_AST_CreateNode(yymsp[0].minor.yy116);
}
#line 1417 "grammar.c"
  yymsp[0].minor.yy96 = yylhsminor.yy96;
        break;
      case 21: /* indexClause ::= indexOpToken INDEX ON indexLabel indexProp */
#line 146 "grammar.y"
{
  yylhsminor.yy74 = New_AST_IndexNode(yymsp[-1].minor.yy0.strval, yymsp[0].minor.yy0.strval, yymsp[-4].minor.yy105);
}
#line 1425 "grammar.c"
  yymsp[-4].minor.yy74 = yylhsminor.yy74;
        break;
      case 22: /* indexOpToken ::= CREATE */
#line 152 "grammar.y"
{ yymsp[0].minor.yy105 = CREATE_INDEX; }
#line 1431 "grammar.c"
        break;
      case 23: /* indexOpToken ::= DROP */
#line 153 "grammar.y"
{ yymsp[0].minor.yy105 = DROP_INDEX; }
#line 1436 "grammar.c"
        break;
      case 24: /* indexLabel ::= COLON UQSTRING */
#line 155 "grammar.y"
{
  yymsp[-1].minor.yy0 = yymsp[0].minor.yy0;
}
#line 1443 "grammar.c"
        break;
      case 25: /* indexProp ::= LEFT_PARENTHESIS UQSTRING RIGHT_PARENTHESIS */
#line 159 "grammar.y"
{
  yymsp[-2].minor.yy0 = yymsp[-1].minor.yy0;
}
#line 1450 "grammar.c"
        break;
      case 26: /* mergeClause ::= MERGE chain */
#line 165 "grammar.y"
{
	yymsp[-1].minor.yy10 = New_AST_MergeNode(yymsp[0].minor.yy116);
}
#line 1457 "grammar.c"
        break;
      case 27: /* setClause ::= SET setList */
#line 170 "grammar.y"
{
	yymsp[-1].minor.yy130 = New_AST_SetNode(yymsp[0].minor.yy116);
}
#line 1464 "grammar.c"
        break;
      case 28: /* setList ::= setElement */
#line 175 "grammar.y"
{
	yylhsminor.yy116 = NewVector(AST_SetElement*, 1);
	Vector_Push(yylhsminor.yy116, yymsp[0].minor.yy124);
}
#line 1472 "grammar.c"
  yymsp[0].minor.yy116 = yylhsminor.yy116;
        break;
      case 29: /* setList ::= setList COMMA setElement */
#line 179 "grammar.y"
{
	Vector_Push(yymsp[-2].minor.yy116, yymsp[0].minor.yy124);
	yylhsminor.yy116 = yymsp[-2].minor.yy116;
}
#line 1481 "grammar.c"
  yymsp[-2].minor.yy116 = yylhsminor.yy116;
        break;
      case 30: /* setElement ::= variable EQ arithmetic_expression */
#line 185 "grammar.y"
{
	yylhsminor.yy124 = New_AST_SetElement(yymsp[-2].minor.yy120, yymsp[0].minor.yy154);
}
#line 1489 "grammar.c"
  yymsp[-2].minor.yy124 = yylhsminor.yy124;
        break;
      case 31: /* chain ::= node */
#line 191 "grammar.y"
{
	yylhsminor.yy116 = NewVector(AST_GraphEntity*, 1);
	Vector_Push(yylhsminor.yy116, yymsp[0].minor.yy89);
}
#line 1498 "grammar.c"
  yymsp[0].minor.yy116 = yylhsminor.yy116;
        break;
      case 32: /* chain ::= chain link node */
#line 196 "grammar.y"
{
	Vector_Push(yymsp[-2].minor.yy116, yymsp[-1].minor.yy35);
	Vector_Push(yymsp[-2].minor.yy116, yymsp[0].minor.yy89);
	yylhsminor.yy116 = yymsp[-2].minor.yy116;
}
#line 1508 "grammar.c"
  yymsp[-2].minor.yy116 = yylhsminor.yy116;
        break;
      case 33: /* chains ::= chain */
#line 204 "grammar.y"
{
	yylhsminor.yy116 = NewVector(Vector*, 1);
	Vector_Push(yylhsminor.yy116, yymsp[0].minor.yy116);
}
#line 1517 "grammar.c"
  yymsp[0].minor.yy116 = yylhsminor.yy116;
        break;
      case 34: /* chains ::= chains COMMA chain */
#line 209 "grammar.y"
{
	Vector_Push(yymsp[-2].minor.yy116, yymsp[0].minor.yy116);
	yylhsminor.yy116 = yymsp[-2].minor.yy116;
}
#line 1526 "grammar.c"
  yymsp[-2].minor.yy116 = yylhsminor.yy116;
        break;
      case 35: /* deleteClause ::= DELETE deleteExpression */
#line 217 "grammar.y"
{
	yymsp[-1].minor.yy115 = New_AST_DeleteNode(yymsp[0].minor.yy116);
}
#line 1534 "grammar.c"
        break;
      case 36: /* deleteExpression ::= UQSTRING */
#line 223 "grammar.y"
{
	yylhsminor.yy116 = NewVector(char*, 1);
	Vector_Push(yylhsminor.yy116, yymsp[0].minor.yy0.strval);
}
#line 1542 "grammar.c"
  yymsp[0].minor.yy116 = yylhsminor.yy116;
        break;
      case 37: /* deleteExpression ::= deleteExpression COMMA UQSTRING */
#line 228 "grammar.y"
{
	Vector_Push(yymsp[-2].minor.yy116, yymsp[0].minor.yy0.strval);
	yylhsminor.yy116 = yymsp[-2].minor.yy116;
}
#line 1551 "grammar.c"
  yymsp[-2].minor.yy116 = yylhsminor.yy116;
        break;
      case 38: /* node ::= LEFT_PARENTHESIS UQSTRING COLON UQSTRING properties RIGHT_PARENTHESIS */
#line 236 "grammar.y"
{
	yymsp[-5].minor.yy89 = New_AST_NodeEntity(yymsp[-4].minor.yy0.strval, yymsp[-2].minor.yy0.strval, yymsp[-1].minor.yy116);
}
#line 1559 "grammar.c"
        break;
      case 39: /* node ::= LEFT_PARENTHESIS COLON UQSTRING properties RIGHT_PARENTHESIS */
#line 241 "grammar.y"
{
	yymsp[-4].minor.yy89 = New_AST_NodeEntity(NULL, yymsp[-2].minor.yy0.strval, yymsp[-1].minor.yy116);
}
#line 1566 "grammar.c"
        break;
      case 40: /* node ::= LEFT_PARENTHESIS UQSTRING properties RIGHT_PARENTHESIS */
#line 246 "grammar.y"
{
	yymsp[-3].minor.yy89 = New_AST_NodeEntity(yymsp[-2].minor.yy0.strval, NULL, yymsp[-1].minor.yy116);
}
#line 1573 "grammar.c"
        break;
      case 41: /* node ::= LEFT_PARENTHESIS properties RIGHT_PARENTHESIS */
#line 251 "grammar.y"
{
	yymsp[-2].minor.yy89 = New_AST_NodeEntity(NULL, NULL, yymsp[-1].minor.yy116);
}
#line 1580 "grammar.c"
        break;
      case 42: /* link ::= DASH edge RIGHT_ARROW */
#line 258 "grammar.y"
{
	yymsp[-2].minor.yy35 = yymsp[-1].minor.yy35;
	yymsp[-2].minor.yy35->direction = N_LEFT_TO_RIGHT;
}
#line 1588 "grammar.c"
        break;
      case 43: /* link ::= LEFT_ARROW edge DASH */
#line 264 "grammar.y"
{
	yymsp[-2].minor.yy35 = yymsp[-1].minor.yy35;
	yymsp[-2].minor.yy35->direction = N_RIGHT_TO_LEFT;
}
#line 1596 "grammar.c"
        break;
      case 44: /* edge ::= LEFT_BRACKET properties edgeLength RIGHT_BRACKET */
#line 271 "grammar.y"
{ 
	yymsp[-3].minor.yy35 = New_AST_LinkEntity(NULL, NULL, yymsp[-2].minor.yy116, N_DIR_UNKNOWN, yymsp[-1].minor.yy140);
}
#line 1603 "grammar.c"
        break;
      case 45: /* edge ::= LEFT_BRACKET UQSTRING properties RIGHT_BRACKET */
#line 276 "grammar.y"
{ 
	yymsp[-3].minor.yy35 = New_AST_LinkEntity(yymsp[-2].minor.yy0.strval, NULL, yymsp[-1].minor.yy116, N_DIR_UNKNOWN, NULL);
}
#line 1610 "grammar.c"
        break;
      case 46: /* edge ::= LEFT_BRACKET edgeLabels edgeLength properties RIGHT_BRACKET */
#line 281 "grammar.y"
{ 
	yymsp[-4].minor.yy35 = New_AST_LinkEntity(NULL, yymsp[-3].minor.yy83, yymsp[-1].minor.yy116, N_DIR_UNKNOWN, yymsp[-2].minor.yy140);
}
#line 1617 "grammar.c"
        break;
      case 47: /* edge ::= LEFT_BRACKET UQSTRING edgeLabels properties RIGHT_BRACKET */
#line 286 "grammar.y"
{ 
	yymsp[-4].minor.yy35 = New_AST_LinkEntity(yymsp[-3].minor.yy0.strval, yymsp[-2].minor.yy83, yymsp[-1].minor.yy116, N_DIR_UNKNOWN, NULL);
}
#line 1624 "grammar.c"
        break;
      case 48: /* edgeLabel ::= COLON UQSTRING */
#line 293 "grammar.y"
{
	yymsp[-1].minor.yy106 = yymsp[0].minor.yy0.strval;
}
#line 1631 "grammar.c"
        break;
      case 49: /* edgeLabels ::= edgeLabel */
#line 298 "grammar.y"
{
	yylhsminor.yy83 = array_new(char*, 1);
	yylhsminor.yy83 = array_append(yylhsminor.yy83, yymsp[0].minor.yy106);
}
#line 1639 "grammar.c"
  yymsp[0].minor.yy83 = yylhsminor.yy83;
        break;
      case 50: /* edgeLabels ::= edgeLabels PIPE edgeLabel */
#line 304 "grammar.y"
{
	char *label = yymsp[0].minor.yy106;
	yymsp[-2].minor.yy83 = array_append(yymsp[-2].minor.yy83, label);
	yylhsminor.yy83 = yymsp[-2].minor.yy83;
}
#line 1649 "grammar.c"
  yymsp[-2].minor.yy83 = yylhsminor.yy83;
        break;
      case 51: /* edgeLength ::= */
#line 313 "grammar.y"
{
	yymsp[1].minor.yy140 = NULL;
}
#line 1657 "grammar.c"
        break;
      case 52: /* edgeLength ::= MUL INTEGER DOTDOT INTEGER */
#line 318 "grammar.y"
{
	yymsp[-3].minor.yy140 = New_AST_LinkLength(yymsp[-2].minor.yy0.intval, yymsp[0].minor.yy0.intval);
}
#line 1664 "grammar.c"
        break;
      case 53: /* edgeLength ::= MUL INTEGER DOTDOT */
#line 323 "grammar.y"
{
	yymsp[-2].minor.yy140 = New_AST_LinkLength(yymsp[-1].minor.yy0.intval, UINT_MAX-2);
}
#line 1671 "grammar.c"
        break;
      case 54: /* edgeLength ::= MUL DOTDOT INTEGER */
#line 328 "grammar.y"
{
	yymsp[-2].minor.yy140 = New_AST_LinkLength(1, yymsp[0].minor.yy0.intval);
}
#line 1678 "grammar.c"
        break;
      case 55: /* edgeLength ::= MUL INTEGER */
#line 333 "grammar.y"
{
	yymsp[-1].minor.yy140 = New_AST_LinkLength(yymsp[0].minor.yy0.intval, yymsp[0].minor.yy0.intval);
}
#line 1685 "grammar.c"
        break;
      case 56: /* edgeLength ::= MUL */
#line 338 "grammar.y"
{
	yymsp[0].minor.yy140 = New_AST_LinkLength(1, UINT_MAX-2);
}
#line 1692 "grammar.c"
        break;
      case 57: /* properties ::= */
#line 344 "grammar.y"
{
	yymsp[1].minor.yy116 = NULL;
}
#line 1699 "grammar.c"
        break;
      case 58: /* properties ::= LEFT_CURLY_BRACKET mapLiteral RIGHT_CURLY_BRACKET */
#line 348 "grammar.y"
{
	yymsp[-2].minor.yy116 = yymsp[-1].minor.yy116;
}
#line 1706 "grammar.c"
        break;
      case 59: /* mapLiteral ::= UQSTRING COLON value */
#line 354 "grammar.y"
{
	yylhsminor.yy116 = NewVector(SIValue*, 2);

	SIValue *key = malloc(sizeof(SIValue));
	*key = SI_ConstStringVal(yymsp[-2].minor.yy0.strval);
	Vector_Push(yylhsminor.yy116, key);

	SIValue *val = malloc(sizeof(SIValue));
	*val = yymsp[0].minor.yy189;
	Vector_Push(yylhsminor.yy116, val);
}
#line 1721 "grammar.c"
  yymsp[-2].minor.yy116 = yylhsminor.yy116;
        break;
      case 60: /* mapLiteral ::= UQSTRING COLON value COMMA mapLiteral */
#line 366 "grammar.y"
{
	SIValue *key = malloc(sizeof(SIValue));
	*key = SI_ConstStringVal(yymsp[-4].minor.yy0.strval);
	Vector_Push(yymsp[0].minor.yy116, key);

	SIValue *val = malloc(sizeof(SIValue));
	*val = yymsp[-2].minor.yy189;
	Vector_Push(yymsp[0].minor.yy116, val);
	
	yylhsminor.yy116 = yymsp[0].minor.yy116;
}
#line 1737 "grammar.c"
  yymsp[-4].minor.yy116 = yylhsminor.yy116;
        break;
      case 61: /* whereClause ::= */
#line 380 "grammar.y"
{ 
	yymsp[1].minor.yy181 = NULL;
}
#line 1745 "grammar.c"
        break;
      case 62: /* whereClause ::= WHERE cond */
#line 383 "grammar.y"
{
	yymsp[-1].minor.yy181 = New_AST_WhereNode(yymsp[0].minor.yy86);
}
#line 1752 "grammar.c"
        break;
      case 63: /* cond ::= arithmetic_expression relation arithmetic_expression */
#line 392 "grammar.y"
{ yylhsminor.yy86 = New_AST_PredicateNode(yymsp[-2].minor.yy154, yymsp[-1].minor.yy122, yymsp[0].minor.yy154); }
#line 1757 "grammar.c"
  yymsp[-2].minor.yy86 = yylhsminor.yy86;
        break;
      case 64: /* cond ::= LEFT_PARENTHESIS cond RIGHT_PARENTHESIS */
#line 394 "grammar.y"
{ yymsp[-2].minor.yy86 = yymsp[-1].minor.yy86; }
#line 1763 "grammar.c"
        break;
      case 65: /* cond ::= cond AND cond */
#line 395 "grammar.y"
{ yylhsminor.yy86 = New_AST_ConditionNode(yymsp[-2].minor.yy86, AND, yymsp[0].minor.yy86); }
#line 1768 "grammar.c"
  yymsp[-2].minor.yy86 = yylhsminor.yy86;
        break;
      case 66: /* cond ::= cond OR cond */
#line 396 "grammar.y"
{ yylhsminor.yy86 = New_AST_ConditionNode(yymsp[-2].minor.yy86, OR, yymsp[0].minor.yy86); }
#line 1774 "grammar.c"
  yymsp[-2].minor.yy86 = yylhsminor.yy86;
        break;
      case 67: /* returnClause ::= RETURN returnElements */
#line 400 "grammar.y"
{
	yymsp[-1].minor.yy188 = New_AST_ReturnNode(yymsp[0].minor.yy66, 0);
}
#line 1782 "grammar.c"
        break;
      case 68: /* returnClause ::= RETURN DISTINCT returnElements */
#line 403 "grammar.y"
{
	yymsp[-2].minor.yy188 = New_AST_ReturnNode(yymsp[0].minor.yy66, 1);
}
#line 1789 "grammar.c"
        break;
      case 69: /* returnElements ::= returnElements COMMA returnElement */
#line 409 "grammar.y"
{
	yylhsminor.yy66 = array_append(yymsp[-2].minor.yy66, yymsp[0].minor.yy34);
}
#line 1796 "grammar.c"
  yymsp[-2].minor.yy66 = yylhsminor.yy66;
        break;
      case 70: /* returnElements ::= returnElement */
#line 413 "grammar.y"
{
	yylhsminor.yy66 = array_new(AST_ReturnElementNode*, 1);
	array_append(yylhsminor.yy66, yymsp[0].minor.yy34);
}
#line 1805 "grammar.c"
  yymsp[0].minor.yy66 = yylhsminor.yy66;
        break;
      case 71: /* returnElement ::= MUL */
#line 421 "grammar.y"
{
	yymsp[0].minor.yy34 = New_AST_ReturnElementExpandALL();
}
#line 1813 "grammar.c"
        break;
      case 72: /* returnElement ::= arithmetic_expression */
#line 424 "grammar.y"
{
	yylhsminor.yy34 = New_AST_ReturnElementNode(yymsp[0].minor.yy154, NULL);
}
#line 1820 "grammar.c"
  yymsp[0].minor.yy34 = yylhsminor.yy34;
        break;
      case 73: /* returnElement ::= arithmetic_expression AS UQSTRING */
#line 428 "grammar.y"
{
	yylhsminor.yy34 = New_AST_ReturnElementNode(yymsp[-2].minor.yy154, yymsp[0].minor.yy0.strval);
}
#line 1828 "grammar.c"
  yymsp[-2].minor.yy34 = yylhsminor.yy34;
        break;
      case 74: /* arithmetic_expression ::= LEFT_PARENTHESIS arithmetic_expression RIGHT_PARENTHESIS */
#line 435 "grammar.y"
{
	yymsp[-2].minor.yy154 = yymsp[-1].minor.yy154;
}
#line 1836 "grammar.c"
        break;
      case 75: /* arithmetic_expression ::= arithmetic_expression ADD arithmetic_expression */
#line 447 "grammar.y"
{
	Vector *args = NewVector(AST_ArithmeticExpressionNode*, 2);
	Vector_Push(args, yymsp[-2].minor.yy154);
	Vector_Push(args, yymsp[0].minor.yy154);
	yylhsminor.yy154 = New_AST_AR_EXP_OpNode("ADD", args);
}
#line 1846 "grammar.c"
  yymsp[-2].minor.yy154 = yylhsminor.yy154;
        break;
      case 76: /* arithmetic_expression ::= arithmetic_expression DASH arithmetic_expression */
#line 454 "grammar.y"
{
	Vector *args = NewVector(AST_ArithmeticExpressionNode*, 2);
	Vector_Push(args, yymsp[-2].minor.yy154);
	Vector_Push(args, yymsp[0].minor.yy154);
	yylhsminor.yy154 = New_AST_AR_EXP_OpNode("SUB", args);
}
#line 1857 "grammar.c"
  yymsp[-2].minor.yy154 = yylhsminor.yy154;
        break;
      case 77: /* arithmetic_expression ::= arithmetic_expression MUL arithmetic_expression */
#line 461 "grammar.y"
{
	Vector *args = NewVector(AST_ArithmeticExpressionNode*, 2);
	Vector_Push(args, yymsp[-2].minor.yy154);
	Vector_Push(args, yymsp[0].minor.yy154);
	yylhsminor.yy154 = New_AST_AR_EXP_OpNode("MUL", args);
}
#line 1868 "grammar.c"
  yymsp[-2].minor.yy154 = yylhsminor.yy154;
        break;
      case 78: /* arithmetic_expression ::= arithmetic_expression DIV arithmetic_expression */
#line 468 "grammar.y"
{
	Vector *args = NewVector(AST_ArithmeticExpressionNode*, 2);
	Vector_Push(args, yymsp[-2].minor.yy154);
	Vector_Push(args, yymsp[0].minor.yy154);
	yylhsminor.yy154 = New_AST_AR_EXP_OpNode("DIV", args);
}
#line 1879 "grammar.c"
  yymsp[-2].minor.yy154 = yylhsminor.yy154;
        break;
      case 79: /* arithmetic_expression ::= UQSTRING LEFT_PARENTHESIS arithmetic_expression_list RIGHT_PARENTHESIS */
#line 476 "grammar.y"
{
	yylhsminor.yy154 = New_AST_AR_EXP_OpNode(yymsp[-3].minor.yy0.strval, yymsp[-1].minor.yy116);
}
#line 1887 "grammar.c"
  yymsp[-3].minor.yy154 = yylhsminor.yy154;
        break;
      case 80: /* arithmetic_expression ::= value */
#line 481 "grammar.y"
{
	yylhsminor.yy154 = New_AST_AR_EXP_ConstOperandNode(yymsp[0].minor.yy189);
}
#line 1895 "grammar.c"
  yymsp[0].minor.yy154 = yylhsminor.yy154;
        break;
      case 81: /* arithmetic_expression ::= variable */
#line 486 "grammar.y"
{
	yylhsminor.yy154 = New_AST_AR_EXP_VariableOperandNode(yymsp[0].minor.yy120->alias, yymsp[0].minor.yy120->property);
	free(yymsp[0].minor.yy120);
}
#line 1904 "grammar.c"
  yymsp[0].minor.yy154 = yylhsminor.yy154;
        break;
      case 82: /* arithmetic_expression_list ::= arithmetic_expression_list COMMA arithmetic_expression */
#line 493 "grammar.y"
{
	Vector_Push(yymsp[-2].minor.yy116, yymsp[0].minor.yy154);
	yylhsminor.yy116 = yymsp[-2].minor.yy116;
}
#line 1913 "grammar.c"
  yymsp[-2].minor.yy116 = yylhsminor.yy116;
        break;
      case 83: /* arithmetic_expression_list ::= arithmetic_expression */
#line 497 "grammar.y"
{
	yylhsminor.yy116 = NewVector(AST_ArithmeticExpressionNode*, 1);
	Vector_Push(yylhsminor.yy116, yymsp[0].minor.yy154);
}
#line 1922 "grammar.c"
  yymsp[0].minor.yy116 = yylhsminor.yy116;
        break;
      case 84: /* variable ::= UQSTRING */
#line 504 "grammar.y"
{
	yylhsminor.yy120 = New_AST_Variable(yymsp[0].minor.yy0.strval, NULL);
}
#line 1930 "grammar.c"
  yymsp[0].minor.yy120 = yylhsminor.yy120;
        break;
      case 85: /* variable ::= UQSTRING DOT UQSTRING */
#line 508 "grammar.y"
{
	yylhsminor.yy120 = New_AST_Variable(yymsp[-2].minor.yy0.strval, yymsp[0].minor.yy0.strval);
}
#line 1938 "grammar.c"
  yymsp[-2].minor.yy120 = yylhsminor.yy120;
        break;
      case 86: /* orderClause ::= */
#line 514 "grammar.y"
{
	yymsp[1].minor.yy28 = NULL;
}
#line 1946 "grammar.c"
        break;
      case 87: /* orderClause ::= ORDER BY arithmetic_expression_list */
#line 517 "grammar.y"
{
	yymsp[-2].minor.yy28 = New_AST_OrderNode(yymsp[0].minor.yy116, ORDER_DIR_ASC);
}
#line 1953 "grammar.c"
        break;
      case 88: /* orderClause ::= ORDER BY arithmetic_expression_list ASC */
#line 520 "grammar.y"
{
	yymsp[-3].minor.yy28 = New_AST_OrderNode(yymsp[-1].minor.yy116, ORDER_DIR_ASC);
}
#line 1960 "grammar.c"
        break;
      case 89: /* orderClause ::= ORDER BY arithmetic_expression_list DESC */
#line 523 "grammar.y"
{
	yymsp[-3].minor.yy28 = New_AST_OrderNode(yymsp[-1].minor.yy116, ORDER_DIR_DESC);
}
#line 1967 "grammar.c"
        break;
      case 90: /* skipClause ::= */
#line 529 "grammar.y"
{
	yymsp[1].minor.yy173 = NULL;
}
#line 1974 "grammar.c"
        break;
      case 91: /* skipClause ::= SKIP INTEGER */
#line 532 "grammar.y"
{
	yymsp[-1].minor.yy173 = New_AST_SkipNode(yymsp[0].minor.yy0.intval);
}
#line 1981 "grammar.c"
        break;
      case 92: /* limitClause ::= */
#line 538 "grammar.y"
{
	yymsp[1].minor.yy77 = NULL;
}
#line 1988 "grammar.c"
        break;
      case 93: /* limitClause ::= LIMIT INTEGER */
#line 541 "grammar.y"
{
	yymsp[-1].minor.yy77 = New_AST_LimitNode(yymsp[0].minor.yy0.intval);
}
#line 1995 "grammar.c"
        break;
      case 94: /* unwindClause ::= UNWIND LEFT_BRACKET arithmetic_expression_list RIGHT_BRACKET AS UQSTRING */
#line 547 "grammar.y"
{
	yymsp[-5].minor.yy137 = New_AST_UnwindNode(yymsp[-3].minor.yy116, yymsp[0].minor.yy0.strval);
}
#line 2002 "grammar.c"
        break;
      case 95: /* relation ::= EQ */
#line 552 "grammar.y"
{ yymsp[0].minor.yy122 = EQ; }
#line 2007 "grammar.c"
        break;
      case 96: /* relation ::= GT */
#line 553 "grammar.y"
{ yymsp[0].minor.yy122 = GT; }
#line 2012 "grammar.c"
        break;
      case 97: /* relation ::= LT */
#line 554 "grammar.y"
{ yymsp[0].minor.yy122 = LT; }
#line 2017 "grammar.c"
        break;
      case 98: /* relation ::= LE */
#line 555 "grammar.y"
{ yymsp[0].minor.yy122 = LE; }
#line 2022 "grammar.c"
        break;
      case 99: /* relation ::= GE */
#line 556 "grammar.y"
{ yymsp[0].minor.yy122 = GE; }
#line 2027 "grammar.c"
        break;
      case 100: /* relation ::= NE */
#line 557 "grammar.y"
{ yymsp[0].minor.yy122 = NE; }
#line 2032 "grammar.c"
        break;
      case 101: /* value ::= INTEGER */
#line 568 "grammar.y"
{  yylhsminor.yy189 = SI_DoubleVal(yymsp[0].minor.yy0.intval); }
#line 2037 "grammar.c"
  yymsp[0].minor.yy189 = yylhsminor.yy189;
        break;
      case 102: /* value ::= DASH INTEGER */
#line 569 "grammar.y"
{  yymsp[-1].minor.yy189 = SI_DoubleVal(-yymsp[0].minor.yy0.intval); }
#line 2043 "grammar.c"
        break;
      case 103: /* value ::= STRING */
#line 570 "grammar.y"
{  yylhsminor.yy189 = SI_ConstStringVal(yymsp[0].minor.yy0.strval); }
#line 2048 "grammar.c"
  yymsp[0].minor.yy189 = yylhsminor.yy189;
        break;
      case 104: /* value ::= FLOAT */
#line 571 "grammar.y"
{  yylhsminor.yy189 = SI_DoubleVal(yymsp[0].minor.yy0.dval); }
#line 2054 "grammar.c"
  yymsp[0].minor.yy189 = yylhsminor.yy189;
        break;
      case 105: /* value ::= DASH FLOAT */
#line 572 "grammar.y"
{  yymsp[-1].minor.yy189 = SI_DoubleVal(-yymsp[0].minor.yy0.dval); }
#line 2060 "grammar.c"
        break;
      case 106: /* value ::= TRUE */
#line 573 "grammar.y"
{ yymsp[0].minor.yy189 = SI_BoolVal(1); }
#line 2065 "grammar.c"
        break;
      case 107: /* value ::= FALSE */
#line 574 "grammar.y"
{ yymsp[0].minor.yy189 = SI_BoolVal(0); }
#line 2070 "grammar.c"
        break;
      case 108: /* value ::= NULLVAL */
#line 575 "grammar.y"
{ yymsp[0].minor.yy189 = SI_NullVal(); }
#line 2075 "grammar.c"
        break;
      default:
        break;
/********** End reduce actions ************************************************/
  };
  assert( yyruleno<sizeof(yyRuleInfo)/sizeof(yyRuleInfo[0]) );
  yygoto = yyRuleInfo[yyruleno].lhs;
  yysize = yyRuleInfo[yyruleno].nrhs;
  yyact = yy_find_reduce_action(yymsp[yysize].stateno,(YYCODETYPE)yygoto);

  /* There are no SHIFTREDUCE actions on nonterminals because the table
  ** generator has simplified them to pure REDUCE actions. */
  assert( !(yyact>YY_MAX_SHIFT && yyact<=YY_MAX_SHIFTREDUCE) );

  /* It is not possible for a REDUCE to be followed by an error */
  assert( yyact!=YY_ERROR_ACTION );

  yymsp += yysize+1;
  yypParser->yytos = yymsp;
  yymsp->stateno = (YYACTIONTYPE)yyact;
  yymsp->major = (YYCODETYPE)yygoto;
  yyTraceShift(yypParser, yyact, "... then shift");
}

/*
** The following code executes when the parse fails
*/
#ifndef YYNOERRORRECOVERY
static void yy_parse_failed(
  yyParser *yypParser           /* The parser */
){
  ParseARG_FETCH;
#ifndef NDEBUG
  if( yyTraceFILE ){
    fprintf(yyTraceFILE,"%sFail!\n",yyTracePrompt);
  }
#endif
  while( yypParser->yytos>yypParser->yystack ) yy_pop_parser_stack(yypParser);
  /* Here code is inserted which will be executed whenever the
  ** parser fails */
/************ Begin %parse_failure code ***************************************/
/************ End %parse_failure code *****************************************/
  ParseARG_STORE; /* Suppress warning about unused %extra_argument variable */
}
#endif /* YYNOERRORRECOVERY */

/*
** The following code executes when a syntax error first occurs.
*/
static void yy_syntax_error(
  yyParser *yypParser,           /* The parser */
  int yymajor,                   /* The major type of the error token */
  ParseTOKENTYPE yyminor         /* The minor type of the error token */
){
  ParseARG_FETCH;
#define TOKEN yyminor
/************ Begin %syntax_error code ****************************************/
#line 32 "grammar.y"

	char buf[256];
	snprintf(buf, 256, "Syntax error at offset %d near '%s'", TOKEN.pos, TOKEN.s);

	ctx->ok = 0;
	ctx->errorMsg = strdup(buf);
#line 2140 "grammar.c"
/************ End %syntax_error code ******************************************/
  ParseARG_STORE; /* Suppress warning about unused %extra_argument variable */
}

/*
** The following is executed when the parser accepts
*/
static void yy_accept(
  yyParser *yypParser           /* The parser */
){
  ParseARG_FETCH;
#ifndef NDEBUG
  if( yyTraceFILE ){
    fprintf(yyTraceFILE,"%sAccept!\n",yyTracePrompt);
  }
#endif
#ifndef YYNOERRORRECOVERY
  yypParser->yyerrcnt = -1;
#endif
  assert( yypParser->yytos==yypParser->yystack );
  /* Here code is inserted which will be executed whenever the
  ** parser accepts */
/*********** Begin %parse_accept code *****************************************/
/*********** End %parse_accept code *******************************************/
  ParseARG_STORE; /* Suppress warning about unused %extra_argument variable */
}

/* The main parser program.
** The first argument is a pointer to a structure obtained from
** "ParseAlloc" which describes the current state of the parser.
** The second argument is the major token number.  The third is
** the minor token.  The fourth optional argument is whatever the
** user wants (and specified in the grammar) and is available for
** use by the action routines.
**
** Inputs:
** <ul>
** <li> A pointer to the parser (an opaque structure.)
** <li> The major token number.
** <li> The minor token number.
** <li> An option argument of a grammar-specified type.
** </ul>
**
** Outputs:
** None.
*/
void Parse(
  void *yyp,                   /* The parser */
  int yymajor,                 /* The major token code number */
  ParseTOKENTYPE yyminor       /* The value for the token */
  ParseARG_PDECL               /* Optional %extra_argument parameter */
){
  YYMINORTYPE yyminorunion;
  unsigned int yyact;   /* The parser action. */
#if !defined(YYERRORSYMBOL) && !defined(YYNOERRORRECOVERY)
  int yyendofinput;     /* True if we are at the end of input */
#endif
#ifdef YYERRORSYMBOL
  int yyerrorhit = 0;   /* True if yymajor has invoked an error */
#endif
  yyParser *yypParser;  /* The parser */

  yypParser = (yyParser*)yyp;
  assert( yypParser->yytos!=0 );
#if !defined(YYERRORSYMBOL) && !defined(YYNOERRORRECOVERY)
  yyendofinput = (yymajor==0);
#endif
  ParseARG_STORE;

#ifndef NDEBUG
  if( yyTraceFILE ){
    int stateno = yypParser->yytos->stateno;
    if( stateno < YY_MIN_REDUCE ){
      fprintf(yyTraceFILE,"%sInput '%s' in state %d\n",
              yyTracePrompt,yyTokenName[yymajor],stateno);
    }else{
      fprintf(yyTraceFILE,"%sInput '%s' with pending reduce %d\n",
              yyTracePrompt,yyTokenName[yymajor],stateno-YY_MIN_REDUCE);
    }
  }
#endif

  do{
    yyact = yy_find_shift_action(yypParser,(YYCODETYPE)yymajor);
    if( yyact >= YY_MIN_REDUCE ){
      yy_reduce(yypParser,yyact-YY_MIN_REDUCE,yymajor,yyminor);
    }else if( yyact <= YY_MAX_SHIFTREDUCE ){
      yy_shift(yypParser,yyact,yymajor,yyminor);
#ifndef YYNOERRORRECOVERY
      yypParser->yyerrcnt--;
#endif
      yymajor = YYNOCODE;
    }else if( yyact==YY_ACCEPT_ACTION ){
      yypParser->yytos--;
      yy_accept(yypParser);
      return;
    }else{
      assert( yyact == YY_ERROR_ACTION );
      yyminorunion.yy0 = yyminor;
#ifdef YYERRORSYMBOL
      int yymx;
#endif
#ifndef NDEBUG
      if( yyTraceFILE ){
        fprintf(yyTraceFILE,"%sSyntax Error!\n",yyTracePrompt);
      }
#endif
#ifdef YYERRORSYMBOL
      /* A syntax error has occurred.
      ** The response to an error depends upon whether or not the
      ** grammar defines an error token "ERROR".  
      **
      ** This is what we do if the grammar does define ERROR:
      **
      **  * Call the %syntax_error function.
      **
      **  * Begin popping the stack until we enter a state where
      **    it is legal to shift the error symbol, then shift
      **    the error symbol.
      **
      **  * Set the error count to three.
      **
      **  * Begin accepting and shifting new tokens.  No new error
      **    processing will occur until three tokens have been
      **    shifted successfully.
      **
      */
      if( yypParser->yyerrcnt<0 ){
        yy_syntax_error(yypParser,yymajor,yyminor);
      }
      yymx = yypParser->yytos->major;
      if( yymx==YYERRORSYMBOL || yyerrorhit ){
#ifndef NDEBUG
        if( yyTraceFILE ){
          fprintf(yyTraceFILE,"%sDiscard input token %s\n",
             yyTracePrompt,yyTokenName[yymajor]);
        }
#endif
        yy_destructor(yypParser, (YYCODETYPE)yymajor, &yyminorunion);
        yymajor = YYNOCODE;
      }else{
        while( yypParser->yytos >= yypParser->yystack
            && yymx != YYERRORSYMBOL
            && (yyact = yy_find_reduce_action(
                        yypParser->yytos->stateno,
                        YYERRORSYMBOL)) >= YY_MIN_REDUCE
        ){
          yy_pop_parser_stack(yypParser);
        }
        if( yypParser->yytos < yypParser->yystack || yymajor==0 ){
          yy_destructor(yypParser,(YYCODETYPE)yymajor,&yyminorunion);
          yy_parse_failed(yypParser);
#ifndef YYNOERRORRECOVERY
          yypParser->yyerrcnt = -1;
#endif
          yymajor = YYNOCODE;
        }else if( yymx!=YYERRORSYMBOL ){
          yy_shift(yypParser,yyact,YYERRORSYMBOL,yyminor);
        }
      }
      yypParser->yyerrcnt = 3;
      yyerrorhit = 1;
#elif defined(YYNOERRORRECOVERY)
      /* If the YYNOERRORRECOVERY macro is defined, then do not attempt to
      ** do any kind of error recovery.  Instead, simply invoke the syntax
      ** error routine and continue going as if nothing had happened.
      **
      ** Applications can set this macro (for example inside %include) if
      ** they intend to abandon the parse upon the first syntax error seen.
      */
      yy_syntax_error(yypParser,yymajor, yyminor);
      yy_destructor(yypParser,(YYCODETYPE)yymajor,&yyminorunion);
      yymajor = YYNOCODE;
      
#else  /* YYERRORSYMBOL is not defined */
      /* This is what we do if the grammar does not define ERROR:
      **
      **  * Report an error message, and throw away the input token.
      **
      **  * If the input token is $, then fail the parse.
      **
      ** As before, subsequent error messages are suppressed until
      ** three input tokens have been successfully shifted.
      */
      if( yypParser->yyerrcnt<=0 ){
        yy_syntax_error(yypParser,yymajor, yyminor);
      }
      yypParser->yyerrcnt = 3;
      yy_destructor(yypParser,(YYCODETYPE)yymajor,&yyminorunion);
      if( yyendofinput ){
        yy_parse_failed(yypParser);
#ifndef YYNOERRORRECOVERY
        yypParser->yyerrcnt = -1;
#endif
      }
      yymajor = YYNOCODE;
#endif
    }
  }while( yymajor!=YYNOCODE && yypParser->yytos>yypParser->yystack );
#ifndef NDEBUG
  if( yyTraceFILE ){
    yyStackEntry *i;
    char cDiv = '[';
    fprintf(yyTraceFILE,"%sReturn. Stack=",yyTracePrompt);
    for(i=&yypParser->yystack[1]; i<=yypParser->yytos; i++){
      fprintf(yyTraceFILE,"%c%s", cDiv, yyTokenName[i->major]);
      cDiv = ' ';
    }
    fprintf(yyTraceFILE,"]\n");
  }
#endif
  return;
}
#line 577 "grammar.y"


	/* Definitions of flex stuff */
	typedef struct yy_buffer_state *YY_BUFFER_STATE;
	int             yylex( void );
	extern int             yylex_destroy (void);
	YY_BUFFER_STATE yy_scan_string( const char * );
  	YY_BUFFER_STATE yy_scan_bytes( const char *, size_t );
  	extern int yylineno;
  	extern char *yytext;
	extern int yycolumn;

	AST *Query_Parse(const char *q, size_t len, char **err) {
		yycolumn = 1;	// Reset lexer's token tracking position
		yy_scan_bytes(q, len);
  		void* pParser = ParseAlloc(malloc);
  		int t = 0;

		parseCtx ctx = {.root = NULL, .ok = 1, .errorMsg = NULL};

		while( (t = yylex()) != 0) {
			Parse(pParser, t, tok, &ctx);
		}
		if (ctx.ok) {
			Parse(pParser, 0, tok, &ctx);
  		}
		ParseFree(pParser, free);
		if (err) {
			*err = ctx.errorMsg;
		}
		yylex_destroy();
		return ctx.root;
	}
#line 2388 "grammar.c"
