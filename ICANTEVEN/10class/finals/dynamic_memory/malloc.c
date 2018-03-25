#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main ()
{
	int *arr = malloc(sizeof(int) * 10);
	for(int i = 0; i < 10; i++)
	{
		scanf("%d",(arr + i));
	}
	for(int i = 0; i < 10; i++)
	{
		printf("%d\n",*(arr + i));
	}
	free(arr);
	return 0;
}
