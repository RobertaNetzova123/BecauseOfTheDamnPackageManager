#include <stdio.h>
#include <stdlib.h>

struct job_offer_t
{
	float salary;
	int is_remote;
	int work_hours;
	int meetings[7];
};

int accept_offer(struct job_offer_t);

int main ()
{
	struct job_offer_t offer;
	printf("Salary: ");
	scanf("%f",&offer.salary);
	printf("Remote? :");
	scanf("%d",&offer.is_remote);
	printf("Hours at work: ");
	scanf("%d",&offer.work_hours);
	
	for(int i = 0; i < 7; i++)
	{
		printf("Meeting: ");
		scanf("%d",&offer.meetings[i]);
	}
	printf("%d\n",accept_offer(offer));
	return 0;
}

int accept_offer(struct job_offer_t offer)
{
	if(offer.salary < 1024.64) { return 0; }
	int meetings_count = 0;
	for(int i = 0; i < 7; i++)
	{
		meetings_count = meetings_count + offer.meetings[i];
	}

	if(offer.is_remote == 0 && meetings_count < 6) { return 1; }
	if(offer.is_remote == 1 && meetings_count < 4) { return 1; }
	
	return 0;
}
