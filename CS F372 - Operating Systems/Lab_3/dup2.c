#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define READ 0
#define WRITE 1

int main()
{
    int file_descriptor[2];
    if (pipe(file_descriptor) == -1)
    {
        printf("Error: Could not create pipe");
        return -1;
    }

    pid_t child_proc1 = fork();
    if (child_proc1 == 0)
    {
        // Child Process -> ls process
        printf("Child Process #1: Started\n");
        // We use dup2 command to redirect output
        // We close read first
        // then we redirect stdout to write end and close write
        dup2(file_descriptor[WRITE], STDOUT_FILENO);
        fprintf(stdout, "hello world");
        close(file_descriptor[READ]);
        close(file_descriptor[WRITE]);
        execlp("ls", "ls", "-l && echo hello", NULL);
        printf("Child Process #1: Terminated\n");
    }
    else
    {
        // Parent Process
        // Create another child process
        pid_t child_proc2 = fork();
        if (child_proc2 == 0)
        {
            // Second Child Process -> wc process
            printf("Child Process #2: Started\n");
            // We close write first
            // then we redirect read from standard input and close read
            char output[1000];
            int numberOfBytes = read(file_descriptor[READ], output, sizeof(output));
            printf("--> %s", output);
            close(file_descriptor[WRITE]);
            // dup2(file_descriptor[READ], STDIN_FILENO);
            close(file_descriptor[READ]);
            // execlp("wc", "wc", "-l", NULL);
            printf("Child Process #2: Terminated\n");
        }
        else
        {
            //  Main Parent Process
            close(file_descriptor[READ]);
            close(file_descriptor[WRITE]);
            waitpid(child_proc1, NULL, 0);
            waitpid(child_proc2, NULL, 0);
            printf("Main Program Terminating\n");
        }
    }
}