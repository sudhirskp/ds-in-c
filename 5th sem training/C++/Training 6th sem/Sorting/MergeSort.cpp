#include<iostream>
using namespace std;

class MergeSort {
    int* ARRAY;
    int SIZE;

public:
    MergeSort(int size) {
        this->SIZE = size;
        ARRAY = new int[SIZE];
    }

    ~MergeSort() {
        delete[] ARRAY;
    }

    void insertData() {
        int data;
        cout << "DATA: ";
        for (int i = 0; i < SIZE; i++) {
            cin >> data;
            ARRAY[i] = data;
        }
    }

    void showData() {
        cout << "DATA: ";
        for (int i = 0; i < SIZE; i++) {
            cout << ARRAY[i] << " ";
        }
        cout << endl;
    }

    // Merge Sort call
    void sort() {
        mergeSort(0, SIZE - 1);
    }

    // Merge Sort logic
    void mergeSort(int left, int right) {
        if (left < right) {
            int mid = left + (right - left) / 2;

            mergeSort(left, mid);
            mergeSort(mid + 1, right);

            merge(left, mid, right);
        }
    }

    // Merge function
    void merge(int left, int mid, int right) {
        int n1 = mid - left + 1;
        int n2 = right - mid;

        int* L = new int[n1];
        int* R = new int[n2];

        for (int i = 0; i < n1; i++)
            L[i] = ARRAY[left + i];
        for (int j = 0; j < n2; j++)
            R[j] = ARRAY[mid + 1 + j];

        int i = 0, j = 0, k = left;

        while (i < n1 && j < n2) {
            if (L[i] <= R[j]) {
                ARRAY[k] = L[i];
                i++;
            } else {
                ARRAY[k] = R[j];
                j++;
            }
            k++;
        }

        while (i < n1) {
            ARRAY[k] = L[i];
            i++;
            k++;
        }

        while (j < n2) {
            ARRAY[k] = R[j];
            j++;
            k++;
        }

        delete[] L;
        delete[] R;
    }
};

// DRIVER CODE
int main() {
    int size;

    cout << "ARRAY SIZE: ";
    cin >> size;

    MergeSort obj(size);

    obj.insertData();
    obj.showData();

    obj.sort();

    obj.showData();

    return 0;
}