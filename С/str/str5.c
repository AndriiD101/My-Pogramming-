#include <stdio.h>
#include <stdlib.h>

#define SIZE 100

char *strcpy(char *destination, char *source)
{
    int i=0;
    char *temp;
    temp = destination;
    while(source[i]!='\0')
    {
        destination[i]=source[i];
        i++; 
    }
    destination[i]='\0';
    return temp;
}

int main()
{
    char origin_str[SIZE];
    char cpy_str[SIZE];
    char tmp;
    printf("enter sone text: ");
    gets(origin_str);
    tmp = *strcpy(cpy_str, origin_str);
    printf("from this %s\n", origin_str);
    printf("copied to this %s\n", cpy_str);
    return 0;
}