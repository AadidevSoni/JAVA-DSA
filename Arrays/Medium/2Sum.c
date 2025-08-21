package Arrays;

import java.util.Arrays;
import java.util.HashMap;

public class 2Sum {

	public static void main(String[] args) {
		
    //Brute Force
	  int[] arr = {1,2,3,4,5};
	  int target = 9;
	  int[] res = new int[2];
	  res = twoSumBrute(arr,target);
	  System.out.println(Arrays.toString(res));

    //Hashing
	 int[] ans = new int[2];
	 ans = twoSum(arr,target);
	 System.out.println(Arrays.toString(ans));
	 
	 //2Sum type 2
	 boolean answer = twoSumPointer(arr,target);
	 System.out.println(answer);
	 

	}

  public static int[] twoSumBrute(int[] nums, int target) {
    int arr[] = new int[2];

    for(int i=0;i<nums.length;i++) {
      for(int j=i+1;j<nums.length;j++) {
        if(nums[i] + nums[j] == target) {
          arr[0] = i;
          arr[1] = j;
          return arr;
        }
      }
    }
    return arr;
  }
  
  public static int[] twoSum(int[] nums, int target) {
      HashMap<Integer, Integer> map = new HashMap<>();
      int ar[] = new int[2];
      for(int i=0;i<nums.length;i++) {
          int a = nums[i];
          int req = target - a;
          if(map.containsKey(req)) {
              ar[0] = map.get(req);
              ar[1] = i;
              return ar;
          }
          map.put(a, i);
      }
      return ar;
  }
  
  public static boolean twoSumPointer(int[] nums, int target) {
	  Arrays.sort(nums);
	  
	  int first = 0;
	  int last = nums.length - 1;
	  while(first < last) {
		  if(nums[first] + nums[last] == target) {
			  return true;
		  }
		  if(nums[first] + nums[last] < target) {
			  first++;
		  }
		  if(nums[first] + nums[last] > target) {
			  last--;
		  }
	  }
	  return false;
  }
}

