import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

public class SubsequenceBitManipulation { //rev - 1

	public static void main(String[] args) {
		
		String s = "abc";
		List<String> res = findSubsequence(s);
		
		for(String st: res) {
			System.out.print(st + " ");
		}

	}
	
	public static List<String> findSubsequence(String s) {
		List<String> res = new ArrayList<>();
		int n = s.length();
		
		for(int i=0;i<Math.pow(2, n);i++) {
			String sub = "";
			for(int j=0;j<n;j++) {
				if((i & (1<<j)) != 0) {
					sub += s.charAt(j);
				}
			}
			res.add(sub);
		}
		
		Collections.sort(res);
		return res;
	}

}

