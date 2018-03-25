#include <stdio.h>
#include <stdlib.h>

void by_two(int*,int);
void product(int*,int,int*);
int *last_index_of(int*,int,int);
int copy_only_positive(int*,int,int*);
void print(int*,int);
int main()
{
	int arr[] = {1, -2, 3, 4};
	print(arr,4);
	by_two(arr,4);
	print(arr,4);
	int *element = last_index_of(arr,4,6);
	if(element != NULL)
	{
		printf("%d\n", *element);
	}
	else { printf("No such element!"); }

	int positive_arr[20];
	int positive_size = copy_only_positive(arr,4,positive_arr);
	print(positive_arr, positive_size);

	return 0;
}

void by_two(int *arr, int size)
{
	for(int i = 0; i < size; i++)
	{
		*(arr + i) = arr[i] * 2;
	}
}

void product(int *arr, int size, int *prod)
{
	if(size == 0) { return; }
	*prod = 1;
	for(int i = 0; i < size; i++)
	{
		*prod = arr[i];
	}
}

int *last_index_of(int *arr, int size, int item)
{
	int p = -1;
	for(int i = 0; i < size; i++)
	{
		if(arr[i] == item) { p = 1; }
	}	
	if( p == -1) { return NULL;}
	else return arr + p;
	
	return 0;
}

int copy_only_positive(int *arr, int size, int *positive_arr)
{
	int positive = 0;
	for(int i = 0; i < size; i++)
	{
		if(arr[i] > 0)
		{
			positive_arr[positive++] = arr[i];
		}
	}
	return positive;
}

void print(int *arr, int size)
{
	for(int i = 0; i < size; i++)
	{	
		printf("%d\n",arr[i]);
	}
}
