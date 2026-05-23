//Linear
package Arrays;

import java.util.*;

public class Practice {
	
	public static void main(String[] args) {
		
		//Min distance between cows is max
		int[] arr = {0,3,4,7,10,9}; //stalls
		int cows = 4;
		int n = arr.length;
		int res = 0;
		Arrays.sort(arr);
		for(int i=1;i<arr[n-1]-arr[0];i++) { //range is 1 to max-min
			int cow = cows;
			if(canWePlace(arr,i,cow)) {
				res = i;
			}else {
				break;
			}
		}
		System.out.println("Min distance between cows is: " + res);
		
	}
	
	public static boolean canWePlace(int[] arr, int gap, int cow) {
		int countCows = 1; //first cow at index 0
		int last = 0; //last cow index
		for(int i=1;i<arr.length;i++) {
			if(arr[i]-arr[last] >= gap) {
				countCows++;
				last = i;
			}
			
		}
		if(countCows >= cow) {
			return true;
		}else {
			return false;
		}
	}
	
}

//Binary Search
package Arrays;

import java.util.*;

public class Practice {
	
	public static void main(String[] args) {
		
		//Min distance between cows is max
		int[] arr = {0,3,4,7,10,9}; //stalls
		int cows = 4;
		int n = arr.length;
		int res = 0;
		Arrays.sort(arr);
		int low = 1;
		int high = arr[n-1]-arr[0];
		while(low <= high) {
			int mid = (low+high)/2;
			int cow = cows;
			if(canWePlace(arr,mid,cow)) {
				res = mid;
				low = mid+1;
			}else {
				high = mid-1;
			}
		}
		System.out.println("Min distance between cows is: " + res);
		
	}
	
	public static boolean canWePlace(int[] arr, int gap, int cow) {
		int countCows = 1; //first cow at index 0
		int last = 0; //last cow index
		for(int i=1;i<arr.length;i++) {
			if(arr[i]-arr[last] >= gap) {
				countCows++;
				last = i;
			}
			
		}
		if(countCows >= cow) {
			return true;
		}else {
			return false;
		}
	}
	
}
