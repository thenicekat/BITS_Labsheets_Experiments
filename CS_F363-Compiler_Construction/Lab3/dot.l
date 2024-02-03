%{
#include <stdio.h>
%}
%%
[.] printf("I am a dot");
. printf("I am not dot");
%% 
int main(){
	printf("Enter any input: ");
	yylex();
}