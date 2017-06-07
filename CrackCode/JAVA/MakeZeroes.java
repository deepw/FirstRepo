/* 
 * 1.1 Write an algorithm such that if an element in an MxN matrix is 0, its entire row and column is set to 0.
 */

public class MakeZeroes {
  public static void main (String args[]) {
    int nrows = Integer.parseInt(args[0]);
    int ncols = (args.length - 1) / nrows;
    System.out.println("Creating a matrix of " + nrows + " X " + ncols);
    int input[][] = new int[nrows][ncols];
    int argint = 1;
    for (int i = 0; i < nrows ; i++) {
      for (int j = 0; j < ncols; j++) {
        input[i][j] = Integer.parseInt(args[argint++]);
      }
    }
    
    printArray(input, nrows, ncols);
    makeZeroes(input, nrows, ncols);
    printArray(input, nrows, ncols);
  }

  private static void printArray(int[][] input, int rows, int cols) {
    for (int i = 0 ; i < rows; i++) {
      for (int j = 0; j < cols; j++) {
        System.out.print(input[i][j]);
        System.out.print("\t");
      }
      System.out.println();
    }
  }

  private static void makeZeroes(int[][] input, int rows, int cols) {
    int rowinfo[] = new int[rows];
    int colinfo[] = new int[cols];

    for (int i = 0 ; i < rows; i++) {
      for (int j = 0; j < cols; j++) {
        if (input[i][j] == 0) {
          rowinfo[i] = 1;
          colinfo[j] = 1;
        }
      }
    }

    for (int i = 0 ; i < rows; i++) {
      for (int j = 0; j < cols; j++) {
        if (rowinfo[i] == 1 || colinfo[j] == 1) {
          input[i][j] = 0;
        }
      }
    }
  }
}

