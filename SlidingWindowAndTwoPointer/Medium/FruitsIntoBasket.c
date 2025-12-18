//Brute force

class Solution {
    public int totalFruits(int[] fruits) {
        //max length subarray with atmost 2 types of fruits
        int maxLen = 0;
        int n = fruits.length;
        for(int i=0;i<n;i++) {
            Set<Integer> set = new HashSet<>();
            for(int j=i;j<n;j++) {
                set.add(fruits[j]);
                if(set.size() <= 2) {
                    maxLen = Math.max(maxLen,j-i+1);
                }else{
                    break;
                }
            }
        }
        return maxLen;
    }
}