//***************************************************************************
//  CODE FILENAME:  BarronValero-assn4-common.cpp
//  DESCRIPTION:    Common Functions used in sorting of arrays 
//  TERM:	    Spring 8 weeks 2 2015
/*			
*/
//  DESIGNER:       Eric Valero / Jose Barron
//  FUNCTIONS:    
/*		 
		    displayHeader-		Displays a quick description of what the program does
		    printDisplay-		Displays a menu to the user to make a selection
		    verifiySorted		verifies array is sorted in ascending order
		    choices			It takes the string inputted by the user, and splits it into 2 characters
		    parseChoice			takes the choice made by the user and assigns it a string value
		    executeSort			calls other functions based on the users selection
*/
//***************************************************************************

#include <iostream>
#include <ctime>
#include <cstdlib>
#include <string>
#include <cmath>
#include "common.h"

using namespace std;


//*********************************************************************
// FUNCTION: 	displayHeader
// DESCRIPTION: prints a brief description of what the program does to the user
// INPUT:	None
// Parameters: 	None
// File: 	None
// OUTPUT:	a brief description of what the program does
// Return Val:  None
//**********************************************************************

void displayHeader()
{
	cout << "This program will display a menu to the user asking them to select 2 choices" << endl;
	cout << "The choices are 4 different types of sorts. After the user selects the choices," << endl;
	cout << "The program will either exit (if that is what the user chooses) or it will asks" << endl;
	cout << "The user how many times they would like to repeat each sort." << endl << endl;
}
//*********************************************************************
// FUNCTION: 	printDisplay
// DESCRIPTION: Prints a menu of possible choices to the user
// INPUT:	None
// Parameters: 	None
// File: 	None
// OUTPUT:	The output is the menu that the user makes there selections off of
// Return Val:  None
//**********************************************************************

void printDisplay()
{
	cout << "Choose two sorts you wish to compare:" << endl;		// this whole function just displays a menu
	cout << "B = Bubble Sort" << endl;
	cout << "I = Insertion Sort" << endl;
	cout << "M = Merge Sort" << endl;
	cout << "Q = Quick Sort" << endl;
	cout << "E = Exit program" << endl;
	cout << endl << endl;
	cout << "Enter two letter choices (or EE to exit) :";
}

//*********************************************************************
// FUNCTION: 	verifySorted
// DESCRIPTION: verifies array is sorted in ascending order
// INPUT:
// Parameters:	
//		*arr - an array of numbers that should be sorted in ascending order
//		size - the size of the array
//
// OUTPUT:
// returned:	true - if the array is sorted
//		false - if the array is not sorted
//**********************************************************************
bool verifySorted(int* arr, int size)
{
	bool sorted = true;							
	for (int count = 0; count < size; count++)						
	{
		if (count == size - 1)				
		{
			sorted = true;
			return sorted;
		}
		if (arr[count] > arr[count + 1])		
		{
			sorted = false;
			return sorted;
		}
	}

	return sorted;


}


//*********************************************************************
// FUNCTION: 	choices
// DESCRIPTION: It takes the string inputted by the user, and splits it into 2 characters
// Parameters: 	input - the choices the user makes
// Return Val: 	choice	- the broken up characters from the user
//**********************************************************************
char* choices(string input)
{
	char* choice = new char[2];
	char sort1 = input[0];
	char sort2 = input[1];
	choice[0] = sort1;
	choice[1] = sort2;
	return choice;
}

//*********************************************************************
// FUNCTION: 	parseChoice
// DESCRIPTION: takes the choice made by the user and assigns it a string value
// INPUT:
// Parameters: 	choice - the choice made by the user (1 at a time will be passed)
// Return Val: 	A string containing the name of the type of sort that was selected
//**********************************************************************
string parseChoice(char choice)
{
	switch (choice)
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

//*********************************************************************
// FUNCTION: 	executeSort
// DESCRIPTION: Takes the choice that the user inputted and calls the functions
//		required in order to execute the requested type of sort.  This
//		function also keeps track of the time it takes the execute the sort
// INPUT:
// Parameters: 
//			choice	- the chocies inputted by the user
//			* arr	- the array of random numbers
//			size	- size of array
//
// OUTPUT:
// Return Val	 	elapsedTime - the total amount of time it took to perform the sort

// Parameters: 		testSorted	- array that gets sorted
//			size		- size of array

// CALLS TO: 		depending on the user's choice one of the following for will be called:
//			bubbleSort, insertionSort, mergeSort, quickSort
//			
//			verifySorted	Will alwasy be called
//**********************************************************************
int executeSort(char choice, int* arr, int size)
{
	int startTime = 0;							// start time initialized to 0
	int endTime = 0;							// end time initialized to 0
	int elapsedTime = 0;							// elapsed time initialized to 0
	int* testSorted = arr;							// testSorted initialized to array
										// passed down by parameters
	switch (choice)
	{
		case 'B':							// if choice is B
			startTime = clock();					//start keeping track of time
			cout << "Executing bubble sort" << endl;		// prompts user that bubble sort is occuring
			testSorted = bubbleSort(testSorted, size);		// sorts array using bubbleSort
			if (verifySorted(testSorted, size))			// if array is sorted
			{
				cout << "Sorted validated!" << endl;		// confirmation message
				endTime = clock();				// stop keeping track of time
			}
			elapsedTime = endTime - startTime;			// calculates time
			return elapsedTime;				
			break;

		case 'I':							// if choice is A
			startTime = clock();					// start keeping track of time
			cout << "Executing insert sort" << endl;		// prompts message to user
			testSorted = insertionSort(testSorted, size);		// array is sorted using insertionSort
			if (verifySorted(testSorted, size))			// array sort is verified
			{
				cout << "Sorted validated!" << endl;		// confirmation message
				endTime = clock();				// stop keeping track of time
			}
			elapsedTime = endTime - startTime;			// calculate time
			return elapsedTime;				
			break;

		case 'M':
			startTime = clock();					// start keeping track of time
			cout << "Executing merge sort" << endl;			// prompt message to user
			testSorted = mergeSort(testSorted, 0, size - 1);	// array sorted using test sort
			if (verifySorted(testSorted, size))			// verifies arra is sorted
			{
				cout << "Sorted validated!" << endl;		// confirmation message
				endTime = clock();				// stops keeping track of time
			}
			elapsedTime = endTime - startTime;			// calculates time
			return elapsedTime;					
			break;

		case 'Q':
			startTime = clock();					// starts keeping track of time
			cout << "Executing quick sort" << endl;			// prompts user that sort has begun
			quickSort(testSorted, 0, size - 1);			// quick sort is used to sort array
			if (verifySorted(testSorted, size))			// sorted array is verified
			{
				cout << "Sorted validated!" << endl;		// confirmation message is sent to user
				endTime = clock();				// time stops
			}
			elapsedTime = endTime - startTime;			// calculates time
			return elapsedTime;
			break;

		default: cout << "INVALID INPUT ERROR" << endl;			// default message
	}
}


