#include <stdio.h>
#include <stdlib.h>

int EvenOrOddNumber(number1, number2)
{
    if (number1%2==0 && number2%2==0)
    {
        return "num1 and num2 are even";
    }
    else if (number1%2==0 && number2%2!=0)
    {
        return "num1 is even and num2 is odd";
    }
    else if (number1%2!=0 && number2%2==0)
    {
        return "num1 is odd and num2 is even";
    }
    else
    {
        return "num1 and num2 are odd";
    }

    
}


int main()
{
    int num1, num2, result;
    printf("enter any two numbers: ");
    scanf("%d %d", &num1, &num2);
    result=EvenOrOddNumber(num1, num2);
    printf("%s", result);

    return 0;
}
