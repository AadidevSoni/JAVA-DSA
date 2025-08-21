package Arrays;

import java.util.Arrays;
import java.util.HashMap;
import java.util.Map;

public class MajorityElement {

	public static void main(String[] args) {
		
		//Hashing
		int nums[] = {1,2,5,5,5,5,5,2};
		int res = majorityElement(nums);
		System.out.println("Majority element: " + res);
		
		//Boyer Moore's Voting Algorithm
		/*
		 * we have ele and count
		 * asssume ele = arr[0] and count 0
		 * iterate through the array
		 * if array[i] == ele then count++
		 * else count--
		 * if count == 0 means it cancelled out and set ele to  next element and count to 1
		 * repeat this till end of array
		 * and whatever remains in ele might be the majority element
		 */
		
		int res1 = majorityElement1(nums);
		System.out.println("Majority element: " + res1);

	}
	
	public static int majorityElement(int[] nums) {
        HashMap<Integer, Integer> map = new HashMap<>();
        for(int n: nums) {
            map.put(n, map.getOrDefault(n,0) + 1);
        }
        for(Map.Entry<Integer, Integer> entry: map.entrySet()) {
            if(entry.getValue() > (nums.length)/2) {
                return entry.getKey();
            }
        }
        return 0;
    }
	
	public static int majorityElement1(int[] nums) {
        int ele = nums[0];
        int count = 0;
        
        for (int num : nums) {
            if (count == 0) {
                ele = num;
                count = 1;
            } else if (num == ele) {
                count++;
            } else {
                count--;
            }
        }

        int c = 0;
        for(int i=0;i<nums.length;i++) {
            if(nums[i] == ele) {
                c++;
            }
        }
        if(c > nums.length/2) {
            return ele;
        }else {
            return -1;
        }
    }
}
                         
