#include <stdio.h>
int count (int a, int b);

int main ()
{
        int a,b;
        printf ("\n Input a:");
        scanf ("%d",&a);
        printf("\n Input b:");
        scanf("%d",&b);
        printf("%d",count(a,b));
        return 0;
}

int count (int a, int b)
{
        int count;
        count=a*b;
        return count;
}

