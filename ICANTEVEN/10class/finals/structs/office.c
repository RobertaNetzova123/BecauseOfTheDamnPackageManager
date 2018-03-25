#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct office_t
{
	int rooms;
	float rent;
	int is_kitchen;
};

struct office_t find_office(struct office_t offices[10]);

int main()
{
	struct office_t offices[10];
	for(int i = 0; i < 2; i++)
	{
		printf("Count of the rooms: ");
		scanf("%d",&offices[i].rooms);
		printf("Rent: ");
		scanf("%f",&offices[i].rent);
		printf("Is there a kitchen: ");
		scanf("%d",&offices[i].is_kitchen);
	}

	struct office_t build = find_office(offices);
	printf("%d\n",build.rooms);
        printf("%f\n",build.rent);
        printf("%d\n",build.is_kitchen);

	return 0;
}

struct office_t find_office(struct office_t offices[10])
{
	for(int i = 0; i < 10; i++)
	{
		if(offices[i].rooms >= 3 && offices[i].rent < 500 && offices[i].is_kitchen == 1)
		{
			return offices[i];
		}
	}
}
