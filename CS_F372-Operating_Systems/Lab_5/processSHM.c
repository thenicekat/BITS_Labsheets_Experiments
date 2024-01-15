#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <string.h>

#define BUF_SIZE 1000

int main(int argc, char **args)
{
    if (argc < 4)
    {
        printf("You have entered too few arguments\n");
        return -1;
    }

    char *filename1 = args[1];
    char *filename2 = args[2];
    char *filename3 = args[3];
    char *shm;

    printf("[Logs]: %s %s %s\n", filename1, filename2, filename3);

    key_t key;
    if ((key = ftok(".", 'B')) == -1)
    {
        printf("Error occurred while getting file key");
        return -1;
    }

    pid_t childproc1, childproc2;

    int shm_id;
    if ((shm_id = shmget(key, sizeof(shm), 0666 | IPC_CREAT)) == -1)
    {
        printf("Error occurred while connecting to shm\n");
        return -1;
    }

    childproc1 = fork();
    if (childproc1 == 0)
    {
        printf("Inside Child 1\n");
        FILE *f1 = fopen(filename1, "r");

        char input[BUF_SIZE];
        if (fgets(input, sizeof(input), f1) != NULL)
        {
            printf("Reading from file 1: %s\n", input);
        }

        char *shm = (char *)shmat(shm_id, NULL, 0);
        strcpy(shm, input);
        if (shmdt(shm) == -1)
        {
            perror("Error in shmdt\n");
            exit(-3);
        }
        printf("Done reading file 1\n");
        fclose(f1);
    }
    else
    {
        childproc2 = fork();
        if (childproc2 == 0)
        {
            printf("Inside Child 2\n");
            FILE *f2 = fopen(filename2, "r");

            char input2[BUF_SIZE];
            if (fgets(input2, sizeof(input2), f2) != NULL)
            {
                printf("Reading from file 2: %s\n", input2);
            }

            char *shm = (char *)shmat(shm_id, NULL, 0);
            strcpy(shm, input2);
            if (shmdt(shm) == -1)
            {
                perror("Error in shmdt\n");
                exit(-3);
            }
            printf("Done reading file 2\n");
        }
        else
        {
            wait(NULL); // Wait for child 1 to finish

            char *shm = (char *)shmat(shm_id, NULL, 0);
            if (shm[0] != '\0')
            {
                printf("Data in shared memory: %s\n", shm);
            }

            wait(NULL); // Wait for child 2 to finish

            shm = (char *)shmat(shm_id, NULL, 0);
            if (shm[0] != '\0')
            {
                printf("Data in shared memory: %s\n", shm);
            }

            if (shmdt(shm) == -1)
            {
                perror("Error in shmdt\n");
                exit(-3);
            }
        }
    }

    return 0;
}
