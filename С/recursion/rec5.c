#include <stdio.h>
#include <stdlib.h>

#define nmb 32184573
int count = 0;

int CountOfDigits(int num)
{
    int digit=0;
    if(num>0)
    {
        digit = num%10;
        num=(num-digit)/10;
        count++;
        CountOfDigits(num);
    }
    return count;
}






int main()
{
    int var;
    var = CountOfDigits(nmb);
    printf("%d\n", var);
    return 0;
}