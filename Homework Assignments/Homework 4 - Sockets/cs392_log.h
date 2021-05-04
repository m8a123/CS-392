#include <stdio.h>
#include <sys/wait.h> 
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <sys/wait.h>
#include <string.h>
#include <errno.h>

#ifndef cs392_log
#define cs392_log

void logger(char log[]);

#endif