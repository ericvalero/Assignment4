#include <iostream>
#include <ctime>
#include <time.h>
#include <stdlib.h>
#include "common.h"
#include "valero-assn4.h"
#include "barron-assn4.h"

using namespace std;
//main implemented by eric valero

int main()
{
	//this is an array of pointers to the results arrays. 
	//indexes 0 and 1 are the two arrays
	//access them using the syntax: (resultsArrays[index(1 or 2)])[index]
	int numResults = getResultSize();
    double** resultsArrays = results(numResults);
    
    //this is just a test to demonstrate how the results array functions
    (resultsArrays[0])[0] = 1.2;
    cout << (resultsArrays[0])[0];
    cin.get();
    //end test
    
    
	int startTime = 0, endTime = 0, elapsedTime = 0;
	bool looping = true;
	char input;
	srand(time(NULL));
	int* test = new int[100000];
	int* insertSorted = new int[100000];
	for (int i = 0; i < 100000; i++)
	{
		int randomNumber = rand() % 30000 + 1;
		test[i] = randomNumber;
	}
	while (looping)
	{
		printDisplay();
		cin >> input;
		input = toupper(input);
		switch (input)
		{
			
			case 'B': 
				cout << "Executing bubble sort" << endl;	
				break;

			case 'I':
				startTime = clock();
				cout << "Executing insert sort" << endl;
				insertSorted = insertionSort(test, 100000);
				if (verifySorted(insertSorted, 100000))
				{
					cout << "IT WORKED" << endl;
				}
				endTime = clock();
				elapsedTime = endTime - startTime;
				cout << "This insert sort took " << elapsedTime << " tics..." << endl;
				//resultArray[0] = elapsedTime;
				//resultArray[1] = elapsedTime;
				//resultArray[2] = elapsedTime;
				break;

			case 'M': 
				cout << "Executing merge sort" << endl;
				break;

			case 'Q': 
				cout << "Executing quick sort" << endl;
				break;

			case 'E': 
				cout << "Exiting program..." << endl;
				looping = false;
				break;

			default: cout << "Incorrect input please try again..." << endl;
		}
	}
	
	
	/*
	int* myArray = new int[10];
	for (int i = 0; i < 10; i++)
	{
		int randomNumber = rand() % 100 + 1;
		myArray[i] = randomNumber;
	}

	printArray(myArray, 10);
	cout << endl;
	cout << verifySorted(myArray, 10);
	cout << endl;

	int* test1 = createCopy(myArray, 10);
	int* test2 = createCopy(myArray, 10);
	int* test3 = createCopy(myArray, 10);
	int* test4 = createCopy(myArray, 10);
	
	int* bubbleSorted = bubbleSort(test1, 10);
	printArray(bubbleSorted, 10);

	cout << endl;
	cout << verifySorted(bubbleSorted, 10);
	cout << endl;

	int* insertSorted = insertionSort(test2, 10);
	printArray(insertSorted, 10);

	cout << endl;

	int* mergeSorted = mergeSort(test3, 0, 9);
	printArray(mergeSorted, 10);

	cout << endl;

	quickSort(test4, 0, 9);
	printArray(test4, 10);

	cout << endl;
	printArray(myArray, 10);
	*/
	
	cout << "This program reached conclusion after " << elapsedTime << " tics of the clock..." << endl;

	return 0;
}
