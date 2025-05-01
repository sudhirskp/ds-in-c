#include<iostream>
using namespace std;

class BinarySearch {
private:
    int* arr;
    int size;

public:
    BinarySearch(int* array, int n) {
        arr = array;
        size = n;
    }

    void search(int key) {
        int low = 0, high = size - 1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (arr[mid] == key) {
                cout << "Element found at index " << mid << endl;
                return;
            }
            if (arr[mid] < key) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        cout << "Element not found" << endl;
    }

  
};

int main() {
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int n = sizeof(arr) / sizeof(arr[0]);
    int key = 8;

    BinarySearch bs(arr, n);
    bs.search(key);  

    return 0;
}