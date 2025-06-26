#include<iostream>
#include<deque>
using namespace std;

int main(){
    deque<int>dq;
    dq.push_back(1);
    dq.push_front(10);
    dq.push_back(3);
    dq.push_back(5);

    cout<<"All value :";
    for(int val : dq){
        cout<< val << endl;
    }

    cout<<"front value : ";
    cout<< dq.front()<<endl;

    cout<<"rear Value :";
    cout<<dq.back();

    cout<< " "<< endl;
    cout<<dq.size();



}