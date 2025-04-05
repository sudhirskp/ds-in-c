#include <stdio.h>
void print_uppertriangle(int A[3][3],int i,int j)
{
    for(i = 0; i < 3; i++)        
    {
        for(j = 0; j < 3;j ++)
        {
            if(i <= j)
            {
                printf("%d", A[i][j]);
         }
         else
         {
                printf("%d", 0);
            }
         printf(" ");
     }
        printf("\n");
    }
}
void print_lowertriangle(int A[3][3],int i,int j)
{
    for(i = 0; i < 3; i++)      
    {
        for(j = 0; j < 3; j++)
        {
            if(i >= j)
         {
                printf("%d", A[i][j]);
            }
         else
         {
                printf("%d", 0);
            }
         printf(" ");
        }
     printf("\n");
    }
}
int main()
{
    int i,j;
    int A[3][3] = {{0, 5, 12}, {10, 9, 12}, {7, 9, 0} };
    printf("Matrix A :--> \n");
    for(i = 0;i < 3; i++)
    {
        for( j = 0; j < 3; j++)
     {
         printf("%d  ", A[i][j]);
     }
     printf("\n");
    }
    printf("Upper Triangular Matrix :--> \n");
    print_uppertriangle(A, i, j);
    printf("\nLower Triangular Matrix :--> \n");
    print_lowertriangle(A, i, j);
    return 0;
}