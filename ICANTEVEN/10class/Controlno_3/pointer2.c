#include <stdio.h>


int copy_only_positive(int*, int, int*);

int main()
{
	int src [20];
	int count = 5, positive_arr;
	for(int i = 0; i < count; i++)
	{
		scanf("%d",&src[i]); 
	}
        int positive =	copy_only_positive(&src,count,&positive_arr);
	printf("%d", positive);
	return 0;	
}

int copy_only_positive(int *src, int count, int *positive_arr)
{
	int pos = 0;
	for (int i = 0; i < count; i++)
	{
		if(src[i] > 0)
		{
			positive_arr[pos++] = src[i];
		}
	}
	return pos;
}
