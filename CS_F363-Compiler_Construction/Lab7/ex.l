%{
#include "y.tab.h"
%}
%%
[a-z]+ return ID;
\+ return ADD;
\* return MUL;
\( return LBRA;
\) return RBRA;
\n return NL;
[ ] {};
. return DUMMY; // previously when 'bits 123' the cfg accepted it coz space was ignored, making it valid 
%%
