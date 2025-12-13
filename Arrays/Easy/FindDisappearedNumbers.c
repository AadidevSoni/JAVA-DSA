class Solution {
    public List<Integer> findDisappearedNumbers(int[] nums) {
        int n = nums.length;
        int[] numb = new int[n];
        for(int i=0;i<n;i++) {
            numb[i] = i+1;
        }

        for(int num: nums) {
            numb[num-1] = 0;
        }

        List<Integer> ans = new LinkedList<Integer>();
        for(int i=0;i<n;i++) {
            if(numb[i] != 0) {
                ans.add(numb[i]);
            }
        }

        return ans;
    }
}