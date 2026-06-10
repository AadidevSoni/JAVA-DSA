package Arrays;

import java.util.*;

public class Practice {
	
	public static void main(String[] args) {
		
		//Infix to postfix
		String infix = "a+b*(c^d-e)";
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
				while(!st.isEmpty() && priority(infix.charAt(i)) <= priority(st.peek())) {
					ans += st.pop();
				}
				st.push(infix.charAt(i));
			}
			i++;
		}
		while(!st.isEmpty()) {
			ans += st.pop();
		}
		
		System.out.println(ans);
		
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


