#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <pthread.h>
#include <stdlib.h>

int main(){
 pid_t p;
 p = fork();
 if(p == 0){
 execlp("./a.out", "sdjfnekvnfsd", NULL);
 printf("\n Ch Hello");
 printf("\n Ch Hello");
 }
 else{
 printf("\nElse Hello");
 printf("\nElse Hello");
}
 printf("\nOut Hello");
}
