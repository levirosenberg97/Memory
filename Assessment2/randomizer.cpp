#include "randomizer.h"
#include <iostream>
#include <time.h>
#include<Windows.h>
#include<fstream>
#include<string>
#include<cstring>

using namespace std;

bool containsValue(char arr[], int arrLen, char val)
{
	for (int i = 0; i < arrLen; ++i)
	{
		if (arr[i] == val) { return true; }
	}

	return false;
}

void playerInput(char random[])
{
	char in[6];
	int counter = 0;

	cout << "Enter a Guess (no more than 6 digits): ";
	while (true)
	{
		int len = 6;
		do
		{
			cin >> in;
		} while (strlen(in) != len);

		for (int i = 0; i < len; i++)
		{
			// is valid?
			if (containsValue(random, 6, in[i]))
			{
				// is correct or wrong position?
				if (in[i] == random[i])
				{
					// correct! yay
					colorPicker(10); // green
				}
				else
				{
					// somewhere else...
					colorPicker(14); // yellow
				}
			}
			else
			{
				colorPicker(12);  // red!
			}

			cout << in[i];
		}
		counter++;
		cout << endl;
		colorPicker(7); // white
		if (in[1] == random[1] && in[2] == random[2] && in[3] == random[3] && in[4] == random[4] && in[5] == random[5] && in[6] == random[6])
		{
			break;
		}
	}	
	winState(counter);
}

void winState(int counter)
{
	timedPause(500);
	system("CLS"); //clears Screen

	cout << "You Win!!!!" << endl;
	timedPause(250);
	

	fstream file;
	string buffer;
	srand(time(NULL));
	char in[3];
	file.open("highscores.txt");
	if (file.fail())
	{
		cout << "File Not Found";
	}

	do
	{
		cout << "Enter 3 Letters to Log your Score: ";
		cin >> in;
	} while(strlen(in) != 3);

	system("CLS");

	cout << "HIGH SCORES\n"<< "NAME        SCORES" << endl;
	file.clear();
	file.seekp(0, ios_base::end);
	file << endl << in << "          " << counter;

	file.flush();

	file.close();

	file.open("highscores.txt");

	if (file.fail())
	{
		cout << "File Not Found";
	}
	while (getline(file, buffer))
	{
		cout << buffer << endl;
	}

	file.close();
	timedPause(10000);

	exit(0);
}

void colorPicker(int color)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

void timedPause(int millisec)
{
	Sleep(millisec);
}