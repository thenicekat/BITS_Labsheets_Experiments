// Read content from sample.txt and writes the output to another file temp.txt 
// by removing empty lines, appending line numbers, and finally, printing the number 
// of empty lines in sample.txt

%{
#include <stdio.h>
int lineNumber = 1;
int total = 1;
%}
num [0-9]
symbol [!@#$%,.]
newline [\n\r]

%%
[a-zA-Z \t]* { fprintf(yyout, "%d\t%s\n", lineNumber, yytext); }
{newline}* { lineNumber++; total += yyleng; }
^exit$  { exit(0); }

%%

main(){
	yyin = fopen("sample.txt", "r");
	yyout = fopen("out.txt", "w");
	yylex();
	fprintf(yyout, "The total number of empty lines: %d", total - lineNumber);
}