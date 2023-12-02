#include <stdio.h>

int check_diagonal(int rows, int cols, const char board[rows][cols], int row, int col, char player_piece) {
    //left-down to right-upper
    int l_row = row - 1;
    int l_col = col - 1;

    while (l_row >= 0 && l_col >= 0 && board[l_row][l_col] == player_piece) {
        l_row--;
        l_col--;
    }

    int count = 0;
    // Diagonal counting from right-upper to left-down
    for (int r = l_row + 1, c = l_col + 1; r < rows && c < cols; r++, c++) {
        if (board[r][c] != player_piece) {
            break;
        }
        count++;
    }

    if (count >= 4) {
        return 1;
    }

    //left-uppper to right-down
    l_row = row + 1;
    l_col = col - 1;

    while (l_row < rows && l_col >= 0 && board[l_row][l_col] == player_piece) {
        l_row++;
        l_col--;
    }

    count = 0;
    // Diagonal counting from left-upper to right-down
    for (int r = l_row - 1, c = l_col + 1; r >= 0 && c < cols; r--, c++) {
        if (board[r][c] != player_piece) {
            break;
        }
        count++;
    }

    if (count >= 4) {
        return 1;
    }

    return 0;
}

int main() {
    int rows = 4;
    int cols = 7;
    char board[4][7] = {
        {'X', '.', '.', '.', '.', '.', '.'},
        {'O', 'X', '.', '.', '.', '.', '.'},
        {'O', 'O', 'X', '.', '.', '.', '.'},
        {'O', 'O', 'O', 'X', '.', '.', '.'}
    };

    int result = check_diagonal(rows, cols, board, 0, 0, 'X'); // Check diagonals around the last move

    printf("Result: %d\n", result);

    return 0;
}
