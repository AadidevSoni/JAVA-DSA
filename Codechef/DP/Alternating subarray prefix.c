import java.util.*;
import java.lang.*;
import java.io.*;

class Codechef
{
	public static void main (String[] args) throws java.lang.Exception
	{
	    Scanner scanner = new Scanner(System.in);
	    int t = scanner.nextInt();
        while(t-- > 0) {
            int N = scanner.nextInt();
            int[] arr = new int[N];
            for(int i=0;i<N;i++) {
                arr[i] = scanner.nextInt();
            }
            int[] res = new int[N];
            int[] dp = new int[N+1];
            Arrays.fill(dp,-1);
            for(int i=0;i<N;i++) {
                System.out.print(f(i,arr,N,dp) + " ");
            }
            System.out.println();
        }
	}
	
	public static int f(int ind, int[] arr, int n,int[] dp) {
	    if(ind == n-1) {
	        return 1;
	    }
	    if(dp[ind] != -1) {
	        return dp[ind];
	    }
	    if((arr[ind] > 0 && arr[ind+1] < 0) || (arr[ind] < 0 && arr[ind+1] > 0)){
	        dp[ind] = 1 + f(ind+1,arr,n,dp);
	        return dp[ind];
	    }
	    return 1;
	}
}
