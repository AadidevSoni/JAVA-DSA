class Solution {
    public boolean checkGoodInteger(int n) {
        int digitSum = 0;
        int squareSum = 0;
        while(n > 0) {
            int x = n%10;
            digitSum += x;
            squareSum += x*x;
            n /= 10;
        }
        if(squareSum - digitSum >= 50) {
            return true;
        }else {
            return false;
        }
    }
}©leetcode