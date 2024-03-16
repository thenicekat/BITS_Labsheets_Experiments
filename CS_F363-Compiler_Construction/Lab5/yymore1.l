%%
a { printf("\nFound a "); yymore(); ECHO; printf(" yytext: %s", yytext);}
ab { printf("\nFound ab "); ECHO; printf(" yytext: %s", yytext); }
b { printf("\nFound b "); ECHO; printf(" yytext: %s", yytext); }
%%
main(){
    yylex();
    return 0;
    // yymore(): Appends the next matched string to the current value of
    // the yytext array rather than replacing the contents of the yytext array.
}