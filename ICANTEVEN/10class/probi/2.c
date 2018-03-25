#include <stdio.h>
#include <string.h>
int main ()
{
	char s1[50];
	char s2[50];
	char s3[150];
	int edno,dve,tri;
	tri=0;
	scanf("%s",&s1);
	scanf("%s",&s2);
	//fgets(s2,50,stdin);
	for(edno=0;s1[edno]!='\0';edno++)
	{
		s3[tri]=s1[edno];
		tri++;
	}
	for(dve=0;s2[dve]!='\0';dve++)
	{
		s3[tri]=s2[dve];
		tri++;
	}

	printf("\n%s",s3);
	return 0;
}
