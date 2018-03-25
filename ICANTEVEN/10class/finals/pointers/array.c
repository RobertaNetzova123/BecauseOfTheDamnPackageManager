#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int all_positive(int*,int);
int *longest_odd_even_chain(int*,int);

int main()
{
	return 0;
}

int all_positive(int *arr, int size)
{
	for(int i = 0; i < size; i++)
	{
		if(arr[i] > 0) return 1;
	}
	return 0;
}

int *longest_odd_even_chain(int *arr,int size)
{
	
}
