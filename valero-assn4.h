#include <iostream>
#include <ctime>
#include <cstdlib>
#include <string>
#include <cmath>

//FUNCTION PROTOTYPES

//Function to print out any array of numbers
void printArray(int* arr, int size);

//Function that sorts an array using the bubble sort method
int* bubbleSort(int* arr, int size);

//Function that sorts an array using the merge sort method
int* mergeSort(int* input, int p, int r);

//Function that merges two arrays together, used in part of the merge sort sorting method
void merge(int* input, int p, int r);

//Function to average out the number of tics from a results array
double averageResults(int* arr, int size);

double** results(int);
