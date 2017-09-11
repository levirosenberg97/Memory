#include<iostream>

using namespace std;

int sum(int * numA, int * numB)
{
	return *numA + *numB;
}

int difference(int *numA, int *numB)
{
	return *numA - *numB;
}

void pop(int * arr, int size)
{
	for (int i = 0; i < size; i++)
	{
		arr[i] = (i + 1) * 3;
		cout << arr[i] << endl;
	}
	
}

void printArr(int arr[], int *size)
{
	
	for (int i = 0; i < *size; i++)
	{
		cout << arr[i] << endl;
	}
}

void EvenorOdd()
{
	int in = 0;
	int in2 = 0;
	int number = 1;
	int even = 0;
	int odd = 0;

	cout << "How many Numbers Would You Like to Provide: ";
	cin >> in;

	do
	{
		if (in == 0)
		{
			break;
		}
		else
		{
			cout << "Okay, What's Number " << number << "?" << endl;
			cin >> in2;

			in2 %= 2; 
			if (in2 == 0)
			{
				even++;
			}
			else
			{
				odd++;
			}
			number++;
			in--;
		}
	} while (in > 0);
	if (even >= odd)
	{
		cout << "You Sure Like Even Numbers" << endl;
	}
	else
	{
		cout << "You Sure Like Odd Numbers" << endl;
	}
}

void blackJack()
{
	
}

int main()
{
	////Working with Pointers
	////Working with Heap-Allocation Memory
	//int age = 13;
	//cout << age << endl;
	//int * agePtr = new int(22);    //Allocate AGE
	//cout << agePtr << endl;
	//cout << *agePtr << endl;
	//int * ageAlias = &age;
	//
	//*ageAlias = 48;
	//cout << age << endl;
	//cout << *ageAlias << endl;
	//
	//// Pointers as Parameters
	//int result = sum(agePtr, ageAlias);
	//cout << result << endl;
	//delete agePtr;		//Deallocate AGE

	// 1. Heap-Allocated Object

	int * numz = new int(11);
	float * flo = new float(10.0f);
	bool * tf = new bool(false);
	int * wholearr = new int[100];
	float * arrF = new float[16];
	bool * arrB = new bool[10];
	

	delete numz;
	delete flo;
	delete tf;
	delete[] wholearr;
	delete[] arrF;
	delete[] arrB;


	// 2. Subtracting Heap-Allocated Numbers

	int * num = new int(11);
	int * numPtr = new int(5);
	int diff = difference(num, numPtr);
	cout << diff << endl;

	delete num;
	delete numPtr;

	//3. A Heap-Allocated Integer Array

	int * arr = new int[100];

	for (int i = 0; i < 100; i++)
	{
		arr[i] = i + 1;
 		cout << arr[i] << endl;
	}

	delete[] arr;


	//Open

	// 1. Populating an Array From 1 to X(Function)	
	
	int * arrA = new int[100];
	pop(arrA,45);

	delete[] arrA;

	//2. Printing Heap-Allocated Integer Array

	int arrC[5] = { 3,6,8,12,23 };
	int * size = new int(5);

	printArr(arrC, size);

	delete size;

	//3. Heap-Allocated Array of Numbers

	EvenorOdd();

	//Adding Up to 21

	cout << "How Many?" << endl;

	int count = 0;
	cin >> count;

	int* numbers = new int[count];

	for (int i = 0; i < count; i++)
	{
		cout << "Okay what's num " << i + 1 << "?" << endl;

		int userInput = 0;
		cin >> userInput;

		numbers[i] = userInput;
	}

	int total = 0;
	for (int i = 0; i < count; i++)
	{
		total += numbers[i];
	}

	if (total == 21)
	{
		cout << "You CAN Add" << endl;
	}
	else
	{
		cout << "You Suck" << endl;
	}

	delete[]numbers;

	while (true){}
}