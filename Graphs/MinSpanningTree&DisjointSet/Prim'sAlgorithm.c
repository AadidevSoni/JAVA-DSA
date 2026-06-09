package Arrays;

import java.util.*;

public class Practice {
	
	public static void main(String[] args) {
		
		//Graph
		List<List<List<Integer>>> adj = new ArrayList<>();

		for(int i = 0; i < 3; i++) {
		    adj.add(new ArrayList<>());
		}

		// 0 <-> 1 (weight 2)
		adj.get(0).add(Arrays.asList(2, 1));
		adj.get(2).add(Arrays.asList(0, 1));

		// 0 <-> 2 (weight 4)
		adj.get(0).add(Arrays.asList(1, 5));
		adj.get(1).add(Arrays.asList(0, 5));

		// 1 <-> 2 (weight 3)
		adj.get(1).add(Arrays.asList(2, 3));
		adj.get(2).add(Arrays.asList(1, 3));
		
		int v = 3;
		PriorityQueue<Pair> pq = new PriorityQueue<Pair>((x,y) -> x.distance - y.distance); //take min dist/weight next
		int[] vis = new int[v];
		pq.add(new Pair(0,0)); //you need to store the parent only if you have to print the MST
		int sum = 0;
		while(pq.size() > 0) {
			Pair p = pq.poll();
			int node = p.node;
			int wt = p.distance;
			if(vis[node] == 1) {
				continue;
			}
			vis[node] = 1;
			sum += wt;
			for(int i=0;i<adj.get(node).size();i++) {
				int adjNode = adj.get(node).get(i).get(0);
				int adjWt = adj.get(node).get(i).get(1);
				if(vis[adjNode] == 0) {
					pq.add(new Pair(adjNode, adjWt));
				}
			}
		}
		
		System.out.println("MST sum: " + sum);
		
		
    }
	
	
}

class Pair {
	int node;
	int distance;
	public Pair(int node, int distance) {
		this.node = node;
		this.distance = distance;
	}
}
	


