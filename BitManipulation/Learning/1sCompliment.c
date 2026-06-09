package Arrays;

import java.util.*;

public class Practice {
	
	public static void main(String[] args) {
		
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int num = n;
		String res = "";
		
		while(n > 0) {
			if(n%2 == 1) {
				res += "1";
			}else {
				res += "0";
			}
			n /= 2;
		}
		res = reverse(res);
		System.out.println(num + " : Binary - " + res);
		
		String temp = "";
		int l = res.length();
		for(int i=0;i<l;i++) {
			if(res.charAt(i) == '1') {
				temp += "0";
			}else {
				temp += "1";
			}
		}
		
		System.out.println(num + " : 1's compliment - " + temp);
		
    }
	
	public static String reverse(String s) {
		int n = s.length();
		String t = "";
		for(int i=0;i<n;i++) {
			t += s.charAt(n-i-1);
		}
		return t;
	}
	
}
	


