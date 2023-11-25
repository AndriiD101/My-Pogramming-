#include <string.h>
#include <stdio.h>
#include <stdlib.h>

int is_whites(const char c)
{
    if(c == ' ' || c == '\t' || c == '\n')
    {
        return 1;
    }
    return 0;
}

void change_whites(char string[])
{
    for(int i = 0; i < strlen(string); i++)
    {
        if(string[i] == ' ' || string[i] == '\n')
        {
            string[i] = '.';
        }
    }
}

int guess_evaul(const int guess, const int my_number)
{
    if(guess == my_number)
    {
        return 1;
    }
    else if(guess < my_number)
    {
        return 2;
    }
    else
    {
        return 0;
    }
}

int leap_year(const int year)
{
    if(year<1 && year<4443)
    {
        return -1;
    }
    if(year % 400 == 0)
    {
        return 1;
    }
    else if(year % 100 == 0)
    {
        return 0;
    }
    else if(year % 4 == 0)
    {
        return 1;
    }
    return 0;
}

int count_positives(const int size, const int array[])
{
    int flag = 0;
    if(array == NULL)
    {
        return -1;
    }
    for(int i=0; i<size; i++)
    {
        if(array[i]>0)
        {
            flag ++;
        }
    }
    return flag;
}

int count_whites(const char string[])
{
    int count = 0;
    for(int i = 0; i < strlen(string); i++)
    {
        if (string[i] == ' ' || string[i] == '\n' || string[i] == '\t') 
        {
            count++;
        }
    }
    return count;
}

int direction_correction(const int degree)
{
    
}

int main()
{
    printf("%d %d \n", is_whites('0'), is_whites(' '));
    ////////////////////////////////////////////////////////////////
    char string[100] = "Hello world";
    change_whites(string);
    printf("%s\n", string);
    ////////////////////////////////////////////////////////////////
    printf("%d %d %d\n", guess_evaul(34, 22), guess_evaul(22, 34), guess_evaul(34,34));
    ////////////////////////////////////////////////////////////////
    printf("%d %d %d\n", leap_year(4000), leap_year(3000), leap_year(3004));
    ////////////////////////////////////////////////////////////////
    const int array1[] = {1,2,0,3,4,0};
    const int array2[] = {1,2,6,3,4,7};
    const int array3[] = {-1,-2,0,-3,0,-2};
    printf("%d %d %d\n", count_positives (6, array1), count_positives (6, array2), count_positives (6, array3));
    ////////////////////////////////////////////////////////////////
    const char string2[] = "Hello, how are you?\n";
    printf("%d\n", count_whites(string2));
    ////////////////////////////////////////////////////////////////

    return 0;
}