class Solution {
    public int[] findOrder(int numCourses, int[][] prerequisites) {
        List<List<Integer>> adj = new ArrayList<>();
        for (int i = 0; i < numCourses; i++) {
            adj.add(new ArrayList<>());
        }

        for (int[] p : prerequisites) {
            adj.get(p[1]).add(p[0]);
        }

        int[] vis = new int[numCourses];
        int[] pathVis = new int[numCourses];
        Stack<Integer> st = new Stack<>();

        for(int i=0;i<numCourses;i++) {
            if(vis[i] == 0) {
                if(dfs(i,vis,pathVis,numCourses,prerequisites,adj,st)) {
                    int[] res1 = new int[0];
                    return res1;
                }
            }
        }

        int[] res = new int[numCourses];
        int ind = 0;
        while(!st.isEmpty()) {
            res[ind++] = st.pop();
        }
        return res;
    }

    public static boolean dfs(int node, int[] vis, int[] pathVis, int numCourses, int[][] prerequisites, List<List<Integer>> adjl,Stack<Integer> st) {
        vis[node] = 1;
        pathVis[node] = 1;
        for(int i=0;i<adjl.get(node).size();i++) {
            int n = adjl.get(node).get(i);
            if(vis[n] == 0) {
                if(dfs(n,vis,pathVis,numCourses,prerequisites,adjl,st)) {
                    return true;
                }
            } else if(pathVis[n] == 1) {
                return true;
            }
        }
        st.push(node);
        pathVis[node] = 0;
        return false;
    }
}