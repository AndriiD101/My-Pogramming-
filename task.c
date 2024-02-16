#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

int main()
{
    char token[] = "255";
    int num = atoi(token);
    if(0<num && num<=255){
        printf("%d", num);
    }
    return 0;
}