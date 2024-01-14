#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <pthread.h>

void *PrintStars(void *arg)
{
    intptr_t thr = (intptr_t)arg;
    for (int i = 0; i < thr; i++)
    {
        printf("*");
    }
    printf("\n");
    pthread_exit(NULL);
}

int main()
{
    pthread_t thread_id[5];
    for (int i = 0; i < 5; i++)
    {
        printf("Creating thread %d...\n", i);
        int status = pthread_create(&thread_id[i], NULL, PrintStars, (void *)((intptr_t)i));
        // printf("Thread %d created returning status: %d\n", i, status);
        if (status)
        {
            printf("Error: Unable to create thread: %d due to %d\n", i, status);
            exit(-1);
        }
    }

    for (int i = 0; i < 5; i++)
    {
        pthread_join(thread_id[i], NULL);
    };

    return 0;
}