/* Create a BST from a Binary tree which has the same tree structure */
import java.util.*;
public class MakeBST {

  static class Node {
    Node left, right;
    int data;
  
    Node (int value) {
      left = right = null;
      data = value;
    }
  }

  static class Index {
    int value;
    Index(int i) {
      value = i;
    }
  }

  static void createInorderArray(Node root, int[] array, Index index) {
    if (root == null) {
      return;
    }
    createInorderArray(root.left, array, index);
    array[index.value++] = root.data;
    createInorderArray(root.right, array, index);
  }

  static void refillTree(Node root, int[] array, Index index) {
    if (root == null) {
      return;
    }
    refillTree(root.left, array, index);
    root.data = array[index.value++];
    refillTree(root.right, array, index);
  }
  
  static Node clone(Node root) {
    if (root == null) {
      return;
    }
    Node newNode = new Node(root.data);
    newNode.left = clone(root.left);
    newNode.right = clone(root.right);
    return newNode;
  }

  static void convert(Node root, int size) {
    int[] array = new int[size];
    Index index = new Index(0);
    createInorderArray(root, array, index);
    Arrays.sort(array);
    refillTree(root, array, new Index(0));
  }
   
  static void printArray(int[] array) {
    for (int i : array) {
      System.out.print(i);
      System.out.print("\t");
    }
    System.out.println();
  }

  public static void main (String args[]) {
    Node root = new Node(10);
    root.left = new Node(5);
    root.right = new Node(15);
    root.left.left = new Node(2);
    root.left.right = new Node(8);
    root.right.left = new Node(12);
    root.right.right = new Node(7);
    int[] array = new int[7];
    createInorderArray(root, array, new Index(0));
    printArray(array); 
    convert(root, 7);
    createInorderArray(root, array, new Index(0));
    printArray(array);
  }
}
    
