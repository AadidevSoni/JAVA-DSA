package Arrays;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.HashSet;
import java.util.List;
import java.util.Scanner;
import java.util.Set;

public class Practice {

	public static void main(String[] args) {
		
		//Brute force
		
		int nums[] = {-2,5,3,0,1,2};
		
		if(nums.length == 1) {
            System.out.println(nums[0]);
        }else {
        	int max = 0;
            for(int i=0;i<nums.length;i++) {
                for(int j=i;j<nums.length;j++) {
                    int product = 1;
                    for(int k=i;k<=j;k++) {
                        product *= nums[k];
                    }
                    if(product > max) {
                        max = product;
                    }
                }
            }
            System.out.println(max);
        }
		
		//Better
		
		if(nums.length == 1) {
			System.out.println(nums[0]);
        }else {
        	int max = 0;
            for(int i=0;i<nums.length;i++) {
                int product = 1;
                for(int j=i;j<nums.length;j++) {
                    
                    product *= nums[j];
                    
                    if(product > max) {
                        max = product;
                    }
                }
            }
            System.out.println(max);
        }
		
		//Optimal - 2 pointer
		
		int pre = 1;
        int suf = 1;
        int n = nums.length;
        int max = Integer.MIN_VALUE;
        for(int i=0;i<n;i++) {
            if(pre == 0) pre = 1;
            if(suf == 0) suf = 1;
            pre *= nums[i];
            suf *= nums[n-i-1];
            max = Math.max(max,Math.max(pre,suf));
        }
        System.out.println(max);
		
	}
	
}
