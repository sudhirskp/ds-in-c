#include<iostream>
#include<vector>
using namespace std;
#include<algorithm>

int main() {
    vector<int> arr1 = {1, 3, 5, 7, 9};
    vector<int> arr2 = {2, 4, 6, 8, 10};
    vector<int> mergedArr(arr1.size() + arr2.size());

    // Merge the two sorted arrays
    merge(arr1.begin(), arr1.end(), arr2.begin(), arr2.end(), mergedArr.begin());

    // Display the merged array
    cout << "Merged array: ";
    for (int i : mergedArr) {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}