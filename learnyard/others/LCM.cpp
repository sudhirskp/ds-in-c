#include<iostream>
using namespace std;

int HCF(int a , int b){
    if(b==0){
        return a;
    }
    else{
        return HCF(b,a%b);
    }
}

int LCM(int a , int b){
    return (a*b)/HCF(a,b);
}

int main(){
    int a,b;
    cout<<"Enter two numbers to check LCM and HCF : ";
    cin>>a>>b;
    cout<<"The HCF and LCM of the number "<< a <<" "<< b << " are " <<HCF(a,b)<<" and "<<LCM(a,b)<<endl;
    
}