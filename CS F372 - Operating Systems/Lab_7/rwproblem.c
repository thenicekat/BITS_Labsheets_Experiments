#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <sys/wait.h>

pthread_mutex_t write;
pthread_mutex_t read;

int count = 1;
int numReader = 0;

void *writer(void *arg)
{
    pthread_mutex_lock(&write);
    count *= 2;
    printf("Writer %d modified count to %d\n", *((int *)arg), count);
    pthread_mutex_unlock(&write);
}

void *reader(void *arg)
{
    pthread_mutex_lock(&read);
    numReader++;
    if (numReader == 1)
    {
        pthread_mutex_lock(&write);
    }
    pthread_mutex_unlock(&read);

    printf("Reader %d reading count as %d\n", *((int *)arg), count);

    pthread_mutex_lock(&read);
    numReader--;
    if (numReader == 0)
    {
        pthread_mutex_unlock(&write);
    }
    pthread_mutex_unlock(&read);
}

int main()
{
    pthread_t readerThreads[5], writerThreads[5];
    pthread_mutex_init(&read, NULL);
    pthread_mutex_init(&write, NULL);

    int arrIds[] = {1, 2, 3, 4, 5};

    for (int i = 0; i < 5; i++)
    {
        pthread_create(&readerThreads[i], NULL, (void *)reader, (void *)&arrIds[i]);
        pthread_create(&writerThreads[i], NULL, (void *)writer, (void *)&arrIds[i]);
    }

    for (int i = 0; i < 5; i++)
    {
        pthread_join(readerThreads[i], NULL);
        pthread_join(writerThreads[i], NULL);
    }

    pthread_mutex_destroy(&write);
    pthread_mutex_destroy(&read);
    return 0;
}