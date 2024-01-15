#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <pthread.h>

int arr[5] = {1, 2, 3, 4, 5};
int ind = 0;

pthread_mutex_t lock;

void *solve(void *arg)
{
    pthread_mutex_lock(&lock);
    int *x = (int *)arg;
    printf("%d -> %d\n", ind, arr[ind]);
    ind++;
    pthread_mutex_unlock(&lock);
    pthread_exit(0);
}

int main()
{
    pthread_t threads[5];
    pthread_mutex_init(&lock, NULL);

    for (int i = 0; i < 5; i++)
    {
        pthread_create(&threads[i], NULL, (void *)solve, (void *)(intptr_t)i);
    }

    for (int i = 0; i < 5; i++)
        pthread_join(threads[i], NULL);

    pthread_mutex_destroy(&lock);
}