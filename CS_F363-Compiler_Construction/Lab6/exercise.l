%{
#include <stdio.h>
#include <stdlib.h>
%}

zero-digit [0-9]
digit [1-9]
number ({zero-digit}|{digit}{zero-digit}*)
identifier [a-zA-Z][a-zA-Z0-9]*

%%

"/*" { 
    printf("Multi-line comment found\n");
    while(1) {
        int c = yyinput();
        if (c == EOF) {
            fprintf(stderr, "Unterminated multi-line comment\n");
            exit(1);
        }
        if (c == '*' && yyinput() == '/') {
            break;
        }
    }
}

"//" {
    printf("Single-line comment found\n");
    while(1) {
        int c = yyinput();
        if (c == '\n' || c == EOF) {
            break;
        }
    }
}

{number} {
    fprintf(yyout, "%s", yytext);
}

{identifier} {
    fprintf(yyout, "%s", yytext);
}

. {
    fprintf(yyout, "%s", yytext);
}

%%

int yyinput() {
    int c = input();
    if (c == '\n') {
        yylineno++;
    }
    return c;
}

int yywrap() {
    return 1;
}

int main() {
    yyin = fopen("input.c", "r");
    yyout = fopen("output.c", "w");
    if (!yyin || !yyout) {
        fprintf(stderr, "Error opening files\n");
        return 1;
    }

    yylex();

    fclose(yyin);
    fclose(yyout);
    return 0;
}
