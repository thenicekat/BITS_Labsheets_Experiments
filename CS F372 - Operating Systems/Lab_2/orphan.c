#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

// Orphan means parent exits without exiting the child
// so here the record for the child is still there
// after a point orphan gets converted to zombie
int main()
{
    pid_t pid = fork();

    if (pid == 0)
    {
        printf("In child %d\n", getpid());
        sleep(10);
    }
    else
    {
        printf("In Parent %d\n", getpid());
        printf("Process will exit\n");
        exit(0);
    }
}