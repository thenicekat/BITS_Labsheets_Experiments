#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>

int main(){
	pid_t pid = fork();
	int n;
	if(pid == 0){
		n = 5;
		printf("Child Process: %d, Parent Process: %d\n", getpid(), getppid());
		printf("Child: n: %d\n", n);
		
		pid_t gc = fork();
		if(gc == 0){
			printf("Grand Child Process: %d, Child Process: %d\n", getpid(), getppid());
			for(;;);
			printf("Terminated Grand Child\n");
		}else{
			printf("Child Process: %d, Grand Child Process: %d\n", getpid(), pid);
			waitpid(pid, NULL, 0);
			printf("Terminated Child\n");
		}
	}else{
	 	//wait(NULL);
		n = 15;
		printf("Parent Process: %d, Child Process: %d\n", getpid(), pid);
		printf("Parent: n: %d\n", n);
		printf("Terminated Parent\n");
	}
	
	return 0;
}
