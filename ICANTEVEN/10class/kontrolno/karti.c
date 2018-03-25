#include <stdio.h>
#include <string.h>
int main ()
{
	int i,k,found,d;
	char propusk[16]={'2','3','4','5','6','7','8','9','T','J','Q','K','A','\0'};
	char karti[52]={'2','3','4','5','6','7','8','9','T','J','Q','K','A','\0'};
	fgets(karti,52,stdin);
	for (i=0;karti[i]!='\0';i++)
	{
		
		while(propusk[k]!='\0')
		{
			if(karti[i]==propusk[k]) {found++;}
			i++;
		}
		if(found<4) 
		{
			d=karti[i];
			break;
		}
		else 
		{
			i++;
			k=0;
		}
		
	}
	printf("\n missed=%d",d);
	return 0;
	
	


}
