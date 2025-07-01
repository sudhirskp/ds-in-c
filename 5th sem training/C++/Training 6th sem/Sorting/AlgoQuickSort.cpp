#include<iostream>
using namespace std;

class QuickSort{
	
	int* ARRAY;
	int SIZE;
	
	public:
		
		QuickSort(int size){
			this->SIZE = size;
			ARRAY = new int[SIZE];

		}
		
		
		~QuickSort(){
			
			delete[] ARRAY;
						
		}
		
		
		void insertData(){
			int data;
			
			cout<<"DATA: ";
			for(int i=0; i<SIZE; i++){
				cin>> data;
				ARRAY[i] = data;
			}			
			
		}
		
		void showData(){

			cout<<"ORIGINAL DATA: ";
			for(int i=0; i<SIZE; i++){
				cout<< ARRAY[i] << " ";
			}			
				
		}
	
		//quick sort call...
		void sort(){
			quickSort(0, SIZE-1);	//first_index and last_index		
		}
	
		//LOGIC BUILDING - QuickSort
		void quickSort(int low, int high){
			
			if(low < high){
			
				int pivot = partition(low, high);	//ARRAY[high];
				
				quickSort(low, pivot - 1);
				quickSort(pivot + 1, high);
			}
		
		}
	
		//LOGIC BUILDING - SUPPORTER		
		int partition(int low, int high){
			
			int pivot = ARRAY[high];
			int i = (low - 1);
			
			for(int j=low; j<high; j++){
			
				if(ARRAY[j] <= pivot){
					i++;
					swap(ARRAY[i], ARRAY[j]);		
				} 
			}
			
			swap(ARRAY[i+1], ARRAY[high]);
			return i+1;
			
		}		
	
	
};

//DRIVER CODE
int main(){
	
	int size;
	
	cout<<"ARRAY SIZE: ";
	cin>> size;
	

	QuickSort obj(size);
	
	obj.insertData();
	obj.showData();
		
	obj.sort();

	obj.showData();
	
	
	return 0;
}