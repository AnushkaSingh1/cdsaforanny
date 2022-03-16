/*Recursive Way :
1) Initialize start and end indexes as start = 0, end = n-1 
2) Swap arr[start] with arr[end] 
3) Recursively call reverse for rest of the array.
*/

// Recursive C program to reverse an array
#include <stdio.h>

/* Function to reverse arr[] from start to end*/
void rvereseArray(int arr[], int start, int end)
{
int temp;
if (start >= end)
	return;
temp = arr[start];
arr[start] = arr[end];
arr[end] = temp;
rvereseArray(arr, start+1, end-1);
}	

/* Utility that prints out an array on a line */
void printArray(int arr[], int size)
{
int i;
for (i=0; i < size; i++)
	printf("%d ", arr[i]);

printf("\n");
}

/* Driver function to test above functions */
int main()
{
	int arr[] = {1, 2, 3, 4, 5, 6};
	printArray(arr, 6);
	rvereseArray(arr, 0, 5);
	printf("Reversed array is \n");
	printArray(arr, 6);
	return 0;
}


/*
Output : 

1 2 3 4 5 6 
Reversed array is 
6 5 4 3 2 1 


Time Complexity : O(n)
*/
