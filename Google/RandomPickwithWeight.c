class Solution {
    int[] prefixSum;
    Random rand;
    int total;

    public Solution(int[] w) {
        prefixSum = new int[w.length];
        rand = new Random();
        prefixSum[0] = w[0];
        for(int i=1;i<w.length;i++) {
            prefixSum[i] = prefixSum[i-1]+w[i];
        }
        total = prefixSum[w.length-1];
    }
    
    public int pickIndex() {
        int target = rand.nextInt(total)+1;
        int left = 0;
        int right = prefixSum.length-1;
        while(left < right) {
            int mid = left + (right-left)/2;
            if(prefixSum[mid] >= target) {
                right = mid;
            }else {
                left = mid+1;
            }
        }
        return left;
    }
}

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(w);
 * int param_1 = obj.pickIndex();
 */