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
		root.left.left = new Node(4);
		root.left.right = new Node(5);
		root.right.left = new Node(6);
		root.right.right = new Node(7);
		
		List<Integer> res = new ArrayList<>(); //1, 2, 4, 5, 6, 7, 3
		if(root != null) {
			if(!isLeaf(root)) {
				res.add(root.data);
			}
			addLeftBoundary(root,res);
			addLeaves(root,res);
			addRightBoundary(root,res);
		}
		
		for(int n: res) {
			System.out.print(n + " ");
		}
		
    }
	
	public static boolean isLeaf(Node root) {
		return(root.left == null && root.right == null);
	}
	
	public static void addLeftBoundary(Node root, List<Integer> res) {
		Node curr = root.left;
		while(curr != null) {
			if(!isLeaf(curr)) {
				res.add(curr.data);
			}
			if(curr.left != null) {
				curr = curr.left;
			}else {
				curr = curr.right;
			}
		}
	}
	
	public static void addLeaves(Node root, List<Integer> res) {
		if(root == null) {
			return;
		}
		if(isLeaf(root)) {
			res.add(root.data);
			return;
		}
		addLeaves(root.left,res);
		addLeaves(root.right,res);
	}
	
	public static void addRightBoundary(Node root, List<Integer> res) {
		Node curr = root.right;
		while(curr != null) {
			if(!isLeaf(curr)) {
				res.add(curr.data);
			}
			if(curr.right != null) {
				curr = curr.right;
			}else {
				curr = curr.left;
			}
		}
	}
		
}
	


