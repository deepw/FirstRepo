/* Given a binary search tree, design an algorithm which creates a linked list of all the
nodes at each depth (i.e., if you have a tree with depth D, you’ll have D linked lists).
*/

import java.util.*;

// Java program to demonstrate insert operation in binary search tree
class BinarySearchTree {
 
    // Root of BST
    TreeNode root;
 
    // Constructor
    BinarySearchTree() { 
        root = null; 
    }
 
    // This method mainly calls insertRec()
    void insert(int data) {
       root = insertRec(root, data);
    }
     
    /* A recursive function to insert a new data in BST */
    TreeNode insertRec(TreeNode root, int data) {
 
        /* If the tree is empty, return a new node */
        if (root == null) {
            root = new TreeNode(data);
            return root;
        }
 
        /* Otherwise, recur down the tree */
        if (data < root.data)
            root.left = insertRec(root.left, data);
        else if (data > root.data)
            root.right = insertRec(root.right, data);
 
        /* return the (unchanged) node pointer */
        return root;
    }
 
    // This method mainly calls InorderRec()
    void inorder()  {
       inorderRec(root);
    }
 
    // A utility function to do inorder traversal of BST
    void inorderRec(TreeNode root) {
        if (root != null) {
            inorderRec(root.left);
            System.out.println(root.data);
            inorderRec(root.right);
        }
    }
}

class Node {
  int data;
  Node next;
  
  Node(int data) {
    this.data = data;
    this.next = null;
  }
}

class TreeNode {
  int data;
  TreeNode left;
  TreeNode right;

  TreeNode(int data) {
    this.data = data;
    this.left = null;
    this.right = null;
  }
}

class LinkedLists {
  Map<Integer, Node>map;
  
  LinkedLists() {
    map = new HashMap<Integer, Node>();
  }

  synchronized void createLists(TreeNode root, LinkedHashSet<Node> heads, int depth) {
     
    if (root == null) { 
      return;
    }

    Node thisNode = new Node(root.data);
    if (this.map.get(depth) == null) {
      heads.add(thisNode);
    } else {
      this.map.get(depth).next = thisNode;
    }
    this.map.put(depth, thisNode);

    createLists(root.left, heads, depth + 1);
    createLists(root.right, heads, depth + 1);
  
  }
}

public class TreeLevelLinkedLists {
  public static void main (String args[]) {
    
  BinarySearchTree tree = new BinarySearchTree();
 
        /* Let us create following BST
              50
           /     \
          30      70
         /  \    /  \
       20   40  60   80 */
        tree.insert(50);
        tree.insert(30);
        tree.insert(20);
        tree.insert(40);
        tree.insert(70);
        tree.insert(60);
        tree.insert(80);    
  tree.inorder();
  LinkedHashSet<Node> all = new LinkedHashSet<Node>();
  LinkedLists myList = new LinkedLists();
  myList.createLists(tree.root, all, 0);
  for (Node node : all) {
    while(node != null) {
      System.out.print(node.data);
      System.out.print("\t");
      node = node.next;
    }
    System.out.println();
  }
}
}
   
  
