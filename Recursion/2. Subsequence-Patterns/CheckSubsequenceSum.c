import java.util.ArrayList;
import java.util.List;

public class CheckSubsequenceSum { // rev - 1

	public static void main(String[] args) {
		int[] n = new int[] {1,2,3,4,5};
		int k = 10;
		boolean res = checkSubsequenceSum(n,k);
		System.out.println(res);

	}
	
    public static void checkSubsequence(int ind, int n, int target, int[] nums, List<List<Integer>> ans, List<Integer> ds) {
        if(target == 0) {
            ans.add(new ArrayList<>(ds));
        }
        if(ind == n) return;

        if(nums[ind] <= target) {
            ds.add(nums[ind]);
            checkSubsequence(ind+1,n,target-nums[ind],nums,ans,ds);
            ds.remove(ds.size()-1);
        }

        checkSubsequence(ind+1,n,target,nums,ans,ds);
    }
    public static boolean checkSubsequenceSum(int[] nums, int k) {
         List<List<Integer>> ans = new ArrayList<>();
         int n = nums.length;
         checkSubsequence(0,n,k,nums,ans,new ArrayList<>());
         for(List<Integer> lst: ans) {
        	 System.out.println(lst);
         }
         if(ans.size() != 0) {
            return true;
         }else {
            return false;
         }
    }

}

