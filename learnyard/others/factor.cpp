#include<iostream>
using namespace std;

int main(){
    int n;
    cout<<"Enter Number to find factors : ";
    cin>>n;
    cout<<"The factors of the Number "<<n<<" are : ";
    for(int i=1;i<=n;i++){
        if(n%i==0){
            cout<<i<<" ";
        }
    }
}