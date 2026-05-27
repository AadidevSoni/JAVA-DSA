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
		
		Node root = new Node(40);
		root.left = new Node(10);
		root.right = new Node(20);
		root.left.left = new Node(2);
		root.left.right = new Node(5);
		root.right.left = new Node(30);
		root.right.right = new Node(40);
		
		List<List<Integer>> levelList = levelorder(root);
		for(List<Integer> sub: levelList) {
			for(Integer num: sub) {
				System.out.print(num + " ");
			}
		}
		System.out.println();
		
		changeTree(root);
		
		System.out.println("Updated tree: ");
		List<List<Integer>> levelList1 = levelorder(root);
		for(List<Integer> sub: levelList1) {
			for(Integer num: sub) {
				System.out.print(num + " ");
			}
		}
		System.out.println();
		
    }
	
	static List<List<Integer>> levelorder(Node root) {
		Queue<Node> queue = new LinkedList<Node>();
		List<List<Integer>> levelList = new LinkedList<List<Integer>>();
		if(root == null) return levelList;
		queue.offer(root);
		while(!queue.isEmpty()) {
			int levelNum = queue.size();
			List<Integer> subList = new LinkedList<Integer>();
			for(int i=0;i<levelNum;i++) {
				if(queue.peek().left != null) queue.offer(queue.peek().left);
				if(queue.peek().right != null) queue.offer(queue.peek().right);
				subList.add(queue.poll().data);
			}
			levelList.add(subList);
		}
		return levelList;
	}
	
	static void changeTree(Node root) {
		if(root == null) {
			return;
		}
		int child = 0;
		if(root.left != null) {
			child += root.left.data;
		}
		if(root.right != null) {
			child += root.right.data;
		}
		if(child >= root.data) {
			root.data = child;
		}else {
			if(root.left != null) {
				root.left.data = root.data;
			}
			if(root.right != null) {
				root.right.data = root.data;
			}
		}
		
		changeTree(root.left);
		changeTree(root.right);
		
		int total = 0;
		if(root.left != null) {
			total += root.left.data;
		}
		if(root.right != null) {
			total += root.right.data;
		}
		if(root.left != null || root.right != null) {
			root.data = total;
		}
	}
	
}
	


