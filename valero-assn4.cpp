//***************************************************************************
//  CODE FILENAME:  Valero-assn4-funcs.cpp
//  DESCRIPTION:    Functions used in sorting of arrays 
//  TERM:	    Spring 8 weeks 2 2015
/*			
*/
//  DESIGNER:       Eric Valero
//  FUNCTIONS:    
/*		 
		    bubbleSort-		sorts array using the bubble sort algorithm
		    merge-		sorts an array using the merge sort method
		    mergeSort-		merges two arrays together, used in part of the merge sort sorting method
		    averageResults-	Function to average out the number of tics from a results array
		    
					
*/
//***************************************************************************/


#include <iostream>
#include <ctime>
#include <cstdlib>
#include <string>
#include <cmath>
#include "valero-assn4.h"

using namespace std;

//*********************************************************************
// FUNCTION: 	bubbleSort
// DESCRIPTION: sorts an array using the bubble sort algorithm
// INPUT:
// Parameters: 	*arr	- an array with random values
//		size	- the size of the array
// OUTPUT:
// Return Val: 	arr	- the array sorted using insertion sort
// IMPLEMENTED BY:	Eric Valero
//**********************************************************************
int* bubbleSort(int* arr, int size)
{
	for (int i = 0; i < size; i++)					
	{
		for (int j = i + 1; j < size; j++)				// starts at 2nd element
		{
			if (arr[j] < arr[i])					// if right element is greater than left
			{							// temp is used to swap
				int temp = arr[i];				//swaps entries in array
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
	}

	return arr;								// returns sorted array

}

//*********************************************************************
// FUNCTION: 	merge
// DESCRIPTION: sorts an array using the merge sort method
// INPUT:
// Parameters: 	*input	- array
//		pivot	- the starting point for the sorting
//		right	- the furthest right element of the array
// IMPLEMENTED BY:	Eric Valero
//**********************************************************************
void merge(int* input, int pivot, int right)
{
	int mid = floor((pivot + right) / 2);					// gives mid a value
	int i1 = 0;								// i1 is set to first element
	int i2 = pivot;								// i2 is set to pivot
	int i3 = mid + 1;							// i3 is to the right of mid

	int* temp = new int[right - pivot + 1];					// Temp array
	
	while (i2 <= mid && i3 <= right)					// Merge in sorted form the 2 arrays
		if (input[i2] < input[i3])
			temp[i1++] = input[i2++];
		else
			temp[i1++] = input[i3++];

	while (i2 <= mid)							// Merge the remaining elements in left array
		temp[i1++] = input[i2++];

	while (i3 <= right)							// Merge the remaining elements in right array
		temp[i1++] = input[i3++];

	for (int i = pivot; i <= right; i++)					// Move from temp array to master array
		input[i] = temp[i - pivot];
}

//*********************************************************************
// FUNCTION: 	mergeSort
// DESCRIPTION: merges two arrays together, used in part of the merge sort sorting method
// INPUT:
// Parameters: 	*input	- an array with random values
//		pivot	- the starting point for the sort
//		right	- the last element in the array
// OUTPUT:
// Return Val: 	input	- sorted merged array
// calls to:	mergeSort, merge
// IMPLEMENTED BY:	Eric Valero
//**********************************************************************
int* mergeSort(int* input, int pivot, int right)
{
	if (pivot < right)								// if starting point is greater then last element
	{
		int mid = floor((pivot + right) / 2);					// mid is given the value
		mergeSort(input, pivot, mid);						// mergeSort calls itself to sort and merge
		mergeSort(input, mid + 1, right);
		merge(input, pivot, right);					
	}

	return input;
}
//*********************************************************************
// FUNCTION: 	averageResults
// DESCRIPTION: Function to average out the number of tics from a results array
// INPUT:
// Parameters: 	*arr	- array passed down from other functions
//		size	- the size of the array
// OUTPUT:
// Return Val: 	average - the average value
// IMPLEMENTED BY:	Eric Valero
//**********************************************************************
double averageResults(int* arr, int size)
{
	double average;
	double total = 0.0;							//total initialized
	for (int i = 0; i < size; i++)						
	{
		total += arr[i];						// total is equal to total plus array value
	}

	average = total / size;				
	return average;								// returns average


}


double** results(int arraySize) {
	double** results = new double*[2];
	double* result1 = new double[arraySize];
	double* result2 = new double[arraySize];
	
	results[0] = new double[arraySize];
	results[1] = new double[arraySize];
	
	return results;
}
