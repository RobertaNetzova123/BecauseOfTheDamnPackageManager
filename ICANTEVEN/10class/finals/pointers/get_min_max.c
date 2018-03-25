#include <stdio.h>
#include <stdlib.h>

void get_min_max(int *arr,int *min, int *max,int size);

int main ()
{
	int array[10];
	int *min = array, *max =  array;
	int size = sizeof(array)/4;
	get_min_max(array,min,max,size);
	return 0;	
}

void get_min_max(int *arr,int *min, int *max, int size)
{
	if(size == 0)
	{	
		min = NULL;
		max = NULL;
	}
	
	*min = *arr;
	*max = *arr;
	for(int i = 0; i < size; i++)
	{
		if(*min > *(arr + i)) min = (arr + i);
		if(*max < *(arr + i)) max = (arr + i);
	}	
	printf("Min: %p\n %d\n",(void*)min,*min);
	printf("Max: %p\n %d\n",(void*)max,*max);

}
