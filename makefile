all:
	bison -v -d --file-prefix=y ppC.y
	flex lexer.lex
	gcc -o parser y.tab.c lex.yy.c -lfl
	cat ifelse.ppc | parser
