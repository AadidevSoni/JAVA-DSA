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
		
		//Better - Hashing
		
		int nums[] = {1,1,2,2,2,3,1,5};
		List<Integer> res = new ArrayList<>();

        HashMap<Integer, Integer> map = new HashMap<>();
        for(int n: nums) {
            map.put(n, map.getOrDefault(n,0)+1);
        }
        for(Map.Entry<Integer, Integer> entry: map.entrySet()) {
            if(entry.getValue() > (nums.length)/3) {
                res.add(entry.getKey());
            }
        }
        for(int n: res) {
        	System.out.print(n + " ");
        }
        
        System.out.println();
        
        //Optimal - Boyer Moore's Modified algorithm
        
        List<Integer> res1 = new ArrayList<>();
        int ct1 = 0;
        int ct2 = 0;
        int ele1 = Integer.MIN_VALUE;
        int ele2 = Integer.MAX_VALUE;
        int n = nums.length;
        for(int i=0;i<n;i++) {
            if(ct1==0 && nums[i] != ele2) {
                ct1 = 1;
                ele1 = nums[i];
            }else if(ct2 == 0 && nums[i] != ele1) {
                ct2 = 1;
                ele2 = nums[i];
            }else if(ele1 == nums[i]) {
                ct1++;
            }else if(ele2 == nums[i]) {
                ct2++;
            }else {
                ct1--;
                ct2--;
            }
        }
        
        int ctr1 = 0;
        int ctr2 = 0;

        for(int i: nums) {
            if(i == ele1) {
                ctr1++;
            }
            if(i == ele2) {
                ctr2 ++;
            }
        }

        if(ctr1 > n/3) {
            res1.add(ele1);
        }

        if(ctr2 > n/3) {
            res1.add(ele2);
        }

        for(int j: res1) {
        	System.out.print(j + " ");
        }
        System.out.println();
		
	}
	
}
