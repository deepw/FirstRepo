/* 3.3 Imagine a (literal) stack of plates. If the stack gets too high, it might topple. Therefore,
in real life, we would likely start a new stack when the previous stack exceeds
some threshold. Implement a data structure SetOfStacks that mimics this. SetOf-
Stacks should be composed of several stacks, and should create a new stack once
the previous one exceeds capacity. SetOfStacks.push() and SetOfStacks.pop() should
behave identically to a single stack (that is, pop() should return the same values as it
would if there were just a single stack).
FOLLOW UP
Implement a function popAt(int index) which performs a pop operation on a specific
sub-stack.
_______________________________________________________________
*/

class Stack {
  int[] array;
  Stack nextStack;
  int head;
  int size;

  Stack(int size) {
    this.array = new int[size];
    this.nextStack = null;
    this.head = -1;
    this.size = size;
  }
  
  boolean isfull() {
    return (this.head == this.size - 1) {
  }
  
  boolean isEmpty() {
    return (this.head == -1) {
  }

  void push(int data) {
    this.array[++this.head] = data;
  }
  
  int pop() {
    return this.array[this.head--];
  }
}

class StackofStacks {
  Stack topStack;
  int sizeOfEach;

  StackofStacks(int size) {
    this.topStack = null;
    this.sizeOfEach = size;
  }

  void push(int value) {
    if (this.topStack == null) {
      this.topStack = new Stack(this.sizeOfEach);
    }
    if (this.topStack.isfull()) {
      // Current stack is full
      Stack newStack = new Stack(this.sizeOfEach);
      newStack->nextStack = this.topStack;
      this.topStack = newStack;
    }
    
    this.topStack.push(value);
  }

  int pop() {
    if (this.topStack == null) {
      throw new RuntimeException("No more elements");
    }
    if (this.topStack.isEmpty()) {
      if (this.topStack.nextStack == null) {
        throw new RuntimeException("No more elements");
      }
      this.topStack = this.topStack.nexStack;
    }
    return this.topStack.pop();
  }
}
