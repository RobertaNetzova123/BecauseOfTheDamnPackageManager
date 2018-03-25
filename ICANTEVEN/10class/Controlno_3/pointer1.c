#include <stdio.h>

void by_two(int*, int);
void product(int*, int, int*);
int *last_index_of(int*, int, int);

int main()
{
	/*t arr[10];
	int i, size = 10;
	for(i = 0; i < size; i++)
	{
		scanf("%d",&arr[i]);
	}
	by_two(&arr,size);
	return 0;*/

	int arr[10];
	int size, i;
	int prod[3];
	scanf("%d",&size);
	for(i = 0; i < size; i++)
	{
		scanf("%d",&arr[i]);
	}
	product(&arr,size,&prod);
	return 0;
}

/*id by_two(int *arr, int size)
{
	int i, b = 0;
	for (i = 0; i < size; i++)
	{
		arr[b] = arr[i] * 2;
		printf("%d\n",arr[b]);
		b++;
	}
}*/

void product(int *arr, int size, int *prod)
{
	int k = 0, i;
	if(size == 0) prod[k] = 0;
	for(i = 0; i < size; i++)
	{
		prod[k] = prod[k] * arr[i];
	}
	printf("%d\n",prod[k]);
}
