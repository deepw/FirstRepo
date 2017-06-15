public class LongestPalindromeSub {
  
  static int findLongest(char[] string, int begin, int end) {
    if (begin == end) {
      return 1;
    }
    if (begin == end - 1) {
      if (string[begin] == string[end]) {
        return 2;
      } 
    }

    if (string[begin] == string[end]) {
      return 2 + findLongest(string, begin+1, end-1);
    } else {
      return Math.max(findLongest(string, begin+1, end), findLongest(string, begin, end-1));
    }
  }

  static int findLongestOpt(char[] string, int begin, int end) {
    if (begin == end) return 1;
    int[][] DP = new int[end+1][end+1];
    for (int i = 0; i<= end; i++) {
      DP[i][i] = 1;
    }

    for (int gap=1; gap <= end; gap++) {
      for (int i = 0, j = gap; j <= end; i++, j++) {
        if (string[i] == string[j]) {
          DP[i][j] = 2 + DP[i+1][j-1];
        } else {
          DP[i][j] = Math.max(DP[i+1][j], DP[i][j-1]);
        }
      }
    }
    return DP[0][end];
  }

  public static void main (String args[]) {
    System.out.println("Longest palindromic subsequence in the string " + args[0] 
                       + " is of length " + findLongest(args[0].toCharArray(), 0, args[0].length() - 1));
    System.out.println("Optimized Longest palindromic subsequence in the string " + args[0] 
                       + " is of length " + findLongestOpt(args[0].toCharArray(), 0, args[0].length() - 1));
  }
} 

