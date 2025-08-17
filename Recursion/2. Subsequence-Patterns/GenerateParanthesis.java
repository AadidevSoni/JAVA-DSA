import java.util.ArrayList;
import java.util.List;

public class GenerateParanthesis {

	public static void main(String[] args) {
		
		int n = 4;
		List<String> res = genPara(n);
		System.out.println(res);

	}
	
	public static void generate(int open, int close, String s, int max, List<String> ans) {
		if(s.length() == max*2) {
			ans.add(s);
			return;
		}
		
		if(open<max) {
			generate(open+1,close,s+"(",max,ans);
		}
		
		if(close<open) {
			generate(open,close+1,s+")",max,ans);
		}
		
	}
	
	public static List<String> genPara(int n) {
		List<String> res = new ArrayList<>();
		generate(0,0,"",n,res);
		return res;
	}

}

