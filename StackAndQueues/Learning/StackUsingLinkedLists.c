package Arrays;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.HashMap;
import java.util.HashSet;
import java.util.List;
import java.util.Map;
import java.util.Scanner;
import java.util.Set;

class Node {
	int data;
	Node next;

	Node(int data) {
		this.data = data;
		this.next = null;
	}	
}

class Stack {
	private Node top;   
	private int size;  

	public Stack() {
		this.top = null;
		this.size = 0;
	}

	public void push(int x) {
		Node newNode = new Node(x);
		newNode.next = top;  // new node points to old top
		top = newNode;       // update top
		size++;
		System.out.println(x + " pushed to stack");
	}

	 public int pop() {
	     if (isEmpty()) {
	         System.out.println("Stack Underflow! Cannot pop");
	         return -1; 
	     }
	     int popped = top.data;
	     top = top.next; // move top to next node
	     size--;
	     return popped;
	 }

	 public int peek() {
	     if (isEmpty()) {
	         System.out.println("Stack is empty");
	         return -1;
	     }
	     return top.data;
	 }

	 public boolean isEmpty() {
	     return top == null;
	 }

	 public int size() {
	     return size;
	 }
}

public class Practice {
 public static void main(String[] args) {
     Stack stack = new Stack();

     stack.push(10);
     stack.push(20);
     stack.push(30);

     System.out.println("Top element: " + stack.peek());
     System.out.println("Stack size: " + stack.size());

     System.out.println("Popped element: " + stack.pop());
     System.out.println("Top element after pop: " + stack.peek());
 }
}
