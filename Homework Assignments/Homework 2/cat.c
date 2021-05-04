#include<stdio.h>
#include <stdlib.h>
#include <errno.h>
// Mehta Nimtrakul
// I pledge my honor that I have abided by the Stevens Honor System.
// Implement a simplified version of the "cat" shell command.

// reads all contents from input file and prints the data to the standard output.

int main(int argc, char ** argv){

	
// check if too little or too many arguments
	if (argc != 2){
		printf("Incorrect number of arguments: %d\n", argc);
		exit(1);
	}
// open first argument/file
	FILE *fp = fopen(argv[1], "r");
// check if file is null
	if (fp == NULL){
		printf("Cannot open file \n");
		exit(1);
	}
// allocate memory
	char *readStr = malloc(20);
	int size;

	while((size = fread(readStr, sizeof(char), 20, fp)) > 0){
		if(ferror(fp)){
			printf("Cannot read data due to error %d\n", errno);
		}
		fwrite(readStr, sizeof(char), size, stdout);
	} 

	free(readStr);
	
	fclose(fp);

	return 0;
}