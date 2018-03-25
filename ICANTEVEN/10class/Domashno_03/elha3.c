#include <stdio.h>
int main ()
{
	int p,broihash,n;
	scanf("%d",&n);
	p=2;
	broihash=0;
	
	while(p<n)
	{
		broihash=broihash+p*2-1;
		p++;
	}
	printf("%d",&broihash);
	return 0;
		
}
