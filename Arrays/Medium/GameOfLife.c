class Solution {
    public void gameOfLife(int[][] board) {
        int n = board.length;
        int m = board[0].length;
        int[][] copy = new int[n][m];
        for (int i = 0; i < n; i++) {
            copy[i] = board[i].clone();
        }

        int[] drow = {-1,-1,0,1,1,1,0,-1};
        int[] dcol = {0,1,1,1,0,-1,-1,-1};
        for(int row=0;row<n;row++) {
            for(int col=0;col<m;col++) {
                int neigh = 0;
                for(int i=0;i<8;i++) {
                    int row_ = row + drow[i];
                    int col_ = col + dcol[i];
                    if(row_ >= 0 && row_ < n && col_ >= 0 && col_ < m && copy[row_][col_] == 1){
                        neigh++;
                    }
                }
                if(board[row][col] == 1) {
                    if(neigh < 2 || neigh > 3) {
                        board[row][col] = 0;
                    }
                }else {
                    if(neigh == 3) {
                        board[row][col] = 1;
                    }
                }
            }
        }
    }
}