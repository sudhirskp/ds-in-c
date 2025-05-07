// *
// **
// * *
// *  *
// *****
#include<iostream>
using namespace std;
int main(){
    int r ,c ;
    cout<<" ENter row and col : ";
    cin>>r>>c;
    for(int i=1;i<=r;i++){
        for(int j=1;j<=i;j++){
           if(i==j || i==r || j==1){
            cout<<"*";
           }
           else{
            cout<<" ";
           }
        }
        cout<<endl;
    }
}