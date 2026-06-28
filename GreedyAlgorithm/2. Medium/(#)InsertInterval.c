package Arrays;

import java.util.*;


public class Practice {
	
	public static void main(String[] args) {
		
		int[][] intervals = {{1,3},{5,6},{7,10},{13,17}};
		int[] newInterval = {3,5};
		int n = intervals.length;
		
		int[][] result = insert(intervals,newInterval);
		
		for(int i=0;i<result.length;i++) {
			System.out.print("[" + result[i][0] + " , " + result[i][1] + "] , ");
		}
		System.out.println();

	}
	
	public static int[][] insert(int[][] intervals, int[] newInterval) {
        int n = intervals.length;
        List<List<Integer>> ans = new ArrayList<>();
        for(int i=0;i<n;i++) {
            ans.add(Arrays.asList(intervals[i][0],intervals[i][1]));
        }
        ans.add(Arrays.asList(newInterval[0],newInterval[1]));

        ans.sort((a, b) -> a.get(0) - b.get(0));

        List<List<Integer>> result = new ArrayList<>();
        
        for(int i=0;i<n+1;i++) {
            if(result.isEmpty() || ans.get(i).get(0) > result.get(result.size() - 1).get(1)) {
                result.add(Arrays.asList(ans.get(i).get(0),ans.get(i).get(1)));
            }else {
                result.get(result.size() - 1).set(1,Math.max(ans.get(i).get(1),result.get(result.size()-1).get(1)));
            }
        }

        int[][] res = new int[result.size()][2];

        for(int i=0;i<result.size();i++) {
            res[i][0] = result.get(i).get(0);
            res[i][1] = result.get(i).get(1);
        }

        return res; 
    }

  
}

