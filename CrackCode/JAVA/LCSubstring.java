public class LCSubstring {

  static int LCS(char[] str1, char[]str2, int m, int n) {
    int[][] DP = new int[m+1][n+1];
    int max = 0;

    for (int i = 0; i <= m; i++) {
      for (int j = 0; j <= n; j++) {
        if (i == 0 || j == 0) {
          DP[i][j] = 0;
        } else if (str1[i] == str2[j]) {
          DP[i][j] = DP[i-1][j-1] + 1;
          max = Math.max(DP[i][j], max);
        } else {
          DP[i][j] = 0;
        }
      }
    }
    return max;
  }

  public static void main (String args[]) {
    System.out.println(LCS(args[0].toCharArray(), args[1].toCharArray(), args[0].length()-1, args[1].length()-1));
  }
}
