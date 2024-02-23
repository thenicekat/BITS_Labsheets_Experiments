%{
#include <math.h>
%}

%s newflow

%%

expect-floats BEGIN(newflow);

<newflow>[0-9]+"."[0-9]+ {
    printf("found a float = %f\n",atof( yytext ));
}
<newflow>\n {
    printf("reverting to actual flow\n");
    BEGIN(INITIAL);
}

[0-9]+ {
    printf("found an integer, = %d\n", atoi( yytext ));
}
"." printf("found a dot\n" );

%%
