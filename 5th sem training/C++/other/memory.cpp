#include<iostream>
using namespace std;

int main(){
    int a =5;
    int *p = new int ;
    p= &a ;
    cout<<*p<<" "<<p<<" "<<a <<endl ;
    //delete p;
    return 0 ;

}