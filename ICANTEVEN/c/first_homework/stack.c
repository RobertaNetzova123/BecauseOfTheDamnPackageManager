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
int stack_full(stack);
//int size(stack);

/*int size(stack st) {
	return st.size;
}*/

void stack_init (stack *stack) {
	//or only stack->size = 0???
	stack->capacity = 666;
	stack->size = 0;
	//not sure about that one
	stack->elements = malloc(sizeof(int) * stack->capacity);

	//OR IN CLASS 
	/*
		stack->size = 0;
		stack->elements = NULL;
	*/

}

void stack_destroy (stack *stack) {
	/*stack->size = 0;
	stack->capacity = 0;
	free(stack->elements);
	stack->elements = NULL;*/
	free(stack->elements);
	stack->capacity = 0;
	stack->size = 0;
	stack->elements = NULL;
}

int stack_empty (stack *stack) {
	if(stack->size == 0) {
		return 1; 
	}
	else return 0;
}

int stack_full(stack st) {
	return st.size == st.capacity;
}

void stack_push(stack *stack, int el) {
	if(stack_full(*stack)) {
		stack->elements = realloc(stack->elements, sizeof(int) * (stack->capacity * 2));
		stack->capacity = 2 * stack->capacity;
	}
	stack->elements[stack->size++] = el;
	/*if(stack->size < stack->capacity) {
		stack->elements[stack->size] = el;
		stack->size++;
	}*/
	//stack->elements = (int *)malloc(sizeof(int));
	//stack->elements[stack->size++] = el;
	//stack->capacity--;
}

int stack_top(stack *st) {
	//if(!stack_full(*st)) {return 0;}
	//else return st->elements[st->size - 1];
	if(st->size == 0) {
		return 0;;

	}
	else return st->elements[st->size-1];

}

void stack_pop(stack *stack) {
	if(stack->size == 0) { return ;}
	else stack->elements[stack->size--];
	
}




