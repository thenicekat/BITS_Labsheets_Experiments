%%
[a-z]* printf("\n"); printf(" %s %d", yytext, yyleng); yyless(2); printf(" %s %d", yytext, yyleng);
%%
main(){
    yylex();
    return 0;
}