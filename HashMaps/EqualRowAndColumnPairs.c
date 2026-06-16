class Solution {
    public int equalPairs(int[][] grid) {
        int n = grid.length;
        Map<String, Integer> rows = new HashMap<>();
        for(int i=0;i<n;i++) {
            StringBuilder st = new StringBuilder();
            for(int j=0;j<n;j++) {
                st.append(grid[i][j] + " ");
            }
            String r = st.toString();
            rows.put(r,rows.getOrDefault(r,0)+1);
        }
        int count = 0;
        for(int i=0;i<n;i++) {
            StringBuilder st = new StringBuilder();
            for(int j=0;j<n;j++) {
                st.append(grid[j][i] + " ");
            }
            String c = st.toString();
            count += rows.getOrDefault(c,0);
        }
        return count;
    }
}