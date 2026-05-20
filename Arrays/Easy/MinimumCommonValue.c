class Solution {
    public int getCommon(int[] nums1, int[] nums2) {
        int n = nums1.length;
        int n1 = nums2.length;
        int i = 0;
        int j = 0;
        while(i<n && j<n1) {
            if(nums1[i] < nums2[j]) {
                i++;
            }else if(nums1[i] > nums2[j]) {
                j++;
            }else {
                return nums1[i];
            }
        }
        return -1;
    }
}