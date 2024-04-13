yacc q5.y
lex q5.l
yacc -d q5.y
cc lex.yy.c y.tab.c -ll
./a.out