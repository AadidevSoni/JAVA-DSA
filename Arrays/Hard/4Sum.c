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
		
		int[] nums = {-1,-2,0,2,1,3};
		int target = 0;
		
		Set<List<Integer>> set = new HashSet<>();
        int n = nums.length;

        for(int i=0;i<n;i++) {
            for(int j=i+1;j<n;j++) {
                for(int k=j+1;k<n;k++) {
                    for(int l=k+1;l<n;l++) {
                        int sum = nums[i] + nums[j] + nums[k] + nums[l];
                        if(sum == target) {
                            List<Integer> sub = Arrays.asList(nums[i], nums[j], nums[k], nums[l]);
                            Collections.sort(sub);
                            set.add(sub);
                        }
                    }
                }
            }
        }

        List<List<Integer>> ans = new ArrayList<>(set);
        
        for(List<Integer> l: ans) {
        	System.out.println(l);
        }
        
        //Better
        
        System.out.println("Better: ");
        n = nums.length; // size of the array
        Set<List<Integer>> st = new HashSet<>();

        // checking all possible quadruplets:
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                Set<Long> hashset = new HashSet<>();
                for (int k = j + 1; k < n; k++) {
                    // taking bigger data type
                    // to avoid integer overflow:
                    long sum = nums[i] + nums[j];
                    sum += nums[k];
                    long fourth = target - sum;
                    if (hashset.contains(fourth)) {
                        List<Integer> temp = new ArrayList<>();
                        temp.add(nums[i]);
                        temp.add(nums[j]);
                        temp.add(nums[k]);
                        temp.add((int) fourth);
                        temp.sort(Integer::compareTo);
                        st.add(temp);
                    }
                    // put the kth element into the hashset:
                    hashset.add((long) nums[k]);
                }
            }
        }
        List<List<Integer>> answer = new ArrayList<>(st);
        
        for(List<Integer> l: answer) {
        	System.out.println(l);
        }
        
        //Optimal - 2 pointer approach 
        
        System.out.println("Optimal: ");
        List<List<Integer>> ans1 = new ArrayList<>();
        n = nums.length;
        Arrays.sort(nums);

        for(int i=0;i<n;i++) {
            if(i>0 && nums[i] == nums[i-1]) continue;
            for(int j=i+1;j<n;j++) {
                if( j > i + 1 && nums[j] == nums[j-1]) continue;
                int k = j+1;
                int l = n-1;

                while(k<l) {
                    long sum = nums[i] + nums[j];
                    sum += nums[k];
                    sum += nums[l];

                    if(sum < target) {
                        k++;
                    }else if(sum > target) {
                        l--;
                    }else {
                        List<Integer> temp = Arrays.asList(nums[i], nums[j], nums[k], nums[l]);
                        ans1.add(temp);
                        k++;
                        l--;

                        while(k<l && nums[k] == nums[k-1]) k++;
                        while(k<l && nums[l] == nums[l+1]) l--;
                    }
                }
            }
        }

        for(List<Integer> s: ans) {
        	System.out.println(s);
        }
        
        
	}
	
}
