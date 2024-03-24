%{
#include "y.tab.h"
#include<stdlib.h>

%}
%%
[0-9]+ {yylval.ival=atoi(yytext);return INTEGER;}
"+" return PL;
\n return NL;
[1-9]+"."[0-9]+ {yylval.dval=atof(yytext);return NUMBER;}
%%