%%
a printf("\n"); printf("%s %d", yytext, yyleng); yyless(3); printf(" %s %d", yytext, yyleng);
b printf("\n"); printf("%s %d", yytext, yyleng); yyless(3); printf(" %s %d", yytext, yyleng);
%%
main(){
    yylex();
    return 0;
}