#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <string.h>

#define PERMS 0644

struct msgbufs {
	long mtype;
	char mtext[260];
};

int main(void){
	struct msgbufs buf;
    int msgid, len;
	
	key_t key;

    if((key = ftok("sender.c", 'B')) == -1){
		perror("Error while generating key of the file");
		exit(-1);
	}

    if((msgid = msgget(key, PERMS | IPC_CREAT)) == -1){
		perror("Error while connecting with Message Queue");
		exit(-1);
	}

    printf("Receiver is ready to receive messages. \nCTRL+D to end: \n");

	int i = 10;
    while(msgrcv(msgid, &buf, sizeof(buf.mtext), -10, 0) != -1){
        printf("%s\n", buf.mtext);
    }

    if(msgctl(msgid, IPC_RMID, NULL) == -1){
		perror("Error in line 41");
		exit(-4);
	}
}