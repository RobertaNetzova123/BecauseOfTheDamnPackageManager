#include <stdio.h>
#include <stdlib.h>

struct point_t 
{
	int x;
	int y;
};
struct line_t
{
	struct point_t start;
	struct point_t end;	
};
	
int are_they_parallel(struct line_t, struct line_t);
int are_they_not_parallel(struct line_t, struct line_t);

int main ()
{
	struct line_t first;
	struct line_t last;
	
	scanf("%d",&first.start.x);
	scanf("%d",&first.end.x);
	scanf("%d",&last.start.y);
	scanf("%d",&last.end.y);

	printf("%d\n",are_they_parallel(first,last));
	printf("%d\n",are_they_not_parallel(first,last));
	return 0;

}
int are_they_parallel(struct line_t first, struct line_t last)
{
	struct point_t result;
	result.x = first.start.x + first.end.x;
	result.y = last.start.y + last.end.y;
	if (result.x == result.y)
	{
		return 1;
	}
	return 0;
}

int are_they_not_parallel(struct line_t first, struct line_t last)
{
	return !are_they_parallel(first,last);
}
