class Solution {
    public void wiggleSort(int[] nums) {
        int c = 0;
        int n = nums.length;
        int[] sorted = nums.clone();
        Arrays.sort(sorted);
        int mid = (n+1)/2;
        int i = mid-1; // end of smaller half
        int j = n-1; // end of bigger half
        for(int k=0;k<n;k++) {
            if(k%2 == 0) {
                nums[k] = sorted[i--];
            }else {
                nums[k] = sorted[j--];
            }
        }
    }
}