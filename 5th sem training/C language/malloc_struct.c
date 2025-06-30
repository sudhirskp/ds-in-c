#include<stdio.h>
#include<stdlib.h>
int main(){
    int *p;
    int n=5;
    p = (int*)malloc(n*sizeof (int));
    if(p==NULL){
        printf("empty");
        exit(1);
    }
    printf("enter any 5 integer : ");
    for(int i=0;i<n;i++){
        scanf("%d",p+i); //notice here p+i
    }
    for (int i = 0; i < n; i++)
    {
        printf("%d ",*(p+i));     // notic here *(p+i)
    }
    return 0;
}