#include<stdio.h>
#include<conio.h>
int main(){
//     int n=5
//     int fact=1;
//     for(int i=1;i<=n;i++){
//          fact=fact*i;
//     }
//      printf(fact);
for(int i=1;i<=4;i++){
     for(int j=1;j<=i;j++){
        printf("*");
     }
     printf("\n");
}
printf("------------------------------\n");
for(int i=1;i<=4;i++){
     for(int j=4;j>=i;j--){
        printf("*");
     }
     printf("\n");
}

printf("------------------------------\n");
for(int i=1;i<=4;i++){
     for(int j=4;j>i;j--){ //j=space i=row  st=star
        printf(" ");
     }
     for(int st=1;st<=i;st++){
          printf("*");
     }
     printf("\n");
}
printf("------------------------------\n");
int num=1;
for(int i=1;i<=4;i++){
     for(int j=1;j<=i;j++){
        printf("%d ",num);
        num++;
     }
     printf("\n");
}

printf("------------------------------\n");
for(int i=1;i<=4;i++){
     for(int j=4;j>i;j--){
        printf(" ");
     }
     for(int st=1;st<=i;st++){
          printf("*");
     }
     for(int st1=1;st1<i;st1++){
          printf("*");
     }
     printf("\n");
}
return 0;
}