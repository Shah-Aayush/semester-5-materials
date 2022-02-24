

#include <limits.h>
#include <stdio.h>

//Matrix Chain
char name = 'A';
void printParenthesis(int i, int j, int n, int s[n][n])
{
	if (i == j) {
		printf("%c",name++);
		return;
	}

	printf("(");

	printParenthesis(i, s[i][j], n,s);
	printParenthesis(s[i][j] + 1 , j, n,s);

	printf(")");
}

void matrixChainOrder(int p[], int n)
{

	int m[n][n];


	int s[n][n];


	for (int i = 0; i < n; i++){
		for (int j = 0; j < n; j++){
			m[i][j] = 0;
			s[i][j] = 0;
		}
	}



	for (int d = 1; d < n-1; d++)
	{
		for (int i = 1; i < n - d; i++)
		{
			int j = i + d;
			m[i][j] = INT_MAX;
			for (int k = i; k <= j - 1; k++)
			{
				int q = m[i][k] + m[k + 1][j]+ p[i - 1] * p[k] * p[j];
				if (q < m[i][j])
				{
					m[i][j] = q;

					s[i][j] = k;
//					printf("s[%d][%d] : %d\n",i,j,k);
				}
			}

		}
	}


	printf("Optimal Parenthesization is : ");
	printParenthesis(1, n - 1, n, s);
	printf("\nOptimal Cost is : %d",m[1][n - 1]);
}


int main()
{
    int n,i;
	printf("Enter Length of sequence : ");
	scanf("%d",&n);
	int arr[n];
	printf("Enter sequence : ");
	for(i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
	matrixChainOrder(arr, n);

	getchar();
	return 0;
}

//2 3 5 2 4 3