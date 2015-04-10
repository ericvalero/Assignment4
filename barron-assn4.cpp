#include "barron-assn4.h"
#include <cmath>
//create random arrays

//merge sort
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

//insertion sort
int* insertionSort(int* arr, int size)
{
	int i, j, temp;
	for (i = 1; i<size; i++)
	{
		temp = arr[i];
		j = i - 1;
		while (temp<arr[j] && j >= 0)
		{
			arr[j + 1] = arr[j];
			--j;
		}
		arr[j + 1] = temp;
	}
	return arr;
}
