%x comment
%{
    int line_num = 1;
%}
%%

"/*" BEGIN(comment);
<comment>[^*\n]* /* eat anything that’s not a ’*’ */
<comment>"*"+[^*/\n]* /* eat up ’*’s not followed by ’/’s */
<comment>\n ++line_num;
<comment>"*"+"/" BEGIN(INITIAL);

%% 

int main(){
    yyin = fopen("input.c", "r");
    yyout = fopen("output.c", "w");

    printf("Number of lines: %d\n", line_num);
    
    yylex();
    return 0;
}