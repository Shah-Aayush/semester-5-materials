#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void swap(int *xp, int *yp){
	int temp = *xp;
	*xp = *yp;
	*yp = temp;
}

void bubbleSortRecursive(int arr[],int n){
	if(n==1)
		return;
	for(int i=0;i<n-1;i++)
		if(arr[i]>arr[i+1])
			swap(&arr[i],&arr[i+1]);
	bubbleSortRecursive(arr, n-1);
}

void insertionSortRecursive(int arr[], int n){
	if (n <= 1)
		return;
	insertionSortRecursive( arr, n-1 );
	int last = arr[n-1];
	int j = n-2;
	while (j >= 0 && arr[j] > last){
		arr[j+1] = arr[j];
		j--;
	}
	arr[j+1] = last;
}

int minIndex(int a[], int i, int j){
	if (i == j)
		return i;
	int k = minIndex(a, i + 1, j);
	return (a[i] < a[k])? i : k;
}

void selectionSortRecursive(int a[], int n, int index)
{
	if (index == n)
		return;
	int k = minIndex(a, index, n-1);
	if (k != index)
		swap(&a[k], &a[index]);
	
	selectionSortRecursive(a, n, index + 1);
}

void printArray(int arr[], int n)
{
	for (int i=0; i < n; i++)
		printf("%d ", arr[i]);
	printf("\n");
}

int main() {
	int lower = 0;
	int upper = 100000;
	int count = 10000;
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
	bubbleSortRecursive(arrForBubbleSort, n);
	end = clock();
	cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
	printf("Sorted array in %f seconds with BUBBLE sort: \n",cpu_time_used);
	//	printArray(arrForBubbleSort, n);
	
	
	//INSERTION SORT
	start = clock();
	insertionSortRecursive(arrForInsertionSort, n);
	end = clock();
	cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
	
	printf("Sorted array in %f seconds with INSERTION sort: \n",cpu_time_used);
	//	printArray(arrForInsertionSort, n);
	
	//SELECTION SORT
	start = clock();
	selectionSortRecursive(arrForSelectionSort, n, 0);
	end = clock();
	cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
	
	printf("Sorted array in %f seconds with SELECTION sort: \n",cpu_time_used);
	//	printArray(arrForSelectionSort, n);
	
	return 0;
}