#include <stdio.h>

#define size 6

int main()
{
    int arr[size];
    int flag=1;
    int i=0;
    for(int i=0; i<size; i++)
    {
        printf("Enter value for %d element of array: ", i);
        scanf("%d", &arr[i]);
    }

    do
    {
        if(arr[i]==arr[-i])
        {
            flag=1;
        }
        else
        {
            flag=0;
        }
    }while(i!=0);

    if(flag==1)
    {
        printf("array is polindrom\n");
    }
    else
    {
        printf("array is NOT polindrom\n");
    }
}