class Solution {
    public int findMinArrowShots(int[][] points) {
        int n = points.length;
        Arrays.sort(points, (a,b) -> Integer.compare(a[1], b[1]));
        if(n == 0) {
            return 0;
        }
        
        int arrows = 1;
        int arrowpos = points[0][1];
        for(int i=1;i<n;i++) {
            if(points[i][0] > arrowpos) {
                arrows++;
                arrowpos = points[i][1];
            }   
        }
        return arrows;
    }
}