//Brute force 
class Solution {
    public int minEatingSpeed(int[] piles, int h) {
        int n = piles.length;
        int b = 0;
        int sum = Integer.MAX_VALUE;
        while(sum > h) {
            b++;
            sum = 0;
            for(int i=0;i<n;i++) {
                if(piles[i] % b == 0) {
                    sum += (piles[i])/b;
                }else {
                    sum += ((piles[i])/b)+1;
                }
            }
        }
        return b;
    }
}

//Optimal 
class Solution {
    public int minEatingSpeed(int[] piles, int h) {
        int n = piles.length;
        int left = 1;

        int max = Integer.MIN_VALUE;
        for(int i=0;i<n;i++) {
            if(piles[i] > max) {
                max = piles[i];
            }
        }

        int ans = 0;

        int right = max;
        while(left <= right) {
            int mid = (left + right)/2; //eat mid bananas per hour
            long sum = 0;
            for(int i=0;i<n;i++) {
                if(piles[i] % mid == 0) {
                    sum += piles[i]/mid;
                }else {
                    sum += (piles[i]/mid)+1;
                }
            }

            if(sum <= h) {
                ans = mid;
                right = mid-1;
            }else {
                left = mid+1;
            }
        }

        return ans;
    }
}