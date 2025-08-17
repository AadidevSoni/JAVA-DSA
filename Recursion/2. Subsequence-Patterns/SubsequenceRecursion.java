import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

public class SubsequenceRecursion {

	public static void main(String[] args) {
		
		String s = "abc";
		List<String> res = findSubsequence(s);
		
		for(String st: res) {
			System.out.print(st + " ");
		}

	}
	
	public static void findingSubsequence(int ind, int n, String s, List<String> res, String sub) {
		if(ind == n) {
			res.add(sub);
			return;
		}
		
		// Include current character
		findingSubsequence(ind + 1, n, s, res, sub + s.charAt(ind));

		// Exclude current character
		findingSubsequence(ind + 1, n, s, res, sub);
		
	}
	
	public static List<String> findSubsequence(String s) {
		List<String> res = new ArrayList<>();
		int n = s.length();
		String sub = "";
		findingSubsequence(0,n,s,res,sub);
		Collections.sort(res);
		return res;
	}

}

