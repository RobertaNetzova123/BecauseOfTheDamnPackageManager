#include <stdio.h>

struct time_t
{
	float sec;
	
	
	
};
struct time_t get_fastest_time(float times[10]); 

int main()
{
	struct time_t time;
	float times;
	for (int i = 0; i < 10; i++)
	{
		scanf("%f",&time.sec);
	} 


	//float answ = get_fastest_time(times);
	//printf("%f",answ);

	//
	return 0;
}

struct time_t get_fastest_time(float times[10])
{
	int min;
	for(int i = 0; i < 10; i++)
	{
		min = times[i];
		if (min < times[i + 1]) min = times[i];
		else min = times[i+1];  	
	}

	

	
}

