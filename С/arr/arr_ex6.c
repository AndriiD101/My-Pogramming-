#include <stdio.h>

int main()
{
    // int mat[3][3] = {{2,56,7}, {12,6,240}, {235, 10, 36}};
    int mat[3][3]={364, 2, 7905, 286, 675, 36};
    for (int i=0; i<3; i++)
    {
        for(int j=0; j<3; j++)
        {
            printf("%d ", mat[i][j]);
        }
        printf("\n");
    }
}