#include<iostream>
using namespace std;

class SelectionSort {
    private:
        int* arr;
        int size;
    public: 
        SelectionSort(int* array, int n) {
            arr = array;
            size = n;
        }

        void sort() {
            for (int i = 0; i < size - 1; i++) {
                int minIndex = i;
                for (int j = i + 1; j < size; j++) {
                    if (arr[j] < arr[minIndex]) {
                        minIndex = j;
                    }
                }
                swap(arr[i], arr[minIndex]);
            }
        }

        void display() {
            for (int i = 0; i < size; i++) {
                cout << arr[i] << " ";
            }
            cout << endl;
        }

        void swap(int &a, int &b) {
            int temp = a;
            a = b;
            b = temp;
        }
};

int main() {
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int n = sizeof(arr) / sizeof(arr[0]);
    SelectionSort ob = SelectionSort(arr, n);
    cout << "Unsorted array: ";
    ob.display();
    cout << "Sorted array: ";
    ob.sort();
    ob.display();
}