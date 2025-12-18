class Solution {

    public int f(int day, int last, int[][] points) {
        if(day == 0) {
            int maxi = 0;
            for(int task=0;task<3;task++) {
                if(task != last) {
                    maxi = Math.max(maxi, points[0][task]);
                }
            }
            return maxi;
        }

        int maxi = 0;
        for(int task = 0;task<3;task++) {
            if(task != last) {
                int point = points[day][task] + f(day-1,task,points);
                maxi = Math.max(maxi, point);
            }
        }
        return maxi;
    }
    public int ninjaTraining(int[][] matrix) {
        int n = matrix.length;
        // 3 because 3 is last and by default iterating from n-1 to 0, n-1 have no last from 0 to 2 so 3
        return f(n-1, 3, matrix);
    }
}