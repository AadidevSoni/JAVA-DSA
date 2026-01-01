//Better 
class Solution {
    public boolean searchMatrix(int[][] matrix, int target) {
        int rows = matrix.length;
        int columns = matrix[0].length;
        for(int i=0;i<rows;i++) {
            int left = 0;
            int right = columns - 1;
            while(left <= right) {
                int mid = (left + right)/2;
                if(matrix[i][mid] == target) {
                    return true;
                }else if(matrix[i][mid] < target) {
                    left = mid + 1;
                }else {
                    right = mid - 1;
                }
            }
        }
        return false;
    }
}

//Optimal 
class Solution {
    public boolean searchMatrix(int[][] matrix, int target) {
        int rows = matrix.length;
        int columns = matrix[0].length;
        int r = 0;
        int c = columns - 1;
        while(r < rows && c >= 0) {
            if(matrix[r][c] == target) {
                return true;
            }else if(matrix[r][c] < target) {
                r++;
            }else {
                c--;
            }
        }
        return false;
    }
}