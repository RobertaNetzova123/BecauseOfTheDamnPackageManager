#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void swap (int*a, int*b);

int main()
{
	int a,b;
	printf("a: ");
	scanf("%d",&a);
	printf("b: ");
	scanf("%d",&b);
	swap(&a,&b);
	return 0;
}

void swap (int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
	printf("new a: %d\n new b: %d\n",*a,*b);
	
}
