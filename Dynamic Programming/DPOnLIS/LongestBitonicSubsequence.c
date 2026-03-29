package main;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.Comparator;
import java.util.List;

import javax.swing.JFrame;

public class Main {

	public static void main(String[] args) {
		
		int[] arr = {1,11,2,10,4,5,2,1};
		int n = arr.length;
		int[] dp1 = new int[n];
		int[] dp2 = new int[n];
		Arrays.fill(dp1, 1);
		Arrays.fill(dp2, 1);
		
		for(int i=1;i<n;i++) {
			for(int j=0;j<i;j++) {
				if(arr[j] < arr[i] && dp1[j]+1>dp1[i]) {
					dp1[i] = dp1[j]+1;
				}
			}
		}
		
		for(int i=n-2;i>=0;i--) {
			for(int j=n-1;j>i;j--) {
				if(arr[j] < arr[i] && dp2[j]+1>dp2[i]) {
					dp2[i] = dp2[j]+1;
				}
			}
		}
		
		int max = Integer.MIN_VALUE;
		for(int i=0;i<n;i++) {
			max = Math.max(max, dp1[i]+dp2[i]-1);
		}
		
		System.out.println("Longest bitonic subsequence: " + max);

	}

}
