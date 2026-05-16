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
		    long ans = 0;
		    int[] dp = new int[N+1];
		    Arrays.fill(dp,-1);
		    for(int i=0;i<N;i++) {
		        ans += f(i,arr,N,dp);
		    }
		    System.out.println(ans);
		}
	}
	
	public static int f(int ind,int[] arr,int n,int[] dp) {
	    if(ind == n-1) {
	        return 1;
	    }
	    if(dp[ind] != -1) {
	        return dp[ind];
	    }
	    if(arr[ind] <= arr[ind+1]) {
	        dp[ind] = 1 + f(ind+1,arr,n,dp);
	        return dp[ind];
	    }
	    dp[ind] = 1;
	    return dp[ind];
	}
}
