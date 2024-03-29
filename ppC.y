%{
#include <stdio.h>
extern FILE* yyin;
%}

%define parse.error verbose
%start prog_start
%token INTEGER FUNCTION BEGIN_BODY END_BODY ARRAY OF IF THEN ENDIF ELSE WHILE DO CONTINUE BREAK READ WRITE NOT TRUE FALSE RETURN MOD EQ NEQ LT GT LTE GTE SEMICOLON COLON COMMA L_SQUARE_BRACKET R_SQUARE_BRACKET EQUAL NUMBER PLUS MINUS MULT DIV L_PAREN R_PAREN ASSIGN IDENT VOID
%%

prog_start: /* epsilon */ {printf("prog_start->epsilon \n");}
	| functions {printf("prog_start->functions \n");}

functions: function {printf("functions->function \n");}
	| function functions {printf("functions -> function functions \n");}

function: INTEGER IDENT L_PAREN arguments R_PAREN BEGIN_BODY statements END_BODY {printf("function -> INTEGER IDENT L_PAREN arguments R_PAREN BEGIN_BODY statements END_BODY\n");}
	| VOID IDENT L_PAREN arguments R_PAREN BEGIN_BODY statements END_BODY {printf("function ->  VOID IDENT L_PAREN arguments R_PAREN BEGIN_BODY statements END_BODY\n");}

arguments: argument {printf("arguments -> argument \n");}
	| argument COMMA arguments {printf("arguments -> COMMA arguments \n");}

argument: /* epsilon */ {printf("argument->epsilon \n");}
	| INTEGER IDENT {printf("argument-> INT IDENT \n");}
        | IDENT {printf("argument->IDENT\n");}
	| statements {printf("argument -> statements\n");}

variable: IDENT {printf("variable -> IDENT\n");}
	| NUMBER {printf("variable -> NUMBER\n");}

statements: /* epsilon */ {printf("statements->epsilon\n");}
	| statement SEMICOLON {printf("statements -> statement SEMICOLON\n");}
	| statement statements {printf("statements -> statement statements \n");}

statement: /* epsilon */ {printf("statement -> epsilon \n");}
	| ifElseState {printf("statement -> ifElseState \n");}
	| whileLoop {printf("statement -> whileLoop\n");}
	| assignment {printf("statement -> assignemnt\n");}
	| definition {printf("statement -> definition\n");}
	| return {printf("statement -> return\n");}
	| functionCall {printf("statement -> functionCall\n");}
	| math {printf("statement -> math");}

math: variable MINUS variable {printf("math -> variable MINUS variable\n");}
	| variable PLUS variable {printf("math -> variable PLUS variable\n");}
	| variable MULT variable {printf("math -> variable MULT variable\n");}
	| variable DIV variable {printf("math -> variable DIV variable\n");}
        | variable MULT  statement {printf("math -> variable MULT  statement\n");}
	| variable PLUS statement {printf("math -> variable PLUS statment\n ");}
	| variable MINUS  statement {printf("math -> variable MINUS statment\n");}
	| variable DIV statement {printf("math-> variable DIV statement\n");}
	| statement MULT statement {printf("math-> statement DIV statement\n");}
	| statement DIV statement {printf("math-> statement DIV statement\n");}
	| statement PLUS statement {printf("math-> statement DIV statement\n");}
	| statement MINUS statement {printf("math-> statement DIV statement\n");}

functionCall: IDENT L_PAREN arguments R_PAREN {printf("functionCall -> IDENT L_PAREN arguments R_PAREN\n");}

return: RETURN NUMBER SEMICOLON {printf("return -> RETURN INTEGER SEMICOLON\n");}
	| RETURN IDENT SEMICOLON {printf("return -> RETURN IDENT SEMICOLON\n");}
	| RETURN statements {printf("return -> statements\n");}

definition: INTEGER IDENT SEMICOLON {printf("definition -> INTEGER IDENT SEMICOLON\n");}

ifElseState: /* epsilon */ {printf("ifElseState -> epsilon\n");}
	| IF L_PAREN condition R_PAREN BEGIN_BODY statements END_BODY ifElseState {printf("ifElseState -> IF L_PAREN condition R_PAREN BEGIN_BODY statements END_BODY ifElseState\n");}
	| ELSE BEGIN_BODY statements END_BODY {printf("ifElseState -> ELSE BEGIN_BODY statements END_BODY\n");}
 
whileLoop: WHILE L_PAREN condition R_PAREN BEGIN_BODY statements END_BODY {printf("whileLoop -> WHILE L_PAREN condition R_PAREN BEGIN_BODY statements END_BODY\n");}


assignment: IDENT ASSIGN NUMBER SEMICOLON {printf("IDENT ASSIGN NUMBER SEMICOLON\n");} 
            | IDENT ASSIGN statement {printf("IDENT ASSIGN STATMENT");}  



condition: /* epsilon */ {printf("condition -> epsilon\n");}
	| IDENT EQ IDENT {printf("condition -> IDENT EQ IDENT\n");}
	| IDENT NEQ IDENT {printf("condition -> IDENT NEQ IDENT\n");}
	| IDENT LT IDENT {printf("condition -> IDENT LT IDENT\n");}
	| IDENT GT IDENT {printf("condition -> IDENT GT IDENT\n");}
	| IDENT LTE IDENT {printf("condition -> IDENT LTE IDENT\n");}
	| IDENT GTE IDENT {printf("condition -> IDENT GTE IDENT\n");}
	| IDENT EQ NUMBER {printf("condition -> IDENT EQ NUMBER\n");}
	| IDENT NEQ NUMBER {printf("condition -> IDENT NEQ NUMBER\n");}
	| IDENT LT NUMBER {printf("condition -> IDENT LT NUMBER\n");}
	| IDENT GT NUMBER {printf("condition -> IDENT GT NUMBER\n");}
	| IDENT LTE NUMBER {printf("condition -> IDENT LTE NUMBER\n");}
	| IDENT GTE NUMBER {printf("condition -> IDENT GTE NUMBER\n");}

%%

void main(int argc, char** argv) {
    if (argc >= 2) {
	yyin = fopen(argv[1], "r");
	if (yyin == NULL) 
		yyin = stdin;
    }  else {
	yyin = stdin;
    }

    yyparse();
}
int yyerror(char *error_message){
  printf("%s\n", error_message);

	printf("%s\n", error_message);

}
