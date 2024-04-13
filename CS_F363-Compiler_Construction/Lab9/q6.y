%{
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
%}
%union{
    struct {
        int zc;
        int oc;
        double value;
        int length;
    } t;
}
%token ONE ZERO
%%

stmt: L'.'L { 
   printf("\nLeft: 0s -> %d, 1s -> %d, Len: %d, Value: %f", $<t.zc>1, $<t.oc>1, $<t.length>1, $<t.value>1);
   printf("\nRight: 0s -> %d, 1s -> %d, Len: %d, Value: %f", $<t.zc>3, $<t.oc>3, $<t.length>3, $<t.value>3);

   double answer = $<t.value>1;
   answer += ($<t.value>3 / pow(2, $<t.length>3));
   printf("\n::> Answer: %f", answer);
}
L: L B { $<t.oc>$ = $<t.oc>1 + $<t.oc>2; $<t.zc>$ = $<t.zc>1 + $<t.zc>2; $<t.value>$ = $<t.value>1*2 + $<t.value>2; $<t.length>$ = $<t.length>1 + $<t.length>2; }
| B { $<t.oc>$ = $<t.oc>1; $<t.zc>$ = $<t.zc>1; $<t.value>$ = $<t.value>1; $<t.length>$ = $<t.length>1; }
;
B: ONE { $<t.oc>$ = 1; $<t.zc>$ = 0; $<t.value>$ = 1; $<t.length>$ = 1; }
| ZERO { $<t.zc>$ = 1; $<t.oc>$ = 0; $<t.value>$ = 0; $<t.length>$ = 1; }
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