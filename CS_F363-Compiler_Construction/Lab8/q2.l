%{
#include "y.tab.h"
#include<stdlib.h>
extern int yylval;
%}
%%
[0-9]+ {yylval=atoi(yytext);return INT;}
"+" return PL;
"-" return SB;
"*" return ML;
"/" return DV;
"(" return OB;
")" return CB;
\n return NL;
%%