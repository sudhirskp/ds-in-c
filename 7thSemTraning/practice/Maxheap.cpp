#include <iostream>
using namespace std;

class MaxHeap {
    int* arr;
    int capacity;
    int index;

public:
    MaxHeap(int cap = 5) {
        capacity = cap;
        index = 0;
        arr = new int[capacity];
    }

    int parent(int i) { return (i - 1) / 2; }
    int leftChild(int i) { return 2 * i + 1; }
    int rightChild(int i) { return 2 * i + 2; }

    void insert(int num) {
        if (index >= capacity) {
            cout << "Heap is full!" << endl;
            return;
        }

        arr[index] = num;
        cout << "Inserted " << num << " at index " << index << endl;

        int current = index;
        while (current > 0 && arr[current] > arr[parent(current)]) {
            swap(arr[current], arr[parent(current)]);
            current = parent(current);
        }
        index++;
    }

    void deleteTop() {
        if (index == 0) {
            cout << "Heap is empty!" << endl;
            return;
        }

        cout << "Deleting top element: " << arr[0] << endl;
        swap(arr[0], arr[index - 1]);
        index--;
        heapify(0);
    }

    void heapify(int i) {
        int largest = i;
        while (true) {
            int left = leftChild(i);
            int right = rightChild(i);

            if (left < index && arr[left] > arr[largest])
                largest = left;
            if (right < index && arr[right] > arr[largest])
                largest = right;

            if (largest != i) {
                swap(arr[i], arr[largest]);
                i = largest;
            } else {
                break;
            }
        }
    }

    int top() {
        if (index == 0) {
            cout << "Heap is empty!" << endl;
            return -1;
        }
        return arr[0];
    }

    void printHeap() {
        cout << "Max Heap: ";
        for (int i = 0; i < index; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    ~MaxHeap() {
        delete[] arr;
    }
};

int main(){
    MaxHeap h(4);
    h.insert(45);
    h.printHeap();

    h.insert(66);
    h.printHeap();

    h.insert(42);
    h.printHeap();

    h.insert(32);
    h.printHeap();

    h.insert(43);
    h.printHeap();
    h.deleteTop();
    h.printHeap();
}
