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
		root.left.left.left = new Node(9);
		root.left.left.right = new Node(10);
		
		List<Integer> lst = new ArrayList<>();
		int target = 10;
		if(root == null) {
			System.out.println("Null Root");
		}
		getPath(lst,root,target);
		for(int n: lst) {
			System.out.print(n + " ");
		}
		
    }
	
	public static boolean getPath(List<Integer> lst, Node root, int target) {
		if(root == null) {
			return false;
		}
		lst.add(root.data);
		if(root.data == target) {
			return true;
		}
		if(getPath(lst,root.left,target) || getPath(lst,root.right,target)) {
			return true;
		}
		lst.remove(lst.size()-1);
		return false;
	}
		
}
	


