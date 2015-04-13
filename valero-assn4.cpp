//-------------------------------------------------------------------------
//FILE: valero-assn3.cpp
//DESCRIPTION: files developed by Eric Valero
//Functions:	print array- prints the array its passed
//				bubble sort- performs bubble sort
//				merge- merges two arrays
//				merge sort- performs merge sort
//				average results- finds average of results array
//				results- contains results
//-------------------------------------------------------------------------
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <string>
#include <cmath>
#include "valero-assn4.h"

using namespace std;

//-------------------------------------------------------------------------
//FUNCTION: printArray
//DESCRIPTION: prints the results of an array
//INPUT:
//	Parameters: arr- an array
//				size- size of arr
//-------------------------------------------------------------------------
void printArray(int* arr, int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << arr[i] << endl;
	}
}

//-------------------------------------------------------------------------
//FUNCTION: bubbleSort
//DESCRIPTION: performs bubble sort
//INPUT:
//	Parameters: arr- array to sort
//				size- size of array
//-------------------------------------------------------------------------
int* bubbleSort(int* arr, int size)
{
	//bubble sort outer loop runs through unsorted array sections
	for (int i = 0; i < size; i++)
	{
		//inner loop allows bubbling
		for (int j = i + 1; j < size; j++)
		{
			if (arr[j] < arr[i])
			{
				int temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
	}

	return arr;

}

//------------------------------------------------------------------------
//FUNCTION: merge
//DESCRIPTION: merges two arrays
//INPUT:
//	Parameters: input- pointer to an integer array
//				p- bottom of array
//				r- top of array
//------------------------------------------------------------------------
void merge(int* input, int p, int r)
{
	int mid = floor((p + r) / 2);
	int i1 = 0;
	int i2 = p;
	int i3 = mid + 1;

	// Temp array
	int* temp = new int[r - p + 1];

	// Merge in sorted form the 2 arrays
	while (i2 <= mid && i3 <= r)
		if (input[i2] < input[i3])
			temp[i1++] = input[i2++];
		else
			temp[i1++] = input[i3++];

	// Merge the remaining elements in left array
	while (i2 <= mid)
		temp[i1++] = input[i2++];

	// Merge the remaining elements in right array
	while (i3 <= r)
		temp[i1++] = input[i3++];

	// Move from temp array to master array
	for (int i = p; i <= r; i++)
		input[i] = temp[i - p];
}

//-----------------------------------------------------------------------
//FUNCTION: mergeSort
//DESCRIPTION: performs merge sort
//INPUT:
//	Parameters: input- pointer to int array
//				p- bottom of array
//				r- top of array
//RETURN VAL: input- sorted array
//CALLS TO: merge
//-----------------------------------------------------------------------
int* mergeSort(int* input, int p, int r)
{
	if (p < r)
	{
		int mid = floor((p + r) / 2);
		mergeSort(input, p, mid);
		mergeSort(input, mid + 1, r);
		merge(input, p, r);
	}

	return input;
}

//------------------------------------------------------------------------
//FUNCTION: averageResults
//DESCRIPTION: finds average of all values in an array
//INPUT:
//	Parameters: arr- input array
//				size- size of arr
//RETURN VAL: average value
//------------------------------------------------------------------------
double averageResults(int* arr, int size)
{
<<<<<<< HEAD
	double total = 0.0;
	for (int i = 0; i < size; i++)
=======
	double average;
	double total = 0.0;							//total initialized
	for (int i = 0; i < size; i++)						
>>>>>>> 4fd455e595350541df79f42944e64331caff9c53
	{
		total += arr[i];
	}

	return total / size;


}

//------------------------------------------------------------------------
//FUNCTION: results
//DESCRIPTION: contains an array of pointers to both results arrays
//INPUT:
//	Parameters: arraySize
//OUTPUT:
//	Return Val: results- an array containing both results arrays as pointers
//------------------------------------------------------------------------
double** results(int arraySize) {
	double** results = new double*[2];
	double* result1 = new double[arraySize];
	double* result2 = new double[arraySize];
	
	results[0] = new double[arraySize];
	results[1] = new double[arraySize];
	
	return results;
}
