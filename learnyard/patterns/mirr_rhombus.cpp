#include<iostream>
using namespace std;
int main(){
    int r ,c ;
    cout<<" ENter row and col : ";
    cin>>r>>c;
    for(int i=1;i<=r;i++){
        for(int j=1;j<=i;j++){
            cout<<" ";
        }
       
        for(int k=1;k<=c;k++){
            cout<<"*";
        }
        cout<<endl;
            
    }
}