#include<iostream>
#include<stdio.h>
using namespace std;
int fact(int a);
int fact(int a){
    if(a==0 || a==1){
        return 1;
    }
    else{
        return a*fact(a-1);
    }
}
int main(){
    int n;
    cout<<"Enter the range to find number : ";
    cin>>n;
    cout<<"the strong number between 1 to "<<n<<" is : ";
    int sum=0;
    int t;
    for(int i=1;i<=n;i++){
        sum=0;
        t=i;
    while(t>0){
        int r =t%10;
        sum = sum + fact(r);
        t=t/10;
        
    }
    if(i==sum){
        cout<<i<<" ";
    }
    }

    return 0;

}