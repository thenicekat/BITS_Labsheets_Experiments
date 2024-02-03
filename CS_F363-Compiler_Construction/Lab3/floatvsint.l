%%

^exit$          {exit(0);} /* Helps avoid doing ^C or ^Z for stopping execution 😀 */
0|([1-9][0-9]*)    {printf("Integer: %s\n", yytext);}
(0|([1-9][0-9]*))[.][0-9]* {printf("Float: %s\n", yytext);}
.*               {printf("Neither: '%s'\n", yytext);} 

%%

int main() {
    yylex();
}