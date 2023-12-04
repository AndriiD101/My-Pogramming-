#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <math.h>
#include <stdbool.h>

void encode_char(const char character, bool bits[8])
{
    int letter_ascii = character;
    for(int div = 7; div >= 0; div--)
    {
        if(letter_ascii%2 == 0){
            bits[div] = letter_ascii%2;
            letter_ascii/=2;
        }
        else {
            bits[div] = letter_ascii%2;
            letter_ascii/=2;
        }
    }
}

char decode_byte(const bool bits[8])
{
    int result_ascii=0;
    int mid;
    for(int i=8; i>0; i--)
    {
        mid = pow(2, 8-i) * bits[i-1];
        result_ascii += mid;
    }
    return result_ascii;
}

void encode_string(const char string[], bool bytes[strlen(string)+1][8])
{
    char string_element;
    int letter_ascii;
    for(int elm = 0; elm < strlen(string); elm++)
    {
        string_element = string[elm];
        int letter_ascii = string_element;
        for(int div = 7; div >= 0; div--)
        {
        if(letter_ascii%2 == 0){
            bytes[elm][div] = letter_ascii%2;
            letter_ascii/=2;
        }
        else {
            bytes[elm][div] = letter_ascii%2;
            letter_ascii/=2;
        }
        }
    }
    for(int i = 0; i < 8; i++)
    {
        bytes[strlen(string)][i] = 0;
    }
}

void decode_bytes(const int rows, bool bytes[rows][8], char string[rows])
{
    int result_ascii=0;
    int mid;
    char ch;
    for(int i = 0; i < rows; i++)
    {
        for(int j=8; j>0; j--)
        {
            mid = pow(2, 8-j) * bytes[i][j-1];
            result_ascii += mid;
        }
        ch = result_ascii;
        string[i] = ch;
        result_ascii = 0;
    }
}



int main()
{
    bool bits1[8];
    encode_char('B', bits1);
    for(int i = 0; i < 8; i++){
    printf("%d", bits1[i]);
    }
    printf("\n");
    // prints: 01000001

    bool bits2[8] = {0,1,0,0,0,0,1,0};
    printf("%c\n", decode_byte(bits2));
    // prints: A
    char* text = "Hello, how are you?";
    const int len = strlen(text);
    bool bytes1[len+1][8];
    encode_string(text, bytes1);
    for(int j = 0; j <= len; j++){
    printf("%c: ", text[j]);
    for(int i = 0; i < 8; i++){
        printf("%d", bytes1[j][i]);
    }
    printf("\n");
    }
    // prints:
    // H: 01001000
    // e: 01100101
    // l: 01101100
    // l: 01101100
    // o: 01101111
    // ,: 00101100
    //  : 00100000
    // h: 01101000
    // o: 01101111
    // w: 01110111
    //  : 00100000
    // a: 01100001
    // r: 01110010
    // e: 01100101
    //  : 00100000
    // y: 01111001
    // o: 01101111
    // u: 01110101
    // ?: 00111111
    // : 00000000

    bool bytes2[7][8] = {
    {0,1,0,0,1,0,0,0},
    {0,1,1,0,0,1,0,1},
    {0,1,1,0,1,1,0,0},
    {0,1,1,0,1,1,0,0},
    {0,1,1,0,1,1,1,1},
    {0,0,1,0,0,0,0,1},
    {0,0,0,0,0,0,0,0}
};
char string[7];
decode_bytes(7, bytes2, string);
printf("%s\n", string);
// prints: Hello!
    return 0;
}