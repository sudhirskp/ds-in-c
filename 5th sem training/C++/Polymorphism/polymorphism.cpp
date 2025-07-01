#include<iostream>
using namespace std;

class bird {
    public:
   void features(){
    cout<<"Birds can fly , swim and sing"<<endl;
   }
};

class DonalDuck : public bird {
    public:
    void features(){
    cout<<"Donal can dance on song"<<endl;
   }
    
};
class cukoo : public bird  {
    public:
    void features(){
    cout<<"cukoo can dance on water layer"<<endl;
   }
};
;

int main(){
    bird b;
    DonalDuck d;
    cukoo c;
    b.features();
    d.features();
    c.features();

    return 0;
}