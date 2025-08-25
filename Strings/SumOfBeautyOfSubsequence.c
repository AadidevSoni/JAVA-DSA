package Strings;

import java.util.ArrayList;
import java.util.List;

public class SumOfBeautyOfSAubsequence {

public static void main(String[] args) {
		
		String s = "aabc";
		int res = beautySum(s);
		System.out.println("BEAUTY SUM: " + res);

	}
	
	 public static void getSubstring(int ind, int n, String s, List<String> res, String sub) {
	        if(ind == n) {
	            res.add(sub);
	            return;
	        }
	        getSubstring(ind+1,n,s,res,sub+s.charAt(ind));
	        getSubstring(ind+1,n,s,res,sub);
	 }
	 
	 public static int beautySum(String s) {
	        List<String> res = new ArrayList<>();
	        int n = s.length();
	        String sub = "";
	        getSubstring(0,n,s,res,sub);
	        int sum = 0;
	        for(String st: res) {
	        	if (st.length() == 0) continue;
	        	
	            int l = st.length();
	            int[] freq = new int[26];
	            for(int i=0;i<l;i++) {
	                freq[st.charAt(i) - 'a']++;
	            }
	            int max = Integer.MIN_VALUE;
	            int min = Integer.MAX_VALUE;
	            for (int f : freq) {
	                if (f > 0) {
	                    max = Math.max(max, f);
	                    min = Math.min(min, f);
	                }
	            }
	            int diff = max-min;
	            sum += diff;
	        }
	        return sum;
	    }

}
