#include <stdio.h>
#include <stdlib.h>

int fuct(int num)
{
    if (num>1)
    {
        return num*fuct(num-1);
    }
}

int main()
{
    int nmb = 5;
    int temp;
    temp = fuct(nmb);
    printf("%d\n", temp);
    return 0;
}