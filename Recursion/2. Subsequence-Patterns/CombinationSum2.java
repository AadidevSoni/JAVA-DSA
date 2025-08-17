import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class CombinationSum2 {

	public static void main(String[] args) {
		
		int[] arr = new int[] {1,2,3,4,5};
		int target = 7;
		int s=  0;
		List<List<Integer>> res = combinationSums(arr,target);
		for(List<Integer> list: res) {
			System.out.println(list);
			s++;
		}
		System.out.println("No of subsets: " + s);
	}
	
	public static void findCombinations(int ind, List<List<Integer>> ans, int[] arr, int target, List<Integer> ds) {
		if(target == 0) {
			ans.add(new ArrayList<>(ds));
			return;
		}
		
		for(int i=ind;i<arr.length;i++) {
			if(i>ind && arr[i] == arr[i-1]) continue;
			if(arr[i] > target) break;
			
			ds.add(arr[i]);
			findCombinations(i+1,ans,arr,target-arr[i],ds);
			ds.remove(ds.size()-1);
		}
	}
	
	public static List<List<Integer>> combinationSums(int[] arr, int target) {
		List<List<Integer>> ans = new ArrayList<>();
		Arrays.sort(arr);
		findCombinations(0,ans,arr,target,new ArrayList<>());
		return ans;
	}

}
