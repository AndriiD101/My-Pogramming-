#include <stdio.h>
#include <stdlib.h>


#define nmb 9
int DigitSum=0;

int sum_of_digits(int num)
{
    int digit=0;
    if(num>0)
    {
        digit = num%10; // 1
        //printf("tmp %d\n", digit);
        DigitSum=DigitSum+digit; //DigitSum = 1+3 = 4
        //printf("DigitSum %d\n", DigitSum);
        num=(num-digit)/10;
        //printf("Num %d\n", num);
        sum_of_digits(num);
    }

    return DigitSum;
}

int main()
{
    int var;
    var=sum_of_digits(nmb);
    printf("sum of numbers %d\n", var);
    return 0;
}