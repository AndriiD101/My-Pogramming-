#include <stdio.h>

#define ROWS 6
#define COLS 7

void initialize_board_c4(char board[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            board[i][j] = '.';
        }
    }
}

void print_board_c4(const char board[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (j == 0) {
                printf(" |");
            }
            printf(" %c |", board[i][j]);
        }
        printf("\n");
    }
    printf(" +");
    for (int col = 0; col < COLS; col++) {
        printf("---+");
    }
    printf("\n");
    for (int col = 1; col <= COLS; col++) {
        printf("  %2d", col);
    }
    printf("\n\n");
}

int is_valid_move_c4(const char board[ROWS][COLS], int col) {
    if (col < 0 || col >= COLS) {
        return 0;
    }
    if (board[ROWS - 1][col] != '.') {
        return 0;
    }
    return 1;
}

int drop_piece_c4(char board[ROWS][COLS], int col, char player_piece) {
    for (int row = ROWS - 1; row >= 0; row--) {
        if (board[row][col] == '.') {
            board[row][col] = player_piece;
            return row;
        }
    }
    return -1; // Column is full
}

int check_vertical_c4(const char board[ROWS][COLS], int row, int col, char player_piece) {
    int count = 0;
    for (int i = 0; i < ROWS; ++i) {
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

int check_horizontal_c4(const char board[ROWS][COLS], int row, int col, char player_piece) {
    int count = 0;
    for (int j = 0; j < COLS; ++j) {
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

int check_diagonal_c4(const char board[ROWS][COLS], char player_piece) {
    // Check diagonals from top left to bottom right
    for (int i = 0; i < ROWS - 3; i++) {
        for (int j = 0; j < COLS - 3; j++) {
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
    for (int i = ROWS - 1; i >= 3; i--) {
        for (int j = 0; j < COLS - 3; j++) {
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

int check_win_c4(const char board[ROWS][COLS], int row, int col, char player_piece) {
    return (check_vertical_c4(board, row, col, player_piece) ||
            check_horizontal_c4(board, row, col, player_piece) ||
            check_diagonal_c4(board, player_piece));
}

int is_board_full_c4(const char board[ROWS][COLS]) {
    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COLS; ++j) {
            if (board[i][j] == '.') {
                return 0;
            }
        }
    }
    return 1;
}

int main() {
    char board[ROWS][COLS];
    int col;

    initialize_board_c4(board);
    int player_turn = 1;
    char player_piece = 'X';

    while (1) {
        // Print the board
        print_board_c4(board);

        // Prompt the user to enter the column number (starting from 1)
        printf("Enter the column number (1-7): ");
        scanf("%d", &col);

        // Subtract 1 from the input to adjust it to the array index
        col--;

        // Validate the column number
        if (col < 0 || col >= COLS) {
            printf("Invalid column number. Please enter a value between 1 and 7.\n");
            continue;
        }

        // Drop the piece and get the row where it was placed
        int row = drop_piece_c4(board, col, player_piece);

        // Check if the piece was placed successfully
        if (row == -1) {
            printf("Column is full. Please choose another column.\n");
        }

        // Check for a win
        if (check_win_c4(board, row, col, player_piece)) {
            print_board_c4(board);
            printf("Player %d wins!\n", player_turn);
            return 0;
        }

        // Switch to the next player
        player_turn = 3 - player_turn; // Toggle between players 1 and 2
        player_piece = (player_piece == 'X') ? 'O' : 'X';

        // Check for a tie
        if (is_board_full_c4(board)) {
            print_board_c4(board);
            printf("The game is a tie!\n");
            return 0;
        }
    }

    return 0;
}
