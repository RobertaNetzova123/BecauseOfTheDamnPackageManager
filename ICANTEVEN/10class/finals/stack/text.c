#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct note_t
{
	char message[20];
};	

struct board_t 
{
	struct note_t notes[10];
	int count;
};

struct board_t copy_board(struct board_t);
void filter_board_notes(struct board_t*);

int main()
{
	struct board_t original;
	for(int i = 0; i < 3; i++)
	{
		fgets(original.notes[i].message,10,stdin);
	}
	original.count = 3;
	struct board_t copied = copy_board(original);
	for(int i = 0 ; i < 3; i++)
	{
		printf("%s\n",copied.notes[i].message);
	}
	filter_board_notes(&copied);
	for(int i = 0; i < copied.count; i++)
	{
		printf("%s\n",copied.notes[i].message);
	}
	return 0;
}

struct board_t copy_board(struct board_t reference)
{
	struct board_t copied;
	copied.count = 0;
	for(int i = 0; i < reference.count; i++)
	{
		copied.notes[i].message == reference.notes[i].message;
		copied.count++;
	}	
	return copied;
}

void filter_board_notes(struct board_t *reference)
{
	int k = 0;
	for(int i = 0; i < reference->count; i++)
	{
		if(strlen(reference->notes[i].message) >= 5 && strlen(reference->notes[i].message <= 15))
		{
			reference->notes[k].message == reference->notes[i].message;
			k++;
		}
	}
	reference->count = k;
}	
