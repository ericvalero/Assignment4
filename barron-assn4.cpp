//***************************************************************************
//  CODE FILENAME:  Barron-assn4-funcs.cpp
//  DESCRIPTION:    Functions used in order to sort arrays
/*  TERM:	    Spring 8 week 2 2015		
*/
//  DESIGNER:       Jose Barron
//  FUNCTIONS:    
/*			insertionSort-	sorts array using the insertion sort algorithm
			createCopy-	creates a copy of the array that was created earlier
			quickSort-	sorts the array that is passed to it using the quick sort algorithm
			generateArrays-	creates an array using rand() % HighLimit + lowLimit command
			copyArrays-	Description of what the function does
			getResultSize-	asks the user for the number of times to repeat each sort
			properChoice-	ensures that one of the 5 letters options is input
*/
//***************************************************************************/

#include <iostream>
#include <ctime>
#include <cstdlib>
#include <string>
#include <cmath>
#include "common.h"

using namespace std;

//*********************************************************************
// FUNCTION: 	insertionSort
// DESCRIPTION: sorts array using the insertion sort algorithm
// INPUT:
// Parameters: 	*arr	- an array with random values
//		size	- the size of the array
// OUTPUT:
// Return Val: 	arr	- the array sorted using insertion sort
// IMPLEMENTED BY:	Jose Barron
//**********************************************************************
int* insertionSort(int* arr, int size)
{
	int i;								//used for sorting
	int j;								//used for sorting
	int temp;							//used for sorting
	for (i = 1; i < size; i++)					// sorted initialized to 1, because first 
	{								//element is sorted
		temp = arr[i];					
		j = i - 1;						// first entry in the array
		while (temp < arr[j] && j >= 0)				// goes until the entry to the left is smaller
		{
			arr[j + 1] = arr[j];				// shifts all values to the right
			--j;						// updates counter to move left
		}
		arr[j + 1] = temp;					// inserts value into sorted portion of array
	}
	return arr;							// returns sorted array
}

//*********************************************************************
// FUNCTION: 	createCopy
// DESCRIPTION: creates a copy of the array that was created earlier
// INPUT:
// Parameters:	*arr 	- an array with random values
//		size	- size of the array
// OUTPUT:
// Return Val: 	newArray	- new copy of array created
// IMPLEMENTED BY:	Jose Barron
//**********************************************************************
int* createCopy(int* arr, int size)
{
	int* newArray = new int[size];					// a copy of the array is made
	for (int i = 0; i < size; i++)					// for loop is used to make every
	{								// value equal each other
		newArray[i] = arr[i];
	}

	return newArray;						// new array is returned.

}


//*********************************************************************
// FUNCTION: 	quickSort
// DESCRIPTION: sorts the array that is passed to it using the quick sort algorithm
// INPUT:
// Parameters: 	*arr	-an unsorted array holding random values
//		left	- furthest left value
//		right 	- furthest right value
// Parameters:  *arr	- an array not fully sorted
//		left	- the furthest left value
//		right	- the furthest right value
// CALLS TO: 	quickSort
// IMPLEMENTED BY:	Jose Barron
//**********************************************************************
void quickSort(int* arr, int left, int right) 
{

	int i = left;								// i is set to the left value
	int j = right;								// j is set to the right value
	int tmp;								// temp is used for sorting purposes
	int pivot = arr[(left + right) / 2];					// the point where we start sorting
	
	while (i <= j) {							// while the left side is less than or equal to the right

		while (arr[i] < pivot)						// while left is less than the starting point
			i++;							// move on one element to the right

		while (arr[j] > pivot)						// while the right side is greater than the start
			j--;							// move one element to the left

		if (i <= j) {							// if the left side is less than or equal to the right
			tmp = arr[i];						// use tmp to hold value for left side
			arr[i] = arr[j];					// swap occurs
			arr[j] = tmp;
			i++;							// move left end to the right one spot
			j--;							// move right end to the left on spot
		}
	};
	
	if (left < j)								// calls itself until the array is sorted
		quickSort(arr, left, j);

	if (i < right)
		quickSort(arr, i, right);

}

//*********************************************************************
// FUNCTION: 	generateArrays
// DESCRIPTION: creates an array using rand() % HighLimit + lowLimit command
// INPUT:
// Parameters: 	count 	- a counter
//		size	- array size
// OUTPUT:
// Return Val: 	arrays	- the array that gets created
// IMPLEMENTED BY:	Jose Barron
//**********************************************************************
int** generateArrays(int count, int size)
{

	int** arrays = new int*[count];					// initializes new array
	
	for (int i = 0; i < count; i++)				
	{
		arrays[i] = new int[size];
		for (int j = 0; j < size; j++)				// repeats until all elements of array have values
		{
			int randomNumber = rand() % MAXIMUM + MINIMUM;	// creates random value for array	
			arrays[i][j] = randomNumber;
		}
	}

	return arrays;							// returns array

}

//*********************************************************************
// FUNCTION: 	copyArrays
// DESCRIPTION: Description of what the function does
// INPUT:
// Parameters: 	**toCopy	- array to copy
//		count		- counter for array
//		size		- size of array
// Return Val: 	copy		- new array copy
//calls to:	createCopy
// IMPLEMENTED BY:	Jose Barron
//**********************************************************************
int** copyArrays(int **toCopy, int count, int size)
{
	int **copy = new int*[count];						// new array is created
	for (int i = 0; i < count; i++)						// every value is iterated
	{
		copy[i] = createCopy(toCopy[i], size);				// every vlue of array is passed to createCopy
	}
	return copy;

}


//*********************************************************************
// FUNCTION: 	properChoice
// DESCRIPTION: ensures that one of the 5 letters options is input
// INPUT:
// Parameters: 	input
// Return Val: 	true: if choice is valid
//		false: if choice is invalid
// IMPLEMENTED BY:	Jose Barron
//**********************************************************************

bool properChoice(string input)
{											//string input is broken down into 2 chars
	char choice1 = input[0];							// choice 1 = first letter
	char choice2 = input[1];							// choice 2 = second letter
	choice1 = toupper(choice1);							// converts inputs to uppercase
	choice2 = toupper(choice2);
											// if either choice isnt B, I, M, Q, or E
											// the boolean value returns false
	if (choice1 != 'B' && choice1 != 'I' && choice1 != 'M' && choice1 != 'Q' && choice1 != 'E')
	{
		return false;
	}

	if (choice2 != 'B' && choice2 != 'I' && choice2 != 'M' && choice2 != 'Q' && choice2 != 'E')
	{
		return false;
	}

	return true;									// if valid input the boolean value is true
}

//*********************************************************************
// FUNCTION: 	getResultSize
// DESCRIPTION: asks the user for the number of times to repeat each sort
// INPUT:	answer	- the number of times to repeat each sort
// Parameters: 	none
// Return Val: 	answer	- the number of times to repeat each sort
// IMPLEMENTED BY:	Jose Barron
//**********************************************************************
int getResultSize() {
	int answer;
	cout << "Enter the number of times to repeat each sort (1 or more):";		//asks the user for input
	cout << endl;									// takes input in next line
	cin >> answer;									// user input
	return answer;	
}
