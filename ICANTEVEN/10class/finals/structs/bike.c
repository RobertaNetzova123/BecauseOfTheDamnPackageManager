#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct bike_t
{
	int tire_size;
	int gears;
	char brand[50];
	char model[15];
	char frame;
	float price;
};

struct bikeshop_t
{
	struct bike_t bikes[50]; //list of bikes
	int total_bikes; // total count of bikes
	int max_bikes; // capacity of the store
};

struct bikeshop_t add_bike(struct bike_t, struct bikeshop_t);
float avrg_bike_price(struct bikeshop_t);
float expensive_bike(struct bikeshop_t);


int main ()
{
	
	struct bikeshop_t shop;
	shop.total_bikes = 0;
	shop.max_bikes = 50;
	
	int add;
	printf("How much bikes ypu want to add: ");
	scanf("%d",&add);
	
	struct bike_t bikes[50];
	for (int i = 0; i < add; i++)
	{
		printf("Input size of the tires: ");
		scanf("%d",&bikes[i].tire_size);
                printf("Input a gears: ");
		scanf("%d",&bikes[i].gears);
                printf("Input a brand: ");
		fgets(bikes[i].brand,51,stdin);
                printf("Input a model: ");
		fgets(bikes[i].model,15,stdin);
                printf("Input a frame: ");
		scanf("%c",&bikes[i].frame);
                printf("Input a price: ");
		scanf("%f",&bikes[i].price);
		
		shop = add_bike(bikes[i],shop);
		if(shop.total_bikes == shop.max_bikes) break;
	}
	printf("%f",avrg_bike_price(shop));
	printf("%f",expensive_bike(shop));
	return 0;
}

struct bikeshop_t add_bike(struct bike_t bike, struct bikeshop_t shop)
{
	if(shop.total_bikes < shop.max_bikes)
	{
		shop.bikes[shop.total_bikes] = bike;
		shop.total_bikes++;
	}
	return shop;
}

float avrg_bike_price(struct bikeshop_t shop)
{
	float avrg = 0;
	int i;	for (i = 0; i < shop.total_bikes; i++)
	{
		avrg = avrg + shop.bikes[i].price;
	}
	avrg = avrg / i;
	return avrg;
}	

float expensive_bike(struct bikeshop_t shop)
{
	float expensive = 0;
	for (int i = 0; i < shop.total_bikes; i++)
	{
		if (shop.bikes[i].price > expensive)
		{
			expensive = shop.bikes[i].price;
		}
	}	
	return expensive;
}
	

















