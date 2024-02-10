// Count words, numbers, new lines and stuff
%{
#include <stdio.h>
int chars = 0;
int words = 0;
int numbers = 0;
int newlines = 0;
int spaces = 0;
%}
num [0-9]
symbol [!@#$%,.]
newline [\n\r]

%%

[a-zA-Z]* { words++; chars += yyleng }
{num}* { numbers++; }
{symbol}* {}
{newline} { newlines++; }
[ \t] { spaces++; }
^exit$  { exit(0); }

%%

main(){
	yyin = fopen("sample.txt", "r");
	yyout = fopen("out.txt", "w");
	yylex();


	fprintf(yyout, "The number of chars: %d\n", chars);
	fprintf(yyout, "The number of words: %d\n", words);
	fprintf(yyout, "The number of numbers: %d\n", numbers);
	fprintf(yyout, "The number of spaces: %d\n", spaces);
	fprintf(yyout, "The number of newlines: %d\n", newlines);
}   