#include <stdio.h>
#include <stdlib.h>

void rotl(int *a, int *b, int *c);

int main()
{
	int a,b,c;
	scanf("%d",&a);
	scanf("%d",&b);
	scanf("%d",&c);
	rotl(&a,&b,&c);
	return 0;
}

void rotl(int *a, int *b, int *c)
{
	int temp = *a;
	int temp2 = *b;
	*a = temp2;
	*b = *c;
	*c = temp;
	printf("new a: %d\n new b: %d\n new c: %d\n",*a,*b,*c);
}
