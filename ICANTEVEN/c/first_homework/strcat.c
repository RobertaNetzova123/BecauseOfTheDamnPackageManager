#include <stdio.h>
char* strcat (char* destination, const char* source);

char* strcat (char* destination, const char* source)
{
	int i = 0;
	for(;destination[i] != '\0'; i++) {
	}

	for(int k =0; source[k] != '\0'; k++, i++) {
		destination[i] = source[k];
	}
	return destination;
}
