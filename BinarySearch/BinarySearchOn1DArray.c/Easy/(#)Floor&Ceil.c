package Arrays;

import java.util.*;

public class Practice {
	
	public static void main(String[] args) {
		
		int[] arr = {10,20,30,40,50};
		int target = 25;
		int n = arr.length;
		int low = 0;
		int high = n-1;
		int floor = n;
		int ceil = n;
		while(low <= high) {
			int mid = (low+high)/2;
			if(arr[mid] <= target) {
				floor = arr[mid];
				low = mid+1;
			}else {
				ceil = arr[mid];
				high = mid-1;
			}
		}
		System.out.println("Floor: " + floor);
		
		System.out.println("Ceil: " + ceil);
		
	}
	
}
