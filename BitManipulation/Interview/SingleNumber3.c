package Arrays;

import java.util.*;

public class Practice {
	
	public static void main(String[] args) {
		
		int[] nums = {2,4,2,14,8,7,7,8};
		int n = nums.length;
		
		int xor = 0;
		for(int num: nums) {
			xor = xor ^ num;
		}
		
		int rightMostSet = (xor & (xor-1)) ^ xor;
		int bucket1 = 0;
		int bucket2 = 0;
		
		for(int i=0;i<n;i++) {
			if((nums[i] & rightMostSet) != 0) {
				bucket1 = bucket1 ^ nums[i];
			}else {
				bucket2 = bucket2 ^ nums[i];
			}
		}
		
		System.out.println("Two single numbers: " + bucket1 + " & " + bucket2);
		
		
    }
	
}
	


