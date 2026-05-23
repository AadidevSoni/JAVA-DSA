class Solution {
    public int minDays(int[] bloomDay, int m, int k) {
        int n = bloomDay.length;
        if(m*k > n) {
            return -1;
        }
        int max = Integer.MIN_VALUE;
        int min = Integer.MAX_VALUE;
        for(int i=0;i<n;i++) {
            if(bloomDay[i] > max) {
                max = bloomDay[i];
            }
            if(bloomDay[i] < min) {
                min = bloomDay[i];
            }
        }

        int left = min;
        int right = max;
        int result = -1;
        while(left <= right) {
            int mid = (left+right)/2;
            int c = 0;
            int count = 0;
            for(int i=0;i<n;i++) {
                if(bloomDay[i] <= mid) {
                    c++;
                }else {
                    count += c/k;
                    c = 0;
                }
            }
            // IMPORTANT: add last segment
            count += c / k;

            if(count >= m) {
                result = mid;
                right = mid-1;
            }else {
                left = mid+1;
            }
        }
        return result;
    }
}