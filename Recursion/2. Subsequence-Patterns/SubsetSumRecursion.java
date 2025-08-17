import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

public class SubsetSumRecursion {

	public static void main(String[] args) {
		
		int[] arr = new int[] {5,1,2};
		int n = arr.length;
		List<Integer> ans = subsetSum(arr,n);
		
		System.out.println(ans);

	}
	
	public static void findSums(int ind, int sum, int[] arr, int n, List<Integer> ans) {
		if(ind == n) {
			ans.add(sum);
			return;
		}
		
		findSums(ind+1,sum+arr[ind],arr,n,ans);
		findSums(ind+1,sum,arr,n,ans);
	}
	
	public static List<Integer> subsetSum(int[] arr, int n) {
		List<Integer> ans = new ArrayList<>();
		findSums(0,0,arr,n,ans);
		Collections.sort(ans);
		return ans;
	}

}
