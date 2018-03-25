#include <stdio.h>
#include <stdlib.h>
int main ()
{
	int size;
	scanf("%d",&size);
	char *arr = malloc(size * sizeof(char));

	for (int i = 0; i < size; i++)
	{
		getchar();
		scanf("%c",&arr[i]);
	}	
	for(int i = size - 1; i >= 0; i--)
	{
		printf("%c",arr[i]);
	}
	free(arr);
	
	return 0;
}	
