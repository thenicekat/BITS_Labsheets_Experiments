%{
#include "y.tab.h"
%}

%%

<*>[\n] { return 0; }
0 { return ZERO; }
1 { return ONE; }
[.] { return '.'; }
. {}

%%