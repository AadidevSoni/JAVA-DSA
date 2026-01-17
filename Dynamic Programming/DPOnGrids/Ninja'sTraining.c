package Arrays;

import java.util.*;

public class Practice {
	
	public static void main(String[] args) {
		
		Scanner scanner = new Scanner(System.in);
		int n;
		System.out.println("Enter number of days: ");
		n = scanner.nextInt();
		int[][] tasks = new int[n][3];
		
		for(int i=0;i<n;i++) {
			for(int j=0;j<=2;j++) {
				System.out.println("Enter merit of task " + j + ": ");
				int m = scanner.nextInt();
				tasks[i][j] = m;
			}
		}
		
		int result = func(n-1,3,tasks);
		System.out.println("Max merit: " + result);

	}
	
	public static int func(int day, int last, int[][] tasks) {
		if(day == 0) {
			int max = 0;
			for(int i=0;i<=2;i++) {
				if(i != last) {
					max = Math.max(max, tasks[0][i]);
				}
			}
			return max;
		}else {
			int max = 0;
			for(int i=0;i<=2;i++) {
				if(i != last) {
					int points = tasks[day][i] + func(day-1,i,tasks);
					max = Math.max(max, points);
				}
			}
			return max;
		}
	}
	
	
}


class Solution {

    public int f(int day, int last, int[][] points) {
        if(day == 0) {
            int maxi = 0;
            for(int task=0;task<3;task++) {
                if(task != last) {
                    maxi = Math.max(maxi, points[0][task]);
                }
            }
            return maxi;
        }

        int maxi = 0;
        for(int task = 0;task<3;task++) {
            if(task != last) {
                int point = points[day][task] + f(day-1,task,points);
                maxi = Math.max(maxi, point);
            }
        }
        return maxi;
    }
    public int ninjaTraining(int[][] matrix) {
        int n = matrix.length;
        // 3 because 3 is last and by default iterating from n-1 to 0, n-1 have no last from 0 to 2 so 3
        return f(n-1, 3, matrix);
    }
}

//Dynamic
package Arrays;

import java.util.*;

public class Practice {
	
	public static void main(String[] args) {
		
		Scanner scanner = new Scanner(System.in);
		int n;
		System.out.println("Enter number of days: ");
		n = scanner.nextInt();
		int[][] tasks = new int[n][3];
		int[][] dp = new int[n][4];
		
		for(int[] row : dp)
            Arrays.fill(row, -1);
		
		for(int i=0;i<n;i++) {
			for(int j=0;j<=2;j++) {
				System.out.println("Enter merit of task " + j + ": ");
				int m = scanner.nextInt();
				tasks[i][j] = m;
			}
		}
		
		int result = func(n-1,3,tasks,dp);
		System.out.println("Max merit: " + result);

	}
	
	public static int func(int day, int last, int[][] tasks, int[][] dp) {
		
		if(day == 0) {
			int max = 0;
			for(int i=0;i<=2;i++) {
				if(i != last) {
					max = Math.max(max, tasks[0][i]);
				}
			}
			return max;
		}else {
			if(dp[day][last] != -1)
	            return dp[day][last];
			
			int max = 0;
			for(int i=0;i<=2;i++) {
				if(i != last) {
					int points = tasks[day][i] + func(day-1,i,tasks,dp);
					max = Math.max(max, points);
				}
			}
			dp[day][last] = max;
			return dp[day][last] ;
		}
	}
	
	
}
