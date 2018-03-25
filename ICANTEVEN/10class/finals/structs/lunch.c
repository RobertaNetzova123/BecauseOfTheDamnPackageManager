#include <stdio.h>
#include <stdlib.h>

struct time_t
{
	int hours;
	int minutes;
};

struct datetime_t
{
	int month;
	int day;
	struct time_t time;
};

int is_lunch_break(struct time_t);
struct datetime_t datetime(struct datetime_t, struct datetime_t);

int main()
{
	struct datetime_t first;
	struct datetime_t second;
	
	printf("Input month 1: ");
	scanf("%d",&first.month);
        printf("Input month 2: ");
	scanf("%d",&second.month);
        printf("Input day 1: ");
        scanf("%d",&first.day);
        printf("Input day 2: ");
        scanf("%d",&second.day);
        printf("Input hours 1: ");
        scanf("%d",&first.time.hours);
        printf("Input hours 2: ");
        scanf("%d",&second.time.hours);
        printf("Input minutes 1: ");
        scanf("%d",&first.time.minutes);
        printf("Input minutes 2: ");
        scanf("%d",&second.time.minutes);

	//printf("%d",is_lunch_break(time));
	struct datetime_t time_new = datetime(first,second);
	printf("%d\n %d\n %d\n %d\n",time_new.month, time_new.day, time_new.time.hours, time_new.time.minutes);
	//printf("%d %d %d %d",datetime(fisrt,second).month, datetime(first,second).day...
	return 0;
}

struct datetime_t datetime(struct datetime_t first, struct datetime_t second)
{
	struct datetime_t result;
	result.month = first.month - second.month;
	result.day = first.day - second.day;
	result.time.hours = first.time.hours - second.time.hours;
	result.time.minutes = first.time.minutes - second.time.minutes;
	return result;
}

int is_lunch_break(struct time_t time)
{
	if((time.hours == 12 && time.minutes >= 15) || (time.hours == 13) || (time.hours == 14 &&
	time.minutes <= 23))
	{
		return 1;
	}
	return 0;
}

