#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#define MAX 10

int n = 6;
int k = 0;

struct Activity
{
    int start;
    int finish;
};

struct Activity activities[MAX] = {
    {1, 2},
    {3, 4},
    {0, 6},
    {5, 7},
    {8, 9},
    {5, 9}
};

struct Activity solution[MAX];

void algorithm ()
{
    struct Activity temp;
    for(int i=0; i< n-1; i++)
    {
        for (int j=0; j<n-i-1; j++)
        {
            if (activities[j].finish > activities[j+1].finish)
            {
                temp = activities[j];
                activities[j] = activities[j+1];
                activities[j+1] = temp;
            }
        }
    }

    int finish = 0;
    for (int i = 0; i < n; i++)
    {
        if (activities[i].start >= finish)
        {
            finish = activities[i].finish;
            solution[k++] = activities[i];
        }
    }
}

void printResult()
{
    for (int i = 0; i < k; i++)
    {
        printf("%d %d \n", solution[i].start, solution[i].finish);
    }
    
}

int main()
{
    algorithm();
    printResult();
    return 0;
}