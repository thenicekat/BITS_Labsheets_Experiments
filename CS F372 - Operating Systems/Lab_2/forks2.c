#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main(){
	pid_t pid;
	pid = fork();

	if(pid < 0){
		fprintf(stderr, "Fork Failed");
		return 1;
	}else if(pid == 0){
		for(int i=0; i<5; i++){
			sleep(1);
			printf("Child Process: %d\n", i);		
			execlp("ls", "ls", NULL);
		}
	}else{
		for(int i=5; i<10; i++){
			printf("Parent Process: %d\n", i);	
		}
	}

	return 0;
}
