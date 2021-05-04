#include <stdio.h>
#include <sys/wait.h> 
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <sys/wait.h>
#include <string.h>
#include <errno.h>

#ifndef cs392_signal
#define cs392_signal


void register_handler();
void sighandler(int sig);

#endif