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