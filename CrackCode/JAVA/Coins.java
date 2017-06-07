/* 8.7
 * Given an infinite number of quarters (25 cents), dimes (10 cents), nickels (5 cents) and
pennies (1 cent), write code to calculate the number of ways of representing n cents.
 */

public class Coins {
  
  static void printAll(int[] coinSet, int here, int nCoins, int value, int N, int[] result) {
    if (value > N) {
      return;
    }
    if (value == N) {
      for (int i = 0; i < nCoins ; i++) {
        System.out.print(result[i]);
        System.out.print("\t");
      }
      System.out.println();
      return;
    }

    for (int i = here; i < coinSet.length; i++) {
      if (value + coinSet[i] <= N) {
        result[nCoins] = coinSet[i];
        printAll(coinSet, i, nCoins+1, value+coinSet[i], N, result);
      }
    } 
  }

  public static void main (String args[]) {
    int[] coins = {1, 5, 10, 25};
    int[] result = new int[Integer.parseInt(args[0])];
    printAll(coins, 0, 0, 0, Integer.parseInt(args[0]), result);
  }
}

