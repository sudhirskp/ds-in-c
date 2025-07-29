#include<iostream>
#include<array>
using namespace std;
#define N 5

int main(){
    array<int, N> arr = {2,0,2,5};
    array<int, N> prefixSum = {arr[0]};

    for(int i = 1; i < N; i++){
        prefixSum[i] = prefixSum[i-1] + arr[i];
    }
    
    for(int i = 0; i < N; i++){
        cout << prefixSum[i] << " ";
    }
}