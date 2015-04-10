#include <iostream>
using namespace std;

//common functions
void printArray(int* arr, int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << arr[i] << endl;
	}
}

void printDisplay()
{
	cout << "Choose two sorts you wish to compare:" << endl;
	cout << "B = Bubble Sort" << endl;
	cout << "I = Insertion Sort" << endl;
	cout << "M = Merge Sort" << endl;
	cout << "Q = Quick Sort" << endl;
	cout << "E = Exit program" << endl;
}

bool verifySorted(int* arr, int size)
{
	bool sorted = true;
	for (int i = 0; i < size; i++)
	{
		if (i == size - 1)
		{
			sorted = true;
			return sorted;
		}
		if (arr[i]>arr[i + 1])
		{
			sorted = false;
			return sorted;
		}
	}

	return sorted;
}


//create random arrays- Eric Valero


//display menu- Jose Barron
