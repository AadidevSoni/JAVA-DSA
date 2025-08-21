import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class Subsets2Recursion {

	public static void main(String[] args) {
		
		int[] arr = new int[] {1,1,1};
		List<List<Integer>> ans = findSubsets(arr);
		
		System.out.println("SUBSETS: ");
		for(List<Integer> ls: ans) {
			System.out.println(ls);
		}
	}
	
	public static void findingSubsets(int ind, int n, int[] arr, List<List<Integer>> ans, List<Integer> ds) {
		ans.add(new ArrayList<>(ds));
		
		for(int i=ind;i<n;i++) {
			if(i != ind && arr[i] == arr[i-1]) continue;
			ds.add(arr[i]);
			findingSubsets(i+1,n,arr,ans,ds);
			ds.remove(ds.size() -1);
		}
	}
	
	public static List<List<Integer>> findSubsets(int[] arr) {
		Arrays.sort(arr);
		List<List<Integer>> ans = new ArrayList<>();
		int n = arr.length;
		findingSubsets(0,n,arr,ans,new ArrayList<>());
		return ans;
	}

}
