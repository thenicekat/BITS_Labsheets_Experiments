%{
# include <stdio.h>
%}
%token INT PL SB ML DV OB CB NL
%%

s: expr NL {printf("Value: %d",$1);return 0;}
    ;

expr: expr PL mulex {$$=$1+$3;}
    | expr SB mulex {$$=$1-$3;}
    | mulex {$$=$1;}
    ;

mulex: mulex ML term {$$=$1*$3;}
    |  mulex DV term {$$=$1/$3;}
    |  term {$$=$1;}
    ;
term: OB expr CB {$$=$2;}
    | INT           {$$=$1;}
    ;





%%

void main()
{
printf ("Enter the sentence:\n"); yyparse();

}
yyerror(){
    
}

