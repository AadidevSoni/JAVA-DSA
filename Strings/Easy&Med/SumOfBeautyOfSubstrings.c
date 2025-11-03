package Strings;

public class SumOfBeautyOfSubstrings {

	public static void main(String[] args) {
		
		String s = "aabbcc";
		int res = beautySum(s);
		System.out.println("BEAUTY SUM: " + res);

	}
	
	public static int beautySum(String s) {
        int n = s.length();
        int sum = 0;
        for(int i=0;i<n;i++) {
            int[] freq = new int[26];
            for(int j=i;j<n;j++) {
                freq[s.charAt(j)-'a']++;

                int maxm = Integer.MIN_VALUE;
                int minm = Integer.MAX_VALUE;
                for(int f: freq) {
                    if(f > 0) {
                        maxm = Math.max(maxm,f);
                        minm = Math.min(minm,f);
                    }
                }
                sum += (maxm-minm);
            }
        }
        return sum;
    }

}
