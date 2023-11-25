#include <stdio.h>
#include <stdlib.h>

int sum_of_numbers(int num)
{
    if (num==0)
    {
        return 0;
    }

    return num+sum_of_numbers(num-1);
    
}

int main()
{
    int nmb = 5;
    int temp;
    temp = sum_of_numbers(nmb);
    printf("%d\n", temp);
    return 0;
}