#include<iostream>
using namespace std;

int main(){
    int n,x,y;
    cin>>n>>x>>y;
    int sum=0;
    if(x==0 || y==0){
        cout<<"YES"<<endl;
    }
    else{
    for(int i=1;i<n;i++){
        sum=sum+x;
    
    if(sum==y){
        cout<<"YES"<<endl;
    }
    else{
        cout<<"NO"<<endl;
    }
    }
    }
    return 0;
}