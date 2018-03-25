#include <stdio.h>

int main ()
{
	float n,m,k,result,count,t;
	scanf ("%f %f %f",&n,&m,&k);
	count=0;
	result=0;
	t=m*0.02;
	while(n>0)
	{
		if(count==k)
		{
			m=m-t;
			count=0;
		}
		result=result+m;
		n--;
		count++;
	}
	printf ("%.f",result);
	return 0;
}
