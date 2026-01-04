package Arrays;

import java.util.*;

class Pair {
	int node;
	int from;
	Pair(int node, int from) {
		this.node = node;
		this.from = from;
	}
}

public class Practice {
	
	public static void main(String[] args) {
		
		int n;
		System.out.println("Enter no of vertices: ");
		Scanner scanner = new Scanner(System.in);
		n = scanner.nextInt();
		
		int m;
		System.out.println("Enter no of edges: ");
		m = scanner.nextInt();
		
		ArrayList<ArrayList<Integer>> adjl = new ArrayList<ArrayList<Integer>>();
		
		for(int i=0;i<=n;i++) {
			adjl.add(new ArrayList<Integer>());
		}
		
		for(int i=1;i<=m;i++) {
			System.out.println("Enter edge pair " + i + ": ");
			int v1 = scanner.nextInt();
			int v2 = scanner.nextInt();
			adjl.get(v1).add(v2);
			adjl.get(v2).add(v1);
		}
		
		int[] visited = new int[n+1];
		
		for(int i=0;i<=n;i++) {
			visited[i] = 0;
		}
		
		int hasCycle = 0;
		
		int start = -1;
		System.out.println("Enter starting vertex: ");
		start = scanner.nextInt();
		visited[start] = 1;
		
		Queue<Pair> queue = new LinkedList<>();
		queue.add(new Pair(start,-1));
		
		while(!queue.isEmpty()) {
			int node = queue.peek().node;
			int from = queue.peek().from;
			queue.remove();
			
			for(int i=0;i<adjl.get(node).size();i++) {
				int num = adjl.get(node).get(i);
				if(visited[num] == 0) {
					visited[num] = 1;
					queue.add(new Pair(num,node));
				}else if(num != from) {
					hasCycle = 1;
					break;
				}
			}
		}
		
		if(hasCycle == 0) {
			System.out.println("No Cycle");
		}else {
			System.out.println("Has Cycle");
		}

	}
	
	
}

