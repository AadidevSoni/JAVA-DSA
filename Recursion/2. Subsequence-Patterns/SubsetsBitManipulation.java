import java.util.ArrayList;
import java.util.List;

public class SubsetsBitManipulation {

	public static void main(String[] args) {
		
		int[] arr = new int[] {1,2,3};
		List<List<Integer>> ans = subsetFinder(arr);
		
		System.out.println("SUBSETS: ");
		for(List<Integer> list: ans) {
			System.out.println(list);
		}

	}
	
	public static List<List<Integer>> subsetFinder(int[] arr) {
		List<List<Integer>> ans = new ArrayList<>();
		int n = arr.length;
		
		for(int i=0;i<Math.pow(2, n);i++) {
			List<Integer> subset = new ArrayList<>();
			for(int j=0;j<n;j++) {
				if((i & (1<<j)) != 0) {
					subset.add(arr[j]);
				}
			}
			ans.add(subset);
		}
		
		return ans;

	}

}
