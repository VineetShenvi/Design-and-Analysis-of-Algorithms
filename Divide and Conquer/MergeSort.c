//Best Case: O(n log n)
//Worst Case: O(n log n)

#include <stdio.h>
#include <stdlib.h>

void merge(int arr[], int start, int mid, int end)
{
    int i=start, j=mid+1;
    int b[100];
    int k=start;
    while (i<=mid && j<=end)
    {
        if (arr[i]<arr[j])
        b[k++] = arr[i++];
        else
        b[k++] = arr[j++]; 
    }
    if (i>mid)
    {
        while(j<=end)
        b[k++] = arr[j++];
    }
    if (j>end)
    {
        while(i<=mid)
        b[k++] = arr[i++];
    }
    for (int i=start; i<=end; i++)
    arr[i] = b[i];
}

void sort(int arr[], int start, int end)
{
    if (start < end)
    {
        int mid = (start+end)/2;
        sort(arr, start, mid);
        sort(arr, mid+1, end);
        merge(arr, start, mid, end);
    }
}

int main()
{
    int arr[10] = {34,64,234,545,4523,356,3654,3343,4665,34231};
    sort(arr, 0, 9);
    for (int i=0; i<10; i++)
    printf("%d ", arr[i]);
}