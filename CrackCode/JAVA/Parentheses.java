/* 8.5 
 * Implement an algorithm to print all valid (e.g., properly opened and closed) combinations
of n-pairs of parentheses.
EXAMPLE:
input: 3 (e.g., 3 pairs of parentheses)
output: ()()(), ()(()), (())(), ((()))
*/

public class Parentheses {
  static void printAll(int N, int open, int close, int index, char[] result) {
    if (index == N*2) {
      System.out.println(result);
      return;
    }
      
    if (open < N) {
      result[index] = '{';
      printAll(N, open+1, close, index+1, result);
    } 
    if (open > close) {
      result[index] = '}';
      printAll(N, open, close+1, index+1, result);
    } 
  }
  
  public static void main (String args[]) {
    char[] str = new char[Integer.parseInt(args[0])*2];
    printAll(Integer.parseInt(args[0]), 0, 0, 0, str); 
  }     
}
