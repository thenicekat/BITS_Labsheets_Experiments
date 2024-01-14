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
	
	printf("Writer is ready to send messages. \nEnter lines of text, CTRL+D to end: \n");

	
	int i = 10;
	while(fgets((buf.mtext), sizeof(buf.mtext), stdin) != NULL){
		buf.mtype = i;
		len = strlen(buf.mtext);
		if(buf.mtext[len-1] == '\n')
			buf.mtext[len-1] = '\0';
		if(msgsnd(msgid, &buf, len + 1, 0) == -1){
			perror("Message could not be sent, please try again");
			exit(-3);
		}
		i--;
	}
	
	if(msgctl(msgid, IPC_RMID, NULL) == -1){
		perror("Error in line 41");
		exit(-4);
	}
}