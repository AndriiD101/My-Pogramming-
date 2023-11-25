#include <stdio.h>
#include <stdlib.h>


int main()
{
    int size, value;
    int flag = 1;
    printf("enter the value for size: ");
    scanf("%d", &size);
    int arr[size];
    for(int i = 0; i<size; i++)
    {
        printf("enter the value for variable value: ");
        scanf("%d", &value);
        arr[i]=value;

    }
    //add numbers to array
     size_t length = sizeof(arr);
     for (int i=0; i<=size-1; i++)
     {
         printf("%d\n", arr[i]);
     }
     //check them if they are progresible or not
     for (int i=0; i<=length-1; i++)
     {
         if (arr[i]<arr[i+1])
         {
             continue;
         }
         else
         {
             flag=0;
             break;
         }
         if (arr[-1]==arr[-1])
         {
             break;
         }
     }
     if (flag==1)
     {
         printf("yes\n");
     }
     else
     {
         printf("no\n");
     }

    return 0;

}
