class Solution {
    public int sumOfPrimesInRange(int n) {
        int num = n;
        int rev = 0;
        while(num > 0) {
            int i = num%10;
            num /= 10;
            rev = rev*10 + i;
        }
        int min = Math.min(n,rev);
        int max = Math.max(n,rev);
        int res = getCount(min,max);
        return res;
    }

    public int getCount(int min, int max) {
        int sum = 0;
        for(int i=min;i<=max;i++) {
            if(isPrime(i)) {
                sum += i;
            }
        }
        return sum;
    }

    public boolean isPrime(int num) {
        if(num < 2) {
            return false;
        }
        for(int i=2;i<=num/2;i++) {
            if(num%i == 0) {
                return false;
            }
        }
        return true;
    }
}©leetcode