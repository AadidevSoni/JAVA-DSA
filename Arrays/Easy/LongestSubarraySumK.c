package Arrays;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

public class LongestSubarraySumK {

	public static void main(String[] args) {
		
		int nums[] = {1,2,1,1,1,2,1};
		int k = 3;
		int maxLength = Integer.MIN_VALUE;
		
		//BRUTE FORCE
		
		for(int i=0;i<nums.length;i++) {
			for(int j=i;j<nums.length;j++) {
				int sum = 0;
				for(int l=i;l<=j;l++) {
					sum += nums[l];
				}
				if(sum == k) {
					int len = j-i+1;
					if(len > maxLength) {
						maxLength = len;
					}
				}
			}
		}
		
		System.out.println("Max length of subaaray: " + maxLength);
		
		//BETTER
		
		maxLength = Integer.MIN_VALUE;
		
		for(int i=0;i<nums.length;i++) {
			int sum = 0;
			for(int j=i;j<nums.length;j++) {
				sum += nums[j];
				if(sum == k) {
					int len = j-i+1;
					if(len > maxLength) {
						maxLength = len;
					}
				}
			}
		}
		
		System.out.println("Max length of subaaray: " + maxLength);
		
		//Hashing
		
		int arr[] = {1,2,3,1,0,1,1,1,4,2,3};
		int target = 3;
		
		HashMap<Long, Integer> map = new HashMap<>(); 
		
		int maxLen = Integer.MIN_VALUE;
		long sum = 0;
		
		for(int i=0;i<arr.length;i++) {
			//Calculate prefix sum till index i
			sum += arr[i];
			
			if(sum == target) {
				maxLen = Math.max(maxLen,i+1);
			}
			
			// calculate the sum of remaining part i.e. x-k:
      long rem = sum - target;
			
      //Calculate the length and update maxLen:
      if (map.containsKey(rem)) {
          int len = i - map.get(rem);
          maxLen = Math.max(maxLen, len);
      }

      //Finally, update the map checking the conditions to avoid error when 0 is present
      if (!map.containsKey(sum)) {
          map.put(sum, i);
      }
		}
		
		System.out.println("Max length: " + maxLen);
		
		//2 pointer
		
		target = 6;
		sum = arr[0];
		maxLen = 0;
		int left = 0;
		int right = 0;
		int n = nums.length;
			
		while(right < n) {
			while(left <= right && sum > target) {
				sum -= arr[left];
				left++;
			}
			
			if(sum == target) {
				maxLen = Math.max(maxLen, right-left+1);
			}
			
			right++;
			if(right < n) {
				sum += arr[right];
			}
		}
		
		System.out.println("Max length: " + maxLen);

	}
	
	

}
