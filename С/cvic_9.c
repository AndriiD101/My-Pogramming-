#include <stdio.h>
#include <stdlib.h>

void draw(const int size, char field[][size]);
int add_cross(const int size, char field[][size], const int x, const int y, const char player);
int is_solved(const int size, char field[][size]);

int main() {
    
    int size;

    do {
        printf("Enter the size of field: ");
        scanf("%d", &size);
    } while (size < 4 || size > 9);

    char field[size][size];

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            field[i][j] = ' '; 
        }
    }
    draw(size, field);

    char player = 'B';

    for (; is_solved(size, field) == 0;) {
        player = player == 'A' ? 'B' : 'A';
        printf("Player %c: ", player);

        int x, y;
        scanf("%d %d", &x, &y);

        int cross = add_cross(size, field, x, y, player);

        if (cross == -1) {
            printf("Wrong position!\n");
            continue;
        } else if (cross == 0) {
            printf("X | O is already there!\n");
            continue;
        }
        draw(size, field);
        
    }

    printf("Player %c wins!\n", player);

}

void draw(const int size, char field[][size]) {
    printf("\n");
    printf("  +");

    for (int i = 0; i < size; i++) {
        printf("-+");
    }

    printf("\n");

    for (int j = size; j > 0; j--) { {
        printf("%d |", j);
        for (int i = 0; i < size; i++)
            printf("%c|", field[size - j][i]);
        }
        printf("\n");
        printf("  +");

        for (int i = 0; i < size; i++) {
            printf("-+");
        }
        printf("\n");
    }


    printf("  ");
    for (int i = 1; i <= size; i++) {
        printf(" %d", i);
    }

    printf("\n");
}

int add_cross(const int size, char field[][size], const int x, const int y, const char player) {
    if (size < x || x < 1 || size < y || y < 1) {
        return -1;
    }

    char c = player == 'A' ? 'X' : 'O';

    if (field[size - y][x - 1] == c) {
        return 0;
    }

    field[size - y][x - 1] = c;
    return 1;
}

int is_solved(const int size, char field[][size]) {
    for (int i = 0; i < size - 2; i++) {
        if (field[i] == 'X' && field[i + 1] == 'X' && field[i + 2] == 'X') {
            return 1;
        }
    }
    return 0;
}