#include <stdio.h>
#include <stdlib.h>

#define SIZE 100

int strlen(char *str);


int main()
{
    char something[SIZE];
    int temp;
    printf("enter some text: ");
    gets(something);

    temp = strlen(something);

    printf("%d\n", temp);
    return 0;
}

int strlen(char *str)
{
    int i=0;
    while(str[i]!='\0')
    {
        i++;
    }
    return i;
}
