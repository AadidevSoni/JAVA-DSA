package Arrays;

import java.util.*;

class Job {
	int id;
	int deadline;
	int profit;
	
	Job(int id, int deadline, int profit) {
		this.id = id;
		this.deadline = deadline;
		this.profit = profit;
	}
}

class Solve {
	int[] JobScheduling(Job arr[], int n) {
		Arrays.sort(arr, (a,b) -> (b.profit - a.profit));
		
		int maxi = 0;
		for(int i=0;i<n;i++) {
			if(arr[i].deadline > maxi) {
				maxi = arr[i].deadline;
			}
		}
		
		int[] result = new int[maxi+1];
		
		for(int i=0;i<=maxi;i++) {
			result[i] = -1;
		}
		
		int countJobs = 0;
		int jobProfit = 0;
		
		for(int i=0;i<n;i++) {
			for(int j = arr[i].deadline;j>=0;j--) {
				if(result[j] == -1) {
					result[j] = i;
					countJobs++;
					jobProfit += arr[i].profit;
					break;
				}
			}
		}
		
		int[] ans = new int[2];
		ans[0] = countJobs;
		ans[1] = jobProfit;
		return ans;
	}
}

public class Practice {
	
	public static void main(String[] args) {
		
		Job[] jobs = new Job[8];
		jobs[0] = new Job(6,2,80);
		jobs[1] = new Job(3,6,70);
		jobs[2] = new Job(4,6,65);
		jobs[3] = new Job(2,5,60);
		jobs[4] = new Job(5,4,25);
		jobs[5] = new Job(8,2,22);
		jobs[6] = new Job(1,4,20);
		jobs[7] = new Job(7,2,10);
		
		Solve arr = new Solve();
		
		int[] result = arr.JobScheduling(jobs, 8);
		System.out.println("No of jobs: " + result[0]);
		System.out.println("Job profit: " + result[1]);

	}
  
}

