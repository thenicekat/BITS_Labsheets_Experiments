#define _GNU_SOURCE

#include <stdio.h>
#include <stdlib.h>
#include <sched.h>
#include <pthread.h>

void *threadFunction(void *arg)
{
    printf("Hello there :)");
}

int main()
{
    pthread_t thr;
    pthread_attr_t attr;
    pthread_attr_init(&attr);

    int policy;

    pthread_attr_getschedpolicy(&attr, &policy);

    printf("Thread created with default policy: %d\n", policy);

    pthread_attr_setschedpolicy(&attr, SCHED_FIFO);
    pthread_attr_getschedpolicy(&attr, &policy);
    printf("Thread created with FIFO policy: %d\n", policy);
    pthread_create(&thr, NULL, threadFunction, NULL);
}