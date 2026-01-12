class Solution {
    public int shortestPathBinaryMatrix(int[][] grid) {
        int n = grid.length;
        int m = grid[0].length;
        if (grid[0][0] == 1 || grid[n-1][m-1] == 1) return -1;
        int[][] dist = new int[n][m];
        for (int i = 0; i < n; i++) {
            Arrays.fill(dist[i], Integer.MAX_VALUE);
        }
        dist[0][0] = 1;
        Queue<Pair> queue = new LinkedList<>();
        queue.add(new Pair(0,0,1));
        int[] drow = {-1, -1, -1, 0, 0, 1, 1, 1};
        int[] dcol = {-1,  0,  1, -1, 1, -1, 0, 1};
        while(!queue.isEmpty()) {
            Pair cell = queue.peek();
            int x = cell.cellx;
            int y = cell.celly; 
            int d = cell.distance;
            queue.remove();
            if(d > dist[x][y]) continue;
            if (x == n-1 && y == m-1) return d;
            for (int i = 0; i < 8; i++) {
                int nx = x + drow[i];
                int ny = y + dcol[i];

                if (nx >= 0 && nx < grid.length && ny >= 0 && ny < grid[0].length && dist[nx][ny] > d+1 &&
                    grid[nx][ny] == 0) {
                        dist[nx][ny] = d+1;
                        queue.offer(new Pair(nx,ny,d+1));
                }
            }
        }
        return(-1);
    }
}

class Pair {
    int cellx;
    int celly;
    int distance;
    Pair(int cellx, int celly, int distance) {
        this.cellx = cellx;
        this.celly = celly;
        this.distance = distance;
    }
}