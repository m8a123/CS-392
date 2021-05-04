#include<stdio.h>
#include<string.h>
#include<stdlib.h>
// Mehta Nimtrakul
// I pledge my honor that I have abided by the Stevens Honor System.

struct cs392_struct{
	int course;
	int student;
	char  semester;
	char string[24];
};


void cs392_read_datastructure(struct cs392_struct * cs_ds, char * fpath){

	/* Please write down your code here  */

	int course;
	int student;
	char semester;
	char string[30];


	FILE *fp;
	fp = fopen(fpath, "r+");
	

	if (fp == NULL) return;

	fscanf(fp, "%d %d %c %s", &cs_ds->course, &cs_ds->student, &cs_ds->semester, cs_ds->string);
	

	fclose(fp);
	return;
}


int main(int argc, char ** argv){


	int index = 0; 

	struct cs392_struct test, res; 

	int course[5] = {123, 345, 456, 789, 868};
	int student[5] = {987,675, 234, 432, 656};
	char semester[5] = {'A', 'B', 'C', 'D', 'E'};
	char string[5][24]= {"This", "Is", "The", "Mid", "Term"};


	for(index = 0; index < 5; index++){
		
		FILE * fp = fopen("/tmp/ds", "w");

		fprintf(fp, "%d %d %c %s",  course[index], student[index], semester[index],string[index]);
		
		fclose(fp);

		memset(&test, 0, sizeof(struct cs392_struct));
		memset(&res, 0, sizeof(struct cs392_struct));
		
		res.course = course[index];
		res.student = student[index]; 
		res.semester = semester[index];
		strcpy(res.string, string[index]);
		
		cs392_read_datastructure(&test, "/tmp/ds");		

		printf("	Test case %d:\n", index);

		if ( memcmp(&res, &test, sizeof(struct cs392_struct)) == 0)
			printf("	=== Result: PASSED === \n\n");
		else
			printf("	=== Result: FAILED === \n\n");	
	
	}


	return 0;
}


