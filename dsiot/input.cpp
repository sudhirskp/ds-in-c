#include<iostream>
using namespace std;
int main(){
    int arr1[10];
    int arr2[10];
    cout<<"ENter the arr1 element ";
    for(int i=0;i<10;i++){
        cin>>arr1[i];
    }

    cout<<"ENter the arr2 element ";
    for(int i=0;i<10;i++){
        cin>>arr2[i];
    }

    // Display the elements of arr1 and arr2
    cout<<"Elements of arr1: ";
    for(int i=0;i<10;i++){
        cout<<arr1[i]<<" ";
    }
    cout<<endl;

    cout<<"Elements of arr2: ";
    for(int i=0;i<10;i++){
        cout<<arr2[i]<<" ";
    }
    cout<<endl;
}