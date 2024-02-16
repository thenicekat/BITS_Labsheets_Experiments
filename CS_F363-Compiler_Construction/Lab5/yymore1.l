%%
a ECHO; yymore();
b ECHO;
%%
main(){
    yylex();
    return 0;
    // yymore(): Appends the next matched string to the current value of
    // the yytext array rather than replacing the contents of the yytext array.
}