#include <stdio.h>
#include <stdlib.h>

int *find(int *haystack, int size, int needle);

int main ()
{
	int arr[10];
	int *element = find(arr,6,11);
	if(element != NULL)
	{
		printf("%d\n",*element);
	}
	else { printf("No such an element"); }
//	printf("%d\n",*find(arr,4,9) == NULL);
//	printf("%d\n",*find(arr,4,1) == NULL);
//       printf("%d\n",*find(arr,4,4) == NULL);


	return 0;
}

int *find(int *haystack, int size, int needle)
{
	for(int i = 0; i < size; i++)
	{
		if(*(haystack + i) == needle) return &haystack[i];
	}		
	return NULL;
}
