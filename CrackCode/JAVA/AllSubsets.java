/* 8.3 Write a method that returns all subsets of a set. */

public class AllSubsets {

  static void printSubsets(Set<Integer> set) {
    int[] array = new int[set.size];
    for (int i = 0; i < Math.pow(2, set.size()) ; i++) {
      printSetFor(i, array);
    }
  }

  static void printSetFor(int place, int [] array) {
    System.out.print("{");
    index = 0;
    while (place > 0) {
      if (place & 0x1) {
        System.out.print(array[index])
      }
      place >> 1;
      index++;
    }
    System.out.println("}");


}
