class Solution {
    public int orangesRotting(int[][] grid) {
        int r = grid.length;
        int c = grid[0].length;

        Queue<Pair> queue = new LinkedList<>();

        int[][] visited = new int[r][c];

        int cntfresh = 0;
        for(int i=0;i<r;i++) {
            for(int j=0;j<c;j++) {
                if(grid[i][j] == 2) {
                    queue.add(new Pair(i,j,0));
                    visited[i][j] = 2;
                }else {
                    visited[i][j] = 0;
                }
                if(grid[i][j] == 1) {
                    cntfresh++;
                }
            }
        }     

        int tm = 0;
        int cnt = 0;
        int drow[] = {-1,0,1,0};
        int dcol[] = {0,1,0,-1};
        while(!queue.isEmpty()) {
            int ro = queue.peek().row;
            int co = queue.peek().col;
            int tim = queue.peek().time;
            tm = Math.max(tm,tim);
            queue.remove();

            for(int i=0;i<4;i++) {
                int row_ = ro + drow[i];
                int col_ = co + dcol[i];
                if(row_ >= 0 && row_ < r && col_ >= 0 && col_ < c && grid[row_][col_] == 1 && visited[row_][col_] == 0) {
                    queue.add(new Pair(row_,col_,tim+1));
                    visited[row_][col_] = 2;
                    cnt++;
                }
            }
        }   

        if(cnt != cntfresh) {
            return -1;
        }else {
            return tm;
        }
    }

    class Pair {
        int row;
        int col;
        int time;
        Pair(int _row, int _col, int _time) {
            row = _row;
            col = _col;
            time = _time;
        }
    }
}

//Cleaner 

class Solution {
    public int orangesRotting(int[][] grid) {
        int r = grid.length;
        int c = grid[0].length;

        Queue<Pair> rotten = new LinkedList<>();
        int[][] vis = new int[r][c];

        for(int i=0;i<r;i++) {
            for(int j=0;j<c;j++) {
                if(grid[i][j] == 2) {
                    vis[i][j] = 2;
                    rotten.offer(new Pair(i,j,0));
                }else {
                    vis[i][j] = 0;
                }
            }
        }

        int timeMax = 0;
        int[] drow = {-1,0,1,0};
        int[] dcol = {0,1,0,-1};

        while(!rotten.isEmpty()) {
            Pair orange = rotten.poll();
            int row = orange.row;
            int col = orange.col;
            int time = orange.time;
            timeMax = Math.max(timeMax, time);
            for(int i=0;i<4;i++) {
                int row_ = row + drow[i];
                int col_ = col + dcol[i];
                if(row_ >= 0 && row_ < r && col_ >=0 && col_ < c && grid[row_][col_] == 1 && vis[row_][col_] == 0) {
                    rotten.add(new Pair(row_,col_,time+1));
                    vis[row_][col_] = 2;
                }
            }
        }

        for(int i=0;i<r;i++) {
            for(int j=0;j<c;j++) {
                if(grid[i][j] == 1 && vis[i][j] != 2) {
                    return -1;
                }
            }
        }

        return timeMax;

    }
}

class Pair {
    int row;
    int col;
    int time;
    public Pair(int row, int col, int time) {
        this.row = row;
        this.col = col;
        this.time = time;
    }
}