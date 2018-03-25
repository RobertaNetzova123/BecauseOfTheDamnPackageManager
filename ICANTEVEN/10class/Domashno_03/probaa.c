#include <stdio.h>
int main ()
{
	float n,k,m,sum;
	scanf("%f %f %f",&n,&m,&k);
	sum=n*m-((2*k+1)*n-(n*n)/k);
	printf ("%.f",sum);
	return 0;
}
