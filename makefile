all:

	bison -v -d --file-prefix=y ppc_Final.y
	flex lexer.lex
	g++ -o parser y.tab.c lex.yy.c -lfl
	
clean:

	rm -f lexer lex.yy.c
