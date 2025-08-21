import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

public class SubsetSumBitManipulation {

	public static void main(String[] args) {
		
		int[] arr = new int[] {5,1,2};
		List<Integer> ans = findSums(arr);
		
		System.out.println(ans);

	}
	
	public static List<Integer> findSums(int[] arr) {
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
		
		List<Integer> res = new ArrayList<>();
		int size = 0;
		
		for(List<Integer> lst: ans) {
			int sum = 0;
			for(int num: lst) {
				sum += num;
			}
			res.add(sum);
			size++;
		}
		
		Collections.sort(res);
		
		return res;

	}

}

