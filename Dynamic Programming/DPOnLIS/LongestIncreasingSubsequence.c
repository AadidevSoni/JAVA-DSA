package main;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.Comparator;
import java.util.List;

import javax.swing.JFrame;

public class Main {

	public static void main(String[] args) {
		
		int[] arr = {1,7,8,4,5,6,-1,9};
		int n = arr.length;
		List<Integer> lst = new ArrayList<>();
		lst.add(arr[0]);
		for(int i=1;i<n;i++) {
			if(arr[i] >= lst.get(lst.size() - 1)) {
				lst.add(arr[i]);
			}else {
				int ind = binarySearch(lst, arr[i]); //index of the element just greater than arr[i]
				lst.set(ind, arr[i]);
			}
		}
		System.out.println("LIS: " + lst.size());

	}
	
	public static int binarySearch(List<Integer> lst, int num) {
		int low = 0;
		int high = lst.size() - 1;
		while(low < high) {
			int mid = low + (high - low) / 2;
			if(lst.get(mid) < num) {
				low = mid + 1;
			}else {
				high = mid;
			}
		}
		return low;
	}

}
