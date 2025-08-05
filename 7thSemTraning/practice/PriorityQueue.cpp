#include<iostream>
#include<queue>
using namespace std;



int main(){
    //MaxHeap
    priority_queue<int> que;
    que.push(10);
    que.push(20);
    que.push(30);
    que.push(40);
    que.push(50);
    cout<<que.top()<<endl;
    que.pop();
    cout<<que.top()<<endl;
    cout<<que.size()<<endl;
    cout<<que.empty()<<endl;

    cout << "------------------------" << endl;
    //MinHeap
    priority_queue<int, vector<int>, greater<int>> minQue;
    minQue.push(10);
    minQue.push(20);
    minQue.push(30);
    minQue.push(40);
    minQue.push(50);

    cout<<minQue.top()<<endl;
    minQue.pop();
    cout<<minQue.top()<<endl;
    cout<<minQue.size()<<endl;
    cout<<minQue.empty()<<endl;


    priority_queue<int> temp(que);
    cout << "Copying MaxHeap to another MaxHeap : Psudo Traversal" << endl;
    while (!temp.empty()) {
        cout << temp.top() << " ";
        temp.pop();
    }
    cout << endl;
    

}