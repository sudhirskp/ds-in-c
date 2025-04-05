#include<stdio.h>
void lisearch(int arr[], int n, int key){
   int low=0,high=n-1,mid;
   while (low<=high)            
   {
    mid=(low+high)/2;
    if(arr[mid]==key){
        printf("key is found = %d ",key);
        break;
    }
    else if(arr[mid]>key) {
        high=mid-1;
   }
   else{
    low=mid+1;
   }
}
}
void main(){
    int arr[]={1,2,3,4,5,6,7};
    int key=1;
    lisearch(arr,6,key);
}