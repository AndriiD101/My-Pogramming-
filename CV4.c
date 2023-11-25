#include <string.h>
#include <stdio.h>

void get_available_letters(const char letters_guessed[], char available_letters[])
{
    char alphabet[] = "abcdefghijklmnopqrstuvwxyz";
    int len_alphabet = strlen(alphabet);
    int len_letter_guessed = strlen(letters_guessed);

    for (int i = 0; i < len_alphabet; i++)
    {
        available_letters[i] = alphabet[i];
    }
    available_letters[len_alphabet] = '\0';
    for (int i = 0; i < len_letter_guessed; i++) 
    {
        for(int j = 0; j<len_alphabet; j++)
        {
            if (alphabet[j] == letters_guessed[i])
            {
                available_letters[j] = '_';
                break;
            }
        }
    }

    int current_index = 0;
    for (int i = 0; i < len_alphabet; i++)
    {
        if (available_letters[i] != '_')
        {
            available_letters[current_index] = available_letters[i];
            current_index++;
        }
    }
    available_letters[current_index] = '\0';

    for (int i = 0; i < current_index; i++)
    {
        printf("%c", available_letters[i]);
    }
    int avail_len = strlen(available_letters);
    available_letters[avail_len] = '\0';
    printf("\n");
}

int main()
{
    char result[30];
    get_available_letters("arpstxgoieyu", result);
    // result = "bcdfhjklmnqvwz"
    return 0;
}