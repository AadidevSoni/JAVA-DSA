class Solution {
    public int candy(int[] ratings) {
        int n = ratings.length;
        int[] left = new int[n];
        int[] right = new int[n];
        left[0] = 1;
        right[n-1] = 1;
        for(int i=1;i<n;i++) {
            if(ratings[i] > ratings[i-1]) {
                left[i] = left[i-1] + 1;
            }else {
                left[i] = 1;
            }
        }
        for(int i=n-2;i>=0;i--) {
            if(ratings[i] > ratings[i+1]) {
                right[i] = right[i+1] + 1;
            }else {
                right[i] = 1;
            }
        }
        int sum = 0;
        for(int i=0;i<n;i++) {
            sum += Math.max(left[i],right[i]);
        }
        return sum;
    }
}

class Solution {
    public int candy(int[] ratings) {
        int n = ratings.length;
        int[] left = new int[n];
        left[0] = 1;

        for (int i = 1; i < n; i++) {
            if (ratings[i] > ratings[i - 1]) {
                left[i] = left[i - 1] + 1;
            } else {
                left[i] = 1;
            }
        }

        int sum = left[n - 1];
        int curr = 1;

        for (int i = n - 2; i >= 0; i--) {
            if (ratings[i] > ratings[i + 1]) {
                curr += 1;
            } else {
                curr = 1;
            }
            sum += Math.max(left[i], curr);
        }

        return sum;
    }
}
