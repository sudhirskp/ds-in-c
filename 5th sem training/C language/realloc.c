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
    int x=7;   //here the loop of scanf is over at 5 hence it will print grabage value at other space
    p = realloc(p,x*sizeof(int));
    free(p);
    for (int i = 0; i < x; i++)
    {
        printf("%d ",*(p+i));     // notic here *(p+i)
    }
    //free(p);

    return 0;
}