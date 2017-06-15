public class MoveZeroes {
  static void move(int[] array) {
    int len = array.length;
    int end = len-1;  
    int temp;
    
    for (int i=0; i<end;) {
      if (array[i] == 0) {
        temp = array[end];
        array[end] = 0;
        array[i] = temp;
        end--;
      } else {
        i++;
      }
    }
  }
  
  static void move2(int[] array) {
    int curr = 0; int len = array.length;

    for (int i=0; i< len; i++) {
      if (array[i] != 0) {
        array[curr++] = array[i];
      }
    }

   for (; curr<len; curr++) {
     array[curr]=0;
   }

  }
        

  public static void main (String args[]) {
    int[] arr = {0, 1, 3, 0, 5, 3, 0, 7};
    move2(arr);
    for (int i = 0; i < arr.length; i++) {
      System.out.println(arr[i] + ", ");
    }
  }
}
