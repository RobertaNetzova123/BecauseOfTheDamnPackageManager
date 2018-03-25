#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct dynamic_arr_t 
{
	int *arr;
	int size;
};

struct dynamic_arr_t generate(int);
void free_dynamic_arr(struct dynamic_arr_t*);
struct dynamic_arr_t filter_even(struct dynamic_arr_t);
struct dynamic_arr_t map_sqr(struct dynamic_arr_t);
struct dynamic_arr_t sqr_of_odds(struct dynamic_arr_t);
int reduce_sum(struct dynamic_arr_t);

int main()
{
	int size;
	printf("Size: ");
	scanf("%d\n",&size);
	
	struct dynamic_arr_t array = generate(size);
	for(int i = 0; i < array.size; i++)
	{
		printf("Element: ");
		printf("%d\n",array.arr[i]);
	}

	struct dynamic_arr_t filter = filter_even(array);
	for(int i = 0; i < filter.size; i++)
	{
		printf("Left elements: ");
		printf("%d\n",filter.arr[i]);
	}

	struct dynamic_arr_t map = map_sqr(array);
	for(int i = 0; i < map.size; i++)
	{
		printf("Na vtora stepen:");
		printf("%d\n",map.arr[i]);
	}

	struct dynamic_arr_t odds = sqr_of_odds(array);
	for(int i = 0; i < odds.size; i++)
	{
		printf("Na vtora stepen nechetni: ");
		printf("%d\n",odds.arr[i]);
	}

	int sum = reduce_sum(array);
	printf("\n%d\n",sum);
	
	free_dynamic_arr(&array);

	return 0;
}

struct dynamic_arr_t generate (int num)
{
	struct dynamic_arr_t array;
	array.arr = malloc(sizeof(int) * num);
	array.size = num;
	for(int i = 0; i < num; i++)
	{
		array.arr[i] = i + 1;
	}
	return array;
}

void free_dynamic_arr(struct dynamic_arr_t *array)
{
	free(array->arr);
	array->size = 0;
}

struct dynamic_arr_t filter_even(struct dynamic_arr_t array)
{
	struct dynamic_arr_t tmp;
	tmp.arr = malloc(tmp.size * sizeof(int));
	tmp.size = 0;
	for(int i = 0; i < array.size; i++)
	{
		if(array.arr[i] % 2 != 0)
		{
			tmp.size++;
			tmp.arr = realloc(tmp.arr,sizeof(int) * tmp.size);
			tmp.arr[tmp.size - 1] = array.arr[i];
		}
		
	}
	return tmp;
}

struct dynamic_arr_t map_sqr(struct dynamic_arr_t array)
{
	struct dynamic_arr_t tmp;
	tmp.arr = malloc(sizeof(int) * tmp.size);
	tmp.size = array.size;
	for(int i = 0; i < array.size; i++)
	{
		tmp.arr[i] = tmp.arr[i] * array.arr[i];
	}	
	return tmp;
}

struct dynamic_arr_t sqr_of_odds(struct dynamic_arr_t array)
{
	struct dynamic_arr_t tmp = filter_even(array);
	tmp = map_sqr(tmp);
	return tmp;
}

int reduce_sum(struct dynamic_arr_t array)
{
	int sum = 0;
	for(int i = 0; i < array.size; i++)
	{
		sum = sum + array.arr[i];
	}
	return sum;
}









