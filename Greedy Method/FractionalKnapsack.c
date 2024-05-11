#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#define MAX 10

int n = 5;
float W = 10.0;
float profit = 0.0;

struct Item
{
    float profit;
    float weight;
    float ratio;
};

struct Item item[MAX] = {
    {10, 3},
    {15, 3},
    {10, 2},
    {20, 5},
    {8, 1}
};



void algorithm ()
{
    for (int i =0; i < n; i++)
    {
        item[i].ratio = item[i].profit/ item[i].weight;
    }

    struct Item temp;
    for(int i=0; i< n-1; i++)
    {
        for (int j=0; j<n-i-1; j++)
        {
            if (item[j].ratio<item[j+1].ratio)
            {
                temp = item[j];
                item[j] = item[j+1];
                item[j+1] = temp;
            }
        }
    }

    int index = 0;
    while (W != 0)
    {
        if (item[index].weight <= W)
        {
            W -= item[index].weight;
            profit += item[index].profit;
        }
        else
        {
            profit += ((W /item[index].weight) * item[index].profit);
            W-=W;
        }
        printf("%f\n", profit);
        index++;
    }
}

void printResult()
{
    printf("%f", profit);
}

int main()
{
    algorithm();
    printResult();
    return 0;
}