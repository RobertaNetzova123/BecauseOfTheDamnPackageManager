#include <stdio.h>

int *longest_odd_even_chain(int*, int);

int main()
{
	int arr[6] = {3,2,5,5,7,4,6};
	int size = 6;
	int answer = longest_odd_even_chain(&arr,size);
	printf("%d", answer);
	return 0;
}

int *longest_odd_even_chain(int *arr, int size)
{
	int *p, even, odd, *k, *max, max1;
	for (int i = 0; i < size; i++)
	{
		if(arr[i] % 2 == 0)
		{
			p = &i;
			even++;
			while(arr[i] % 2 != 0)
			{
				i++;
				even++;
			}	
			k = &i;
			while(arr[i] % 2 == 0)
                        {
                                i++;
                                odd++;
                        }
		if(max1 == 0)
		{
			if (even > odd) { max = &p; odd = 0; max1 = even; even = 0; }
			else {max = &k; even = 0; max1 = odd; odd = 0; }

		} else 
		{
			if(even > max1) { max = &p; max1 = even; even = 0; }
			else if (odd > max1) { max = &k; even = 0; max1 = odd; odd = 0; }
			

		}	

	}
}
}
