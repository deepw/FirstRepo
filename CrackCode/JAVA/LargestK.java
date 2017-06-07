/* 20.6
Describe an algorithm to find the largest 1 million numbers in 1 billion numbers. Assume
that the computer memory can hold all one billion numbers.
*/
import java.util.*;
public class LargestK {

  static void printKLargest(int array[], int K) {
    PriorityQueue<Integer> pq = new PriorityQueue<Integer>(K);
    for (int i : array) {
      pq.offer(i);
      if (pq.size() > K) {
        pq.poll();
      }
    }
    for (int i = 0; i < K ; i++) {
      System.out.println(pq.poll());
    }
  }

  public static void main (String args[]) {
    int array[] = {1, 5, 3, 4, 8, 7, 2, 10, 51};
    printKLargest(array, 3);
  }
}
    
        

