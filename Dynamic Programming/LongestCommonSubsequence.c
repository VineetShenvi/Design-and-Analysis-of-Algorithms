#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

#define MAX 20

char string1[MAX] = "PROSPERITY";
char string2[MAX] = "PROPERTIES";

int table[MAX][MAX] = {0};

void algorithm ()
{
    for (int i =1; i <= strlen(string2); i++)
    {
        for (int j =1; j <= strlen(string1); j++)
        {
            if (string2[i-1]==string1[j-1])
            {
                // printf("1");
                table[i][j] = table[i-1][j-1]+1;
            }
            else
            table[i][j] = fmax(table[i-1][j], table[i][j-1]);
        }
    }
}

void printMatrix ()
{
    for (int i =0; i <= strlen(string2); i++)
    {
        for (int j =0; j <=strlen(string1); j++)
        {
            printf ("%d  ", table[i][j]);
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