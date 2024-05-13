#include <stdlib.h>
#include <stdio.h>

#define MAX 10
#define INF 9999

int dist[MAX];
int visited[MAX] = {0};
int parents[MAX];
int answer = 0;

int graph[MAX][MAX] = { 
    { 0, 2, 0, 6, 0 },
    { 2, 0, 3, 8, 5 },
    { 0, 3, 0, 0, 7 },
    { 6, 8, 0, 0, 9 },
    { 0, 5, 7, 9, 0 } 
};

int minDist(int nodes, int selected)
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

void initialize (int nodes)
{
    for (int i=0; i< nodes; i++)
    {
        if (i == 0)
        dist[i] = 0;
        else
        dist[i] = INF;
    }
}

int isComplete(int nodes)
{
    for (int i=0; i<nodes; i++)
    {
        if (visited[i] == 0)
        return 0;
    }
    return 1;
}

int findParent (int nodes, int child)
{
    if (child == 0)
    return -1;
    for (int i=0; i< nodes; i++)
    {
        if (graph[child][i] == dist[child])
        return i;
    }
}

void printMatrix (int nodes)
{
    printf("%d\n", answer);
    for (int i=0; i<nodes; i++)
    {
        printf("%d %d %d \n", parents[i], i, dist[i]);
    }
}

void algorithm (int nodes)
{
    int selected;
    while (!isComplete(nodes))
    {
        selected = minDist(nodes, selected);
        answer += dist[selected];
        visited[selected] =  1;
        int parent = findParent(nodes, selected);
        parents[selected] = parent;
        for (int j =0; j < nodes; j++)
        {
            if (graph[selected][j] && !visited[j])
            {
                if(dist[j] > graph[selected][j])
                {
                    dist[j] = graph[selected][j];
                }
            }
            
        }
        
    }
}

int main()
{
    int rows =4, cols =4;
    initialize(5);
    algorithm(5);
    printMatrix(5);
    return 0;
}