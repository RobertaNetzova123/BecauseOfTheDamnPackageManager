#include <stdio.h>
int main ()
{
	float n,m,k,sum;
	scanf ("%f %f %f",&n,&m,&k);
	sum=0;
	sum=sum+m*((100*n-k*(((n/k)*(n/k-1))))/100);
	printf ("%.f",sum);
	return 0;

}
