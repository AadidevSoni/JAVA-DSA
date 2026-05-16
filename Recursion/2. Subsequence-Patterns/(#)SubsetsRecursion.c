import java.util.ArrayList;
import java.util.List;

public class SubsetsRecursion {

	public static void main(String[] args) {
		
		int[] arr = new int[] {1,2,3};
		List<List<Integer>> ans = findSubsets(arr);
		
		for(List<Integer> lst: ans) {
			System.out.println(lst);
		}

	}
	
	public static void findingSubsets(int ind, int n, int[] arr, List<List<Integer>> res, List<Integer> ds) {
		if(ind == n) {
			res.add(new ArrayList<>(ds));
			return;
		}
		
		ds.add(arr[ind]);
		findingSubsets(ind+1,n,arr,res,ds);
		ds.remove(ds.size() - 1);
		
		findingSubsets(ind+1,n,arr,res,ds);
	}
	
	public static List<List<Integer>> findSubsets(int[] arr) {
		List<List<Integer>> res = new ArrayList<>();
		int n = arr.length;
		findingSubsets(0,n,arr,res,new ArrayList<>());
		return res;
	}

}
