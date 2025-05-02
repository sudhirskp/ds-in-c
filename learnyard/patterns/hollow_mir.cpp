//     *
//    **
//   * *
//  *  *
// *****
#include<iostream>
using namespace std;
int main(){
    int r ,c,i,j ;
    cout<<" ENter row and col : ";
    cin>>r>>c;
    for(int i=1;i<=r;i++){
        for(int j=1;j<=r-i;j++){
            cout<<" ";
        }
        for(int j=1;j<=i;j++){
            if(i==r || i==1 || j==1 || j==i){
            cout<<"*";
            }
            else{
                cout<<" ";

            }
        }
        cout<<endl;
            
    }
}