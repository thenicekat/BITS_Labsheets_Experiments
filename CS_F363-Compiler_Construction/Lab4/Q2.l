// Replace CS with Computer Science
%{
#include <stdio.h>
%}
num [0-9]
symbol [!@#$%]

%%
CS { fprintf(yyout, "Computer Science"); }
[a-zA-Z]* { ECHO; }
^exit$  { exit(0); }

%%

main(){
	yyin = fopen("sample.txt", "r");
	yyout = fopen("out.txt", "w");
	yylex();
}