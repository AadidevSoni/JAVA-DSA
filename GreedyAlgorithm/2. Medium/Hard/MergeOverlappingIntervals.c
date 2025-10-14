package Arrays;

import java.util.*;


public class Practice {
	
	public static void main(String[] args) {
		
		int[][] intervals = {{1, 3}, {8, 10}, {2, 6}, {15, 18}};
		
		List<List<Integer>> ans = new ArrayList<>();
		
		int n = intervals.length;
		ans = MergeOverlapping(intervals,n);
		
		for(List<Integer> lst: ans) {
			System.out.print("[ " + lst.get(0) + " , " + lst.get(1) + " ]");
			System.out.println();
		}

	}
	
	public static List<List<Integer>> MergeOverlapping(int[][] intervals, int n) {
		
		Arrays.sort(intervals, new Comparator<int[]>() {
			//Sorting in ascending order of starting interval
			public int compare(int[] a, int[] b) {
				return a[0] - b[0];
			}
		});	
		
		List<List<Integer>> ans = new ArrayList<>();
		
		for(int i=0;i<n;i++) {
			//If the current interval lies in the interval in ans
			if(ans.isEmpty() || intervals[i][0] > ans.get(ans.size() - 1).get(1)) {
				ans.add(Arrays.asList(intervals[i][0] , intervals[i][1]));
			}else {
				//1 here means the second pos in ans
				ans.get(ans.size()-1).set(1,Math.max(ans.get(ans.size()-1).get(1), intervals[i][1]));
			}
		}
		
		return ans;
		
	}

  
}

//LEETCODE

class Solution {
    public int[][] merge(int[][] intervals) {
        int n = intervals.length;

        Arrays.sort(intervals,new Comparator<int[]>() {
            public int compare(int[] a, int[] b) {
                return a[0] - b[0];
            }
        });

        List<List<Integer>> ans = new ArrayList<>();

        for(int i=0;i<n;i++) {
            if(ans.isEmpty() || intervals[i][0] > ans.get(ans.size() - 1).get(1)) {
                ans.add(Arrays.asList(intervals[i][0],intervals[i][1]));
            }else {
                ans.get(ans.size() - 1).set(1,Math.max(intervals[i][1],ans.get(ans.size()-1).get(1)));
            }
        }

        int[][] result = new int[ans.size()][2];

        for(int i=0;i<ans.size();i++) {
            result[i][0] = ans.get(i).get(0);
            result[i][1] = ans.get(i).get(1);
        }

        return result;
    }
}