#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct calendar_t 
{
	int events_count[52];
};

int* events_per_month(struct calendar_t);

int main()
{
	struct calendar_t calendar;
	for(int i = 0; i < 52; i++)
	{
		calendar.events_count[i] = 0;
	}
	calendar.events_count[2] = 76;
	calendar.events_count[3] = 76;
	calendar.events_count[40] = 76;
	
	int *all_events = events_per_month(calendar);
	for(int i = 0; i < 13; i++)
	{
		printf("%d\n",all_events[i]);
	}
	return 0;
}

int* events_per_month(struct calendar_t calendar)
{
	int *month = malloc(sizeof(int) * 13);
	for(int i = 0, k = 0; i < 52; i++)
	{
		month[k] = calendar.events_count[i];
		if(i % 4 == 0) k++;
	}
	return month;
}
