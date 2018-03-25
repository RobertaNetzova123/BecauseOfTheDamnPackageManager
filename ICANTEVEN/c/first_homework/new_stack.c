#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct stack
{
	size_t size;
	size_t capacity;
	int *elements;
}stack;

void stack_init(stack *);
void stack_destroy(stack *);
int stack_empty(stack *);
void stack_push(stack *, int);
int stack_top(stack *);
void stack_pop(stack *);
int size(stack);

int size(stack st) {
	return st.size;
}

void stack_init(stack *stack) {
	stack->size = 0;
}

void stack_destroy(stack *stack) {
	free(stack->elements);
	stack->elemenets = NULL;
	stack->capacity = 0;
	stack->size = -1;
}



