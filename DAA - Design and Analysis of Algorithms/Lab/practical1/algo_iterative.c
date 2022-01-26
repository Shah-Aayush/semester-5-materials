#include <stdio.h>
#include <time.h>
#include <stdlib.h>


void swap(int *xp, int *yp){
	int temp = *xp;
	*xp = *yp;
	*yp = temp;
}

void bubbleSortIterative(int arr[], int n){
	int i, j;
	for (i = 0; i < n-1; i++)     
		for (j = 0; j < n-i-1; j++)
			if (arr[j] > arr[j+1])
				swap(&arr[j], &arr[j+1]);
}

void insertionSortIterative(int arr[], int n){
	int i, key, j;
	for (i = 1; i < n; i++){
		key = arr[i];
		j = i - 1;
		while (j >= 0 && arr[j] > key){
			arr[j + 1] = arr[j];
			j = j - 1;
		}
		arr[j + 1] = key;
	}
}

void selectionSortIterative(int arr[], int n){
	int i, j, min_idx;
	for (i = 0; i < n-1; i++){
		min_idx = i;
		for (j = i+1; j < n; j++)
			if (arr[j] < arr[min_idx])
			min_idx = j;
		swap(&arr[min_idx], &arr[i]);
	}
}

void printArray(int arr[], int size){
	int i;
	for (i=0; i < size; i++)
		printf("%d ", arr[i]);
	printf("\n");
}

int main() {
	int lower = 0;
	int upper = 100000;
	int count = 160000;
	int arrForBubbleSort[count];
	int arrForInsertionSort[count];
	int arrForSelectionSort[count];
	
	clock_t start, end;
	double cpu_time_used;
	
	srand(time(0));
	
	for (int i = 0; i < count; i++){
		int num = (rand() % (upper - lower + 1)) + lower;
		arrForBubbleSort[i] = num;
		arrForInsertionSort[i] = num;
		arrForSelectionSort[i] = num;
	}
	
//	int arr[] = {64, 34, 25, 12, 22, 11, 90};
	int n = sizeof(arrForBubbleSort)/sizeof(arrForBubbleSort[0]);		//as all array are same -> size of all the array will be same.
	
	
	//BUBBLE SORT
	start = clock();
	bubbleSortIterative(arrForBubbleSort, n);
	end = clock();
	cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
	printf("Sorted array in %f seconds with BUBBLE sort: \n",cpu_time_used);
//	printArray(arrForBubbleSort, n);
	
	
	//INSERTION SORT
	start = clock();
	insertionSortIterative(arrForInsertionSort, n);
	end = clock();
	cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
	
	printf("Sorted array in %f seconds with INSERTION sort: \n",cpu_time_used);
//	printArray(arrForInsertionSort, n);
	
	//SELECTION SORT
	start = clock();
	selectionSortIterative(arrForSelectionSort, n);
	end = clock();
	cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
	
	printf("Sorted array in %f seconds with SELECTION sort: \n",cpu_time_used);
//	printArray(arrForSelectionSort, n);
	
	return 0;
}