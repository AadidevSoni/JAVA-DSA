class Solution {
    public int maxDistance(int[] colors) {
        int n = colors.length;
        int max = 0;
        for(int i=0;i<n;i++) {
            for(int j=i+1;j<n;j++) {
                if(colors[j] != colors[i]) {
                    max = Math.max(j-i, max);
                }
            }
        }
        return max;
    }
}