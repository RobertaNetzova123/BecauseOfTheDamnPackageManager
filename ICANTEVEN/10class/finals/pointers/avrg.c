#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void avrg(float *arr,int size,float *avrg);

int main()
{
	float farr[] = {1.0, 2.5, 1.5, 1.0};
	float arrAvrg;
	avrg(farr,4,&arrAvrg);
	printf("%f\n",arrAvrg);
	return 0;
}

void avrg(float *arr,int size, float *avrg)
{
	float sum = 0;
	for(int i = 0; i < size; i++)
	{
		sum = sum + arr[i];
	}
	*avrg = sum / size;
}
