#include<iostream>
using namespace std;

int add(int a , int b){
    return a + b;
}
float add(float x , float y){
    return x + y;
}
int main(){
    int a,b;
    float x,y;
    a = 5,b=10;
    x=2.5 , y =3.0;
    float real = add(x,y);

    cout<<add(a,b)<<endl;
    cout<<real;

}