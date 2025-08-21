import java.util.ArrayList;
import java.util.List;

public class CombinationSumSingle {

	public static void main(String[] args) {
		
		int[] arr = new int[] {1,2,3};
		int target = 7;
		List<Integer> res = combSum(arr,target);
		System.out.println(res);
	}
	
	public static boolean getComb(int ind, int target, List<Integer> ans, int[] arr, List<Integer> ds) {
		if(ind == arr.length) {
			if(target == 0) {
				ans.clear();
				ans.addAll(ds);
				return true;
			}
			else return false;
		}
		
		if(arr[ind] <= target) {
			ds.add(arr[ind]);
			if(getComb(ind+1,target-arr[ind],ans,arr,ds) == true) return true;
			ds.remove(ds.size()-1);
		}
		
		if(getComb(ind+1,target,ans,arr,ds) == true) return true;
		return false;
	}
	
	public static List<Integer> combSum(int[] arr, int target) {
		List<Integer> ans = new ArrayList<>();
		boolean bool = false;
		bool = getComb(0,target,ans,arr,new ArrayList<>());
		if(bool == true) {
			return ans;
		}else {
			System.out.println("No subsets satisfy the target");
			return ans;
		}
	}

}
