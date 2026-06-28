package Arrays;

import java.util.*;


public class Practice {
	
	public static void main(String[] args) {
		
		//Naive approach
		
		int[] arr = {900,945,955,1100,1500,1800};
		int[] dep = {920,1200,1130,1150,1900,2000};
		int n = dep.length;
		int minPlatforms = 0;
		minPlatforms = getMinPlat(arr,dep,n);
		System.out.println("Min number of platforms required: " + minPlatforms);
		
		//Using Sorting efficient
		
		int MinPlatforms = 0;
		Arrays.sort(arr);
		Arrays.sort(dep);
		MinPlatforms = getMinPlatforms(arr,dep,n);
		System.out.println("Min number of platforms required: " + MinPlatforms);

	}
	
	public static int getMinPlat(int[] arr, int[] dep, int n) {
		int platforms = 1;
		for(int i=0;i<n;i++) {
			int count = 1;
			for(int j=i+1;j<n;j++) {
				//No of intersections
				if((arr[i] >= arr[j] && arr[i] <= dep[j]) || (arr[j]>=arr[i] && arr[j]<=dep[i])) {
					count++;
				}
			}
			platforms = Math.max(platforms, count);
		}
		
		return platforms;
	}
	
	public static int getMinPlatforms(int[] arr, int[] dep, int n) {
		int result = 0;
		int platforms = 0;
		int i = 0;
		int j = 0;
		
		while(i<n && j<n) {
			if(arr[i] <= dep[j]) {
				platforms++;
				i++;
			}else if(dep[j] < arr[i]) {
				platforms--;
				j++;
			}
			if(platforms > result) {
				result = platforms;
			}
		}
		
		return result;
	}
  
}

