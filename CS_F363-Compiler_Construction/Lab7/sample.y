%{
#include <stdio.h>
#include <stdlib.h>
%}
%token NUM WORD

%%
sentence: s { return 1; };
s: WORDS | NUM;
WORDS: WORD WORDS | WORD;
%%

int main(){
    printf ("Enter the sentence:\n"); 
    yyparse();
    printf("Valid statement\n"); 
    return 0;
}

int yyerror(char* err)
{
    printf("Invalid statement\n"); 
    exit(0);
}
