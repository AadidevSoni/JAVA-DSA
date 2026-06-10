package Arrays;

import java.util.*;

public class Practice {
	
	public static void main(String[] args) {
		
		//Infix to prefix
		String s = "a+b*(c^d-e)";
		String infix = "";
		//Reverse the infix and reverse brackets
		for(int i=s.length()-1;i>=0;i--) {
		    char ch = s.charAt(i);

		    if(ch == '(') infix += ')';
		    else if(ch == ')') infix += '(';
		    else infix += ch;
		}
		int i = 0;
		Stack<Character> st = new Stack<>();
		String ans = "";
		while(i < infix.length()) {
			if((infix.charAt(i) >= 'A' && infix.charAt(i) <= 'Z') || (infix.charAt(i) >= 'a' && 
					infix.charAt(i) <= 'z') || (infix.charAt(i) >= '0' && infix.charAt(i) <= '9')) {
				ans += infix.charAt(i);
			}else if(infix.charAt(i) == '(') {
				st.push(infix.charAt(i));
			}else if(infix.charAt(i) == ')') {
				while(!st.isEmpty() && st.peek() != '(') {
					ans += st.pop();
				}
				st.pop(); //pop out the opening bracket
			}else { //operators
				while(!st.isEmpty() && priority(infix.charAt(i)) < priority(st.peek())) { //< not <=
					ans += st.pop();
				}
				st.push(infix.charAt(i));
			}
			i++;
		}
		while(!st.isEmpty()) {
			ans += st.pop();
		}
		String res = "";
		for(int j=0;j<ans.length();j++) {
			res += ans.charAt(ans.length()-j-1);
		}
		
		System.out.println(res);
		
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


