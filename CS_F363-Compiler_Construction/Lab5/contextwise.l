%%
a*b+/c+ { printf("T_AB:%s\n", yytext); }
// this basically catches a*b+ such that c+ is to the right of it
a*b*c/a { printf("T_ABC:%s\n", yytext); }
// this catches a*b*c with an a to its right
a { printf("T_A:%s\n", yytext); }
c+ { printf("T_C:%s\n", yytext); }
. ECHO;
\n return 1;
%%
int main()
{
    yylex();
    // Input: abcca
    // T_AB: ab
    // T_C: cc
    // T_A: a
}