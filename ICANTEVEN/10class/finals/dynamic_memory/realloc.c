#include <stdio.h>
#include <stdlib.h>

int main()
{
	int size;
	printf("Size: ");
	scanf("%d",&size);

	char *word = malloc(sizeof(char) * size);
		
	int i;
	for(i = 0; scanf("%c",(word + i)) != EOF; i++)
	{
		getchar();
		word = realloc(word,size + 2 + sizeof(char));
	}
	for(int k = 0; k <= i; k++)
	{
		printf("%c\n",*(word + i - k + size));
	}
	free(word);
	return 0;
}
