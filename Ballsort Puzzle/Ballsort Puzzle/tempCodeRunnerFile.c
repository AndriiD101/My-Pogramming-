int is_valid_move(int rows, int cols, const char board[rows][cols], int col) {
    int column = col + 1;
    int colik = col - 1;
    int flag = 0;
    if (col < 0 || col > cols || board[rows][col] == 'X' || board[rows][col] == 'O') {
        flag = 0;
        return 0;
    }

    for (int row = 0; row<rows; row++) {
        if (board[row][col] == '.') {
            flag = 1;
    }
}
    return flag;
}