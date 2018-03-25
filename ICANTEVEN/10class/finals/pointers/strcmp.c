#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int str_cmp(char*,char*);

int main()
{	
	char first[50], second[50];
	fgets(first,50,stdin);
	fgets(second,50,stdin);
	printf("%d\n",str_cmp(first,second));
	return 0;
}

int str_cmp(char *first, char *second)
{
	int lenght1 = strlen(first);
	int lenght2 = strlen(second);
	int min;
	
	if(lenght1 > lenght2) { min = lenght2; }
	else if (lenght1 < lenght2) { min = lenght1; }

	for(int i = 0; i < min; i++)
	{
		if(first[i] > second[i]) { return 1; }
		else if(first[i] < second[i]) {	return -1; }
	}

	if(lenght1 == lenght2) { return 0; }
	else if(lenght1 > lenght2) { return 1; }
	else if(lenght1 < lenght2) { return -1; }
	return 0;
}
