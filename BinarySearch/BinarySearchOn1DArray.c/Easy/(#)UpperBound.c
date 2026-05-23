package Arrays;

import java.util.*;

public class Practice {
	
	public static void main(String[] args) {
		
		int[] arr = {1,2,4,5,7,9,9,10};
		int target = 8;
		int n = arr.length;
		int low = 0;
		int high = n-1;
		int ans = n;
		while(low <= high) {
			int mid = (low+high)/2;
			if(arr[mid] <= target) {
				ans = mid;
				low = mid+1;
			}else {
				high = mid-1;
			}
		}
		System.out.println("Smallest index less than target: " + ans);
		
	}
	
}
