class Solution {
    public int largestAltitude(int[] gain) {
        int n = gain.length;
        int[] alt = new int[n+1];
        alt[0] = 0;
        int max = 0;
        for(int i=0;i<n;i++) {
            alt[i+1] = alt[i] + gain[i];
            max = Math.max(max,alt[i+1]);
        }
        return max;
    }
}