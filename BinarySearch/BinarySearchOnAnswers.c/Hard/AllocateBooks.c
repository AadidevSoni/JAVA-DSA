package Arrays;

import java.util.*;

public class Practice {
	
	public static void main(String[] args) {
		
		int[] arr = {12,34,67,90};
		int students = 2;
		int max = Integer.MIN_VALUE;
		int sum = 0;
		int n = arr.length;
		for(int i=0;i<n;i++) { //largest as the max split will always be largest if only 2 elements
			if(arr[i] > max) {
				max = arr[i];
			}
			sum += arr[i];
		}
		int low = max;
		int high = sum;
		int res = -1;
		while(low <= high) {
			int mid = (low+high)/2;
			if(isPossible(mid,arr,n,students)) {
				res = mid;
				high = mid-1;
			}else {
				low = mid+1;
			}
		}
		System.out.println("Min of the maximum pages alloted: " + res);
	}
	
	public static boolean isPossible(int p, int[] arr, int n, int students) {
		int s = 1;
		int sum = 0;
		for(int i=0;i<n;i++) {
			if(arr[i] > p) {
				return false;
			}else {
				if(sum + arr[i] > p) {
					s++;
					sum += arr[i];
				}else {
					sum += arr[i];
				}
			}
		}
		if(s > students) {
			return false;
		}else {
			return true;
		}
	}
	
}
