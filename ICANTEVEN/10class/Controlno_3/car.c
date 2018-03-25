#include <stdio.h>

struct driving_license_t 
{
	char category[20];
	int master;
};

int can_drive(struct driving_license_t, char[3]);

int main()
{
	int i;
	char client[3];
	struct driving_license_t basic;
	fgets(basic.category,20,stdin);
	fgets(client,3,stdin);
	scanf("%d",&basic.master);
	
	if(can_drive(basic,client) == 1) printf("Yes\n");
	else printf("No\n");

	for(i = 0; basic.category[i] != '\0'; i++)
	{
		printf("%c", basic.category[i]);
	}	
	return 0;
}

int can_drive(struct driving_license_t basic, char client[3])
{
	int i, p = 0;
	for(i = 0; basic.category != '\0'; i++)
	{
		if (basic.category[i] == client [p])
		{
			if(client[p+1] != '\0')
			{
				if (client[p+1] <= '5') return 1;
				else if(basic.master == 1) return 1;
			}
		}
	}
	return 0;
}
