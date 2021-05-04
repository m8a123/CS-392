#include <stdio.h>
#include <sys/wait.h> 
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <sys/wait.h>
#include <string.h>
#include <errno.h>

#include "cs392_signal.h"

// register handlers for SIGINT AND SIGTSTP
void register_handler(){
	struct sigaction act;
 
	memset (&act, '\0', sizeof(act));
 
	act.sa_handler = &sighandler;
	act.sa_flags = SA_SIGINFO;
 
	if ((sigaction(SIGINT, &act, NULL) != 0) || (sigaction(SIGTSTP, &act, NULL) != 0)){
		perror("Sigaction error");
		exit(0);
	}
}


void sighandler(int sig) {
	if (sig == SIGINT){
		printf("signal: SIGINT\n");
	}
	else if (sig == SIGTSTP){
		printf("signal: SIGTSTP\n");
	}
}
