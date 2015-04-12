#include <iostream>
#include <ctime>
#include <cstdlib>
#include <string>
#include <cmath>
#include "barron-assn4.h"

using namespace std;

//*********************************************************************
// FUNCTION: 	insertionSort
// DESCRIPTION: sorts array using the insertion sort algorithm
// INPUT:
// Parameters: 	*arr	- an array with random values
//		size	- the size of the array
// OUTPUT:
// Return Val: 	arr	- the array sorted using insertion sort
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
		arr[unsorted + 1] = temp;				// inserts value into sorted portion of array
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
// Return Val: 	newArray
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

void quickSort(int* arr, int left, int right) 
{

	int i = left;
	int j = right;

	int tmp;

	int pivot = arr[(left + right) / 2];


	while (i <= j) {

		while (arr[i] < pivot)

			i++;

		while (arr[j] > pivot)

			j--;

		if (i <= j) {

			tmp = arr[i];

			arr[i] = arr[j];

			arr[j] = tmp;

			i++;

			j--;

		}

	};


	if (left < j)

		quickSort(arr, left, j);

	if (i < right)

		quickSort(arr, i, right);

}

int** generateArrays(int count, int size)
{

	int** arrays = new int*[count];
	
	for (int i = 0; i < count; i++)
	{
		arrays[i] = new int[size];
		for (int j = 0; j < size; j++)
		{
			int randomNumber = rand() % MAXIMUM + MINIMUM;
			arrays[i][j] = randomNumber;
		}
	}

	return arrays;

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
//**********************************************************************
int getResultSize() {
	int answer;
	cout << "Enter the number of times to repeat each sort (1 or more):";		//asks the user for input
	cout << endl;									// takes input in next line
	cin >> answer;									// user input
	return answer;	
}
