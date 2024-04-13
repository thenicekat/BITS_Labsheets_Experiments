%{
#include "y.tab.h"
%}

CHAR [a-zA-Z0-9]
%x CONDSTART

%%

<*>[ ];
<*>[ \t]+;
<*>[\n] { return 0; }
"if" { return IF; }
"else" { return ELSE; }
"then" { return THEN; }
\( {
    BEGIN(CONDSTART);
    return ('(');
}
<CONDSTART>{CHAR}+ return COND;
<CONDSTART>\) {
    BEGIN(INITIAL);
    return (')');
}
{CHAR}+ return STAT;

%%