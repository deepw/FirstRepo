/* 9.3 
Given a sorted array of n integers that has been rotated an unknown number of
times, give an O(log n) algorithm that finds an element in the array. You may assume
that the array was originally sorted in increasing order.
EXAMPLE:
Input: find 5 in array (15 16 19 20 25 1 3 4 5 7 10 14)
Output: 8 (the index of 5 in the array)
*/

public class RotatedArray {

  static int find(int[] array, int start, int end, int value) {
    System.out.println("start = " + start + " end = " + end);
    if (start > end) {
      return -1;
    }
    int mid = (start + end) /2;
    if (value == array[mid]) {
      return mid;
    }
    if (array[start] < array[mid]) {
      if (value <= array[mid]) {
        return find (array, start, mid, value);
      } else {
        return find(array, mid+1, end, value);
      }
    } else {
      if (value <= array[end]) {
        return find(array, mid+1, end, value);
      } else {
        return find(array, start, mid, value);
      }
    }
  }

  public static void main (String args[]) {
     int[] array = {15, 16, 19, 20, 25, 1, 3, 4, 5, 7, 10, 14};
     System.out.println("Found " + args[0] + " at index " + find (array, 0, array.length-1, Integer.parseInt(args[0])));
  }
}
