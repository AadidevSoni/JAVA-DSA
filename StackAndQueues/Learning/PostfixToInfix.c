package Arrays;

import java.util.*;

public class Practice {
	
	public static void main(String[] args) {
		
		//Postfix to infix
		String postfix = "AB-DE+F*/";
		int i = 0;
		int n = postfix.length();
		Stack<String> st = new Stack<>();
		while(i < n) {
			char c = postfix.charAt(i);
			if((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') || (c >= '0' && c <= '9')) {
				st.push(String.valueOf(c));
			}else {
				String t1 = st.pop();
				String t2 = st.pop();
				String t3 = '(' + t2 + c + t1 + ')';
				st.push(t3);
			}
			i++;
		}
		System.out.println(st.pop());
		
    }
	
	public static int priority(Character c) {
		if(c == '^') {
			return 3;
		}else if(c == '*' || c == '/') {
			return 2;
		}else if(c == '+' || c == '-') {
			return 1;
		}else {
			return 0;
		}
	}
	
	
}


