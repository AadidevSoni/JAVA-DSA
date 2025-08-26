package Arrays;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashSet;
import java.util.List;
import java.util.Set;

public class Practice {

	public static void main(String[] args) {
		
		//Better by me
		
		int nums[] = {2,4,3,10,20,1};
		
		Arrays.sort(nums);
        int maxC = Integer.MIN_VALUE;
        int c = 0;
        for(int i=0;i<nums.length-1;i++) {
            if(nums[i+1] == nums[i] + 1) {
                c++;
                if(c > maxC) {
                    maxC = c;
                }
            }else if(nums[i+1] == nums[i]) {
                continue;
            }
            else {
                c=0;
            }
        }
        
        maxC += 1;
        
        System.out.println("Max consecutive sequence: " + maxC);
        
        //Brute Force
     
        int max = 0;

        for(int i=0;i<nums.length;i++) {
            int count = 1;
            int x = nums[i];
            while(linearSearch(nums,x+1) == true) {
                count++;
                x++;
            }
            if(count > max) {
                max = count;
            }
        }

        System.out.println("Max consecutive sequence: " + max);
        
        //Better
        
        if(nums.length == 0) {
        	System.out.println("Max consecutive sequence: 0");
        }
        Arrays.sort(nums);
        int longest = 1;
        int smallest = Integer.MIN_VALUE;
        c = 0;
        for(int i=0;i<nums.length;i++) {
            if(smallest == nums[i]-1) {
                c++;
                smallest = nums[i];
                if(c > longest) {
                    longest = c;
                }
            }else if(nums[i] == smallest) {
                continue;
            }else {
                c = 1;
                smallest = nums[i];
            }
        }
        System.out.println("Max consecutive sequence: " + longest);
        
        //Optimal approach using Sets
        
        if(nums.length == 0) {
        	System.out.println("Max consecutive sequence: 0");
        }
        longest = 1;
        Set<Integer> set = new HashSet<>();
        for(int n: nums) {
            set.add(n);
        }
        for(int n: set) {
            if(!set.contains(n-1)) {
                c = 1;
                int x = n;
                while(set.contains(x+1)) {
                    c++;
                    x++;
                }
                if(c > longest) {
                    longest = c;
                }
            }
        }
        System.out.println("Max consecutive sequence: " + longest);

	}
	
	public static boolean linearSearch(int[] nums, int x) {
        for (int i = 0; i < nums.length; i++) {
            if (nums[i] == x) {
                return true;
            }
        }
        return false;
    }
	
}
