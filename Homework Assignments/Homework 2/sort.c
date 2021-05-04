#include "sort.h"
#define NUM_SIZE 100000;
// Mehta Nimtrakul
// I pledge my honor that I have abided by the Stevens Honor System.
// Task 2: Given input file, convert strings of digits to integers, 
// sort the integers, and save to output file as strings.
// each integer string should take one line in the output file 

// reads all contents from input file, converts to int, sort, 
// convert to string, and write to 2nd file.



void swap(int* a, int* b){
	int t = *a;
	*a = *b;
	*b = t;
}

int partition (int arr[], int low, int high) 
{ 
    int pivot = arr[high];    // pivot 
    int i = (low - 1);  // Index of smaller element 
  
    for (int j = low; j <= high- 1; j++) 
    { 
        // If current element is smaller than the pivot 
        if (arr[j] < pivot) 
        { 
            i++;    
            swap(&arr[i], &arr[j]); 
        } 
    } 
    swap(&arr[i + 1], &arr[high]); 
    return (i + 1); 
} 

void quickSort(int arr[], int low, int high) 
{ 
    if (low < high) 
    { 
        /* pi is partitioning index, arr[p] is now 
           at right place */
        int pi = partition(arr, low, high); 
  
        // Separately sort elements before 
        // partition and after partition 
        quickSort(arr, low, pi - 1); 
        quickSort(arr, pi + 1, high); 
    } 
} 

int main(int argc, char ** argv){
// check if too little or too many arguments
	int nums = NUM_SIZE;
	int arr[nums];
	int n; 
	char c; 

	if (argc != 3){
		printf("Incorrect number of arguments: %d\n", argc);
		exit(1);
	}
// open file reading from
	FILE *fp1 = fopen(argv[1], "r");
// check if file is null
	if (fp1 == NULL){
		printf("Cannot open file \n");
		exit(1);
	}

	
	int count = 0;
	
	
	while(count < nums && fscanf(fp1, "%d", &n) == 1){
		arr[count] = n;
		count++;
	}
	fclose(fp1); 

	quickSort(arr, 0, count-1);

	FILE *fp2 = fopen(argv[2], "w");
	if (fp2 == NULL){
		printf("Cannot open file \n");
		exit(1);
	}
	
	fwrite(arr, sizeof(int), count, fp2);
	
	fclose(fp2);

}