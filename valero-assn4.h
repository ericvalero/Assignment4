//***************************************************************************
//  CODE FILENAME:  Valero-assn4-funcs.h
//  DESCRIPTION:    Functions prototypes used for Valero-assn4-funcs.cpp
//  TERM:	          Spring 8 weeks 2 2015
/*			
*/
//  DESIGNER:       Eric Valero
//  FUNCTIONS:    
/*		 
		    bubbleSort-		  sorts array using the bubble sort algorithm
		    merge-		      sorts an array using the merge sort method
		    mergeSort-		  merges two arrays together, used in part of the merge sort sorting method
		    averageResults-	Function to average out the number of tics from a results array
		    
					
*/
//***************************************************************************/

#include <iostream>
#include <ctime>
#include <cstdlib>
#include <string>
#include <cmath>

//FUNCTION PROTOTYPES

//Function that sorts an array using the bubble sort method
int* bubbleSort(int* arr, int size);

//Function that sorts an array using the merge sort method
int* mergeSort(int* input, int pivot, int right);

//Function that merges two arrays together, used in part of the merge sort sorting method
void merge(int* input, int pivot, int right);

//Function to average out the number of tics from a results array
double averageResults(int* arr, int size);

double** results(int);
