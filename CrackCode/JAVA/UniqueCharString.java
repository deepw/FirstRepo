/* 
 * 1.1 Implement an algorithm to determine if a string has all unique characters. What if you can not use additional data structures?
*/

ublic class UniqueCharString {
  public static void main (String[] args) {
    if (args.length == 0) {
      System.out.println ("Argument string is required");
      return;
    }
    System.out.println (String.format("All chars are %s unique in string %s", isUnique(args[0]) ? "" : "not", args[0]));
  }

  private static boolean isUnique(String str) {
    int checker = 0;
    for (int i = 0; i < str.length(); i++) {
      int pos = str.charAt(i) - 97;
      System.out.println(String.format("Position is %d", pos));
      if ((checker & (1 << pos)) != 0) {
        return false;
      } else {
        checker |= (1 << pos);
      }
    }
    return true;
  }
}

