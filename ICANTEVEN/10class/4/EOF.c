#include <stdio.h>
#include  <stdlib.h>

int main ()
{
	int size;
	char *letter = malloc(sizeof(char) * size);
	int count = 0;
	char ch;
	while(scanf("%c",&ch) != EOF)
	{
		getchar();
		letter[count++] = ch;
		if (count == size) 
		{
			 size = size * 2; 
		
			char *new = letter;
			letter = malloc(sizeof(char) * size);
			for (int i = count - 1; i >= 0 ; i--)
			{

				letter[i] = new[i];
			} 
		free(new);
		}
		
	}

	printf ("%s",letter);
	free(letter);
	
	
}
