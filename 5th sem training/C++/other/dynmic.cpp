#include<iostream>

using namespace std;
int main() {
    int n; 
    cout << "Enter the number of inputs: ";
    cin >> n;
    
    int* p = new int[n];

   
    for(int i = 0; i < n; i++){
        cout << "Enter input "<< ": "; 
        cin >> p[i]; 
    }

    for(int i = 0; i < n; i++) {
        cout << p[i] * p[i]<< " ";
    cout << endl;
    //delete[] p; 
    }
    return 0;


}