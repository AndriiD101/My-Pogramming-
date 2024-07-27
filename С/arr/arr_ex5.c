#include <stdio.h>
//#define size 5

void ResetArray(int *array, int size)
{
    for(int i=0; i<size; i++)
    {
        array[i]=0;
    }
    for(int i=0; i<size; i++)
    {
        printf("%d", array[i]);
    }
}

int main()
{
    int size = 5;
    int arr[size];
    for(int i=0; i<size; i++)
    {
        printf("enter the %d element of the array: ", i);
        scanf("%d", &arr[i]);
    }

    ResetArray(arr, size);

}