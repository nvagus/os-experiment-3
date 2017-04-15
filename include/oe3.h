/*	PB15111599 Mingxiao An
 *	header file oe3
 *	project: os-experiment-3
 */

#ifndef OS_EXPERIMET_3
#define OS_EXPERIMET_3

#define BUF	256
typedef char buffer[BUF];
#define EXIT_EXP "#\n"

int reader(int media);
int writer(int media);

int receiver(int media);
int sender(int media);

#endif
