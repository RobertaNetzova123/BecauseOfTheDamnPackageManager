#include <stdio.h>
int sum(int a,int b);

int main ()
{
	int a,b;
	printf ("\n Input a:");
	scanf ("%d",&a);
	printf("\n Input b:");
	scanf("%d",&b);
	printf("%d",sum(a,b));
	return 0;
}

int sum (int a, int b)
{
	int sum;
	sum=a+b;
	return sum;
}
