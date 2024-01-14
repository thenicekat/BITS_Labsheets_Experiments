#include <stdio.h>
#include <stdlib.h>
#include <sched.h>
#include <pthread.h>

void *thread1(void *arg)
{
    for (int i = 0; i < 10; i++)
    {
        printf("Thread 1 --> %d\n", i);
        sleep(5);
    }
    pthread_exit(NULL);
}

void *thread2(void *arg)
{
    for (int i = 0; i < 10; i++)
    {
        printf("Thread 2 --> %d\n", i);
        sleep(5);
    }
    pthread_exit(NULL);
}

int main()
{
    pthread_t threads[2];
    pthread_attr_t attr[2];
    for (int i = 0; i < 2; i++)
    {
        pthread_attr_init(&attr[i]);
    }

    // Get current policy
    int policy;

    // Execute threads
    for (int i = 0; i < 2; i++)
    {
        pthread_attr_getschedpolicy(&attr[i], &policy);
        printf("Current policy for %d = %d\n", i + 1, policy);

        // Set policy for both to RR
        pthread_attr_setschedpolicy(&attr[i], SCHED_RR);
        pthread_attr_getschedpolicy(&attr[i], &policy);
        printf("Modified policy for %d = %d\n", i + 1, policy);

        if (i == 0)
            pthread_create(&threads[i], NULL, thread1, NULL);
        else
            pthread_create(&threads[i], NULL, thread2, NULL);
    }

    for (int i = 0; i < 2; i++)
        pthread_join(threads[i], NULL);
}