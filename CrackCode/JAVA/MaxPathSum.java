/* Find the max path sum in a Binary Tree */

public class MaxPathSum {
  static class Result {
    int value;
    Result(int i) {
      value = i;
    }
  }
  static class Node {
    Node left, right;
    int data;
    Node (int data) {
      this.data = data;
    }
  }

  static void findMax(Node root, int cur_sum, Result res) {
    if (root == null) {
      return;
    }
    cur_sum += root.data;
    res.value = Math.max(res.value, cur_sum);
    
    findMax(root.left, cur_sum, res);
    findMax(root.right, cur_sum, res);
    cur_sum -= root.data;
  }

  public static void main (String args[]) {
    Node root = new Node(10);
    root.left = new Node(5);
    root.right = new Node(15);
    root.left.left = new Node(2);
    root.left.right = new Node(8);
    root.right.left = new Node(2);
    root.right.right = new Node(7);
    Integer cur = 0;
    Result res = new Result(0);
    findMax(root, cur, res);
    System.out.println("Max path sum is " + res.value);
  }
}
