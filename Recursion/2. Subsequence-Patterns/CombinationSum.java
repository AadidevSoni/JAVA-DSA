import java.util.ArrayList;
import java.util.List;

public class CombinationSum {

	public static void main(String[] args) {
		
		int[] arr = new int[] {1,2,3,4,5};
		int target = 10;
		List<List<Integer>> res = combinationSuming(arr, target);
		
		System.out.println("Combinations summing to " + target + ":");
		for(List<Integer> list : res) {
			System.out.println(list);
		}
	}
	
	public static void findCombinations(int ind, List<List<Integer>> ans, int[] arr, int target, List<Integer> ds) {
		if (ind == arr.length) {
			if (target == 0) {
				ans.add(new ArrayList<>(ds));
			}
			return;
		}
		
		// pick the element
		if (arr[ind] <= target) {
			ds.add(arr[ind]);
			findCombinations(ind, ans, arr, target - arr[ind], ds);
			ds.remove(ds.size() - 1);
		}
		
		// skip the element
		findCombinations(ind + 1, ans, arr, target, ds);
	}
	
	public static List<List<Integer>> combinationSuming(int[] arr, int target) {
		List<List<Integer>> ans = new ArrayList<>();
		findCombinations(0, ans, arr, target, new ArrayList<>());
		return ans;
	}
}
