/*	PB15111599 Mingxiao An
 *	communicating between processes using pipe
 *	project: os-experiment-3
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "oe3.h"

int main(int argc, char *argv[], char *env[]) {
	int pipedes[2];
	if (pipe(pipedes) == 0) {
		pid_t pid = fork();
		if (pid == -1) {
			printf("Error on fork.\n");
			return 1;
		} else if (pid == 0) {
			return reader(pipedes[0]);
		} else {
			return writer(pipedes[1]);
		}
	}
	return 1;
}
