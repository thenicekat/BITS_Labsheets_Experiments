
%{
// We want to force lex to start from a different operating point
#include <stdio.h>
int npink = 0, npin = 0, nin = 0;
%}

%%

pink { npink++; REJECT; }
pin { npin++; REJECT; }
in { nin++; REJECT; }
{} {
	ECHO;
	printf("\n");
}
\n return; 

%%

main(){
	yylex();
	printf("%d %d %d", npink, npin, nin);
	// - Output = k1 0 1 depending on number of rejects
	// - k is being echoed
}	