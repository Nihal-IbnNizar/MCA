#include <stdio.h>

int binarySearch(int arr[], int low, int high, int key) {
    while (low <= high) {
        int mid = low + (high - low) / 2;
        
        if (arr[mid] == key) {
            return mid; // Element found, return its index
        } else if (arr[mid] < key) {
            low = mid + 1; // Discard the left half
        } else {
            high = mid - 1; // Discard the right half
        }
    }
    
    return -1; // Element not found
}

int main() {
    int arr[] = {12, 34, 45, 67, 89, 123, 456};
    int n = sizeof(arr) / sizeof(arr[0]);
    int key = 67;

    int result = binarySearch(arr, 0, n - 1, key);
    if (result != -1) {
        printf("Element found at index %d\n", result);
    } else {
        printf("Element not found\n");
    }

    return 0;
}
