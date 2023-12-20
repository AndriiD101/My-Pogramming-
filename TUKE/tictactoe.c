#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void draw(const int size, char field[][size]);
int is_solved(const int size, char field[][size]);
int add_cross(const int size, char field[][size], const int x, const int y, const char player);

int main(){
    int size;

    do{
        printf("Enter the size of field: ");
        scanf("%d", &size);
    } while(size < 4 || size > 9);

    char field[size][size];
    for(int y = 0; y < size; y++){
        for(int x = 0; x < size; x++){
            field[y][x] = ' ';
        }
    }
    draw(size, field);

    char player = 'B';
    while( !is_solved(size, field) ){
        player = (player == 'A') ? 'B' : 'A';
        printf("Player %c: ", player);

        int x, y;
        scanf("%d %d", &x, &y);

        int cross = add_cross(size, field, x, y, player);

        if( cross == -1 ){
            printf("Wrong position!\n");
            continue;
        }
        else if( cross == 0 ){
            printf("X is already there!\n");
            continue;
        }

        draw(size, field);
    }

    printf("Player %c wins!\n", player);

    return EXIT_SUCCESS;
}

int add_cross(const int size, char field[][size], const int x, const int y, const char player){
    if(x < 1 || y < 1 || x > size || y > size){
        return -1;
    }

    if(field[size-y][x-1] == 'X' || field[size-y][x-1] == 'O'){
        return 0;
    }

    field[size-y][x-1] = (player == 'A') ? 'X' : 'O';
    return 1;
}

int is_solved(const int size, char field[][size]){
    for(int y = 0; y < size-2; y++){
        for(int x = 0; x < size-2; x++){
            char tmp = field[y][x];
            if(tmp == ' '){
                continue;
            }
            // horizontal check
            if(field[y][x+1] == tmp && field[y][x+2] == tmp){
                return 1;
            }
            // vertical check
            if(field[y+1][x] == tmp && field[y+2][x] == tmp){
                return 1;
            }
            // diagonal 1
            if(field[y+1][x+1] == tmp && field[y+2][x+2] == tmp){
                return 1;
            }
        }
    }
    // diagonal 2
    for(int y = 2; y < size; y++){
        for(int x = 0; x < size-2; x++){
            char tmp = field[y][x];
            if(tmp == ' '){
                continue;
            }
            if(field[y-1][x+1] == tmp && field[y-2][x+2] == tmp){
                return 1;
            }
        }
    }

    return 0;
}

void draw(const int size, char field[][size]){
    printf("\n");

    printf("  +");
    for(int i = 0; i < size; i++){
        printf("-+");
    }
    printf("\n");

    for(int j = size; j > 0; j--){
        printf("%d |", j);
        for(int i = 0; i < size; i++){
            printf("%c|", field[size-j][i]);
        }
        printf("\n");

        printf("  +");
        for(int i = 0; i < size; i++){
            printf("-+");
        }
        printf("\n");
    }

    printf("  ");
    for(int i = 0; i < size; i++){
        printf(" %d", i+1);
    }

    printf("\n\n");
}

