/* 4.3 Given a sorted (increasing order) array, write an algorithm to create a binary tree with
minimal height.
*/

class Node {
  Node left;
  Node right;
  Object data;
  
  Node(Object val) {
    this.left = null;
    this.right = null;
    this.data = val;
  } 
}

class CreateTree {
  public static Node createMinHeightTree(int[] array, int start, int end) {
    if (start > end) {
      return null;
    }
    int mid = (start + end) / 2;
    Node root = new Node(array[mid]);
    root.left = createMinHeightTree(array, start, mid-1);
    root.right = createMinHeightTree(array, mid+1, end);
    return root;
  }

  public static void printTree(Node root) {
    if (root == null) {
      return;
    }
    printTree(root.left);
    System.out.print(root.data);
    System.out.print("\t");
    printTree(root.right); 
  }   
}

public class BinaryTreeCreation {
  public static void main(String args[]) {
    int[] array = new int[args.length];
    int i = 0;
    for (String val : args) {
      array[i++] = Integer.parseInt(val);
    }
    Node root = CreateTree.createMinHeightTree(array, 0, i-1);
    System.out.println("Root is at " + root.data);
    CreateTree.printTree(CreateTree.createMinHeightTree(array, 0, i-1)); 
  }
}
