#include<stdio.h>
#include<string.h>
// Mehta Nimtrakul
// I pledge my honor that I have abided by the Stevens Honor System.

int strlength(char *str) {
	int i=0;
	while (str[i++] != '\0');
	return i-1;
} 

void cs392_reversestr(char * str){

	/*Please write down your code here*/
	int l;
    char *start, *end, ch; 
  
    // Get the length of the string 
    l = strlength(str); 
  
    start = str; 
    end = str; 
  
    for (int i = 0; i < l - 1; i++) 
        end++; 
  
    for (int i = 0; i < l / 2; i++) { 
    // swap 
        ch = *end; 
        *end = *start; 
        *start = ch; 
  
        start++; 
        end--; 
    } 

}


int main(int argc, char ** argv){

	int index; 
	char src[128];
	char dst[128];

	printf("CS_392 midterm task 1: \n");

	index = 1; 

	while(index <= 5){

		printf("	Test case %d:\n", index);

		memset(src, 0, 128);
		memset(dst, 0, 128);

		strcpy(src, argv[index]);
		strcpy(dst, argv[index+5]);

		cs392_reversestr(src);
		
		printf("	Original string: \"%s\"; Reversed string: \"%s\"; \n", argv[index], src);	

		if(strcmp(src, dst) == 0 )	
			printf("	=== Result: PASSED === \n\n");
		else
			printf("	=== Result: FAILED === \n\n");	

		index += 1;
	}

	return 0;
}


