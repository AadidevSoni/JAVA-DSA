class Solution {
    public int countPrimeSetBits(int left, int right) {
        int result = 0;
        for(int i=left;i<=right;i++) {
            String bin = Integer.toBinaryString(i);
            int count = 0;
            for(int j=0;j<bin.length();j++) {
                if(bin.charAt(j) == '1') {
                    count++;
                }
            }
            if(isPrime(count)) {
                result++;
            }
        }

        return result;
    }

    public boolean isPrime(int n) {
        if(n < 2) {
            return false;
        }
        for(int i=2;i<=n/2;i++) {
            if(n%i == 0) {
                return false;
            }
        }
        return true;
    }
}