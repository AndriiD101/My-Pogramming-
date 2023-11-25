#include <stdio.h>

#define size 5

int main()
{
    int arr[size];
    int i=0;
    int FlagForVSorted = 1, FlagForSorted = 1;
    for(int i=0; i<size; i++)
    {
        printf("Enter value for %d element of array: ", i);
        scanf("%d", &arr[i]);
    }
    for(int i=0; i<size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
    //for verysorted array
    
    for(i=0; i<size-1; i++)
    {
        if(arr[i+1]<arr[i])
        {
            FlagForVSorted=0;
            break;
        }
    }

    //for sorted array
    for(i=0; i<size-1; i++)
    {
        if(arr[i]==arr[i+1])
        {
            FlagForSorted=0;
            break;
        }
    }

    //print rasult
    if (FlagForVSorted==1 && FlagForSorted==1)
    {
        printf("very sorted");
    }

    else if (FlagForSorted==0)
    {
        printf("just sorted");
    }

    else
    {
        printf("this array is not sorted at all");
    }
    
    return 0;
}