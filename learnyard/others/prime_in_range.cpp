#include<iostream>

using namespace std;

int main(){
    int n , count=0;
    cout<<"Enter the range to check prime number : ";
    cin>>n;
    cout<<"the prime number in range "<< n <<" are : ";
    for(int i=1;i<=n;i++){
        for(int j=1;j<=i;j++){
            if(i%j==0){
                count++;
            }

        }
        if(count==2){
        cout<<i<<" ";
        }
        count=0;



    }
}