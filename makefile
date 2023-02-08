all:
	bison -v -d --file-prefix=y ppC.y
	flex lexer.lex
	gcc lex.yy.c -lfl
