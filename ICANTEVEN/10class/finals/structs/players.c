#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct card_t
{
	char paint[10];
	char number[2];
};
struct player_t
{
	char name[20];
	int wins;
	int loses;
	struct card_t cards[26];	
};

void fight (struct player_t, struct player_t);

int main ()
{
	struct player_t player1;
	struct player_t player2;
	printf("Player1: ");
	fgets(player1.name,20,stdin);
	for (int i = 0; i < 2; i++) //here should be i < 26 but i'm lazy to input so much cards
	{
		fgets(player1.cards[i].paint,10,stdin);
		fgets(player1.cards[i].number,3,stdin);
	}
	printf("Player2: ");
	fgets(player2.name,20,stdin);
	for (int i = 0; i < 2; i++) // here too
	{
		fgets(player2.cards[i].paint,10,stdin);
		fgets(player2.cards[i].number,3,stdin);
	}
	fight(player1,player2);
	
	
	return 0;
}

void fight (struct player_t player1, struct player_t player2)
{
	char paint[][100] = {"club","diamond","heart","spade"};
        char number[][2] = {"2","3","4","5","6","7","8","9","10","J","Q","K","A"};
        
	player1.wins = 0;
	player2.wins = 0;
	player1.loses = 0;
	player2.loses = 0;

	int paint1, paint2, number1, number2;
        for (int k = 0; k < 26; k++)
	{
		for (int i = 0; i < 4; i++)
        	{
                	if(strcmp(player1.cards[k].paint, paint[i]) == 0) { paint1 = i; }
                	if(strcmp(player2.cards[k].paint, paint[i]) == 0) { paint2 = i; }
        	}
        	for (int i = 0; i < 13; i++)
        	{
                	if(strcmp(player1.cards[k].number, number[i]) == 0) { number1 = i; }
                	if(strcmp(player2.cards[k].number, number[i]) == 0) { number2 = i; }
        	}

        	if (number1 > number2) player1.wins++;
        	else if (number1 < number2) player2.wins++;
        	else
        	{
                	if (paint1 >= paint2) player1.wins++;
                	else player2.wins++;
        	}
	}

	player1.loses = 26 - player1.wins;
	player2.loses = 26 - player2.wins;
	if (player1.wins > player2.wins) printf("%s",player1.name);
	else if (player1.wins < player2.wins) printf("%s",player2.name);
	


}
