package Arrays;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class MaxSubArraySum2 {

	public static void main(String[] args) {
		
		//Creating subarrays and checking 
		int nums[] = {-2,-3,4,-1,-2,1,5,-3};
		
		List<List<Integer>> res = findSubArray(nums);
        int max = Integer.MIN_VALUE;
        List<Integer> maxSub = new ArrayList<>();
        for(List<Integer> s: res) {
            int sum = 0;
            for(int n: s) {
                sum += n;  
            }
            if(sum > max) {
                max = sum;
                maxSub = s;
            }
        }
        System.out.println("Max sum: " + max);
        System.out.println(maxSub);
        
        //Kadane's Algorithm method
        int sum = 0;
        int maxm = Integer.MIN_VALUE;
        int ansStart = -1;
        int ansEnd = -1;
        int start = 0;
        for(int i=0;i<nums.length;i++) {
        	if(sum == 0) {
        		start = i;
        	}
        	sum += nums[i];
        	if(sum > maxm) {
        		maxm = sum;
        		ansStart = start;
        		ansEnd = i;
        	}
        	if(sum < 0) {
        		sum = 0;
        	}
        }
        System.out.print("[ ");
        for(int i=ansStart;i<ansEnd+1;i++) {
        	System.out.print(nums[i] + " ");
        }
        System.out.print("]");

	}
	
	public static List<List<Integer>> findSubArray(int nums[]) {
        List<List<Integer>> res = new ArrayList<>();
        int n = nums.length;

        for(int i=0; i<n; i++) {
            List<Integer> current = new ArrayList<>();
            for(int j=i; j<n; j++) {
                current.add(nums[j]);
                res.add(new ArrayList<>(current));  
            }
        }
        return res;
    }

}
