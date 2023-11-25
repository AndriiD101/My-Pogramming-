#include <stdio.h>
#include <stdlib.h>

int main()
{

    int count=0, sum_of_grades=0;
    int grades;
    printf("If you want to exit enter to the field value that equals to -1\n");

    do {
        printf("enter your grade\n>>>: ");
        scanf("%d", &grades);
        sum_of_grades=sum_of_grades+grades;
        count++;
    }while (grades!=-1);
    /**if (grades == -1)
    {
        count=count-1;
    }**/
    printf("your average grade is %.3f\n", (float)sum_of_grades/count);
    return 0;
}
