// Read input from file and count numbers and words

%{
#include <stdio.h>
int words = 0;
int numbers = 0;
%}
num [0-9]
symbol [!@#$%]

%%

[a-zA-Z \t][a-zA-Z]* { fprintf(yyout, "Word Found: %s\n", yytext); words++; }
{num}* { numbers++; }
{symbol}* {}
^exit$  { exit(0); }

%%

main(){
	yyin = fopen("sample.txt", "r");
	yyout = fopen("out.txt", "w");
	yylex();

	fprintf(yyout, "The number of words: %d\n", words);
	fprintf(yyout, "The number of numbers: %d", numbers);
}