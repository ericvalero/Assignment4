//--------------------------------------------------------------------------
//FILE: common.cpp
//DESCRIPTION: contains common function bodies
//--------------------------------------------------------------------------
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <string>
#include <cmath>
#include "common.h"

using namespace std;

//--------------------------------------------------------------------------
//FUNCTION: printDisplay
//DESCRIPTION: displays the main menu
//--------------------------------------------------------------------------
void printDisplay()
{
	cout << "Choose two sorts you wish to compare:" << endl;
	cout << "B = Bubble Sort" << endl;
	cout << "I = Insertion Sort" << endl;
	cout << "M = Merge Sort" << endl;
	cout << "Q = Quick Sort" << endl;
	cout << "E = Exit program" << endl;
	cout << endl << endl;
	cout << "Enter two letter choices (or EE to exit) :";
}

//--------------------------------------------------------------------------
//FUNCTION: verifySorted
//DESIGNER: Eric Valero
//DESCRIPTION: verifies that an array is sorted
//INPUT:
//	Parameters: arr- array to check
//				size- size of array
//--------------------------------------------------------------------------
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

//-------------------------------------------------------------------------
//FUNCTION: processInput
//DESIGNER: Jose Barron
//DESCRIPTION: recieves user input as a string
//-------------------------------------------------------------------------
string processInput()
{
	string s;
	cin.ignore('\n');
	getline(cin, s);
	return s;
}

//------------------------------------------------------------------------
//FUNCTION: choices
//DESIGNER: Eric Valero
//DESCRIPTION: returns a pointer to an array of user choices
//INPUT:
//	Parameters: s- string containing both user choices
//OUTPUT:
//	Return value- c- array containing both user choices
//------------------------------------------------------------------------
char* choices(string s)
{
	char* c = new char[2];
	char sort1 = s[0];
	char sort2 = s[1];
	c[0] = sort1;
	c[1] = sort2;
	return c;
}

//------------------------------------------------------------------------
//FUNCTION: parseChoice
//DESIGNER: Jose Barron
//DESCRIPTION: returns a string describing user choice
//INPUT:
//	Parameters: c- character extracted from user entry string
//OUTPUT:
//	Return Val: string contiaining user selection
//------------------------------------------------------------------------
string parseChoice(char c)
{
	switch (c)
	{
	
		case 'B':
			return "Bubble Sort";
			break;
		case 'I':
			return "Insertion Sort"; 
			break;
		case 'M':
			return "Merge Sort";
			break;
		case 'Q':
			return "Quick Sort";
			break;
	
		default: cout << "ERROR INPUT ERROR" << endl;
	

	}
	

}

//------------------------------------------------------------------------
//FUNCTION: executeSort
//DESIGNER: Eric Valero
//DESCRIPTION: executes sort choice
//INPUT:
//	Parameters: choice- user choice
//				arr- array to be sorted
//				size- size of array
//------------------------------------------------------------------------
int executeSort(char choice, int* arr, int size)
{
	int startTime = 0, endTime = 0, elapsedTime = 0;
	int* testSorted = arr;
	switch (choice)
	{
		case 'B':
			startTime = clock();
			cout << "Executing bubble sort" << endl;
			testSorted = bubbleSort(testSorted, size);
			if (verifySorted(testSorted, size))
			{
				cout << "Sorted validated!" << endl;
				endTime = clock();
			}
			elapsedTime = endTime - startTime;
			return elapsedTime;
			break;

		case 'I':
			startTime = clock();
			cout << "Executing insert sort" << endl;
			testSorted = insertionSort(testSorted, size);
			if (verifySorted(testSorted, size))
			{
				cout << "Sorted validated!" << endl;
				endTime = clock();
			}
			elapsedTime = endTime - startTime;
			return elapsedTime;
			break;

		case 'M':
			startTime = clock();
			cout << "Executing merge sort" << endl;
			testSorted = mergeSort(testSorted, 0, size-1);
			if (verifySorted(testSorted, size))
			{
				cout << "Sorted validated!" << endl;
				endTime = clock();
			}
			elapsedTime = endTime - startTime;
			return elapsedTime;
			break;

		case 'Q':
			startTime = clock();
			cout << "Executing quick sort" << endl;
			quickSort(testSorted, 0, size-1);
			if (verifySorted(testSorted, size))
			{
				cout << "Sorted validated!" << endl;
				endTime = clock();
			}
			elapsedTime = endTime - startTime;
			return elapsedTime;
			break;

		default: cout << "INVALID INPUT ERROR" << endl;
	
	}

}


