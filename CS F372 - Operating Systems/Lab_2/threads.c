#include <pthread.h>
#include <stdlib.h>
#include <stdio.h>

int sum;

void *runner(void *param){
    printf("Start of 1st Thread\n");
    int i;
    int upper = atoi(param);
    sum = 0;
    for(int i=1; i<=upper; i++){
        printf("%d\n", i);
        sum += i;
    }
    printf("End of 1st Thread\n");
    pthread_exit(0);
}

void *runner2(void *param){
    printf("Start of 2nd Thread\n");
    int i;
    int upper = atoi(param);
    sum = 0;
    for(int i=1; i<=upper*10; i++){
        printf("%d\n", i);
        sum += i;
    }
    printf("End of 2nd Thread\n");
    pthread_exit(0);
}

int main(int argc, char* argv[]){
    pthread_t tid;
    pthread_t tid2;
    pthread_attr_t attr;

    pthread_attr_init(&attr);
    pthread_create(&tid, &attr, runner, argv[1]);
    pthread_create(&tid2, &attr, runner2, argv[1]);
    pthread_join(tid, NULL);
    printf("\nSUM = %d", sum);
    printf("End of main\n");
}