#include <iostream>
using namespace std;

//4 2 1 6 9
class SortingAlgos {

private:

    int* ARRAY;
    int size;

public:

    SortingAlgos(int ARRAY[], int size) {
        
		this->ARRAY = ARRAY;
        this->size = size;
    
	}

	//LOGIC BUILDING CODE - BUBBLE SORT
	//Comparing the adjacent values and setting the higher at the last
	void bubble_sort(){
		
	    bool swapped;

        for (int i = 0; i < size-1; i++) {

            swapped = false;
            for (int j = 0; j < size-i-1; j++) {
                if (ARRAY[j] > ARRAY[j+1]) {1
                    swap(ARRAY[j], ARRAY[j+1]); 
                    swapped = true;
                }
            }         
            if (!swapped) break;            
        }
	
	}


	//LOGIC BUILDING CODE - SELECTION SORT
	//Selecting the smallest value to swap with the original (main)
	void selection_sort(){
		
		for (int i = 0; i < size-1; i++) {
	
            int minimumValueIndex = i;

            for (int j = i+1; j < size; j++) {
                if (ARRAY[j] < ARRAY[minimumValueIndex]) {
                    minimumValueIndex = j;
                }
            }
            
            if (minimumValueIndex != i) {
                swap(ARRAY[i], ARRAY[minimumValueIndex]);
            }
            
        }
	
	}


	void insertion_sort(){
		    
            for (int i = 1; i < size; i++) {
                int key = ARRAY[i];
                int j = i - 1;
    
                while (j >= 0 && ARRAY[j] > key) {
                    ARRAY[j + 1] = ARRAY[j];
                    j--;
                }
                ARRAY[j + 1] = key;
            }
	}


    void display() {
        for (int i = 0; i < size; i++) {
            cout << ARRAY[i] << " ";
        }
        cout << endl;
    }




};




//DRIVER CODE
int main(){
	
    int ARRAY[] = {4, 2, 1, 6, 9};
    //int ARRAY[] = {64, 34, 25, 12, 22, 11, 90};
    int size = sizeof(ARRAY) / sizeof(ARRAY[0]);
	
	SortingAlgos _obj(ARRAY, size);	
	
	cout << "Unsorted array: ";
    _obj.display();
	_obj.bubble_sort();
	cout << "Sorted array: ";
    _obj.display();

    cout << "Sorted array using selection sort: ";
    _obj.selection_sort();
    _obj.display();

    cout << "Sorted array using insertion sort: ";
    _obj.insertion_sort();
    _obj.display();
	
		
		
	
}
