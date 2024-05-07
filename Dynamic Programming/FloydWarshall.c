#include <stdlib.h>
#include <stdio.h>

#define MAX 10

int graph[MAX][MAX] = {
        {0,3,0,7},
        {8,0,2,0},
        {5,0,0,1},
        {2,0,0,0}
    };

int cost[MAX][MAX];

void initialize (int rows, int cols)
{
    for (int i=0; i< rows; i++)
    {
        for (int j=0; j< cols; j++)
        {
            if (i == j)
            cost[i][j] = 0;
            else if (graph[i][j] == 0)
            cost[i][j] = 999;
            else
            cost[i][j] = graph[i][j];
        }
    }
}

void algorithm (int rows, int cols)
{
    for (int i =0; i < rows; i++)
    {
        for (int j =0; j < rows; j++)
        {
            for (int k = 0; k < rows; k++)
            {
                if(cost[j][k] > cost[j][i]+cost[i][k])
                {
                    cost[j][k] = cost[j][i]+cost[i][k];
                }
            }
        }
    }
}

void printMatrix (int rows, int cols)
{
    for (int i =0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            printf("%d ", cost[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    int rows =4, cols =4;
    initialize(4, 4);
    algorithm(4, 4);
    printMatrix(4, 4);
    return 0;
}