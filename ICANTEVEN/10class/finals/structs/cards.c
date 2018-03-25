#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct card_t
{
	char paint[10];
	char number[3];
};

struct card_t fight(struct card_t, struct card_t);

int main()
{
	struct card_t card1;
	struct card_t card2;
	
	printf ("Input card 1 paint: ");
	//scanf("%s",&card1.paint);
	fgets(card1.paint,10,stdin);
	printf ("Input card 1 power: ");
	//scanf("%s",&card1.number);
	fgets(card1.number,3,stdin);
	printf("Input card 2 paint: ");
	//scanf("%s",&card2.paint);
	fgets(card2.paint,10,stdin);
	printf("Input card 2 power: ");
	//scanf("%s",&card2.number);
	fgets(card2.number,3,stdin);


	//struct card_t x = fight(card1,card2);
	//printf("%s %s",x.paint,x.numer);

	printf("%s %s\n",fight(card1,card2).paint,fight(card1,card2).number);
	return 0;
}

struct card_t fight(struct card_t card1, struct card_t card2)
{
	char paint[][100] = {"club","diamond","heart","spade"};
	char number[][2] = {"2","3","4","5","6","7","8","9","10","J","Q","K","A"};
	int paint1, paint2, number1, number2;
	for (int i = 0; i < 4; i++)
	{
		if(strcmp(card1.paint, paint[i]) == 0) { paint1 = i; }
		if(strcmp(card2.paint, paint[i]) == 0) { paint2 = i; }
	}
	for (int i = 0; i < 13; i++)
	{
		if(strcmp(card1.number, number[i]) == 0) { number1 = i; }
		if(strcmp(card2.number, number[i]) == 0) { number2 = i; }
	}

	if (number1 > number2) return card1;
	else if (number1 < number2) return card2;
	else
	{
		if (paint1 >= paint2) return card1;
		else return card2;
	}

}
