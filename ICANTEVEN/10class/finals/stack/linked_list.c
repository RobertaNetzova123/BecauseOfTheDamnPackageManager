#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node_t
{
	int value;
	struct node_t *next;
};

struct list_t
{
	struct node_t *head;
	int size;
};

//Basic functions - 1st slide
struct node_t *create(int); //създаване
void insert_before(struct list_t*,int); //добавяне на елемент в началото на списъка
void insert_after(struct list_t*,int); //добавяне на елемент след някой друг елемент
void remove_before(struct list_t*); //премахване на елемент от началото на списъка
void remove_after(struct list_t*,int); //премахване на елемент след някой друг елемент
int get(struct list_t*, int); //взема стойността на дадена позиция от списъка
//2nd slide
struct list_t init_list(); //създава празен списък
void destroy_list(struct list_t*); //освобождава паметта, заето от даден списък
int size(struct list_t*); // връща големината на списъка
int is_empty(struct list_t*); // дали списъкът е празен
int top(struct list_t); //поглежда стойността на най-горния елемент
struct list_t copy(struct list_t*); //създава и връща копие на списъка

int main()
{
	struct list_t list;
	struct node_t *node = create(5);
	list.head = node;
	insert_before(&list,4);
	insert_after(&list,11);
	struct list_t new = copy(&list);
	printf("%d\n",get(&new,2));
	printf("%d\n %d\n",get(&list,0),top(list));	
	return 0;
}

struct list_t copy(struct list_t *list)
{
	struct list_t new = init_list();
	struct node_t *current_node = list->head;
	struct node_t *new_node;
	struct node_t *previous_node;

	while(current_node != NULL)
	{
		new_node = create(current_node->value);
		if(new.head == NULL)
		{
			new.head = new_node;
		}
		else
		{
			previous_node->next = new_node;
		}
		previous_node = new_node;
		current_node = current_node->next;
	}
	new.size = list->size;
	return new;
}

int top(struct list_t list)
{
	return list.head->value;
}

int is_empty(struct list_t *list)
{
	if(list->size == 0) { return 1; }
	else return 0;
}

int size(struct list_t *list)
{
	return list->size;
}

void destroy_list(struct list_t *list)
{
	struct node_t *find = list->head;
	while(find->next != NULL)
	{
		struct node_t *trash = find;
		find = find->next;
		free(trash);
	}
	free(find);
	list->head = NULL;
	list->size = 0;
	free(list);
}

struct list_t init_list()
{
	struct list_t new;
	new.head = NULL;
	new.size = 0;
	return new;
}

int get(struct list_t *list, int element)
{
	struct node_t *last = list->head;
	for(int i = 0; i < element; i++)
	{
		if(last == NULL) {return 0;}
		last = last->next;
	}
	return last->value;
}

void remove_after(struct list_t *list, int index)
{
	struct node_t *last = list->head;
	for(int i = 0; i < index; i++)
	{	
		last = last->next;
	}
	struct node_t *trash = last->next;
	last->next = last->next->next;
	free(trash);
}

void remove_before(struct list_t *list)
{
	struct node_t *removed = list->head;
	list->head = removed->next;
	free(removed);
}

void insert_after(struct list_t *list, int element)
{
	struct node_t *last = list->head;
	while(last->next != NULL) { last = last->next; }
	struct node_t *new_element = create(element);
	last->next = new_element;
}

void insert_before(struct list_t *list, int element)
{
	struct node_t *new_element = create(element);
	new_element->next = list->head;
	list->head = new_element;
}

struct node_t *create(int element)
{
	struct node_t *new_element = malloc(sizeof(struct node_t));
	new_element->value = element;
	new_element->next = NULL;
	return new_element;
}
