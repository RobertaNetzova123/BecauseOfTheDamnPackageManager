#include <stdio.h>
#include <stdlib.h>

struct point_t
{
	int x;
	int y;
};

int are_point_on_line (struct point_t, struct point_t);
struct point_t sum (struct point_t, struct point_t);

int main()
{
	struct point_t start;
	struct point_t end;

	printf("Input x1: ");
	scanf("%d",&start.x);
	printf("Input x2: ");
	scanf("%d",&end.x);
	printf("Input y1: ");
	scanf("%d",&start.y);
	printf("Input y2: ");
	scanf("%d",&end.y);

	printf("%d\n", are_point_on_line(start,end));
	printf("%d\n %d\n",sum(start,end).x,sum(start,end).y);

	return 0;
}

int are_point_on_line (struct point_t x, struct point_t y)
{
	return 1;
}

struct point_t sum (struct point_t start, struct point_t end)
{
	struct point_t result;
	result.x = start.x + end.x;
	result.y = start.y + end.y;
	return result;
}
