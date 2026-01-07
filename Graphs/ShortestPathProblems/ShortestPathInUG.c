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
		
		int[] dist = new int[n];
		Arrays.fill(dist, Integer.MAX_VALUE);
		
		Queue<Pair> queue = new LinkedList<>();
		int src;
		System.out.println("Enter source vertex: ");
		src = scanner.nextInt();
		queue.offer(new Pair(src,0));
		dist[src] = 0;
		
		while(!queue.isEmpty()) {
			int node = queue.peek().node;
			int distance = queue.peek().distance;
			queue.remove();
			for(int i=0;i<adjl.get(node).size();i++) {
				int nod = adjl.get(node).get(i);
				if(dist[nod] == Integer.MAX_VALUE) {
					queue.offer(new Pair(nod,distance+1));
					dist[nod] = distance+1;
				}else {
					if(dist[nod] > distance + 1) {
						dist[nod] = distance+1;
					}
				}
			}
		}
		
		for(int i=0;i<n;i++) {
			System.out.print(src + " - " + i + ": " + dist[i]);
			System.out.println();
		}

	}
	
	
}

class Pair {
	int node;
	int distance;
	Pair(int node, int distance) {
		this.node = node;
		this.distance = distance;
	}
}
