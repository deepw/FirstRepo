/* 11.4
You have an array with all the numbers from 1 to N, where N is at most 32,000. The
array may have duplicate entries and you do not know what N is. With only 4KB of
memory available, how would you print all duplicate elements in the array?
*/

public class CheckDuplicates {

  public static void checkDuplicates(int[] array) {
    Bitset bs = new Bitset(32001);
    for (int i : array) {
      if (bs.get(i)) {
        System.out.println("Duplicate is " + i);
      } 
      bs.set(i);
    }
  }

}
