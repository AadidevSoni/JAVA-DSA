class Solution {
    public boolean uniformArray(int[] nums1) {
        int length = nums1.length;
        int minOdd = Integer.MAX_VALUE;
        int minEven = Integer.MAX_VALUE;
        int oddCount = 0;
        int evenCount = 0;
        for(int n: nums1) {
            if(n % 2 == 0) {
                evenCount++;
                minEven = Math.min(minEven, n);
            }else {
                minOdd = Math.min(minOdd, n);
                oddCount++;
            }
        }
        if(oddCount == length || evenCount == length) {
            return true;
        }
        if(minOdd < minEven) {
            return true;
        }else {
            return false;
        }
    }
}