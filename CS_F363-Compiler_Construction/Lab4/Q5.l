// Write a program that prints (to monitor) the longest string from the input file along with its length
%{
#include <stdio.h>
#include <stdlib.h>
int longestLength = 0;
char* longestString = NULL;
%}
newline [\n\r]
%%
[a-zA-Z]* { 
	fprintf(yyout, "The string %s has %d characters\n", yytext, yyleng); 
	if (yyleng > longestLength){
		longestString = (char*) realloc(longestString, yyleng + 1);
		strncpy(longestString, yytext, yyleng);
		longestString[yyleng] = '\0';
		longestLength = yyleng;
	}
}
[ \t] {}
{newline} {}
^exit$  { exit(0); }

%%

main(){
	yyin = fopen("sample.txt", "r");
	yyout = fopen("out.txt", "w");
	yylex();

	fprintf(yyout, "\nThe longest string %s has %d characters\n", longestString, longestLength); 
}