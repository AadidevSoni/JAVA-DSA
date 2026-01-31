package entity;

import java.util.Arrays;
import java.util.Scanner;

public class Priority {

    public static void main(String[] args) {
    	
    	String text1 = "abgde";
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
        int max = Integer.MIN_VALUE;
        for(int i=1;i<=s1;i++) {
            for(int j=1;j<=s2;j++) {
                if(text1.charAt(i-1) == text2.charAt(j-1)) { 
                    dp[i][j] = 1 + dp[i-1][j-1];
                    if(dp[i][j] > max) {
                    	max = dp[i][j];
                    }
                }else {
                    dp[i][j] = 0;
                    
                }
            }
        }
        
        System.out.println(max);

        
    }
}
