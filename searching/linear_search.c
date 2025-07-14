#include<stdio.h>
#include<stdlib.h>

int main(){
    int i,n,arr[50],search;
    printf("Enter the size of array = ");
    scanf("%d",&n);
    printf("Enter the array elements = ");
    for(i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    printf("Enter the number to search = ");
    scanf("%d",&search);
    for(i=0;i<n;i++){
        if(arr[i]==search){
            printf("%d is present at the position of %d\n",search,i);
            break;
        }
    }
    if (n==i){
        printf("%d is not present in the given array\n",search);
    }
    return 0;
}
