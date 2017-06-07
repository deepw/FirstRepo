public class HelloWorld {
    public static void main(String[] args) {
        if (args.length == 0) {
            System.out.println("Hello World!");
        } else {
            System.out.print("Hello ");
            for (String name : args) {
                System.out.print(name + " ");
            }
            System.out.println();
        }
    }
}
