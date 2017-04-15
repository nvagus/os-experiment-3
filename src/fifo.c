/*	PB15111599 Mingxiao An
 *	communicating between processes using fifo
 *	project: os-experiment-3
 */

#include <fcntl.h>
#include <stdio.h>

#include <string.h>
#include <unistd.h>
#include <sys/stat.h>
#include "oe3.h"

#define PATH_MAX 256

int main(int argc, char *argv[], char *env[]) {
	char fifoname[PATH_MAX];
	char mode = getopt(argc, argv, "rw");
	if (mode == -1) {
		printf("You should start the process with either -r or -w\n");
		return 1;
	} else if (mode == 'r' || mode == 'w') {
		memset(fifoname, 0x00, PATH_MAX);
		if (optind < argc) {
			sprintf(fifoname, "/tmp/fifo-%s", argv[optind]);
		} else {
			sprintf(fifoname, "/tmp/fifo-%d", getpid());
		}
		if (access(fifoname, F_OK) == -1) {
			if (mkfifo(fifoname, 0666) == 0) {
				printf("Generate FIFO: %s\n", fifoname);
			}
		}
		if (mode == 'r') {
			int fifo = open(fifoname, O_RDONLY);
			if (fifo == -1) {
				printf("Can't open %s\n", fifoname);
				return 1;
			}
			return reader(fifo);
		} else if (mode == 'w') {
			int fifo = open(fifoname, O_WRONLY);
			if (fifo == -1) {
				printf("Can't open %s\n", fifoname);
				return 1;
			}
			return writer(fifo);
		}
	}
	return 1;
}
