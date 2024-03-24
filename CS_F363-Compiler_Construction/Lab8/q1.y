%{
# include <stdio.h>
%}
%token NUM PL NL

%%

s: val NL {return 1;}
    ;
//it basically adds the numbers but the 1st and the 3rd ones only, because $2 would be + sign
val: NUM PL NUM PL NUM {$$=$1+$3; printf("%d",$$);}
    ;

%%

void main()
{
    printf ("Enter the sentence:\n"); yyparse();
}

yyerror(){
    
}

