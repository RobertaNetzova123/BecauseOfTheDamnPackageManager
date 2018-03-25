#include <stdio.h>
int fib (int);


int main ()
{
        int n;
        printf("\n Input n:");
        scanf ("%d",&n);
        printf("%d",fib(n));
        return 0;
}

int fib (int n)
{
        if (n<2) return n;
	else return fib(n-1)+fib(n-2);
}

