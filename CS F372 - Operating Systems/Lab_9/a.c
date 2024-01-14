#define _GNU_SOURCE

#include <stdio.h>
#include <stdlib.h>
#include <sched.h>

int main()
{
    // First print all the schedulers
    printf("SCHED_OTHER: %d\n", SCHED_OTHER);
    printf("SCHED_FIFO: %d\n", SCHED_FIFO);
    printf("SCHED_RR: %d\n", SCHED_RR);
    printf("SCHED_BATCH: %d\n", SCHED_BATCH);
    printf("SCHED_IDLE: %d\n", SCHED_IDLE);
    printf("SCHED_DEADLINE: %d\n", SCHED_DEADLINE);

    printf("\nCurrent scheduler: %d\n", sched_getscheduler(0));
    printf("Choose one: ");

    int scheduler;
    scanf("%d", &scheduler);

    printf("Max priority: %d\n", sched_get_priority_max(scheduler));
    printf("Min priority: %d\n", sched_get_priority_min(scheduler));

    printf("Enter pid of the process to change: ");
    int pid;
    scanf("%d", &pid);

    printf("Before Changing scheduler: %d\n", sched_getscheduler(pid));
    struct sched_param param;
    param.sched_priority = 0;
    sched_setscheduler(pid, scheduler, &param);
    printf("After Changing scheduler: %d\n", sched_getscheduler(pid));
}