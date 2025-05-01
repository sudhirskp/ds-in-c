#include<iostream>
using namespace std;

int main(){
    int number;
    int product=1;
    cout << "Enter a number: ";
    cin >> number;

    while(number!=0){
        int remainder = number % 10;
        product = product * remainder;
        number = number / 10;
        
    }

    cout<<"The product of the digits is: "<<product;

    
}