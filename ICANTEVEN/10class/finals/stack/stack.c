#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct stack_t
{
	int *data;
	int size;
	int capacity;
};

//1
struct stack_t stack_init(int); //заделя памет за един стек със зададения капацитет
void stack_destroy(struct stack_t*); //освобождава паметта за дадения стек
//2
void push(struct stack_t*,int); //добавя елемент към началото на стека
int top(struct stack_t); //връща най-горния елемент
void pop(struct stack_t*); //премахва най-горния елемент
int size(struct stack_t); //връща колко елемента има в стека
//3
int is_full(struct stack_t); //дали стека е пълен
int is_empty(struct stack_t); // дали стека е празен
void stack_resize(struct stack_t*); //увеличава капацитета на стека два пъти и запазва всички налични данни
struct stack_t stack_copy(struct stack_t); //връща копие на подадения стек

int main()
{
	struct stack_t new_stack = stack_init(10);
	
	new_stack.data[0] = 3;
	new_stack.data[1] = 4;
	new_stack.data[2] = 5;
	new_stack.data[3] = 6;
	new_stack.size = 4;
	
	for(int i = 0; i < new_stack.size; i++)
	{
		printf("Element: %d\n",new_stack.data[i]);
	}	
	return 0;
}

struct stack_t stack_copy(struct stack_t stack)
{
	struct stack_t new_stack = stack_init(10);
	new_stack.size = stack.size;
	new_stack.capacity = stack.capacity;
	for(int i = 0; i < stack.size; i++)
	{
		new_stack.data[i] = stack.data[i];
	}
	return new_stack;
}

void stack_resize(struct stack_t *stack)
{
	stack->data = realloc(stack->data, sizeof(int) * (stack->capacity * 2));
	stack->capacity = stack->capacity * 2;
}

int is_empty(struct stack_t stack)
{
	if (stack.size == 0) { return 1; }
	else return 0;
}

int is_full(struct stack_t stack)
{
	if(stack.size == stack.capacity) { return 1; }
	else return 0;
}

int size(struct stack_t stack)
{
	return stack.size;
}

void pop(struct stack_t* stack)
{
	if(is_empty(*stack)) {return ;}
	stack->size--;
}

int top(struct stack_t stack)
{
	return stack.data[stack.size - 1];
}

void push(struct stack_t *stack, int element)
{
	if(is_full(*stack))
	{
		stack->data = realloc(stack->data,sizeof(int) * (stack->capacity * 2));
		stack->capacity = 2 * stack->capacity;
	}
	stack->data[stack->size++] = element;
}
y
void stack_destroy(struct stack_t *stack)
{
        stack->size = 0;
        stack->capacity = 0;
        free(stack->data);
        stack->data = NULL;
}

struct stack_t stack_init(int initial_capacity)
{
	struct stack_t stack;
	stack.size = 0;
	stack.capacity = initial_capacity;
	stack.data = malloc(sizeof(int) * initial_capacity);
	return stack;
}

