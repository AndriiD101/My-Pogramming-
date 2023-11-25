#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define SIZE 100

int main()
{
    char str[SIZE];
    int space_counter=0, i=0;
    printf("enter some text: ");
    gets(str);

    while(str[i]!='\0')
    {
        if(str[i]==' ')
        {
            space_counter++;
        }
        if(str[i]==' ' && str[i+1]==' ')
        {
        space_counter--;
        }
        i++;
    }


    printf("words in that text is: %d", space_counter);
    return 0;
}