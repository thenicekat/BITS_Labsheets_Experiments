#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>
#include <pthread.h>
#include <semaphore.h>

int store[5];
int ind = 0;

sem_t checkIfSpaceAvailable;
sem_t checkIfEmpty;
sem_t readOrWrite;

void *producer(void *argc)
{
    int *x = (int *)argc;
    sem_wait(&checkIfSpaceAvailable);

    sem_wait(&readOrWrite);
    printf("Producing\n");
    store[ind]++;
    ind++;
    for (int i = 0; i < 5; i++)
    {
        printf("%d ", store[i]);
    }
    printf("\n");
    sem_post(&readOrWrite);

    sem_post(&checkIfEmpty);
}

void *consumer(void *argc)
{
    int *x = (int *)argc;
    sem_wait(&checkIfEmpty);

    sem_wait(&readOrWrite);
    printf("Consuming\n");
    ind--;
    store[ind] = 0;
    for (int i = 0; i < 5; i++)
    {
        printf("%d ", store[i]);
    }
    printf("\n");
    sem_post(&readOrWrite);

    sem_post(&checkIfSpaceAvailable);
}

int main()
{
    sem_init(&checkIfSpaceAvailable, 0, 5);
    sem_init(&checkIfEmpty, 0, 0);
    sem_init(&readOrWrite, 0, 1);

    int thread_ids[5] = {0, 1, 2, 3, 4};
    pthread_t threads[5];

    for (int i = 0; i < 5; i++)
    {
        pthread_create(&threads[i], NULL, producer, (void *)&thread_ids[i]);
    }

    for (int i = 0; i < 5; i++)
    {
        pthread_create(&threads[i], NULL, consumer, (void *)&thread_ids[i]);
    }

    for (int i = 0; i < 5; i++)
    {
        pthread_join(threads[i], NULL);
    }
}