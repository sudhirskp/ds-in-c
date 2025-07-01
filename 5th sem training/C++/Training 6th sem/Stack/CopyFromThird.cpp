#include<iostream>
#include<stack>
#include<string>
using namespace std;


void CopyStack(stack<int> &s1, stack<int> &s2){
    stack<int> temp;
    stack<int> temp2;
    stack<int> res;
    while(!s1.empty()){
        temp.push(s1.top());
        s1.pop();
    }

    while(!s2.empty()){
        temp2.push(s2.top());
        s2.pop();
    }

    while(!temp.empty()){
        res.push(temp.top());
        temp.pop(); 
    }

    while(!temp2.empty()){
        res.push(temp2.top());
        temp2.pop();
    }

    while(!res.empty()){
        cout<< res.top() << " ";
        res.pop();
    }
}

void Copy(stack<int> &s1){
    stack<int> temp;
    stack<int> res;
    while(!s1.empty()){
        temp.push(s1.top());
        s1.pop();
    }

    while(!temp.empty()){
        res.push(temp.top());
        temp.pop(); 
    }

    while(!res.empty()){
        cout<< res.top() << " ";
        res.pop();
    }
}


int addEnd(stack<int> &s1, int ele){
    stack<int> temp;
    while(!s1.empty()){
        temp.push(s1.top());
        s1.pop();
    }

    s1.push(ele);

    while(!temp.empty()){
        s1.push(temp.top());
        temp.pop();
    }

    while(!s1.empty()){
        cout<< s1.top() << " ";
        s1.pop();
    }
}


int main(){
    stack<int> s1; 
    stack<int> s2;
    
    s1.push(10); 
    s1.push(20);
    s1.push(30);

    s2.push(100);
    s2.push(200);
    s2.push(300);

    //CopyStack(s1, s2);

   // Copy(s1);

   addEnd(s1, 1000);

}