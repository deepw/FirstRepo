/* 2.1 Write code to remove duplicates from an unsorted linked list. FOLLOW UP
 * How would you solve this problem if a temporary buffer is not allowed?
 */

import java.util.Set;
import java.util.HashSet;

class Node {
  int value;
  Node next;

  public Node (int val) {
    this.value = val;
    this.next = null;
  }
}

class LinkedList {
  Node head;
  public LinkedList() {
    this.head = null;
  }

  public void enqueue(int val) {
    if (this.head == null) {
      this.head = new Node(val);
    } else {
      Node newNode = new Node(val);
      newNode.next = this.head;
      this.head = newNode;
    }
  }

  public void printList() {
    if (this.head == null) {
      System.out.println("Empty list");
    }
    Node curr = this.head;
    while (curr != null) {
      System.out.print(curr.value);
      System.out.print("\t");
      curr = curr.next;
    }
  }

  public void removeDuplicates() {
    if (this.head == null) {
      System.out.println("Empty list");
    }

    Set<Integer> seenSet = new HashSet<Integer>();
    Node curr = this.head;
    seenSet.add(curr.value);
    while (curr != null && curr.next != null) {
      if (seenSet.contains(curr.next.value)) {
        curr.next = curr.next.next;
      } else {
        curr = curr.next;
        seenSet.add(curr.value);
      }
    }
  }
}

class RemoveDuplicates {
  public static void main(String args[]) {
    LinkedList myList = new LinkedList();
    for (String node : args) {
      System.out.println("Next arg " + node);
      myList.enqueue(Integer.parseInt(node));
    }
    myList.printList();
    myList.removeDuplicates();
    System.out.println("\nAfter removing duplicates");
    myList.printList();
  }
}

      
