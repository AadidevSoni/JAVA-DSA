class Solution {
    public int findLongestChain(int[][] pairs) {
        int n = pairs.length;
        int res = 0;
        int prevEnd = Integer.MIN_VALUE;
        Arrays.sort(pairs, (a, b) -> a[1] - b[1]);
        for(int i=0;i<n;i++) {
            if(prevEnd < pairs[i][0]) {
                res++;
                prevEnd = pairs[i][1];
            }
        }
        return res;
    }
}