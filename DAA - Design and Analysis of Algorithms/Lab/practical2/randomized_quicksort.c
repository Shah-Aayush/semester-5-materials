#include <stdio.h>
#include <time.h>
#include <stdlib.h>

//FINAL

void swap(int *xp, int *yp){
	int temp = *xp;
	*xp = *yp;
	*yp = temp;
}

int partition (int arr[], int low, int high, int randomIndex)
{
//	int pivot = arr[high];
	int pivot = arr[randomIndex];
	int pivotIndex = randomIndex;
	
	int i = (low - 1);
	for (int j = low; j <= high; j++){
		if (arr[j] < pivot){
			i++;
			if(pivotIndex==i){
				pivotIndex = j;
			}
			swap(&arr[i], &arr[j]);
			
		}
	}
	i++;
	swap(&arr[i], &arr[pivotIndex]);
//	return (i + 1);
	return i;
}

int random_partition(int arr[], int low, int high){
	srand(time(NULL));
	int randomIndex = low + rand() % (high-low);
//	swap(&arr[random], &arr[high]);
	return partition(arr, low, high, randomIndex);
}

void quickSort(int arr[], int low, int high){
	if (low < high){
//		int pi = partition(arr, low, high);
		
		int pi = random_partition(arr,low,high);
		quickSort(arr, low, pi - 1);
		quickSort(arr, pi + 1, high);
	}
}

void printArray(int arr[], int size){
	int i;
	for (i = 0; i < size; i++)
		printf("%d ",arr[i]);
}

int main() {
	int lower = 0;
	int upper = 1000;
	int count = 10;
	int arr[count];
	
	clock_t start, end;
	double cpu_time_used;
	
	srand(time(0));
	
	for (int i = 0; i < count; i++){
		int num = (rand() % (upper - lower + 1)) + lower;
		arr[i] = num;
	}
	
//	int arr[] = {64, 34, 25, 12, 22, 11, 90};
	int n = sizeof(arr)/sizeof(arr[0]);
	
	printArray(arr, n);
	//QUICK SORT
	start = clock();
	quickSort(arr, 0, n-1);
	end = clock();
	cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
	printf("\nSorted array in %f seconds with QUICK sort: \n",cpu_time_used);
	printArray(arr, n);
	
	
	return 0;
}