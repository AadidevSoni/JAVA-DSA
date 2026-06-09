class Solution {
    public List<List<Integer>> subsets(int[] nums) {
        int n = nums.length;
        int subsets = 1 << n;
        List<List<Integer>> lst = new ArrayList<>();
        for(int i=0;i<subsets;i++) {
            List<Integer> sub = new ArrayList<>();
            for(int j=0;j<n;j++) {
                if ((i & (1 << j)) != 0) {
                    sub.add(nums[j]);
                }
            }
            lst.add(sub);
        }
        return lst;
    }
}