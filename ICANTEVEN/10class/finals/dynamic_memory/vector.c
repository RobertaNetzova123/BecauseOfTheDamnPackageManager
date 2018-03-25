#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct vector_t 
{
	int size;
	int count;
	int *arr;
};

struct vector_t init();
void add_last(struct vector_t*,int);
int last(struct vector_t);
int pop(struct vector_t*);
int empty(struct vector_t);
int full(struct vector_t);
void destroy(struct vector_t*);
int at(struct vector_t, int);
int first(struct vector_t);
int insert_at(struct vector_t*,int,int);
void add_first(struct vector_t*,int);

int main()
{
	struct vector_t vector = init();
	int new;
	while(scanf("%d",&new) != EOF)
	{
		add_last(&vector, new);
	}
	
	int last_element = last(vector);
	printf("last: ");
	printf("%d\n",last_element);
	
	int pop_el = pop(&vector);
	printf("pop: ");
	printf("%d\n",pop_el);
	
	int empty_el = empty(vector);
	printf("empty: ");
	printf("%d\n",empty_el);
	
	int full_el = full(vector);
	printf("full: ");
	printf("%d\n",full_el);
	
	int index;
	scanf("%d",&index);
	int element = at(vector,index);
	printf("At: ");
	printf("%d\n",element);
	
	int first_element = first(vector);
	printf("first: ");
	printf("%d\n",first_element);
		
	int index2, item2;
	scanf("%d",&index2);
	scanf("%d",&item2);
	insert_at(&vector,index2,item2);

	int item3;
	scanf("%d",&item3);
	add_first(&vector,item3);

	for(int i = 0; i < vector.size; i++)
	{
		printf("%d",vector.arr[i]);
	}
	destroy(&vector);

	return 0;
}

struct vector_t init()
{
	struct vector_t vector;
	vector.size = 1;
	vector.count = 0;
	vector.arr = malloc(sizeof(int));
	return vector;
}

void add_last(struct vector_t *vector, int item)
{
	if(vector->count == vector->size)
	{
		vector->size = vector->size * 2;
		vector->arr = realloc(vector->arr,sizeof(int) * vector->size);
	}
	vector->arr[vector->count] = item;
	vector->count++;
}

int last(struct vector_t vector)
{
	return vector.arr[vector.count - 1];
}

int pop(struct vector_t *vector)
{
	int pop_element = vector->arr[vector->count - 1];
	vector->size--;
	vector->count--;
	vector->arr[vector->count] = 0;
	return pop_element;
}

int empty(struct vector_t vector)
{
	if(vector.size == 0 && vector.count == 0) return 1;
	else return 0;
}

int full(struct vector_t vector)
{
	if(vector.size > 0) return 1;
	else return 0;
}

void destroy(struct vector_t *vector)
{
	free(vector->arr);
	vector->size = 0;
	vector->count = 0;
}

int at(struct vector_t vector, int index)
{
	return vector.arr[index];
}

int first(struct vector_t vector)
{
	return vector.arr[0];
}

int insert_at(struct vector_t *vector, int index, int item)
{
	vector->arr = realloc(vector->arr, sizeof(int) * (vector->size + 1));
	for(int i = vector->size; i > index; i--)
	{
		vector->arr[i] = vector->arr[i - 1];
	}
	vector->arr[index] = item;
	vector->size++;
	vector->count++;
	
	return 0;
}

void add_first(struct vector_t *vector, int item)
{
	vector->arr = realloc(vector->arr, sizeof(int) * (vector->size + 1));	
	for(int i = vector->size; i > 0; i--)
	{
		vector->arr[i] = vector->arr[i - 1];
	} 	
	vector->arr[0] = item;
	vector->size++;
	vector->count++;
}

