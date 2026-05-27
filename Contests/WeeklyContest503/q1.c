class Solution {
    public int[] limitOccurrences(int[] nums, int k) {
        List<Integer> lst = new ArrayList<>();
        int count = 0;
        int prev = -1;
        for(int n: nums) {
            if(n != prev) {
                count = 1;
                prev = n;
            }
            if(count <= k) {
                lst.add(n);
                count++;
            }            
        }
        int[] res = new int[lst.size()];
        for(int i=0;i<lst.size();i++) {
            res[i] = lst.get(i);
        }
        return res;
    }
}