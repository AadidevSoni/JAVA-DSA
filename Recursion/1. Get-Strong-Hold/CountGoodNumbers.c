public class CountGoodNumbers {
	
	static final int MOD = 1000000007;

	public static void main(String[] args) {
		
		int res = countGood(4);
		System.out.println(res);
	}
	
	public static int countGood(long n) {
        long even = (n+1)/2;
        long odd = n/2;

        long evenWays = modPow(5,even);
        long oddWays = modPow(4,odd);

        return (int) ((evenWays * oddWays)%MOD);
    }

    public static long modPow(long base, long exp) {
        long result = 1;
        base %= MOD;

        while(exp > 0) {
            if((exp&1) == 1) {
               result = (result * base) % MOD;
            }
            base = (base * base) % MOD;
            exp >>= 1;
        }
        return result;
    }

}
