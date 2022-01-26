// CPP code for Dynamic Programming based
// solution for 0-1 Knapsack problem
#include <stdio.h>

// A utility function that returns maximum of two integers
int max(int a, int b) { return (a > b) ? a : b; }

// Prints the items which are put in a knapsack of capacity W
void printknapSack(int W, int wt[], int val[], int n)
{
	int i, w;
	int K[n + 1][W + 1];

	// Build table K[][] in bottom up manner
	for (i = 0; i <= n; i++) {
		for (w = 0; w <= W; w++) {
			if (i == 0 || w == 0)
				K[i][w] = 0;
			else if (wt[i - 1] <= w)
				K[i][w] = max(val[i - 1] +
					K[i - 1][w - wt[i - 1]], K[i - 1][w]);
			else
				K[i][w] = K[i - 1][w];
		}
	}

	// stores the result of Knapsack
	int res = K[n][W];
	printf("%d\n", res);
	printf("DEBUG : \n");
	w = W;
	for (i = n; i > 0 && res > 0; i--) {
		
		// either the result comes from the top
		// (K[i-1][w]) or from (val[i-1] + K[i-1]
		// [w-wt[i-1]]) as in Knapsack table. If
		// it comes from the latter one/ it means
		// the item is included.
		printf("\ti:%d\t|\tres:%d\t|\tw%d\t|\tupper_value:%d",i,res,w,K[i - 1][w]);
		if (res == K[i - 1][w]){
            printf("\t || if taken.\n");
            continue;
        }
		else {
			printf("\t || else taken.\n");
			// This item is included.
			printf("%d ", wt[i - 1]);
			
			// Since this weight is included its
			// value is deducted
			res = res - val[i - 1];
			w = w - wt[i - 1];
		}
	}
}

// Driver code
int main()
{
	int val[] = { 1, 2, 5, 6 };
	int wt[] = {2, 3, 4, 5};
	int W = 8;
	int n = sizeof(val) / sizeof(val[0]);
	
	printknapSack(W, wt, val, n);
	
	return 0;
}
