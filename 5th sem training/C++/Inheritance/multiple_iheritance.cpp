#include<iostream>
using namespace std;

class father {
    public:
   
    string vechicals = "bike ";
    string asset = "house ";
};

class mother{
    public:
    
    string asset = "car ";
    
};
class child : public father , public mother {
    public:
    string nullasset = "None";
};


int main(){
    child chhota_bheem;
    cout<<"asset from mother : "<<chhota_bheem.vechicals<<endl;
    cout<<"asset from  father : "<<chhota_bheem.asset<<endl;
    cout<<"asset from son : "<<chhota_bheem.nullasset<<endl;

    return 0;
}