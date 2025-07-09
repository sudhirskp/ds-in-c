#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
void main(){
    char n;
    printf("enter any alphabate : ");
    scanf("%c",&n);

    switch(n){
        case('a'):
        case('A'):
        printf("the alphabate is vowel");
        break;
        case('e'):
        case('E'):
        printf("the alphabate is vowel");
        break;
        case('i'):
        case('I'):
        printf("the alphabate is vowel");
        break;
        case('o'):
        case('O'):
        printf("the alphabate is vowel");
        break;
        case('u'):
        case('U'):
        printf("the alphabate is vowel");
        break;

        default:

        printf("the alphabate is consonats");
    }
}