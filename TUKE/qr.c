#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <stdbool.h> 
#include <math.h>
#include <string.h>

void encode_char(const char character, bool bits[8])
{
    size_t value = 256;
    size_t modChar = (size_t)character;
    for (size_t i = 0; i < 8; i++)
    {
       value = value / 2;
       bits[i] = modChar / value;
       if (bits[i])
            modChar = modChar - value;
    }
} 


char decode_byte(const bool bits[8]) {
    size_t cc = 0;
    for (size_t i = 0; i < 8; i++)
        cc += bits[7 - i] ? pow(2, i) : 0;
    return cc;
}

void encode_string(const char string[], bool bytes[strlen(string)+1][8]) {
    size_t i ;
    size_t length = strlen(string)+1;
        for (i=0; i < length ; i++) encode_char(string[i], bytes[i]);
}
 
void decode_bytes(const int rows, bool bytes[rows][8], char string[rows]) {
    size_t i;
        for (i=0; i < rows; i++) string[i] = decode_byte(bytes[i]);
}
 
void blocks_to_bytes(const int cols, const int offset, bool blocks[offset*8][cols], const int rows, bool bytes[rows][8]) {
    size_t first=0;
    for (; first < offset; first++){
        size_t second=0;
        for (; second < cols; second++){
            size_t third=0;
            for (; third< 8; third++) {
                if (first*cols+second > rows) return;
                bytes[first*cols+second][third] = blocks[first*8+third][second];
            }
        }
    }
}


void bytes_to_blocks(const int cols, const int offset, bool blocks[offset*8][cols], const int rows, bool bytes[rows][8]) {
    size_t first=0;
    for (; first < offset; first++){
        size_t second=0;
        for (; second < cols; second++){
            size_t third=0;
            for (; third < 8; third++) {
                if(first*cols+second < rows) blocks[first*8+third][second] =  bytes[first*cols+second][third];
                else blocks[first*8+third][second] = 0;
            }
        }
    }
}


int main(){   
}
