//call by referance 
#include<iostream>
using namespace std;
int change(int &a);

int change (int &a){
    a = 10;
    return a;
}
int main(){

    int a = 5,val;
    val = change(a);
    cout<<"a : "<<a;

}

