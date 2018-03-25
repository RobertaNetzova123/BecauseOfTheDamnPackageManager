#include <stdio.h>
#include <stdlib.h>

struct person_t
{
	char name[20];
	char code[5];
	int age;
};

struct phonebook_entry_t
{
	struct person_t *person;
	char number[10];
};


int main()
{
	int size = 5;
	struct phonebook_entry_t *book = malloc(sizeof(struct phonebook_entry_t) * size);
	book->person = malloc(sizeof(struct person_t) * 1);
	
	for (int i = 0; scanf("%c",(book + i)->person->name) != EOF; i++)
	{
		fgets((book + i)->person->code,5,stdin);
		fgets((book + i)->number,10,stdin);
		scanf("%d",&(book + i)->person->age);
		(book + i)->person = realloc((book + i)->person, sizeof(struct person_t) * (i + 2));
		(book + i + 1)->person = malloc(sizeof(struct person_t) * 1);
	}
	return 0;
}


