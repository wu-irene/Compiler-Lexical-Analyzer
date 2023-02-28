all:

	bison -v -d --file-prefix=y ppC_phasethree.y
	flex lexer.lex
	g++ -o parser y.tab.c lex.yy.c -lfl
	
clean:

	rm -f lexer lex.yy.c
