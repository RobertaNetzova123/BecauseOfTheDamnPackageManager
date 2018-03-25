#include <stdio.h>
#include <stdlib.h>

int main ()
{
	int arr[4];
	int *ptr;
	
	ptr = arr;
	
	printf("%d\n",*arr);
	printf("%d\n",*(arr + 4));

	for(; ptr != arr + 4; ptr++)
	{
		printf("%d",*ptr);
	}		

	printf ("\n");
	return 0;
}
