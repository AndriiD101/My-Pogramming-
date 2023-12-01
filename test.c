#include <stdio.h>

int drop_piece(int rows, int cols, char board[rows][cols], int col, char player_piece) {
    int column = col - 1;
    if (column < 0 || column >= cols) {
        return -1; // Invalid column number
    }
    int row = rows - 1;
    while (row >= 0 && board[row][column] != '.') {
        row--;
    }
    if (row < 0) {
        return -1; // Column is full
    }
    board[row][column] = player_piece; // Place the player's piece in the found row
    return row;
}

int main() {
    // Example usage
    const int rows = 10;
    const int cols = 10;
    char board[rows][cols];

    // Initialize the board with dots (representing empty spaces)
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            board[i][j] = '.';
        }
    }

    // Example usage of drop_piece function
    int result = drop_piece(8, cols, board, 5, 'X'); // Drop 'X' in column 5

    // Display the resulting board
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }

    // Display the result of drop_piece function
    if (result >= 0) {
        printf("Ring successfully placed in row %d\n", result);
    } else if (result == -1) {
        printf("Invalid column number or column is full\n");
    } else {
        printf("Failed to place the ring\n");
    }

    return 0;
}
