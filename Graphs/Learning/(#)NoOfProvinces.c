package Arrays;

import java.util.*;

public class Practice {
	
	public static void main(String[] args) {
		
		Scanner sc = new Scanner(System.in);
		
		System.out.println("No of nodes: ");
		int n = sc.nextInt();
		
		System.out.println("No of edges: ");
		int m = sc.nextInt();
		
		List<List<Integer>> arrList = new ArrayList<>();
		for(int i=0;i<=n;i++) {
			arrList.add(new ArrayList<Integer>());
		}
		
		for(int i=1;i<=m;i++) {
			System.out.println("Give nodes of edge " + i + ": ");
			int x = sc.nextInt();
			int y = sc.nextInt();
			arrList.get(x).add(y);
			arrList.get(y).add(x);
		}
		
		int provinces = 0;
		int[] vis = new int[n+1];
		
		for(int i=1;i<=n;i++) {
			if(vis[i] == 0) {
				provinces++;
				dfs(i,vis,arrList);
			}
		}
		
		System.out.println("No of provinces: " + provinces);
		
    }
	
	public static void dfs(int node, int[] vis, List<List<Integer>> arrList) {
		vis[node] = 1;
		for(int i=0;i<arrList.get(node).size();i++) {
			int n = arrList.get(node).get(i);
			if(vis[n] == 0) {
				dfs(n,vis,arrList);
			}
		}
	}
	
}
	


