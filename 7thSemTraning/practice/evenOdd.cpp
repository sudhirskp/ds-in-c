#include<iostream>
#include<array>
using namespace std;
#define N 5

int main(){
    int n;
    cout << " Enter the Number to check : ";
    cin>>n;
    if((n/2)*2 == n) {
        cout << n << " is Even" << endl;
    } else {
        cout << n << " is Odd" << endl;
    }
}

//N%2 , (n/2)*2 == n(even) , n&1==1(odd), n^1 == n+1(even)