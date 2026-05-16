import java.util.ArrayList;
import java.util.List;

public class LetterCombinationPhoneNumber {
	
	public static final String[] KEYPAD = {
			"",
			"",
			"abc",
			"def",
			"ghi",
			"jkl",
			"mno",
			"pqrs",
			"tuv",
			"wxyz"
	};

	public static void main(String[] args) {
		
		String digits = "234";
		List<String> res = findComb(digits);
		System.out.println(res);

	}
	
	public static void findCombinations(String digits, int ind, List<String> ans, StringBuilder s) {
		if(ind == digits.length()) {
			ans.add(s.toString());
			return;
		}
		
		String letters = KEYPAD[digits.charAt(ind)-'0'];
		for(char c: letters.toCharArray()) {
			s.append(c);
			findCombinations(digits,ind+1,ans,s);
			s.deleteCharAt(s.length()-1);
		}
		
	}
	
	public static List<String> findComb(String digits) {
		List<String> ans = new ArrayList<>();
		if(digits == null || digits.length() == 0) return ans;
		findCombinations(digits,0,ans,new StringBuilder());
		return ans;
	}

}

