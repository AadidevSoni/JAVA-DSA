//Brute force

class Solution {
    public int totalFruits(int[] fruits) {
        //max length subarray with atmost 2 types of fruits
        int maxLen = 0;
        int n = fruits.length;
        for(int i=0;i<n;i++) {
            Set<Integer> set = new HashSet<>();
            for(int j=i;j<n;j++) {
                set.add(fruits[j]);
                if(set.size() <= 2) {
                    maxLen = Math.max(maxLen,j-i+1);
                }else{
                    break;
                }
            }
        }
        return maxLen;
    }
}

//Optimal

package Arrays;

import java.util.*;

public class Practice {
	
	public static void main(String[] args) {
		
		int[] fruits = {3,3,3,1,2,1,1,2,3,3,4};
		int k = 2;
		HashMap<Integer, Integer> map = new HashMap<>();
		int maxLen = 0;
		int l =0;
		int r = 0;
		int n = fruits.length;
		while(r < n) {
			if(map.containsKey(fruits[r])) {
				map.put(fruits[r],map.get(fruits[r])+1);
			}else {
				map.put(fruits[r], 1);
			}
			if(map.size() <= k) {
				int len = r-l+1;
				maxLen = Math.max(len,maxLen);
			}else {
				while(map.size() > k) {
					int f = map.get(fruits[l]);
					map.put(fruits[l], f-1);
					if(f-1 == 0) {
						map.remove(fruits[l]);
					}
					l++;
				}
			}
			r++;
			
		}
		
		System.out.println("Max no of fruits: " + maxLen);
		
	}
	
	
}

//Best
package Arrays;

import java.util.*;

public class Practice {
	
	public static void main(String[] args) {
		
		int[] fruits = {3,3,3,1,2,1,1,2,3,3,4};
		int k = 2;
		HashMap<Integer, Integer> map = new HashMap<>();
		int maxLen = 0;
		int l =0;
		int r = 0;
		int n = fruits.length;
		while(r < n) {
			if(map.containsKey(fruits[r])) {
				map.put(fruits[r],map.get(fruits[r])+1);
			}else {
				map.put(fruits[r], 1);
			}
			if(map.size() <= k) {
				int len = r-l+1;
				maxLen = Math.max(len,maxLen);
			}else { //trim it once without while loop
				int f = map.get(fruits[l]);
				map.put(fruits[l], f-1);
				if(f-1 == 0) {
					map.remove(fruits[l]);
				}
				l++;
				
			}
			r++;
			
		}
		
		System.out.println("Max no of fruits: " + maxLen);
		
	}
	
	
}
