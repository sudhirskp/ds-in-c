#include <iostream>
#include<stack>
#include<string>
using namespace std;
int main(){
    stack<char> s;
    //string str;
    s.push('a');
    s.push('b');
    s.push('c');
    s.push('d');
    s.pop();



    cout<< s.top()<<endl;

    cout<<s.size()<<endl;

    cout<<s.empty()<<endl;

    cout<< "Stack elements: ";
    while(!s.empty()){
        //cout<< s.pop() << " ";
        cout<< s.top() << " ";
        s.pop();
    }
    cout<< endl;

    return 0;
}