package Arrays;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.HashSet;
import java.util.List;
import java.util.Set;

public class Practice {

	public static void main(String[] args) {
		
		//Brute Force
		
		int nums[] = {1,2,5,3,1,2};
		List<Integer> res = new ArrayList<>();
		
		for(int i=0;i<nums.length;i++) {
			int max = nums[i];
			int greater = 0;			for(int j=i+1;j<nums.length;j++) {
				if(nums[j] >= max) {
					greater++;
				}
			}
			if(greater == 0) {
				res.add(max);
			}
		}
		
		for(int n: res) {
			System.out.print(n + " ");
		}
		System.out.println();
		
		//Optimal - Back iteration
		
		List<Integer> ans = new ArrayList<>();
		int n = nums.length;
		int max = Integer.MIN_VALUE;
		
		for(int i=n-1;i>=0;i--) {
			if(nums[i] > max) {
				ans.add(nums[i]);
				max = nums[i];
			}
		}
		
		Collections.reverse(ans);
		
		for(int r: ans) {
			System.out.print(r + " ");
		}
        
	}
	
}
