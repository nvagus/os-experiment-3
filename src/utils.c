/*	PB15111599 Mingxiao An
 *	utilities
 *	project: os-experiment-3
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/msg.h>
#include "oe3.h"

int reader(int media) {
	buffer s;
	pid_t pid = getpid();
	do {
		memset(s, 0x00, BUF);
		read(media, s, BUF);
		printf("Process %d: %s", pid, s);
	} while (strcmp(s, EXIT_EXP));
	printf("Process %d exit\n", pid);
	return 0;
}

int writer(int media) {
	buffer s;
	pid_t pid = getpid();
	do {
		memset(s, 0x00, BUF);
		printf("Process %d: ", pid);
		fgets(s, BUF, stdin);
		write(media, s, strlen(s));
		sleep(1);
	} while (strcmp(s, EXIT_EXP));
	printf("Process %d exit\n", pid);
	return 0;
}

struct msg {
	long type;
	buffer s;
};

struct msg_recv {
	long type;
	buffer s;
	buffer _in_case_stack_smashing;
};

int receiver(int media) {
	struct msg_recv data;
	pid_t pid = getpid();
	do {
		memset(data.s, 0x00, BUF);
		msgrcv(media, (void*)&data, sizeof(struct msg), 0, 0);
		printf("Process %d: %s", pid, data.s);
	} while (strcmp(data.s, EXIT_EXP));
	printf("Process %d exit\n", pid);
	return 0;
}

int sender(int media) {
	struct msg data;
	pid_t pid = getpid();
	data.type = 1;
	do {
		memset(data.s, 0x00, BUF);
		printf("Process %d: ", pid);
		fgets(data.s, BUF, stdin);
		msgsnd(media, (void*)&data, sizeof(struct msg), 0);
		sleep(1);
	} while (strcmp(data.s, EXIT_EXP));
	printf("Process %d exit\n", pid);
	return 0;
}
