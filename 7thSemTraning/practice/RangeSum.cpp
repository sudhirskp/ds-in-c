#include<iostream>
#include<array>
using namespace std;
#define N 10

array<int, N> arr = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
array<int, N> prefixSum = {arr[0]};

void preSum(){
    for(int i=1;i<N;i++){
        prefixSum[i] = prefixSum[i-1] + arr[i];
    }
}

int rangeSum(int l, int r){
    if(l == 0) return prefixSum[r];
    return prefixSum[r] - prefixSum[l-1];
}

void displayPrefixSum() {
    for(int i = 0; i < N; i++) {
        cout << prefixSum[i] << " ";
    }
    cout << endl;
}


int main(){

    preSum();
    displayPrefixSum();

    int l, r;
    cout << "Enter range (l r): ";
    cin >> l >> r;

    if(l < 0 || r >= N || l > r) {
        cout << "Invalid range!" << endl;
        return 1;
    }

    int sum = rangeSum(l, r);
    cout << "Range Sum from " << l << " to " << r << " is: " << sum << endl;

    return 0;

}