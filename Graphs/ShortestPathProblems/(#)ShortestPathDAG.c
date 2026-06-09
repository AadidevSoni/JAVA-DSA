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
			System.out.println("Enter edge pair " + i + " along with edge weight: ");
			int v1 = scanner.nextInt();
			int v2 = scanner.nextInt();
			int v3 = scanner.nextInt();
			adjl.get(v1).add(new Pair(v2,v3));
		}
		
		int[] vis = new int[n];
		Stack<Integer> st = new Stack<>();
		
		for(int i=0;i<n;i++) {
			if(vis[i] == 0) {
				dfs(i,adjl,st,vis);
			}
		}
		
		int[] dist = new int[n];
		Arrays.fill(dist, Integer.MAX_VALUE);
		
		int src;
		System.out.println("Enter source vertex: ");
		src = scanner.nextInt();
		dist[src] = 0;
		
		while(!st.isEmpty()) {
			int node = st.peek();
			st.pop();
			for(int i=0;i<adjl.get(node).size();i++) {
				Pair p = adjl.get(node).get(i);
				int no = p.node;
				int we = p.weight;
				if(dist[no] > dist[node] + we) {
					dist[no] = dist[node] + we;
				}
				
			}
		}
		
		for(int i=0;i<n;i++) {
			System.out.print(src + " - "  + i + " : "+ dist[i]);
			System.out.println();
		}

	}
	
	public static void dfs(int node, ArrayList<ArrayList<Pair>> adjl, Stack<Integer> st, int[] vis) {
		vis[node] = 1;
		for(int i=0;i<adjl.get(node).size();i++) {
			Pair v = adjl.get(node).get(i);
			int n = v.node;
			if(vis[n] == 0) {
				dfs(n,adjl,st,vis);
			}
		}
		st.push(node);
	}
	
	
}

class Pair {
	int node;
	int weight;
	Pair(int node, int weight) {
		this.node = node;
		this.weight = weight;
	}
}
