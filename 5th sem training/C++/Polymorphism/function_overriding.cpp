//compile time - function overriding 


#include<iostream>
using namespace std;

class base {
    public:
    void greet(){
        cout<<"hello i am base";
    }
};
class child : public base{
    public:
    void greet(){
        cout<<"hello i am child";
    }
};
int main(){
    base b;
    child c;
    b.greet();
    cout<<endl;
    c.greet();
}