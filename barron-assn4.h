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

bool properChoice(string);

int getResultSize();
