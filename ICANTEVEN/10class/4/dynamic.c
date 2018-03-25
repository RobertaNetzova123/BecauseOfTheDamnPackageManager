#include <stdio.h>
#include <stdlib.h>

int main ()
{
        int size;
        scanf("%d",&size);
        char *letter = malloc(sizeof(char)*size);
        for (int i =0; i < size; i++)
        {
                getchar();
                scanf("%c",&letter[i]);
        }
        for (int i = size - 1; i >= 0; i--)
        {
                printf("%c",letter[i]);
        }
        free(letter);
        return 0;
}                          
