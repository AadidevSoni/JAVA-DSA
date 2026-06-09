package Arrays;

import java.util.*;

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
		
		Queue<Integer> queue = new LinkedList<>();
		
		int start = -1;
		System.out.println("Enter starting vertex: ");
		start = scanner.nextInt();
		visited[start] = 1;
		
		queue.offer(start);
		while(!queue.isEmpty()) {
			int peek = queue.peek();
			queue.remove();
			System.out.print(peek + " ");
			for(int i=0;i<adjl.get(peek).size();i++) {
				int num = adjl.get(peek).get(i);
				if(visited[num] != 1) {
					queue.offer(num);
					visited[num] = 1;
				}
			}
		}
		

	}
	
	
}

