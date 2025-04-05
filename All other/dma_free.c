#include<stdio.h>
#include<stdlib.h>

int *var(){
    int i,*ptr;
    ptr = (int*)malloc(5*sizeof(int));
    printf("Enter any 5 numbers: ");
    for(int i=0;i<5 ;i++){
        scanf("%d",ptr+i);
    }
    return ptr;

}
int main()
{
    int i,sum=0 ;
    int *ptr=var();
    for(i=0;i<5;i++)
     sum += *(ptr+i);
    
    printf("%d",sum);
    free(ptr);
    ptr=NULL;
    return 0;
}

    
