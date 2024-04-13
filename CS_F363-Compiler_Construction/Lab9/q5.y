%{
#include <stdio.h>
#include <stdlib.h>
%}
%union{
    struct {
        int zc;
        int oc;
        int value;
    } t;
}
%token ONE ZERO
%%

stmt: L { printf("Valid Input: Value: %d, Zeros: %d, Ones: %d\n", $<t.value>$, $<t.zc>1, $<t.oc>1); }
L: L B { $<t.oc>$ = $<t.oc>1 + $<t.oc>2; $<t.zc>$ = $<t.zc>1 + $<t.zc>2; $<t.value>$ = $<t.value>1*2 + $<t.value>2; }
| B { $<t.oc>$ = $<t.oc>1; $<t.zc>$ = $<t.zc>1; $<t.value>$ = $<t.value>1; }
;
B: ONE { $<t.oc>$ = 1; $<t.zc>$ = 0; $<t.value>$ = 1; }
| ZERO { $<t.zc>$ = 1; $<t.oc>$ = 0; $<t.value>$ = 0; }
;
%%

void main(){
    printf("Enter any string: ");
    yyparse();
    exit(0);
}

void yyerror(){
    printf("Invalid Input\n");
    return 0;
}