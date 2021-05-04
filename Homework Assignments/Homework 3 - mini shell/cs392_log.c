

#include "cs392_log.h"


// Mehta Nimtrakul
// I pledge my honor that I have abided by the Stevens Honor System.

// appends to log commands in a logging file. 
// creates logging file if not there
void logger(char log[]){
	FILE *fp = fopen("cs392_shell.log", "a");
	
	if (fp == NULL){
		fp = fopen("cs392_shell.log", "w");
	}

	fprintf(fp, "%s\n", log);
	fclose(fp);


}