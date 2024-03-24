%{
#include <stdio.h>
#include <stdlib.h>
%}

%token ID ADD MUL LBRA RBRA NL

%%
FINAL: E NL {printf("Valid statement\n"); return 1;}
     ;

E:E ADD T
 |T
 ;

T:T MUL F
 |F
 ;

F:LBRA E RBRA
 |ID
 ;
%%

void main() {
  printf("Enter the sentence:\n");
  yyparse();
  exit(0);
}

void yyerror() {
  printf("Invalid Statement\n");
  exit(0);
}
