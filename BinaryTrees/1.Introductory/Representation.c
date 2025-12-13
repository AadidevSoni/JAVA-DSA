package Arrays;

import java.util.*;

class Node {
	int data;
	Node left;
	Node right;
	
	public Node(int key) {
		data = key;
	}
}


public class Practice {
	
	public static void main(String[] args) {
		
		Node root = new Node(1);
		root.left = new Node(2);
		root.right = new Node(3);
		root.left.right = new Node(4);

	}
	
	
}

