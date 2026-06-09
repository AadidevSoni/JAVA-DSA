class Solution {
    public int findCircleNum(int[][] isConnected) {
        int n = isConnected.length; //number of vertices

        int provinces = 0;

        int[] visited = new int[n];

        for(int i=0;i<n;i++) {
            if(visited[i] == 0) {
                provinces++;
                dfs(i,isConnected,provinces,visited);
            }
        }

        return provinces;
    }

    public static void dfs(int node, int[][] isConnected, int provinces, int[] visited) {
        visited[node] = 1;
        int n = isConnected.length;
        for(int j=0;j<n;j++) {
            if(isConnected[node][j] == 1 && visited[j] == 0) {
                dfs(j,isConnected,provinces,visited);
            }
        }
        
    }
}