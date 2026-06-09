class Solution {
    public int[] pivotArray(int[] nums, int pivot) {
        List<Integer> smaller = new ArrayList<>();
        List<Integer> larger = new ArrayList<>();
        List<Integer> equal = new ArrayList<>();
        for(int i=0;i<nums.length;i++) {
            if(nums[i] < pivot) {
                smaller.add(nums[i]);
            }else if(nums[i] > pivot) {
                larger.add(nums[i]);
            }else {
                equal.add(nums[i]);
            }
        }
        int i = 0;
        for(int j=0;j<smaller.size();j++) {
            nums[i] = smaller.get(j);
            i++;
        }
        for(int j=0;j<equal.size();j++) {
            nums[i] = equal.get(j);
            i++;
        }
        for(int j=0;j<larger.size();j++) {
            nums[i] = larger.get(j);
            i++;
        }
        return nums;
    }
}