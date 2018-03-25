#include <stdio.h>

struct job_offer_t
{
	float salary;
	int remote;
	int hoursperweek;
	int meetings[7];
	
};

int accept_offer(struct job_offer_t);

int main()
{
	struct job_offer_t offer;
	
	scanf("%2f",&offer.salary);
	scanf("%d",&offer.remote);
	scanf("%d",&offer.hoursperweek);
	printf("*********\n");
	for(int i = 0; i < 7; i++)
	{
		scanf("%d",&offer.meetings[i]);
	}	
	
	int answer = accept_offer(offer);
	if(answer == 1) printf ("yes\n");
	else printf("no\n");

	return 0;
	
}

int accept_offer(struct job_offer_t accept)
{
	int sum = 0;
	if(accept.salary >= 1024.64)
	{
		for(int i = 0; i < 7; i++)
		{
			sum = sum + accept.meetings[i];	
		}
		if(accept.remote == 0 && sum < 6)
		{
			return 1;
		}
		if(accept.remote == 1 && sum < 4)
		{
			return 1;
		}
	
	}
	else return 0;
}
















