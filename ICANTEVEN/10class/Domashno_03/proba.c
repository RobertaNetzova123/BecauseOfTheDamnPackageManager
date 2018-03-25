#include <stdio.h>
int main ()
{
	int broistola,cena,navsekiK,sum,i,otstupka;
	scanf ("%d %d %d",&broistola,&cena,&navsekiK);
	sum=0;
	i=0;
	otstupka=0;
	otstupka=(cena*2)/100;
	while(broistola!=0)
	{
		if(i==navsekiK)
		{
			cena=cena-otstupka;
			i=0;
		}
		sum=sum+cena;
		broistola--;
		i++;
	}
	printf ("%d",sum);
	return 0;
	
	
}

