#include<iostream>
#include<cassert>
#include"globals.h"

using namespace std;

void arrayCopy(int *srcArr, size_t srcSize,
				int *dstArr, size_t dstSize)
{ 
	assert(dstSize >= srcSize);
}

void counterThing()
{
	static int ct = 0;
	ct++;

	cout << ct << endl;
}

void releaseHalfLove()
{
	int num = 1;
	do
	{
		if (num < 3)
		{
			cout << "The Game Half-Life " << num << ", was Released" << endl;
			num++;
			system("pause");
		}
		else
		{
			num = 1;
		}
	} while (num <= 3);
}

void stepFizzBuzz()
{
	
	static int ct = 0;
	ct++;
	if (ct % 3 == 0 && ct % 5 == 0)
	{
		cout << "FizzBuzz" << endl;
	}
	else if (ct % 3 == 0)
	{
		cout << "Fizz" << endl;
	}
	else if (ct % 5 == 0)
	{
		cout << "Buzz" << endl;
	}
	else
	{
		cout << ct << endl;
	}
}

float divide(float lhs, float rhs)
{
	assert(rhs != 0.0f &&"Division by zero detected!");

	return lhs / rhs;
}

void callMeMaybe()
{
	static int counter = 0;
	counter = ++counter % 10;

	if (counter == 0)
	{
		cout << "Howdy!" << endl;
	}
	else if (counter == 1)
	{
		cout << "BUTTS" << endl;
	}
	else if (counter == 1)
	{
		cout << "Madonna is Overated" << endl;
	}
	else if (counter == 1)
	{
		cout << "idk dood" << endl;
	}
}

int& picker(int& optA, int& optB, int& optC, int& temp)
{
	int sum = optA + optB + optC;


	if (temp == 0)
	{
		cout << optA << endl;
		temp += optA;
		return optA;
	}
	else if (temp == optA)
	{
		cout << optB << endl;
		temp += optB;
		return optB;
	}
	else if (temp == optA + optB)
	{
		cout << optC << endl;
		temp += optC;
		return optC;
	}
	if (temp == sum)
	{
		temp = 0;
	}

}

void gridGen(unsigned int width, unsigned int height)
{
	assert(width > -1);
	assert(height > -1);
}

int main()
{
	/*// Preprocessor Directives
	int numA[] = { 3, 2, 1 };
	int numB[] = { 3, 2, 1, 10, 12 };

	diffArrays(numA, 3, numB, 5);

	for (int i = 0; i < 3; i++)
	{
		cout << numA[i] << endl;
	}


	// Static Local Variables
	for (int i = 0; i < 50; i++)
	{
		counter();
	}
	// Global Variables
	cout << globalOffensive << endl;
	makeitOne();
	cout << globalOffensive << endl;
	makeitTwo();
	cout << globalOffensive << endl;
	*/

	//==CLOSED==

	// 1. Counting to Three
	//releaseHalfLove();

	// 2. Iterative Fizz Buzz
	for (int i = 0; i < 30; i++)
	{
		stepFizzBuzz();
	}

	// 3. Shared Counter

	cout << counter << endl;
	increment();
	cout << counter << endl;
	decrement();
	cout << counter << endl;
	increment();
	cout << counter << endl;

	// 4. Dividing by Zero

	//cout << divide(5.0f, 0.0f) << endl;

	//==OPEN==

	// 1. CallMeMaybe

	cout << "Do you Want Some Messages?" << endl;
	
	char in = 0;
	while (in == 0)
	{
		cin >> in;

		if (in == 'y')
		{
			callMeMaybe();
		}
		else if (in = 'n')
		{
			break;
		}
		else
		{
			in = 0;
		}
	}

	// 2. Picker
	int a = 2;
	int b = 4;
	int c = 6;
	int d = 0;

	for (int i = 0; i < 30; i++)
	{
		picker(a, b, c, d);
	}
	
	// 3. Unit Tests


	while(true){}
}