#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#define MAX 10

int capacity = 8, n=4;
int profits[MAX] = {1, 2, 5, 6};
int weights[MAX] = {2, 3, 4, 5};

int table[MAX][MAX] = {0};

void algorithm ()
{
    for (int i =1; i <= n; i++)
    {
        for (int j =1; j <= capacity; j++)
        {
            if (j-weights[i-1]>=0)
            {
                table[i][j] = fmax(table[i-1][j], table[i-1][j-weights[i-1]]+profits[i-1]);
            }
            else
            table[i][j] = table[i-1][j];
        }
    }
}

void printMatrix ()
{
    for (int i =0; i <=n; i++)
    {
        for (int j =0; j <=capacity; j++)
        {
            printf ("%d      ", table[i][j]);
        }
        printf ("\n");
    }
}

int main()
{
    algorithm();
    printMatrix();
    return 0;
}