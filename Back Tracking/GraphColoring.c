#include <stdbool.h>
#include <stdio.h>

#define MAX 10

int color[MAX]={0};

int graph[MAX][MAX] = {
		{ 0, 1, 1, 1 },
		{ 1, 0, 1, 0 },
		{ 1, 1, 0, 1 },
		{ 1, 0, 1, 0 },
};

void printSolution(int nodes)
{
	printf("Following are the assigned colors: \n");
	for (int i = 0; i < nodes; i++)
		printf(" %d ", color[i]);
	printf("\n");
}

int isSafe(int v, int nodes, int c)
{
	for (int i = 0; i < nodes; i++)
		if (graph[v][i] && c == color[i])
			return 0;
	return 1;
}


int graphColoringUtil(int nodes, int m, int v)
{
	if (v == nodes)
		return 1;

	for (int c = 1; c <= m; c++) 
    {
		if (isSafe(v, nodes, c)) 
        {
			color[v] = c;

			if (graphColoringUtil(nodes, m, v + 1))
				return 1;

			color[v] = 0;
		}
	}

	return 0;
}

int graphColoring(int m, int nodes)
{
	if (!graphColoringUtil(nodes, m, 0)) {
		printf("Solution does not exist");
		return 0;
	}

    printSolution(nodes);
	return 1;
}


int main()
{
	int nodes = 4;
    int m = 3; // Number of colors

	graphColoring(m, nodes);
	return 0;
}
