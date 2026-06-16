class Solution {
    public void nextPermutation(int[] nums) {
        int pivot = -1;
        int n = nums.length;
        for(int i=n-1;i>0;i--) {
            if(nums[i-1] < nums[i]) {
                pivot = i-1;
                break;
            }
        }
        if(pivot == -1) {
            int left = pivot+1;
            int right = n-1;
            while(left < right) {
                int temp = nums[left];
                nums[left] = nums[right];
                nums[right] = temp;
                left++;
                right--;
            }
        }else {
            //Smallest after pivot
            int minIndex = n - 1;
            while(nums[minIndex] <= nums[pivot]) {
                minIndex--;
            }
            //Swap pivot and smallest 
            int temp = nums[pivot];
            nums[pivot] = nums[minIndex];
            nums[minIndex] = temp;
            //Reverse after pivot;
            int left = pivot+1;
            int right = n-1;
            while(left < right) {
                temp = nums[left];
                nums[left] = nums[right];
                nums[right] = temp;
                left++;
                right--;
            }
        }
    }
}