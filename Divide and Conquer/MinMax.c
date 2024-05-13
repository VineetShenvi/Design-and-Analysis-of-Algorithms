//Best Case: O(n log n)
//Worst Case: O(n^2) 

#include <stdio.h>
#include <stdlib.h>

void MaxMin(int A[], int i, int j, int *max, int *min) {
    int max1, min1, max2, min2, mid;
    if (i == j) 
    {
        *max = *min = A[i];
    } 
    else if (i == j - 1) 
    {
        if (A[i] < A[j]) 
        {
            *min = A[i];
            *max = A[j];
        } 
        else 
        {
            *min = A[j];
            *max = A[i];
        }
    } 
    else 
    {
        mid = (i + j) / 2;
        MaxMin(A, i, mid, &max1, &min1);
        MaxMin(A, mid + 1, j, &max2, &min2);
        *max = (max1 > max2) ? max1 : max2;
        *min = (min1 < min2) ? min1 : min2;
    }
}



int main()
{
    int max, min;
    int arr[10] = {34,64,234,545,4523,3568676,3654,3343,4665,34231};
    MaxMin(arr, 0, 9, &max, &min);
    printf("Maximum element: %d\n", max);
    printf("Minimum element: %d\n", min);
}
   