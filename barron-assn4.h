//***************************************************************************
//  CODE FILENAME:  Barron-assn4-funcs.h
//  DESCRIPTION:    Function headers for Barron-assn4-funcs.cpp
/*  TERM:	          Spring 8 week 2 2015		
*/
//  DESIGNER:       Jose Barron
//  FUNCTIONS:      Only the function prototypes will be found in this file
/*		insertionSort-	sorts array using the insertion sort algorithm
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


using namespace std;

//FUNCTION PROTOTYPES

//Function that creates a copy of an array to allow us to have a backup for sorting purposes
int* createCopy(int* arr, int size);

//Function that sorts an array using the insertion sort method
int* insertionSort(int* arr, int size);

//Function that sorts an array using the quicksort sorting method
void quickSort(int* arr, int left, int right);

//Function that generates number of random arrays based on user's choice returns an array of arrays
int** generateArrays(int count, int size);

//Function that creates an identical copy of the generated arrays for use for both sorts
int** copyArrays(int **toCopy, int count, int size);

//Function to ensure one of the 5 letters options is input
bool properChoice(string);

// asks the user how many times to repeat the sort
int getResultSize();
