#include<iostream>
using namespace std;

int main(){

    int number;
    int firstdigit;
    int lastdigit;

    cout<<"Enter Number : ";
    cin>>number;

     // for last digit od number
    if(number>0){
        lastdigit=number%10;
    }

    //for first digit of number

    while(number>=10){
        number = number / 10;
    }
    firstdigit = number;

    if(firstdigit == lastdigit){
        cout<<"First and Last digit are same" << " Sum is "<<lastdigit+firstdigit;
    }
    else{
        cout<< " Sum is "<<lastdigit+firstdigit;
    }

    
}