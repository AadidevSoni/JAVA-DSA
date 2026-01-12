class Solution {
    public int minimumEffortPath(int[][] heights) {
        int n = heights.length;
        int m = heights[0].length;
        int[][] effort = new int[n][m];
        for(int i=0;i<n;i++) {
            Arrays.fill(effort[i],Integer.MAX_VALUE);
        }
        int minEffort = Integer.MAX_VALUE;
        PriorityQueue<Pair> queue = new PriorityQueue<>((a,b) -> a.e - b.e);
        queue.add(new Pair(0,0,0));
        int[] drow = {-1,0,0,1};
        int[] dcol = {0,-1,1,0};
        while(!queue.isEmpty()) {
            Pair cell = queue.peek();
            int x = cell.x;
            int y = cell.y;
            int e = cell.e;
            queue.remove();
            if(effort[x][y] < e) continue;
            if(x == n-1 && y == m-1) return e;
            for(int i=0;i<4;i++) {
                int nx = x + drow[i];
                int ny = y + dcol[i];

                if(nx >= 0 && nx < n && ny >= 0 && ny < m) {
                    int newEffort = Math.max(Math.abs(heights[nx][ny] - heights[x][y]),e);
                    if(newEffort < effort[nx][ny]) {
                        effort[nx][ny] = newEffort;
                        queue.add(new Pair(nx,ny,newEffort));
                    }
                }
            }
        }
        return 0;
    }
}

class Pair {
    int x;
    int y;
    int e;
    Pair(int x, int y, int e) {
        this.x = x;
        this.y = y;
        this.e = e;
    }
}