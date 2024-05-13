//Best Case: O(1) 
//Worst Case: O(log n) 

#include <stdio.h>
#include <stdlib.h>

int binarySearch(int arr[], int low, int high, int x)
{
    if (high >= low) {
        int mid = (low+high) / 2;

        if (arr[mid] == x)
            return mid;

        if (arr[mid] > x)
            return binarySearch(arr, low, mid - 1, x);

        return binarySearch(arr, mid + 1, high, x);
    }

    return -1;
}

int main()
{
    int arr[] = { 2, 3, 4, 10, 40 };
    int x = 10;
    int result = binarySearch(arr, 0, 4, x);
    (result == -1)
        ? printf("Element is not present in array")
        : printf("Element is present at index %d", result);
    return 0;
}