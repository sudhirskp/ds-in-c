#include<iostream>
using namespace std;

class grand {
    public:
    string property = "Grand Pr";
    string vechicals = "Grand ";
    string assetone = "G";
};

class father : public grand {
    public:
    string property = "Father Pr";
    string vechicals = "Father ";
    string assettwo = "F";
};
class child : public father {
    public:
    string asset = "None";
};


int main(){
    child c;
    cout<<"asset from grand : "<<c.assetone<<endl;
    cout<<"asset from father : "<<c.assettwo<<endl;
    cout<<"asset from son : "<<c.asset<<endl;
    return 0;
}