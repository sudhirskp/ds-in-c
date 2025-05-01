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
    cout<<"Enter the number to check strong or not : ";
    cin>>n;
    int sum=0;
    int t=n;
    while(t>0){
        int r =t%10;
        sum = sum + fact(r);
        t=t/10;
        
    }
    if(n==sum){
        cout<<n<<" is strong number ";
    }
    else{
        cout<<n<<" is not strong number ";
    }

    return 0;

}