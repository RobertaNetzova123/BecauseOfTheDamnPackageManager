#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct type_t
{
	char arr[10];
	double arr2[10];
	short arr3[10];
};

int main()
{
	struct type_t type;
        char *c = &type.arr[10];
        double *d = &type.arr2[10];
	short *s = &type.arr3[10];

	for(int i = 0; i < 2; i++)
	{ 
		printf("%p\n",(void*)(c + i));
		printf("%p\n",(void*)(d + i));
		printf("%p\n",(void*)(s + i));
	}

	printf("%d\n", sizeof(char));
	printf("%d\n", sizeof(double));
	printf("%d\n", sizeof(short));

				
	return 0;
	
}
