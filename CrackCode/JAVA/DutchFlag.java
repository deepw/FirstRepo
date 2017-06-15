/* Dutch Flag Problem */

public class DutchFlag {

  static void sort (int[] array) {
    int start = 0, end = array.length-1, i = 0;

    while (i < end) {
      switch (array[i]) {
        case 0: 
        {
          swap(array, start, i);
          start++;
          i++;
          break;
        } 
        case 1: 
        {
          i++; 
          break;
        }
        case 2: 
        {
          swap(array, end, i);
          end--;
          break;
        }
      }
   }
  }

  static void swap(int[] array, int a, int b) {
    int temp = array[a];
    array[a] = array[b];
    array[b] = temp;
  }

  static void printArray(int[] array) {
    for (int i : array) {
      System.out.println(i);
    }
  }
       
  

  public static void main (String args[]) {
    int[] array = {2, 0, 1, 1, 1,0,2,2,1,0,0,0};
    printArray(array);
    sort(array);
    System.out.println("Sorted Array: ");
    printArray(array);
  }
}
