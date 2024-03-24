%{
# include <stdio.h>
%}
%token INT PL SB ML DV NL
%left PL SB
%%

s: expr NL {printf("Value: %d",$1);return 0;}
    ;

expr: expr PL expr {$$=$1+$3;}
    | expr SB expr {$$=$1-$3;}
    | expr ML expr {$$=$1*$3;}
    | expr DV expr {$$=$1/$3;}
    | INT {$$=$1;}
    ;






%%

void main()
{
printf ("Enter the sence:\n"); yyparse();

}
yyerror(){
    
}

