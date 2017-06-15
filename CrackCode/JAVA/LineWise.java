/*  - To print nodes of a tree with one level on a line, use a nodecount to keep the current size of the queue and print on one line ti    ll this nodecount >0. Check out: http://geeksquiz.com/print-level-order-traversal-line-line/
*/


public class Graph {

  class Node {
    Node left, right;
    Integer data;
    
    Node(Integer data) {
      this.data = data;
      this.left = this.right = null;
    }
  }
 

  void printLineWise(Node root) {
    Node curr = root;
    Queue q = new LinkedList();

    q.add(curr);
    while (!q.isEmpty()) {
      int count = q.size();
      while(count-- > 0) {
        curr = q.remove();
        System.out.println(curr->data);
        q.add(curr->left);
        q.add(curr->right);
      }
      System.out.println();
    }
  }

  public static void main(String args[]) {
    

  }
  
