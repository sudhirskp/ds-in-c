#include<iostream>
using namespace std;

class base {
    public:
    void msg(){
        cout<<"This is base class"<<endl;
    }

};
class derived : public base
{
    string child = "tom";
};
int main(){
    derived d;
    //cout<<d.child<<endl;
    d.msg();
    cout<<child;

}