#include <sys/types.h>
#include <time.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(){
	pid_t child_pid = fork();
	if(child_pid > 0){
		printf("\nParent Process: %d\n", getpid());
		sleep(6);
	}else{
		printf("Parent PID: %d\n", getppid());
		sleep(20);
		printf("Child Process: %d\n", getpid());
		printf("Parent PID: %d", getppid());
		exit(0);
	}
	return 0;
}
