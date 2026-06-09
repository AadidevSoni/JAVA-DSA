package Arrays;

import java.util.*;

public class Practice {
	
	public static void main(String[] args) {
		
		int n = 5;
		int k = 4;
		String[] dict = {"baa","abcd","abca","cab","cad"};
		List<List<Integer>> adjList = new ArrayList<>();
		for(int i = 0; i < k; i++) {
		    adjList.add(new ArrayList<>());
		}
		
		for(int i=0;i<n-1;i++) {
			String s1 = dict[i];
			String s2 = dict[i+1];
			int len = Math.min(s1.length(), s2.length());
			for(int ptr = 0;ptr < len;ptr++) {
				if(s1.charAt(ptr) != s2.charAt(ptr)) {
					adjList.get(s1.charAt(ptr)-'a').add(s2.charAt(ptr)-'a');
					break;
				}
			}
			
		}
		
		int[] res = topoSort(k,adjList);
		for(int x : res) {
		    System.out.print((char)(x + 'a'));
		}
		
    }
	
	public static int[] topoSort(int V, List<List<Integer>> adj) {
        int[] vis = new int[V];
        for(int i=0;i<V;i++) {
            vis[i] = 0;
        }
        Stack<Integer> st = new Stack<>();

        for(int i=0;i<V;i++) {
            if(vis[i] == 0) {
                dfs(i,adj,vis,st);
            }
        }

        int[] res = new int[V];
        int ind = 0;
        while(!st.isEmpty()) {
            res[ind++] = st.pop();
        }
        return res;
    }

    public static void dfs(int node, List<List<Integer>> adjl, int[] vis,Stack<Integer> st) {
        vis[node] = 1;
        for(int i=0;i<adjl.get(node).size();i++) {
            int v = adjl.get(node).get(i);
            if(vis[v] == 0) {
                dfs(v,adjl,vis,st);
            }
        }
        st.push(node);
    }
	
	
}
	


