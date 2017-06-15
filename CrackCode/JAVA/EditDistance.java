/* Find the Edit Distance between two strings */

public class EditDistance {

  static int getDistance(char[] a, char[] b, int m, int n) {
    if (m == -1 && n == -1) {
      return 0;
    } else if (m == -1) {
      return n+1;
    } else if (n == -1) {
      return m+1;
    }
    if (a[m] == b[n]) {
      return getDistance(a, b, m-1, n-1);
    } else {
      return 1 + Math.min(getDistance(a, b, m-1, n), Math.min(getDistance(a, b, m, n-1), getDistance(a, b, m-1, n-1)));
    }
  }

  public static void main (String args[]) {
    System.out.println("Edit distance between " + args[0] + " and " + args[1] + 
        " is " + getDistance(args[0].toCharArray(), args[1].toCharArray(), args[0].length()-1, args[1].length()-1));
  }
  }
