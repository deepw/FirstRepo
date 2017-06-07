/*
 * 1.3 Design an algorithm and write code to remove the duplicate characters in a string without using any additional buffer. NOTE: One or two additional variables are fine. An extra copy of the array is not.
 * FOLLOW UP
 * Write the test cases for this method. 
*/

public class RemoveRepeatingCharacters {

  public static void main (String[] args) {
    if (args.length == 0) {
      System.out.println("missing input");
    }
    System.out.println("New string " + removeRepeating(args[0]));
  }

  private static String removeRepeating(String arg) {
    char[] resultArray = new char[arg.length()];
    int checker = 0;
    int resultPosition = 0;
    for (int i = 0; i < arg.length(); i++) {
      int pos = 1 << arg.charAt(i);
      if ((checker & (1 << pos)) == 0) {
        // character is a new character
        resultArray[resultPosition++] = arg.charAt(i);
      }
      checker |= 1 << pos;
    }
    return new String(resultArray);
  }
}
