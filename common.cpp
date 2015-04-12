#include <iostream>
#include <ctime>
#include <cstdlib>
#include <string>
#include <cmath>
#include "common.h"

using namespace std;

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

string processInput()
{
	string s;
	cin.ignore('\n');
	getline(cin, s);
	return s;
}

char* choices(string s)
{
	char* c = new char[2];
	char sort1 = s[0];
	char sort2 = s[1];
	c[0] = sort1;
	c[1] = sort2;
	return c;
}

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

int executeSort(char choice, int* arr, int size)
{
	int startTime = 0;
	int endTime = 0;
	int elapsedTime = 0;
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


