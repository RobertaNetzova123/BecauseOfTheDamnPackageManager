#include <stdio.h>
#include <stdlib.h>

void sum(int *arr, int size, int *sum);

int main()
{
	int arr[] = {2,5,6,7,8};
	int sum2;
	sum(arr,5,&sum2);
	printf("%d\n",sum2);
	return 0;
}

void sum(int *arr, int size, int *sum)
{
	*sum = 0;
	for(int i = 0; i < size; i++)
	{
		*sum = *sum + arr[i];
	}

}
