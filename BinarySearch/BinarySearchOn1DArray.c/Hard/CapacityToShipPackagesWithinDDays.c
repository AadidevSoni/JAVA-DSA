class Solution {
    public int shipWithinDays(int[] weights, int days) {
        int sum = 0;
        int max = Integer.MIN_VALUE;
        int n = weights.length;
        for(int i=0;i<n;i++) {
            sum += weights[i];
            if(weights[i] > max) {
                max = weights[i];
            }
        }
        int left = max;
        int right = sum;
        int result = -1;
        while(left <= right) {
            int mid = (left+right)/2;
            int day = 1;
            int c = 0;
            for(int w: weights) {
                if(c+w > mid) {
                    day++;
                    c = 0;
                }
                c+=w;
            }

            if(day <= days) {
                result = mid;
                right = mid-1;
            }else {
                left = mid+1;
            }
        }
        return result;
    }
}