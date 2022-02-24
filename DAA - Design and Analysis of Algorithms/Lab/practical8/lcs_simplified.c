#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#define MAX(a,b) ((a>b)?a:b)

int lcs(char *X, char *Y, int m, int n){
	int dp[m+1][n+1];
	int i,j;
	for (i=0; i<=m; i++) {
		for (j=0; j<=n; j++) {
			if (i==0||j==0) {
				dp[i][j] = 0;
			}
			else if(X[i-1]==Y[j-1]){
				dp[i][j] = 1+dp[i-1][j-1];
			}
			else{
				dp[i][j] = MAX(dp[i-1][j], dp[i][j-1]);
			}
		}
	}
	
	int index = dp[m][n];
	char lcs[index+1];
	lcs[index] = '\0';
	
	int row = m, col = n;
	
	while(row>0 && col>0){
		if (X[row-1] == Y[col-1]) {
			lcs[index-1]=X[row-1];
			row--,col--,index--;
		}
		else if(dp[row-1][col]>dp[row][col]){
			row--;
		}
		else{
			col--;
		}
	}
	printf("\t> Longest Common Subsequence : %s.\n",lcs);
	
	for (int i=0; i<=m; i++) {
		for (int j=0; j<=n; j++) {
			printf("%3d ",dp[i][j]);
		}
		printf("\n");
	}
	printf("\n");
	return dp[m][n];
}

int main(){
	char str1[100]="AGGTAB", str2[100]="GXTXAYB";
	int m=strlen(str1),n=strlen(str2);
	printf("\t> Length of LCS is %d.", lcs( str1, str2, m, n ) );
	return 0;
}