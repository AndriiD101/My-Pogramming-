int drop_piece(char board[ROWS][COLS], int col, char player_piece) {
    for (int row = ROWS - 1; row >= 0; row--) {
        if (board[row][col] == '.') {
            board[row][col] = player_piece;
            return row;
        }
    }
    return 0; // Column is full
}
