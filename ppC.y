%{
#include <stdio.h>
extern FILE* yyin;
%}

%define parse.error verbose
%start prog_start
%token INTEGER FUNCTION BEGIN_BODY END_BODY ARRAY OF IF THEN ENDIF ELSE WHILE DO CONTINUE BREAK READ WRITE NOT TRUE FALSE RETURN MOD EQ NEQ LT GT LTE GTE SEMICOLON COLON COMMA L_SQUARE_BRACKET R_SQUARE_BRACKET EQUAL NUMBER PLUS MINUS MULT DIV L_PAREN R_PAREN ASSIGN IDENT
%%

prog_start: /* epsilon */ {printf("prog_start->epsilon \n");}
	| functions {printf("prog_start->functions \n");}

functions: function {printf("functions->function \n");}
	| function functions {printf("functions -> function functions \n");}

function: INTEGER IDENT L_PAREN arguments R_PAREN BEGIN_BODY statements END_BODY {printf("function -> INTEGER IDENT L_PAREN arguments R_PAREN BEGIN_BODY statements END_BODY\n");}

arguments: argument {printf("arguments -> argument \n");}
	| argument COMMA arguments {printf("arguments -> COMMA arguments \n");}

argument: /* epsilon */ {printf("argument->epsilon \n");}
	| INTEGER IDENT {printf("argument-> INT IDENT \n");}

statements: /* epsilon */ {printf("statements->epsilon\n");}
	| statement statements {printf("statements -> statement SEMICOLON statements \n");}

statement: /* epsilon */ {printf("statement -> epsilon \n");}
	| ifElseState {printf("statement -> ifElseState \n");}
	| whileLoop {printf("statement -> whileLoop\n");}
	| assignment {printf("statement -> assignemnt\n");}

ifElseState: /* epsilon */ {printf("ifElseState -> epsilon\n");}
	| IF L_PAREN condition R_PAREN BEGIN_BODY statements END_BODY ifElseState {printf("ifElseState -> IF L_PAREN condition R_PAREN BEGIN_BODY statements END_BODY ifElseState\n");}
	| ELSE BEGIN_BODY statements END_BODY {printf("ifElseState -> ELSE BEGIN_BODY statements END_BODY\n");}
 
whileLoop: WHILE L_PAREN condition R_PAREN BEGIN_BODY statements END_BODY {printf("whileLoop -> WHILE L_PAREN condition R_PAREN BEGIN_BODY statements END_BODY\n");}


assignment: IDENT ASSIGN NUMBER SEMICOLON {printf("IDENT ASSIGN NUMBER SEMICOLON\n");} 

condition: /* epsilon */ {printf("condition -> epsilon\n");}
	| IDENT EQ IDENT {printf("condition -> IDENT EQ IDENT\n");}
	| IDENT NEQ IDENT {printf("condition -> IDENT NEQ IDENT\n");}
	| IDENT LT IDENT {printf("condition -> IDENT LT IDENT\n");}
	| IDENT GT IDENT {printf("condition -> IDENT GT IDENT\n");}
	| IDENT LTE IDENT {printf("condition -> IDENT LTE IDENT\n");}
	| IDENT GTE IDENT {printf("condition -> IDENT GTE IDENT\n");}






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
int yyerror(char *error_message) {

  printf("%s\n", error_message);

}
