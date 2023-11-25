#include <stdio.h>



int SumOfElements(int *array, int size)
{
    int sum=0;
    for(int i=0; i<size; i++)
    {
        sum=sum+array[i];
    }
    return sum;
}

int main()
{
    int size = 5;
    int arr[size];
    int sumofarray;
    for(int i=0; i<size; i++)
    {
        printf("enter the %d element of the array: ", i);
        scanf("%d", &arr[i]);
    }
    sumofarray=SumOfElements(arr, size);
    printf("%d", sumofarray);

}