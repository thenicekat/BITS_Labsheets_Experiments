#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int charc, char** charv){
	int n = atoi(charv[1]);
	for(int i=0; i<n/3; i++){
		sleep(1);
	}
	printf("%d\n", n);
	return 0;
}
