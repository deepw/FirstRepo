/* 
You are given an array of integers (both positive and negative). Find the continuous
sequence with the largest sum. Return the sum.
EXAMPLE
Input: {2, -8, 3, -2, 4, -10}
Output: 5 (i.e., {3, -2, 4} )
*/

public class LargestSum {

  static int findSum(int[] array) {
    int max = 0;
    int sum = 0;
    for (int i = 0; i < array.length; i++) {
      sum += array[i];
      max = Math.max(sum, max);
      if (sum < 0) {
        sum = 0;
      }
    }
    return max;
  }

  public static void main (String args[]) {
    int[] array = {2, -8, 3, -2, 4, -10};
    System.out.println("Largest sum is " + findSum(array));
  }
}

