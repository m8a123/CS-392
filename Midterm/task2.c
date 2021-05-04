#include<stdio.h>
#include<string.h>
// Mehta Nimtrakul
// I pledge my honor that I have abided by the Stevens Honor System.

int my_strcmp(char *s1, char *s2) 
{ 
	int i; 
	for (i = 0; s1[i] && s2[i]; i++) 
	{ 
		if (s1[i] == s2[i] || (s1[i] ^ 32) == s2[i]) continue; 
		else
		break; 
	} 

	if (s1[i] == s2[i]) 
		return 0; 
	
	if ((s1[i] | 32) < (s2[i] | 32)) 
		return -1; 
	return 1; 
} 

char* my_strcpy(char* dest, const char* source)
{
	if (dest == NULL){
		return NULL;
	}

	// take a pointer pointing to the beginning of destination string
	char *ptr = dest;
	
	while (*source != '\0')
	{
		*dest = *source;
		dest++;
		source++;
	}

	*dest = '\0';
	return ptr;
}

void cs392_str_sort(char ** strlist, int number){

	/* Please write down your code here */
	char temp[30];
	int len = number;

	for(int i = 0; i < len; i++){
		for(int j = 0; j < len-i-1; j++){
			if(my_strcmp(strlist[j], strlist[j+1])>0){
				my_strcpy(temp, strlist[j]);
				my_strcpy(strlist[j], strlist[j+1]);
				my_strcpy(strlist[j+1], temp);
			}
		}
	}

}


int main(int argc, char ** argv){

	printf("CS_392 midterm task 2: \n");

	printf("        Test case 1:\n");

	char *strlist[5] = {"String1", "STring1", "String1extended", "String", "StRING1"};
	
	cs392_str_sort(strlist, 5);

	printf("	Correct results are: STring1, StRING1, String, String1, String1extended\n");
	printf("	Your results are: %s, %s, %s, %s, %s\n", strlist[0], strlist[1], strlist[2], strlist[3], strlist[4]);

	if(strcmp(strlist[0], "STring1") == 0 && strcmp(strlist[1], "StRING1") == 0 && strcmp(strlist[2], "String") == 0 && strcmp(strlist[3], "String1") == 0 && strcmp(strlist[4], "String1extended") == 0)
			printf("	=== Result: PASSED === \n\n");
		else
			printf("	=== Result: FAILED === \n\n");	

	char *strlist1[5] = {"string2", "s@ing2", "stringA", "sTRING2", "@tring2"};
	
	cs392_str_sort(strlist1, 5);

	printf("	Correct results are: @tring2, s@ing2, sTRING2, string2, stringA\n");
	printf("	Your results are: %s, %s, %s, %s, %s\n", strlist1[0], strlist1[1], strlist1[2], strlist1[3], strlist1[4]);

	if(strcmp(strlist1[0], "@tring2") == 0 && strcmp(strlist1[1], "s@ing2") == 0 && strcmp(strlist1[2], "sTRING2") == 0 && strcmp(strlist1[3], "string2") == 0 && strcmp(strlist1[4], "stringA") == 0)
			printf("	=== Result: PASSED === \n\n");
		else
			printf("	=== Result: FAILED === \n\n");	

	return 0;
}


