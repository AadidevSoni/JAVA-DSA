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
	        int sum = arr[0] + arr[n-1];
	        boolean possible = true;
	        for(int i=0;i<=n/2;i++) {
	            if(arr[i] + arr[n-i-1] != sum) {
	                possible = false;
	                break;
	            }
	        }
	        if(possible) {
	            System.out.println("Yes");
	        }else {
	            System.out.println("No");
	        }
	    }

	}
}
