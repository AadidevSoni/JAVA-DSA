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

class Pair {
	Node node;
	int col;
	public Pair(Node node, int col) {
		this.node = node;
		this.col = col;
	}
}

public class Practice {
	
	public static void main(String[] args) {
		
		Node root = new Node(1);
		root.left = new Node(2);
		root.right = new Node(3);
		root.left.left = new Node(4);
		root.left.right = new Node(5);
		root.right.left = new Node(6);
		root.right.right = new Node(7);
		root.left.left.left = new Node(9);
		
		TreeMap<Integer, Integer> map = new TreeMap<>();
		Queue<Pair> queue = new LinkedList<>();
		queue.offer(new Pair(root, 0));
		while(!queue.isEmpty()) {
			Pair p = queue.poll();
			Node node = p.node;
			int col = p.col;
			map.put(col, node.data); //Overwrite each time to get bottom value
			if(node.left != null) {
				queue.offer(new Pair(node.left,col-1));
			}
			if(node.right != null) {
				queue.offer(new Pair(node.right, col+1));
			}
		}
		
		for(int n: map.values()) {
			System.out.print(n + " ");
		}
		
  }
		
}
	


