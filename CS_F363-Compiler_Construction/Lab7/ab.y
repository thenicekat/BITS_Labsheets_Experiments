%{
#include <stdio.h>
#include <stdlib.h>
%}

%token A B END

%%
sentence: a_prod b_prod END {printf("Valid statement\n"); return 1;}
        ;
a_prod: A a_prod
      |
      ;
b_prod: B b_prod
      |
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
