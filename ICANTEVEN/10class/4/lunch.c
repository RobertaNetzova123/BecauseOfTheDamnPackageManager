#include <stdio.h>
#include <stdlib.h>

struct time_t 
{
	int hours;
	int minutes;
};

int is_lunch_break(struct time_t);

int main ()
{
	struct time_t time;
	scanf("%d", &time.hours);
	scanf("%d", &time.minutes);
	int b = is_lunch_break(time);
	printf("%d",b);
	return 0;
}

int is_lunch_break(struct time_t time)
{
	if (time.hours == 12 && time.minutes >= 15)
	{
		return 1;
	}
	if (time.hours == 13)
	{
		return 1;
	}
	if (time.hours == 14 && time.minutes <= 23)
	{
		return 1;
	}	
	return 0;
}

