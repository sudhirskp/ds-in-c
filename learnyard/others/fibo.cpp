#include<iostream>
using namespace std;

int fib(int f){
    if(f==0 || f==1){
        return f;
    }
    else{
        return fib(f-1)+fib(f-2);
    }
}

int main(){
    int fib_limit;
    cout << "Enter the limit for Fibonacci sequence: ";
    cin>>fib_limit;
    cout<<"Fibonnaci sequence up to "<<fib_limit<<" is: ";
    for(int i=0;i<fib_limit;i++){
    cout<<" " <<fib(i);
    }

}