#include<iostream>
using namespace std;



class BubbleSort{
    private:
        int* arr;
        int size;
    public: 
    BubbleSort(int* array, int n) {
            arr = array;
            size = n;
        }

    void sort() {
        for (int i = 0; i < size - 1; i++) {
            for (int j = 0; j < size - i - 1; j++) {
                if (arr[j] > arr[j + 1]) {
                    swap(arr[j], arr[j + 1]);
                }
            }
        }
    }

        void display() {
            for (int i = 0; i < size; i++) {
                cout << arr[i] << " ";
            }
            cout << endl;
        }

    void swap(int &a, int &b){
        int temp = a;
        a = b;
        b = temp;
    }
};

int main (){
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int n = sizeof(arr)/sizeof(arr[0]);
    BubbleSort ob = BubbleSort(arr, n);
    cout << "Unsorted array: ";
    ob.display();
    cout<< "Sorted array: ";
    ob.sort();
    ob.display();
}