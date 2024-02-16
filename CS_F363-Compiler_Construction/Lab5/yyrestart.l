%%
[a-z]+ { 
    printf("\nLower case token = ");
    ECHO; 
    return;
}
[a-zA-Z]+ { ECHO;}
%%
main(){
    printf("\nBegin of first yylex:\n");
		yyin = fopen("input1.txt","r+");
    yylex();

    printf("\nBegin of 2nd lex operation on file");
    yyin = fopen("input2.txt","r+");
    yyrestart(yyin);
    yylex();
    printf("\nEnd of 2nd lex operation on file\n");
}