class Solution {
    public int minimumTotal(List<List<Integer>> triangle) {
        int n = triangle.size();
        int[][] dp = new int[n][n];
        for(int[] row: dp) {
            Arrays.fill(row, Integer.MAX_VALUE);
        }
        int res = f(0,0,triangle,n,dp);
        return res;
    }

    public int f(int i, int j, List<List<Integer>> triangle,int n, int[][] dp) {
        if (i == n - 1){
            return triangle.get(i).get(j);
        }
        if(dp[i][j] != Integer.MAX_VALUE) {
            return dp[i][j];
        }
        int down = triangle.get(i).get(j) + f(i+1,j,triangle,n,dp);
        int diag = triangle.get(i).get(j) + f(i+1,j+1,triangle,n,dp);   
        dp[i][j] = Math.min(down,diag); 
        return dp[i][j];
    }
}