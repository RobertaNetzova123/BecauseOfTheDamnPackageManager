#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

void swap (void *a, void *b, size_t size);
void swap_byte (uint8_t *a, uint8_t *b);

void swap_byte (uint8_t *a, uint8_t *b) {
	uint8_t c = *a;
	*a = *b;
	*b = c;
}

void swap(void *a, void *b, size_t size) {
	uint8_t *first = (uint8_t *)a;
	uint8_t *second = (uint8_t *)b;
	
	for(int i = 0; i < size; ++i) {
		swap_byte(first, second); //swap
		++first;
		++second;
	}
}

int main ()
{
	return 0;
}
