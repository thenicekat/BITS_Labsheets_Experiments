## REJECT

- We want to force lex to start from a different operating point

```jsx
%{
#include <stdio.h>
int npink = 0, npin = 0, nin = 0;
%}

%%

pink { npink++; REJECT; }
pin { npin++; REJECT; }
in { nin++; REJECT; }
\n return; 

%%

main(){
	yylex();
	printf("%d %d %d", npink, npin, nin);
}
```

- Output = k1 0 1
- k is being echoed