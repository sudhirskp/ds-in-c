// #include<iostream>
// #include<vector>
// #include<queue>
// using namespace std;
// class Heap{
//     int *arr; // pointer to array of elements in heap
//     int capacity;
//     int index; // current number of elements in heap - working size

//     public:
//     Heap(int cap=5){
//         capacity= cap;
//         index = 0;
//         arr = new int[capacity]();
//        if (!arr) {
//             cerr<< "Memory allocation failed" << endl;
//             exit(1);
//         }
//     }

//     int parent(int i) {
//         return (i - 1) / 2;
//     }


//     int leftChild(int i) {
//         return 2 * i + 1;
//     }

//     int rightChild(int i) {
//         return 2 * i + 2;
//     }

//     void insertForMinHeap (int num){
//         if (index >= capacity) {
//             cout << "Heap is full!" << endl;
//             return;
//         }
//         arr[index] = num;
//         cout << "Inserted " << num << " into heap. at index " << index << "." << endl;

//         cout<< "Repositioning heap: ";

//         int current = index;
//         while (current>0) {
//           if(arr[current] < arr[parent(current)]) {
//             // Swap with parent if current is greater
//             swap(arr[current], arr[parent(current)]);
//             current = parent(current);
//           } else {
//             break; // If current is not greater than parent, stop
//           }
//         }
//         index++;
//     }

//     void insertForMaxHeap(int num) {
//         if (index >= capacity) {
//             cout << "Heap is full!" << endl;
//             return;
//         }
//         arr[index] = num;
//         cout << "Inserted " << num << " into heap. at index " << index << "." << endl;

//         cout<< "Repositioning heap: ";
//         //current index i 
//         int current = index;
//         while (current > 0) {
//             if (arr[current] > arr[parent(current)]) {
//                 // Swap with parent if current is greater
//                 swap(arr[current], arr[parent(current)]);
//                 current = parent(current);
//             } else {
//                 break; // If current is not greater than parent, stop
//             }
//         }
//         index++;
//     }

//     int top(){
//         return arr[0];
//     }

//     void heapifyMin(int i) {
//         int Smallest = i; // Initialize largest as root
//         int left = leftChild(i);
//         int right = rightChild(i);
//         // If left child is larger than root
//         if(left < index && arr[left] > arr[Smallest]) {
//             Smallest = left;
            
//         if(right < index && arr[right] > arr[Smallest]) {
//             Smallest = right;

//         }
//         if (largest != i) {
//             swap(arr[i], arr[Smallest]);
//             heapifyMin(Smallest);

//         }
//     }

//     void Delete(){
//         if (index == 0) {
//             cout << "Heap is empty, nothing to delete." << endl;
//             return;
//         }

//         swap(arr[0], arr[index-1]); // Swap the root with the last element
//         index--; // Reduce the size of the heap
//         heapifyMin(0); // Restore the heap property
//     }

//     void printHeap() {
//         cout << "Heap elements: ";
//         for (int i = 0; i < index; i++) {
//             cout << arr[i] << " ";
//         }
//         cout << endl;
//     }

//     ~Heap(){
//         delete [] arr;
//     }

// };


// int main(){
//    Heap h(4);
// //    h.insertForMaxHeap(20);
// //    h.printHeap();
// //    h.insertForMaxHeap(10);
// //    h.printHeap();
// //    h.insertForMaxHeap(40);
// //    h.printHeap();
// //    h.insertForMaxHeap(50);
// //    h.printHeap();
// //    h.Delete();
// //    h.printHeap();

//    cout<<"Min Heap ---------------------------------------" << endl;

//    h.insertForMinHeap(10);
//    h.printHeap();
//    h.insertForMinHeap(50);
//    h.printHeap();
//    h.insertForMinHeap(40);
//    h.printHeap();
//    h.insertForMinHeap(30);
//    //h.printHeap();
// }


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
