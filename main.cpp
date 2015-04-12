#include <iostream>
#include <ctime>
#include <cstdlib>
#include <string>
#include <cmath>
#include "common.h"

using namespace std;

int main()
{

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

