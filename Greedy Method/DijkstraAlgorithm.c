#include <stdlib.h>
#include <stdio.h>

#define MAX 10
#define INF 9999

int dist[MAX];
int visited[MAX];

int graph[MAX][MAX] = {
        {0, 2, 4, 0, 0, 0},
        {0, 0, 1, 7, 0, 0},
        {0, 0, 0, 0, 3, 0},
        {0, 0, 0, 0, 0, 1},
        {0, 0, 0, 2, 0, 5},
        {0, 0, 0, 0, 0, 0}
    };

int minDist(int nodes)
{
    int minDist = INF + 1;
    int minIndex = 99;
    for (int i =0; i<nodes; i++)
    {
        if (!visited[i] && dist[i]<minDist)
        {
            minDist = dist[i];
            minIndex = i;
        }
    }
    return minIndex;
}

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

void printMatrix (int nodes)
{
    for (int i =0; i < nodes; i++)
    {
        printf("%d ", dist[i]);
    }
}

void algorithm (int nodes)
{
    for (int i =0; i < nodes; i++)
    {
        int index = minDist(nodes);
        for (int j =0; j < nodes; j++)
        {
            if (graph[index][j])
            {
                if(dist[index] + graph[index][j] < dist[j])
                {
                    dist[j] = graph[index][j]+dist[index];
                }
            }
            
        }
        visited[index] = 1;
    }
}

int main()
{
    int rows =4, cols =4;
    initialize(6, 0);
    algorithm(6);
    printMatrix(6);
    return 0;
}