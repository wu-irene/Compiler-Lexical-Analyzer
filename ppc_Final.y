%{
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

%}

%union{
	char *op_val;
	int int_val;
}

%define parse.error verbose
%start prog_start
%token INTEGER BREAK IFF FUNCTION BEGIN_BODY END_BODY ARRAY OF IF THEN ENDIF ELSE WHILE DO CONTINUE BREAK READ WRITE NOT TRUE FALSE RETURN MOD EQ NEQ LT GT LTE GTE SEMICOLON COLON COMMA L_SQUARE_BRACKET R_SQUARE_BRACKET EQUAL NUMBER PLUS MINUS MULT DIV L_PAREN R_PAREN ASSIGN INPUT OUTPUT IDENT VOID
%type <op_val> variable
%type <int_val> NUMBER
%type <op_val> IDENT
%type <op_val> LT
%%

prog_start: /* epsilon */
	| functions 

functions: functionstart L_PAREN parameters R_PAREN BEGIN_BODY statements functionend
	| functionstart L_PAREN parameters R_PAREN BEGIN_BODY statements functionend functions 

functionstart: INTEGER IDENT
{
	std::string func = $2;
	printf("func %s\n", func.c_str());
}
	| FUNCTION IDENT
{
	std::string func = $2;
	printf("func %s\n", func.c_str());
}

functionend: END_BODY
{
	paramCnt = 0;
	printf("endfunc\n");
}

parameters: parameter 
	| parameter COMMA parameters

parameter: /* epsilon */ 
	| INTEGER IDENT 
{
	std::string argIdent = $2;
	printf(". %s\n", argIdent.c_str());
	printf("= %s, $%i\n", argIdent.c_str(),paramCnt);
	paramCnt++;
}
        | IDENT
{
	std::string ident = $1;
	printf("param %s\n", ident.c_str());
} 
	| statements  {
        printf("param %s\n", _temp_0.c_str());
}

variable: 
	IDENT 
	|NUMBER


statements: /* epsilon */ 
	| statement SEMICOLON 
	| statement statements 

statement: /* epsilon */ 
	| ifElseState 
	| ifState
	| breakState
	| whileLoop
	| assignment 
{
        //printf("= %s, %s\n", _temp_0.c_str(), _temp_1.c_str());
}


 
	| definition 
	| return 
	| functionCall 
{
	_temp_1 = new_label();
	_temp_3 = _temp_1;
	_temp_4 = _temp_3;
	printf(". %s\n", _temp_1.c_str());
	printf("call %s, %s \n", _temp_0.c_str(), global_temp_dst.c_str());

}
	| math
{
	_temp_0 = new_label();
	_temp_3 = _temp_0;
	_temp_4 = _temp_3;
	printf(". %s\n", _temp_0.c_str());
	printf("%s %s, %s, %s\n", temp_3.c_str(), _temp_0.c_str(),temp_1.c_str(), temp_2.c_str());
}
	| write
	| variable {_temp_4 = $1;}
	| arrayAccess
	| arrayUnzip {
				//assignment try to do 
				_temp_3 = new_label();
				 _temp_4 = _temp_3;
				printf(". %s\n", _temp_3.c_str());
				printf("=[] %s,%s,%s\n", _temp_3.c_str(),temp_2.c_str(),temp_3.c_str());
				flag = 1;
				}

breakState: BREAK 
{
	printf(":= endloop%i\n", loopCnt);
}

write: WRITE INPUT statement SEMICOLON
{	
	std::string src = _temp_4;
	printf(".> %s\n", src.c_str());
}

math: 
  variable MINUS variable{ temp_1 = $1; temp_2 = $3; temp_3 = "-";}
| variable PLUS variable{ temp_1 = $1; temp_2 = $3; temp_3 = "+"; }
| variable MULT variable{ temp_1 = $1; temp_2 = $3; temp_3 = "*"; }
| variable DIV variable{ temp_1 = $1; temp_2 = $3; temp_3 = "/"; }
| variable MOD variable { temp_1 = $1; temp_2 = $3; temp_3 = "%"; }

| statement MINUS variable{ temp_1 = _temp_3; temp_2 = $3; temp_3 = "-";}
| statement PLUS variable{ temp_1 = _temp_3; temp_2 = $3; temp_3 = "+"; }
| statement MULT variable{ temp_1 = _temp_3; temp_2 = $3; temp_3 = "*"; }
| statement DIV variable{ temp_1 = _temp_3; temp_2 = $3; temp_3 = "/"; }
| statement MOD variable { temp_1 = _temp_3; temp_2 = $3; temp_3 = "%"; }





arrayAccess: variable L_SQUARE_BRACKET variable R_SQUARE_BRACKET ASSIGN statement SEMICOLON {
                std::string dst = $1;
                std::string index = $3;
                printf("[]= %s,%s,%s\n", dst.c_str(),index.c_str(),_temp_3.c_str());
                }
    |variable L_SQUARE_BRACKET variable R_SQUARE_BRACKET ASSIGN variable SEMICOLON {
                std::string dst = $1;
                std::string index = $3;
                std::string number = $6;
                printf("[]= %s,%s,%s\n", dst.c_str(),index.c_str(),number.c_str());
                }

arrayUnzip: variable L_SQUARE_BRACKET variable R_SQUARE_BRACKET{
				temp_2 =$1;
				temp_3 =$3;
			
				}

functionCall: IDENT ASSIGN IDENT L_PAREN arguments R_PAREN SEMICOLON 
{
	global_temp_dst = $1;
	_temp_0 = $3;
}

arguments: argument
| argument COMMA arguments

argument: IDENT
{
	std::string param = $1;
	printf("param %s\n", param.c_str());
}
| NUMBER
{
	int param = $1;
	printf("param %i\n", param);
}

return: RETURN NUMBER SEMICOLON 
	| RETURN IDENT SEMICOLON 
{
	std::string src = $2;
	printf("ret %s\n", src.c_str());
}
	| RETURN statements 
{
	printf("ret %s\n", _temp_0.c_str());

}


definition: INTEGER IDENT SEMICOLON
{
	std::string name = $2;
	printf(". %s\n", name.c_str());
} | INTEGER IDENT L_SQUARE_BRACKET variable R_SQUARE_BRACKET SEMICOLON
{
    std::string ident = $2;
    std::string size = $4;

    printf(".[] %s, %s\n", ident.c_str(), size.c_str());
}

ifState: ifStart R_PAREN BEGIN_BODY statements ifEnd

ifStart: IF L_PAREN condition
{
	printf("?:= if_true%i, %s\n", iftrueCnt, storeCondition.c_str());
	printf(":= endif%i\n", endifCnt);
	printf(": if_true%i\n", iftrueCnt);
}

ifElseState: ifElseStart R_PAREN BEGIN_BODY statements ifEnd elseStart BEGIN_BODY statements ifEnd

ifElseStart: IFF L_PAREN condition
{
	printf("?:= if_true%i, %s\n", iftrueCnt, storeCondition.c_str());
	printf(":= else%i\n", elseCnt);
	printf(": if_true%i\n", iftrueCnt);
}

elseStart: ELSE
{
	printf(": else%i\n",elseCnt);
}

ifEnd: END_BODY
{
	printf(": endif%i\n", endifCnt);
}
 
whileLoop: whileLoopStart condition R_PAREN BEGIN_BODY whileLoopBody statements statements whileLoopEnd

whileLoopStart: WHILE L_PAREN
{
	loopCnt++;
	printf(": beginloop%i\n", loopCnt);
}

whileLoopBody:
{
	loopBdyCnt++;
	printf("?:= loopbody%i, %s\n", loopBdyCnt, storeCondition.c_str());
	printf(":= endloop%i\n", loopCnt);
	printf(": loopbody%i\n", loopBdyCnt);
}

whileLoopEnd: END_BODY
{
	printf(":= beginloop%i\n", loopCnt);
	printf(": endloop%i\n", loopCnt);
	loopCnt--;
}

assignment: IDENT ASSIGN variable SEMICOLON 
{
	std::string dest = $1;
	std::string src = $3;
	printf("= %s, %s\n", dest.c_str(), src.c_str());

}
| IDENT ASSIGN arrayUnzip SEMICOLON{
  std::string temp_dst = $1;
  printf("=[] %s,%s,%s\n",temp_dst.c_str(),temp_2.c_str(),temp_3.c_str());
} 
| IDENT ASSIGN statement SEMICOLON{
  std::string temp_dst = $1;
  printf("%s %s,%s,%s\n", temp_3.c_str(),temp_dst.c_str(),temp_1.c_str(),temp_2.c_str());
}
//| IDENT ASSIGN statement{
//  _temp_0 = $1;
//  printf("= %s, %s\n", _temp_0.c_str(), _temp_1.c_str());
//}




/*
< dst, src1, src2	dst = src1 < src2
<= dst, src1, src2	dst = src1 <= src2
!= dst, src1, src2	dst = src1 != src2
== dst, src1, src2	dst = src1 == src2
>= dst, src1, src2	dst = src1 >= src2
> dst, src1, src2	dst = src1 > src2
*/
condition: variable LT variable 
{
	Phase4_temp_1 = new_label();
	storeCondition = Phase4_temp_1;
	std::string salsa = Phase4_temp_1;
    std::string burrito = $1;
    std::string taco = $3;
	printf(". %s\n", salsa.c_str());
	printf("< %s, %s, %s\n", salsa.c_str(), burrito.c_str(), taco.c_str());
}
| variable GT variable 
{
	Phase4_temp_1 = new_label();
	storeCondition = Phase4_temp_1;
	std::string salsa = Phase4_temp_1;
    std::string burrito = $1;
    std::string taco = $3;
	printf(". %s\n", salsa.c_str());
	printf("> %s, %s, %s\n", salsa.c_str(), burrito.c_str(), taco.c_str());
}
| variable LTE variable 
{
	Phase4_temp_1 = new_label();
	storeCondition = Phase4_temp_1;
	std::string salsa = Phase4_temp_1;
    std::string burrito = $1;
    std::string taco = $3;
	printf(". %s\n", salsa.c_str());
	printf("<= %s, %s, %s\n", salsa.c_str(), burrito.c_str(), taco.c_str());
}
| variable GTE variable 
{
	Phase4_temp_1 = new_label();
	storeCondition = Phase4_temp_1;
	std::string salsa = Phase4_temp_1;
    std::string burrito = $1;
    std::string taco = $3;
	printf(". %s\n", salsa.c_str());
	printf(">= %s, %s, %s\n", salsa.c_str(), burrito.c_str(), taco.c_str());
}
| variable EQ variable 
{
	Phase4_temp_1 = new_label();
	storeCondition = Phase4_temp_1;
	std::string salsa = Phase4_temp_1;
    std::string burrito = $1;
    std::string taco = $3;
	printf(". %s\n", salsa.c_str());
	printf("== %s, %s, %s\n", salsa.c_str(), burrito.c_str(), taco.c_str());
}
| variable NEQ variable 
{
	Phase4_temp_1 = new_label();
	storeCondition = Phase4_temp_1;
	std::string salsa = Phase4_temp_1;
    std::string burrito = $1;
    std::string taco = $3;
	printf(". %s\n", salsa.c_str());
	printf("!= %s, %s, %s\n", salsa.c_str(), burrito.c_str(), taco.c_str());
}

%%

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
