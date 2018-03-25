#include <stdio.h>
#include <stdlib.h>

struct bike_t
{
	int tire_size;
	int gears;
	char brand[50];
	char model[15];
	char frame_size;
	float price;
};

struct bikeshop_t
{
	int total;
	int max;
	struct bike_t bikes[50];
}

struct bikeshop_t add_bike(struct bike_t, struct bikeshop_t);
float avrg_bike_price(struct bikeshop_t);
int main ()
{
	return 0;
}

struct bikeshop_t add_bike(struct bike_t shop, struct bikeshop_t bike)
{
	if(shop.total < shop.max)
	{
		shop.bikes[shop.total] = bike;
		shop.total ++;
	}
	return shop;
}

float avrg_bike_price(struct bikeshop_t shop)
{
	float total_price = 0;
	for (int i = 0; i < shop.total; i++)
	{
		total_price = total_price + shop.bikes[i].price;
	}		
	int avrg = total_price / shop.total;
	return avrg;
}


