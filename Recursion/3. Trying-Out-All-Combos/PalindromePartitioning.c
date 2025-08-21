import java.util.ArrayList;
import java.util.List;

public class PalindromePartitioning {

	public static void main(String[] args) {
		
		String s = "aabb";
		List<List<String>> res = partition(s);
		System.out.println(res);

	}
	
	public static boolean isPalindrome(String s, int start, int end) {
		while(start <= end) {
			if(s.charAt(start++) != s.charAt(end--)) {
				return false;
			}
		}
		return true;
	}
	
	public static void getParts(int ind, String s, List<List<String>> res, List<String> ds) {
		
		if(ind == s.length()) {
			res.add(new ArrayList<>(ds));
			return;
		}
		
		for(int i=ind;i<s.length();i++) {
			if(isPalindrome(s,ind,i)) {
				ds.add(s.substring(ind,i+1));
				getParts(i+1,s,res,ds);
				ds.remove(ds.size()-1);
			}
		}
		
	}
	
	public static List<List<String>> partition(String s) {
		List<List<String>> ans = new ArrayList<>();
		getParts(0,s,ans,new ArrayList<>());
		return ans;
	}

}

