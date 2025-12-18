class Solution {
    public int NthRoot(int N, int M) {
        int left = 1;
        int right = M;
        int result = 0;
        while(left <= right) {
            int mid = (left + right)/2;
            int res = 1;
            for(int i=0;i<N;i++) {
                res *= mid;
            }
            if( res == M) {
                return mid;
            }else if(res < M) {
                result = mid;
                left = mid + 1;
            }else {
                right = mid - 1;
            }
        }
        return -1;
    }
}
  