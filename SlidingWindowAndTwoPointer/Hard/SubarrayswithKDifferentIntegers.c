//Brute
class Solution {
    public int subarraysWithKDistinct(int[] nums, int k) {
        int n = nums.length;
        int count = 0;
        for(int i=0;i<n;i++) {
            Map<Integer, Integer> map = new HashMap<>();
            for(int j=i;j<n;j++) {
                map.put(nums[j],map.getOrDefault(nums[j],0)+1);
                if(map.size() == k) {
                    count++;
                }else if(map.size() > k) {
                    break;
                }
            }
        }
        return count;
    }
}

//Optimal 
class Solution {
    public int subarraysWithKDistinct(int[] nums, int k) {
        return atMost(nums, k) - atMost(nums, k - 1);
    }

    public int atMost(int[] nums, int k) {
        int count = 0;
        int left = 0;
        int n = nums.length;
        Map<Integer, Integer> map = new HashMap<>();
        for(int right = 0;right < n;right++) {
            map.put(nums[right], map.getOrDefault(nums[right],0)+1);
            if(map.get(nums[right]) == 1) {
                k--;
            }
            while(k < 0) {
                map.put(nums[left], map.getOrDefault(nums[left],0)-1);
                if(map.get(nums[left]) == 0) {
                    k++;
                }
                left++;
            }
            count += right-left+1;
        }
        return count;
    }
}