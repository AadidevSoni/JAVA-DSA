class Solution {
    public long maxRatings(int[][] units) {
        int m = units.length;
        int n = units[0].length;

        if(n == 1) {
            long res = 0;
            for(int[] z: units) {
                res += z[0];
            }
            return res;
        }

        long ans = 0;
        long inc = 0;

        int smallestRate = Integer.MAX_VALUE;

        int[] smallest = new int[m];
        int[] secondS = new int[m];
        for(int i=0;i<m;i++) {
            int min = Integer.MAX_VALUE;
            int min1 = Integer.MAX_VALUE;
            for(int num: units[i]) {
                if(num < min) {
                    min1 = min;
                    min = num;
                }else if(num < min1) {
                    min1 = num;
                }
            }
            smallest[i] = min;
            if(min1 == Integer.MAX_VALUE) {
                min1 = 0;
            }
            secondS[i] = min1;

            ans += min;
            inc += (long) (min1 - min);

            smallestRate = Math.min(smallestRate,min);
            
        }

        long dec = Integer.MAX_VALUE;
        for(int i=0;i<m;i++) {
            dec = Math.min(dec, (long) secondS[i]-smallestRate);
        }
        return ans + inc - dec;
    }
}©leetcode