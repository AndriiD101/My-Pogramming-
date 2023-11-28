#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <ctype.h>


void generator(const int rows, const int columns, char field[rows][columns]) {
    char space = ' ';
    char available[] = {'@', '#', '*', '$', '%', '&', '>', '~', '<', '%', '^', '+', '=', '?'};

    srand(time(NULL));

    int collector = rows; // Количество повторений символов
    

    int nullcol = rand() % columns;
    int nullcol2 = rand() % columns;
    
    // GENERATE 2 EMPTY COLUMNS
    while (nullcol == nullcol2) {
        nullcol2 = rand() % columns;
    }

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            field[i][j] = space;
        }
    }
    // GENERATE STRUCTURED SIMBOLS
    for (int i = 0; i < columns; i++) {
        if (i != nullcol && i != nullcol2) {
            collector = rows;
            for (int j = 0; j < collector; j++) {
                field[j][i] = available[i];
            }
        }
    }

    int x, y, z;
    char temp[rows][columns];

    for(int x = 0; x < rows; x++) {
        if (x != nullcol && x != nullcol2){
            for(y = 0; y < columns; y++) {
                temp[y][x] = field[x][y];
            }
        }
    }

    for(x = 0; x < rows; x++) {
        if(x != nullcol && x != nullcol2){
        z = rand() % rows;
        for(y = 0; y < columns; y++) {
            temp[x][y] = field[z][y];    
        }
    }
    
    }
}
int main() {
    int rows = 10;
    int columns = 9;
    char field[rows][columns];
    generator(rows, columns, field);

    // Вывод результатов
    for (int i = 0; i < rows; i++) {
        printf("%d |", i + 1);
        for (int j = 0; j < columns; j++) {
            printf(" %c |", field[i][j]);
        }
        printf("\n");
    }
    printf("   ");

    for (int i = 0; i < columns; i++) {
        printf("--- ");
    }

    printf("\n");
    printf("   ");

    for (int i = 0; i < columns; i++) {
        printf(" %d  ", i + 1);
    }
}