#include<fstream>
#include<iostream>
#include<string>
#include<cstring>
#include<time.h>

using namespace std;

int main()
{
	fstream file;

	//file.open("text.txt");

	//if (file.fail())
	//{
	//	cout << "File not Found." << endl;
	//	return -1;
	//}

	//// Reading from a File
	string buffer;
	//while (getline(file, buffer))
	//{
	//	//print the line
	//	cout << buffer << endl;
	//}

	//file.clear(); // reset error flags

	//file.seekp(0, ios_base::end); // move my cursor to the end

	////write a message

	//file << endl << "Today is Today";

	//file.flush();

	//file.close();

	////lets make another thing

	//fstream autoCreate;

	//autoCreate.open("createme.txt", ios::out | ios::in);

	//if (autoCreate.fail())
	//{
	//	cout << "Something Went Wrong" << endl;
	//	return -1;
	//}

	//autoCreate.close();

	// ==CLOSED==

	// 1. Digital Printer
	/*
	char in[60];
	char anim[] = "commonAnimeTropes.txt";
	char lin[] = "famousLines.txt";

	cout << "Hi | What File do you Want to Access|\ncommonAnimeTropes.txt or famousLines.txt?" << endl;
	while (true)
	{
		cin >> in;

		if (strcmp(anim,in) == 0)
		{
			file.open("commonAnimeTropes.txt");
			if (file.fail())
			{
				cout << "File not Found." << endl;
				return -1;
			}
			while (getline(file, buffer))
			{
				cout << buffer << endl;
			}
			
		}
		else if (strcmp(lin, in) == 0)
		{
			file.open("famousLines.txt");
			if (file.fail())
			{
				cout << "File not Found." << endl;
				return -1;
			}
			while (getline(file, buffer))
			{
				cout << buffer << endl;
			}
		}
		else
		{
			cout << "That File Doesnt Exist" << endl;
		}

		file.close();
		cout << "Do You Wish to open Another File?" << endl;
	}
	*/


	// 2. My Information


	/*
	char name[60];
	char age[60];
	char colo[60];

	while (true)
	{
		file.open("Information.txt");
		if (file.fail())
		{
			cout << "File not Found." << endl;
			return -1;
		}
		cout << "Who Are You?: ";
		cin >> name;
		
		file << endl << "Name: " << name;

		cout << "How Old Are You?: ";
		cin >> age;

		file << endl << "Age: " << age;

		cout << "What is Your Favorite Color?: " ;
		cin >> colo;

		file << endl << "Favorite Color: " << colo;

		file.flush();

		file.close();
		cout << "Check Information.txt" << endl;
	}
	*/
	
	//==OPEN==

	// 1. Running Out of Toner
	
	file.open("importantMessage.txt");

	srand(time(NULL));

	if (file.fail())
	{
		cout << "don fucked up";
	}

	while(getline(file, buffer))
	{
		for (int i = 0; i < buffer.length(); i++)
		{
			int indx = rand() % buffer.length();
			buffer[indx] = 61;
			cout << buffer[i];
		}
		cout << endl;
	}

	file.close();

	while (true){}

}