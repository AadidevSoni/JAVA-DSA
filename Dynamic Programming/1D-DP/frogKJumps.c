package DynamicProgramming;

public class frogKJumps {

	public static void main(String[] args) {
		
		int[] arr = {10,5,20,0,15};
		int n = arr.length;
		int k = 2;
		int res = jump(n-1,k,arr);
		System.out.println("Min Jumps: " + res);
	}
	
	public static int jump(int n, int k, int[] arr) {
		if(n == 0) {
			return 0;
		}
		int minSteps = Integer.MAX_VALUE;
		for(int i=1;i<=k;i++) {
			if((n-i) >= 0) {
				int step = jump(n-i,k,arr) + Math.abs(arr[i] - arr[n-i]);
				minSteps = Math.min(minSteps, step);
			}
		}
		return minSteps;
	}

}
