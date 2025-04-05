#include <stdio.h>
int main(){
int arr[3][3],m,n,i,j;
printf("Enter total number of rows= ");
scanf("%d",&m);
printf("Enter total number of columns= ");
scanf("%d",&n);
printf("Enter the array element\n");
for(i=0;i<m;i++){
for(j=0;j<n;j++){
scanf("%d\n",&arr[i][j]);
}
}
printf("Row-Major Order:\n");
for(i=0;i<m;i++){
for(j=0;j<n;j++){
printf("%d\t",arr[i][j]);
}
printf("\n");
}
printf("Column-Major Order:\n");
for(i=0;i<m;i++){
for(j=0;j<n;j++)
printf("%d\t",arr[j][i]);

  printf("\n");
}
}