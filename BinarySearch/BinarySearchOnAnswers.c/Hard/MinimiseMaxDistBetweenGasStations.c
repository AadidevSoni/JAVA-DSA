//Linear
package Arrays;

import java.util.*;

public class Practice {
	
	public static void main(String[] args) {
		
		int[] arr = {1,13,17,23};
		int n = arr.length;
		int k = 5; //place k new gas station and minimize amx distance between any 2 gas stations
		int[] howMany = new int[n-1];
		
		for(int gas=1;gas<=k;gas++) {
			int max = Integer.MIN_VALUE;
			int ind = -1;
			for(int i=0;i<n-1;i++) {
				int diff = arr[i+1] - arr[i];
				int sectionLength = diff/(howMany[i]+1); //if there is one placed, then 2 sections hence +1
				if(sectionLength > max) {
					max = sectionLength;
					ind = i;
				}
			}
			howMany[ind]++; //place the gas station in max section length
		}
		
		int maxAns = -1;
		for(int i=0;i<n-1;i++) {
			int sectionLength = (arr[i+1]-arr[i])/(howMany[i]+1);
			if(sectionLength > maxAns) {
				maxAns = sectionLength;
			}
		}
		
		System.out.println("Max distance: " + maxAns);
		 
	}
	
}


