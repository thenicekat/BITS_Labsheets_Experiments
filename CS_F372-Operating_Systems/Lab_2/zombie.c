#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

// Zombie means parent does not wait for the process to die
// so the process is never removed from the queue
// in this case if wait is never called then the os will remove the process as
// part of it's clean up
int main()
{
    pid_t pid = fork();

    if (pid == 0)
    {
        printf("In child %d\n", getpid());
    }
    else
    {
        printf("In Parent %d\n", getpid());
        printf("Process will stay in zombie mode\n");
        sleep(10);
        printf("Process will leave zombie mode\n");
        wait();
        sleep(10);
    }
}