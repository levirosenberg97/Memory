#include<iostream>
#include "randomizer.h"
#include <time.h>

using namespace std;

int main()
{


	srand(time(NULL));
	char random[] = { "000000" };
	char a, b, c, d, e, f = 0;
	do
	{
		for (int i = 0; i < strlen(random); i++)
		{
			random[i] = rand() % 10 + 48;
		}
	} while (random[0] == random[1] || random[0] == random[2] || random[0] == random[3] || random[0] == random[4] || random[0] == random[5] || random[1] == random[2] || random[1] == random[3] || random[1] == random[4] || random[1] == random[5] || random[2] == random[3] || random[2] == random[4] || random[2] == random[5] || random[3] == random[4] || random[3] == random[5] || random[4] == random[5]);
	
	titleScreen();

	playerInput(random);

	while (true) {}
}