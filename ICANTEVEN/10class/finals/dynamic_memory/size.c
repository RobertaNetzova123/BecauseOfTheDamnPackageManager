#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main()
{
	int size;
	printf("Size: ");
	scanf("%d",&size);

	char *arr = malloc(sizeof(char) * 10);
	for(int i = 0; i < size; i++)
	{
		getchar();
		scanf("%c",(arr + i));
	}
	for(int i = 0; i < size; i++)
	{
		printf("%c\n",*(arr + size - i - 1));
	}
	free(arr);
	return 0;
}
