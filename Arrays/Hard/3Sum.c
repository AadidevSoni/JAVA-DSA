package Arrays;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.HashSet;
import java.util.List;
import java.util.Set;

public class Practice {

	public static void main(String[] args) {
		
		//Brute force
		
		int[] nums = {-1,2,-2,0,1,3};
		
		Set<List<Integer>> set = new HashSet<>();
        int n = nums.length;
        for(int i=0;i<n;i++) {
            for(int j=i+1;j<n;j++) {
                for(int k=j+1;k<n;k++) {
                    if(nums[i] + nums[j] + nums[k] == 0) {
                        List<Integer> triplet=Arrays.asList(nums[i], nums[j], nums[k]);
                        Collections.sort(triplet); 
                        set.add(triplet);
                    }
                }
            }
        }
        
        for(List<Integer> triplet : set) {
            System.out.println(triplet);
        }
        
        //Better Hashing by finding third element
        System.out.println("Better: ");
        
        Set<List<Integer>> set1 = new HashSet<>();
        int n1 = nums.length;

        for(int i=0;i<n1;i++) {
            Set<Integer> hashSet = new HashSet<>();
            for(int j=i+1;j<n1;j++) {
                int third = -(nums[i] + nums[j]);
                if(hashSet.contains(third)) {
                    List<Integer> temp = Arrays.asList(nums[i],nums[j],third);
                    temp.sort(null);
                    set1.add(temp);
                }
                hashSet.add(nums[j]);
            }
        }

        List<List<Integer>> ans = new ArrayList<>(set);
        
        for(List<Integer> s : ans) {
            System.out.println(s);
        }
        
        //Optimal - 2 pointer with no extra storage space
        
        System.out.println("Optimal");
        
        int[] arr = {2,1,-1,-2,0,3,-3};
        
        List<List<Integer>> ans = new ArrayList<>();
        Arrays.sort(nums);
        int n = nums.length;
        for(int i=0;i<n;i++) {
            if(i!=0 && nums[i] == nums[i-1]) continue;
            int j = i+1;
            int k = n-1;
            while(j<k) {
                int sum = nums[i] + nums[j] + nums[k];

                if(sum < 0) {
                    j++;
                }else if(sum > 0) {
                    k--;
                }else {
                    List<Integer> temp = Arrays.asList(nums[i], nums[j], nums[k]);
                    ans.add(temp);
                    j++;
                    k--;

                    while(j<k && nums[j] == nums[j-1]) j++;
                    while(j<k && nums[k] == nums[k+1]) k--;
                }
            }

        }

        return ans;
        
        
	}
	
}
