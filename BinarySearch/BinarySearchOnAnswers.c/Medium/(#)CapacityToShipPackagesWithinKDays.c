class Solution {
    public int shipWithinDays(int[] weights, int days) {
        int n = weights.length;
        int sum = 0;
        int max = Integer.MIN_VALUE;
        for(int i=0;i<n;i++) {
            if(weights[i] > max) {
                max = weights[i];
            }
            sum += weights[i];
        }
        int low = max;
        int high = sum;
        int res = -1;
        while(low <= high) {
            int mid = (low+high)/2;
            int day = 1;
            int c = 0;
            for(int w: weights) {
                if(c+w > mid) {
                    day++;
                    c = 0;
                } 
                c += w;
            }
            if(day <= days) {
                res = mid;
                high = mid - 1;
            }else {
                low = mid+1;
            }
        }
        return res;
    }
}