#include <stdio.h>

int main() {
    int n, min = 0, max = 0;

    printf("Enter the size of the array: ");
    scanf("%d", &n);

    // Declare the array after initializing n
    int arr[n];

    printf("Enter the array elements: ");
    for (size_t i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    for (size_t i = 0; i < n; i++) {
        max=min =i;
        if (arr[i] > max) {
            max = arr[i];
        }
        if (arr[i+1] < arr[min]) {
            min = i+1;
        }
    }

    printf("The maximum element is %d and the minimum element is %d\n", max, arr[min]);

    return 0;
}