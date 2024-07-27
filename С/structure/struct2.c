#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    char name[50];
    char id[10];
    int age;
    int grades[5];
}STUDENT;

int main()
{
    STUDENT Andrii;
    Andrii.age = 17;
    printf("age of student Andrii is %d \n", Andrii.age);
}
