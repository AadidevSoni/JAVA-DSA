package entity;

import java.util.Arrays;
import java.util.Scanner;

public class Priority {

    public static void main(String[] args) {
    	
    	String text1 = "abdge";
    	String text2 = "bge";
    	
    	int s1 = text1.length();
        int s2 = text2.length();
        int[][] dp = new int[s1+1][s2+1];
        for(int[] rows: dp) {
            Arrays.fill(rows, -1);
        }
        for(int j=0;j<=s2;j++) {
            dp[0][j] = 0;
        }
        for(int i=0;i<=s1;i++) {
            dp[i][0] = 0;
        }
        for(int i=1;i<=s1;i++) {
            for(int j=1;j<=s2;j++) {
                if(text1.charAt(i-1) == text2.charAt(j-1)) { 
                    dp[i][j] = 1 + dp[i-1][j-1];
                }else {
                    dp[i][j] = 0 + Math.max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }
        
        int n = dp[s1][s2];
        char[] res = new char[n];
        int ind = n-1;
        
        int i = s1;
        int j = s2;
        while(i > 0 && j > 0) {
        	if(text1.charAt(i-1) == text2.charAt(j-1)) {
        		res[ind] = text1.charAt(i-1);
        		ind--;
        		i--;
        		j--;
        	}else {
        		if(dp[i-1][j] > dp[i][j-1]) {
        			i--;
        		}else {
        			j--;
        		}
        	}
        }
        
        System.out.println("LCS Length: " + n);
        System.out.println("LCS String: " + new String(res));
        
    }
}
