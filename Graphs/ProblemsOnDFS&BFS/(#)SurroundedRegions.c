class Solution {
    public void solve(char[][] board) {
        int r = board.length;
        int c = board[0].length;

        int[][] vis = new int[r][c];
        for(int i=0;i<r;i++) {
            for(int j=0;j<c;j++) {
                vis[i][j] = 0;
            }
        }

        Queue<Pair> queue = new LinkedList<>();
        int drow[] = {-1,0,1,0};
        int dcol[] = {0,1,0,-1};
        for(int i=0;i<c;i++) {
            if(board[0][i] == 'O' && vis[0][i] == 0) {
                dfs(0,i,vis,drow,dcol,board);
            }
            if(board[r-1][i] == 'O' && vis[r-1][i] == 0) {
                dfs(r-1,i,vis,drow,dcol,board);
            }
        }
        for(int i=0;i<r;i++) {
            if(board[i][0] == 'O' && vis[i][0] == 0) {
                dfs(i,0,vis,drow,dcol,board);
            }
            if(board[i][c-1] == 'O' && vis[i][c-1] == 0) {
                dfs(i,c-1,vis,drow,dcol,board);
            }
        }

        for(int i=0;i<r;i++) {
            for(int j=0;j<c;j++) {
                if(board[i][j] == 'O' && vis[i][j] == 0) {
                    board[i][j] = 'X';
                }
            }
        }
    }

    public static void dfs(int row, int col, int[][] vis, int[] drow, int[] dcol, char[][] board) {
        vis[row][col] = 1;
        int r = board.length;
        int c = board[0].length;
        for(int i=0;i<4;i++) {
            int nrow = row + drow[i];
            int ncol = col + dcol[i];
            if(nrow >= 0 && nrow < r && ncol >= 0 && ncol < c && vis[nrow][ncol] == 0 && board[nrow][ncol] == 'O') {
                dfs(nrow,ncol,vis,drow,dcol,board);
            }
        }
    }
}

class Pair {
    int row;
    int col;
    Pair(int row, int col) {
        this.row = row;
        this.col = col;
    }
}