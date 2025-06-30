#include<stdio.h>
#include<math.h>
int main(){
    int arr[3][3] , arr2[3][3],arr3[3][3];
    printf("enter arr element : ");
    for (int i = 0; i < 3; i++)
    {
        for (size_t j = 0; j < 3; j++){
            scanf("%d",&arr[i][j]);
        }

    }
    for (size_t i = 0; i < 3; i++)
    {
        for (size_t j = 0; j < 3; j++){
            printf("%d ",arr[i][j]);
        }
        printf("\n");

    }
    printf("enter arr2 element : ");
    for (size_t i = 0; i < 3; i++)
    {
        for (size_t j = 0; j < 3; j++){
            scanf("%d",&arr2[i][j]);
        }

    }
    printf("multiplicated matrix  : \n");
    for (size_t i = 0; i < 3; i++)
    {
        for (size_t j = 0; j < 3; j++){
           arr3[i][j]=arr[i][j]*arr2[i][j];
        }

    }
    for (size_t i = 0; i < 3; i++)
    {
        for (size_t j = 0; j < 3; j++){
           printf("%d ",arr3[i][j]);
        }
        printf("\n");

    }
    return 0;

}