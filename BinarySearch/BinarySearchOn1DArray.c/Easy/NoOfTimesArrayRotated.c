package Arrays;

import java.util.*;

public class Practice {
	
	public static void main(String[] args) {
		
		int[] arr = {3,4,5,1,2};
		int n = arr.length;
		int min = Integer.MAX_VALUE;
		int low = 0;
		int high = n-1;
		int ind = 0;
		while(low <= high) {
			int mid = (low+high)/2;
			if(arr[low] <= arr[mid]) {
				if(arr[low] < min) {
					ind = low;
					min = arr[low];
				}
				low = mid+1;
			}else {
				if(arr[mid] < min) {
					ind = mid;
					min = arr[mid];
				}
				high = mid;
			}
		}
		System.out.println("No of times rotate: " + ind);
	}
	
}
