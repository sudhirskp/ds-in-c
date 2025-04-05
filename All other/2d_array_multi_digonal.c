#include<stdio.h> 
int main()
{
int a[3][3], b[3][3], c[3][3], n, i, j, k;
printf("Enter the value of n\n");
 scanf("%d",&n);
printf("Enter the elements of the first matrix\n");
 for(i=0;i<=n-1; i++)
{
for(j=0;j<=n-1;j++)
{
scanf("%d", &a[i][j]);
}
}
printf("Enter the elements of the second matrix\n"); 
for(i=0;i<=n-1; i++)
{
for(j=0;j<=n-1;j++)
{
scanf("%d", &b[i][j]);
}
}
 for(i=0;i<=n-1; i++)
{
for(j=0;j<=n-1;j++)
{ c[i][j]=0;
for(k=0;k<=n-1;k++)
{
c[i][j]=c[i][j]+a[i][k]*b[k][j];
}
}
}
printf("The multiplication matrix is\n");
 for(i=0;i<=n-1; i++)
{
for(j=0;j<=n-1;j++)
{
printf("%d\t", c[i][j]);
}
printf("\n");
}
printf("The Diagonal Elements of a matrix are\n");
 for(i=0;i<=n-1; i++)
{
for(j=0;j<=n-1;j++)
{ 
 if (i==j)
 {
 
printf("%d\t", c[i][j]);
}
}
}
printf("\n");
return 0;
}