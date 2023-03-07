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
int  count_names = 0;
int  temp_0 = 0;
int global_variable_counter = 0;


std::string global_temp_dst = "";
std::string temp_1 = "";
std::string temp_2 = "";
std::string temp_3 = "";

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


std::string new_label() {
	std::ostringstream os;
	os << "__label__" << global_variable_counter++;
	return os.str();

}

%}

%union{
	char *op_val;
	int int_val;
}

%define parse.error verbose
%start prog_start
%token INTEGER FUNCTION BEGIN_BODY END_BODY ARRAY OF IF THEN ENDIF ELSE WHILE DO CONTINUE BREAK READ WRITE NOT TRUE FALSE RETURN MOD EQ NEQ LT GT LTE GTE SEMICOLON COLON COMMA L_SQUARE_BRACKET R_SQUARE_BRACKET EQUAL NUMBER PLUS MINUS MULT DIV L_PAREN R_PAREN ASSIGN INPUT OUTPUT IDENT VOID
%type <op_val> variable
%type <int_val> NUMBER
%type <op_val> IDENT
%%

prog_start: /* epsilon */
	| functions 

functions: function 
	| function functions 

function: INTEGER IDENT L_PAREN arguments R_PAREN BEGIN_BODY statements END_BODY 
{
	std::string func = $2;
	printf("func %s\n", func.c_str());	
	
}
	| VOID IDENT L_PAREN arguments R_PAREN BEGIN_BODY statements END_BODY 
{
	std::string func = $2;
	printf("func %s\n", func.c_str());
}

arguments: argument 
	| argument COMMA arguments

argument: /* epsilon */ 
	| INTEGER IDENT
{
	std::string arg = $2;
	printf(". %s\n", arg.c_str());
} 
        | IDENT 
	| statements 

variable: IDENT 
	|NUMBER


statements: /* epsilon */ 
	| statement SEMICOLON 
	| statement statements 

statement: /* epsilon */ 
	| ifElseState 
	| whileLoop 
	| assignment 
	| definition 
	| return 
	| functionCall 
	| math
	| write
	| arrayAccess

write: WRITE INPUT variable SEMICOLON
{	
	std::string src = $3;
	printf(".> %s\n", src.c_str());
}

math: variable MINUS variable{ temp_1 = $1; temp_2 = $3; temp_3 = "-"; }
| variable PLUS variable{ temp_1 = $1; temp_2 = $3; temp_3 = "+"; }
| variable MULT variable{ temp_1 = $1; temp_2 = $3; temp_3 = "*"; }
| variable DIV variable{ temp_1 = $1; temp_2 = $3; temp_3 = "/"; }


arrayUnzip: variable L_SQUARE_BRACKET variable R_SQUARE_BRACKET SEMICOLON{
				std::string src = $1;
				temp_2 =$1;
				temp_3 =$3;
				std::string index = $3;
				}

arrayAccess: variable L_SQUARE_BRACKET variable R_SQUARE_BRACKET ASSIGN variable SEMICOLON {
				std::string dst = $1;
				std::string index = $3;
				std::string src = $6;
				printf("[]= %s,%s,%s\n", dst.c_str(),index.c_str(),src.c_str());
				}

functionCall: IDENT L_PAREN arguments R_PAREN 
{
	std::string name = $1;

	printf("call %s, \n", name.c_str());

}


return: RETURN NUMBER SEMICOLON 
	| RETURN IDENT SEMICOLON 
{
	std::string src =$2;
	printf("ret %s\n", src.c_str());
}
	| RETURN statements



definition: INTEGER IDENT SEMICOLON 

ifElseState: /* epsilon */ 
	| IF L_PAREN condition R_PAREN BEGIN_BODY statements END_BODY ifElseState 
	| ELSE BEGIN_BODY statements END_BODY 
 
whileLoop: WHILE L_PAREN condition R_PAREN BEGIN_BODY statements END_BODY 

assignment: IDENT ASSIGN variable SEMICOLON 
{
	std::string dest = $1;
	std::string src = $3;
	printf("= %s, %s\n", dest.c_str(), src.c_str());

}
| IDENT ASSIGN arrayUnzip{
  std::string temp_dst = $1;
  printf("=[] %s,%s,%s\n",temp_dst.c_str(),temp_2.c_str(),temp_3.c_str());
} 
| IDENT ASSIGN math SEMICOLON{
  std::string temp_dst = $1;
  printf("%s %s,%s,%s\n", temp_3.c_str(),temp_dst.c_str(),temp_1.c_str(),temp_2.c_str());
}
| IDENT ASSIGN statement{} 


condition: /* epsilon */ 
	| IDENT EQ IDENT
	| IDENT NEQ IDENT
	| IDENT LT IDENT 
	| IDENT GT IDENT 
	| IDENT LTE IDENT 
	| IDENT GTE IDENT 
	| IDENT EQ NUMBER
	| IDENT NEQ NUMBER 
	| IDENT LT NUMBER 
	| IDENT GT NUMBER 
	| IDENT LTE NUMBER 
	| IDENT GTE NUMBER 

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

