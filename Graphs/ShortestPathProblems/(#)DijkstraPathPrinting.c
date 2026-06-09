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
		
		ArrayList<ArrayList<Pair>> adjl = new ArrayList<ArrayList<Pair>>();
		
		for(int i=0;i<=n;i++) {
			adjl.add(new ArrayList<Pair>());
		}
		
		for(int i=1;i<=m;i++) {
			System.out.println("Enter edge pair " + i + " along with weight: ");
			int v1 = scanner.nextInt();
			int v2 = scanner.nextInt();
			int v3 = scanner.nextInt();
			
			adjl.get(v1).add(new Pair(v2,v3));
			adjl.get(v2).add(new Pair(v1,v3));
		}
		
		int[] dist = new int[n+1];
		Arrays.fill(dist, Integer.MAX_VALUE);
		
		int[] parent = new int[n+1];
		Arrays.fill(parent, -1);
		
		PriorityQueue<Pair> queue = new PriorityQueue<>((a, b) -> a.distance - b.distance);

		int src;
		System.out.println("Enter source vertex: ");
		src = scanner.nextInt();
		queue.offer(new Pair(src,0));
		dist[src] = 0;
		
		while(!queue.isEmpty()) {
			int node = queue.peek().node;
			int distance = queue.peek().distance;
			queue.remove();
			if (distance > dist[node]) continue;

			for(int i=0;i<adjl.get(node).size();i++) {
				Pair nod = adjl.get(node).get(i);
				int n1 = nod.node;
				int d1 = nod.distance;
				if(dist[n1] > d1+distance) {
					dist[n1] = d1+distance;
					parent[n1] = node;
					queue.offer(new Pair(n1,dist[n1]));
				}
			}
		}
		
		System.out.println("Enter node to reach: ");
		int goal = scanner.nextInt();
		
		if (dist[goal] == Integer.MAX_VALUE) {
		    System.out.println("No path exists");
		}else {
			List<Integer> path = new ArrayList<>();
			for (int v = goal; v != -1; v = parent[v]) {
			    path.add(v);
			}
			Collections.reverse(path);

			System.out.println("Shortest distance: " + dist[goal]);
			System.out.println("Path: " + path);
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
