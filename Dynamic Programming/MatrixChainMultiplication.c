#include <limits.h>
#include <stdio.h>
 
 #define MAX 10

int cost[MAX][MAX] = {0};
int d[MAX] = {3, 2, 4, 2, 5};

void MatrixChainOrder(int n)
{
    for (int gap=1; gap<n-1; gap++) 
    {
        for (int i = 1; i<n-gap; i++) 
        {
            int j = i+gap;
            int minCost = 999999;
            int c;
            for (int k=i; k<j; k++)
            {
                c = cost[i][k] + cost[k+1][j] + d[i-1]*d[j]*d[k];
                if (c < minCost)
                minCost = c;
            }
            cost[i][j] = minCost;
        }
    }
}

void printMatrix (int n)
{
    for (int i =1; i < n; i++)
    {
        for (int j = 1; j < n; j++)
        {
            printf("%d ", cost[i][j]);
        }
        printf("\n");
    }
}
 
int main()
{
    int n=5;
    MatrixChainOrder(n);
    printMatrix(n);
    return 0;
}