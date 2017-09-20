#include "randomizer.h"
#include<iostream>
#include <time.h>
#include<Windows.h>
#include<fstream>
#include<string>
#include<cstring>

using namespace std;

void titleScreen()
{
	colorPicker(10);
	cout << "\n\n\n\n\n\n\n\n\n" << endl;
	cout << " 	     __  __           _            __  __ _           _ " << endl;
	cout << " 	    |  \\/  |         | |          |  \\/  (_)         | |" << endl;
	cout << "	    | \\  / | __ _ ___| |_ ___ _ __| \\  / |_ _ __   __| |" << endl;
	cout << "	    | |\\/| |/ _` / __| __/ _ \\ '__| |\\/| | | '_ \\ / _` |" << endl;
	cout << "	    | |  | | (_| \\__ \\ ||  __/ |  | |  | | | | | | (_| |" << endl;
	cout << "	    |_|  |_|\\__,_|___/\\__\\___|_|  |_|  |_|_|_| |_|\\__,_|" << endl;
	cout << "\n\n\n\n\n\n\n\n\n" << endl;
	colorPicker(7);
	timedPause(3000);
	system("CLS");
}

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
	
	cout << "Enter a Guess, No Guesses Over or Below 6 digits (No Repeating Numbers)"  << "\n___________________________________________________________________________"<< endl;
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
		cout << "\n" <<endl;
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
	timedPause(2000);
	system("CLS"); //clears Screen

	cout << "You Win!!!!" << endl;
	timedPause(2500);
	int arr[5];
	string narr[5];
	int line = 1;
	fstream file;
	string buffer;
	srand(time(NULL));
	bool even = false;
	char in[3];

	system("CLS");
	

	file.open("highscores.txt");

	//will helped with the high score ordering
	
	if (file.fail())
	{
		cout << "File Not Found";
	}
	while (getline(file, buffer) && line < 11)
	{	
		if (even == true)
		{
			narr[(line - 2) / 2] = buffer;
			even = false;
		}
		else
		{
			arr[(line - 1)/2] = stoi(buffer);
			even = true;
		}
		line++;
	}
	file.close();
	bool topscore = false;
	//did player make a top score?
	for (int i = 0; i < 5; i++)
	{
		if (counter <= arr[i] && topscore == false)
		{
			topscore = true;
		}
		else
		{
			topscore = false;
		}
	}
	//if a player made a top score
	if (topscore == true)
	{
		//ask name
		do
		{
			cout << "You Got a Top 5 Score \nEnter 3 Letters to Log your Score: ";
			cin >> in;
		} while (strlen(in) != 3);
		//rearange score board
		for (int i = 0; i < 5; ++i)
		{
			if (counter <= arr[i])
			{
				//if last on the scoreboard
				if (i == 4)
				{
					//replace last score with current
					arr[i] = counter;
					narr[i] = in;
				}
				else
				{
					//bump scoreboard
					for (int j = 4;j > i ; --j)
					{
						arr[j] = arr[j - 1];
						narr[j] = narr[j - 1];
					}
					arr[i] = counter;
					narr[i] = in;
				}
				//idk why this is here
				i = 4;
			}
		}
	}
	else
	{
		cout << "You did Not Get a High Score" << endl;
	}


	for (int i = 0; i < 5; ++i)
	{
		cout << arr[i] << " " << narr[i] << endl;
	}
	
	file.open("highscores.txt",ios::out);
	
	even = false;

	for (int line = 1; line < 11; line++)
	{
		if (even == true)
		{
			narr[(line - 2) / 2];
			file << narr[(line - 2) / 2] << endl;
			even = false;
		}
		else
		{
			arr[(line - 1) / 2];
			file << arr[(line - 1) / 2] << endl;
			even = true;
		}
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
