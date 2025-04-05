#include<stdio.h> 
int main()
{
int a [3] [3], b[3] [3], c[3][3], i , j;
printf(" Enter elements of matrix A\n"); 
for( i=0; i<=2; i++)
{
for( j=0; j<=2; j++)
{
scanf("%d", &a[i][j]);
}
}
printf(" Enter elements of matrix B\n"); 
for( i=0; i<=2; i++)
{
for( j=0; j<=2; j++)
{
scanf("%d", &b[i][j]);
}
}
for( i=0; i<=2; i++)
{
for( j=0; j<=2; j++)
{
c[i][j] = a[i][j] - b[i][j];
}
}
printf(" The resultant of matrix Subtraction is\n"); 
for( i=0; i<=2; i++)
{
for( j=0; j<=2; j++)
{
printf("%d \t", c[i][j]);
}
printf("\n");
}
return 0;
}