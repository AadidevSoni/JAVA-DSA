class Solution {
    public int floorSqrt(int n) {
      int left = 1;
      int right = n;
      int result = 1;

      while(left <= right) {
        int mid = (left+right)/2;
        if(mid * mid <= n) {
            result = mid;
            left = mid + 1;
        }else {
            right = mid - 1;
        }
      }

        return result;
    }
}