int drop_piece(int rows, int cols, char board[rows][cols], int col, char player_piece) {
  int res = 0;

  if(col < 0|| col >= cols) {
    return 0;
  }
  for(int i = rows -1; 0<=rows; rows++)
  {
    if(board[i][col] == '.')
    {
      res=rows;
      board[i][col] = player_piece;
      return res;
    }
  }
  return 0;
}