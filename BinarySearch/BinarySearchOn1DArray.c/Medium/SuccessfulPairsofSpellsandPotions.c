class Solution {
    public int[] successfulPairs(int[] spells, int[] potions, long success) {
        int n = spells.length;
        int m = potions.length;
        Arrays.sort(potions);
        int[] res = new int[n];
        for(int i=0;i<n;i++) {
            int left = 0;;
            int right = m-1;
            int idx = m;
            while(left <= right) {
                int mid = left + (right-left)/2;
                long product = (long)spells[i] * potions[mid];
                if((long)product >= success) {
                    idx = mid;
                    right = mid-1;
                }else {
                    left = mid+1;
                }
            }
            res[i] = m-idx;
        }
        return res;
    }
}