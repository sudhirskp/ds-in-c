#include <stdio.h>
void main () 
{
     int arr[4][4];
    int i,j,r,c;
    int s=0;
    printf("No. of rows and columns in the matrix are \n");
    scanf("%d\n %d\n", &r, &c);
    printf("Enter the elements in the matrix :\n");
    for(i=0;i<r;i++)
    {
        for(j=0;j<c;j++)
        {
            scanf("%d",&arr[i][j]);
            if (arr[i][j]==0)
                ++s;
        }
    }
    if (s>((r*c)/2))
        printf ("The given matrix is a sparse matrix. \n");
    else
        printf ("The given matrix is not a sparse matrix.\n");
    printf ("There are %d number of zeros in the matrix.\n",s);
}