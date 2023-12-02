#include <string.h>
#include <stdio.h>
//#include "c4.h"

void initialize_board(int rows, int cols, char board[rows][cols]) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            board[i][j] = '.';
        }
    }
}

void print_board(int rows, int cols, const char board[rows][cols]) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (j == 0) {
                printf(" |");
            }
            printf(" %c |", board[i][j]);
        }
        printf("\n");
    }
    printf(" +");
    for (int col = 0; col < cols; col++) {
        printf("---+");
    }
    printf("\n");
    for (int col = 1; col <= cols; col++) {
        printf("  %2d", col);
    }
    printf("\n\n");
}

int is_valid_move(int rows, int cols, const char board[rows][cols], int col) {
    if (col < 0 || col >= cols) {
        return 0;  // Invalid column
    }
else{
    for (int row = rows - 1; row >= 0; row--) {
        if (board[row][col] == '.') {
            return 1;  // Valid move
        } else if (row == 0) {
            return 0;  // Column is full
        }
    }
}
    return 0;  // Default case (should not reach here)
}


int drop_piece(int rows, int cols, char board[rows][cols], int col, char player_piece) {
    int column = col - 1;
    if (column < 0 || column >= cols) {
        return 0;
    }
    for (int row = rows - 1; row >= 0; row--) {
        if (board[row][column] == '.') {
            board[row][column] = player_piece;
            return row;
        }
    }
    return 0;
}

int drop_piece_c4(int rows, int cols, char board[rows][cols], int col, char player_piece) {
    if (col < 0 || col >= cols) {
        return 0;
    }
    
    for (int row = rows - 1; row >= 0; row--) {
        if (board[row][col] == '.') {
            board[row][col] = player_piece;
            return row+1;
        }
    }
    return 0;
}

int check_vertical(int rows, int cols, const char board[rows][cols], int row, int col, char player_piece) {
    int count = 0;
    for (int i = 0; i < rows; ++i) {
        if (board[i][col] == player_piece) {
            count++;
            if (count == 4) {
                return 1;
            }
        } else {
            count = 0;
        }
    }
    return 0;
}

int check_horizontal(int rows, int cols, const char board[rows][cols], int row, int col, char player_piece) {
    int count = 0;
    for (int j = 0; j < cols; ++j) {
        if (board[row][j] == player_piece) {
            count++;
            if (count == 4) {
                return 1;
            }
        } else {
            count = 0;
        }
    }
    return 0;
}

int check_diagonal(int rows, int cols, const char board[rows][cols], char player_piece) {
    // Check diagonals from top left to bottom right
    for (int i = 0; i < rows - 3; i++) {
        for (int j = 0; j < cols - 3; j++) {
            int count = 0;
            for (int k = 0; k < 4; k++) {
                if (board[i + k][j + k] == player_piece) {
                    count++;
                } else {
                    count = 0;
                }
                if (count == 4) {
                    return 1;
                }
            }
        }
    }

    // Check diagonals from bottom left to top right
    for (int i = rows - 1; i >= 3; i--) {
        for (int j = 0; j < cols - 3; j++) {
            int count = 0;
            for (int k = 0; k < 4; k++) {
                if (board[i - k][j + k] == player_piece) {
                    count++;
                } else {
                    count = 0;
                }
                if (count == 4) {
                    return 1;
                }
            }
        }
    }

    return 0;
}

int check_win(int rows, int cols, const char board[rows][cols], int row, int col, char player_piece) {
    return (check_vertical(rows, cols, board, row, col, player_piece) ||
            check_horizontal(rows, cols, board, row, col, player_piece) ||
            check_diagonal(rows, cols, board, player_piece));
}

int is_board_full(int rows, int cols, const char board[rows][cols]) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            if (board[i][j] == '.') {
                return 0;
            }
        }
    }
    return 1;
}

void play_connect4_game(int rows, int cols) {
    char board[rows][cols];
    int col;

    initialize_board(rows, cols, board);
    int player_turn = 1;
    char player_piece = 'X';

    while (1) {
        print_board(rows, cols, board);
        printf("Player %d, enter the column number (1-%d): ", player_turn, cols);
        scanf("%d", &col);
        col--;
        if (!is_valid_move(rows, cols, board, col)) {
            printf("Invalid column number or column is full. Please choose another column.\n");
            continue;
        }
        int row = drop_piece_c4(rows, cols, board, col, player_piece);
        if (!is_valid_move(rows, cols, board, col)) {
            printf("Column is full. Please choose another column.\n");
            continue;
        }
        if (check_win(rows, cols, board, row, col, player_piece)) {
            print_board(rows, cols, board);
            printf("Player %d wins!\n", player_turn);
            return;
        }
        player_turn = 3 - player_turn;
        player_piece = (player_piece == 'X') ? 'O' : 'X';

        
        if (is_board_full(rows, cols, board)) {
            print_board(rows, cols, board);
            printf("The game is a tie!\n");
            return;
        }
    }
}

int main() {
    int rows = 6;
    int cols = 7;
    play_connect4_game(rows, cols);
    return 0;
}

