class Solution {
    public int[] separateDigits(int[] nums) {
        List<Integer> lst = new ArrayList<>();
        int n = nums.length;
        for(int i=n-1;i>=0;i--) {
            int num = nums[i];
            while(num > 0) {
                lst.add(num%10);
                num /= 10;
            }
        }
        int sz = lst.size();
        int[] res = new int[sz];
        int j = 0;
        for(int i=sz-1;i>=0;i--) {
            res[j] = lst.get(i);
            j++;
        }
        return res;
    }
}