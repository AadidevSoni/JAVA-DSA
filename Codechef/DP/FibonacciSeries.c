import java.util.Scanner;
import java.util.Arrays;

public class Main {
    static long fib(int n, long[] dp) {
        if(n <= 1) {
            return n;
        }
        if(dp[n] != -1) {
            return dp[n];
        }
        dp[n] = fib(n-1,dp) + fib(n-2,dp);
        return dp[n];
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        long[] dp = new long[n+1];
        Arrays.fill(dp,-1);
        System.out.println(fib(n-1,dp));
        sc.close();
    }
}

