#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void reverse(char*);

int main()
{
	char arr[50];
	fgets(arr,50,stdin);
	reverse(arr);
	printf("%s\n",arr);
	return 0;
}

void reverse(char *arr)
{
	int lenght = strlen(arr);
	for(int i = 0; i < lenght / 2 ; i++)
	{
		char new = arr[i];
		arr[i] = arr[lenght - i - 1];
		arr[lenght - i -1] = new;
	}
}
