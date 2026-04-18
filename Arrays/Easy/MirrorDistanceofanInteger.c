class Solution {
    public int mirrorDistance(int n) {
        int rev = reverse(n);
        return(Math.abs(rev - n));
    }

    public int reverse(int n) {
        int rev = 0;
        while(n > 0) {
            int l = n % 10;
            n /= 10;
            rev = rev*10 + l;
        }
        return rev;
    }
}