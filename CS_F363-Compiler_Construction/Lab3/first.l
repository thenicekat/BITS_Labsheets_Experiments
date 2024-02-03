%{
#include <stdio.h>
int num = 0;
int word = 0;
%}
%%
[0-9]+ { num = 1; }
[a-zA-Z].[a-zA-Z0-9]* { word = 1; }
%% 
int main(){
	printf("Enter any input: ");
	yylex();
	if(num == 1) printf("It is a number");
	
	if(word == 1) printf("It is a word");
}