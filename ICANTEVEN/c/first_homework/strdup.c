#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *strdup (const char *);

char *strdup (const char *text)
{
	char *help = malloc(strlen(text) + 1);
	if (help != NULL)
	{
		strcpy(help, text);
	}
	return help;
}
