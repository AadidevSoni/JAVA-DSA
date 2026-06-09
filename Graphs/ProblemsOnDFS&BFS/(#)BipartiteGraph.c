class Solution {
    public boolean isBipartite(int[][] graph) {
        int n = graph.length;
        int[] color = new int[n];
        Arrays.fill(color,-1);

        for(int i=0;i<n;i++) {
            if(color[i] == -1) {
                if(!dfs(i,0,color,graph)) {
                    return false;
                }
            }
        }

        return true;
    }
    public boolean dfs(int node, int color, int[] colors, int[][] graph) {
        colors[node] = color;
        for(int n: graph[node]) {
            if(colors[n] == -1) {
                if(!dfs(n,1-color,colors,graph)) {
                    return false;
                }
            }else if(colors[n] == color) {
                return false;
            }
        }
        return true;
    }
}
