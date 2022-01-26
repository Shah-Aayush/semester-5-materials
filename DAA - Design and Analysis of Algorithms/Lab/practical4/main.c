/*
Aayush Shah
19BCE245
DAA Practical 4
*/

#include <stdio.h>
#include <limits.h>
#include <time.h>
#include <stdlib.h>

/*
	Returns maximum of two integers
*/
int max2(int a, int b){
	return (a>b) ? a : b; 
}

/*
	Returns maximum of three integers
*/
int max3(int a, int b, int c){
	return max2(max2(a,b),c); 
}

/*
	Prints subarray
*/
void printSubArray(int arr[], int startIndex, int endIndex){
	printf("\nSub Array : ");
	for(int i=startIndex;i<=endIndex;i++){
		printf("%d ",arr[i]);
	}
}

/* ------------------------------ */

/*
	Kadane's algorithm
	Solves the maximum subarray sum in O(N) time. 
*/
int maxSubArraySum1(int arr[], int size)
{
	int maxTillHere = 0, maxBest = arr[0], counter = 0, startIndex = 0, finalStartIndex = 0;
	int subArray[size];
	int maxCounter = 0;
	
	for(int i=0;i<size;i++){
		if(maxTillHere+arr[i]<arr[i]){
			maxTillHere = arr[i];
			counter = 0;
			startIndex = i;
		}
		else{
			maxTillHere += arr[i];
			counter++;
		}
		if(maxTillHere>maxBest){
			maxBest = maxTillHere;
			maxCounter = counter;
			finalStartIndex = startIndex;
		}
	}
	
	printSubArray(arr, finalStartIndex, finalStartIndex+maxCounter-1);
	
//	printf("\nSubarray : ");
//	for(int i=finalStartIndex;i<finalStartIndex+counter;i++){
//		printf("%d ",arr[i]);
//	}
	
	return maxBest;
}

/* ------------------------------ */

/*
	Brute force
	Solves the maximum subarray sum in O(N^2) time. 
*/
int maxSubArraySum2(int arr[], int size){
	int startIndex = 0;
	int endIndex = 0;
	
	int max = -1e9;
	for(int i = 0; i < size; i++) {
		int sum = 0;
		for (int j = i; j < size; j++) {
			sum += arr[j];
			if (sum > max){
				max = sum;
				startIndex = i;
				endIndex = j;
			}
		}
	}
	
	printSubArray(arr, startIndex, endIndex);
	
//	printf("\nSubarray : ");
//	for(int i=startIndex;i<=endIndex;i++){
//		printf("%d ",arr[i]);
//	}
	return max;
}

/* ------------------------------ */

/*
	Brute force (another approach)
	Sovles the maximum subarray sum in O(N^3) time.
*/
int maxSubArraySum3(int arr[], int size){
	int max = -1e9;
	int startIndex = 0, endIndex = 0;
	
	for (int i = 0; i < size; i++)
		for (int j = i; j < size; j++) {
			int sum = 0;
			for (int k = i; k <= j; k++)
				sum += arr[k];
			if (sum > max){
				max = sum;
				startIndex = i;
				endIndex = j;
			}
		}
	
	printSubArray(arr, startIndex, endIndex);
	
	return max;
}

/* ------------------------------ */

/*
	Divide and Conquer
	Solves the maximum subarray sum in O(N log(N)) time.
*/
int startIndex = 0;
int endIndex = 0;
int globalMax = 0;

int maxSumIncludingMid(int arr[], int l, int m, int h){
	int leftStart = m;
	int rightEnd = m+1;
	int sum = 0;
	int left_sum = INT_MIN;
	for(int i=m; i>=l; i--){
		sum += arr[i];
		if (sum>left_sum){
			left_sum = sum;
			leftStart = i;
		}
	}
	
	sum = 0;
	int right_sum = INT_MIN;
	for(int i=m+1; i<=h; i++){
		sum += arr[i];
		if (sum>right_sum){
			right_sum = sum;
			rightEnd = i;
		}
	}
	
	int maxCrossingSum = max3(left_sum+right_sum, left_sum, right_sum);
	
	if(maxCrossingSum == left_sum + right_sum && maxCrossingSum>globalMax){
		startIndex = leftStart;
		endIndex = rightEnd;
		globalMax = maxCrossingSum;
	}
	else if(maxCrossingSum == left_sum  && maxCrossingSum>globalMax){
		startIndex = leftStart;
		endIndex = m;
		globalMax = maxCrossingSum;
	}
	else if(maxCrossingSum == rightEnd  && maxCrossingSum>globalMax){
		startIndex = m+1;
		endIndex = rightEnd;
		globalMax = maxCrossingSum;
	}
	
	return maxCrossingSum;
}

int divideAndConquer(int arr[], int l, int h){
	if (l==h)
		return arr[l];
	
	int m = (l+h)/2;
	return max3(divideAndConquer(arr, l, m), divideAndConquer(arr, m+1, h), maxSumIncludingMid(arr, l, m, h));
}

int maxSubArraySum4(int arr[], int size){
	int l = 0;
	int h = size - 1;
	return divideAndConquer(arr, l, h);
}

/* ------------------------------ */

int main() {
	
	int lower = -100000;
	int upper = 100000;
	int count = 100;
	
	srand(time(0));

	int a[count];
	for (int i=0; i<count; i++) {
		a[i] = (rand() % (upper - lower + 1)) + lower;
	}
	
//	int a[] = {-5, 4,  6, -3, 4, -1};	//11
//	int a[] = {-2, -3,  4, -1, -2,  1,  5, -3};	//7
//	int a[] = {-2, -3, -4, -1, -2, -1, -5,  3};	//3
//	int a[] = {-2, -3, -4, -1, -2, -1, -5, -3};	//-1
//	int a[] = {-2, -3,  4, -1, -2, -1, -5, -3};	//4
	
	printf("Given array : ");
	printSubArray(a, 0, count);
	printf("\n");
	
	clock_t start, end;
	double cpu_time_used;
	
	
	int n = sizeof(a)/sizeof(a[0]);
	
	start = clock();
	printf("\nMaximum contiguous sum from method 1 is %d", maxSubArraySum1(a, n));
	end = clock();
	cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
	printf("\tTime taken : %f seconds\n", cpu_time_used);
	start = clock();
	
	printf("\nMaximum contiguous sum from method 2 is %d", maxSubArraySum2(a, n));
	end = clock();
	cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
	printf("\tTime taken : %f seconds\n", cpu_time_used);
	start = clock();
	
	printf("\nMaximum contiguous sum from method 3 is %d", maxSubArraySum3(a, n));
	end = clock();
	cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
	printf("\tTime taken : %f seconds\n", cpu_time_used);
	start = clock();
	
	printf("\nMaximum contiguous sum from method 4 is %d", maxSubArraySum4(a, n));
	end = clock();
	cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
	printSubArray(a, startIndex, endIndex);
	printf("\tTime taken : %f seconds\n", cpu_time_used);
	
	
	
	return 0;
}