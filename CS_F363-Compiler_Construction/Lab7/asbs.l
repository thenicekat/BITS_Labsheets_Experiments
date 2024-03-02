%{
#include "y.tab.h"
%}

%%

a* return TERM_A;
b* return TERM_B;
. {};

%%