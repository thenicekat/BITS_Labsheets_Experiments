%{
# include <stdio.h>
%}
%union {int ival; double dval;}
%token<ival> INTEGER
%token<dval> NUMBER
%token PL NL
%type<dval> sum


%%

s: sum NL {printf("Result: %f",$1);return 1;}
    ;

sum: INTEGER PL INTEGER {$$=(double)($1+$3);}
    | NUMBER PL NUMBER  {$$=$1+$3;}
    ;




%%

void main()
{
printf ("Enter the sentence:\n"); yyparse();

}
yyerror(){
    printf("Invalid");
}

