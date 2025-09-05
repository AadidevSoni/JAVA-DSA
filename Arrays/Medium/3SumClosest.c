class Solution {
    public int threeSumClosest(int[] nums, int target) {
        Arrays.sort(nums);
        int n = nums.length;
        int closest = nums[0] + nums[1] + nums[2];

        for(int i=0;i<n;i++) {
            if(i!=0 && nums[i] == nums[i-1]) continue;
            int left = i+1;
            int right = n-1;
            while(left < right) {
                int current = nums[i] + nums[left] + nums[right];
                if(Math.abs(target - current) < Math.abs(target - closest)) {
                    closest = current;
                }

                if(current < target) {
                    left++;
                }else if(current > target){
                    right--;
                }else {
                    return target;
                }
            }
        }

        return closest;
    }
}