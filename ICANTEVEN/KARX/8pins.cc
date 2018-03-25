#include <iostream>
using namespace std;

int countPin, countDiode;

void resetPins() {
	for(int i = 0; i < countPin; i++)
	{
		if(i <= countPin /2)
		{
			digitalWrite(i, HIGH);
		} else 
		{
			digitalWrite(i, LOW);
		}
	}
}

void setup() {
	cin << countPin;
	cin << countDiode;

	for(int i = 0; i < countDiode; i++)
	{
		cin << diodX[i] << diodY[i];
	}
	resetPins();
}

void loop() {
	for(int i = 0; i < countDiode / 2; i++)
	{
		for(int p = countPin / 2; p < countPin; p++)
		{
			for(k = 0; k < countDiode; k++)
			{
				if(diodX[k] == i && (diodY[k] + countPin / 2) == p)
				{
					digitalWrite(i, LOW);
					digitalWrite(p, HIGH);
					delay(20);
				}
			}
		}
		resetPins();
	}
}
