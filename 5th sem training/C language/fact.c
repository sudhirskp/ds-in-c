#include<stdio.h>
#include<conio.h>
int fact(int n){
    if(n==0){
        return 1;
    }
    if(n>0){
        return fact(n-1)*n;
    }
}
int main(){
    int n=5;
    int x= fact(n);
    printf("%d",x);
}