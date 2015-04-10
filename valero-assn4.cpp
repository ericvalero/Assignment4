//create results arrays
double** results(int arraySize) {
	double** results = new double*[2];
	double* result1 = new double[arraySize];
	double* result2 = new double[arraySize];
	
	results[0] = result1;
	results[1] = result2;
	
	return results;
}

//fill results arrays

//bubble sort
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

//quick sort
void quickSort(int* arr, int left, int right) 
{

	int i = left, j = right;

	int tmp;

	int pivot = arr[(left + right) / 2];



	/* partition */

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



	/* recursion */

	if (left < j)

		quickSort(arr, left, j);

	if (i < right)

		quickSort(arr, i, right);

}

