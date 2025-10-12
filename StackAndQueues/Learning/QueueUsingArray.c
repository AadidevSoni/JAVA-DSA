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

class Queue {
    private int[] arr;      
    private int front;      
    private int rear;     
    private int capacity;   
    private int count;      

    public Queue(int size) {
        arr = new int[size];
        capacity = size;
        front = 0;
        rear = -1;
        count = 0;
    }
    
    public int size() {
        return count;
    }

    public boolean isEmpty() {
        return (count == 0);
    }

    public boolean isFull() {
        return (count == capacity);
    }

    public void enqueue(int item) {
        if (isFull()) {
            System.out.println("Queue Overflow! Cannot enqueue " + item);
            return;
        }
        
        rear = (rear + 1) % capacity; 
        arr[rear] = item;
        count++;
        System.out.println(item + " enqueued");
    }

    public int dequeue() {
        if (isEmpty()) {
            System.out.println("Queue Underflow! Cannot dequeue");
            return -1; 
        }

        int item = arr[front];
        front = (front + 1) % capacity; 
        count--;
        return item;
    }

    public int peek() {
        if (isEmpty()) {
            System.out.println("Queue is empty");
            return -1;
        }
        return arr[front];
    }
}

public class Practice {
    public static void main(String[] args) {
        Queue q = new Queue(5);

        q.enqueue(10);
        q.enqueue(20);
        q.enqueue(30);

        System.out.println("Front element: " + q.peek());
        System.out.println("Queue size: " + q.size());

        System.out.println("Dequeued: " + q.dequeue());
        System.out.println("Front element after dequeue: " + q.peek());
    }
}

	


	

