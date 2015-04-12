#include <iostream>
#include <ctime>
#include <cstdlib>
#include <string>
#include <cmath>
#include "barron-assn4.h"

using namespace std;

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

int* createCopy(int* arr, int size)
{
	int* newArray = new int[size];
	for (int i = 0; i < size; i++)
	{
		newArray[i] = arr[i];
	}

	return newArray;

}

void quickSort(int* arr, int left, int right) 
{

	int i = left, j = right;

	int tmp;

	int pivot = arr[(left + right) / 2];


	while (i <= j) {

		while (arr[i] < pivot)

			i++;

		while (arr[j] > pivot)

			j--;

		if (i <= j) {

			tmp = arr[i];

			arr[i] = arr[j];

			arr[j] = tmp;

			i++;

			j--;

		}

	};


	if (left < j)

		quickSort(arr, left, j);

	if (i < right)

		quickSort(arr, i, right);

}

int** generateArrays(int count, int size)
{

	int** arrays = new int*[count];
	
	for (int i = 0; i < count; i++)
	{
		arrays[i] = new int[size];
		for (int j = 0; j < size; j++)
		{
			int randomNumber = rand() % MAXIMUM + MINIMUM;
			arrays[i][j] = randomNumber;
		}
	}

	return arrays;

}

int** copyArrays(int **toCopy, int count, int size)
{
	int **copy = new int*[count];
	for (int i = 0; i < count; i++)
	{
		copy[i] = createCopy(toCopy[i], size);
	}
	return copy;

}

bool properChoice(string s)
{
	char choice1 = s[0];
	char choice2 = s[1];
	choice1 = toupper(choice1);
	choice2 = toupper(choice2);

	if (choice1 != 'B' && choice1 != 'I' && choice1 != 'M' && choice1 != 'Q' && choice1 != 'E')
	{
		return false;
	}

	if (choice2 != 'B' && choice2 != 'I' && choice2 != 'M' && choice2 != 'Q' && choice2 != 'E')
	{
		return false;
	}

	return true;
}

int getResultSize() {
	int answer;
	cout << "Enter the number of times to repeat each sort (1 or more):";						// I changed this line to match the pdf
	cout << endl;
	cin >> answer;
	return answer;
}
