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

struct datetime_t data (struct datetime_t, struct datetime_t);

int main()
{
	struct datetime_t first;
	struct datetime_t second;
	printf("\n Input month 1: ");
	scanf("%d",&first.month);
	printf("\n Input month 2: ");
	scanf("%d",&second.month);
	printf("\n Input day 1: ");
	scanf("%d",&first.day);
	printf("\n Input day 2: ");
	scanf("%d",&second.day);
 	printf("\n Input hours 1: ");
	scanf("%d",&first.time.hours);
 	printf("\n Input hours 2: ");
	scanf("%d",&second.time.hours);
 	printf("\n Input minutes 1: ");
	scanf("%d",&first.time.minutes);
 	printf("\n Input minutes 2: ");
	scanf("%d",&second.time.minutes);

	printf("%d\n %d\n %d\n %d\n",data(first,second).month, data(first,second).day, data(first,second).time.hours, data(first,second).time.minutes);
	return 0;
}

struct datetime_t data(struct datetime_t first, struct datetime_t second)
{
	struct datetime_t result;
	result.month = first.month - second.month;
	result.day = first.day - second.day;
	result.time.hours = first.time.hours - second.time.hours;
	result.time.minutes = first.time.minutes - second.time.minutes;
	return result;

}
