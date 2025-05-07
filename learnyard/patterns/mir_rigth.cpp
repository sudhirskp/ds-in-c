//     *
//    **
//   ***
//  ****
// *****
#include<iostream>
using namespace std;
int main(){
    int r ,c ;
    cout<<" ENter row and col : ";
    cin>>r>>c;
    for(int i=1;i<=r;i++){
        for(int j=1;j<=r-i;j++){
            cout<<" ";
        }
       
        for(int k=1;k<=i;k++){
            cout<<"*";
        }
        cout<<endl;
            
    }
}