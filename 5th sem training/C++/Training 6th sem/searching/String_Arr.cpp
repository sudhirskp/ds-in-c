#include<iostream>
#include<vector>
using namespace std;

class LinearSearch {
private:
    vector<string> arr;
    int position;

public:
    LinearSearch(int* array, int n) {
        arr = array;
        size = n;
    }

    void search(int key) {
        for (int i = 0; i < size; i++) {
            if (arr[i] == key) {
                cout << "Element found at index " << i << endl;
                return;
            }
        }
        cout << "Element not found" << endl;
    }

    void display() {
        cout << "Array elements: ";
        for (int i = 0; i < size; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int n = sizeof(arr) / sizeof(arr[0]);
    int key = 8;

    LinearSearch ls(arr, n);
    ls.search(key);
    ls.display();   

    return 0;
}