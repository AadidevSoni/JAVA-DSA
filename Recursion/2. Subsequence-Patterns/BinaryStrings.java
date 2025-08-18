import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

public class BinaryStrings { //Rev - 1

	public static void main(String[] args) {
		// Given an integer n, return all binary strings of length n that do not contain consecutive 1s. Return the result in lexicographically increasing order.

		int n = 4;
		List<String> res = getBinary(n);
		System.out.println(res);

	}
	
	public static void generateBinary(int ind,int n, List<String> ans, String s, String prev) {
		if(ind == n) {
			ans.add(s);
			return;
		}
		
		//Add 0 generally
		generateBinary(ind+1,n,ans,s+"0", "0");
		
		//Add 1 only if prev is not 1
		if(prev != "1") {
			generateBinary(ind+1,n,ans,s+"1","1");
		}
	}
	
	public static List<String> getBinary(int n) {
		List<String> ans = new ArrayList<>();
		String s = "";
		generateBinary(0,n,ans,s,"0");
		Collections.sort(ans);
		return ans;
	}

}
