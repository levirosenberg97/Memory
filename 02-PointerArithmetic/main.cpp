#include<iostream>

using namespace std;

void printFloats(float * arr, int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << *(arr+i) << endl;
	}
}

int arraySum(int * arr, int size)
{
	int sum = 0;
	for (int i = 0; i < size; i++)
	{
		sum += *(arr+i);
	}
	return sum;
}

float arrayAvg(int * arr, int size)
{
	int sum = 0;
	for (int i = 0; i < size; i++)
	{
		sum += *(arr+i);		
	}
	return sum / (float)size;
	
}

int findCount(int target, int * arr, int size)
{
	int counter = 0;
	for (int i = 0; i < size; i++)
	{
		if (target == *(arr + i))
		{
			counter++;
		}
	}
	return counter;
}

void arrCopy(int * srcArr, int srcSize, int * dstArr, int dstSize)
{
	if (srcSize >= dstSize)
	{
		for (int i = 0; i < dstSize; i++)
		{
			*(dstArr + i) = *(srcArr + i);
			cout << *(dstArr + i);
		}
	}
	else
	{
		for (int i = 0; i < srcSize; i++)
		{
			*(dstArr + i) = *(srcArr + i);
			cout << *(dstArr + i);
		}
	}

}

void arrReversal(int * arr, int size)
{
	for (int i = size; i > 0; i--)
	{
		cout << *(arr + (i - 1)) << endl;;
	}
}

void cstrReversal(char * arr, int size)
{

	cout << "Enter Anything: ";
	cin >> arr;
	
	for (int i = strlen(arr); i > 0; i--)
	{
			cout << *(arr + (i - 1));	
	}
}


int main()
{
	
	//Pointer Arithmetic
	int a = 0;
	int b = 1;
	int c = 2;


	struct
	{
		int a;
		int b;
		int c;
	}thing;

	thing.a = 2;
	thing.b = 3;
	thing.c = 3;

	cout << thing.a << endl;
	cout << thing.b << endl;
	cout << thing.c << endl;

	cout << *((&thing.a) + 1) << endl;
	cout << *((&thing.b) + 1) << endl;
	cout << *((&thing.c) + 1) << endl;

	for (int i = 0; i < 3; i++)
	{
		cout << *((&thing.a) + 1) << endl;
	}

	//Pointer Arithmetic 2 :I Want to Die Edition
	int * hArr = new int[2];

	hArr[0] = 1;
	hArr[1] = 2;

	cout << hArr[0] << endl;
	cout << hArr[1] << endl;

	cout << hArr[0] << endl;
	cout << *(hArr + 1) << endl;

	int *arrLarge = new int[100];
	int arrLargeStack[100];

	for (int i = 0; i < 100; i++)
	{
		arrLarge[i] = i;
		arrLargeStack[i] = i;
	}

	for (int i = 0; i < 100; i++)
	{
		cout << *(arrLarge + 1) << endl;
	}

	delete[] hArr;

	//Type Casting
	float dollars = 1.80f;

	cout << dollars << endl;
	cout << (int)dollars << endl;
	

	//==CLOSED==
	// 1. Print an Array of Floats

	float  arrA[] = { 21.4,32.32,3.1,654.3,21.34 };
	printFloats(arrA, 5);

	// 2. Sum of Interger Array
	int arrB[] = { 1,2,3,4,5 };
	cout << arraySum(arrB,5) << endl;

	// 3. Average of Integer Array

	cout << arrayAvg(arrB, 5) << endl;


	//==OPEN==
	// 1. FindCount
	int in = 0;
	cout << "What Number?: ";
	cin >> in;
	int arrC[] = { 3,2,3,2,1,321 };
	cout << "There are " << findCount(in, arrC, 5) << " " << in << "s in this Array" << endl;

	// 2. Array Copy
	int *arrD = new int[50];
	arrCopy(arrB, 5, arrD, 5);

	// 3. Array Reversal	
	arrReversal(arrC,6);
	cout << "\n " << endl;

	// 4. String Reversal;
	char name[50];
	cstrReversal(name , 12);

	//

	while(true){}
}