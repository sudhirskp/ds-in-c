#include<iostream>
using namespace std;

class father {
    public:
   
    string asset = "bike ";
    string property = "house ";
};

class son : public father {
    public:
    void msg(){
        cout << "Asset of son is " << endl;
    }
};
class daughter : public father {
    public:
    string vechical = "car ";
    string asset = "bangle";
};


int main(){
    son s;
    daughter d;
    cout<<"asset from father : "<<s.asset<<endl;
    cout<<"asset from  father : "<<d.asset<<endl;
   s.msg();

    return 0;
}