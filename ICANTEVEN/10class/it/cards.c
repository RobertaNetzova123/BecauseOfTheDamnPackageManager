nclude <stdio.h>

struct card_t
{
	char number;
	char color;
};

struct card_t fight (struct card_t, struct card_t);

int main ()
{
	struct card_t card1, card2, result;
	scanf("%c",&card1.number);
	scanf("%c",&card1.color);
	getchar();
	scanf("%c",&card2.number);
        scanf("%c",&card2.color);

	result=fight(card1,card2);
	printf ("%c%c", result.number, result.color);
	return 0;
}

struct card_t fight (struct card_t karta1, struct card_t karta2)
{
	struct card_t karta01, karta02;
	karta01 = karta1;
	karta02 = karta2;
	
	if (karta1.number == 'T') { karta1.number = 'A'; }
	if (karta2.number == 'T') { karta2.number = 'A'; }
        if (karta1.number == 'J') { karta1.number = 'B'; }
        if (karta2.number == 'J') { karta2.number = 'B'; }
        if (karta1.number == 'Q') { karta1.number = 'C'; }
        if (karta2.number == 'Q') { karta2.number = 'C'; }
        if (karta1.number == 'K') { karta1.number = 'D'; }
        if (karta2.number == 'K') { karta2.number = 'D'; }
        if (karta1.number == 'A') { karta1.number = 'E'; }
        if (karta2.number == 'A') { karta2.number = 'E'; }

        if(karta1.number > karta2.number) { return karta01;}
        if(karta1.number == karta2.number)
        {
                if (karta1.color > karta2.color) { return karta01;}
                else return karta02;    
        }

        return karta02;

