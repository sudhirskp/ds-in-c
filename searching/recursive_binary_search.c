#include <stdio.h>
#include <string.h>

int binarySearch(int arr[], int low, int high, int key) {
    if (high >= low) {
        int mid = low + (high - low) / 2;
        if (arr[mid] == key){
            return mid;
        }
        if (arr[mid] > key){
            return binarySearch(arr, low, mid - 1, key);
        }
        else{
            return binarySearch(arr, mid + 1, high, key);
    }
    return -1;
}
}

int main(void) {
    int arr[] = {2, 99, 88, 10, 40};
    int n = sizeof(arr) / sizeof(arr[0]);
    int key = 88;
    int result = binarySearch(arr, 0, n - 1, key);
    if (result == -1) {
        printf("Element is not present in array");
    } else {
        printf("%d Element is present at index %d", key, result);
    }
    return 0;
}
