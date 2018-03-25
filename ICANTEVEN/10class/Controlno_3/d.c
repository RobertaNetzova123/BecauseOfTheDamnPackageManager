#include <stdio.h>

int main()
{
	int *arr = malloc(10 * sizeof(int));
	for(int i = 0; i < 10; i++)
	{
		arr[i] = i + 1;
		printf("%d\n",arr[i]);
	}
	free(arr);

	
	return 0;
}
