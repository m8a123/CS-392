#include<stdio.h>
#include<unistd.h>
#include<signal.h>
#include <stdlib.h>
#include <sys/wait.h>

#include "cs392_exec.h"
#include "cs392_log.h"
#include "cs392_signal.h"

#define max_buffer 1024

// Mehta Nimtrakul
// I pledge my honor that I have abided by the Stevens Honor System.

char *read_line(void){

  int size = max_buffer;
  int i = 0;
  char *buffer = malloc(sizeof(char) * size);

  if (!buffer) {
    fprintf(stderr, "Memory allocation error\n");
    exit(EXIT_FAILURE);
  }

  while (1) {
    // Read a char
    int c = getchar();

    // reach null byte then return buffer
    if (c == '\n') {
      buffer[i] = '\0';
      return buffer;
    } 
    else {
      buffer[i] = c;
    }
    i++;

    // reallocate if past buffer
    if (i >= size) {
      size += max_buffer;
      buffer = realloc(buffer, size);
      if (!buffer) {
        fprintf(stderr, "Memory allocation error\n");
        exit(EXIT_FAILURE);
      }
    }
  }
}







int main(int argc, char** argv) {

	while(1){
		
		register_handler();

		printf("cs392_shell $: ");

		// reads input while expanding buffer
		char *input = read_line();

		//logs command
		if (input[0] != 0){
			logger(input);
		}

		// exits if user types "exit"
		if(strcmp(input, "exit") == 0){
    		break;
		}

		exec(input);

		for (int i = 0; input != NULL && input[i] != 0; ++i){
			input[i] = 0;
		}
		free(input);
	}

	

	return EXIT_SUCCESS;
}