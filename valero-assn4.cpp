#include <iostream>
#include <ctime>
#include <cstdlib>
#include <string>
#include <cmath>
#include "valero-assn4.h"
#include "common.h"

using namespace std;

void printArray(int* arr, int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << arr[i] << endl;
	}
}

int* bubbleSort(int* arr, int size)
{
	for (int i = 0; i < size; i++)
	{
		for (int j = i + 1; j < size; j++)
		{
			if (arr[j] < arr[i])
			{
				int temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
	}

	return arr;

}

void merge(int* input, int p, int r)
{
	int mid = floor((p + r) / 2);
	int i1 = 0;
	int i2 = p;
	int i3 = mid + 1;

	// Temp array
	int* temp = new int[r - p + 1];

	// Merge in sorted form the 2 arrays
	while (i2 <= mid && i3 <= r)
		if (input[i2] < input[i3])
			temp[i1++] = input[i2++];
		else
			temp[i1++] = input[i3++];

	// Merge the remaining elements in left array
	while (i2 <= mid)
		temp[i1++] = input[i2++];

	// Merge the remaining elements in right array
	while (i3 <= r)
		temp[i1++] = input[i3++];

	// Move from temp array to master array
	for (int i = p; i <= r; i++)
		input[i] = temp[i - p];
}

int* mergeSort(int* input, int p, int r)
{
	if (p < r)
	{
		int mid = floor((p + r) / 2);
		mergeSort(input, p, mid);
		mergeSort(input, mid + 1, r);
		merge(input, p, r);
	}

	return input;
}

double averageResults(int* arr, int size)
{
	double total = 0.0;
	for (int i = 0; i < size; i++)
	{
		total += arr[i];
	}

	return total / size;


}

double** results(int arraySize) {
	double** results = new double*[2];
	double* result1 = new double[arraySize];
	double* result2 = new double[arraySize];
	
	results[0] = new double[arraySize];
	results[1] = new double[arraySize];
	
	return results;
}
