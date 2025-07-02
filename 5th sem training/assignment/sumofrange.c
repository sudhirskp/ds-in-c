#include<stdio.h>
int main(){
    int n ,sum=0;
    printf("Enter the range for sum : ");
    scanf("%d",&n);

    for(int i=0;i<n;i++){
        sum = sum + i;
        
    }
    printf("The sume of range %d is %d",n,sum);

    return 0;
}