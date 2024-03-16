%%
a printf("\n"); printf("::> From A: %s %d", yytext, yyleng); yyless(3); printf(" %s %d", yytext, yyleng);
b printf("\n"); printf("::> From B: %s %d", yytext, yyleng); yyless(3); printf(" %s %d", yytext, yyleng);
. {}
%%
main(){
    yylex();
    return 0;
}