#include<stdio.h>

int fact(int n){
    if(n==0 || n==1){
        return 1;
    }
    if(n>0){
        return fact(n-1)*n;
    }
    else{
        return -1;
    }
}
int main(){
    int n ,sum;
    printf("Enter the number for fact : ");
    scanf("%d",&n);
    sum=fact(n);
    printf("The sume of range %d is %d",n,sum);

    return 0;
}