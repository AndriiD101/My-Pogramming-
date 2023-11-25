#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    float cent = 0.01;
    for (int i=1; i<=30; i++)
    {
        printf("day: %d, amount: %.2f\n", i, cent);
        cent=cent*2;
    }
    return 0;
}
