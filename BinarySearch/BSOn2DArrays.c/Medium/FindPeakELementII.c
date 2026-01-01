//Brute force 
class Solution {
    public int[] findPeakGrid(int[][] mat) {
        int rows = mat.length;
        int columns = mat[0].length;
        int max = Integer.MIN_VALUE;
        int row = -1;
        int col = -1;
        for(int r=0;r<rows;r++) {
            for(int c=0;c<columns;c++) {
                if(mat[r][c] > max) {
                    row = r;
                    col = c; 
                    max = mat[r][c];
                }
            }
        }
        int[] ans = {row,col};
        return ans;
    }
}

//Optimal 
class Solution {
    public int[] findPeakGrid(int[][] mat) {
        int rows = mat.length;
        int cols = mat[0].length;

        int low = 0, high = cols - 1;

        while (low <= high) {
            int mid = (low + high) / 2;

            // Find row index of max element in mid column
            int maxRow = 0;
            for (int i = 0; i < rows; i++) {
                if (mat[i][mid] > mat[maxRow][mid]) {
                    maxRow = i;
                }
            }

            int left = mid - 1 >= 0 ? mat[maxRow][mid - 1] : -1;
            int right = mid + 1 < cols ? mat[maxRow][mid + 1] : -1;

            // Check peak condition
            if (mat[maxRow][mid] > left && mat[maxRow][mid] > right) {
                return new int[]{maxRow, mid};
            }
            // Move search space
            else if (right > mat[maxRow][mid]) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        return new int[]{-1, -1};
    }
}
