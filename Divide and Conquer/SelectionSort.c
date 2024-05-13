//Best Case: O(n^2) 
//Worst Case: O(n^2) 

#include <stdio.h>
#include <stdlib.h>

void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void sort(int arr[], int n)
{
    int i, j, min_idx;

    for (i = 0; i < n-1; i++)
    {
        min_idx = i;
        for (j = i+1; j < n; j++)
          if (arr[j] < arr[min_idx])
            min_idx = j;

        if(min_idx != i)
        swap(&arr[min_idx], &arr[i]);
    }
}

int main()
{
    int arr[10] = {34,64,234,545,4523,356,3654,3343,4665,34231};
    sort(arr, 10);
    for (int i=0; i<10; i++)
    printf("%d ", arr[i]);
}