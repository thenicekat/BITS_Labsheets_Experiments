%{
#include <stdio.h>
%}

%%

pp* {printf("\n%s T1", yytext);}
r(p|q)* {printf("\n%s T2", yytext);}
pq*r {printf("\n%s T3", yytext);}
q*p*r|q*p* {printf("\n%s T5", yytext);}
rpp* {printf("\n%s T4", yytext);}

%%

int main()
{
    yylex();
    return 0;
}