import java.util.*;

public class AnagramStrings {
  public static void main (String[] args) {
    if (args.length != 2) {
       System.out.println("missing argument");
    }
    System.out.println(args[0] + " and " + args[1] + 
      String.format(" are %sAnagram Strings.", anagrams(args[0], args[1]) ? "" : "not "));
  }

  private static boolean anagrams(String str1, String str2) {
    // lengths must be the same
    if (str1.length() != str2.length()) {
      return false;
    }
    //Build map from the first string 
    Map<Character, Integer> map = new HashMap<Character, Integer>();
    for (int i = 0; i < str1.length(); i++) {
      if (map.get(str1.charAt(i)) == null) {
        map.put(str1.charAt(i), 1);
      } else {
        map.put(str1.charAt(i), map.get(str1.charAt(i)) + 1);
      }
    }
    // Check for second string
    for (int i = 0; i < str2.length(); i++) {
      if (map.get(str2.charAt(i)) == null) {
        return false;
      } else {
        if (map.get(str2.charAt(i)) == 1) {
          map.remove(str2.charAt(i));
        } else {
          map.put(str2.charAt(i), map.get(str2.charAt(i)) - 1);
        }
      }
    }
    return (map.size() == 0);        
  }
}
