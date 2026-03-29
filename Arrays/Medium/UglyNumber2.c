//Brute Force 

class Solution {
    public int nthUglyNumber(int n) {
        if (n == 1) return 1;
        int count = 1;
        int i = 2;
        while(true) {
            if (isUgly(i)) {
                count++;
                if (count == n) return i;
            }
            i++;
        }
    }

    public boolean isUgly(int n) {
        int[] factors = {2,3,5};
        for(int f: factors) {
            while(n % f == 0) {
                n /= f;
            }
        }
        return n == 1;
    }
}

