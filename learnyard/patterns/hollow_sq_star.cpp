// *****
// ** **
// * * *
// ** **
// *****

#include<iostream>
using namespace std;

int main(){
    int r,c;
    cout<<"Enter the row and coln : ";
    cin>>r>>c;
    for(int i=1;i<=r;i++){
        for(int j=1;j<=c;j++){
            if(i==1 || j==1 || i==r || j==c || i==j || j==r-i+1){
                cout<<" * ";
            }
            else{
                cout<<"   ";
            }
            
        }
        cout<<"\n";
    }
}