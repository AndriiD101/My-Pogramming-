#include <stdio.h>

int main()
{
    int mat[2][3];
    int tamp;
    for(int i=0; i<2; i++)
    {
        for(int j=0; j<3; j++)
        {
        printf("enter the value: ");
        scanf("%d", &mat[i][j]);
        }
    }

    for(int i=0; i<2; i++)
    {
        for(int j=0; j<3; j++)
        {
        printf("%d ", mat[i][j]);    
        }
        printf("\n");
    }
    return 0;
}