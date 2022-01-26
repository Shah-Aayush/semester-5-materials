#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <stdbool.h>

void printArray(int arr[], int size){
	int i;
	for (i = 0; i < size; i++)
		printf("%d ",arr[i]);
}

void swap(int *xp, int *yp){
	int temp = *xp;
	*xp = *yp;
	*yp = temp;
}

int partition (int arr[], int low, int high, int pivot)
{
//	int pivot = arr[high];
	int i = (low - 1);
//	bool flag = false;
	for (int j = low; j <= high; j++){
//	for (int j = low; j <= high-1; j++){
		if (arr[j]==arr[pivot] && pivot==j){
//			flag = true;
//			i++;
			printf("%d is encountered at %d pos.\n",arr[pivot],j);
			continue;
		}
		if (arr[j] < arr[pivot]){
			i++;
			if(i==pivot){
				i++;
			}
			swap(&arr[i], &arr[j]);
			printf("intermediate swapping : %d %d\n",arr[i], arr[j]);
		}
		else{
			printf("swapping ignored of : %d %d\n",arr[pivot], arr[j]);
		}
		printf("i : %d; j : %d\n",i,j);
	}
	printf("swapped elements are %d , %d\n",arr[i],arr[pivot]);
	swap(&arr[i], &arr[pivot]);
//	swap(&arr[i + 1], &arr[high]);
	return (i + 1);
}

int random_partition(int arr[], int low, int high){
	srand(time(NULL));
	int random = low + rand() % (high-low);
//	swap(&arr[random], &arr[high]);
	printf("random element selected at %d is : %d\n",random,arr[random]);
	return partition(arr, low, high, random);
}

void quickSort(int arr[], int low, int high){
	if (low < high){
//		int pi = partition(arr, low, high);
		
		int pi = random_partition(arr,low,high);
		printf("AFTER : ");
		printArray(arr, 10);
		quickSort(arr, low, pi - 1);
		quickSort(arr, pi + 1, high);
	}
}

int main() {
	int lower = 0;
	int upper = 100;
	int count = 10;
//	int arr[count];
	
	clock_t start, end;
	double cpu_time_used;
	
	srand(time(0));
	
//	for (int i = 0; i < count; i++){
//		int num = (rand() % (upper - lower + 1)) + lower;
//		arr[i] = num;
//	}
	printf("INDEX : 0 1 2 3 4 5 6 7 8 9\n");
	int arr[] = {5,4,6,3,7,2,9,8,0,1};
	int n = sizeof(arr)/sizeof(arr[0]);
	
	printf("FIRST : ");
	printArray(arr, n);	//UNSORTED
	//QUICK SORT
	start = clock();
	quickSort(arr, 0, n-1);
	end = clock();
	cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
	printf("\nSorted array in %f seconds with QUICK sort: \n",cpu_time_used);
	printArray(arr, n);	//SORTED
	
	
	return 0;
}