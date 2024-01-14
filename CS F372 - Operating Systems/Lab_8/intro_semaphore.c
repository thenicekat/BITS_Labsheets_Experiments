#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <sys/wait.h>
#include <unistd.h>

int sharedResource[] = {0, 0};
sem_t sem;

void *runner(void *arg)
{
    int *x = (int *)arg;
    sem_wait(&sem);
    int sem_value;
    sem_getvalue(&sem, &sem_value);
    printf("Value at %ld\n", sem_value);
    sharedResource[(*x % 2)]++;
    printf("Updated Value at %d: %d\n", *x % 2, sharedResource[(*x % 2)]);
    sem_post(&sem);
    sleep(2);
}

int main()
{
    int thread_ids[] = {0, 1, 2, 3, 4};
    pthread_t threads[5];

    sem_init(&sem, 0, 10);

    int sem_value;
    sem_getvalue(&sem, &sem_value);
    printf("Value at %ld\n", sem_value);

    for (int i = 0; i < 5; i++)
    {
        pthread_create(&threads[i], NULL, runner, (void *)&thread_ids[i]);
    }
    for (int i = 0; i < 5; i++)
    {
        pthread_join(threads[i], NULL);
    }

    sem_destroy(&sem);

    return 0;
}