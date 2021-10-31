// Client code 
#include <stdio.h>
#include <stdlib.h>
#include "ss.h"

int main(int argc, char const *argv[]) 
{
	int n; //size of the array
	int *arr; //array of size n
	int key; //key to be searched
	int res; //location of key in arr
	int i;

	printf("Enter number of elements : ");
	scanf("%d", &n);
	arr = (int *) malloc(n * sizeof(n));
    printf("Enter elements : \n");
	for (i = 0; i < n; ++i) 
	{
		scanf("%d", &arr[i]);
	}
    printf("Enter elements to be searched : ");
	scanf("%d", &key);
	res = seqsearch(arr, n, key); //to get the first occurrence of key in arr
	printf("Searched element is at %d index.\n", res);
	free(arr);
	return 0;
}

//returns the duration from start to end times in sec

