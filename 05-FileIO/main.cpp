#include<fstream>
#include<iostream>
#include<string>
#include<cstring>
#include<time.h>
#include"entity.h"


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
		getline(cin, name);
		
		// cin.ignore(1000, '\n');

		file << endl << "Name: " << name;

		cout << "How Old Are You?: ";
		getline(cin, age);

		file << endl << "Age: " << age;

		cout << "What is Your Favorite Color?: " ;
		getline(cin, colo);

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
		cout << "File Not Found";
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


	// 2. Load Entity Data

	fstream entityStream;
	entityStream.open("monsters.txt");

	if (entityStream.fail())
	{
		cout << "COULD NOT OPEN" << endl;
	}

	int entityCount = 0;
	Entity entities[100];

	while (true)
	{
		string buf;
		bool entityFound = false;

		//seek to next entity

		while (getline(entityStream, buf))
		{
			if (buf[0] == '@')
			{
				entityFound = true;
				break;
			}
		}

		// exit if no entity found

		if (!entityFound)
		{
			break;
		}

		//load data into the array of entities

		Entity& curEntity = entities[entityCount];

		getline(entityStream, buf);
		curEntity.hp = stof(buf);

		getline(entityStream, buf);
		curEntity.armor = stof(buf);

		getline(entityStream, buf);
		curEntity.strength = stof(buf);

		getline(entityStream, buf);
		curEntity.defense = stof(buf);

		getline(entityStream, buf);
		curEntity.agility = stof(buf);

		getline(entityStream, buf);
		curEntity.luck = stof(buf);

		entityCount++;

		//exit if no entity found

		if (entityCount >= 100)
		{
			break;
		}

	}

	while (true){}

}