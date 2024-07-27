#include <stdio.h>

#define size 10

int main()
{
    int table[size][size];

    for(int i= 1; i<size; i++)
    {
        for(int j=1; j<size; j++)
        {
        table[i][j]= i*j;
        }
    }

    for (int i=1; i<size; i++)
    {
        for(int j=1; j<size; j++)
        {
            printf("%d ", table[i][j]);
        }
        printf("\n");
    }
    return 0;
}