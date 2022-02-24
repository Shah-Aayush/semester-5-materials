#include <stdio.h>
#include <stdbool.h>
#define max(a,b) ((a>b)?a:b)

int knapsack(int N, int W, int val[], int wt[]){
	int dp[N+1][W+1];
	int n,w;
	for (n=0; n<=N; n++) {
		for (w=0; w<=W; w++) {
			if (n==0 || w==0) {
				dp[n][w]=0;
			}
			else if(wt[n-1]<=w){
				dp[n][w] = max(dp[n-1][w], dp[n-1][w-wt[n-1]] + val[n-1]);
			}
			else{
				dp[n][w] = dp[n-1][w];
			}
		}
	}
	
	int max_loot = dp[N][W];
	int remaining = max_loot;
	w = W;
	n = N;
	bool flag = false;
	printf("Selected weights : ");
	while(n>0 && remaining>0){
		if (remaining==dp[n-1][w]) {
			
		}
		else{
			if (flag){
				printf(", %d",wt[n-1]);
			}
			else{
				flag = true;
				printf("%d", wt[n-1]);
			}
			w-=wt[n-1];
			remaining-=val[n-1];
		}
		n--;
	}
	printf("\n");
	
	
	return max_loot;
}

int main(){
	int val[] = {60,100,120}; //values
	int wt[] = {10, 20, 30 }; //weights
	int N = sizeof(val)/sizeof(val[0]);
	int W = 50; 	// 10,20,30
//	int N = 4;       // n : number of objects
//	int W = 8;       // w : maximum weight capacity
//	int wt[] = {2, 3, 4, 5};
//	int val[]   = {1, 2, 5, 6};
	printf("%d", knapsack(N,W,val,wt));
}