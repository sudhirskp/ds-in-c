#include<stdio.h>
#include<stdlib.h>
#include<stddef.h>
int cirq[6];
int maxsize=6;
int rear=-1;
int front=-1;
void enqueue(int value){
    if(front==-1){
        front=rear=0;
        cirq[rear]=value; 
    }
   else if(front==(rear+1)%maxsize){
        printf("the queue is full");
        return;
    }
    else{
        rear=(rear+1)/maxsize;
        cirq[rear]=value;
    }
}
//queue full and empty basic
void main(){
   /* if(front==-1)
    {
        printf("the queue is empty");
    }
else{
     if(front==rear+1){
        printf("the queue is full");
     }
}*/
enqueue(2);
enqueue(34);
enqueue(5);
enqueue(10);
enqueue(15);
enqueue(25);
enqueue(30);
enqueue(35);
}

void display(){
    int i;
    for(i=front;i<=rear;(i+1)%maxsize){
        printf("\n");
        printf("%d",cirq[i]);
    }
}