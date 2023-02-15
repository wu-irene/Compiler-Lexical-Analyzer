%{
#include <stdio.h>
extern FILE* yyin;
%}

%start prog_start
%token INTEGER FUNCTION BEGIN_BODY END_BODY ARRAY OF IF THEN ENDIF ELSE WHILE DO CONTINUE BREAK READ WRITE NOT TRUE FALSE RETURN MOD EQ NEQ LT GT LTE GTE SEMICOLON COLON COMMA L_SQUARE_BRACKET R_SQUARE_BRACKET EQUAL NUMBER PLUS MINUS MULT DIV L_PAREN R_PAREN ASSIGN IDENT
%%

prog_start: /* epsilon */ {printf("prog_start->epsilon \n");}
	| functions {printf("prog_start->functions \n");}

functions: statements {printf("functions->statement \n");}

statements: statement {printf("statements -> \n");}

ident: IDENT {printf("ident -> IDENT \n");}

statement: IfElse {printf("statement -> IfElse \n");}
	| whileLoop {printf("statement -> whileLoop \n");}
	| assign {printf("statement -> assign \n");}

IfElse: IF L_PAREN condition R_PAREN BEGIN_BODY {printf("IfElse -> IF L_PAREN condition R_PAREN BEGIN_BODY \n");}

whileLoop: WHILE L_PAREN condition R_PAREN BEGIN_BODY {printf("whileLoop -> WHILE L_PAREN condition R_PAREN BEGIN_BODY\n");}

assign: ident  EQUAL IDENT SEMICOLON{printf("assign -> IDENT EQUAL IDENT SEMICOLON \n");}
	| ident EQUAL NUMBER SEMICOLON {printf("assign -> IDENT EQUAL NUMBER SEMICOLON \n");}

condition: /* epsilon */ {printf("condition -> epsilon\n");}
	| ident LT NUMBER{printf("condition -> IDENT LT NUMBER\n");}
	| ident GT NUMBER {printf("condition -> IDENT GT NUMBER\n");}
	| ident LTE NUMBER {printf("condition -> IDENT LTE NUMBER\n");}
	| ident GTE NUMBER {printf("condition -> IDENT GTE NUMBER\n");}
	| ident EQ NUMBER {printf("condition -> IDENT EQ NUMBER\n");} 

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
int yyerror() {}
