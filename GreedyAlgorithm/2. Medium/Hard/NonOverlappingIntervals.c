package Arrays;

import java.util.*;


public class Practice {
	
	public static void main(String[] args) {
		
		int[][] intervals = {{1,2},{2,3},{3,4},{1,4}};
		
        Arrays.sort(intervals, (a,b) -> a[1] - b[1]); //Arrange in order of increasing end time

        int count = 0;
        int n = intervals.length;
        int limit = intervals[0][1];

        for(int i=1;i<n;i++) {
            if(intervals[i][0] < limit) {
                count++;
            }else {
                limit = intervals[i][1];
            }
        }

        System.out.println("No of intervals to remove: " + count);

	}
	

  
}

