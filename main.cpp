
//  CODE FILENAME:  BarronValero-assn4-main.cpp
//  Spring 8 week 2 2015
//  DESCRIPTION:    This is the main function, this particular file simply calls multiple other
//		    functions that will perform there jobs.
//  DESIGNER:       Jose Barron / Eric Valero
//  FUNCTIONS:      			
//				        properChoice	- Function to ensure one of the 5 letters options is input
//					choices		- Function that takes a string and returns the two sort method choices
//					getResultSize	- Fucntion that asks the user for the number of times to repeat each sort
//					generateArrays	- Function that generates number of random arrays based on user's choice returns an array of arrays
//					copyArrays	- Function that creates an identical copy of the generated arrays for use for both sorts
//					executeSort	- Function that executes a sort based on a character input and returns the number of tics it took to run
//					parseChoice	- Function to return a string based on the sort char passed in
//					averageResult	- Function to average out the number of tics from a results array
//					printDisplay	- Function to display the user menu
//					displayHeader	- Displays a brief description of what the program does
//***************************************************************************/

#include <iostream>
#include <ctime>
#include <cstdlib>
#include <string>
#include <cmath>
#include "common.h"

using namespace std;

//*********************************************************************
// FUNCTION: 	main
// DESCRIPTION: this function primarily calls other functions to perform there jobs
//		the end result of this is arrays are sorted using 2 different sort methods,
//		however many times the user decided to perform the sort
// INPUT:
// Parameters: 	none
// Return Val:  no return value
// calls to:	properChoice, choices, getResultSize, generateArrays, copyArrays, executeSort
//		parseChoice, averageResults, printDisplay, displayHeader
//**********************************************************************

int main()
{	
	displayHeader();
	
	//Seed our random number generator in order to verify random data 
	srand(time(NULL));

	//Our boolean that controls our user menu loop
	bool running = true;

	while (running)
	{
		
		int numberOfLoops = 0;
		string sortChoice = " ";

		//Print sort menu to user
		printDisplay();
		
		bool trying = true;
		while (trying)
		{
			//Get our user input for which two sorting methods to compare
			getline(cin, sortChoice);
			
			//Ensure our user followed proper input
			if (sortChoice.size() != 2  || !properChoice(sortChoice))
			{
				//Try again if invalid input
				cout << "Please provide proper input and try again!" << endl;
			}
			else
			{
				trying = false;
			}
		}

		//Split our input string into two upper case characters representing the users two sort choices
		char* splitChoice = choices(sortChoice);
		char choice1 = splitChoice[0];
		char choice2 = splitChoice[1];
		choice1 = toupper(choice1);
		choice2 = toupper(choice2);

		//Exit if user chose 'EE'
		if (choice1 == 'E' || choice2 == 'E')
		{
			running = false;
		}
		//Else we execute the sorts with the two chosen methods
		if (running)
		{
			//Get the users desired number of times to run
			numberOfLoops = getResultSize();
			cin.ignore();
			cout << endl;

			//Allocate memory for our results of the two methods
			int* resultsSort1 = new int[numberOfLoops];
			int* resultsSort2 = new int[numberOfLoops];
		
			//Allocate memory and fill our arrays for the two different sorting methods
			int** sortArrays1 = generateArrays(numberOfLoops, SIZE);
			int** sortArrays2 = copyArrays(sortArrays1, numberOfLoops, SIZE);
		
			//Sort through and output our data
			for (int i = 0; i < numberOfLoops; i++)
			{
				cout << "Starting sort #" << i + 1 << "..." << endl << endl;
				
				//Execute our two sorts and return the tics taken to sort
				int tics1 = executeSort(choice1, sortArrays1[i], SIZE);
				int tics2 = executeSort(choice2, sortArrays2[i], SIZE);

				cout << parseChoice(choice1) << " time " << tics1 << endl;
				cout << parseChoice(choice2) << " time " << tics2 << endl;

				cout << endl;

				//Store our data in our results array after outputting to screen
				resultsSort1[i] = tics1;
				resultsSort2[i] = tics2;
			}
			//Print out our final averages
			cout << endl << "SORTING RESULTS" << endl;
			cout << "-----------------------------------" << endl;
			cout << "\t" << parseChoice(choice1) << " " << averageResults(resultsSort1, numberOfLoops) << " tics on average" << endl;
			cout << "\t" << parseChoice(choice2) << " " << averageResults(resultsSort2, numberOfLoops) << " tics on average" << endl;
			
			//Deallocate memory of the arrays we used
			delete resultsSort1;
			delete resultsSort2;
			delete sortArrays1;
			delete sortArrays2;
		
		}
	
	
	}
	
	return 0;
}

