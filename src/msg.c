/*	PB15111599 Mingxiao An
 *	communicating between processes using message
 *	project: os-experiment-3
 */

#include <stdio.h>
#include <unistd.h>
#include <sys/msg.h>
#include "oe3.h"

int main(int argc, char *argv[], char *env[]) {
	key_t key;
	char mode = getopt(argc, argv, "rs");
	if (mode == -1) {
		printf("You should start the process with either -r or -s\n");
		return 1;
	} else if (mode == 'r' || mode == 's') {
		if (optind < argc) {
			if (sscanf(argv[optind], "%d", &key) == 0) {
				printf("Key should be a number\n");
				return 1;
			}
		} else {
			key = (key_t)getpid();
		}
		printf("Linking MSG: %d\n", key);
		int msg = msgget(key, 0666 | IPC_CREAT);
		if (msg == -1) {
			printf("Can't generate MSG: %d\n", key);
			return 1;
		} else if (mode == 'r') {
			return receiver(msg);
		} else if (mode == 's'){
			return sender(msg);
		}
	}
	return 1;
}
