package Strings;

public class LongestCommonPrefix {

	public static void main(String[] args) {
		
		String[] strs = {"flower","flow","flight"};
		String res = longest(strs);
		System.out.println(res);
		

	}
	
	public static String longest(String[] strs) {
		if (strs == null || strs.length == 0) return "";

        int len = strs[0].length();
        for (int i = 1; i < strs.length; i++) {
            len = Math.min(len, strs[i].length());
        }

        int max = 0;
        
        for(int i=0;i<len;i++) {
            char c = strs[0].charAt(i);
            for(int j=1;j<strs.length;j++) {
                if(strs[j].charAt(i) != c) {
                    return strs[0].substring(0,max);
                }
            }
            max++;
        }
        return strs[0].substring(0,max);
	}

}
