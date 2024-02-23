%{
#include<math.h>
int m=0,s=0;
%}
%s mlc slc
%%
"/*" {BEGIN(mlc);}
"//" {BEGIN(slc);}

<mlc>.|\n {}
<mlc>"*/" {m++;BEGIN(INITIAL);}

<slc>. {}
<slc>\n {s++;BEGIN(INITIAL);}
.|\n {ECHO;}
%%

int main(){
yyin = fopen("sample.c","r");
yyout = fopen("new.c","w");
yylex();
printf("No of multiline comments = %d\n", m);
printf("No of single line comments = %d\n", s);

return 0;
}