#include <string.h>
#include <stdio.h>

void initialize_board(int rows, int cols, char board[rows][cols])
 {
     for(int i=0;i<rows;i++)
     {
         for(int j=0;j<cols;j++)
         {
             board[i][j]='.';
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
    for(int col=0;col<cols;col++)
      printf("---+");
  printf("\n");
  for(int col=1;col<=cols;col++)
    printf("  %2d",col);
  printf("\n\n");
}

int is_valid_move(int rows, int cols, const char board[rows][cols], int col) {
  if (col < 0 || col >= cols) {
    return 0;
  }
  if (board[rows - 1][col] != '-') {
    return 0;
  }

  return 1;
}


int drop_piece(int rows, int cols, char board[rows][cols], int col, char player_piece) {
  // Check if the column is valid
  if (!is_valid_move(rows, cols, board, col)) {
    return 0;
  }

  int row = rows - 1;
  while (row >= 0 && board[row][col] != '-') {
    row--;
  }

  // Place the player's piece in the empty cell
  board[row][col] = player_piece;

  return row;
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


int check_diagonal(int rows, int cols, const char board[rows][cols], char player) {
  // Check diagonals from top left to bottom right
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      int count = 0;
      for (int k = 0; k < 4; k++) {
        if (board[i + k][j + k] == player) {
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
        if (board[i - k][j + k] == player) {
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
    return (check_vertical(rows, cols, board, row, col, player_piece) 
            ||check_horizontal(rows, cols, board, row, col, player_piece)
            ||check_diagonal(rows, cols, board, player_piece));
}

int is_board_full(int rows, int cols, const char board[rows][cols]) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            if (board[i][j] == ' ') {
                return 0; 
            }
        }
    }
    return 1; 
}

int main()
{
    int rows = 6;
    int cols = 9;
    char board[rows][cols];

    initialize_board(rows, cols, board);

    int player_turn = 1; 

    print_board(rows, cols, board);


    return 0;
}