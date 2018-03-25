#include <stdio.h>
#include <stdlib.h>

struct point_t
{
	int x;
	int y;
};

struct point_t sum(struct point_t, struct point_t);
int are_on_same_line(struct point_t, struct point_t);
int main ()
{
	struct point_t start;
	struct point_t end;
	
	scanf("%d",&start.x);
	scanf("%d",&end.x);
	scanf("%d",&start.y);
	scanf("%d",&end.y);
        	
	struct point_t sum_new = sum(start,end);
	printf("%d %d\n",sum(start,end).x, sum(start,end).y);
	sum(sum(start,end),sum_new);
        printf("%d",are_on_same_line(start,end));

	return 0;
}

int are_on_same_line(struct point_t start, struct point_t end)
{
	return 1;
}
struct point_t sum(struct point_t start, struct point_t end)
{
	struct point_t result;
	result.x = start.x + end.x;
	result.y = start.y + end.y;
	return result;
}
