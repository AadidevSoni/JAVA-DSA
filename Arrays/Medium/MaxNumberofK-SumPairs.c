class Solution {
    public int maxOperations(int[] nums, int k) {
        Map<Integer, Integer> map = new HashMap<>();
        int n = nums.length;
        int count = 0;
        for(int i=0;i<n;i++) {
            int target = k-nums[i];
            if(map.getOrDefault(target,0) > 0) {
                map.put(target,map.get(target)-1);
                count++;
            }else {
                map.put(nums[i], map.getOrDefault(nums[i],0)+1);
            }
        }
        return count;
    }
}