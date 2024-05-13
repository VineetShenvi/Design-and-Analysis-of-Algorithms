#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int answer[16];

bool isSafe(int queen ,int col)
{
    for (int j=1; j<=queen-1; j++)
    {
        if(answer[j]==col || abs(answer[j]-col)==abs(j-queen))
        return false;
    }
    return true;
}

void printBoard(int n)
{
    for (int i=1; i<=n; i++)
    {
        for (int j=1; j<=n; j++)
        {
            if (answer[i]==j)
            printf("Q ");
            else
            printf("- ");
        }
        printf("\n");
    }
    printf("\n\n");
}

void NQueen(int queen, int n)
{
    for(int cols=1; cols<=n; cols++)
    {
        if(isSafe(queen, cols))
        {
            answer[queen]=cols;
            if(queen==n)
            printBoard(n);
            else
            NQueen(queen+1,n);
        }
    }
}

int main(){
    NQueen(1,8);
}