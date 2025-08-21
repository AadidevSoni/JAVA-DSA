import java.util.Stack;

public class ReverseStackRecursion {

	public static void main(String[] args) {
		
		Stack<Integer> st = new Stack<>();
		st.push(1);
		st.push(2);
		st.push(3);
		st.push(4);
		st.push(5);
		
		System.out.println(st);
		reverseStack(st);
		System.out.println(st);

	}
	
	public static void reversing(Stack<Integer> st, int top) {
		if(st.isEmpty()) {
			st.push(top);
		}else {
			int ele = st.pop();
			reversing(st,top);
			st.push(ele);
		}
	}
	
	public static void reverseStack(Stack<Integer> st) {
		if(!st.isEmpty()) {
			int top = st.pop();
			reverseStack(st);
			reversing(st,top);
		}
	}

}

