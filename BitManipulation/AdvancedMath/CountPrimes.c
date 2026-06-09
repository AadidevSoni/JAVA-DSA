//TLE
class Solution {
    public int countPrimes(int n) {
        int count = 0;
        for(int i=2;i<n;i++) {
            if(isPrime(i)) {
                count++;
            }
        }
        return count;
    }

    public boolean isPrime(int n) {
        if(n < 2) {
            return false;
        }
        for(int i=2;i*i <= n;i++) {
            if(n%i == 0) {
                return false;
            }
        }
        return true;
    }
}

//Optimal
class Solution {
    public int countPrimes(int n) {
        int count = 0;
        int[] prime = new int[n+1];
        for(int i=2;i<=n;i++) {
            prime[i] = 1;
        }
        for(int i=2;i<=n;i++) {
            if(prime[i] == 1) {
                for(int j=2*i;j<=n;j+=i) {
                    prime[j] = 0;
                }
            }
        }
        for(int i=2;i<n;i++) {
            if(prime[i] == 1) {
                count++;
            }
        }
        return count;
    }
}
