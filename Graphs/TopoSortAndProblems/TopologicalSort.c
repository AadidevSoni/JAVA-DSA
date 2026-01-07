class Solution {
    public int[] topoSort(int V, List<List<Integer>> adj) {
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