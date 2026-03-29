package main;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.Comparator;
import java.util.List;

import javax.swing.JFrame;

public class Main {

	public static void main(String[] args) {
		
		int[] nums = {10, 9, 2, 5, 3, 7, 101, 18};
		int n = nums.length;
		int[] dp = new int[n]; //dp[i] is max LIS size till index i
		Arrays.fill(dp, 1);
		int[] prev = new int[n];
		Arrays.fill(prev, -1);
		
		for(int i=1;i<n;i++) {
			for(int j=0;j<n;j++) {
				if(nums[j] < nums[i] && dp[j]+1 > dp[i]) {
					dp[i] = dp[j] + 1;
					prev[i] = j;
				}
			}
		}
		
		int maxVal = Integer.MIN_VALUE;
		int maxIndex = -1;
		for(int i=0;i<n;i++) {
			if(dp[i] > maxVal) {
				maxVal = dp[i];
				maxIndex = i;
			}
		}
		
		int idx = maxIndex;
		List<Integer> lst = new ArrayList<>();
		while(idx != -1) {
			lst.add(nums[idx]);
			idx = prev[idx];
		}
		Collections.reverse(lst);
		int sz = lst.size();
		int[] arr = new int[sz];
		int i = 0;
		for(int num: lst) {
			arr[i] = num;
			i++;
		}
		System.out.print("LIS: ");
		for(int j=0;j<sz;j++) {
			System.out.print(arr[j]);
			if(j != sz-1) {
				System.out.print(", ");
			}
		}
		System.out.println();

	}

}
