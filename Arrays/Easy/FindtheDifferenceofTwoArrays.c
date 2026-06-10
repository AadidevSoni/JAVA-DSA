class Solution {
    public List<List<Integer>> findDifference(int[] nums1, int[] nums2) {

        Set<Integer> set1 = new HashSet<>();
        Set<Integer> set2 = new HashSet<>();
        for (int x: nums1) {
            set1.add(x);
        }
        for (int x: nums2) {
            set2.add(x);
        }

        List<Integer> sub1 = new ArrayList<>();
        for (int x: set1) {
            if (!set2.contains(x)) {
                sub1.add(x);
            }
        }

        List<Integer> sub2 = new ArrayList<>();
        for (int x: set2) {
            if (!set1.contains(x)) {
                sub2.add(x);
            }
        }

        List<List<Integer>> res = new ArrayList<>();
        res.add(sub1);
        res.add(sub2);

        return res;
    }
}