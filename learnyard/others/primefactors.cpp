#include<iostream>
using namespace std;

int main(){
    int n , count=0;
    cout<<"Enter Number to find prime factors : ";
    cin>>n;
    cout<<"The prime factors of the Number "<<n<<" are : ";
    for(int i=1;i<=n;i++){
        if(n%i==0){
            //cout<<i<<" ";

            for(int j=1;j<=i;j++){
                if(i%j==0){
                    count++;
                }
            }
            if(count==2){
                cout<<i<<" " ;
            }
            count=0;
        }
    }
}