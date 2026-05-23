import java.util.*;
import java.lang.*;
import java.io.*;

class Codechef
{
	public static void main (String[] args) throws java.lang.Exception
	{
		Scanner sc = new Scanner(System.in);
		int t = sc.nextInt();
		while(t-- > 0) {
		    int n = sc.nextInt();
		    int[] arr = new int[n];
		    for(int i=0;i<n;i++) {
		        arr[i] = sc.nextInt();
		    }
		    if(arr[0] == arr[n-1]) {
		        System.out.println(0);
		    }else {
		        int ans = Integer.MAX_VALUE;
		        for(int i=0; i<n; i++) {
    		        for(int j=i+1; j<n; j++) {
    		            if(arr[i] == arr[j]) {
    		                int cost = i + (n - 1 - j);
    		                ans = Math.min(ans, cost);
    		            }
    		        }
    		    }
    
    		    if(ans == Integer.MAX_VALUE) {
    		        System.out.println(-1);
    		    }
    		    else {
    		        System.out.println(ans);
    		    }
		    }
		}

	}
}
