%{
#include <stdio.h>
#include <stdlib.h>
%}

%token IF COND THEN STAT ELSE

%%stmt: IF '(' COND ')' THEN STAT { printf("\nValid Statement"); }
| IF '(' COND ')' THEN STAT ELSE STAT { printf("\nValid Statment"); }
| { printf("Empty String"); }
;

%%

void main(){
    yyparse();
    exit(0);
}

void yyerror(){
    printf("Error Occurred");
}