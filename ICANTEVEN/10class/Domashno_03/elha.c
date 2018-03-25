#include <stdio.h>
int main ()
{
	int n,red,hash,space,star,p,end;
	scanf("%d",&n);
	star=0;
	hash=0;
	red=1;
	space=0;
	end=0;
	star=n;
	for(red=1;red<=n*2;red=red+2)
	{
		if(red>2) {end=end+(red-2);}
	}

	for(red=1;red<=n*2;red=red+2)
	{
		for(space=1;space<=star;space++)
		{
			printf (" ");
		}
		if(hash>1)
		{
			printf("*");
		}
		for(hash=2;hash<red;hash++)
		{
			printf("#");
		}
		printf ("*");
		printf("\n");
		star=star-1;
	}
	for(p=0;p<red;p++)
	{
		printf("*");
	}
	return 0;
}
