package Arrays;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class Practice {

	public static void main(String[] args) {
		
		//Creating subarrays
		int nums[] = {1,2,3,2,1};
		int k = 5;
		
		List<List<Integer>> res = countSubarrays(nums);

        int count = 0;

        for(List<Integer> sub: res) {
            int sum = 0;
            for(int n: sub) {
                sum += n;
            }
            
            if(sum == k) {
                count++;
            }
        }

        System.out.println(count + " subarrays sum upto " + k);
        
        //Brute force
        
        count = 0;

        for(int i=0;i<nums.length;i++) {
            int sum = 0;
            for(int j=i;j<nums.length;j++) {
                sum += nums[j];
                if(sum == k) {
                    count++;
                }
            }
        }

        System.out.println(count + " subarrays sum upto " + k);

        //Hashing 

        int count = 0;
        int sum = 0;

        HashMap<Integer, Integer> map = new HashMap<>();

        map.put(0,1);
        for(int i=0;i<nums.length;i++) {
            sum += nums[i];

            int rem = sum-k;

            // Add the number of subarrays to be removed:
            count += map.getOrDefault(rem, 0);

            // Update the count of prefix sum
            // in the map.
            map.put(sum, map.getOrDefault(sum, 0) + 1);
            
        }
		

	}
	

	public static List<List<Integer>> countSubarrays(int[] nums) {
        List<List<Integer>> res = new ArrayList<>();

        for(int i=0;i<nums.length;i++) {
            List<Integer> sub = new ArrayList<>();
            for(int j=i;j<nums.length;j++) {
                sub.add(nums[j]);
                res.add(new ArrayList<>(sub));
            }
        }

        return res;
    }
	
	

}
