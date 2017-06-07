/* Simple Runnable Example */

public class MyThread {

  static class NewThread implements Runnable {
    public void run() {
      System.out.println("New thread.");
    }
  }

  public static void main (String args[]) {
    NewThread foo = new NewThread();
    Thread myThread = new Thread(foo);
    myThread.start();
  }
}

