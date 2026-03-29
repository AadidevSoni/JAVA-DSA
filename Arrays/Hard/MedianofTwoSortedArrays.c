class Solution {
    public double findMedianSortedArrays(int[] nums1, int[] nums2) {
        int i=0;
        int j=0;
        int n = nums1.length;
        int m = nums2.length;
        List<Integer> lst = new ArrayList<>();
        while(i < n && j < m) {
            if(nums1[i] < nums2[j]) {
                lst.add(nums1[i]);
                i++;
            }else {
                lst.add(nums2[j]);
                j++;
            }
        }
        if(i < n) {
            while(i < n) {
                lst.add(nums1[i]);
                i++;
            }
        }else {
            while(j < m) {
                lst.add(nums2[j]);
                j++;
            }
        }
        int sz = lst.size();
        double res = 0;
        if(sz == 1) {
            return lst.get(0);
        }
        if(sz%2 == 0) {
            int ind1 = sz/2 - 1;
            int ind2 = sz/2;
            int num1 = lst.get(ind1);
            int num2 = lst.get(ind2);
            res = (double) (num1 + num2)/2;
        }else {
            int mid = (int)sz/2;
            res = lst.get(mid);
        }
        return res;
    }
}