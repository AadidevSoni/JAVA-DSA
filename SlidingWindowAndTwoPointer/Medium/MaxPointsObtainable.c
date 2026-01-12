class Solution {
    public int maxScore(int[] cardPoints, int k) {
        int lsum = 0;
        int rsum = 0;
        int l = 0;
        int n = cardPoints.length;
        int r = n-1;
        int maxSum = 0;
        for(int i=0;i<k;i++) {
            lsum += cardPoints[i];
        }
        maxSum = lsum;
        l = k-1;
        for(int i=k-1;i>=0;i--){
            lsum -= cardPoints[l];
            rsum += cardPoints[r];
            r--;
            l--;
            int newSum = lsum + rsum;
            maxSum = Math.max(newSum, maxSum);
        }
        return maxSum;
    }
}