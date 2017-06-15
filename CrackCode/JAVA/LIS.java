public class LIS {

  static int LIsubs(int[] array) {
    int len = array.length;
    int[] DP = new int[len];
    for (int i=0;i <len; i++) {
      System.out.println(DP[i] + ", ");
      DP[i]=1;
    }
    DP[0] = 1;

    for (int i=1; i < len; i++) {
      for (int j=0; j<i; j++) {
        if (array[i] > array[j]) {
          DP[i] = Math.max(DP[j] + 1, DP[i]);
        } 
      }
    }
    return DP[len-1];
  }

  public static void main (String args[]) {
    int[] arr = {2, 1, 2, 5, 6, 4, 10, 8, 9};
    System.out.println(LIsubs(arr));
  }
}
