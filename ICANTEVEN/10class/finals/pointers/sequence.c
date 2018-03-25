#include <stdio.h>
#include <stdlib.h>

int print_sequence(int *start,int *end);

int main()
{
	int arr[10];
	int result = print_sequence(&arr[0],&arr[7]);
	printf("%d\n",result);
	return 0;
}

int print_sequence(int *start, int *end)
{
	int count;
	for (int *i = start; i != end; i++)
	{
		printf("%d\n",*i);
		count++;
	}
	return count;
}
