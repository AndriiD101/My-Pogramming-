#include <stdio.h>

void swap(int *a, int *b)
{
    int tmp;
    tmp = *a;
    *a=*b;
    *b=tmp;
}

int main()
{
    int num1 = 5, num2 = 7;
    printf("%d, %d\n", num1, num2);
    swap(&num1, &num2);
    printf("%d, %d\n", num1, num2);

}