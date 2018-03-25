#include <stdio.h>
#include <stdlib.h>

void rotl (int*, int*, int*);

int main ()
{
	int a,b,c;
	scanf("%d",&a);
        scanf("%d",&a);
        scanf("%d",&a);

        rotl(&a,&b,&c);
	printf("%d\n", a);
	printf("%d\n", b);
	printf("%d\n", c);


	return 0;
}

void rotl (int *a, int *b, int *c)
{
	int temp = *b;
	int temp2 = *a;

	*a = *c;
	*b = temp2;
	*c = temp;
}
