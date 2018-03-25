#include <stdio.h>

void swap (void *a, void *b, size_t size);

void swap (void *a, void *b, size_t size)
{
	char *help_a = (char*)a;
	char *help_b = (char*)b;
	size_t k;
	char new;

	for(k = 0; k < size; k++)
	{
		new = help_a[k];
		help_a[k] = help_b[k];
		help_b[k] = new;
	}

}
