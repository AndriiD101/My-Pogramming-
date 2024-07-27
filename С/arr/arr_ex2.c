#include <stdio.h>

#define size 5
int main()
{
    int arr[size];
    int GreaterSum;
    for(int i=0; i<size; i++)
    {
        printf("Enter value for %d element of array: ", i);
        scanf("%d", &arr[i]);
    }
    for(int i=0; i<size; i++)
    {
        printf("%d ", arr[i]);
    }
    GreaterSum = arr[0] + arr[1];
    printf("\n");
    for(int i=0; i<size-1; i++)
    {
        if(GreaterSum<arr[i]+arr[i+1])
        {
            GreaterSum=arr[i]+arr[i+1];
        }
    }
    printf("%d", GreaterSum);
    return 0;
}