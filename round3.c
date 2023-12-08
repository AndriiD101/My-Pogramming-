#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int max_2d(const int size, const int array[][size])
{
    int max = 0;
    if(array == NULL) return -1;

    for(int row = 0; row < size; row++){
        for(int col = 0; col < size; col++){
            if(array[row][col] > max)
            {
                max = array[row][col];
            }
        }
    }
    return max;
}

int vowel_count_2d(const int row, const int col, char string[][col])
{
    if(string == NULL) return -1;
    int count = 0;
    for(int l_row = 0; l_row < row; l_row++)
    {
        for(int l_col = 0; l_col < col; l_col++)
        {
            if(tolower(string[l_row][l_col]) == 'a' || tolower(string[l_row][l_col]) == 'e' || tolower(string[l_row][l_col]) == 'i' || tolower(string[l_row][l_col]) == 'o' || tolower(string[l_row][l_col]) == 'u'|| tolower(string[l_row][l_col]) == 'y')
            {
                count++;
            }
        }
    }
    return count;
}

int is_in_array_2d(const int num, const int size,int array[][size])
{
    if(array == NULL) return -1;
    int flag = 0;
    for(int row; row < size; row++) {
    
    }
}

int main()
{
    int array[2][2]={{1, 2},
                     {10, -3}
                    };
    printf("%d\n", max_2d(2, array));
    printf("----------------------------------------------------------------\n");
    char string[3][50] ={"hello WORLD", "aHOJ", "Ahoj"};
    printf("%d\n", vowel_count_2d(3, 50, string));
    return 0;
}