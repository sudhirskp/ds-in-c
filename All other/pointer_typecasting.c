#include<stdio.h>
int main(){
    int n=10;
    void *ptr=&n;
    printf("%d",*(int*)ptr);

    //wild pointers
    int *p;
    *p=10;

    //size of NULL pointer
   // printf("%d",sizeof(NULL));
    return 0;
}