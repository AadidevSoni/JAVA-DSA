class Solution {
    public boolean isValidSudoku(char[][] board) {
        Set<String> set = new HashSet<>();
        int n = board.length;
        int m = board[0].length;
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                if(board[i][j] == '.') {
                    continue;
                }
                char num = board[i][j];
                if(!set.add(num + " in row " + i) || !set.add(num + " in col " + j) || !set.add(num + " in box " + i/3 + " - " + j/3)) {
                    return false;
                }
            }
        }
        return true;
    }
}