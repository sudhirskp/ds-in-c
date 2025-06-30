#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
int main()
{
    struct data{
        int a;
        float b;
    };
    struct data mav;

    mav.a=10;
    mav.b=3.99;


    printf("%d %.1f",mav.a,mav.b);
}
