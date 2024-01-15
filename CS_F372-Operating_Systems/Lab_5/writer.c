#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#define BUF_SIZE 200

int main()
{
    key_t key;
    int shmid;
    char *shm, buff[BUF_SIZE];
    if ((key = ftok(".", 10)) == -1)
    {
        perror("Erros in ftok");
        exit(-1);
    }

    if ((shmid = shmget(key, sizeof(char[BUF_SIZE]), 0666 | IPC_CREAT)) == -1)
    {
        perror("Error in shmget");
        exit(-1);
    }

    shm = (char *)shmat(shmid, NULL, 0);
    printf("Enter lines of text, press Ctrl+D to quit\n");

    while (fgets(buff, sizeof(buff), stdin) != NULL)
    {
        int len = strlen(buff);
        if (buff[len - 1] == '\n')
            buff[len - 1] = '\0';
        strcpy(shm, buff);
    }

    if (shmdt(shm) == -1)
    {
        perror("Error in shmdt\n");
        exit(-3);
    }
    if (shmctl(shmid, IPC_RMID, 0) == -1)
    {
        perror("Error while deleting the shared memory\n");
        exit(-1);
    }
}