#include <stdio.h>
#include <stdlib.h>

struct person_t
{
	char name[20];
	int age;
	int post_code;
};

struct phonebook_entry_t 
{
	struct person_t *person;
	char phone[10];
};
	
void print_person (struct phonebook_entry_t);

int main ()
{
	int size;
	scanf("%d",&size);
	int count;
	char phone[10];
	
	struct phonebook_entry_t *book = malloc(sizeof(struct phonebook_entry_t) * size);
	char name[20];
	while (scanf("%s",name) != EOF)
	{
		//char phone[10];
		scanf("%s", phone);
		printf("%s - %s\n", name, phone);
		book[count].name = name;
		book[count++].phone = phone;
		if (count == size)
		{
			size = size * 2;
			book = realloc(book, sizeof(struct phonebook_entry_t));
		}
	}
	for (int i = 0; i < count; i++)
	{
		printf("%s - %s\n", book[i].name, book[i].phone);
	}
	free(book);
	return 0;
		
}
