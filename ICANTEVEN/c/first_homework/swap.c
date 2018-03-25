#include <stdio.h>
void swap(int *a, int *b);

void swap(int *a, int *b)
{
	int help = *a;
	*a = *b;
	*b = help;
	
}

