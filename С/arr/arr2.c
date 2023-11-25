#include <stdio.h>

int main()
{
    int IndexOfMaxNumber, MaxNumber;
    printf("enter the size of the array: ");
    scanf("%d", &size);
    int arr[size];
    for (int i=0; i<size; i++)
    {
        printf("enter the value for %d grade: ", i+1);
        scanf("%d", &arr[i]);

    }
    MaxNumber=arr[0];
    IndexOfMaxNumber=0;
    for(int i=0; i<size; i++)
    {
         if (arr[i]>MaxNumber)
        {
        MaxNumber=arr[i];
        IndexOfMaxNumber=i;
        }
    }
    printf("Max number is: %d, Its index is: %d", MaxNumber, IndexOfMaxNumber);
    return 0;
}