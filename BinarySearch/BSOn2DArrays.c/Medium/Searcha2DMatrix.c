class Solution {
    public boolean searchMatrix(int[][] matrix, int target) {
        int rows = matrix.length;
        int columns = matrix[0].length;

        for(int i=0;i<rows;i++) {
            if (matrix[i][0] <= target && target <= matrix[i][columns - 1]) {
                int right = columns-1;
                int left = 0;
                while(left <= right) {
                    int mid = (left + right)/2;
                    if(matrix[i][mid] == target) {
                        return true;
                    }else if(matrix[i][mid] < target) {
                        left = mid+1;
                    }else {
                        right = mid-1;
                    }
                }
            }
        }

        return false;

    }
}