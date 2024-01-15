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
        perror("Error occured while finding the key");
        exit(-1);
    }

    if ((shmid = shmget(key, sizeof(char[BUF_SIZE]), 0666 | IPC_CREAT)) == -1)
    {
        perror("Error in shmget");
        exit(-1);
    }

    shm = (char *)shmat(shmid, NULL, 0);

    while (1)
    {
        if (shm[0] != '\0')
        {
            strcpy(buff, shm);
            printf("Reader has read: %s\n", buff);
            memset(shm, '\0', sizeof(shm));
        }
    }

    if (shmdt(shm) == -1)
    {
        perror("Error while detaching memory segment\n");
        exit(-3);
    }

    if (shmctl(shmid, IPC_RMID, 0) == -1)
    {
        perror("Error while deleting the memory segments\n");
        exit(-1);
    }
}
