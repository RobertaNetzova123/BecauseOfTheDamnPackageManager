#include <stdio.h>
int main ()
{
	int n,m,k,count,res,p,d;
	scanf ("%d %d %d",&n,&m,&k);
	count=1;
	res=m*k;
	p=count*m*0.02;
	d=m-p;
	while(n!=0)
	{
		res=res+(k*d);
		count++;
	}
	printf ("%d",res);
	return 0;

}
