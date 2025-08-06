#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void countingSort(vector<int>& arr, int place) {
    int n = arr.size();
    vector<int> res(n);
    int count[10] = {0};

    
    for (int i = 0; i < n; i++)
        count[(arr[i] / place) % 10]++;

    
    for (int i = 1; i < 10; i++)
        count[i] += count[i - 1];


    for (int i = n - 1; i >= 0; i--) {
        int index = (arr[i] / place) % 10;
        res[--count[index]] = arr[i];
        //count[index]--;
    }
    arr = res;
}

void radixSort(vector<int>& arr) {
    int maxVal = *max_element(arr.begin(), arr.end());

    
    for (int place = 1; maxVal / place > 0; place *= 10)
        countingSort(arr, place);
}

int main() {
    vector<int> arr = {170, 45, 75, 90, 802, 24, 2, 66};

    cout << "Original array: ";
    for (int num : arr) cout << num << " ";
    cout << endl;

    radixSort(arr);

    cout << "Sorted array: ";
    for (int num : arr) cout << num << " ";
    cout << endl;

    return 0;
}