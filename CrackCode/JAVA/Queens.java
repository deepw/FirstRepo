/* 8.8 
Write an algorithm to print all ways of arranging eight queens on a chess board so
that none of them share the same row, column or diagonal.
*/

public class Queens {
  static boolean placeQueens(int placed, int N, int[][] board) {
    if (placed == N) {
      System.out.println("This works");
      return true;
    }
    for (int i = 0; i < N; i++) {
      for (int j = 0; j < N; j++) {
        if (isPlaceable(board, i, j)) {
          board[i][j] = 1;
          if (!placeQueens(placed+1, N, board)) {
            board[i][j] = 0;
          } else {
            return true;
          }
        }
      }
    }
    return false;
  }

  static boolean placeQueens2(int rows, int placed, int[] cols) {
    if (placed == rows) {
      // solved
      return true;
    }
 
    for (int col = 0; col < rows; col++) {
      if (isSafe(col, cols)) {
        cols[placed] = col;
        if (placeQueens2(rows, placed+1, cols )) {
          return true;
        }
    }
  }
}

