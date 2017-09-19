#include<iostream>
#include "randomizer.h"
#include <time.h>

using namespace std;

int main()
{
	
	srand(time(NULL));
	char random[] = { "000000" };
	while (true)
	{
		for (int i = 0; i < strlen(random); i++)
		{
			random[i] = rand() % 10 + 48;
		}

		playerInput(random);
	}
}