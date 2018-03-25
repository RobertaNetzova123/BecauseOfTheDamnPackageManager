#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main ()
{
	/*int array1[5];
	int *arr = array1;
	
	for(int i = 0; i < 6; i++)
	{
		scanf("%d\n",&arr[i]);
		printf("%d",*arr);
	}*/
	/*int g = 5;
	int *arr = &g;
	scanf("%d",arr);
	printf("%p",*arr);*/

	int array[4];
	char array1[4];
	float array2[4];
	int *p = array;
	char *l = array1;
	float *f = array2;
	for (int i = 0; i < 4; i++)
	{
		printf("%p\n",(void*)(p + i));
		printf("%p\n",(void*)(l + i));
		printf("%p\n",(void*)(f + i));
	}
	return 0;
}
