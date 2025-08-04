#include<iostream>
#include<queue>
#include<vector>
#include<climits>
using namespace std;


int KthLargest(vector<int>& nums, int k) {
    priority_queue<int, vector<int>, greater<int>> minHeap;

    for (int num : nums) {
        minHeap.push(num);
        if (minHeap.size() > k) {
            minHeap.pop();
        }
        cout<<"Current : " << minHeap.top() << endl;
    }

    return minHeap.top();
}

int KthSmallest(vector<int>& nums, int k) {
    priority_queue<int> maxHeap;

    for (int num : nums) {
        maxHeap.push(num);
        if (maxHeap.size() > k) {
            maxHeap.pop();
        }
        cout<<"Current : " << maxHeap.top() << endl;
    }

    return maxHeap.top();
}


int main(){
    int n, k;
    cout << "Enter number of elements: ";
    cin >> n;
    vector<int> nums(n);
    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    cout << "Enter the value of k: ";
    cin >> k;
    int result = KthLargest(nums, k);
    cout << "The " << k << "th largest element is: " << result << endl;
    


    int resultSmallest = KthSmallest(nums, k);
    cout << "The " << k << "th smallest element is: " << resultSmallest << endl;
    return 0;
}