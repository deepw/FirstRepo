public class Permutations {

  static void swap(char[] array, int a, int b) {
    char temp = array[a];
    array[a] = array[b];
    array[b] = temp;
  }

  static void printAll(char[] string, int pos, int length) {
    
    if (pos == length) {
      System.out.println(string);
    }
    for (int i = pos; i <= length ; i++) {
      swap(string, i, pos);
      printAll(string, pos+1, length);
      swap(string, i, pos);
    }
  }

  public static void main (String args[]) {
    printAll(args[0].toCharArray(), 0, args[0].length() - 1);

  }
}
