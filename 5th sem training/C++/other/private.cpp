#include<iostream>
using namespace std;

class pr{
    int a ;
    public:
    void display(int b){
        a = b ;
        cout<<"Value of a is "<<a<<endl;
    }
};
int main(){
    pr prt;
    prt.display(5);
}