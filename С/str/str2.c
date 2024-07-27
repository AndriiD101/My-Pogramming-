#include <stdio.h>

int main()
{
    int counter=0, i=0, chAr; 
    char str[20];
    printf("enter something in this line: ");
    gets(str);
    while(chAr != '\0')
    {
        chAr=str[i];
        i++;
        counter++;
    }
    printf("%d", counter-1);
}