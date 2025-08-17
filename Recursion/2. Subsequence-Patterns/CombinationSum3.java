import java.util.ArrayList;
import java.util.List;

public class CombinationSum3 {

	public static void main(String[] args) {
		
		int n = 9;
		int k = 3;
		List<List<Integer>> ans = findComb(n,k);
		
		for(List<Integer> lst: ans) {
			System.out.println(lst);
		}

	}
	
	public static void findingComb(int ind, int target, int n, int[] arr, List<List<Integer>> ans, List<Integer> ds) {
		if(target == 0 && ds.size() == n) {
			ans.add(new ArrayList<>(ds));
			return;
		}
		
		if(ind == arr.length || ds.size() > n) return;
		
		if(arr[ind] <= target) {
			ds.add(arr[ind]);
			findingComb(ind+1,target-arr[ind],n,arr,ans,ds);
			ds.remove(ds.size()-1);
		}
		
		findingComb(ind+1,target,n,arr,ans,ds);
	}
	
	public static List<List<Integer>> findComb(int n, int k) {
		List<List<Integer>> ans = new ArrayList<>();
		int[] arr = new int[] {1,2,3,4,5,6,7,8,9};
		findingComb(0,n,k,arr,ans,new ArrayList<>());
		return ans;
	}

}

