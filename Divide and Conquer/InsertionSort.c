//Best Case: O(n) Already Sorted
//Worst Case: O(n^2) Reverse Sorted

#include <stdio.h>
#include <stdlib.h>

void sort(int arr[], int n)
{
    int i, key, j;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}


int main()
{
    int arr[10] = {34,64,234,545,4523,356,3654,3343,4665,34231};
    sort(arr, 10);
    for (int i=0; i<10; i++)
    printf("%d ", arr[i]);
}