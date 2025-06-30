#include<stdio.h>
#include<stdlib.h>
int main(){
    struct pt {
        int data;
        float a;
    };
    struct pt *p;

    p = malloc(sizeof(struct pt));

    p->data=345;
    p->a=8.99;

    printf("%d %.1f",p->data,p->a);

}
   