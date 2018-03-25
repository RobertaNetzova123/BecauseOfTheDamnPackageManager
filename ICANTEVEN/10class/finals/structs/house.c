#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct house_t
{
	int floors;
	float area;
	int is_decorated;
};

struct house_t buy_house(struct house_t houses[10]);

int main()
{
	struct house_t houses[10];
	for(int i = 0; i < 2; i++)
	{
		printf("Count of floors: ");
		scanf("%d",&houses[i].floors);
		printf("Area: ");
		scanf("%f",&houses[i].area);
		printf("Is the house decorated: ");
		scanf("%d",&houses[i].is_decorated);
	}
	
	struct house_t home = buy_house(houses);
	printf("%d\n %f\n %d\n",home.floors, home.area, home.is_decorated);
	return 0;
}

struct house_t buy_house(struct house_t houses[10])
{
	for(int i = 0; i < 10; i++)
	{
		if(houses[i].floors >= 2 && houses[i].area >= 1 && houses[i].is_decorated == 1)
		{
			return houses[i];
		}
	}
}
