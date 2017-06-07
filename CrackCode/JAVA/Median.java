/* 20.9 Numbers are randomly generated and passed to a method. Write a program to find
and maintain the median value as new values are generated.
*/
import java.util.*;
public class Median {
  PriorityQueue<Integer> lessQ;
  PriorityQueue<Integer> moreQ;

  Median() {
    lessQ = new PriorityQueue<Integer>(10, Collections.reverseOrder());
    moreQ = new PriorityQueue<Integer>();
  }

  void add(int newValue) {
    float median = getMedian();
    if (newValue > median) {
      if (moreQ.size() > lessQ.size()) {
        lessQ.offer(moreQ.poll());
      }
      moreQ.offer(newValue);
    } else {
      if (lessQ.size() > moreQ.size()) {
        moreQ.offer(lessQ.poll());
      }
      lessQ.offer(newValue);
    }
  }

  float getMedian() {
    float min = lessQ.size() > 0 ? lessQ.peek() : 0;
    float max = moreQ.size() > 0 ? moreQ.peek() : 0;
    if (lessQ.size() == moreQ.size()) {
      return (min + max)/2;
    } else if (lessQ.size() > moreQ.size()) {
      return min;
    } else {
      return max;
    }
  }

  // Driver method
  public static void main (String args[]) {
    int[] array = {1, 4, 5, 6, 7, 8, 9, 10};
    Median median = new Median();
    for (int i : array) {
      median.add(i);
      System.out.println("After adding " + i + " median is " + median.getMedian());
    }
  }
}
