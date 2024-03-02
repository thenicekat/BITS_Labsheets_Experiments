%{
#include <stdio.h>
#include <stdlib.h>
%}
%token TERM_A TERM_B

%%
ACCEPT: RESULT { 
    printf("%d\n", $1);
    return 1; 
}
RESULT: TERM_A TERM_B;
%%

int main(){
    printf("\nEnter any string: ");
    yyparse();
    printf("Valid Statement");
    return 0;
}

int yyerror(char* err){

    printf("\nInvalid Statement");
    return 0;
}