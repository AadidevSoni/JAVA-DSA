class Solution {
    public boolean isHappy(int n) {
        
        int sum = 0;
        int count = 0;
        while(sum != 1) {
            sum = 0;
            while(n > 0) {
                int x = n % 10;
                sum += x * x;
                n /= 10;
            }
            count++;
            n = sum;
            if(count > 10) {
                return false;
            }
        }
        return true;

    }
}