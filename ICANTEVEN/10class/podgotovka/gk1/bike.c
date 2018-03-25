#include <stdio.h>

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
	struct bike_t bikes[50];
	int total_bikes;
	int max_bikes;
};

/* struct bikeshop_t add_bike (struct bikeshop_t, struct bike_t); */
/* float avrg_bike_price (struct bikeshop_t); 
float most_expensive_bike_without_DDS (struct bike_t); */
void print_bike (struct bike_t);
/* struct bike_t find_bike (struct bikeshop_t, float, char); */


int main()
{
	struct bike_t b;
	
	scanf("%d ",&b.tire_size);
	scanf("%d ",&b.gears);
	scanf("%s ",b.brand);
	scanf("%s ",b.model);
	scanf("%c ",&b.frame_size);
	scanf("%f ",&b.price);
	
	print_bike(b);
	struct bikeshop_t bikeshop;

	/* bikeshop.total_bikes = 0;
	bikeshop.max_bikes = 50;
	bikeshop = add_bike (bikeshop,b);
	print_bike (bikeshop.bikes[0]);
	printf ("%d", bikeshop.total_bikes);
	*/
	return 0;
}

void print_bike (struct bike_t bike)
{
	printf ("Tire's Size: %d \n", bike.tire_size);
	printf ("Gears: %d \n", bike.gears);
	printf ("Brand: %s \n", bike.brand);
	printf ("Model: %s \n", bike.model);
	printf ("Frame size: %c \n", bike.frame_size);
	printf ("Price: %f", bike.price);
}

/* struct bikeshop_t add_bike (struct bikeshop_t shop, struct bike_t bike)
{
	if(shop.total_bikes < shop.max_bikes)
	{
		shop.bikes[shop.total_bikes] = bike;
		shop.total_bikes++;
	}
	return shop;
} */

