class Solution {
    public int[] intersection(int[] nums1, int[] nums2) {
        Set<Integer> set1 = new HashSet<>();
        Set<Integer> set2 = new HashSet<>();
        int n = nums1.length;
        int m = nums2.length;
        for(int i=0;i<n;i++) {
            set1.add(nums1[i]);
        }
        for(int i=0;i<m;i++) {
            set2.add(nums2[i]);
        }
        List<Integer> res = new ArrayList<>();
        for(int num: set1) {
            if(set2.contains(num)) {
                res.add(num);
            }
        }
        int[] arr = new int[res.size()];
        for(int i=0;i<res.size();i++) {
            arr[i] = res.get(i);
        }
        return arr;
    }
}