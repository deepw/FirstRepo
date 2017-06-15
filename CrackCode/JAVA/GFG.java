public class GFG {
    
    static int getCount(char[] str, int begin) {
        if (begin == str.length -1) {
            return 1;
        }
        if (str[begin] == '1' || (str[begin] == '2' 
            && str[begin+1] < '7')) {
            return 2 + getCount(str, begin+1);
        } else {
            return 1+getCount(str, begin+1);
        }
    }
	public static void main (String[] args) {
	    System.out.println(getCount(args[0].toCharArray(), 0));
		//code
	}
}

