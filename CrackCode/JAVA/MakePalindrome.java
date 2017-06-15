/* Find least characters required to make a string a palindrome */

public class MakePalindrome {
 
  static int findMin(char[] string, int begin, int end) {
    if (begin == end) {
      return 0;
    } 
    if (end == begin + 1) {
      if (string[begin] == string[end]) {
        return 0;
      } else {
        return 1;
      }
    }
    if (string[begin] == string[end]) {
      return findMin(string, begin + 1, end -1);
    } else {
      return 1 + Math.min(findMin(string, begin + 1, end), findMin(string, begin, end - 1)); 
    }
  }

  public static void main (String args[]) {
    System.out.println("Min chars needed for string " + args[0] + " is " + findMin(args[0].toCharArray(), 0, args[0].length() -1));
  }
}

