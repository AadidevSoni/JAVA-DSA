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

class Queue {
	 private Node front, rear;  
	 private int size;
	
	 public Queue() {
	     this.front = this.rear = null;
	     this.size = 0;
	 }

	 public void enqueue(int x) {
	     Node newNode = new Node(x);
	
	     if (rear == null) {  // queue is empty
	         front = rear = newNode;
	     } else {
	         rear.next = newNode;
	         rear = newNode;
	     }
	
	     size++;
	     System.out.println(x + " enqueued");
	 }

	 public int dequeue() {
	     if (isEmpty()) {
	         System.out.println("Queue Underflow! Cannot dequeue");
	         return -1; 
	     }
	
	     int value = front.data;
	     front = front.next;
	
	     if (front == null) { // if queue becomes empty
	         rear = null;
	     }
	
	     size--;
	     return value;
	 }

	 public int peek() {
	     if (isEmpty()) {
	         System.out.println("Queue is empty");
	         return -1;
	     }
	     return front.data;
	 }

	 public boolean isEmpty() {
	     return front == null;
	 }

	 public int size() {
	     return size;
	 }
}

public class Practice {
 public static void main(String[] args) {
     Queue q = new Queue();

     q.enqueue(10);
     q.enqueue(20);
     q.enqueue(30);

     System.out.println("Front element: " + q.peek());
     System.out.println("Queue size: " + q.size());

     System.out.println("Dequeued: " + q.dequeue());
     System.out.println("Front element after dequeue: " + q.peek());
 }
}

