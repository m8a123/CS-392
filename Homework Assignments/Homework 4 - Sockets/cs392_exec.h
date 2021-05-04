#include <stdio.h>
#include <sys/wait.h> 
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <sys/wait.h>
#include <string.h>
#include <errno.h>

#ifndef cs392_exec
#define cs392_exec

char **parse_command(char *input);

int get_length(char **command);

void exec(char *args);

#endif