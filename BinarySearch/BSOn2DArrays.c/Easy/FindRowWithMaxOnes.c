class Solution {
    public int rowWithMax1s(int[][] mat) {
        int rows = mat.length;
        int columns = mat[0].length;

        int ind = -1;
        int max = 0;

        for (int i = 0; i < rows; i++) {
            int left = 0, right = columns - 1;
            int c = columns; 

            while (left <= right) {
                int mid = (left + right) / 2;
                if (mat[i][mid] == 0) {
                    left = mid + 1;
                } else {
                    c = mid;
                    right = mid - 1;
                }
            }

            int ones = columns - c;
            if (ones > max) {
                max = ones;
                ind = i;   
            }
        }

        return max == 0 ? -1 : ind;
    }
}
