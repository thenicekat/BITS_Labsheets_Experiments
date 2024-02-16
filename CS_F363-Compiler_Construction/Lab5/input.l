%{
    #include <stdio.h>
%}
lower [a-z]
upper [A-Z]
%%
(lower|upper)* { ECHO; }
["] while (input() != '"');
[.] { printf("dot"); }
%%
main(){
    yyin = fopen("input.txt", "r");
    yylex();
}