#include <iostream>
using namespace std;

class MinHeap {
    int* arr;
    int capacity;
    int index;

public:
    MinHeap(int cap = 5) {
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
        while (current > 0 && arr[current] < arr[parent(current)]) {
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
        int smallest = i;
        while (true) {
            int left = leftChild(i);
            int right = rightChild(i);

            if (left < index && arr[left] < arr[smallest])
                smallest = left;
            if (right < index && arr[right] < arr[smallest])
                smallest = right;

            if (smallest != i) {
                swap(arr[i], arr[smallest]);
                i = smallest;
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
        cout << "Min Heap: ";
        for (int i = 0; i < index; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    ~MinHeap() {
        delete[] arr;
    }
};

int main(){
    MinHeap minH(5);
    minH.insert(20);
    minH.insert(40);
    minH.insert(10);
    minH.insert(5);
    minH.printHeap();
    minH.deleteTop();
    minH.printHeap();
}
