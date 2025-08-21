package Arrays;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class MaxSubArraySum {

	public static void main(String[] args) {
		
		//Creating subarrays and checking 
		int nums[] = {-2,1,-3,4,-1,2,1,-5,4};
		
		List<List<Integer>> res = findSubArray(nums);
        int max = Integer.MIN_VALUE;
        for(List<Integer> s: res) {
            int sum = 0;
            for(int n: s) {
                sum += n;  
            }
            if(sum > max) {
                max = sum;
            }
        }
        System.out.println("Max sum: " + max);
        
        //Brute force 
        int nums1[] = {1,2,-1,-2};
        int result = maxSubArray(nums1);
        System.out.println("Max sum: " + result);
        
        //Better
        int result1 = maxSubArray1(nums1);
        System.out.println("Max sum: " + result1);
        
        //Kadane's Algorithm
        int nums2[] = {1,2,-3,-1,5,6,-2,-45,10};
        int result2 = maxSubArrayKadane(nums2);
        System.out.println("Max sum: " + result2);

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
	
    public static int maxSubArray(int[] nums) {
        
        int max = Integer.MIN_VALUE;
        for(int i=0;i<nums.length;i++) {
            for(int j=i;j<nums.length;j++) {
                int sum = 0;
                for(int k=i;k<=j;k++) {
                    sum += nums[k];
                }
                if(sum > max) {
                    max = sum;
                }
            }
        }
        return max;
    }
    
    public static int maxSubArray1(int[] nums) {
        
        int max = Integer.MIN_VALUE;
        for(int i=0;i<nums.length;i++) {
            int sum = 0;
            for(int j=i;j<nums.length;j++) {
                sum += nums[j];
                if(sum > max) {
                    max = sum;
                }
            }
        }
        return max;
    }
    
    public static int maxSubArrayKadane(int[] nums) {
        int max = Integer.MIN_VALUE;
        int sum = 0;
        for(int i=0;i<nums.length;i++) {
            sum += nums[i];

            if(sum > max) {
                max = sum;
            }

            if(sum < 0) {
                sum = 0;
            }
        }
        return max;
    }

}
