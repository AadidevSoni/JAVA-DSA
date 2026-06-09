class Solution {
    public boolean canFinish(int numCourses, int[][] prerequisites) {

        // Build adjacency list
        List<List<Integer>> adj = new ArrayList<>();
        for (int i = 0; i < numCourses; i++) {
            adj.add(new ArrayList<>());
        }

        for (int[] p : prerequisites) {
            adj.get(p[1]).add(p[0]);
        }

        int[] vis = new int[numCourses];
        int[] pathVis = new int[numCourses];

        for (int i = 0; i < numCourses; i++) {
            if (vis[i] == 0) {
                if (dfs(i, adj, vis, pathVis)) {
                    return false; // cycle found → cannot finish
                }
            }
        }

        return true; // no cycle
    }

    private boolean dfs(int node, List<List<Integer>> adj, int[] vis, int[] pathVis) {

        vis[node] = 1;
        pathVis[node] = 1;

        for (int v : adj.get(node)) {
            if (vis[v] == 0) {
                if (dfs(v, adj, vis, pathVis)) return true;
            }
            else if (pathVis[v] == 1) {
                return true; // cycle detected
            }
        }

        pathVis[node] = 0; // backtrack
        return false;
    }
}
