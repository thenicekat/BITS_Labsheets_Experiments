%{
#include "y.tab.h"
%}

%%

[0-9]+ return NUM;
[a-z]+ return WORD;
\n return yytext;

%%