package Arrays;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.HashMap;
import java.util.HashSet;
import java.util.List;
import java.util.Map;
import java.util.Scanner;
import java.util.Set;

public class Practice {

	public static void main(String[] args) {
		
		//Brute force
		
		int nums[] = {-1,1,0,1,2,3};
		int target = 0;
		int max = Integer.MIN_VALUE;
		
		for(int i=0;i<nums.length;i++) {
			for(int j=i;j<nums.length;j++) {
				int sum = 0;
				for(int k=i;k<=j;k++) {
					sum += nums[k];
				}
				if(sum == target) {
					int length = j-i+1;
					if(length > max) {
						max = length;
					}
				}
			}
		}
		
		System.out.println("Longest subarray: " + max);
		
		//Better
		
		max = Integer.MIN_VALUE;
		for(int i=0;i<nums.length;i++) {
			int sum = 0;
			for(int j=i;j<nums.length;j++) {
				sum += nums[j];
				if(sum == target) {
					int length = j-i+1;
					if(length > max) {
						max = length;
					}
				}
			}
		}
		
		System.out.println("Longest subarray: " + max);
		
		//Hashing
		
		HashMap<Integer, Integer> map = new HashMap<>();
		int sum = 0;
		max = Integer.MIN_VALUE;
		
		for(int i=0;i<nums.length;i++) {
			sum += nums[i];
			
			if(sum == target) {
				max = Math.max(max, i+1);
			}
			
			int rem = sum - target;
			
			if(map.containsKey(rem)) {
				int len = i-map.get(rem);
				max = Math.max(max,len);
			}
			
			if(!map.containsKey(sum)) {
				map.put(sum, i);
			}
			
		}
		
		System.out.println("Longest subarray: " + max);
		
	}
	
}
