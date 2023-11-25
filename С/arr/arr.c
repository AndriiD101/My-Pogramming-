#include <stdio.h>
#include <stdlib.h>

int main()
{
    int size, max_grade;
    printf("enter the size of the array: ");
    scanf("%d", &size);
    int grades[size];
    for (int i=0; i<size; i++)
    {
        printf("enter the value for %d grade: ", i+1);
        scanf("%d", &grades[i]);

    }
    max_grade = grades[0];
    for(int i=0; i<size; i++)
    {
        if (grades[i]>max_grade)
        {
        max_grade=grades[i];
        }
    }
    printf("%d", max_grade);
    return 0;
}