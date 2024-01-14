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

    printf("Enter pid of the process: ");
    int pid;
    scanf("%d", &pid);

    struct timespec ts;
    sched_rr_get_interval(pid, &ts);

    printf("Timeslice: %ld\n", ts.tv_nsec);
}