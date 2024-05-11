#include <stdlib.h>
#include <stdio.h>

#define MAX 10
#define INF 9999

int dist[MAX];

int graph[MAX][MAX] = {
        {0, 6, 5, 5, 0, 0, 0},
        {0, 0, 0, 0, -1, 0, 0},
        {0, -2, 0, 0, 1, 0, 0},
        {0, 0, -2, 0, 0, -1, 0},
        {0, 0, 0, 0, 0, 0, 3},
        {0, 0, 0, 0, 0, 0, 3},
        {0, 0, 0, 0, 0, 0, 0}
    };

void initialize (int nodes, int source)
{
    for (int i=0; i< nodes; i++)
    {
        if (i == source)
        dist[i] = 0;
        else
        dist[i] = INF;
    }
}

void algorithm (int nodes)
{
    for (int i =0; i < nodes-1; i++)
    {
        for (int j =0; j < nodes; j++)
        {
            for (int k = 0; k < nodes; k++)
            {
                if (graph[j][k])
                {
                    if(graph[j][k] < dist[k]-dist[j])
                    {
                        dist[k] = graph[j][k]+dist[j];
                    }
                }
            }
        }
    }
}

void printMatrix (int nodes)
{
    for (int i =0; i < nodes; i++)
    {
        printf("%d ", dist[i]);
    }
}

int main()
{
    int rows =4, cols =4;
    initialize(7, 0);
    algorithm(7);
    printMatrix(7);
    return 0;
}