#include<iostream>
#include<string>
#include<time.h>


using namespace std;

struct Track
{
	string trackName; // name of track
	float playtime;        // track runtime
};

struct Playlist
{
	string playlistName; // name of playlist
	Track * trackList;        // pointer to array of tracks
	int trackCount;           // number of tracks
	
};

struct Weapon
{
	int blutDmg;
	int magicDmg;
	int bladeDmg;

	struct OwnerInfo
	{
		int playerID;
		bool isRare;
	};

	OwnerInfo owner;

	int rarity;
};

void enhanceWeapon(Weapon a)
{
	a.blutDmg *= 2;
	a.magicDmg *= 2;
	a.bladeDmg *= 2;
}

void sum(int a, int b, int& c)
{
	c = a + b;
}

void product(float a, float b, float& c)
{
	c = a * b;
}

void swap(float& a, float& b)
{
	int c = 0;
	c = b;
	b = a;
	a = c;
}

struct Aussiegochi
{
	float happiness;
	float hunger;
	float thirst;
	float sanity;
};

void feedAussie(Aussiegochi &aus)
{
	if (aus.hunger >= 50)
	{
		cout << "Not Hungry" << endl;
		aus.thirst--;
		aus.hunger = 50;
	}
	else
	{
		aus.hunger += 10;
		aus.thirst--;
		aus.happiness++;
	}
}

void waterAussie(Aussiegochi &aus)
{
	if (aus.thirst >= 50)
	{
		aus.thirst = 50;
		cout << "Not Thirsty" << endl;
		aus.hunger--;
	}
	else
	{
		aus.thirst += 10;
		aus.hunger--;
		aus.happiness++;
	}
}

void abuseAussie(Aussiegochi &aus)
{
	if (aus.sanity <= 0 && aus.happiness <= 0)
	{
		cout << "Insane" << endl;
		aus.sanity = 0;
		aus.happiness = 0;
		aus.hunger--;
		aus.thirst--;
	}
	else
	{
		aus.sanity--;
		aus.happiness -= 10;
		aus.hunger--;
		aus.thirst--;
	}
}

void coddleAussie(Aussiegochi &aus)
{
	if (aus.happiness >= 25 && aus.sanity >= 25)
	{
		aus.happiness = 25;
		aus.sanity = 25;
		cout << "Already Content" << endl;
		aus.hunger--;
		aus.thirst--;
	}
	else
	{
		aus.happiness++;
		aus.sanity++;
		aus.hunger--;
		aus.thirst--;
	}
}

void printStats(Aussiegochi aus, char name[1100])
{
	cout << name << endl;
	cout << "________________________________________________________\n" << endl;
	cout << "Hunger:    " << aus.hunger << endl;
	cout << "Thirst:    " << aus.thirst << endl;
	cout << "Happiness: " << aus.happiness << endl;
	cout << "Sanity:    " << aus.sanity << endl;
}

void interaction(Aussiegochi &aus, char& in)
{

	while (in == 0)
	{
		cout << "\n\n|Press '1' to Feed  | Press '2' to Water  |\n|Press '3' to Kick | Press '4' to Hug    |" << endl;
		cout << "_______________________________________________________________________";
		cin >> in;

		if (in == '1')
		{
			feedAussie(aus);
		}
		else if (in == '2')
		{
			waterAussie(aus);
		}
		else if (in == '3')
		{
			abuseAussie(aus);
		}
		else if (in == '4')
		{
			coddleAussie(aus);
		}
		else
		{
			in = 0;
		}
	}
}

void naming(char name[1100])
{
	cout << "Enter a Name: ";
	cin >> name;
}

void printPlaylist(const Playlist& pl)
{
	cout << pl.playlistName << endl;
	for (int i = 0; i < pl.trackCount; i++)
	{
		if (pl.trackList[i].trackName !="")
		{
			cout << pl.trackList[i].trackName << endl;
			cout << (int)pl.trackList[i].playtime << ": " << pl.trackList[i].playtime - (int)pl.trackList[i].playtime * 100 << endl;
		}
		
	}

}
void shufflePlaylist(Playlist& pl)
{
	srand(time(NULL));
	int counter = 20;
	Track temp;

	while (counter > 0)
	{
		int bogo = rand() % (pl.trackCount - 1);

		temp = pl.trackList[bogo];

		pl.trackList[bogo] = pl.trackList[bogo + 1];
		pl.trackList[bogo + 1] = temp;

		counter--;
	}
}
void dedupePlaylist(Playlist& pl)
{
	for (int i = 0; i < pl.trackCount; i++)
	{
		for (int j = i + 1; j < pl.trackCount; j++)
		{
			if (pl.trackList[i].trackName == pl.trackList[j].trackName)
			{
				pl.trackList[j].trackName = "";
				pl.trackList[j].playtime = 0.0f;
			}
		}
	}
}


int main()
{
	/*
	int hotdog = 10;			// primitive variable
	int& dinosaur = hotdog;     // reference to hotdog
	int* dinosaurPtr = &hotdog; // pointer to hotdog

	int tacos = hotdog;			// copies the value of hotdog;

	hotdog = 15;

	cout << hotdog << endl;
	cout << dinosaur << endl;
	cout << *dinosaurPtr << endl;

	cout << "tacos" << endl;
	cout << tacos << endl;

	// References with Functions
	int valA = 1;
	int valB = 2;
	int valC = -1;

	cout << valC << endl;

	sum(valA, valB, valC);

	cout << valC << endl;

	//References with Structs
	Weapon hammer;
	hammer.blutDmg = 9001;
	hammer.magicDmg = 0;
	hammer.bladeDmg = 0;
	
	cout << "BLADE: " << hammer.bladeDmg << endl;
	cout << "BLUNT: " << hammer.blutDmg << endl;
	cout << "MAGIC: " << hammer.magicDmg << endl;

	enhanceWeapon(hammer);

	cout << "BLADE: " << hammer.bladeDmg << endl;
	cout << "BLUNT: " << hammer.blutDmg << endl;
	cout << "MAGIC: " << hammer.magicDmg << endl;

	int thing = -12;

	Weapon arsenal[3] = 
	{	
		//Blunt Magic Blade PID Rarity
		{9001 , 0 ,    0 ,   {0,true}, thing},
		{0 ,   9001 ,  0 ,   {0,true}, thing},
		{0 ,   0 ,    8999 , {0,false}, thing}
	};

	for (int i = 0; i < 3; i++)
	{
		int& pid = arsenal[i].owner.playerID;
		cout << pid << endl;

		if (pid == 0)
		{
			pid = -1;
		}
	}
	*/

	//==CLOSED==
	
	// 1. Creating Refrences

	// variables
	int num = 0;
	float dec = 0.0f;
	bool tf = false;
	char letter = 'a';

	// references to said variables
	int& numRef = num;
	float& decRef = dec;
	bool& tfRef = tf;
	char& letRef = letter;

	// 2. Product of Two Floats

	float valA = 7.2;
	float valB = 4;
	float valC = -3;

	product(valA, valB, valC);

	cout << valC << endl;

	//==OPEN==

	// 1. Swap
	cout << "Value of A Before: " << valA << endl;
	cout << "Value of B Before: " << valB << endl;

	swap(valA, valB);

	cout << "Value of A After:  " << valA << endl;
	cout << "Value of B After:  " << valB << endl;

	// 2. Aussiegochi
	char in = 0;
	char name[1100];
	naming(name);
	Aussiegochi Dundy{10,25,25,10};
	/*
	while (in == 0)
	{
		printStats(Dundy, name);
		interaction(Dundy, in);
		in = 0;
	}
	*/

	// 3. MixTape
	
	Track songs[5];

		songs[0].trackName = "Jesse's Girl";
		songs[0].playtime = 3.13f;
		songs[0].trackName = "Fortunate Son";
		songs[0].playtime = 2.20f;
		songs[0].trackName = "Layla";
		songs[0].playtime = 7.07f;
		songs[0].trackName = "What a Fool Believes";
		songs[0].playtime = 3.39f;
		songs[0].trackName = "Walk";
		songs[0].playtime = 4.15f;
	
		Playlist spotify = { "Awesome",songs,5 };
	printPlaylist(spotify);

	while (true){}
}