#include <stdio.h>
int main ()
{
	int n,i;
	float sum;
	sum=0;
	i=0;
	do
	{
		scanf("%d",&n);
	}while(n<1 || n>9999);

	do
	{
		sum=n%10+sum;
		n=n/10;
		i++;
	}while(n>0);
	
	sum=sum/i;
	if(sum>7) printf("heavy\n");
	else printf("light\n");
	return 0;
}
