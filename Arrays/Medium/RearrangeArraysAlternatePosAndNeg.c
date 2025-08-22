package Arrays;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class RearrangeArraysAlternatePosAndNeg {

	public static void main(String[] args) {
		
		//BruteForce
		int nums[] = {-1,-3,1,2,-4,5};
		int[] res = rearrangeArray(nums);
		System.out.println(Arrays.toString(res));
		
		//Better
		int nums1[] = {3,-2,1,-5,2,-4};
		int[] res1 = rearrangeArray1(nums1);
		System.out.println(Arrays.toString(res1));
		
		//Variation2
		int nums2[] = {3,2,-1,5,-3,4};
		int[] res2 = rearrangeArray2(nums2);
		System.out.println(Arrays.toString(res2));
		

	}
	
	public static int[] rearrangeArray(int[] nums) {
        List<Integer> pos = new ArrayList<>();
        List<Integer> neg = new ArrayList<>();
        for(int i=0;i<nums.length;i++) {
            if(nums[i] >= 0) {
                pos.add(nums[i]);
            }else {
                neg.add(nums[i]);
            }
        }
        int res[] = new int[nums.length];
        int p = 0;
        int n = 0;
        for(int i=0;i<nums.length;i++) {
            if(i%2 == 0) {
                res[i] = pos.get(p);
                p++;
            }else{
                res[i] = neg.get(n);
                n++;
            }
        }
        return res;
    }
	
	public static int[] rearrangeArray1(int[] nums) {
        int pos = 0;
        int neg = 1;
        int res[] = new int[nums.length];
        for(int n: nums) {
            if(n >= 0) {
                res[pos] = n;
                if(pos+2 < nums.length) {
                    pos+= 2;
                }
            }else {
                res[neg] = n;
                if(neg+2 < nums.length) {
                    neg+= 2;
                }
            }
        }
        return res;
    }
	
	public static int[] rearrangeArray2(int[] nums) {
	    List<Integer> pos = new ArrayList<>();
	    List<Integer> neg = new ArrayList<>();

	    for (int num : nums) {
	        if (num >= 0) {
	            pos.add(num);
	        } else {
	            neg.add(num);
	        }
	    }

	    int[] res = new int[nums.length];
	    int posSize = pos.size();
	    int negSize = neg.size();

	    int i = 0; 
	    int p = 0; 
	    int n = 0; 
	   
	    while (p < posSize && n < negSize) {
	        res[i++] = pos.get(p++);
	        res[i++] = neg.get(n++);
	    }

	    while (p < posSize) {
	        res[i++] = pos.get(p++);
	    }

	    while (n < negSize) {
	        res[i++] = neg.get(n++);
	    }

	    return res;
	}

	
	

}
