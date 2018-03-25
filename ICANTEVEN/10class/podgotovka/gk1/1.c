#include <stdio.h>
float stepen (float,int);
int main ()
{
	int n;
	float a;
	printf ("\n input a:");
	scanf ("%f",&a);
	printf ("\n input n:");
	scanf ("%d",&n);
	printf("%.2f",stepen(a,n));
	return 0;
}
float stepen (float a,int n)
{
	float temp;
	int i,m;
	if (n>=0) m=n;
	else m=-n;
	temp=1;
	for(i=0;i<m;i++) temp=a*temp;
	if(n<0) temp=1/temp;
	return temp;
}
