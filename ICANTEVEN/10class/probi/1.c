#include <stdio.h>
#include <string.h>
int main ()
{
	char s[80];	
	fgets(s,80,stdin);
	char b[80];
	
	fgets(b,80,stdin);
	
	
	//strcpy(s, "Hello");
	//strcpy(b, " world");
	
	
	strcat(s,b);

	printf("%s",s);

	
	return 0;
	

}
